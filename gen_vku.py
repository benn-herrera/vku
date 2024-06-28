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
// {VKU_H.name} {VKU_H.parent.parent.parent.name} generated {datetime.now} by {Path(sys.argv[0]).name}
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

#if !defined(VK_NULL_HANDLE)
# define VK_NULL_HANDLE 0
#endif

namespace vku {{
"""[1:-1]


# TODO: break out the functionality of the operator macros
# into a python function that inlines the equivalent.
# makes for easier debugging when you can step into an explicit line of code.
WRAPPER_TEMPLATES = """
#define VKU_FRIEND_OP(OP) \\
    friend auto operator OP(const UType& lhs, const VkType rhs) { return lhs.v OP rhs; } \\
    friend auto operator OP(const VkType lhs, const UType& rhs) { return lhs OP rhs.v; }    

#define VKU_MOD_OP(OP) \\
    VkType operator OP(const VkType rhs) { v OP rhs; return v; }

#define VKU_FRIEND_COMPS() \\
    VKU_FRIEND_OP(==) \\
    VKU_FRIEND_OP(!=) \\
    VKU_FRIEND_OP(<) \\
    VKU_FRIEND_OP(>=) \\
    VKU_FRIEND_OP(>) \\
    VKU_FRIEND_OP(>=)

  template<typename T, unsigned int I>
  struct EnumT {
    using UType = EnumT;
    using VkType = T;
    static constexpr auto kInitVal = (VkType)I;
    
    EnumT(VkType i=kInitVal) : v(i) {}
    
    operator VkType() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }

    VKU_MOD_OP(=);
    VKU_FRIEND_COMPS();    
  private:
    VkType v;
  };

  template<typename T>
  struct FlagsT {
    using UType = FlagsT;
    using VkType = T;
    
    FlagsT(VkType i=(VkType)0) : v(i) {}
    
    operator VkType() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
    operator bool() const { return !!v; }
    bool operator!() const { return v; }
    
    VKU_MOD_OP(=);    
    VKU_MOD_OP(|=);
    VKU_MOD_OP(&=);
    VKU_MOD_OP(^=);
    VKU_MOD_OP(+=);
    VKU_MOD_OP(-=);
    
    VKU_FRIEND_COMPS();
    VKU_FRIEND_OP(|);
    VKU_FRIEND_OP(&);
    VKU_FRIEND_OP(^);
    VKU_FRIEND_OP(+);
    VKU_FRIEND_OP(-);
  private:
    VkType v;
  };
  
 template<typename T>
  struct HandleT {
    using UType = HandleT;
    using VkType = T;
    
    HandleT(VkType i = (VkType)0) : v(i) {}
    
    operator VkType() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
    operator bool() const { return !!v; }
    bool operator!() const { return v; }
    
    VKU_MOD_OP(=);
    
    VKU_FRIEND_OP(==);
    VKU_FRIEND_OP(!=);
  private:
    VkType v;
  };
#undef VKU_FRIEND_OP
#undef VKU_MOD_OP
#undef VKU_FRIEND_COMPS
"""[1:-1]


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
  // wrapped handle types"
"""[1:-1]
]


STRUCTS_SECTION = [
"""
  // struct wrappers
  template<typename VkS, int SType>
  struct SWrap : public VkS {
    SWrap() : VkS{} {
        sType = (VkStructureType)SType;
    }
    SWrap(const SWrap&) = default;    
    SWrap(const VkS& s) = default;
  };
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
