# vku
## A single header C++ type and utility library for Vulkan
### Principle
* Unopinionated
  * Does not constrain usage of Vulkan
  * Does not require wholesale adoption
* Minimal coding mercy
  * Adds utility types and simple, useful functions
  * Vulkan API functions are not wrapped
  * No required dependencies beyond Vulkan headers
  * No use of std:: strings or containers (or std:: anything)
  * No heap allocations
  * Minimal impact on compile time
      * As anything generated from vulkan.xml is, this header is long
      * The constructs used are simple
      * Most of the lines are type aliases and switch cases.

### Types
* Structs subclassed with default zero initialization
    * Info types automatically assign correct sType in construction
    * Copy constructor and assignment operators safeguard sType value
* Some utility functions take or return dimensions
  * If VKU_USE_GLM is defined glm vector types will be used
  * If not, simple structs defined.
  * Whether via GLM or simple structs these types are available
    * float coords: vec2, vec3
    * int32_t coords: ivec2, ivec3
    * uint32_t coords: uvec2, uvec3
* Several spatial structs subclassed for conversion and assignment convenience
    * VkOffset2D, VkOffset3D
      * easy conversion from/to ivec2, ivec3
    * VkExtent2D, VkExtent3D
      * easy conversion to/from uvec2, uvec3
    * VkRect2D
      * easy construction from ivec2 offset + uvec2 extent
      * easy conversion to/from VkViewport
    * VkViewport
      * easy conversion to/from VkRect2D
      * easy assignment to offset & extent from vector types
* Simple zero-init wrappers for enum, flags, and handle types
  * More for completeness of type space than massive utility 
* All types are mix & match with base API - incremental integration is painless
* Wrapped types work interchangeably with base types in the base Vulkan API

### Metadata Functions
* const char* vku::to_string(Vk<EnumType>) for all enum types
    * Enum types that are aliased to VkFlags64 have explicitly named to_string()
        * e.g. VkEnumTypeFoo -> enum_type_foo_to_string(VkEnumTypeFoo v); 
        * This was the simplest of a set of imperfect options
* VK_FORMAT metadata getters
    * UncompressedFormatMetadata get_uncompressed_format_metadata(VkFormat)
    * CompressedFormatMetadata get_ccompressed_format_metadata(VkFormat)
    * VideoFormatMetadata get_video_format_metadata(VkFormat fmt)
### General Utility Functions
* uint32_t get_uncompressed_image_texel_count(uvec2 size, uint32_t mip_max, uint32_t array_len)
* uint32_t get_uncompressed_image_size_bytes(VkFormat fnt, uvec2 size, bool use_mips, uint32_t array_len)
* VKU_PROTO VkFormat vanilla_format_for(uint32_t channel_count, NumericFormat nf, uint32_t channel_bit_count, bool packed)
    * For the given channel count, numeric format, channel bit count find a format
    * R, RG, RGB, or RGBA uncompressed, homogenous, base API level format

## Usage
* For Existing Header Versions
    * Clone repo and add vku/[vk-sdk-version]/include to your project's include path
    * all inline
        * add -DVKU_INLINE_ALL to compiler options
        * #include "vku/vku.h"
    * compile utility functions
       * in one C++ source file define VKU_IMPLEMENT before including vku/vku.h 
* Adding a new version
    * Python 3.11+ required (previous versions may work. YMMV.)
        * No additional packages needed
    * ./gen_vku.sh <MAJ.min.patch> # eg 1.3.280
        * On Windows run from git bash 
    * version must match a tag in https://github.com/KhronosGroup/VulkanHeaders.git
    * ./gen_vku.sh -h for more details.

### TODO:
* CMake file with install rule
