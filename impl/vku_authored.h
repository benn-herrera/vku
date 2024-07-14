
#if defined(VKU_USE_GLM)
# include "glm/vec2.hpp
# include "glm/vec3.hpp
namespace vku {
  using vec2 = vec2;
  using uvec2 = uvec2;
  using ivec2 = ivec2;
  using vec3 = vec3;
  using uvec3 = uvec3;
  using ivec3 = ivec3;
}
#else // !VKU_USE_GLM
namespace vku {
  // nothing complicated needed. just a collection of coordinates
  template<typename T>
  struct vec2T {
    using Coord = T;
    Coord x;
    Coord y;
  };

  template<typename T>
  struct vec3T {
    using Coord = T;
    Coord x;
    Coord y;
    Coord z;
  };

  using vec2 = vec2T<float>;
  using uvec2 = vec2T<uint32_t>;
  using ivec2 = vec2T<int32_t>;

  using vec3 = vec3T<float>;
  using uvec3 = vec3T<uint32_t>;
  using ivec3 = vec3T<int32_t>;
}
#endif // !VKU_USE_GLM


namespace vku {
  //
  // wrappers with convenience extensions
  //

  struct Offset2D : VkOffset2D {
    Offset2D() : VkOffset2D(VkOffset2D{}) {}
    Offset2D(const VkOffset2D& i) : VkOffset2D(i) {}
    Offset2D(const Offset2D&) = default;
    Offset2D(const ivec2& i) { *this = i; }
    Offset2D& operator=(const Offset2D&) = default;
    Offset2D& operator=(const VkOffset2D& rhs) {
        ((VkOffset2D&)*this) = rhs;
        return *this;
    }
    Offset2D& operator=(const ivec2& rhs) {
      x = rhs.x;
      y = rhs.y;
      return *this;
    }
    operator ivec2() const { return {x, y}; }
  };

  struct Extent2D : VkExtent2D {
    Extent2D() : VkExtent2D(VkExtent2D{}) {}
    Extent2D(const VkExtent2D& i) : VkExtent2D(i) {}
    Extent2D(const Extent2D&) = default;
    Extent2D(const uvec2& i) { *this = i; }
    Extent2D& operator=(const Extent2D&) = default;
    Extent2D& operator=(const VkExtent2D& rhs) {
      ((VkExtent2D&)*this) = rhs;
      return *this;
    }
    Extent2D& operator=(const uvec2& rhs) {
      width = rhs.x;
      height = rhs.y;
      return *this;
    }
    operator uvec2() const {
      return {width, height};
    }
  };

  struct Rect2D : VkRect2D {
    Rect2D() : VkRect2D(VkRect2D{}) {}
    Rect2D(const Rect2D&) = default;
    Rect2D(const VkRect2D& i) : VkRect2D(i) {}
    Rect2D(const Offset2D& os, const Extent2D& ex) { offset = os; extent = ex; }
    Rect2D(const ivec2& os, const uvec2& ex) { vkuOffset() = os; vkuExtent() = ex; }
    explicit Rect2D(const VkViewport& vp);
    explicit Rect2D(const Extent2D& ex) { offset = Offset2D(); extent = ex; }
    explicit Rect2D(const uvec2& ex) { offset = Offset2D(); vkuExtent() = ex; }
    const Offset2D& vkuOffset() const { return (const Offset2D&)offset; }
    const Extent2D& vkuExtent() const { return (const Extent2D&)extent; }
    Offset2D& vkuOffset() { return (Offset2D&)offset; }
    Extent2D& vkuExtent() { return (Extent2D&)extent; }
    Rect2D& operator=(const Rect2D&) = default;
    Rect2D& operator=(const VkRect2D& rhs) {
      ((VkRect2D&)*this) = rhs;
      return *this;
    }
  };

