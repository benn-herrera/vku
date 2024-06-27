# vku
## A single header C++ type library for Vulkan
### Principles
* Minimal coding mercy (no RAII)
* Unopinionated
    * Just adds some mercy utility types and simple, useful functions
    * Does not constrain usage of Vulkan
    * None of the Vulkan API functions are wrapped
* No additional dependencies
* No use of std:: strings or containers
* No boost syndrome
    * No bloat or major compilation overhead.
    * Using one function or type does not compel the use of others
    * All types are mix & match with base API - incremental adoption is painless

### Types
* Structs subclassed with default zero initialization
    * sType assigned when present 
* Enum wrappers with default initialization to invalid values
* Flags type wrappers with default zero initialization
* Handle type wrappers with default null initialization
* VK_NULL_HANDLE definition added if not defined

All wrapped types work interchangeably with base types in the base API

### Metadata Functions
* const char* vku::to_string(<VkEnumType>) added for all enum types
* VK_FORMAT property getters and predicates
* const char* vku::to_string(const VkStructType&, const void* member) for selected classes

## Usage
* For Existing Versions
    * Clone repo and add [vk-sdk-version]/include to your project's include path
    * all inline
        * add -DVKU_INLINE_ALL to compiler options
        * #include "vku/vku.h"
    * compile utility functions
       * in one C++ source file define VKU_IMPLEMENT before including vku/vku.h 
* Adding a new version
    * Python 3.11+ required
        * No additional packages needed
    * ./gen_vku.sh <MAJ.min.patch> # eg 1.3.280
        * On Windows run from git bash 
    * version must match a tag in https://github.com/KhronosGroup/VulkanHeaders.gits
    * ./gen_vku.sh -h for more details.

### TODO:
* CMake file with install rule
