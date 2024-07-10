#!/usr/bin/env python3
from datetime import datetime
import os
from pathlib import Path
import sys
import xml.etree.ElementTree as ET
"""
This is not a user friendly CLI script.
It is intended to be invoked from gen_vku.sh.
Run that instead.
"""

"""
TODO:
fill in stub for uint32_t get_uncompressed_sample_size(VkFormat f);
"""

assert len(sys.argv) == 3, "args must be paths to vk.xml vku.h"

VK_XML, VKU_H, VKU_AUTHORED_H = Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[0]).with_name("vku_authored.h")

assert ((VK_XML.suffix == ".xml") and VK_XML.exists() and (VKU_H.suffix == ".h")), "args must be paths to vk.xml vku.h"

FILE_HEADER = f"""
#pragma once
// {VKU_H.name} {VKU_H.parent.parent.parent.name} generated {datetime.now()} by {Path(sys.argv[0]).name}
// see https://github.com/benn-herrera/vku.git LICENSE.md and README.md
// define VKU_INLINE_ALL for header-only with no compiled functions
// or 
// define VKU_IMPLEMENT in exactly on C++ source file before including vku/vku.h

#if defined(VKU_INLINE_ALL)
# define VKU_PROTO inline
# define VKU_IMPL inline
# if defined(VKU_IMPLEMENT)
#   static_assert(false, "only one of VKU_INLINE_ALL, VKU_IMPLEMENT may be defined.");
# endif
#elif defined(VKU_IMPLEMENT)
# define VKU_PROTO extern
# define VKU_IMPL
#endif // VKU_INLINE_ALL, VKU_IMPLEMENT

#if !defined(VK_VERSION_1_0)
# include "vulkan/vulkan.h"
#endif

#if !defined(VK_NULL_HANDLE)
# define VK_NULL_HANDLE 0
#endif

namespace vku {{
"""[1:-1]

FRIEND_OP_FMT = """
    friend {RT} operator {OP}(const UType& lhs, const VkType rhs) {{ return lhs.v {OP} rhs; }}
    friend {RT} operator {OP}(const VkType lhs, const UType& rhs) {{ return lhs {OP} rhs.v; }}
"""[1:-1]

FRIEND_FLAG_OP_FMT = """
    friend VkFlags operator {OP}(const UType& lhs, const VkFlags rhs) {{ return VkFlags(lhs.v) {OP} rhs; }}
    friend VkFlags operator {OP}(const VkFlags lhs, const UType& rhs) {{ return lhs {OP} VkFlags(rhs.v); }}
    friend VkFlags operator {OP}(const UType& lhs, const VkType rhs) {{ return VkFlags(lhs.v) {OP} VkFlags(rhs); }}
    friend VkFlags operator {OP}(const VkType lhs, const UType& rhs) {{ return VkFlags(lhs) {OP} VkFlags(rhs.v); }}
"""[1:-1]


def prim_mod_op(op: str) -> str:
    return f"    VkType operator {op}(const VkType rhs) {{ v = (VkType)((VkFlags)v {op[:1]} (VkFlags)rhs); return v; }}"


STRUCT_MOD_OP_FMT = """
    VkType& operator {OP}(const VkType& rhs) {{ (VkType&)*this {OP} rhs; return *this; }}
"""[1:-1]

UNARY_OP_FMT = """
    {RT}operator {OP}(){{ return {OP}(v); }}
"""[1:-1]

CAST_OPS = """
    operator const VkType&() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
"""[1:-1]

PRIM_ASSIGN_OPS = "    VkType operator =(const VkType rhs) { v = rhs; return v; }"
STRUCT_ASSIGN_OPS = STRUCT_MOD_OP_FMT.format(OP='=')

BOOL_OPS = "\n".join([
    UNARY_OP_FMT.format(RT='', OP='bool'),
    UNARY_OP_FMT.format(RT='bool ', OP='!'),
])

RMW_MOD_OPS = "\n".join([
    prim_mod_op("|="),
    prim_mod_op("&="),
    prim_mod_op("^="),
    prim_mod_op("+="),
    prim_mod_op("-="),
])