  struct Offset3D : VkOffset3D {
    Offset3D() : VkOffset3D(VkOffset3D{}) {}
    Offset3D(const VkOffset3D& i) : VkOffset3D(i) {}
    Offset3D(const Offset3D&) = default;
    Offset3D(const ivec3& i) { *this = i; }
    explicit Offset3D(const VkOffset2D& i, int32_t iz=0) {
      x = i.x;
      y = i.y;
      z = iz;
    }
    Offset3D& operator=(const Offset3D&) = default;
    Offset3D& operator=(const VkOffset3D& rhs) {
      ((VkOffset3D&)*this) = rhs;
      return *this;
    }
    Offset3D& operator=(const ivec3& rhs) {
      x = rhs.x;
      y = rhs.y;
      z = rhs.z;
      return *this;
    }
    operator ivec3() const {
      return {x, y, z};
    }
  };

  struct Extent3D : VkExtent3D {
    Extent3D() : VkExtent3D(VkExtent3D{}) {}
    Extent3D(const VkExtent3D& i) : VkExtent3D(i) {}
    Extent3D(const Extent3D&) = default;
    explicit Extent3D(const VkExtent2D& i, uint32_t _depth=1) {
      width = i.width;
      height = i.height;
      depth = _depth;
    }
    Extent3D(const uvec3& i) { *this = i; }
    Extent3D& operator=(const Extent3D&) = default;
    Extent3D& operator=(const VkExtent3D& rhs) {
      ((VkExtent3D&)*this) = rhs;
      return *this;
    }
    Extent3D& operator=(const uvec3& rhs) {
      width = rhs.x;
      height = rhs.y;
      depth = rhs.z;
      return *this;
    }
    operator uvec3() const {
      return {width, height, depth};
    }
  };

  struct Viewport : VkViewport {
    Viewport() : VkViewport(VkViewport{}) {}
    Viewport(const Viewport&) = default;
    Viewport(const VkViewport& i) : VkViewport(i) {}
    explicit Viewport(const VkRect2D& i, float _maxDepth = 1.0f) {
      maxDepth = _maxDepth;
      offset() = vec2{ float(i.offset.x), float(i.offset.y) };
      extent() = vec2{ float(i.extent.width), float(i.extent.height) };
    }
    Viewport(const vec2& _offset, const vec2& _extent, float _maxDepth=1.0f) {
      maxDepth = _maxDepth;
      offset() = _offset;
      extent() = _extent;
    }
    explicit Viewport(const vec2& _extent) : Viewport() { extent() = _extent; }

    Viewport& operator=(const Viewport&) = default;
    Viewport& operator=(const VkViewport& rhs) {
      ((VkViewport&)*this) = rhs;
      return *this;
    }
    const vec2& offset() const { return *((const vec2*) &x); }
    const vec2& extent() const { return *((const vec2*) &width); }
    vec2& offset() { return *((vec2*) &x); }
    vec2& extent() { return *((vec2*) &width); }
  };

  inline Rect2D::Rect2D(const VkViewport& vp) {
    offset.x = int32_t(vp.x);
    offset.y = int32_t(vp.y);
    extent.width = uint32_t(vp.width);
    extent.height = uint32_t(vp.height);
  }

  //
  // prototypes
  //

  VKU_PROTO uint32_t get_uncompressed_image_texel_count(uvec2 image_size, uint32_t mip_max = ~0u, uint32_t array_len=1);
  VKU_PROTO uint32_t get_uncompressed_image_size_bytes(VkFormat format, const uvec2& image_size, bool mip_mapped, uint32_t array_len=1);
  // R, RG, RGB, or RGBA uncompressed, homogenous, base API level format.
  VKU_PROTO VkFormat vanilla_format_for(uint32_t channel_count, NumericFormat nf, uint32_t bit_count, bool packed=false);

#if defined(VKU_INLINE_ALL) || defined(VKU_IMPLEMENT)
  //
  // implementations
  //

