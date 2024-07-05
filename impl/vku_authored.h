
#if defined(VKU_USE_GLM)
# include "glm/vec2.hpp
# include "glm/vec3.hpp
namespace vku {
  using vec2 = glm::vec2;
  using uvec2 = glm::uvec2;
  using ivec2 = glm::ivec2;
  using vec3 = glm::vec3;
  using uvec3 = glm::uvec3;
  using ivec3 = glm::ivec3;
}
#else // !VKU_USE_GLM
namespace vku {
  // nothing complicated needed. just a collection of coordinates
  template<typename T>
  struct vec2T {
    using Coord = T;
    Coord x;
    Coord y;

    // minimum needed for utility functions
    vec2T operator-(const vec2T& rhs) const { return { x - rhs.x, y - rhs.y }; }
  };

  template<typename T>
  struct vec3T {
    using Coord = T;
    Coord x;
    Coord y;
    Coord z;
  };

  using vec2 = vec2T<float>;
  using uvec2 = vec2T<unsigned int>;
  using ivec2 = vec2T<int>;

  using vec3 = vec3T<float>;
  using uvec3 = vec3T<unsigned int>;
  using ivec3 = vec3T<int>;
}
#endif // !VKU_USE_GLM


namespace vku {
  // always inlined functions
  template<typename T>
  inline const char* to_string(const T v, const char* invalidStr) {
    auto str = to_string(v);
    return str ? str : invalidStr;
  }

  inline unsigned int get_uncompressed_mip_count(const uvec2& image_size) {
    unsigned int m = 0;
    for (auto d = image_size.x < image_size.y ? image_size.x : image_size.y; bool(d >> m); ++m)
        ;
    return m;
  }

  inline unsigned int get_uncompressed_mip_sample_count(const uvec2& image_size, unsigned int mip, unsigned int array_len=1) {
    return (image_size.x >> mip) * (image_size.y >> mip) * array_len;
  }

  // prototypes
  VKU_PROTO unsigned int get_uncompressed_image_sample_count(uvec2 image_size, unsigned int mip_max = ~0u, unsigned int array_len=1);
  VKU_PROTO unsigned int get_uncompressed_image_size_bytes(VkFormat format, const uvec2& image_size, bool mip_mapped, unsigned int array_len=1);

  // implementations
#if defined(VKU_INLINE_ALL) || defined(VKU_IMPLEMENT)
  VKU_IMPL unsigned int get_uncompressed_image_sample_count(uvec2 image_size, unsigned int mip_max, unsigned int array_len) {
    for (unsigned int m = 0, c = 0; m < mip_max; ++m, image_size.x >>= 1, image_size.y >>= 1) {
      if (auto mip_sample_count = image_size.x * image_size.y) {
        c += mip_sample_count;
        continue;
      }
      return c * array_len;
    }
  }

  VKU_IMPL unsigned int get_uncompressed_image_size_bytes(VkFormat format, const uvec2& image_size, bool mip_mapped, unsigned int array_len) {
    return get_uncompressed_image_sample_count(image_size, mip_mapped ? ~0u : 1u, array_len) *
               get_uncompressed_sample_size_bytes(format);
  }
#endif // VKU_INLINE_ALL || VKU_IMPLEMENT

  inline unsigned int get_uncompressed_mip_size_bytes(VkFormat format, uvec2 image_size, unsigned int mip, unsigned int array_len=1) {
    return get_uncompressed_mip_sample_count(image_size, mip, array_len) * get_uncompressed_sample_size_bytes(format);
  }

  inline unsigned int get_uncompressed_mip_byte_offset(VkFormat format, const uvec2& image_size, unsigned int mip, unsigned int array_len=1) {
    return get_uncompressed_image_sample_count(image_size, mip, array_len) * get_uncompressed_sample_size_bytes(format);
  }
} // namespace vku