FRIEND_COMP_OPS = "\n".join([
    FRIEND_OP_FMT.format(RT='bool', OP='<'),
    FRIEND_OP_FMT.format(RT='bool', OP='<='),
    FRIEND_OP_FMT.format(RT='bool', OP='>'),
    FRIEND_OP_FMT.format(RT='bool', OP='>=')
])

FRIEND_EQ_OPS = "\n".join([
    FRIEND_OP_FMT.format(RT='bool', OP='=='),
    FRIEND_OP_FMT.format(RT='bool', OP='!='),
])

FRIEND_EXPR_OPS = "\n".join([
    FRIEND_OP_FMT.format(RT='VkType', OP='|'),
    FRIEND_OP_FMT.format(RT='VkType', OP='&'),
    FRIEND_OP_FMT.format(RT='VkType', OP='^'),
    FRIEND_OP_FMT.format(RT='VkType', OP='+'),
    FRIEND_OP_FMT.format(RT='VkType', OP='-')
])

# VkFlags return value (maps from enum flag bit to Flags)
FRIEND_FLAG_OPS = "\n".join([
    FRIEND_FLAG_OP_FMT.format(OP='|'),
    FRIEND_FLAG_OP_FMT.format(OP='&'),
    FRIEND_FLAG_OP_FMT.format(OP='^'),
    FRIEND_FLAG_OP_FMT.format(OP='+'),
    FRIEND_FLAG_OP_FMT.format(OP='-')
])

ENUMS_SECTION = [
"""  // wrapped enum types
  template<typename T>
  struct EnumT {
    using UType = EnumT;
    using VkType = T;  
    static constexpr auto kInvalid = (VkType)0x7fffffff;
    EnumT(VkType i=(VkType)0) : v(i) {}""",
    PRIM_ASSIGN_OPS,
    CAST_OPS,
    FRIEND_COMP_OPS,
    FRIEND_EQ_OPS,
"""  private:
    VkType v;
  };
"""
]

FLAGS_SECTION = [
"""  // wrapped flag types
  template<typename T>
  struct FlagsT {
    using UType = FlagsT;
    using VkType = T;
    
    FlagsT(VkType i=(VkType)0) : v(i) {}""",
    PRIM_ASSIGN_OPS,
    BOOL_OPS,
    CAST_OPS,
    RMW_MOD_OPS,
    FRIEND_COMP_OPS,
    FRIEND_EQ_OPS,
    FRIEND_EXPR_OPS,
"""  private:
    VkType v;
  };
  
  using Flags = FlagsT<VkFlags>;
  using Flags64 = FlagsT<VkFlags64>;
  
  template<typename T>
  struct FlagBitsT {
    using UType = FlagBitsT;
    using VkType = T;  
    FlagBitsT(VkType i=(VkType)0) : v(i) {}""",
    PRIM_ASSIGN_OPS,
    CAST_OPS,
    RMW_MOD_OPS,
    FRIEND_COMP_OPS,
    FRIEND_EQ_OPS,
    FRIEND_FLAG_OPS,
"""  private:
    VkType v;
  };
"""
]

HANDLES_SECTION = [
"""  //
  // wrapped handle types
  //
  template<typename T>
  struct HandleT {
    using UType = HandleT;
    using VkType = T;

    HandleT(VkType i = (VkType)0) : v(i) {}""",
    PRIM_ASSIGN_OPS,
    BOOL_OPS,
    CAST_OPS,
    FRIEND_EQ_OPS,
"""
  private:
    VkType v;
  };
"""
]

STRUCTS_SECTION = [
"""  // wrapped info (type identified) and description (not type identified) structs
  template<class T, int32_t STYPE>
  struct InfoT : public T {
    using UType = InfoT;
    using VkType = T;
    static constexpr auto kStructType = VkStructureType(STYPE);
    InfoT() { *this = VkType{ kStructType }; }
    InfoT(const VkType& rhs) { (VkType&)*this = rhs; this->sType = kStructType; }
    VkType& operator =(const VkType& rhs) { (VkType&)*this = rhs; this->sType = kStructType; return *this; }
  };
  
  template<typename T>
  struct DescriptionT : public T {
    using UType = DescriptionT;
    using VkType = T;
    DescriptionT() { *this = VkType{}; }
    DescriptionT(const VkType& rhs) { (VkType&)*this = rhs; }""",
    STRUCT_ASSIGN_OPS,
"""  };
"""
]