  VKU_IMPL uint32_t get_uncompressed_image_texel_count(uvec2 image_size, uint32_t mip_max, uint32_t array_len) {
    uint32_t c = 0;
    for (uint32_t m = 0; m < mip_max; ++m, image_size.x >>= 1, image_size.y >>= 1) {
      if (auto mip_texel_count = image_size.x * image_size.y) {
        c += mip_texel_count;
        continue;
      }
      break;
    }
    return c * array_len;
  }

  VKU_IMPL uint32_t get_uncompressed_image_size_bytes(VkFormat format, const uvec2& image_size, bool mip_mapped, uint32_t array_len) {
    return get_uncompressed_image_texel_count(image_size, mip_mapped ? ~0u : 1u, array_len) *
               get_uncompressed_format_metadata(format).size_bytes;
  }

  VKU_IMPL VkFormat vanilla_format_for(uint32_t channel_count, NumericFormat nf, uint32_t bit_count, bool packed) {
    // 0 is VK_FORMAT_UNDEFINED, start at 1
    for (uint32_t fi = 1, fe = uint32_t(kLastBaseFormat) + 1; fi < fe; ++fi) {
      const auto f = VkFormat(fi);
      if (UncompressedFormatMetadata md = get_uncompressed_format_metadata(f)) {
        if ( md.channel_count == channel_count &&
             md.is_homogenous() &&
             md.has_numeric_format(nf) &&
             md.channels[0].bit_count == bit_count &&
             md.is_packed() == packed
        ) {
          return f;
        }
        continue;
      }
      break;
    }
    return VK_FORMAT_UNDEFINED;
  }
#endif // VKU_INLINE_ALL || VKU_IMPLEMENT

  template<typename T>
  inline const char* to_string(const T v, const char* invalidStr) {
    auto str = to_string(v);
    return str ? str : invalidStr;
  }

  inline uint32_t get_uncompressed_mip_count(const uvec2& image_size) {
    uint32_t m = 0;
    for (auto d = image_size.x < image_size.y ? image_size.x : image_size.y; bool(d >> m); ++m)
        ;
    return m;
  }

  inline uint32_t get_uncompressed_mip_texel_count(const uvec2& image_size, uint32_t mip, uint32_t array_len=1) {
    return (image_size.x >> mip) * (image_size.y >> mip) * array_len;
  }

  inline uint32_t get_format_extension(VkFormat f) {
    return (uint32_t(f) < 1000u) ? 0u : ((uint32_t(f) - 1000000000u) / 1000u) + 1u;
  }

  inline bool is_extended_format(VkFormat f) {
    return !!get_format_extension(f);
  }

  inline uint32_t get_uncompressed_mip_size_bytes(VkFormat format, uvec2 image_size, uint32_t mip, uint32_t array_len=1) {
    return get_uncompressed_mip_texel_count(image_size, mip, array_len) * get_uncompressed_format_metadata(format).size_bytes;
  }

  inline uint32_t get_uncompressed_mip_byte_offset(VkFormat format, const uvec2& image_size, uint32_t mip, uint32_t array_len=1) {
    return get_uncompressed_image_texel_count(image_size, mip, array_len) * get_uncompressed_format_metadata(format).size_bytes;
  }

  inline VkFormatFeatureFlags image_usage_to_format_feature_flags(VkImageUsageFlags usage) {
    FormatFeatureFlagBits features;
    if (usage & VK_IMAGE_USAGE_TRANSFER_SRC_BIT) { features |= VK_FORMAT_FEATURE_TRANSFER_SRC_BIT; }
    if (usage & VK_IMAGE_USAGE_TRANSFER_DST_BIT) { features |= VK_FORMAT_FEATURE_TRANSFER_DST_BIT; }
    if (usage & VK_IMAGE_USAGE_SAMPLED_BIT) { features |= VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT; }
    if (usage & VK_IMAGE_USAGE_STORAGE_BIT) { features |= VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT; }
    if (usage & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT) { features |= VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT; }
    if (usage & VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT) { features |= VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT; }
    return features;
  }
} // namespace vku

