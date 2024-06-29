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

assert len(sys.argv) == 3, "args must be paths to vk.xml vku.h"

VK_XML, VKU_H = Path(sys.argv[1]), Path(sys.argv[2])

assert ((VK_XML.suffix == ".xml") and VK_XML.exists() and (VKU_H.suffix == ".h")), "args must be paths to vk.xml vku.h"

FILE_HEADER = f"""
#pragma once
// {VKU_H.name} {VKU_H.parent.parent.parent.name} generated {datetime.now()} by {Path(sys.argv[0]).name}
// see https://github.com/benn-herrera/vku.git LICENSE.md and README.md
// define VKU_INLINE_ALL for header-only with no compiled functions
// or 
// define VKU_IMPLEMENT in exactly on C++ source file before including vku/vku.h

#if defined(VKU_INLINE_ALL)
# define VKU_FUNC inline
# if defined(VKU_IMPLEMENT)
#   static_assert(false, "only one of VKU_INLINE_ALL, VKU_IMPLEMENT may be defined.");
# endif
#elif defined(VKU_IMPLEMENT)
# define VKU_FUNC
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
    friend auto operator {OP}(const UType& lhs, const VkType rhs) {{ return lhs.v {OP} rhs; }}
    friend auto operator {OP}(const VkType lhs, const UType& rhs) {{ return lhs {OP} rhs.v; }}
"""[1:-1]

FRIEND_FLAG_OP_FMT = """
    friend auto operator {OP}(const UType& lhs, const VkFlags rhs) {{ return VkFlags(lhs.v) {OP} rhs; }}
    friend auto operator {OP}(const VkFlags lhs, const UType& rhs) {{ return lhs {OP} VkFlags(rhs.v); }}
    friend auto operator {OP}(const UType& lhs, const VkType rhs) {{ return VkFlags(lhs.v) {OP} VkFlags(rhs); }}
    friend auto operator {OP}(const VkType lhs, const UType& rhs) {{ return VkFlags(lhs) {OP} VkFlags(rhs.v); }}
"""[1:-1]

PRIM_MOD_OP_FMT = """
    VkType operator {OP}(const VkType rhs) {{ v {OP} rhs; return v; }}
"""[1:-1]

STRUCT_MOD_OP_FMT = """
    VkType& operator {OP}(const VkType& rhs) {{ (VkType&)*this {OP} rhs; return *this; }}
"""[1:-1]

UNARY_OP_FMT = """
    {RV}operator {OP}(){{ return {OP}(v); }}
"""[1:-1]

CAST_OPS = """
    operator const VkType&() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
"""[1:-1]

PRIM_ASSIGN_OPS = PRIM_MOD_OP_FMT.format(OP='=')
STRUCT_ASSIGN_OPS = STRUCT_MOD_OP_FMT.format(OP='=')

BOOL_OPS = "\n".join([
    UNARY_OP_FMT.format(RV='', OP='bool'),
    UNARY_OP_FMT.format(RV='auto ', OP='!'),
])

RMW_MOD_OPS = "\n".join([
    PRIM_MOD_OP_FMT.format(OP='|='),
    PRIM_MOD_OP_FMT.format(OP='&='),
    PRIM_MOD_OP_FMT.format(OP='^='),
    PRIM_MOD_OP_FMT.format(OP='+='),
    PRIM_MOD_OP_FMT.format(OP='-='),
])

FRIEND_COMP_OPS = "\n".join([
    FRIEND_OP_FMT.format(OP='<'),
    FRIEND_OP_FMT.format(OP='<='),
    FRIEND_OP_FMT.format(OP='>'),
    FRIEND_OP_FMT.format(OP='>=')
])

FRIEND_EQ_OPS = "\n".join([
    FRIEND_OP_FMT.format(OP='=='),
    FRIEND_OP_FMT.format(OP='!='),
])