FUNCTION_PROTOS_HEADER = "// function prototypes"

FUNCTIONS_PROTO_SECTION = [
]

FUNCTION_PROTOS_FOOTER = ""

FUNCTIONS_HEADER = """
  // function implementations
#if defined(VKU_IMPLEMENT) || defined(VKU_INLINE_ALL)"""[1:]

FUNCTIONS_IMPL_SECTION = [
]

FUNCTIONS_FOOTER = "#endif // VKU_IMPLEMENT || VKU_INLINE_ALL"

FILE_FOOTER = "} // end namespace vku"


def write_vku_h():
    # Accumulate the results and write them out
    file_sections = [
        FILE_HEADER,
        *ENUMS_SECTION, "",
        *FLAGS_SECTION, "",
        *HANDLES_SECTION, "",
        *STRUCTS_SECTION, "",
        FUNCTION_PROTOS_HEADER,
        *FUNCTIONS_PROTO_SECTION,
        FUNCTION_PROTOS_FOOTER, "",
        FUNCTIONS_HEADER,
        *FUNCTIONS_IMPL_SECTION,
        FUNCTIONS_FOOTER,
        FILE_FOOTER,
        VKU_AUTHORED_H.read_text()
    ]
    os.makedirs(VKU_H.parent.as_posix(), exist_ok=True)
    VKU_H.write_text("\n".join(file_sections))


DOC = ET.parse(VK_XML)
REGISTRY = DOC.getroot()


def wrap_handle_type(type_name: str) -> str:
    return f"  using {type_name[2:]} = HandleT<{type_name}>;"


def wrap_enum_type(type_name: str) -> str:
    return f"  using {type_name[2:]} = EnumT<{type_name}>;"


def wrap_flag_bits_type(type_name: str, *, bit_width: int) -> str:
    alias = "Flags64" if bit_width == 64 else f"FlagBitsT<{type_name}>"
    return f"  using {type_name[2:]} = {alias};"


def wrap_struct_type(type_name: str, *, stype_value: str) -> str:
    struct_templ = "InfoT" if stype_value else "DescriptionT"
    stype_value = f", {stype_value}" if stype_value else ""
    return f"  using {type_name[2:]} = {struct_templ}<{type_name}{stype_value}>;"


def to_snake(val: str) -> str:
    snake = []
    p = None
    for v in val:
        if v.isupper() and p and not p.isupper():
            snake.append("_")
        snake.append(v.lower())
        p = v
    return "".join(snake)


def to_string_decl(*, vk_type: str, decl: str, is_type_named: bool) -> str:
    end = ';' if decl == "VKU_PROTO" else " {"
    if decl:
        decl = f"{decl} "
    type_pfx = f"{to_snake(vk_type[2:])}_" if is_type_named else ""
    lines = []
    if is_type_named:
        lines.append(f"  // {vk_type} is type aliased. its to_string() must have a unique name.")
    lines.append(f"  {decl}const char* {type_pfx}to_string(const {vk_type} v){end}")
    return "\n".join(lines)


def to_string_proto(vk_type: str, is_type_named: bool) -> str:
    return to_string_decl(vk_type=vk_type, decl="VKU_PROTO", is_type_named=is_type_named)


def to_string_impl(vk_type: str, enum_vals: [str], is_type_named: bool) -> str:
    body = [
        to_string_decl(vk_type=vk_type, decl="VKU_IMPL", is_type_named=is_type_named),
        "    switch(v) {",
    ]

    for v in enum_vals:
        body.append(f"    case {v}: return \"{v}\";")

    body.extend([
        "    default: break;",
        "    }",
        "    return nullptr;",
        "  }",
    ])
    return "\n".join(body)


