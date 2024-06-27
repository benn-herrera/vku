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

namespace vku {{
"""[1:-1]


ENUMS_SECTION = [
"""
  // enum wrappers
  template<typename VkE, int Init=0>
  struct EWrap {
    EWrap() = default;
    EWrap(const EWrap&) = default;    
    EWrap(VkE e) : val(e) {}
    operator VkE() const { return val; }    
    EWrap operator=(const EWrap&) = default;
    EWrap operator=(VkE e) { val = e; return *this; }
    VkE val = (E)Init;
  };
"""[1:-1]
]


FLAGS_SECTION = [
"""
  // flags wrappers"
  template<typename VkF>
  struct FWrap {
    FWrap() = default;
    FWrap(const FWrap&) = default;    
    FWrap(VkF f) : val(f) {}
    operator VkF() const { return val; }    
    FWrap operator=(const FWrap&) = default;
    FWrap operator=(VkF f) { val = f; return *this; }
    VkF val = (VkF)0;
    // TODO: friend operators
  };
"""[1:-1]
]


HANDLES_SECTION = [
"""
  // handle wrappers"
#if !defined(VK_NULL_HANDLE)
# define VK_NULL_HANDLE nullptr
#endif
  template<typename VkH>
  struct HWrap {
    HWrap() = default;
    HWrap(const HWrap&) = default;    
    HWrap(VkH h) : val(h) {}
    operator VkH() const { return val; }    
    HWrap operator=(const FWrap&) = default;
    HWrap operator=(VkH h) { val = h; return *this; }  
    VkH val = VK_NULL_HANDLE;
  };
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