FRIEND_EXPR_OPS = "\n".join([
    FRIEND_OP_FMT.format(OP='|'),
    FRIEND_OP_FMT.format(OP='&'),
    FRIEND_OP_FMT.format(OP='^'),
    FRIEND_OP_FMT.format(OP='+'),
    FRIEND_OP_FMT.format(OP='-')
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
    static constexpr auto kInvalid = (VkType)~0u;
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
  struct Flags {
    using UType = Flags;
    using VkType = VkFlags;
    
    Flags(VkType i=(VkType)0) : v(i) {}""",
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
  
  template<typename T>
  struct FlagBitsT {
    using UType = FlagBitsT;
    using VkType = T;  
    FlagBitsT(VkType i=(VkType)0) : v(i) {}""",
    PRIM_ASSIGN_OPS,
    CAST_OPS,
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
    InfoT(const VkType& rhs) { (VkType&)*this = rhs; }""",
    STRUCT_ASSIGN_OPS,
"""  };
  
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

FUNCTION_PROTOS_HEADER = """
// function prototypes
#if !defined(VKU_INLINE_ALL)"""[1:]

FUNCTION_PROTOS_SECTION = [
  "  extern const char* member_to_string_vp(const VkPhysicalDeviceFeatures&, const void* member);"
]

FUNCTION_PROTOS_FOOTER = "#endif // VKU_INLINE_ALL"

FUNCTIONS_HEADER = """
  // function implementations
#if defined(VKU_IMPLEMENT) || defined(VKU_INLINE_ALL)"""[1:]

FUNCTIONS_IMPL_SECTION = [
"""
  VKU_FUNC const char* member_to_string_vp(const VkPhysicalDeviceFeatures& s, const void* member) {
    return nullptr;
  }"""[1:]
]

FUNCTIONS_FOOTER = "#endif // VKU_IMPLEMENT || VKU_INLINE_ALL"

ALWAYS_INLINE_FUNCTIONS_SECTION = [
"""
  // always inlined functions
  template<typename T>
  inline const char* to_string(const VkPhysicalDeviceFeatures& s, const T& m) {
      return member_to_string_vp(s, &m);
  }"""[1:]
]

FILE_FOOTER = "} // end namespace vku"


def write_vku_h():
    # Accumulate the results and write them out
    file_sections = [
        FILE_HEADER,
        *ENUMS_SECTION,
        "",
        *FLAGS_SECTION,
        "",
        *HANDLES_SECTION,
        "",
        *STRUCTS_SECTION,
        "",
        FUNCTION_PROTOS_HEADER,
        *FUNCTION_PROTOS_SECTION,
        FUNCTION_PROTOS_FOOTER,
        "",
        FUNCTIONS_HEADER,
        *FUNCTIONS_IMPL_SECTION,
        FUNCTIONS_FOOTER,
        "",
        *ALWAYS_INLINE_FUNCTIONS_SECTION,
        FILE_FOOTER
    ]
    os.makedirs(VKU_H.parent.as_posix(), exist_ok=True)
    VKU_H.write_text("\n".join(file_sections))


DOC = ET.parse(VK_XML)
REGISTRY = DOC.getroot()


def handle_type(type_name: str) -> str:
    return f"  using {type_name[2:]} = HandleT<{type_name}>;"


def enum_type(type_name: str, *, is_flags: bool) -> str:
    enum_templ = "FlagBitsT" if is_flags else "EnumT"
    return f"  using {type_name[2:]} = {enum_templ}<{type_name}>;"


def struct_type(type_name: str, *, stype_value: str) -> str:
    struct_templ = "InfoT" if stype_value else "DescriptionT"
    stype_value = f", {stype_value}" if stype_value else ""
    return f"  using {type_name[2:]} = {struct_templ}<{type_name}{stype_value}>;"


def protect(macros: [str], block: str) -> str:
    macros = ") && defined(".join(macros)
    return f"""#if defined({macros})
{block}
#endif""" if macros else block


PLATFORM_MACROS = {}
PLATFORM_BY_TYPE = {}
PLATFORM_NAMES = set()

VERSION_MACROS = set()
VERSION_MACRO_BY_TYPE = {}


def init_platforms_and_versions():
    for platform in REGISTRY.find("./platforms"):
        PLATFORM_MACROS[platform.attrib['name']] = platform.attrib['protect']

    for extension in [
        e for e in REGISTRY.find("./extensions")
        if 'platform' in e.attrib
    ]:
        for plat_type in [pt for pt in extension.find('./require') if 'name' in pt.attrib]:
            platform = extension.attrib['platform']
            PLATFORM_BY_TYPE[plat_type.attrib['name']] = platform
            PLATFORM_NAMES.add(platform)

    for feature in REGISTRY.findall("./feature"):
        version = feature.attrib["name"]
        VERSION_MACROS.add(version)
        for require in feature.findall("./require"):
            for type_tag in require.findall("./type"):
                VERSION_MACRO_BY_TYPE[type_tag.attrib["name"]] = version


def platform_macro_for_type(name: str) -> str | None:
    plat = PLATFORM_BY_TYPE.get(name)
    if plat is None:
        for pn in PLATFORM_NAMES:
            if pn.lower() in name.lower():
                plat = pn
                break
    return PLATFORM_MACROS[plat] if plat is not None else None


def version_macro_for_type(name: str) -> str | None:
    version = VERSION_MACRO_BY_TYPE.get(name)
    if version is None or version == "VK_VERSION_1_0":
        return None
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

    for enum in (
            e for e in REGISTRY.findall("./enums")
            if "type" in e.attrib and
               e.find("./enum") is not None
    ):
        is_flags = enum.attrib["type"] == "bitmask"
        type_name = enum.attrib["name"]
        section = flags if is_flags else enums
        platform_macro = platform_macro_for_type(type_name)
        version_macro = version_macro_for_type(type_name)
        block = enum_type(type_name, is_flags=is_flags)
        section.append(dict(block=block, platform=platform_macro, version=version_macro))

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
            platform_macro = platform_macro_for_type(type_name)
            version_macro = version_macro_for_type(type_name)
            block = handle_type(type_name)
            handles.append(dict(block=block, platform=platform_macro, version=version_macro))
        elif category == "struct":
            type_name = type_entry.attrib["name"]
            if stype := type_entry.find("./member"):
                stype = stype.attrib.get("values")
                if stype and not stype.startswith("VK_STRUCTURE_TYPE"):
                    stype = None
            platform_macro = platform_macro_for_type(type_name)
            version_macro = version_macro_for_type(type_name)
            block = struct_type(type_name, stype_value=stype)
            structs.append(dict(block=block, platform=platform_macro, version=version_macro))

    def sort_key(blk: dict) -> str:
        p = blk['platform'] or "0"
        v = blk['version'] or "0"
        return f"{p}_{v}"

    enums.sort(key=sort_key)
    flags.sort(key=sort_key)
    handles.sort(key=sort_key)
    structs.sort(key=sort_key)

    add_grouped_to_section(ENUMS_SECTION, enums)
    add_grouped_to_section(FLAGS_SECTION, flags)
    add_grouped_to_section(HANDLES_SECTION, handles)
    add_grouped_to_section(STRUCTS_SECTION, structs)


gen_type_wrappers()
write_vku_h()