PLATFORM_MACROS = {}
PLATFORM_BY_TYPE = {}
VULKAN_SC_TYPES = set()
AUTHORED_TYPES = set(t for t in ("VkOffset2D", "VkExtent2D", "VkRect2D", "VkOffset3D", "VkExtent3D", "VkViewport"))

VERSION_MACROS = set()
VERSION_MACRO_BY_TYPE = {}


def init_platforms_and_versions():
    for platform in REGISTRY.find("./platforms"):
        PLATFORM_MACROS[platform.attrib['name']] = platform.attrib['protect']

    for extension in [
        e for e in REGISTRY.find("./extensions")
    ]:
        extension_is_sc = (
                extension.attrib.get("supported") == "vulkansc" or
                extension.attrib.get("ratified") == "vulkansc"
        )
        extension_platform = extension.attrib.get('platform')

        for require in extension.findall("./require"):
            for plat_type in require.findall("./type"):
                if type_name := plat_type.attrib.get('name'):
                    # VulkanSC only
                    if extension_is_sc or require.attrib.get('api') == "vulkansc":
                        VULKAN_SC_TYPES.add(type_name)
                    elif platform := (extension_platform or extension.attrib.get('platform')):
                        PLATFORM_BY_TYPE[type_name] = platform

    for feature in REGISTRY.findall("./feature"):
        version = feature.attrib["name"]
        VERSION_MACROS.add(version)
        for require in feature.findall("./require"):
            for type_tag in require.findall("./type"):
                VERSION_MACRO_BY_TYPE[type_tag.attrib["name"]] = version


def platform_macro_for_type(name: str) -> str | None:
    plat = PLATFORM_BY_TYPE.get(name)
    return PLATFORM_MACROS[plat] if plat is not None else None


def version_macro_for_type(name: str) -> str | None:
    version = VERSION_MACRO_BY_TYPE.get(name)
    return version


def add_grouped_to_section(section: [str], blocks:[dict]):
    cur_plat = None
    cur_version = None
    for block in blocks:
        plat = block["platform"]
        version = block["version"]
        if plat != cur_plat:
            if cur_plat is not None:
                section.append(f"#endif // {cur_plat}")
        if version != cur_version:
            if cur_version is not None:
                section.append(f"#endif // {cur_version}")
        if plat != cur_plat:
            cur_plat = plat
            if cur_plat:
                section.append(f"#if defined({cur_plat})")
        if version != cur_version:
            cur_version = version
            if cur_version:
                section.append(f"#if defined({cur_version})")
        section.append(block["block"])

    if cur_plat is not None:
        section.append(f"#endif // {cur_plat}")
    if cur_version is not None:
        section.append(f"#endif // {cur_version}")


