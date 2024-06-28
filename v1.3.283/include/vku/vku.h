#pragma once
// vku.h v1.3.283 generated 2024-06-27 23:44:34.138786 by gen_vku.py
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

namespace vku {
template<typename T, uint32_t I>
  struct EnumT {
    using UType = EnumT;
    using VkType = T;  
    static constexpr auto kInitVal = (VkType)I;
    EnumT(VkType i=kInitVal) : v(i) {}
    VkType operator =(const VkType rhs) { v = rhs; return v; }
    operator const VkType&() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
    friend auto operator <(const UType& lhs, const VkType rhs) { return lhs.v < rhs; }
    friend auto operator <(const VkType lhs, const UType& rhs) { return lhs < rhs.v; }
    friend auto operator <=(const UType& lhs, const VkType rhs) { return lhs.v <= rhs; }
    friend auto operator <=(const VkType lhs, const UType& rhs) { return lhs <= rhs.v; }
    friend auto operator >(const UType& lhs, const VkType rhs) { return lhs.v > rhs; }
    friend auto operator >(const VkType lhs, const UType& rhs) { return lhs > rhs.v; }
    friend auto operator >=(const UType& lhs, const VkType rhs) { return lhs.v >= rhs; }
    friend auto operator >=(const VkType lhs, const UType& rhs) { return lhs >= rhs.v; }
    friend auto operator ==(const UType& lhs, const VkType rhs) { return lhs.v == rhs; }
    friend auto operator ==(const VkType lhs, const UType& rhs) { return lhs == rhs.v; }
    friend auto operator !=(const UType& lhs, const VkType rhs) { return lhs.v != rhs; }
    friend auto operator !=(const VkType lhs, const UType& rhs) { return lhs != rhs.v; }
  private:
    VkType v;
  };

  template<typename T>
  struct FlagsT {
    using UType = FlagsT;
    using VkType = T;
    
    FlagsT(VkType i=(VkType)0) : v(i) {}
    VkType operator =(const VkType rhs) { v = rhs; return v; }
    operator bool(){ return bool(v); }
    auto operator !(){ return !(v); }
    operator const VkType&() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
    VkType operator |=(const VkType rhs) { v |= rhs; return v; }
    VkType operator &=(const VkType rhs) { v &= rhs; return v; }
    VkType operator ^=(const VkType rhs) { v ^= rhs; return v; }
    VkType operator +=(const VkType rhs) { v += rhs; return v; }
    VkType operator -=(const VkType rhs) { v -= rhs; return v; }
    friend auto operator <(const UType& lhs, const VkType rhs) { return lhs.v < rhs; }
    friend auto operator <(const VkType lhs, const UType& rhs) { return lhs < rhs.v; }
    friend auto operator <=(const UType& lhs, const VkType rhs) { return lhs.v <= rhs; }
    friend auto operator <=(const VkType lhs, const UType& rhs) { return lhs <= rhs.v; }
    friend auto operator >(const UType& lhs, const VkType rhs) { return lhs.v > rhs; }
    friend auto operator >(const VkType lhs, const UType& rhs) { return lhs > rhs.v; }
    friend auto operator >=(const UType& lhs, const VkType rhs) { return lhs.v >= rhs; }
    friend auto operator >=(const VkType lhs, const UType& rhs) { return lhs >= rhs.v; }
    friend auto operator ==(const UType& lhs, const VkType rhs) { return lhs.v == rhs; }
    friend auto operator ==(const VkType lhs, const UType& rhs) { return lhs == rhs.v; }
    friend auto operator !=(const UType& lhs, const VkType rhs) { return lhs.v != rhs; }
    friend auto operator !=(const VkType lhs, const UType& rhs) { return lhs != rhs.v; }
    friend auto operator |(const UType& lhs, const VkType rhs) { return lhs.v | rhs; }
    friend auto operator |(const VkType lhs, const UType& rhs) { return lhs | rhs.v; }
    friend auto operator &(const UType& lhs, const VkType rhs) { return lhs.v & rhs; }
    friend auto operator &(const VkType lhs, const UType& rhs) { return lhs & rhs.v; }
    friend auto operator ^(const UType& lhs, const VkType rhs) { return lhs.v ^ rhs; }
    friend auto operator ^(const VkType lhs, const UType& rhs) { return lhs ^ rhs.v; }
    friend auto operator +(const UType& lhs, const VkType rhs) { return lhs.v + rhs; }
    friend auto operator +(const VkType lhs, const UType& rhs) { return lhs + rhs.v; }
    friend auto operator -(const UType& lhs, const VkType rhs) { return lhs.v - rhs; }
    friend auto operator -(const VkType lhs, const UType& rhs) { return lhs - rhs.v; }
  private:
    VkType v;
  };

 template<typename T>
  struct HandleT {
    using UType = HandleT;
    using VkType = T;

    HandleT(VkType i = (VkType)0) : v(i) {}
    VkType operator =(const VkType rhs) { v = rhs; return v; }
    operator bool(){ return bool(v); }
    auto operator !(){ return !(v); }
    operator const VkType&() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
    friend auto operator ==(const UType& lhs, const VkType rhs) { return lhs.v == rhs; }
    friend auto operator ==(const VkType lhs, const UType& rhs) { return lhs == rhs.v; }
    friend auto operator !=(const UType& lhs, const VkType rhs) { return lhs.v != rhs; }
    friend auto operator !=(const VkType lhs, const UType& rhs) { return lhs != rhs.v; }

  private:
    VkType v;
  };
  template<class T, int32_t STYPE>
  struct InfoT : public T {
    using UType = InfoT;
    using VkType = T;
    static constexpr auto kStructType = VkStructureType(STYPE);
    InfoT() { *this = VkType{ kStructType }; }
    InfoT(const VkType& rhs) { (VkType&)*this = rhs; }
    VkType& operator =(const VkType& rhs) { (VkType&)*this = rhs; return *this; }
  };

  template<typename T>
  struct DescriptionT : public T {
    using UType = DescriptionT;
    using VkType = T;
    DescriptionT() { *this = VkType{}; }
    DescriptionT(const VkType& rhs) { (VkType&)*this = rhs; }
    VkType& operator =(const VkType& rhs) { (VkType&)*this = rhs; return *this; }
  };

  // wrapped enum types

  // wrapped flag types
  using Flags = FlagsT<VkFlags>;

  // wrapped handle types
  using Image = HandleT<VkImage>;

  // wrapped info (type identified) and description (not type identified) structs

// function prototypes
#if !defined(VKU_INLINE_ALL)
  extern const char* member_to_string_vp(const VkPhysicalDeviceFeatures&, const void* member);
#endif // VKU_INLINE_ALL

  // function implementations
#if defined(VKU_IMPLEMENT) || defined(VKU_INLINE_ALL)
  VKU_FUNC const char* member_to_string_vp(const VkPhysicalDeviceFeatures& s, const void* member) {
    return nullptr;
  }
#endif // VKU_IMPLEMENT || VKU_INLINE_ALL

  // always inlined functions
  template<typename T>
  inline const char* to_string(const VkPhysicalDeviceFeatures& s, const T& m) {
      return member_to_string_vp(s, &m);
  }
} // end namespace vku