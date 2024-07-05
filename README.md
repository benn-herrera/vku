# vku
## A single header C++ type and utility library for Vulkan
### Principles
* Minimal coding mercy
* Unopinionated
    * Just adds some mercy utility types and simple, useful functions
    * Does not constrain usage of Vulkan
    * None of the Vulkan API functions are wrapped
* No required dependencies beyond vulkan headers
* No use of std:: strings or containers
* No heap allocations
* All types are mix & match with base API - incremental integration is painless

### Types
* Structs subclassed with default zero initialization
    * sType assigned when present 
    * Copy constructor and assignment operators safeguard sType value
* Enum wrappers with default zero initialization and explicit invalid value
* Flags type wrappers with default zero initialization
* Handle type wrappers with default null initialization
* Some utility functions take or return dimensions
  * If VKU_USE_GLM is defined glm vector types will be used
  * If not, simple 2 and 3 vector structs are used.

All wrapped types work interchangeably with base types in the base API

### Metadata Functions
* const char* vku::to_string(Vk<EnumType>) for all enum types
    * Enum types that are aliased to VkFlags64 have explicitly named to_string()
        * e.g. VkEnumTypeFoo -> enum_type_foo_to_string(VkEnumTypeFoo v); 
        * This was the simplest of a set of imperfect options
* VK_FORMAT property getters and predicates. e.g.
    * bool has_float_channels(VkFormat f)
    * int get_channel_count(VkFormat f)
    * int get_sample_size_bytes(Vkformat f)

### General Utility Functions
    * unsigned int get_mip_levels(unsigned int w, unsigned int h);
    * unsigned int get_mip_size(unsigned int w, unsigned int h, unsigned int mip);
    * unsigned int 

## Usage
* For Existing Header Versions
    * Clone repo and add vku/[vk-sdk-version]/include to your project's include path
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