def gen_type_wrappers():
    init_platforms_and_versions()

    enums = []
    flags = []
    handles = []
    structs = []
    func_protos = []
    func_impls = []

    # wrap enum types (serial and flag bits)
    for enum in (
            e for e in REGISTRY.findall("./enums")
            if "type" in e.attrib and
               e.find("./enum") is not None
    ):
        type_name = enum.attrib["name"]
        if type_name in VULKAN_SC_TYPES:
            continue
        platform_macro = platform_macro_for_type(type_name)
        version_macro = version_macro_for_type(type_name)
        # enums that are 64 bits wide are implemented as a sequence of static const VkFlags64 values
        # instead of an actual enum, so attempting to overload to_string via just the type will not work.
        bit_width = int(enum.attrib.get("bitwidth", "32"))
        type_named_to_string = bit_width != 32

        if enum.attrib["type"] == "bitmask":
            block = wrap_flag_bits_type(type_name, bit_width=bit_width)
            section = flags
        else:
            block = wrap_enum_type(type_name)
            section = enums

        section.append(
            dict(
                block=block,
                platform=platform_macro,
                version=version_macro
            )
        )
        func_protos.append(
            dict(
                block=to_string_proto(type_name, is_type_named=type_named_to_string),
                platform=platform_macro,
                version=version_macro
            )
        )

        def check_enum_val(eattr: dict) -> bool:
            if "alias" in eattr:
                return False
            return bool(eattr.get("value", eattr.get("bitpos")))

        enum_vals = [e.attrib["name"] for e in enum.findall("./enum") if check_enum_val(e.attrib)]
        func_impls.append(
            dict(
                block=to_string_impl(type_name, enum_vals, is_type_named=type_named_to_string),
                platform=platform_macro,
                version=version_macro
            )
        )

    # wrap handle and struct types
    for type_entry in (
        t for t in  REGISTRY.find("./types")
        if t.tag == "type" and "category" in t.attrib
    ):
        category = type_entry.attrib["category"]

        if category == "handle":
            if "objtypeenum" not in type_entry.attrib:
                continue
            if (type_name := type_entry.find("./name")) is None:
                continue
            type_name = type_name.text
            if type_name in VULKAN_SC_TYPES:
                continue
            platform_macro = platform_macro_for_type(type_name)
            version_macro = version_macro_for_type(type_name)
            block = wrap_handle_type(type_name)
            handles.append(dict(block=block, platform=platform_macro, version=version_macro))
        elif category == "struct":
            type_name = type_entry.attrib["name"]
            if type_name in VULKAN_SC_TYPES or type_name in AUTHORED_TYPES:
                continue
            if (stype := type_entry.find("./member")) is not None:
                stype = stype.attrib.get("values")
                if stype and not stype.startswith("VK_STRUCTURE_TYPE"):
                    stype = None
            platform_macro = platform_macro_for_type(type_name)
            version_macro = version_macro_for_type(type_name)
            block = wrap_struct_type(type_name, stype_value=stype)
            structs.append(dict(block=block, platform=platform_macro, version=version_macro))
        elif category == "bitmask":
            if (type_def := type_entry.find("./type")) is None:
                continue
            if (type_name := type_entry.find("./name")) is None:
                continue
            if (requires := type_entry.attrib.get("requires")) is None:
                continue
            type_name = type_name.text
            type_def = type_def.text
            platform_macro = platform_macro_for_type(requires)
            version_macro = version_macro_for_type(requires)
            block = f"  using {type_name[2:]} = {type_def[2:]};"
            flags.append(dict(block=block, platform=platform_macro, version=version_macro))

    def sort_key(blk: dict) -> str:
        p = blk['platform'] or "0"
        v = blk['version'] or "0"
        return f"{p}_{v}"

    enums.sort(key=sort_key)
    flags.sort(key=sort_key)
    handles.sort(key=sort_key)
    structs.sort(key=sort_key)
    func_protos.sort(key=sort_key)
    func_impls.sort(key=sort_key)

    add_grouped_to_section(ENUMS_SECTION, enums)
    add_grouped_to_section(FLAGS_SECTION, flags)
    add_grouped_to_section(HANDLES_SECTION, handles)
    add_grouped_to_section(STRUCTS_SECTION, structs)
    add_grouped_to_section(FUNCTIONS_PROTO_SECTION, func_protos)
    add_grouped_to_section(FUNCTIONS_IMPL_SECTION, func_impls)


def format_meta_decl(
        *,
        decl: str,
        name: str,
        rtype: str,
        extra_params: str | None = None,
        doc_line: str | None = None
) -> str:
    if extra_params is not None:
        extra_params = f", {extra_params}"
    else:
        extra_params = ""
    if doc_line is not None:
        doc_line = f"  // {doc_line}\n"
    else:
        doc_line = ""
    end = ';' if decl == "VKU_PROTO" else " {"
    return f"{doc_line}  {decl} {rtype} {name}(VkFormat f{extra_params}){end}"


def format_meta_proto(
        *,
        name: str,
        rtype: str="uint32_t",
        extra_params: str | None = None,
        doc_line: str | None = None,
) -> str:
    return format_meta_decl(name=name, rtype=rtype, extra_params=extra_params, doc_line=doc_line, decl="VKU_PROTO")


def format_meta_impl(
        *,
        name: str,
        body: str,
        rtype: str="uint32_t",
        extra_params: str | None = None,
) -> str:
    return "\n".join([
        format_meta_decl(name=name, rtype=rtype, extra_params=extra_params, decl="VKU_IMPL"),
        body,
        "  }\n"
    ])


