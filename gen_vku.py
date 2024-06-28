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

tree = ET.parse(VK_XML)
root = tree.getroot()

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
# include "vulkan.h"
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

PRIM_MOD_OP_FMT = """
    VkType operator {OP}(const VkType rhs) {{ v {OP} rhs; return v; }}
"""[1:-1]

STRUCT_MOD_OP_FMT = """
    VkType& operator {OP}(const VkType rhs) {{ v {OP} rhs; return v; }}
"""[1:-1]

UNARY_OP_FMT = """
    auto operator {OP}(){{ return {OP}(v); }}
"""[1:-1]

CAST_OPS = """
    operator const VkType&() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
"""[1:-1]

PRIM_ASSIGN_OPS = PRIM_MOD_OP_FMT.format(OP='=')
STRUCT_ASSIGN_OPS = STRUCT_MOD_OP_FMT.format(OP='=')

BOOL_OPS = ".\n".join([
    UNARY_OP_FMT.format(OP='bool'),
    UNARY_OP_FMT.format(OP='!'),
])[:-1]

RMW_MOD_OPS = "\n".join([
    PRIM_MOD_OP_FMT.format(OP='|='),
    PRIM_MOD_OP_FMT.format(OP='&='),
    PRIM_MOD_OP_FMT.format(OP='^='),
    PRIM_MOD_OP_FMT.format(OP='+='),
    PRIM_MOD_OP_FMT.format(OP='-='),
])[:-1]

FRIEND_COMP_OPS = "\n".join([
    FRIEND_OP_FMT.format(OP='<'),
    FRIEND_OP_FMT.format(OP='<='),
    FRIEND_OP_FMT.format(OP='>'),
    FRIEND_OP_FMT.format(OP='>=')
])[:-1]

FRIEND_EQ_OPS = "\n".join([
    FRIEND_OP_FMT.format(OP='=='),
    FRIEND_OP_FMT.format(OP='!='),
])[:-1]

FRIEND_EXPR_OPS = "\n".join([
    FRIEND_OP_FMT.format(OP='|'),
    FRIEND_OP_FMT.format(OP='&'),
    FRIEND_OP_FMT.format(OP='^'),
    FRIEND_OP_FMT.format(OP='+'),
    FRIEND_OP_FMT.format(OP='-')
])

WRAPPER_TEMPLATES = ".\n".join([
"""
  template<typename T, unsigned int I>
  struct EnumT {
    static constexpr auto kInitVal = (VkType)I;     
    using UType = EnumT;    
    using VkType = T;        
    EnumT(VkType i=kInitVal) : v(i) {}    
""",
    PRIM_ASSIGN_OPS,
    CAST_OPS,
    FRIEND_COMP_OPS,
    FRIEND_EQ_OPS,
"""  private:
    VkType v;
  };

  template<typename T>
  struct FlagsT {
    using UType = FlagsT;
    using VkType = T;
    
    FlagsT(VkType i=(VkType)0) : v(i) {}    
""",
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
  struct HandleT {
    using UType = HandleT;
    using VkType = T;
    
    HandleT(VkType i = (VkType)0) : v(i) {}    
""",
    PRIM_ASSIGN_OPS,
    BOOL_OPS,
    CAST_OPS,
    FRIEND_EQ_OPS,
"""  private:
    VkType v;
  };
"""[1:-1],
"""
  template<class T, int TypeVal>
  struct InfoT : public T {
    using UType = InfoT;
    using VkType = T;
    static constexpr auto kStructType = (VkStructureType)TypeVal;
    InfoT() { *this = VkType{ kStructType }; }
    InfoT(const VkType& rhs) { *((VkType*)this) = rhs; }
""",
    CAST_OPS,
    STRUCT_ASSIGN_OPS,
"""  };

  template<typename T>
  struct DescriptionT : public T {
    using UType = DescriptionT;
    using VkType = T;
    DescriptionT() { *this = VkType{}; }
    DescriptionT(const VkType& rhs) { *((VkType*)this) = bd; }
""",
    CAST_OPS,
    PRIM_ASSIGN_OPS,
"""  };
"""
])[1:-1]


ENUMS_SECTION = [
"""
  // wrapped enum types
"""[1:-1]
]


FLAGS_SECTION = [
"""
  // wrapped flag types
  using Flags = FlagsT<VkFlags>;
"""[1:-1]
]


HANDLES_SECTION = [
"""
  // wrapped handle types
"""[1:-1]
]


STRUCTS_SECTION = [
"""
  // wrapped info (type identified) and description (not type identified) structs
"""[1:-1]
]


FUNCTION_PROTOS_HEADER = """
// function prototypes
#if !defined(VKU_INLINE_ALL)
"""[1:-1]

FUNCTION_PROTOS_SECTION = [
  "  extern const char* member_to_string_vp(const VkPhysicalDeviceFeatures&, const void* member);"
]


FUNCTION_PROTOS_FOOTER = """
#endif // VKU_INLINE_ALL
"""[1:-1]


FUNCTIONS_HEADER = """
// function implementations
#if defined(VKU_IMPLEMENT) || defined(VKU_INLINE_ALL)
"""[1:-1]


FUNCTIONS_IMPL_SECTION = [
"""
  VKU_FUNC const char* member_to_string_vp(const VkPhysicalDeviceFeatures& s, const void* member) {
    return nullptr;
  }
"""[1:-1]
]


FUNCTIONS_FOOTER = """
#endif // VKU_IMPLEMENT || VKU_INLINE_ALL
"""[1:-1]


ALWAYS_INLINE_FUNCTIONS_SECTION = [
"""
  // always inlined functions
  template<MT>
  inline const char* to_string(const VkPhysicalDeviceFeatures& s, const MT& m) {
      return member_to_string_vp(s, &m);
  }  
"""[1:-1]
]


FILE_FOOTER="""
} // end namespace vku
"""[1:-1]

FILE_SECTIONS = [
    FILE_HEADER,
    WRAPPER_TEMPLATES,
    "",
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
VKU_H.write_text("\n".join(FILE_SECTIONS))