def collect_format_data():
    vk_formats = []
    for format_entry in REGISTRY.find("./formats").findall("./format"):
        comp_names = []
        comp_bit_counts = set()
        comp_num_types = set()
        for component_entry in format_entry.findall("./component"):
            comp_name = component_entry.attrib["name"]
            bits = component_entry.attrib["bits"]
            bits = int(bits) if bits != "compressed" else None
            num_type = component_entry.attrib["numericFormat"]
            comp_names.append(comp_name)
            comp_bit_counts.add(bits)
            comp_num_types.add(num_type)
        name = format_entry.attrib["name"]
        size_bytes = int(format_entry.attrib["blockSize"])
        texel_count = int(format_entry.attrib["texelsPerBlock"])
        if texel_count > 1:
            block_size = format_entry.attrib["blockExtent"]
            block_size = tuple(int(d) for d in block_size.split(",")[:2])
        else:
            block_size = (1, 1)
        vk_formats.append({
            "name": name,
            "size_bytes": size_bytes,
            "block_size": block_size,
            "comp_names": comp_names,
            "comp_num_types": comp_num_types,
            "comp_bit_counts": comp_bit_counts
        })
    return vk_formats


def gen_format_metadata_functions():
    vk_formats = collect_format_data()
    STRUCTS_SECTION.append("""
  enum class CompressionScheme : uint8_t {
    None,
    BC1,
    BC2,
    BC3,
    BC4,
    BC5,
    BC6H,
    BC7,    
    EAC,
    ETC2,
    ASTC,
  };
  enum class ChannelType : uint8_t {
    R, G, B, A, D, S
  };  
  enum class NumericFormat : uint8_t {
    UINT,
    SINT,
    UNORM,
    SNORM,    
    USCALED,
    SSCALED,    
    UFLOAT,
    SFLOAT
  };
  struct ChannelMetadata {
    ChannelType type;
    NumericFormat numericFormat;
    uint8_t bitCount;
    // 0 for non-packed
    uint8_t bitShift;
  };
  struct FormatMetadata {
    CompressionScheme compression;  
    uint8_t blockWidth;
    uint8_t blockHeight;
    uint8_t blockSizeBytes;
    uint8_t isPacked;
    uint8_t isSRGB;
    uint8_t areChannelsUniform;
    uint8_t channelCount;
    ChannelMetadata channels[4];
  };  
""")
    FUNCTIONS_PROTO_SECTION.append("")
    FUNCTIONS_IMPL_SECTION.append("")

    func_info = {"name": "get_uncompressed_sample_size_bytes", "rtype": "uint32_t"}
    doc_line = None
    FUNCTIONS_PROTO_SECTION.append(format_meta_proto(doc_line=doc_line, **func_info))
    meta_body = [
        "    switch(f) {"
    ]
    for vk_format in vk_formats:
        if vk_format["block_size"] != (1, 1):
            continue
        meta_body.append(f"    case {vk_format['name']}: return {vk_format['size_bytes']};")
    meta_body.append("    default: break;\n    }\n    return {};")
    FUNCTIONS_IMPL_SECTION.append(format_meta_impl(body="\n".join(meta_body), **func_info))

    func_info = {"name": "get_compressed_block_size", "rtype": "uvec3"}
    doc_line = "x,y texel block size, z block size bytes"
    FUNCTIONS_PROTO_SECTION.append(format_meta_proto(doc_line=doc_line, **func_info))
    meta_body = [
        "    switch(f) {"
    ]
    for vk_format in vk_formats:
        if vk_format["block_size"] == (1, 1):
            continue
        block_size = f"{{{vk_format['block_size'][0]}, {vk_format['block_size'][1]}, {vk_format['size_bytes']}}}"
        meta_body.append(f"    case {vk_format['name']}: return {block_size};")
    meta_body.append("    default: break;\n    }\n    return {};")
    FUNCTIONS_IMPL_SECTION.append(format_meta_impl(body="\n".join(meta_body), **func_info))


gen_type_wrappers()
gen_format_metadata_functions()
write_vku_h()
