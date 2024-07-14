#pragma once
// vku.h v1.3.283 generated 2024-07-14 15:24:18.024287 by gen_vku.py
// see https://github.com/benn-herrera/vku.git LICENSE.md and README.md
// define VKU_INLINE_ALL for header-only with no compiled functions
// or 
// define VKU_IMPLEMENT in exactly on C++ source file before including vku/vku.h

#if defined(VKU_INLINE_ALL)
# define VKU_PROTO inline
# define VKU_IMPL inline
# if defined(VKU_IMPLEMENT)
#   static_assert(false, "only one of VKU_INLINE_ALL, VKU_IMPLEMENT may be defined.");
# endif
#elif defined(VKU_IMPLEMENT)
# define VKU_PROTO extern
# define VKU_IMPL
#endif // VKU_INLINE_ALL, VKU_IMPLEMENT

#if !defined(VK_VERSION_1_0)
# include "vulkan/vulkan.h"
#endif

#if !defined(VK_NULL_HANDLE)
# define VK_NULL_HANDLE 0
#endif

namespace vku {
  //
  // wrapped enum types
  //
  
  template<typename T>
  struct EnumT {
    using UType = EnumT;
    using VkType = T;  
    static constexpr auto kInvalid = (VkType)0x7fffffff;
    EnumT(VkType i=(VkType)0) : v(i) {}
    VkType operator =(const VkType rhs) { v = rhs; return v; }
    operator const VkType&() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
    friend bool operator <(const UType& lhs, const VkType rhs) { return lhs.v < rhs; }
    friend bool operator <(const VkType lhs, const UType& rhs) { return lhs < rhs.v; }
    friend bool operator <=(const UType& lhs, const VkType rhs) { return lhs.v <= rhs; }
    friend bool operator <=(const VkType lhs, const UType& rhs) { return lhs <= rhs.v; }
    friend bool operator >(const UType& lhs, const VkType rhs) { return lhs.v > rhs; }
    friend bool operator >(const VkType lhs, const UType& rhs) { return lhs > rhs.v; }
    friend bool operator >=(const UType& lhs, const VkType rhs) { return lhs.v >= rhs; }
    friend bool operator >=(const VkType lhs, const UType& rhs) { return lhs >= rhs.v; }
    friend bool operator ==(const UType& lhs, const VkType rhs) { return lhs.v == rhs; }
    friend bool operator ==(const VkType lhs, const UType& rhs) { return lhs == rhs.v; }
    friend bool operator !=(const UType& lhs, const VkType rhs) { return lhs.v != rhs; }
    friend bool operator !=(const VkType lhs, const UType& rhs) { return lhs != rhs.v; }
  private:
    VkType v;
  };

  using RayTracingInvocationReorderModeNV = EnumT<VkRayTracingInvocationReorderModeNV>;
  using DirectDriverLoadingModeLUNARG = EnumT<VkDirectDriverLoadingModeLUNARG>;
  using PresentModeKHR = EnumT<VkPresentModeKHR>;
  using ColorSpaceKHR = EnumT<VkColorSpaceKHR>;
  using TimeDomainKHR = EnumT<VkTimeDomainKHR>;
  using DebugReportObjectTypeEXT = EnumT<VkDebugReportObjectTypeEXT>;
  using DeviceMemoryReportEventTypeEXT = EnumT<VkDeviceMemoryReportEventTypeEXT>;
  using RasterizationOrderAMD = EnumT<VkRasterizationOrderAMD>;
  using ValidationCheckEXT = EnumT<VkValidationCheckEXT>;
  using ValidationFeatureEnableEXT = EnumT<VkValidationFeatureEnableEXT>;
  using ValidationFeatureDisableEXT = EnumT<VkValidationFeatureDisableEXT>;
  using LayerSettingTypeEXT = EnumT<VkLayerSettingTypeEXT>;
  using IndirectCommandsTokenTypeNV = EnumT<VkIndirectCommandsTokenTypeNV>;
  using DisplayPowerStateEXT = EnumT<VkDisplayPowerStateEXT>;
  using DeviceEventTypeEXT = EnumT<VkDeviceEventTypeEXT>;
  using DisplayEventTypeEXT = EnumT<VkDisplayEventTypeEXT>;
  using ViewportCoordinateSwizzleNV = EnumT<VkViewportCoordinateSwizzleNV>;
  using DiscardRectangleModeEXT = EnumT<VkDiscardRectangleModeEXT>;
  using BlendOverlapEXT = EnumT<VkBlendOverlapEXT>;
  using CoverageModulationModeNV = EnumT<VkCoverageModulationModeNV>;
  using CoverageReductionModeNV = EnumT<VkCoverageReductionModeNV>;
  using ValidationCacheHeaderVersionEXT = EnumT<VkValidationCacheHeaderVersionEXT>;
  using ShaderInfoTypeAMD = EnumT<VkShaderInfoTypeAMD>;
  using QueueGlobalPriorityKHR = EnumT<VkQueueGlobalPriorityKHR>;
  using ConservativeRasterizationModeEXT = EnumT<VkConservativeRasterizationModeEXT>;
  using ShadingRatePaletteEntryNV = EnumT<VkShadingRatePaletteEntryNV>;
  using CoarseSampleOrderTypeNV = EnumT<VkCoarseSampleOrderTypeNV>;
  using CopyAccelerationStructureModeKHR = EnumT<VkCopyAccelerationStructureModeKHR>;
  using BuildAccelerationStructureModeKHR = EnumT<VkBuildAccelerationStructureModeKHR>;
  using AccelerationStructureTypeKHR = EnumT<VkAccelerationStructureTypeKHR>;
  using GeometryTypeKHR = EnumT<VkGeometryTypeKHR>;
  using AccelerationStructureMemoryRequirementsTypeNV = EnumT<VkAccelerationStructureMemoryRequirementsTypeNV>;
  using AccelerationStructureBuildTypeKHR = EnumT<VkAccelerationStructureBuildTypeKHR>;
  using RayTracingShaderGroupTypeKHR = EnumT<VkRayTracingShaderGroupTypeKHR>;
  using AccelerationStructureCompatibilityKHR = EnumT<VkAccelerationStructureCompatibilityKHR>;
  using ShaderGroupShaderKHR = EnumT<VkShaderGroupShaderKHR>;
  using MemoryOverallocationBehaviorAMD = EnumT<VkMemoryOverallocationBehaviorAMD>;
  using PerformanceCounterScopeKHR = EnumT<VkPerformanceCounterScopeKHR>;
  using PerformanceCounterUnitKHR = EnumT<VkPerformanceCounterUnitKHR>;
  using PerformanceCounterStorageKHR = EnumT<VkPerformanceCounterStorageKHR>;
  using PerformanceConfigurationTypeINTEL = EnumT<VkPerformanceConfigurationTypeINTEL>;
  using QueryPoolSamplingModeINTEL = EnumT<VkQueryPoolSamplingModeINTEL>;
  using PerformanceOverrideTypeINTEL = EnumT<VkPerformanceOverrideTypeINTEL>;
  using PerformanceParameterTypeINTEL = EnumT<VkPerformanceParameterTypeINTEL>;
  using PerformanceValueTypeINTEL = EnumT<VkPerformanceValueTypeINTEL>;
  using PipelineExecutableStatisticFormatKHR = EnumT<VkPipelineExecutableStatisticFormatKHR>;
  using LineRasterizationModeKHR = EnumT<VkLineRasterizationModeKHR>;
  using FragmentShadingRateCombinerOpKHR = EnumT<VkFragmentShadingRateCombinerOpKHR>;
  using FragmentShadingRateNV = EnumT<VkFragmentShadingRateNV>;
  using FragmentShadingRateTypeNV = EnumT<VkFragmentShadingRateTypeNV>;
  using SubpassMergeStatusEXT = EnumT<VkSubpassMergeStatusEXT>;
  using ProvokingVertexModeEXT = EnumT<VkProvokingVertexModeEXT>;
  using AccelerationStructureMotionInstanceTypeNV = EnumT<VkAccelerationStructureMotionInstanceTypeNV>;
  using DeviceAddressBindingTypeEXT = EnumT<VkDeviceAddressBindingTypeEXT>;
  using QueryResultStatusKHR = EnumT<VkQueryResultStatusKHR>;
  using VideoEncodeTuningModeKHR = EnumT<VkVideoEncodeTuningModeKHR>;
  using PipelineRobustnessBufferBehaviorEXT = EnumT<VkPipelineRobustnessBufferBehaviorEXT>;
  using PipelineRobustnessImageBehaviorEXT = EnumT<VkPipelineRobustnessImageBehaviorEXT>;
  using OpticalFlowPerformanceLevelNV = EnumT<VkOpticalFlowPerformanceLevelNV>;
  using OpticalFlowSessionBindingPointNV = EnumT<VkOpticalFlowSessionBindingPointNV>;
  using MicromapTypeEXT = EnumT<VkMicromapTypeEXT>;
  using CopyMicromapModeEXT = EnumT<VkCopyMicromapModeEXT>;
  using BuildMicromapModeEXT = EnumT<VkBuildMicromapModeEXT>;
  using OpacityMicromapFormatEXT = EnumT<VkOpacityMicromapFormatEXT>;
  using OpacityMicromapSpecialIndexEXT = EnumT<VkOpacityMicromapSpecialIndexEXT>;
  using DepthBiasRepresentationEXT = EnumT<VkDepthBiasRepresentationEXT>;
  using DeviceFaultAddressTypeEXT = EnumT<VkDeviceFaultAddressTypeEXT>;
  using DeviceFaultVendorBinaryHeaderVersionEXT = EnumT<VkDeviceFaultVendorBinaryHeaderVersionEXT>;
  using ShaderCodeTypeEXT = EnumT<VkShaderCodeTypeEXT>;
  using ScopeKHR = EnumT<VkScopeKHR>;
  using ComponentTypeKHR = EnumT<VkComponentTypeKHR>;
  using CubicFilterWeightsQCOM = EnumT<VkCubicFilterWeightsQCOM>;
  using BlockMatchWindowCompareModeQCOM = EnumT<VkBlockMatchWindowCompareModeQCOM>;
  using LayeredDriverUnderlyingApiMSFT = EnumT<VkLayeredDriverUnderlyingApiMSFT>;
  using LatencyMarkerNV = EnumT<VkLatencyMarkerNV>;
  using OutOfBandQueueTypeNV = EnumT<VkOutOfBandQueueTypeNV>;
#if defined(VK_VERSION_1_0)
  using ImageLayout = EnumT<VkImageLayout>;
  using AttachmentLoadOp = EnumT<VkAttachmentLoadOp>;
  using AttachmentStoreOp = EnumT<VkAttachmentStoreOp>;
  using ImageType = EnumT<VkImageType>;
  using ImageTiling = EnumT<VkImageTiling>;
  using ImageViewType = EnumT<VkImageViewType>;
  using CommandBufferLevel = EnumT<VkCommandBufferLevel>;
  using ComponentSwizzle = EnumT<VkComponentSwizzle>;
  using DescriptorType = EnumT<VkDescriptorType>;
  using QueryType = EnumT<VkQueryType>;
  using BorderColor = EnumT<VkBorderColor>;
  using PipelineBindPoint = EnumT<VkPipelineBindPoint>;
  using PipelineCacheHeaderVersion = EnumT<VkPipelineCacheHeaderVersion>;
  using PrimitiveTopology = EnumT<VkPrimitiveTopology>;
  using SharingMode = EnumT<VkSharingMode>;
  using IndexType = EnumT<VkIndexType>;
  using Filter = EnumT<VkFilter>;
  using SamplerMipmapMode = EnumT<VkSamplerMipmapMode>;
  using SamplerAddressMode = EnumT<VkSamplerAddressMode>;
  using CompareOp = EnumT<VkCompareOp>;
  using PolygonMode = EnumT<VkPolygonMode>;
  using FrontFace = EnumT<VkFrontFace>;
  using BlendFactor = EnumT<VkBlendFactor>;
  using BlendOp = EnumT<VkBlendOp>;
  using StencilOp = EnumT<VkStencilOp>;
  using LogicOp = EnumT<VkLogicOp>;
  using InternalAllocationType = EnumT<VkInternalAllocationType>;
  using SystemAllocationScope = EnumT<VkSystemAllocationScope>;
  using PhysicalDeviceType = EnumT<VkPhysicalDeviceType>;
  using VertexInputRate = EnumT<VkVertexInputRate>;
  using Format = EnumT<VkFormat>;
  using StructureType = EnumT<VkStructureType>;
  using SubpassContents = EnumT<VkSubpassContents>;
  using Result = EnumT<VkResult>;
  using DynamicState = EnumT<VkDynamicState>;
  using ObjectType = EnumT<VkObjectType>;
  using VendorId = EnumT<VkVendorId>;
#endif // VK_VERSION_1_0
#if defined(VK_VERSION_1_1)
  using DescriptorUpdateTemplateType = EnumT<VkDescriptorUpdateTemplateType>;
  using PointClippingBehavior = EnumT<VkPointClippingBehavior>;
  using TessellationDomainOrigin = EnumT<VkTessellationDomainOrigin>;
  using SamplerYcbcrModelConversion = EnumT<VkSamplerYcbcrModelConversion>;
  using SamplerYcbcrRange = EnumT<VkSamplerYcbcrRange>;
  using ChromaLocation = EnumT<VkChromaLocation>;
#endif // VK_VERSION_1_1
#if defined(VK_VERSION_1_2)
  using SemaphoreType = EnumT<VkSemaphoreType>;
  using SamplerReductionMode = EnumT<VkSamplerReductionMode>;
  using DriverId = EnumT<VkDriverId>;
  using ShaderFloatControlsIndependence = EnumT<VkShaderFloatControlsIndependence>;
#endif // VK_VERSION_1_2
#if defined(VK_USE_PLATFORM_WIN32_KHR)
  using FullScreenExclusiveEXT = EnumT<VkFullScreenExclusiveEXT>;
#endif // VK_USE_PLATFORM_WIN32_KHR

  //
  // wrapped flag types
  //
  
  template<typename T>
  struct FlagsT {
    using UType = FlagsT;
    using VkType = T;
    
    FlagsT(VkType i=(VkType)0) : v(i) {}
    VkType operator =(const VkType rhs) { v = rhs; return v; }
    operator bool(){ return bool(v); }
    bool operator !(){ return !(v); }
    operator const VkType&() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
    VkType operator |=(const VkType rhs) { v = (VkType)((VkFlags)v | (VkFlags)rhs); return v; }
    VkType operator &=(const VkType rhs) { v = (VkType)((VkFlags)v & (VkFlags)rhs); return v; }
    VkType operator ^=(const VkType rhs) { v = (VkType)((VkFlags)v ^ (VkFlags)rhs); return v; }
    VkType operator +=(const VkType rhs) { v = (VkType)((VkFlags)v + (VkFlags)rhs); return v; }
    VkType operator -=(const VkType rhs) { v = (VkType)((VkFlags)v - (VkFlags)rhs); return v; }
    friend bool operator <(const UType& lhs, const VkType rhs) { return lhs.v < rhs; }
    friend bool operator <(const VkType lhs, const UType& rhs) { return lhs < rhs.v; }
    friend bool operator <=(const UType& lhs, const VkType rhs) { return lhs.v <= rhs; }
    friend bool operator <=(const VkType lhs, const UType& rhs) { return lhs <= rhs.v; }
    friend bool operator >(const UType& lhs, const VkType rhs) { return lhs.v > rhs; }
    friend bool operator >(const VkType lhs, const UType& rhs) { return lhs > rhs.v; }
    friend bool operator >=(const UType& lhs, const VkType rhs) { return lhs.v >= rhs; }
    friend bool operator >=(const VkType lhs, const UType& rhs) { return lhs >= rhs.v; }
    friend bool operator ==(const UType& lhs, const VkType rhs) { return lhs.v == rhs; }
    friend bool operator ==(const VkType lhs, const UType& rhs) { return lhs == rhs.v; }
    friend bool operator !=(const UType& lhs, const VkType rhs) { return lhs.v != rhs; }
    friend bool operator !=(const VkType lhs, const UType& rhs) { return lhs != rhs.v; }
    friend VkType operator |(const UType& lhs, const VkType rhs) { return lhs.v | rhs; }
    friend VkType operator |(const VkType lhs, const UType& rhs) { return lhs | rhs.v; }
    friend VkType operator &(const UType& lhs, const VkType rhs) { return lhs.v & rhs; }
    friend VkType operator &(const VkType lhs, const UType& rhs) { return lhs & rhs.v; }
    friend VkType operator ^(const UType& lhs, const VkType rhs) { return lhs.v ^ rhs; }
    friend VkType operator ^(const VkType lhs, const UType& rhs) { return lhs ^ rhs.v; }
    friend VkType operator +(const UType& lhs, const VkType rhs) { return lhs.v + rhs; }
    friend VkType operator +(const VkType lhs, const UType& rhs) { return lhs + rhs.v; }
    friend VkType operator -(const UType& lhs, const VkType rhs) { return lhs.v - rhs; }
    friend VkType operator -(const VkType lhs, const UType& rhs) { return lhs - rhs.v; }
  private:
    VkType v;
  };
  
  using Flags = FlagsT<VkFlags>;
  using Flags64 = FlagsT<VkFlags64>;
  
  template<typename T>
  struct FlagBitsT {
    using UType = FlagBitsT;
    using VkType = T;  
    FlagBitsT(VkType i=(VkType)0) : v(i) {}
    VkType operator =(const VkType rhs) { v = rhs; return v; }
    operator const VkType&() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
    VkType operator |=(const VkType rhs) { v = (VkType)((VkFlags)v | (VkFlags)rhs); return v; }
    VkType operator &=(const VkType rhs) { v = (VkType)((VkFlags)v & (VkFlags)rhs); return v; }
    VkType operator ^=(const VkType rhs) { v = (VkType)((VkFlags)v ^ (VkFlags)rhs); return v; }
    VkType operator +=(const VkType rhs) { v = (VkType)((VkFlags)v + (VkFlags)rhs); return v; }
    VkType operator -=(const VkType rhs) { v = (VkType)((VkFlags)v - (VkFlags)rhs); return v; }
    friend bool operator <(const UType& lhs, const VkType rhs) { return lhs.v < rhs; }
    friend bool operator <(const VkType lhs, const UType& rhs) { return lhs < rhs.v; }
    friend bool operator <=(const UType& lhs, const VkType rhs) { return lhs.v <= rhs; }
    friend bool operator <=(const VkType lhs, const UType& rhs) { return lhs <= rhs.v; }
    friend bool operator >(const UType& lhs, const VkType rhs) { return lhs.v > rhs; }
    friend bool operator >(const VkType lhs, const UType& rhs) { return lhs > rhs.v; }
    friend bool operator >=(const UType& lhs, const VkType rhs) { return lhs.v >= rhs; }
    friend bool operator >=(const VkType lhs, const UType& rhs) { return lhs >= rhs.v; }
    friend bool operator ==(const UType& lhs, const VkType rhs) { return lhs.v == rhs; }
    friend bool operator ==(const VkType lhs, const UType& rhs) { return lhs == rhs.v; }
    friend bool operator !=(const UType& lhs, const VkType rhs) { return lhs.v != rhs; }
    friend bool operator !=(const VkType lhs, const UType& rhs) { return lhs != rhs.v; }
    friend VkFlags operator |(const UType& lhs, const VkFlags rhs) { return VkFlags(lhs.v) | rhs; }
    friend VkFlags operator |(const VkFlags lhs, const UType& rhs) { return lhs | VkFlags(rhs.v); }
    friend VkFlags operator |(const UType& lhs, const VkType rhs) { return VkFlags(lhs.v) | VkFlags(rhs); }
    friend VkFlags operator |(const VkType lhs, const UType& rhs) { return VkFlags(lhs) | VkFlags(rhs.v); }
    friend VkFlags operator &(const UType& lhs, const VkFlags rhs) { return VkFlags(lhs.v) & rhs; }
    friend VkFlags operator &(const VkFlags lhs, const UType& rhs) { return lhs & VkFlags(rhs.v); }
    friend VkFlags operator &(const UType& lhs, const VkType rhs) { return VkFlags(lhs.v) & VkFlags(rhs); }
    friend VkFlags operator &(const VkType lhs, const UType& rhs) { return VkFlags(lhs) & VkFlags(rhs.v); }
    friend VkFlags operator ^(const UType& lhs, const VkFlags rhs) { return VkFlags(lhs.v) ^ rhs; }
    friend VkFlags operator ^(const VkFlags lhs, const UType& rhs) { return lhs ^ VkFlags(rhs.v); }
    friend VkFlags operator ^(const UType& lhs, const VkType rhs) { return VkFlags(lhs.v) ^ VkFlags(rhs); }
    friend VkFlags operator ^(const VkType lhs, const UType& rhs) { return VkFlags(lhs) ^ VkFlags(rhs.v); }
    friend VkFlags operator +(const UType& lhs, const VkFlags rhs) { return VkFlags(lhs.v) + rhs; }
    friend VkFlags operator +(const VkFlags lhs, const UType& rhs) { return lhs + VkFlags(rhs.v); }
    friend VkFlags operator +(const UType& lhs, const VkType rhs) { return VkFlags(lhs.v) + VkFlags(rhs); }
    friend VkFlags operator +(const VkType lhs, const UType& rhs) { return VkFlags(lhs) + VkFlags(rhs.v); }
    friend VkFlags operator -(const UType& lhs, const VkFlags rhs) { return VkFlags(lhs.v) - rhs; }
    friend VkFlags operator -(const VkFlags lhs, const UType& rhs) { return lhs - VkFlags(rhs.v); }
    friend VkFlags operator -(const UType& lhs, const VkType rhs) { return VkFlags(lhs.v) - VkFlags(rhs); }
    friend VkFlags operator -(const VkType lhs, const UType& rhs) { return VkFlags(lhs) - VkFlags(rhs.v); }
  private:
    VkType v;
  };

  using BufferUsageFlagBits2KHR = Flags64;
  using PipelineCreateFlagBits2KHR = Flags64;
  using DisplayPlaneAlphaFlagBitsKHR = FlagBitsT<VkDisplayPlaneAlphaFlagBitsKHR>;
  using CompositeAlphaFlagBitsKHR = FlagBitsT<VkCompositeAlphaFlagBitsKHR>;
  using SurfaceTransformFlagBitsKHR = FlagBitsT<VkSurfaceTransformFlagBitsKHR>;
  using DebugReportFlagBitsEXT = FlagBitsT<VkDebugReportFlagBitsEXT>;
  using ExternalMemoryHandleTypeFlagBitsNV = FlagBitsT<VkExternalMemoryHandleTypeFlagBitsNV>;
  using ExternalMemoryFeatureFlagBitsNV = FlagBitsT<VkExternalMemoryFeatureFlagBitsNV>;
  using IndirectCommandsLayoutUsageFlagBitsNV = FlagBitsT<VkIndirectCommandsLayoutUsageFlagBitsNV>;
  using IndirectStateFlagBitsNV = FlagBitsT<VkIndirectStateFlagBitsNV>;
  using SurfaceCounterFlagBitsEXT = FlagBitsT<VkSurfaceCounterFlagBitsEXT>;
  using DeviceGroupPresentModeFlagBitsKHR = FlagBitsT<VkDeviceGroupPresentModeFlagBitsKHR>;
  using DebugUtilsMessageSeverityFlagBitsEXT = FlagBitsT<VkDebugUtilsMessageSeverityFlagBitsEXT>;
  using DebugUtilsMessageTypeFlagBitsEXT = FlagBitsT<VkDebugUtilsMessageTypeFlagBitsEXT>;
  using ConditionalRenderingFlagBitsEXT = FlagBitsT<VkConditionalRenderingFlagBitsEXT>;
  using GeometryInstanceFlagBitsKHR = FlagBitsT<VkGeometryInstanceFlagBitsKHR>;
  using GeometryFlagBitsKHR = FlagBitsT<VkGeometryFlagBitsKHR>;
  using BuildAccelerationStructureFlagBitsKHR = FlagBitsT<VkBuildAccelerationStructureFlagBitsKHR>;
  using AccelerationStructureCreateFlagBitsKHR = FlagBitsT<VkAccelerationStructureCreateFlagBitsKHR>;
  using DeviceDiagnosticsConfigFlagBitsNV = FlagBitsT<VkDeviceDiagnosticsConfigFlagBitsNV>;
  using MemoryDecompressionMethodFlagBitsNV = Flags64;
  using PerformanceCounterDescriptionFlagBitsKHR = FlagBitsT<VkPerformanceCounterDescriptionFlagBitsKHR>;
  using GraphicsPipelineLibraryFlagBitsEXT = FlagBitsT<VkGraphicsPipelineLibraryFlagBitsEXT>;
  using DeviceAddressBindingFlagBitsEXT = FlagBitsT<VkDeviceAddressBindingFlagBitsEXT>;
  using FrameBoundaryFlagBitsEXT = FlagBitsT<VkFrameBoundaryFlagBitsEXT>;
  using PresentScalingFlagBitsEXT = FlagBitsT<VkPresentScalingFlagBitsEXT>;
  using PresentGravityFlagBitsEXT = FlagBitsT<VkPresentGravityFlagBitsEXT>;
  using PhysicalDeviceSchedulingControlsFlagBitsARM = Flags64;
  using VideoCodecOperationFlagBitsKHR = FlagBitsT<VkVideoCodecOperationFlagBitsKHR>;
  using VideoChromaSubsamplingFlagBitsKHR = FlagBitsT<VkVideoChromaSubsamplingFlagBitsKHR>;
  using VideoComponentBitDepthFlagBitsKHR = FlagBitsT<VkVideoComponentBitDepthFlagBitsKHR>;
  using VideoCapabilityFlagBitsKHR = FlagBitsT<VkVideoCapabilityFlagBitsKHR>;
  using VideoSessionCreateFlagBitsKHR = FlagBitsT<VkVideoSessionCreateFlagBitsKHR>;
  using VideoDecodeH264PictureLayoutFlagBitsKHR = FlagBitsT<VkVideoDecodeH264PictureLayoutFlagBitsKHR>;
  using VideoCodingControlFlagBitsKHR = FlagBitsT<VkVideoCodingControlFlagBitsKHR>;
  using VideoDecodeUsageFlagBitsKHR = FlagBitsT<VkVideoDecodeUsageFlagBitsKHR>;
  using VideoDecodeCapabilityFlagBitsKHR = FlagBitsT<VkVideoDecodeCapabilityFlagBitsKHR>;
  using VideoEncodeUsageFlagBitsKHR = FlagBitsT<VkVideoEncodeUsageFlagBitsKHR>;
  using VideoEncodeContentFlagBitsKHR = FlagBitsT<VkVideoEncodeContentFlagBitsKHR>;
  using VideoEncodeCapabilityFlagBitsKHR = FlagBitsT<VkVideoEncodeCapabilityFlagBitsKHR>;
  using VideoEncodeFeedbackFlagBitsKHR = FlagBitsT<VkVideoEncodeFeedbackFlagBitsKHR>;
  using VideoEncodeRateControlModeFlagBitsKHR = FlagBitsT<VkVideoEncodeRateControlModeFlagBitsKHR>;
  using VideoEncodeH264CapabilityFlagBitsKHR = FlagBitsT<VkVideoEncodeH264CapabilityFlagBitsKHR>;
  using VideoEncodeH264StdFlagBitsKHR = FlagBitsT<VkVideoEncodeH264StdFlagBitsKHR>;
  using VideoEncodeH264RateControlFlagBitsKHR = FlagBitsT<VkVideoEncodeH264RateControlFlagBitsKHR>;
  using HostImageCopyFlagBitsEXT = FlagBitsT<VkHostImageCopyFlagBitsEXT>;
  using VideoEncodeH265CapabilityFlagBitsKHR = FlagBitsT<VkVideoEncodeH265CapabilityFlagBitsKHR>;
  using VideoEncodeH265StdFlagBitsKHR = FlagBitsT<VkVideoEncodeH265StdFlagBitsKHR>;
  using VideoEncodeH265RateControlFlagBitsKHR = FlagBitsT<VkVideoEncodeH265RateControlFlagBitsKHR>;
  using VideoEncodeH265CtbSizeFlagBitsKHR = FlagBitsT<VkVideoEncodeH265CtbSizeFlagBitsKHR>;
  using VideoEncodeH265TransformBlockSizeFlagBitsKHR = FlagBitsT<VkVideoEncodeH265TransformBlockSizeFlagBitsKHR>;
  using ImageCompressionFlagBitsEXT = FlagBitsT<VkImageCompressionFlagBitsEXT>;
  using ImageCompressionFixedRateFlagBitsEXT = FlagBitsT<VkImageCompressionFixedRateFlagBitsEXT>;
  using OpticalFlowGridSizeFlagBitsNV = FlagBitsT<VkOpticalFlowGridSizeFlagBitsNV>;
  using OpticalFlowUsageFlagBitsNV = FlagBitsT<VkOpticalFlowUsageFlagBitsNV>;
  using OpticalFlowSessionCreateFlagBitsNV = FlagBitsT<VkOpticalFlowSessionCreateFlagBitsNV>;
  using OpticalFlowExecuteFlagBitsNV = FlagBitsT<VkOpticalFlowExecuteFlagBitsNV>;
  using BuildMicromapFlagBitsEXT = FlagBitsT<VkBuildMicromapFlagBitsEXT>;
  using MicromapCreateFlagBitsEXT = FlagBitsT<VkMicromapCreateFlagBitsEXT>;
  using ShaderCreateFlagBitsEXT = FlagBitsT<VkShaderCreateFlagBitsEXT>;
  using PipelineLayoutCreateFlags = Flags;
  using PipelineCacheCreateFlags = Flags;
  using PipelineDepthStencilStateCreateFlags = Flags;
  using PipelineColorBlendStateCreateFlags = Flags;
  using MemoryUnmapFlagsKHR = Flags;
  using IndirectCommandsLayoutUsageFlagsNV = Flags;
  using IndirectStateFlagsNV = Flags;
  using GeometryFlagsKHR = Flags;
  using GeometryInstanceFlagsKHR = Flags;
  using BuildAccelerationStructureFlagsKHR = Flags;
  using AccelerationStructureCreateFlagsKHR = Flags;
  using PerformanceCounterDescriptionFlagsKHR = Flags;
  using AcquireProfilingLockFlagsKHR = Flags;
  using PipelineCompilerControlFlagsAMD = Flags;
  using ShaderCorePropertiesFlagsAMD = Flags;
  using DeviceDiagnosticsConfigFlagsNV = Flags;
  using RefreshObjectFlagsKHR = Flags;
  using BuildMicromapFlagsEXT = Flags;
  using MicromapCreateFlagsEXT = Flags;
  using CompositeAlphaFlagsKHR = Flags;
  using DisplayPlaneAlphaFlagsKHR = Flags;
  using SurfaceTransformFlagsKHR = Flags;
  using SwapchainCreateFlagsKHR = Flags;
  using DeviceGroupPresentModeFlagsKHR = Flags;
  using DebugReportFlagsEXT = Flags;
  using ExternalMemoryHandleTypeFlagsNV = Flags;
  using ExternalMemoryFeatureFlagsNV = Flags;
  using SurfaceCounterFlagsEXT = Flags;
  using DebugUtilsMessageSeverityFlagsEXT = Flags;
  using DebugUtilsMessageTypeFlagsEXT = Flags;
  using ConditionalRenderingFlagsEXT = Flags;
  using SwapchainImageUsageFlagsANDROID = Flags;
  using HostImageCopyFlagsEXT = Flags;
  using GraphicsPipelineLibraryFlagsEXT = Flags;
  using ImageCompressionFlagsEXT = Flags;
  using ImageCompressionFixedRateFlagsEXT = Flags;
  using DeviceAddressBindingFlagsEXT = Flags;
  using OpticalFlowGridSizeFlagsNV = Flags;
  using OpticalFlowUsageFlagsNV = Flags;
  using OpticalFlowSessionCreateFlagsNV = Flags;
  using OpticalFlowExecuteFlagsNV = Flags;
  using FrameBoundaryFlagsEXT = Flags;
  using PresentScalingFlagsEXT = Flags;
  using PresentGravityFlagsEXT = Flags;
  using ShaderCreateFlagsEXT = Flags;
  using VideoCodecOperationFlagsKHR = Flags;
  using VideoCapabilityFlagsKHR = Flags;
  using VideoSessionCreateFlagsKHR = Flags;
  using VideoCodingControlFlagsKHR = Flags;
  using VideoDecodeUsageFlagsKHR = Flags;
  using VideoDecodeCapabilityFlagsKHR = Flags;
  using VideoDecodeH264PictureLayoutFlagsKHR = Flags;
  using VideoEncodeFlagsKHR = Flags;
  using VideoEncodeUsageFlagsKHR = Flags;
  using VideoEncodeContentFlagsKHR = Flags;
  using VideoEncodeCapabilityFlagsKHR = Flags;
  using VideoEncodeFeedbackFlagsKHR = Flags;
  using VideoEncodeRateControlModeFlagsKHR = Flags;
  using VideoChromaSubsamplingFlagsKHR = Flags;
  using VideoComponentBitDepthFlagsKHR = Flags;
  using VideoEncodeH264CapabilityFlagsKHR = Flags;
  using VideoEncodeH264StdFlagsKHR = Flags;
  using VideoEncodeH264RateControlFlagsKHR = Flags;
  using VideoEncodeH265CapabilityFlagsKHR = Flags;
  using VideoEncodeH265StdFlagsKHR = Flags;
  using VideoEncodeH265RateControlFlagsKHR = Flags;
  using VideoEncodeH265CtbSizeFlagsKHR = Flags;
  using VideoEncodeH265TransformBlockSizeFlagsKHR = Flags;
#if defined(VK_VERSION_1_0)
  using QueueFlagBits = FlagBitsT<VkQueueFlagBits>;
  using CullModeFlagBits = FlagBitsT<VkCullModeFlagBits>;
  using MemoryPropertyFlagBits = FlagBitsT<VkMemoryPropertyFlagBits>;
  using MemoryHeapFlagBits = FlagBitsT<VkMemoryHeapFlagBits>;
  using AccessFlagBits = FlagBitsT<VkAccessFlagBits>;
  using BufferUsageFlagBits = FlagBitsT<VkBufferUsageFlagBits>;
  using BufferCreateFlagBits = FlagBitsT<VkBufferCreateFlagBits>;
  using ShaderStageFlagBits = FlagBitsT<VkShaderStageFlagBits>;
  using ImageUsageFlagBits = FlagBitsT<VkImageUsageFlagBits>;
  using ImageCreateFlagBits = FlagBitsT<VkImageCreateFlagBits>;
  using PipelineCreateFlagBits = FlagBitsT<VkPipelineCreateFlagBits>;
  using ColorComponentFlagBits = FlagBitsT<VkColorComponentFlagBits>;
  using FenceCreateFlagBits = FlagBitsT<VkFenceCreateFlagBits>;
  using FormatFeatureFlagBits = FlagBitsT<VkFormatFeatureFlagBits>;
  using QueryControlFlagBits = FlagBitsT<VkQueryControlFlagBits>;
  using QueryResultFlagBits = FlagBitsT<VkQueryResultFlagBits>;
  using CommandBufferUsageFlagBits = FlagBitsT<VkCommandBufferUsageFlagBits>;
  using QueryPipelineStatisticFlagBits = FlagBitsT<VkQueryPipelineStatisticFlagBits>;
  using ImageAspectFlagBits = FlagBitsT<VkImageAspectFlagBits>;
  using SparseImageFormatFlagBits = FlagBitsT<VkSparseImageFormatFlagBits>;
  using SparseMemoryBindFlagBits = FlagBitsT<VkSparseMemoryBindFlagBits>;
  using PipelineStageFlagBits = FlagBitsT<VkPipelineStageFlagBits>;
  using CommandPoolCreateFlagBits = FlagBitsT<VkCommandPoolCreateFlagBits>;
  using CommandPoolResetFlagBits = FlagBitsT<VkCommandPoolResetFlagBits>;
  using CommandBufferResetFlagBits = FlagBitsT<VkCommandBufferResetFlagBits>;
  using SampleCountFlagBits = FlagBitsT<VkSampleCountFlagBits>;
  using AttachmentDescriptionFlagBits = FlagBitsT<VkAttachmentDescriptionFlagBits>;
  using StencilFaceFlagBits = FlagBitsT<VkStencilFaceFlagBits>;
  using DescriptorPoolCreateFlagBits = FlagBitsT<VkDescriptorPoolCreateFlagBits>;
  using DependencyFlagBits = FlagBitsT<VkDependencyFlagBits>;
  using FramebufferCreateFlags = Flags;
  using RenderPassCreateFlags = Flags;
  using SamplerCreateFlags = Flags;
  using PipelineShaderStageCreateFlags = Flags;
  using DescriptorSetLayoutCreateFlags = Flags;
  using InstanceCreateFlags = Flags;
  using QueueFlags = Flags;
  using MemoryPropertyFlags = Flags;
  using MemoryHeapFlags = Flags;
  using AccessFlags = Flags;
  using BufferUsageFlags = Flags;
  using BufferCreateFlags = Flags;
  using ShaderStageFlags = Flags;
  using ImageUsageFlags = Flags;
  using ImageCreateFlags = Flags;
  using ImageViewCreateFlags = Flags;
  using PipelineCreateFlags = Flags;
  using ColorComponentFlags = Flags;
  using FenceCreateFlags = Flags;
  using FormatFeatureFlags = Flags;
  using QueryControlFlags = Flags;
  using QueryResultFlags = Flags;
  using EventCreateFlags = Flags;
  using CommandPoolCreateFlags = Flags;
  using CommandPoolResetFlags = Flags;
  using CommandBufferResetFlags = Flags;
  using CommandBufferUsageFlags = Flags;
  using QueryPipelineStatisticFlags = Flags;
  using MemoryMapFlags = Flags;
  using ImageAspectFlags = Flags;
  using SparseMemoryBindFlags = Flags;
  using SparseImageFormatFlags = Flags;
  using SubpassDescriptionFlags = Flags;
  using PipelineStageFlags = Flags;
  using SampleCountFlags = Flags;
  using AttachmentDescriptionFlags = Flags;
  using StencilFaceFlags = Flags;
  using CullModeFlags = Flags;
  using DescriptorPoolCreateFlags = Flags;
  using DependencyFlags = Flags;
#endif // VK_VERSION_1_0
#if defined(VK_VERSION_1_1)
  using SubgroupFeatureFlagBits = FlagBitsT<VkSubgroupFeatureFlagBits>;
  using ExternalMemoryHandleTypeFlagBits = FlagBitsT<VkExternalMemoryHandleTypeFlagBits>;
  using ExternalMemoryFeatureFlagBits = FlagBitsT<VkExternalMemoryFeatureFlagBits>;
  using ExternalSemaphoreHandleTypeFlagBits = FlagBitsT<VkExternalSemaphoreHandleTypeFlagBits>;
  using ExternalSemaphoreFeatureFlagBits = FlagBitsT<VkExternalSemaphoreFeatureFlagBits>;
  using SemaphoreImportFlagBits = FlagBitsT<VkSemaphoreImportFlagBits>;
  using ExternalFenceHandleTypeFlagBits = FlagBitsT<VkExternalFenceHandleTypeFlagBits>;
  using ExternalFenceFeatureFlagBits = FlagBitsT<VkExternalFenceFeatureFlagBits>;
  using FenceImportFlagBits = FlagBitsT<VkFenceImportFlagBits>;
  using PeerMemoryFeatureFlagBits = FlagBitsT<VkPeerMemoryFeatureFlagBits>;
  using MemoryAllocateFlagBits = FlagBitsT<VkMemoryAllocateFlagBits>;
  using DeviceQueueCreateFlags = Flags;
  using SubgroupFeatureFlags = Flags;
  using PeerMemoryFeatureFlags = Flags;
  using MemoryAllocateFlags = Flags;
  using ExternalMemoryHandleTypeFlags = Flags;
  using ExternalMemoryFeatureFlags = Flags;
  using ExternalSemaphoreHandleTypeFlags = Flags;
  using ExternalSemaphoreFeatureFlags = Flags;
  using SemaphoreImportFlags = Flags;
  using ExternalFenceHandleTypeFlags = Flags;
  using ExternalFenceFeatureFlags = Flags;
  using FenceImportFlags = Flags;
#endif // VK_VERSION_1_1
#if defined(VK_VERSION_1_2)
  using SemaphoreWaitFlagBits = FlagBitsT<VkSemaphoreWaitFlagBits>;
  using DescriptorBindingFlagBits = FlagBitsT<VkDescriptorBindingFlagBits>;
  using ResolveModeFlagBits = FlagBitsT<VkResolveModeFlagBits>;
  using SemaphoreWaitFlags = Flags;
  using DescriptorBindingFlags = Flags;
  using ResolveModeFlags = Flags;
#endif // VK_VERSION_1_2
#if defined(VK_VERSION_1_3)
  using PipelineCreationFeedbackFlagBits = FlagBitsT<VkPipelineCreationFeedbackFlagBits>;
  using ToolPurposeFlagBits = FlagBitsT<VkToolPurposeFlagBits>;
  using AccessFlagBits2 = Flags64;
  using PipelineStageFlagBits2 = Flags64;
  using SubmitFlagBits = FlagBitsT<VkSubmitFlagBits>;
  using FormatFeatureFlagBits2 = Flags64;
  using RenderingFlagBits = FlagBitsT<VkRenderingFlagBits>;
  using PipelineCreationFeedbackFlags = Flags;
  using RenderingFlags = Flags;
  using ToolPurposeFlags = Flags;
  using SubmitFlags = Flags;
#endif // VK_VERSION_1_3
#if defined(VK_USE_PLATFORM_FUCHSIA)
  using ImageConstraintsInfoFlagBitsFUCHSIA = FlagBitsT<VkImageConstraintsInfoFlagBitsFUCHSIA>;
  using ImageConstraintsInfoFlagsFUCHSIA = Flags;
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
  using ExportMetalObjectTypeFlagBitsEXT = FlagBitsT<VkExportMetalObjectTypeFlagBitsEXT>;
  using ExportMetalObjectTypeFlagsEXT = Flags;
#endif // VK_USE_PLATFORM_METAL_EXT

  //
  // wrapped handle types
  //
  
  template<typename T>
  struct HandleT {
    using UType = HandleT;
    using VkType = T;

    HandleT(VkType i = (VkType)0) : v(i) {}
    VkType operator =(const VkType rhs) { v = rhs; return v; }
    operator bool(){ return bool(v); }
    bool operator !(){ return !(v); }
    operator const VkType&() const { return v; }
    operator VkType&() { return v; }
    VkType* operator&() { return &v; }
    const VkType* operator&() const { return &v; }
    friend bool operator ==(const UType& lhs, const VkType rhs) { return lhs.v == rhs; }
    friend bool operator ==(const VkType lhs, const UType& rhs) { return lhs == rhs.v; }
    friend bool operator !=(const UType& lhs, const VkType rhs) { return lhs.v != rhs; }
    friend bool operator !=(const VkType lhs, const UType& rhs) { return lhs != rhs.v; }

  private:
    VkType v;
  };

  using IndirectCommandsLayoutNV = HandleT<VkIndirectCommandsLayoutNV>;
  using ValidationCacheEXT = HandleT<VkValidationCacheEXT>;
  using AccelerationStructureKHR = HandleT<VkAccelerationStructureKHR>;
  using AccelerationStructureNV = HandleT<VkAccelerationStructureNV>;
  using PerformanceConfigurationINTEL = HandleT<VkPerformanceConfigurationINTEL>;
  using DeferredOperationKHR = HandleT<VkDeferredOperationKHR>;
  using CuModuleNVX = HandleT<VkCuModuleNVX>;
  using CuFunctionNVX = HandleT<VkCuFunctionNVX>;
  using OpticalFlowSessionNV = HandleT<VkOpticalFlowSessionNV>;
  using MicromapEXT = HandleT<VkMicromapEXT>;
  using ShaderEXT = HandleT<VkShaderEXT>;
  using DisplayKHR = HandleT<VkDisplayKHR>;
  using DisplayModeKHR = HandleT<VkDisplayModeKHR>;
  using SurfaceKHR = HandleT<VkSurfaceKHR>;
  using SwapchainKHR = HandleT<VkSwapchainKHR>;
  using DebugReportCallbackEXT = HandleT<VkDebugReportCallbackEXT>;
  using DebugUtilsMessengerEXT = HandleT<VkDebugUtilsMessengerEXT>;
  using VideoSessionKHR = HandleT<VkVideoSessionKHR>;
  using VideoSessionParametersKHR = HandleT<VkVideoSessionParametersKHR>;
  using CudaModuleNV = HandleT<VkCudaModuleNV>;
  using CudaFunctionNV = HandleT<VkCudaFunctionNV>;
#if defined(VK_VERSION_1_0)
  using Instance = HandleT<VkInstance>;
  using PhysicalDevice = HandleT<VkPhysicalDevice>;
  using Device = HandleT<VkDevice>;
  using Queue = HandleT<VkQueue>;
  using CommandBuffer = HandleT<VkCommandBuffer>;
  using DeviceMemory = HandleT<VkDeviceMemory>;
  using CommandPool = HandleT<VkCommandPool>;
  using Buffer = HandleT<VkBuffer>;
  using BufferView = HandleT<VkBufferView>;
  using Image = HandleT<VkImage>;
  using ImageView = HandleT<VkImageView>;
  using ShaderModule = HandleT<VkShaderModule>;
  using Pipeline = HandleT<VkPipeline>;
  using PipelineLayout = HandleT<VkPipelineLayout>;
  using Sampler = HandleT<VkSampler>;
  using DescriptorSet = HandleT<VkDescriptorSet>;
  using DescriptorSetLayout = HandleT<VkDescriptorSetLayout>;
  using DescriptorPool = HandleT<VkDescriptorPool>;
  using Fence = HandleT<VkFence>;
  using Semaphore = HandleT<VkSemaphore>;
  using Event = HandleT<VkEvent>;
  using QueryPool = HandleT<VkQueryPool>;
  using Framebuffer = HandleT<VkFramebuffer>;
  using RenderPass = HandleT<VkRenderPass>;
  using PipelineCache = HandleT<VkPipelineCache>;
#endif // VK_VERSION_1_0
#if defined(VK_VERSION_1_1)
  using DescriptorUpdateTemplate = HandleT<VkDescriptorUpdateTemplate>;
  using SamplerYcbcrConversion = HandleT<VkSamplerYcbcrConversion>;
#endif // VK_VERSION_1_1
#if defined(VK_VERSION_1_3)
  using PrivateDataSlot = HandleT<VkPrivateDataSlot>;
#endif // VK_VERSION_1_3
#if defined(VK_USE_PLATFORM_FUCHSIA)
  using BufferCollectionFUCHSIA = HandleT<VkBufferCollectionFUCHSIA>;
#endif // VK_USE_PLATFORM_FUCHSIA

  //
  // wrapped info (type identified) and description (not type identified) structs
  //
  
  template<class T, int32_t STYPE>
  struct InfoT : public T {
    using UType = InfoT;
    using VkType = T;
    static constexpr auto kStructType = VkStructureType(STYPE);
    InfoT() { *this = VkType{ kStructType }; }
    InfoT(const VkType& rhs) { (VkType&)*this = rhs; this->sType = kStructType; }
    VkType& operator =(const VkType& rhs) { (VkType&)*this = rhs; this->sType = kStructType; return *this; }
  };
  
  template<typename T>
  struct DescriptionT : public T {
    using UType = DescriptionT;
    using VkType = T;
    DescriptionT() { *this = VkType{}; }
    DescriptionT(const VkType& rhs) { (VkType&)*this = rhs; }
    VkType& operator =(const VkType& rhs) { (VkType&)*this = rhs; return *this; }
  };

  using BufferUsageFlags2CreateInfoKHR = InfoT<VkBufferUsageFlags2CreateInfoKHR, VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR>;
  using CopyMemoryIndirectCommandNV = DescriptionT<VkCopyMemoryIndirectCommandNV>;
  using CopyMemoryToImageIndirectCommandNV = DescriptionT<VkCopyMemoryToImageIndirectCommandNV>;
  using ComputePipelineIndirectBufferInfoNV = InfoT<VkComputePipelineIndirectBufferInfoNV, VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV>;
  using PipelineCreateFlags2CreateInfoKHR = InfoT<VkPipelineCreateFlags2CreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR>;
  using MultiDrawInfoEXT = DescriptionT<VkMultiDrawInfoEXT>;
  using MultiDrawIndexedInfoEXT = DescriptionT<VkMultiDrawIndexedInfoEXT>;
  using DisplayPropertiesKHR = DescriptionT<VkDisplayPropertiesKHR>;
  using DisplayPlanePropertiesKHR = DescriptionT<VkDisplayPlanePropertiesKHR>;
  using DisplayModeParametersKHR = DescriptionT<VkDisplayModeParametersKHR>;
  using DisplayModePropertiesKHR = DescriptionT<VkDisplayModePropertiesKHR>;
  using DisplayModeCreateInfoKHR = InfoT<VkDisplayModeCreateInfoKHR, VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR>;
  using DisplayPlaneCapabilitiesKHR = DescriptionT<VkDisplayPlaneCapabilitiesKHR>;
  using DisplaySurfaceCreateInfoKHR = InfoT<VkDisplaySurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR>;
  using DisplayPresentInfoKHR = InfoT<VkDisplayPresentInfoKHR, VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR>;
  using SurfaceCapabilitiesKHR = DescriptionT<VkSurfaceCapabilitiesKHR>;
  using SurfaceFormatKHR = DescriptionT<VkSurfaceFormatKHR>;
  using SwapchainCreateInfoKHR = InfoT<VkSwapchainCreateInfoKHR, VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR>;
  using PresentInfoKHR = InfoT<VkPresentInfoKHR, VK_STRUCTURE_TYPE_PRESENT_INFO_KHR>;
  using DebugReportCallbackCreateInfoEXT = InfoT<VkDebugReportCallbackCreateInfoEXT, VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT>;
  using ValidationFlagsEXT = InfoT<VkValidationFlagsEXT, VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT>;
  using ValidationFeaturesEXT = InfoT<VkValidationFeaturesEXT, VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT>;
  using LayerSettingsCreateInfoEXT = InfoT<VkLayerSettingsCreateInfoEXT, VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT>;
  using LayerSettingEXT = DescriptionT<VkLayerSettingEXT>;
  using PipelineRasterizationStateRasterizationOrderAMD = InfoT<VkPipelineRasterizationStateRasterizationOrderAMD, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD>;
  using DebugMarkerObjectNameInfoEXT = InfoT<VkDebugMarkerObjectNameInfoEXT, VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT>;
  using DebugMarkerObjectTagInfoEXT = InfoT<VkDebugMarkerObjectTagInfoEXT, VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT>;
  using DebugMarkerMarkerInfoEXT = InfoT<VkDebugMarkerMarkerInfoEXT, VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT>;
  using DedicatedAllocationImageCreateInfoNV = InfoT<VkDedicatedAllocationImageCreateInfoNV, VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV>;
  using DedicatedAllocationBufferCreateInfoNV = InfoT<VkDedicatedAllocationBufferCreateInfoNV, VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV>;
  using DedicatedAllocationMemoryAllocateInfoNV = InfoT<VkDedicatedAllocationMemoryAllocateInfoNV, VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV>;
  using ExternalImageFormatPropertiesNV = DescriptionT<VkExternalImageFormatPropertiesNV>;
  using ExternalMemoryImageCreateInfoNV = InfoT<VkExternalMemoryImageCreateInfoNV, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV>;
  using ExportMemoryAllocateInfoNV = InfoT<VkExportMemoryAllocateInfoNV, VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV>;
  using PhysicalDeviceDeviceGeneratedCommandsFeaturesNV = InfoT<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV>;
  using PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV = InfoT<VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV>;
  using DevicePrivateDataCreateInfoEXT = DescriptionT<VkDevicePrivateDataCreateInfoEXT>;
  using PrivateDataSlotCreateInfoEXT = DescriptionT<VkPrivateDataSlotCreateInfoEXT>;
  using PhysicalDevicePrivateDataFeaturesEXT = DescriptionT<VkPhysicalDevicePrivateDataFeaturesEXT>;
  using PhysicalDeviceDeviceGeneratedCommandsPropertiesNV = InfoT<VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV>;
  using PhysicalDeviceMultiDrawPropertiesEXT = InfoT<VkPhysicalDeviceMultiDrawPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT>;
  using GraphicsShaderGroupCreateInfoNV = InfoT<VkGraphicsShaderGroupCreateInfoNV, VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV>;
  using GraphicsPipelineShaderGroupsCreateInfoNV = InfoT<VkGraphicsPipelineShaderGroupsCreateInfoNV, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV>;
  using BindShaderGroupIndirectCommandNV = DescriptionT<VkBindShaderGroupIndirectCommandNV>;
  using BindIndexBufferIndirectCommandNV = DescriptionT<VkBindIndexBufferIndirectCommandNV>;
  using BindVertexBufferIndirectCommandNV = DescriptionT<VkBindVertexBufferIndirectCommandNV>;
  using SetStateFlagsIndirectCommandNV = DescriptionT<VkSetStateFlagsIndirectCommandNV>;
  using IndirectCommandsStreamNV = DescriptionT<VkIndirectCommandsStreamNV>;
  using IndirectCommandsLayoutTokenNV = InfoT<VkIndirectCommandsLayoutTokenNV, VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV>;
  using IndirectCommandsLayoutCreateInfoNV = InfoT<VkIndirectCommandsLayoutCreateInfoNV, VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV>;
  using GeneratedCommandsInfoNV = InfoT<VkGeneratedCommandsInfoNV, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV>;
  using GeneratedCommandsMemoryRequirementsInfoNV = InfoT<VkGeneratedCommandsMemoryRequirementsInfoNV, VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV>;
  using PipelineIndirectDeviceAddressInfoNV = InfoT<VkPipelineIndirectDeviceAddressInfoNV, VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV>;
  using BindPipelineIndirectCommandNV = DescriptionT<VkBindPipelineIndirectCommandNV>;
  using PhysicalDeviceFeatures2KHR = DescriptionT<VkPhysicalDeviceFeatures2KHR>;
  using PhysicalDeviceProperties2KHR = DescriptionT<VkPhysicalDeviceProperties2KHR>;
  using FormatProperties2KHR = DescriptionT<VkFormatProperties2KHR>;
  using ImageFormatProperties2KHR = DescriptionT<VkImageFormatProperties2KHR>;
  using PhysicalDeviceImageFormatInfo2KHR = DescriptionT<VkPhysicalDeviceImageFormatInfo2KHR>;
  using QueueFamilyProperties2KHR = DescriptionT<VkQueueFamilyProperties2KHR>;
  using PhysicalDeviceMemoryProperties2KHR = DescriptionT<VkPhysicalDeviceMemoryProperties2KHR>;
  using SparseImageFormatProperties2KHR = DescriptionT<VkSparseImageFormatProperties2KHR>;
  using PhysicalDeviceSparseImageFormatInfo2KHR = DescriptionT<VkPhysicalDeviceSparseImageFormatInfo2KHR>;
  using PhysicalDevicePushDescriptorPropertiesKHR = InfoT<VkPhysicalDevicePushDescriptorPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR>;
  using ConformanceVersionKHR = DescriptionT<VkConformanceVersionKHR>;
  using PhysicalDeviceDriverPropertiesKHR = DescriptionT<VkPhysicalDeviceDriverPropertiesKHR>;
  using PresentRegionsKHR = InfoT<VkPresentRegionsKHR, VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR>;
  using PresentRegionKHR = DescriptionT<VkPresentRegionKHR>;
  using RectLayerKHR = DescriptionT<VkRectLayerKHR>;
  using PhysicalDeviceVariablePointersFeaturesKHR = DescriptionT<VkPhysicalDeviceVariablePointersFeaturesKHR>;
  using PhysicalDeviceVariablePointerFeaturesKHR = DescriptionT<VkPhysicalDeviceVariablePointerFeaturesKHR>;
  using ExternalMemoryPropertiesKHR = DescriptionT<VkExternalMemoryPropertiesKHR>;
  using PhysicalDeviceExternalImageFormatInfoKHR = DescriptionT<VkPhysicalDeviceExternalImageFormatInfoKHR>;
  using ExternalImageFormatPropertiesKHR = DescriptionT<VkExternalImageFormatPropertiesKHR>;
  using PhysicalDeviceExternalBufferInfoKHR = DescriptionT<VkPhysicalDeviceExternalBufferInfoKHR>;
  using ExternalBufferPropertiesKHR = DescriptionT<VkExternalBufferPropertiesKHR>;
  using PhysicalDeviceIDPropertiesKHR = DescriptionT<VkPhysicalDeviceIDPropertiesKHR>;
  using ExternalMemoryImageCreateInfoKHR = DescriptionT<VkExternalMemoryImageCreateInfoKHR>;
  using ExternalMemoryBufferCreateInfoKHR = DescriptionT<VkExternalMemoryBufferCreateInfoKHR>;
  using ExportMemoryAllocateInfoKHR = DescriptionT<VkExportMemoryAllocateInfoKHR>;
  using ImportMemoryFdInfoKHR = InfoT<VkImportMemoryFdInfoKHR, VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR>;
  using MemoryFdPropertiesKHR = InfoT<VkMemoryFdPropertiesKHR, VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR>;
  using MemoryGetFdInfoKHR = InfoT<VkMemoryGetFdInfoKHR, VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR>;
  using PhysicalDeviceExternalSemaphoreInfoKHR = DescriptionT<VkPhysicalDeviceExternalSemaphoreInfoKHR>;
  using ExternalSemaphorePropertiesKHR = DescriptionT<VkExternalSemaphorePropertiesKHR>;
  using ExportSemaphoreCreateInfoKHR = DescriptionT<VkExportSemaphoreCreateInfoKHR>;
  using ImportSemaphoreFdInfoKHR = InfoT<VkImportSemaphoreFdInfoKHR, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR>;
  using SemaphoreGetFdInfoKHR = InfoT<VkSemaphoreGetFdInfoKHR, VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR>;
  using PhysicalDeviceExternalFenceInfoKHR = DescriptionT<VkPhysicalDeviceExternalFenceInfoKHR>;
  using ExternalFencePropertiesKHR = DescriptionT<VkExternalFencePropertiesKHR>;
  using ExportFenceCreateInfoKHR = DescriptionT<VkExportFenceCreateInfoKHR>;
  using ImportFenceFdInfoKHR = InfoT<VkImportFenceFdInfoKHR, VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR>;
  using FenceGetFdInfoKHR = InfoT<VkFenceGetFdInfoKHR, VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR>;
  using PhysicalDeviceMultiviewFeaturesKHR = DescriptionT<VkPhysicalDeviceMultiviewFeaturesKHR>;
  using PhysicalDeviceMultiviewPropertiesKHR = DescriptionT<VkPhysicalDeviceMultiviewPropertiesKHR>;
  using RenderPassMultiviewCreateInfoKHR = DescriptionT<VkRenderPassMultiviewCreateInfoKHR>;
  using SurfaceCapabilities2EXT = InfoT<VkSurfaceCapabilities2EXT, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT>;
  using DisplayPowerInfoEXT = InfoT<VkDisplayPowerInfoEXT, VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT>;
  using DeviceEventInfoEXT = InfoT<VkDeviceEventInfoEXT, VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT>;
  using DisplayEventInfoEXT = InfoT<VkDisplayEventInfoEXT, VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT>;
  using SwapchainCounterCreateInfoEXT = InfoT<VkSwapchainCounterCreateInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT>;
  using PhysicalDeviceGroupPropertiesKHR = DescriptionT<VkPhysicalDeviceGroupPropertiesKHR>;
  using MemoryAllocateFlagsInfoKHR = DescriptionT<VkMemoryAllocateFlagsInfoKHR>;
  using BindBufferMemoryInfoKHR = DescriptionT<VkBindBufferMemoryInfoKHR>;
  using BindBufferMemoryDeviceGroupInfoKHR = DescriptionT<VkBindBufferMemoryDeviceGroupInfoKHR>;
  using BindImageMemoryInfoKHR = DescriptionT<VkBindImageMemoryInfoKHR>;
  using BindImageMemoryDeviceGroupInfoKHR = DescriptionT<VkBindImageMemoryDeviceGroupInfoKHR>;
  using DeviceGroupRenderPassBeginInfoKHR = DescriptionT<VkDeviceGroupRenderPassBeginInfoKHR>;
  using DeviceGroupCommandBufferBeginInfoKHR = DescriptionT<VkDeviceGroupCommandBufferBeginInfoKHR>;
  using DeviceGroupSubmitInfoKHR = DescriptionT<VkDeviceGroupSubmitInfoKHR>;
  using DeviceGroupBindSparseInfoKHR = DescriptionT<VkDeviceGroupBindSparseInfoKHR>;
  using DeviceGroupPresentCapabilitiesKHR = InfoT<VkDeviceGroupPresentCapabilitiesKHR, VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR>;
  using ImageSwapchainCreateInfoKHR = InfoT<VkImageSwapchainCreateInfoKHR, VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR>;
  using BindImageMemorySwapchainInfoKHR = InfoT<VkBindImageMemorySwapchainInfoKHR, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR>;
  using AcquireNextImageInfoKHR = InfoT<VkAcquireNextImageInfoKHR, VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR>;
  using DeviceGroupPresentInfoKHR = InfoT<VkDeviceGroupPresentInfoKHR, VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR>;
  using DeviceGroupDeviceCreateInfoKHR = DescriptionT<VkDeviceGroupDeviceCreateInfoKHR>;
  using DeviceGroupSwapchainCreateInfoKHR = InfoT<VkDeviceGroupSwapchainCreateInfoKHR, VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR>;
  using DescriptorUpdateTemplateEntryKHR = DescriptionT<VkDescriptorUpdateTemplateEntryKHR>;
  using DescriptorUpdateTemplateCreateInfoKHR = DescriptionT<VkDescriptorUpdateTemplateCreateInfoKHR>;
  using XYColorEXT = DescriptionT<VkXYColorEXT>;
  using PhysicalDevicePresentIdFeaturesKHR = InfoT<VkPhysicalDevicePresentIdFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR>;
  using PresentIdKHR = InfoT<VkPresentIdKHR, VK_STRUCTURE_TYPE_PRESENT_ID_KHR>;
  using PhysicalDevicePresentWaitFeaturesKHR = InfoT<VkPhysicalDevicePresentWaitFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR>;
  using HdrMetadataEXT = InfoT<VkHdrMetadataEXT, VK_STRUCTURE_TYPE_HDR_METADATA_EXT>;
  using DisplayNativeHdrSurfaceCapabilitiesAMD = InfoT<VkDisplayNativeHdrSurfaceCapabilitiesAMD, VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD>;
  using SwapchainDisplayNativeHdrCreateInfoAMD = InfoT<VkSwapchainDisplayNativeHdrCreateInfoAMD, VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD>;
  using RefreshCycleDurationGOOGLE = DescriptionT<VkRefreshCycleDurationGOOGLE>;
  using PastPresentationTimingGOOGLE = DescriptionT<VkPastPresentationTimingGOOGLE>;
  using PresentTimesInfoGOOGLE = InfoT<VkPresentTimesInfoGOOGLE, VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE>;
  using PresentTimeGOOGLE = DescriptionT<VkPresentTimeGOOGLE>;
  using ViewportWScalingNV = DescriptionT<VkViewportWScalingNV>;
  using PipelineViewportWScalingStateCreateInfoNV = InfoT<VkPipelineViewportWScalingStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV>;
  using ViewportSwizzleNV = DescriptionT<VkViewportSwizzleNV>;
  using PipelineViewportSwizzleStateCreateInfoNV = InfoT<VkPipelineViewportSwizzleStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV>;
  using PhysicalDeviceDiscardRectanglePropertiesEXT = InfoT<VkPhysicalDeviceDiscardRectanglePropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT>;
  using PipelineDiscardRectangleStateCreateInfoEXT = InfoT<VkPipelineDiscardRectangleStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT>;
  using PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX = InfoT<VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX>;
  using InputAttachmentAspectReferenceKHR = DescriptionT<VkInputAttachmentAspectReferenceKHR>;
  using RenderPassInputAttachmentAspectCreateInfoKHR = DescriptionT<VkRenderPassInputAttachmentAspectCreateInfoKHR>;
  using PhysicalDeviceSurfaceInfo2KHR = InfoT<VkPhysicalDeviceSurfaceInfo2KHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR>;
  using SurfaceCapabilities2KHR = InfoT<VkSurfaceCapabilities2KHR, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR>;
  using SurfaceFormat2KHR = InfoT<VkSurfaceFormat2KHR, VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR>;
  using DisplayProperties2KHR = InfoT<VkDisplayProperties2KHR, VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR>;
  using DisplayPlaneProperties2KHR = InfoT<VkDisplayPlaneProperties2KHR, VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR>;
  using DisplayModeProperties2KHR = InfoT<VkDisplayModeProperties2KHR, VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR>;
  using DisplayPlaneInfo2KHR = InfoT<VkDisplayPlaneInfo2KHR, VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR>;
  using DisplayPlaneCapabilities2KHR = InfoT<VkDisplayPlaneCapabilities2KHR, VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR>;
  using SharedPresentSurfaceCapabilitiesKHR = InfoT<VkSharedPresentSurfaceCapabilitiesKHR, VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR>;
  using PhysicalDevice16BitStorageFeaturesKHR = DescriptionT<VkPhysicalDevice16BitStorageFeaturesKHR>;
  using PhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR = DescriptionT<VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR>;
  using BufferMemoryRequirementsInfo2KHR = DescriptionT<VkBufferMemoryRequirementsInfo2KHR>;
  using DeviceBufferMemoryRequirementsKHR = DescriptionT<VkDeviceBufferMemoryRequirementsKHR>;
  using ImageMemoryRequirementsInfo2KHR = DescriptionT<VkImageMemoryRequirementsInfo2KHR>;
  using ImageSparseMemoryRequirementsInfo2KHR = DescriptionT<VkImageSparseMemoryRequirementsInfo2KHR>;
  using DeviceImageMemoryRequirementsKHR = DescriptionT<VkDeviceImageMemoryRequirementsKHR>;
  using MemoryRequirements2KHR = DescriptionT<VkMemoryRequirements2KHR>;
  using SparseImageMemoryRequirements2KHR = DescriptionT<VkSparseImageMemoryRequirements2KHR>;
  using PhysicalDevicePointClippingPropertiesKHR = DescriptionT<VkPhysicalDevicePointClippingPropertiesKHR>;
  using MemoryDedicatedRequirementsKHR = DescriptionT<VkMemoryDedicatedRequirementsKHR>;
  using MemoryDedicatedAllocateInfoKHR = DescriptionT<VkMemoryDedicatedAllocateInfoKHR>;
  using ImageViewSlicedCreateInfoEXT = InfoT<VkImageViewSlicedCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT>;
  using ImageViewUsageCreateInfoKHR = DescriptionT<VkImageViewUsageCreateInfoKHR>;
  using PipelineTessellationDomainOriginStateCreateInfoKHR = DescriptionT<VkPipelineTessellationDomainOriginStateCreateInfoKHR>;
  using SamplerYcbcrConversionInfoKHR = DescriptionT<VkSamplerYcbcrConversionInfoKHR>;
  using SamplerYcbcrConversionCreateInfoKHR = DescriptionT<VkSamplerYcbcrConversionCreateInfoKHR>;
  using BindImagePlaneMemoryInfoKHR = DescriptionT<VkBindImagePlaneMemoryInfoKHR>;
  using ImagePlaneMemoryRequirementsInfoKHR = DescriptionT<VkImagePlaneMemoryRequirementsInfoKHR>;
  using PhysicalDeviceSamplerYcbcrConversionFeaturesKHR = DescriptionT<VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR>;
  using SamplerYcbcrConversionImageFormatPropertiesKHR = DescriptionT<VkSamplerYcbcrConversionImageFormatPropertiesKHR>;
  using TextureLODGatherFormatPropertiesAMD = InfoT<VkTextureLODGatherFormatPropertiesAMD, VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD>;
  using ConditionalRenderingBeginInfoEXT = InfoT<VkConditionalRenderingBeginInfoEXT, VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT>;
  using PipelineCoverageToColorStateCreateInfoNV = InfoT<VkPipelineCoverageToColorStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV>;
  using PhysicalDeviceSamplerFilterMinmaxPropertiesEXT = DescriptionT<VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT>;
  using SampleLocationEXT = DescriptionT<VkSampleLocationEXT>;
  using SampleLocationsInfoEXT = InfoT<VkSampleLocationsInfoEXT, VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT>;
  using AttachmentSampleLocationsEXT = DescriptionT<VkAttachmentSampleLocationsEXT>;
  using SubpassSampleLocationsEXT = DescriptionT<VkSubpassSampleLocationsEXT>;
  using RenderPassSampleLocationsBeginInfoEXT = InfoT<VkRenderPassSampleLocationsBeginInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT>;
  using PipelineSampleLocationsStateCreateInfoEXT = InfoT<VkPipelineSampleLocationsStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT>;
  using PhysicalDeviceSampleLocationsPropertiesEXT = InfoT<VkPhysicalDeviceSampleLocationsPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT>;
  using MultisamplePropertiesEXT = InfoT<VkMultisamplePropertiesEXT, VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT>;
  using SamplerReductionModeCreateInfoEXT = DescriptionT<VkSamplerReductionModeCreateInfoEXT>;
  using PhysicalDeviceBlendOperationAdvancedFeaturesEXT = InfoT<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT>;
  using PhysicalDeviceMultiDrawFeaturesEXT = InfoT<VkPhysicalDeviceMultiDrawFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT>;
  using PhysicalDeviceBlendOperationAdvancedPropertiesEXT = InfoT<VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT>;
  using PipelineColorBlendAdvancedStateCreateInfoEXT = InfoT<VkPipelineColorBlendAdvancedStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT>;
  using PhysicalDeviceInlineUniformBlockFeaturesEXT = DescriptionT<VkPhysicalDeviceInlineUniformBlockFeaturesEXT>;
  using PhysicalDeviceInlineUniformBlockPropertiesEXT = DescriptionT<VkPhysicalDeviceInlineUniformBlockPropertiesEXT>;
  using WriteDescriptorSetInlineUniformBlockEXT = DescriptionT<VkWriteDescriptorSetInlineUniformBlockEXT>;
  using DescriptorPoolInlineUniformBlockCreateInfoEXT = DescriptionT<VkDescriptorPoolInlineUniformBlockCreateInfoEXT>;
  using PipelineCoverageModulationStateCreateInfoNV = InfoT<VkPipelineCoverageModulationStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV>;
  using ImageFormatListCreateInfoKHR = DescriptionT<VkImageFormatListCreateInfoKHR>;
  using ValidationCacheCreateInfoEXT = InfoT<VkValidationCacheCreateInfoEXT, VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT>;
  using ShaderModuleValidationCacheCreateInfoEXT = InfoT<VkShaderModuleValidationCacheCreateInfoEXT, VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT>;
  using PhysicalDeviceMaintenance3PropertiesKHR = DescriptionT<VkPhysicalDeviceMaintenance3PropertiesKHR>;
  using PhysicalDeviceMaintenance4FeaturesKHR = DescriptionT<VkPhysicalDeviceMaintenance4FeaturesKHR>;
  using PhysicalDeviceMaintenance4PropertiesKHR = DescriptionT<VkPhysicalDeviceMaintenance4PropertiesKHR>;
  using PhysicalDeviceMaintenance5FeaturesKHR = InfoT<VkPhysicalDeviceMaintenance5FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR>;
  using PhysicalDeviceMaintenance5PropertiesKHR = InfoT<VkPhysicalDeviceMaintenance5PropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR>;
  using PhysicalDeviceMaintenance6FeaturesKHR = InfoT<VkPhysicalDeviceMaintenance6FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR>;
  using PhysicalDeviceMaintenance6PropertiesKHR = InfoT<VkPhysicalDeviceMaintenance6PropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR>;
  using RenderingAreaInfoKHR = InfoT<VkRenderingAreaInfoKHR, VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR>;
  using DescriptorSetLayoutSupportKHR = DescriptionT<VkDescriptorSetLayoutSupportKHR>;
  using PhysicalDeviceShaderFloat16Int8FeaturesKHR = DescriptionT<VkPhysicalDeviceShaderFloat16Int8FeaturesKHR>;
  using PhysicalDeviceFloat16Int8FeaturesKHR = DescriptionT<VkPhysicalDeviceFloat16Int8FeaturesKHR>;
  using PhysicalDeviceFloatControlsPropertiesKHR = DescriptionT<VkPhysicalDeviceFloatControlsPropertiesKHR>;
  using PhysicalDeviceHostQueryResetFeaturesEXT = DescriptionT<VkPhysicalDeviceHostQueryResetFeaturesEXT>;
  using ShaderResourceUsageAMD = DescriptionT<VkShaderResourceUsageAMD>;
  using ShaderStatisticsInfoAMD = DescriptionT<VkShaderStatisticsInfoAMD>;
  using DeviceQueueGlobalPriorityCreateInfoKHR = InfoT<VkDeviceQueueGlobalPriorityCreateInfoKHR, VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR>;
  using DeviceQueueGlobalPriorityCreateInfoEXT = DescriptionT<VkDeviceQueueGlobalPriorityCreateInfoEXT>;
  using PhysicalDeviceGlobalPriorityQueryFeaturesKHR = InfoT<VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR>;
  using PhysicalDeviceGlobalPriorityQueryFeaturesEXT = DescriptionT<VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT>;
  using QueueFamilyGlobalPriorityPropertiesKHR = InfoT<VkQueueFamilyGlobalPriorityPropertiesKHR, VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR>;
  using QueueFamilyGlobalPriorityPropertiesEXT = DescriptionT<VkQueueFamilyGlobalPriorityPropertiesEXT>;
  using DebugUtilsObjectNameInfoEXT = InfoT<VkDebugUtilsObjectNameInfoEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT>;
  using DebugUtilsObjectTagInfoEXT = InfoT<VkDebugUtilsObjectTagInfoEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT>;
  using DebugUtilsLabelEXT = InfoT<VkDebugUtilsLabelEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT>;
  using DebugUtilsMessengerCreateInfoEXT = InfoT<VkDebugUtilsMessengerCreateInfoEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT>;
  using DebugUtilsMessengerCallbackDataEXT = InfoT<VkDebugUtilsMessengerCallbackDataEXT, VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT>;
  using PhysicalDeviceDeviceMemoryReportFeaturesEXT = InfoT<VkPhysicalDeviceDeviceMemoryReportFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT>;
  using DeviceDeviceMemoryReportCreateInfoEXT = InfoT<VkDeviceDeviceMemoryReportCreateInfoEXT, VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT>;
  using DeviceMemoryReportCallbackDataEXT = InfoT<VkDeviceMemoryReportCallbackDataEXT, VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT>;
  using ImportMemoryHostPointerInfoEXT = InfoT<VkImportMemoryHostPointerInfoEXT, VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT>;
  using MemoryHostPointerPropertiesEXT = InfoT<VkMemoryHostPointerPropertiesEXT, VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT>;
  using PhysicalDeviceExternalMemoryHostPropertiesEXT = InfoT<VkPhysicalDeviceExternalMemoryHostPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT>;
  using PhysicalDeviceConservativeRasterizationPropertiesEXT = InfoT<VkPhysicalDeviceConservativeRasterizationPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT>;
  using CalibratedTimestampInfoKHR = InfoT<VkCalibratedTimestampInfoKHR, VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR>;
  using CalibratedTimestampInfoEXT = DescriptionT<VkCalibratedTimestampInfoEXT>;
  using PhysicalDeviceShaderCorePropertiesAMD = InfoT<VkPhysicalDeviceShaderCorePropertiesAMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD>;
  using PhysicalDeviceShaderCoreProperties2AMD = InfoT<VkPhysicalDeviceShaderCoreProperties2AMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD>;
  using PipelineRasterizationConservativeStateCreateInfoEXT = InfoT<VkPipelineRasterizationConservativeStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT>;
  using PhysicalDeviceDescriptorIndexingFeaturesEXT = DescriptionT<VkPhysicalDeviceDescriptorIndexingFeaturesEXT>;
  using PhysicalDeviceDescriptorIndexingPropertiesEXT = DescriptionT<VkPhysicalDeviceDescriptorIndexingPropertiesEXT>;
  using DescriptorSetLayoutBindingFlagsCreateInfoEXT = DescriptionT<VkDescriptorSetLayoutBindingFlagsCreateInfoEXT>;
  using DescriptorSetVariableDescriptorCountAllocateInfoEXT = DescriptionT<VkDescriptorSetVariableDescriptorCountAllocateInfoEXT>;
  using DescriptorSetVariableDescriptorCountLayoutSupportEXT = DescriptionT<VkDescriptorSetVariableDescriptorCountLayoutSupportEXT>;
  using AttachmentDescription2KHR = DescriptionT<VkAttachmentDescription2KHR>;
  using AttachmentReference2KHR = DescriptionT<VkAttachmentReference2KHR>;
  using SubpassDescription2KHR = DescriptionT<VkSubpassDescription2KHR>;
  using SubpassDependency2KHR = DescriptionT<VkSubpassDependency2KHR>;
  using RenderPassCreateInfo2KHR = DescriptionT<VkRenderPassCreateInfo2KHR>;
  using SubpassBeginInfoKHR = DescriptionT<VkSubpassBeginInfoKHR>;
  using SubpassEndInfoKHR = DescriptionT<VkSubpassEndInfoKHR>;
  using PhysicalDeviceTimelineSemaphoreFeaturesKHR = DescriptionT<VkPhysicalDeviceTimelineSemaphoreFeaturesKHR>;
  using PhysicalDeviceTimelineSemaphorePropertiesKHR = DescriptionT<VkPhysicalDeviceTimelineSemaphorePropertiesKHR>;
  using SemaphoreTypeCreateInfoKHR = DescriptionT<VkSemaphoreTypeCreateInfoKHR>;
  using TimelineSemaphoreSubmitInfoKHR = DescriptionT<VkTimelineSemaphoreSubmitInfoKHR>;
  using SemaphoreWaitInfoKHR = DescriptionT<VkSemaphoreWaitInfoKHR>;
  using SemaphoreSignalInfoKHR = DescriptionT<VkSemaphoreSignalInfoKHR>;
  using VertexInputBindingDivisorDescriptionKHR = DescriptionT<VkVertexInputBindingDivisorDescriptionKHR>;
  using VertexInputBindingDivisorDescriptionEXT = DescriptionT<VkVertexInputBindingDivisorDescriptionEXT>;
  using PipelineVertexInputDivisorStateCreateInfoKHR = InfoT<VkPipelineVertexInputDivisorStateCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR>;
  using PipelineVertexInputDivisorStateCreateInfoEXT = DescriptionT<VkPipelineVertexInputDivisorStateCreateInfoEXT>;
  using PhysicalDeviceVertexAttributeDivisorPropertiesEXT = InfoT<VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT>;
  using PhysicalDeviceVertexAttributeDivisorPropertiesKHR = InfoT<VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR>;
  using PhysicalDevicePCIBusInfoPropertiesEXT = InfoT<VkPhysicalDevicePCIBusInfoPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT>;
  using CommandBufferInheritanceConditionalRenderingInfoEXT = InfoT<VkCommandBufferInheritanceConditionalRenderingInfoEXT, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT>;
  using PhysicalDevice8BitStorageFeaturesKHR = DescriptionT<VkPhysicalDevice8BitStorageFeaturesKHR>;
  using PhysicalDeviceConditionalRenderingFeaturesEXT = InfoT<VkPhysicalDeviceConditionalRenderingFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT>;
  using PhysicalDeviceVulkanMemoryModelFeaturesKHR = DescriptionT<VkPhysicalDeviceVulkanMemoryModelFeaturesKHR>;
  using PhysicalDeviceShaderAtomicInt64FeaturesKHR = DescriptionT<VkPhysicalDeviceShaderAtomicInt64FeaturesKHR>;
  using PhysicalDeviceShaderAtomicFloatFeaturesEXT = InfoT<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT>;
  using PhysicalDeviceShaderAtomicFloat2FeaturesEXT = InfoT<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT>;
  using PhysicalDeviceVertexAttributeDivisorFeaturesKHR = InfoT<VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR>;
  using PhysicalDeviceVertexAttributeDivisorFeaturesEXT = DescriptionT<VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT>;
  using QueueFamilyCheckpointPropertiesNV = InfoT<VkQueueFamilyCheckpointPropertiesNV, VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV>;
  using CheckpointDataNV = InfoT<VkCheckpointDataNV, VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV>;
  using PhysicalDeviceDepthStencilResolvePropertiesKHR = DescriptionT<VkPhysicalDeviceDepthStencilResolvePropertiesKHR>;
  using SubpassDescriptionDepthStencilResolveKHR = DescriptionT<VkSubpassDescriptionDepthStencilResolveKHR>;
  using ImageViewASTCDecodeModeEXT = InfoT<VkImageViewASTCDecodeModeEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT>;
  using PhysicalDeviceASTCDecodeFeaturesEXT = InfoT<VkPhysicalDeviceASTCDecodeFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT>;
  using PhysicalDeviceTransformFeedbackFeaturesEXT = InfoT<VkPhysicalDeviceTransformFeedbackFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT>;
  using PhysicalDeviceTransformFeedbackPropertiesEXT = InfoT<VkPhysicalDeviceTransformFeedbackPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT>;
  using PipelineRasterizationStateStreamCreateInfoEXT = InfoT<VkPipelineRasterizationStateStreamCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT>;
  using PhysicalDeviceRepresentativeFragmentTestFeaturesNV = InfoT<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV>;
  using PipelineRepresentativeFragmentTestStateCreateInfoNV = InfoT<VkPipelineRepresentativeFragmentTestStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV>;
  using PhysicalDeviceExclusiveScissorFeaturesNV = InfoT<VkPhysicalDeviceExclusiveScissorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV>;
  using PipelineViewportExclusiveScissorStateCreateInfoNV = InfoT<VkPipelineViewportExclusiveScissorStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV>;
  using PhysicalDeviceCornerSampledImageFeaturesNV = InfoT<VkPhysicalDeviceCornerSampledImageFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV>;
  using PhysicalDeviceComputeShaderDerivativesFeaturesNV = InfoT<VkPhysicalDeviceComputeShaderDerivativesFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV>;
  using PhysicalDeviceFragmentShaderBarycentricFeaturesNV = DescriptionT<VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV>;
  using PhysicalDeviceShaderImageFootprintFeaturesNV = InfoT<VkPhysicalDeviceShaderImageFootprintFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV>;
  using PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV = InfoT<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV>;
  using PhysicalDeviceCopyMemoryIndirectFeaturesNV = InfoT<VkPhysicalDeviceCopyMemoryIndirectFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV>;
  using PhysicalDeviceCopyMemoryIndirectPropertiesNV = InfoT<VkPhysicalDeviceCopyMemoryIndirectPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV>;
  using PhysicalDeviceMemoryDecompressionFeaturesNV = InfoT<VkPhysicalDeviceMemoryDecompressionFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV>;
  using PhysicalDeviceMemoryDecompressionPropertiesNV = InfoT<VkPhysicalDeviceMemoryDecompressionPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV>;
  using ShadingRatePaletteNV = DescriptionT<VkShadingRatePaletteNV>;
  using PipelineViewportShadingRateImageStateCreateInfoNV = InfoT<VkPipelineViewportShadingRateImageStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV>;
  using PhysicalDeviceShadingRateImageFeaturesNV = InfoT<VkPhysicalDeviceShadingRateImageFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV>;
  using PhysicalDeviceShadingRateImagePropertiesNV = InfoT<VkPhysicalDeviceShadingRateImagePropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV>;
  using PhysicalDeviceInvocationMaskFeaturesHUAWEI = InfoT<VkPhysicalDeviceInvocationMaskFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI>;
  using CoarseSampleLocationNV = DescriptionT<VkCoarseSampleLocationNV>;
  using CoarseSampleOrderCustomNV = DescriptionT<VkCoarseSampleOrderCustomNV>;
  using PipelineViewportCoarseSampleOrderStateCreateInfoNV = InfoT<VkPipelineViewportCoarseSampleOrderStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV>;
  using PhysicalDeviceMeshShaderFeaturesNV = InfoT<VkPhysicalDeviceMeshShaderFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV>;
  using PhysicalDeviceMeshShaderPropertiesNV = InfoT<VkPhysicalDeviceMeshShaderPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV>;
  using DrawMeshTasksIndirectCommandNV = DescriptionT<VkDrawMeshTasksIndirectCommandNV>;
  using PhysicalDeviceMeshShaderFeaturesEXT = InfoT<VkPhysicalDeviceMeshShaderFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT>;
  using PhysicalDeviceMeshShaderPropertiesEXT = InfoT<VkPhysicalDeviceMeshShaderPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT>;
  using DrawMeshTasksIndirectCommandEXT = DescriptionT<VkDrawMeshTasksIndirectCommandEXT>;
  using RayTracingShaderGroupCreateInfoNV = InfoT<VkRayTracingShaderGroupCreateInfoNV, VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV>;
  using RayTracingShaderGroupCreateInfoKHR = InfoT<VkRayTracingShaderGroupCreateInfoKHR, VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR>;
  using RayTracingPipelineCreateInfoNV = InfoT<VkRayTracingPipelineCreateInfoNV, VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV>;
  using RayTracingPipelineCreateInfoKHR = InfoT<VkRayTracingPipelineCreateInfoKHR, VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR>;
  using GeometryTrianglesNV = InfoT<VkGeometryTrianglesNV, VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV>;
  using GeometryAABBNV = InfoT<VkGeometryAABBNV, VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV>;
  using GeometryDataNV = DescriptionT<VkGeometryDataNV>;
  using GeometryNV = InfoT<VkGeometryNV, VK_STRUCTURE_TYPE_GEOMETRY_NV>;
  using AccelerationStructureInfoNV = InfoT<VkAccelerationStructureInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV>;
  using AccelerationStructureCreateInfoNV = InfoT<VkAccelerationStructureCreateInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV>;
  using BindAccelerationStructureMemoryInfoNV = InfoT<VkBindAccelerationStructureMemoryInfoNV, VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV>;
  using WriteDescriptorSetAccelerationStructureKHR = InfoT<VkWriteDescriptorSetAccelerationStructureKHR, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR>;
  using WriteDescriptorSetAccelerationStructureNV = InfoT<VkWriteDescriptorSetAccelerationStructureNV, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV>;
  using AccelerationStructureMemoryRequirementsInfoNV = InfoT<VkAccelerationStructureMemoryRequirementsInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV>;
  using PhysicalDeviceAccelerationStructureFeaturesKHR = InfoT<VkPhysicalDeviceAccelerationStructureFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR>;
  using PhysicalDeviceRayTracingPipelineFeaturesKHR = InfoT<VkPhysicalDeviceRayTracingPipelineFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR>;
  using PhysicalDeviceRayQueryFeaturesKHR = InfoT<VkPhysicalDeviceRayQueryFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR>;
  using PhysicalDeviceAccelerationStructurePropertiesKHR = InfoT<VkPhysicalDeviceAccelerationStructurePropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR>;
  using PhysicalDeviceRayTracingPipelinePropertiesKHR = InfoT<VkPhysicalDeviceRayTracingPipelinePropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR>;
  using PhysicalDeviceRayTracingPropertiesNV = InfoT<VkPhysicalDeviceRayTracingPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV>;
  using StridedDeviceAddressRegionKHR = DescriptionT<VkStridedDeviceAddressRegionKHR>;
  using TraceRaysIndirectCommandKHR = DescriptionT<VkTraceRaysIndirectCommandKHR>;
  using TraceRaysIndirectCommand2KHR = DescriptionT<VkTraceRaysIndirectCommand2KHR>;
  using PhysicalDeviceRayTracingMaintenance1FeaturesKHR = InfoT<VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR>;
  using DrmFormatModifierPropertiesListEXT = InfoT<VkDrmFormatModifierPropertiesListEXT, VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT>;
  using DrmFormatModifierPropertiesEXT = DescriptionT<VkDrmFormatModifierPropertiesEXT>;
  using PhysicalDeviceImageDrmFormatModifierInfoEXT = InfoT<VkPhysicalDeviceImageDrmFormatModifierInfoEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT>;
  using ImageDrmFormatModifierListCreateInfoEXT = InfoT<VkImageDrmFormatModifierListCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT>;
  using ImageDrmFormatModifierExplicitCreateInfoEXT = InfoT<VkImageDrmFormatModifierExplicitCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT>;
  using ImageDrmFormatModifierPropertiesEXT = InfoT<VkImageDrmFormatModifierPropertiesEXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT>;
  using ImageStencilUsageCreateInfoEXT = DescriptionT<VkImageStencilUsageCreateInfoEXT>;
  using DeviceMemoryOverallocationCreateInfoAMD = InfoT<VkDeviceMemoryOverallocationCreateInfoAMD, VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD>;
  using PhysicalDeviceFragmentDensityMapFeaturesEXT = InfoT<VkPhysicalDeviceFragmentDensityMapFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT>;
  using PhysicalDeviceFragmentDensityMap2FeaturesEXT = InfoT<VkPhysicalDeviceFragmentDensityMap2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT>;
  using PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM = InfoT<VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM>;
  using PhysicalDeviceFragmentDensityMapPropertiesEXT = InfoT<VkPhysicalDeviceFragmentDensityMapPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT>;
  using PhysicalDeviceFragmentDensityMap2PropertiesEXT = InfoT<VkPhysicalDeviceFragmentDensityMap2PropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT>;
  using PhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM = InfoT<VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM>;
  using RenderPassFragmentDensityMapCreateInfoEXT = InfoT<VkRenderPassFragmentDensityMapCreateInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT>;
  using SubpassFragmentDensityMapOffsetEndInfoQCOM = InfoT<VkSubpassFragmentDensityMapOffsetEndInfoQCOM, VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM>;
  using PhysicalDeviceScalarBlockLayoutFeaturesEXT = DescriptionT<VkPhysicalDeviceScalarBlockLayoutFeaturesEXT>;
  using SurfaceProtectedCapabilitiesKHR = InfoT<VkSurfaceProtectedCapabilitiesKHR, VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR>;
  using PhysicalDeviceUniformBufferStandardLayoutFeaturesKHR = DescriptionT<VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR>;
  using PhysicalDeviceDepthClipEnableFeaturesEXT = InfoT<VkPhysicalDeviceDepthClipEnableFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT>;
  using PipelineRasterizationDepthClipStateCreateInfoEXT = InfoT<VkPipelineRasterizationDepthClipStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT>;
  using PhysicalDeviceMemoryBudgetPropertiesEXT = InfoT<VkPhysicalDeviceMemoryBudgetPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT>;
  using PhysicalDeviceMemoryPriorityFeaturesEXT = InfoT<VkPhysicalDeviceMemoryPriorityFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT>;
  using MemoryPriorityAllocateInfoEXT = InfoT<VkMemoryPriorityAllocateInfoEXT, VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT>;
  using PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT = InfoT<VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT>;
  using PhysicalDeviceBufferDeviceAddressFeaturesKHR = DescriptionT<VkPhysicalDeviceBufferDeviceAddressFeaturesKHR>;
  using PhysicalDeviceBufferDeviceAddressFeaturesEXT = InfoT<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT>;
  using PhysicalDeviceBufferAddressFeaturesEXT = DescriptionT<VkPhysicalDeviceBufferAddressFeaturesEXT>;
  using BufferDeviceAddressInfoKHR = DescriptionT<VkBufferDeviceAddressInfoKHR>;
  using BufferDeviceAddressInfoEXT = DescriptionT<VkBufferDeviceAddressInfoEXT>;
  using BufferOpaqueCaptureAddressCreateInfoKHR = DescriptionT<VkBufferOpaqueCaptureAddressCreateInfoKHR>;
  using BufferDeviceAddressCreateInfoEXT = InfoT<VkBufferDeviceAddressCreateInfoEXT, VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT>;
  using PhysicalDeviceImageViewImageFormatInfoEXT = InfoT<VkPhysicalDeviceImageViewImageFormatInfoEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT>;
  using FilterCubicImageViewImageFormatPropertiesEXT = InfoT<VkFilterCubicImageViewImageFormatPropertiesEXT, VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT>;
  using PhysicalDeviceImagelessFramebufferFeaturesKHR = DescriptionT<VkPhysicalDeviceImagelessFramebufferFeaturesKHR>;
  using FramebufferAttachmentsCreateInfoKHR = DescriptionT<VkFramebufferAttachmentsCreateInfoKHR>;
  using FramebufferAttachmentImageInfoKHR = DescriptionT<VkFramebufferAttachmentImageInfoKHR>;
  using RenderPassAttachmentBeginInfoKHR = DescriptionT<VkRenderPassAttachmentBeginInfoKHR>;
  using PhysicalDeviceTextureCompressionASTCHDRFeaturesEXT = DescriptionT<VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT>;
  using PhysicalDeviceCooperativeMatrixFeaturesNV = InfoT<VkPhysicalDeviceCooperativeMatrixFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV>;
  using PhysicalDeviceCooperativeMatrixPropertiesNV = InfoT<VkPhysicalDeviceCooperativeMatrixPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV>;
  using CooperativeMatrixPropertiesNV = InfoT<VkCooperativeMatrixPropertiesNV, VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV>;
  using PhysicalDeviceYcbcrImageArraysFeaturesEXT = InfoT<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT>;
  using ImageViewHandleInfoNVX = InfoT<VkImageViewHandleInfoNVX, VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX>;
  using ImageViewAddressPropertiesNVX = InfoT<VkImageViewAddressPropertiesNVX, VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX>;
  using PipelineCreationFeedbackEXT = DescriptionT<VkPipelineCreationFeedbackEXT>;
  using PipelineCreationFeedbackCreateInfoEXT = DescriptionT<VkPipelineCreationFeedbackCreateInfoEXT>;
  using PhysicalDevicePresentBarrierFeaturesNV = InfoT<VkPhysicalDevicePresentBarrierFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV>;
  using SurfaceCapabilitiesPresentBarrierNV = InfoT<VkSurfaceCapabilitiesPresentBarrierNV, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV>;
  using SwapchainPresentBarrierCreateInfoNV = InfoT<VkSwapchainPresentBarrierCreateInfoNV, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV>;
  using PhysicalDevicePerformanceQueryFeaturesKHR = InfoT<VkPhysicalDevicePerformanceQueryFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR>;
  using PhysicalDevicePerformanceQueryPropertiesKHR = InfoT<VkPhysicalDevicePerformanceQueryPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR>;
  using PerformanceCounterKHR = InfoT<VkPerformanceCounterKHR, VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR>;
  using PerformanceCounterDescriptionKHR = InfoT<VkPerformanceCounterDescriptionKHR, VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR>;
  using QueryPoolPerformanceCreateInfoKHR = InfoT<VkQueryPoolPerformanceCreateInfoKHR, VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR>;
  using AcquireProfilingLockInfoKHR = InfoT<VkAcquireProfilingLockInfoKHR, VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR>;
  using PerformanceQuerySubmitInfoKHR = InfoT<VkPerformanceQuerySubmitInfoKHR, VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR>;
  using HeadlessSurfaceCreateInfoEXT = InfoT<VkHeadlessSurfaceCreateInfoEXT, VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT>;
  using PhysicalDeviceCoverageReductionModeFeaturesNV = InfoT<VkPhysicalDeviceCoverageReductionModeFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV>;
  using PipelineCoverageReductionStateCreateInfoNV = InfoT<VkPipelineCoverageReductionStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV>;
  using FramebufferMixedSamplesCombinationNV = InfoT<VkFramebufferMixedSamplesCombinationNV, VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV>;
  using PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL = InfoT<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL>;
  using PerformanceValueINTEL = DescriptionT<VkPerformanceValueINTEL>;
  using InitializePerformanceApiInfoINTEL = InfoT<VkInitializePerformanceApiInfoINTEL, VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL>;
  using QueryPoolPerformanceQueryCreateInfoINTEL = InfoT<VkQueryPoolPerformanceQueryCreateInfoINTEL, VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL>;
  using QueryPoolCreateInfoINTEL = DescriptionT<VkQueryPoolCreateInfoINTEL>;
  using PerformanceMarkerInfoINTEL = InfoT<VkPerformanceMarkerInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL>;
  using PerformanceStreamMarkerInfoINTEL = InfoT<VkPerformanceStreamMarkerInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL>;
  using PerformanceOverrideInfoINTEL = InfoT<VkPerformanceOverrideInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL>;
  using PerformanceConfigurationAcquireInfoINTEL = InfoT<VkPerformanceConfigurationAcquireInfoINTEL, VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL>;
  using PhysicalDeviceShaderClockFeaturesKHR = InfoT<VkPhysicalDeviceShaderClockFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR>;
  using PhysicalDeviceIndexTypeUint8FeaturesKHR = InfoT<VkPhysicalDeviceIndexTypeUint8FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR>;
  using PhysicalDeviceIndexTypeUint8FeaturesEXT = DescriptionT<VkPhysicalDeviceIndexTypeUint8FeaturesEXT>;
  using PhysicalDeviceShaderSMBuiltinsPropertiesNV = InfoT<VkPhysicalDeviceShaderSMBuiltinsPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV>;
  using PhysicalDeviceShaderSMBuiltinsFeaturesNV = InfoT<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV>;
  using PhysicalDeviceFragmentShaderInterlockFeaturesEXT = InfoT<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT>;
  using PhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR = DescriptionT<VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR>;
  using PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT = InfoT<VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT>;
  using AttachmentReferenceStencilLayoutKHR = DescriptionT<VkAttachmentReferenceStencilLayoutKHR>;
  using AttachmentDescriptionStencilLayoutKHR = DescriptionT<VkAttachmentDescriptionStencilLayoutKHR>;
  using PhysicalDevicePipelineExecutablePropertiesFeaturesKHR = InfoT<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR>;
  using PipelineInfoKHR = InfoT<VkPipelineInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR>;
  using PipelineInfoEXT = DescriptionT<VkPipelineInfoEXT>;
  using PipelineExecutablePropertiesKHR = InfoT<VkPipelineExecutablePropertiesKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR>;
  using PipelineExecutableInfoKHR = InfoT<VkPipelineExecutableInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR>;
  using PipelineExecutableStatisticKHR = InfoT<VkPipelineExecutableStatisticKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR>;
  using PipelineExecutableInternalRepresentationKHR = InfoT<VkPipelineExecutableInternalRepresentationKHR, VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR>;
  using PhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT = DescriptionT<VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT>;
  using PhysicalDeviceTexelBufferAlignmentFeaturesEXT = InfoT<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT>;
  using PhysicalDeviceTexelBufferAlignmentPropertiesEXT = DescriptionT<VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT>;
  using PhysicalDeviceSubgroupSizeControlFeaturesEXT = DescriptionT<VkPhysicalDeviceSubgroupSizeControlFeaturesEXT>;
  using PhysicalDeviceSubgroupSizeControlPropertiesEXT = DescriptionT<VkPhysicalDeviceSubgroupSizeControlPropertiesEXT>;
  using PipelineShaderStageRequiredSubgroupSizeCreateInfoEXT = DescriptionT<VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT>;
  using ShaderRequiredSubgroupSizeCreateInfoEXT = DescriptionT<VkShaderRequiredSubgroupSizeCreateInfoEXT>;
  using SubpassShadingPipelineCreateInfoHUAWEI = InfoT<VkSubpassShadingPipelineCreateInfoHUAWEI, VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI>;
  using PhysicalDeviceSubpassShadingPropertiesHUAWEI = InfoT<VkPhysicalDeviceSubpassShadingPropertiesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI>;
  using PhysicalDeviceClusterCullingShaderPropertiesHUAWEI = InfoT<VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI>;
  using MemoryOpaqueCaptureAddressAllocateInfoKHR = DescriptionT<VkMemoryOpaqueCaptureAddressAllocateInfoKHR>;
  using DeviceMemoryOpaqueCaptureAddressInfoKHR = DescriptionT<VkDeviceMemoryOpaqueCaptureAddressInfoKHR>;
  using PhysicalDeviceLineRasterizationFeaturesKHR = InfoT<VkPhysicalDeviceLineRasterizationFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR>;
  using PhysicalDeviceLineRasterizationFeaturesEXT = DescriptionT<VkPhysicalDeviceLineRasterizationFeaturesEXT>;
  using PhysicalDeviceLineRasterizationPropertiesKHR = InfoT<VkPhysicalDeviceLineRasterizationPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR>;
  using PhysicalDeviceLineRasterizationPropertiesEXT = DescriptionT<VkPhysicalDeviceLineRasterizationPropertiesEXT>;
  using PipelineRasterizationLineStateCreateInfoKHR = InfoT<VkPipelineRasterizationLineStateCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_KHR>;
  using PipelineRasterizationLineStateCreateInfoEXT = DescriptionT<VkPipelineRasterizationLineStateCreateInfoEXT>;
  using PhysicalDevicePipelineCreationCacheControlFeaturesEXT = DescriptionT<VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT>;
  using PipelineCompilerControlCreateInfoAMD = InfoT<VkPipelineCompilerControlCreateInfoAMD, VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD>;
  using PhysicalDeviceCoherentMemoryFeaturesAMD = InfoT<VkPhysicalDeviceCoherentMemoryFeaturesAMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD>;
  using PhysicalDeviceToolPropertiesEXT = DescriptionT<VkPhysicalDeviceToolPropertiesEXT>;
  using SamplerCustomBorderColorCreateInfoEXT = InfoT<VkSamplerCustomBorderColorCreateInfoEXT, VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT>;
  using PhysicalDeviceCustomBorderColorPropertiesEXT = InfoT<VkPhysicalDeviceCustomBorderColorPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT>;
  using PhysicalDeviceCustomBorderColorFeaturesEXT = InfoT<VkPhysicalDeviceCustomBorderColorFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT>;
  using SamplerBorderColorComponentMappingCreateInfoEXT = InfoT<VkSamplerBorderColorComponentMappingCreateInfoEXT, VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT>;
  using PhysicalDeviceBorderColorSwizzleFeaturesEXT = InfoT<VkPhysicalDeviceBorderColorSwizzleFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT>;
  using AccelerationStructureGeometryTrianglesDataKHR = InfoT<VkAccelerationStructureGeometryTrianglesDataKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR>;
  using AccelerationStructureGeometryAabbsDataKHR = InfoT<VkAccelerationStructureGeometryAabbsDataKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR>;
  using AccelerationStructureGeometryInstancesDataKHR = InfoT<VkAccelerationStructureGeometryInstancesDataKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR>;
  using AccelerationStructureGeometryKHR = InfoT<VkAccelerationStructureGeometryKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR>;
  using AccelerationStructureBuildGeometryInfoKHR = InfoT<VkAccelerationStructureBuildGeometryInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR>;
  using AccelerationStructureBuildRangeInfoKHR = DescriptionT<VkAccelerationStructureBuildRangeInfoKHR>;
  using AccelerationStructureCreateInfoKHR = InfoT<VkAccelerationStructureCreateInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR>;
  using AabbPositionsKHR = DescriptionT<VkAabbPositionsKHR>;
  using AabbPositionsNV = DescriptionT<VkAabbPositionsNV>;
  using TransformMatrixKHR = DescriptionT<VkTransformMatrixKHR>;
  using TransformMatrixNV = DescriptionT<VkTransformMatrixNV>;
  using AccelerationStructureInstanceKHR = DescriptionT<VkAccelerationStructureInstanceKHR>;
  using AccelerationStructureInstanceNV = DescriptionT<VkAccelerationStructureInstanceNV>;
  using AccelerationStructureDeviceAddressInfoKHR = InfoT<VkAccelerationStructureDeviceAddressInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR>;
  using AccelerationStructureVersionInfoKHR = InfoT<VkAccelerationStructureVersionInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR>;
  using CopyAccelerationStructureInfoKHR = InfoT<VkCopyAccelerationStructureInfoKHR, VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR>;
  using CopyAccelerationStructureToMemoryInfoKHR = InfoT<VkCopyAccelerationStructureToMemoryInfoKHR, VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR>;
  using CopyMemoryToAccelerationStructureInfoKHR = InfoT<VkCopyMemoryToAccelerationStructureInfoKHR, VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR>;
  using RayTracingPipelineInterfaceCreateInfoKHR = InfoT<VkRayTracingPipelineInterfaceCreateInfoKHR, VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR>;
  using PipelineLibraryCreateInfoKHR = InfoT<VkPipelineLibraryCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR>;
  using PhysicalDeviceExtendedDynamicStateFeaturesEXT = InfoT<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT>;
  using PhysicalDeviceExtendedDynamicState2FeaturesEXT = InfoT<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT>;
  using PhysicalDeviceExtendedDynamicState3FeaturesEXT = InfoT<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT>;
  using PhysicalDeviceExtendedDynamicState3PropertiesEXT = InfoT<VkPhysicalDeviceExtendedDynamicState3PropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT>;
  using ColorBlendEquationEXT = DescriptionT<VkColorBlendEquationEXT>;
  using ColorBlendAdvancedEXT = DescriptionT<VkColorBlendAdvancedEXT>;
  using RenderPassTransformBeginInfoQCOM = InfoT<VkRenderPassTransformBeginInfoQCOM, VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM>;
  using CopyCommandTransformInfoQCOM = InfoT<VkCopyCommandTransformInfoQCOM, VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM>;
  using CommandBufferInheritanceRenderPassTransformInfoQCOM = InfoT<VkCommandBufferInheritanceRenderPassTransformInfoQCOM, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM>;
  using PhysicalDeviceDiagnosticsConfigFeaturesNV = InfoT<VkPhysicalDeviceDiagnosticsConfigFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV>;
  using DeviceDiagnosticsConfigCreateInfoNV = InfoT<VkDeviceDiagnosticsConfigCreateInfoNV, VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV>;
  using PhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR = DescriptionT<VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR>;
  using PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR = InfoT<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR>;
  using PhysicalDeviceRobustness2FeaturesEXT = InfoT<VkPhysicalDeviceRobustness2FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT>;
  using PhysicalDeviceRobustness2PropertiesEXT = InfoT<VkPhysicalDeviceRobustness2PropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT>;
  using PhysicalDeviceImageRobustnessFeaturesEXT = DescriptionT<VkPhysicalDeviceImageRobustnessFeaturesEXT>;
  using PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR = InfoT<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR>;
  using PhysicalDevice4444FormatsFeaturesEXT = InfoT<VkPhysicalDevice4444FormatsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT>;
  using PhysicalDeviceSubpassShadingFeaturesHUAWEI = InfoT<VkPhysicalDeviceSubpassShadingFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI>;
  using PhysicalDeviceClusterCullingShaderFeaturesHUAWEI = InfoT<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI>;
  using PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI = InfoT<VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI>;
  using BufferCopy2KHR = DescriptionT<VkBufferCopy2KHR>;
  using ImageCopy2KHR = DescriptionT<VkImageCopy2KHR>;
  using ImageBlit2KHR = DescriptionT<VkImageBlit2KHR>;
  using BufferImageCopy2KHR = DescriptionT<VkBufferImageCopy2KHR>;
  using ImageResolve2KHR = DescriptionT<VkImageResolve2KHR>;
  using CopyBufferInfo2KHR = DescriptionT<VkCopyBufferInfo2KHR>;
  using CopyImageInfo2KHR = DescriptionT<VkCopyImageInfo2KHR>;
  using BlitImageInfo2KHR = DescriptionT<VkBlitImageInfo2KHR>;
  using CopyBufferToImageInfo2KHR = DescriptionT<VkCopyBufferToImageInfo2KHR>;
  using CopyImageToBufferInfo2KHR = DescriptionT<VkCopyImageToBufferInfo2KHR>;
  using ResolveImageInfo2KHR = DescriptionT<VkResolveImageInfo2KHR>;
  using PhysicalDeviceShaderImageAtomicInt64FeaturesEXT = InfoT<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT>;
  using FragmentShadingRateAttachmentInfoKHR = InfoT<VkFragmentShadingRateAttachmentInfoKHR, VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR>;
  using PipelineFragmentShadingRateStateCreateInfoKHR = InfoT<VkPipelineFragmentShadingRateStateCreateInfoKHR, VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR>;
  using PhysicalDeviceFragmentShadingRateFeaturesKHR = InfoT<VkPhysicalDeviceFragmentShadingRateFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR>;
  using PhysicalDeviceFragmentShadingRatePropertiesKHR = InfoT<VkPhysicalDeviceFragmentShadingRatePropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR>;
  using PhysicalDeviceFragmentShadingRateKHR = InfoT<VkPhysicalDeviceFragmentShadingRateKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR>;
  using PhysicalDeviceShaderTerminateInvocationFeaturesKHR = DescriptionT<VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR>;
  using PhysicalDeviceFragmentShadingRateEnumsFeaturesNV = InfoT<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV>;
  using PhysicalDeviceFragmentShadingRateEnumsPropertiesNV = InfoT<VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV>;
  using PipelineFragmentShadingRateEnumStateCreateInfoNV = InfoT<VkPipelineFragmentShadingRateEnumStateCreateInfoNV, VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV>;
  using AccelerationStructureBuildSizesInfoKHR = InfoT<VkAccelerationStructureBuildSizesInfoKHR, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR>;
  using PhysicalDeviceImage2DViewOf3DFeaturesEXT = InfoT<VkPhysicalDeviceImage2DViewOf3DFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT>;
  using PhysicalDeviceImageSlicedViewOf3DFeaturesEXT = InfoT<VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT>;
  using PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT = InfoT<VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT>;
  using PhysicalDeviceMutableDescriptorTypeFeaturesEXT = InfoT<VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT>;
  using PhysicalDeviceMutableDescriptorTypeFeaturesVALVE = DescriptionT<VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE>;
  using MutableDescriptorTypeListEXT = DescriptionT<VkMutableDescriptorTypeListEXT>;
  using MutableDescriptorTypeListVALVE = DescriptionT<VkMutableDescriptorTypeListVALVE>;
  using MutableDescriptorTypeCreateInfoEXT = InfoT<VkMutableDescriptorTypeCreateInfoEXT, VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT>;
  using MutableDescriptorTypeCreateInfoVALVE = DescriptionT<VkMutableDescriptorTypeCreateInfoVALVE>;
  using PhysicalDeviceDepthClipControlFeaturesEXT = InfoT<VkPhysicalDeviceDepthClipControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT>;
  using PipelineViewportDepthClipControlCreateInfoEXT = InfoT<VkPipelineViewportDepthClipControlCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT>;
  using PhysicalDeviceVertexInputDynamicStateFeaturesEXT = InfoT<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT>;
  using PhysicalDeviceExternalMemoryRDMAFeaturesNV = InfoT<VkPhysicalDeviceExternalMemoryRDMAFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV>;
  using VertexInputBindingDescription2EXT = InfoT<VkVertexInputBindingDescription2EXT, VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT>;
  using VertexInputAttributeDescription2EXT = InfoT<VkVertexInputAttributeDescription2EXT, VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT>;
  using PhysicalDeviceColorWriteEnableFeaturesEXT = InfoT<VkPhysicalDeviceColorWriteEnableFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT>;
  using PipelineColorWriteCreateInfoEXT = InfoT<VkPipelineColorWriteCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT>;
  using MemoryBarrier2KHR = DescriptionT<VkMemoryBarrier2KHR>;
  using ImageMemoryBarrier2KHR = DescriptionT<VkImageMemoryBarrier2KHR>;
  using BufferMemoryBarrier2KHR = DescriptionT<VkBufferMemoryBarrier2KHR>;
  using DependencyInfoKHR = DescriptionT<VkDependencyInfoKHR>;
  using SemaphoreSubmitInfoKHR = DescriptionT<VkSemaphoreSubmitInfoKHR>;
  using CommandBufferSubmitInfoKHR = DescriptionT<VkCommandBufferSubmitInfoKHR>;
  using SubmitInfo2KHR = DescriptionT<VkSubmitInfo2KHR>;
  using QueueFamilyCheckpointProperties2NV = InfoT<VkQueueFamilyCheckpointProperties2NV, VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV>;
  using CheckpointData2NV = InfoT<VkCheckpointData2NV, VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV>;
  using PhysicalDeviceSynchronization2FeaturesKHR = DescriptionT<VkPhysicalDeviceSynchronization2FeaturesKHR>;
  using PhysicalDeviceHostImageCopyFeaturesEXT = InfoT<VkPhysicalDeviceHostImageCopyFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT>;
  using PhysicalDeviceHostImageCopyPropertiesEXT = InfoT<VkPhysicalDeviceHostImageCopyPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT>;
  using MemoryToImageCopyEXT = InfoT<VkMemoryToImageCopyEXT, VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT>;
  using ImageToMemoryCopyEXT = InfoT<VkImageToMemoryCopyEXT, VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT>;
  using CopyMemoryToImageInfoEXT = InfoT<VkCopyMemoryToImageInfoEXT, VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT>;
  using CopyImageToMemoryInfoEXT = InfoT<VkCopyImageToMemoryInfoEXT, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT>;
  using CopyImageToImageInfoEXT = InfoT<VkCopyImageToImageInfoEXT, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT>;
  using HostImageLayoutTransitionInfoEXT = InfoT<VkHostImageLayoutTransitionInfoEXT, VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT>;
  using SubresourceHostMemcpySizeEXT = InfoT<VkSubresourceHostMemcpySizeEXT, VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT>;
  using HostImageCopyDevicePerformanceQueryEXT = InfoT<VkHostImageCopyDevicePerformanceQueryEXT, VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT>;
  using PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT = InfoT<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT>;
  using PhysicalDeviceLegacyDitheringFeaturesEXT = InfoT<VkPhysicalDeviceLegacyDitheringFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT>;
  using PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT = InfoT<VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT>;
  using SubpassResolvePerformanceQueryEXT = InfoT<VkSubpassResolvePerformanceQueryEXT, VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT>;
  using MultisampledRenderToSingleSampledInfoEXT = InfoT<VkMultisampledRenderToSingleSampledInfoEXT, VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT>;
  using PhysicalDevicePipelineProtectedAccessFeaturesEXT = InfoT<VkPhysicalDevicePipelineProtectedAccessFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT>;
  using QueueFamilyVideoPropertiesKHR = InfoT<VkQueueFamilyVideoPropertiesKHR, VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR>;
  using QueueFamilyQueryResultStatusPropertiesKHR = InfoT<VkQueueFamilyQueryResultStatusPropertiesKHR, VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR>;
  using VideoProfileListInfoKHR = InfoT<VkVideoProfileListInfoKHR, VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR>;
  using PhysicalDeviceVideoFormatInfoKHR = InfoT<VkPhysicalDeviceVideoFormatInfoKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR>;
  using VideoFormatPropertiesKHR = InfoT<VkVideoFormatPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR>;
  using VideoProfileInfoKHR = InfoT<VkVideoProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR>;
  using VideoCapabilitiesKHR = InfoT<VkVideoCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR>;
  using VideoSessionMemoryRequirementsKHR = InfoT<VkVideoSessionMemoryRequirementsKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR>;
  using BindVideoSessionMemoryInfoKHR = InfoT<VkBindVideoSessionMemoryInfoKHR, VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR>;
  using VideoPictureResourceInfoKHR = InfoT<VkVideoPictureResourceInfoKHR, VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR>;
  using VideoReferenceSlotInfoKHR = InfoT<VkVideoReferenceSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR>;
  using VideoDecodeCapabilitiesKHR = InfoT<VkVideoDecodeCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR>;
  using VideoDecodeUsageInfoKHR = InfoT<VkVideoDecodeUsageInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR>;
  using VideoDecodeInfoKHR = InfoT<VkVideoDecodeInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR>;
  using PhysicalDeviceVideoMaintenance1FeaturesKHR = InfoT<VkPhysicalDeviceVideoMaintenance1FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR>;
  using VideoInlineQueryInfoKHR = InfoT<VkVideoInlineQueryInfoKHR, VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR>;
  using VideoDecodeH264ProfileInfoKHR = InfoT<VkVideoDecodeH264ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR>;
  using VideoDecodeH264CapabilitiesKHR = InfoT<VkVideoDecodeH264CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR>;
  using VideoDecodeH264SessionParametersAddInfoKHR = InfoT<VkVideoDecodeH264SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR>;
  using VideoDecodeH264SessionParametersCreateInfoKHR = InfoT<VkVideoDecodeH264SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR>;
  using VideoDecodeH264PictureInfoKHR = InfoT<VkVideoDecodeH264PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR>;
  using VideoDecodeH264DpbSlotInfoKHR = InfoT<VkVideoDecodeH264DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR>;
  using VideoDecodeH265ProfileInfoKHR = InfoT<VkVideoDecodeH265ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR>;
  using VideoDecodeH265CapabilitiesKHR = InfoT<VkVideoDecodeH265CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR>;
  using VideoDecodeH265SessionParametersAddInfoKHR = InfoT<VkVideoDecodeH265SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR>;
  using VideoDecodeH265SessionParametersCreateInfoKHR = InfoT<VkVideoDecodeH265SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR>;
  using VideoDecodeH265PictureInfoKHR = InfoT<VkVideoDecodeH265PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR>;
  using VideoDecodeH265DpbSlotInfoKHR = InfoT<VkVideoDecodeH265DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR>;
  using VideoDecodeAV1ProfileInfoKHR = InfoT<VkVideoDecodeAV1ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR>;
  using VideoDecodeAV1CapabilitiesKHR = InfoT<VkVideoDecodeAV1CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR>;
  using VideoDecodeAV1SessionParametersCreateInfoKHR = InfoT<VkVideoDecodeAV1SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR>;
  using VideoDecodeAV1PictureInfoKHR = InfoT<VkVideoDecodeAV1PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR>;
  using VideoDecodeAV1DpbSlotInfoKHR = InfoT<VkVideoDecodeAV1DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR>;
  using VideoSessionCreateInfoKHR = InfoT<VkVideoSessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR>;
  using VideoSessionParametersCreateInfoKHR = InfoT<VkVideoSessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR>;
  using VideoSessionParametersUpdateInfoKHR = InfoT<VkVideoSessionParametersUpdateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR>;
  using VideoEncodeSessionParametersGetInfoKHR = InfoT<VkVideoEncodeSessionParametersGetInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR>;
  using VideoEncodeSessionParametersFeedbackInfoKHR = InfoT<VkVideoEncodeSessionParametersFeedbackInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR>;
  using VideoBeginCodingInfoKHR = InfoT<VkVideoBeginCodingInfoKHR, VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR>;
  using VideoEndCodingInfoKHR = InfoT<VkVideoEndCodingInfoKHR, VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR>;
  using VideoCodingControlInfoKHR = InfoT<VkVideoCodingControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR>;
  using VideoEncodeUsageInfoKHR = InfoT<VkVideoEncodeUsageInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR>;
  using VideoEncodeInfoKHR = InfoT<VkVideoEncodeInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR>;
  using QueryPoolVideoEncodeFeedbackCreateInfoKHR = InfoT<VkQueryPoolVideoEncodeFeedbackCreateInfoKHR, VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR>;
  using VideoEncodeQualityLevelInfoKHR = InfoT<VkVideoEncodeQualityLevelInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR>;
  using PhysicalDeviceVideoEncodeQualityLevelInfoKHR = InfoT<VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR>;
  using VideoEncodeQualityLevelPropertiesKHR = InfoT<VkVideoEncodeQualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR>;
  using VideoEncodeRateControlInfoKHR = InfoT<VkVideoEncodeRateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR>;
  using VideoEncodeRateControlLayerInfoKHR = InfoT<VkVideoEncodeRateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR>;
  using VideoEncodeCapabilitiesKHR = InfoT<VkVideoEncodeCapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR>;
  using VideoEncodeH264CapabilitiesKHR = InfoT<VkVideoEncodeH264CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR>;
  using VideoEncodeH264QualityLevelPropertiesKHR = InfoT<VkVideoEncodeH264QualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR>;
  using VideoEncodeH264SessionCreateInfoKHR = InfoT<VkVideoEncodeH264SessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR>;
  using VideoEncodeH264SessionParametersAddInfoKHR = InfoT<VkVideoEncodeH264SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR>;
  using VideoEncodeH264SessionParametersCreateInfoKHR = InfoT<VkVideoEncodeH264SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR>;
  using VideoEncodeH264SessionParametersGetInfoKHR = InfoT<VkVideoEncodeH264SessionParametersGetInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR>;
  using VideoEncodeH264SessionParametersFeedbackInfoKHR = InfoT<VkVideoEncodeH264SessionParametersFeedbackInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR>;
  using VideoEncodeH264DpbSlotInfoKHR = InfoT<VkVideoEncodeH264DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR>;
  using VideoEncodeH264PictureInfoKHR = InfoT<VkVideoEncodeH264PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR>;
  using VideoEncodeH264ProfileInfoKHR = InfoT<VkVideoEncodeH264ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR>;
  using VideoEncodeH264NaluSliceInfoKHR = InfoT<VkVideoEncodeH264NaluSliceInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR>;
  using VideoEncodeH264RateControlInfoKHR = InfoT<VkVideoEncodeH264RateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR>;
  using VideoEncodeH264QpKHR = DescriptionT<VkVideoEncodeH264QpKHR>;
  using VideoEncodeH264FrameSizeKHR = DescriptionT<VkVideoEncodeH264FrameSizeKHR>;
  using VideoEncodeH264GopRemainingFrameInfoKHR = InfoT<VkVideoEncodeH264GopRemainingFrameInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR>;
  using VideoEncodeH264RateControlLayerInfoKHR = InfoT<VkVideoEncodeH264RateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR>;
  using VideoEncodeH265CapabilitiesKHR = InfoT<VkVideoEncodeH265CapabilitiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR>;
  using VideoEncodeH265QualityLevelPropertiesKHR = InfoT<VkVideoEncodeH265QualityLevelPropertiesKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR>;
  using VideoEncodeH265SessionCreateInfoKHR = InfoT<VkVideoEncodeH265SessionCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR>;
  using VideoEncodeH265SessionParametersAddInfoKHR = InfoT<VkVideoEncodeH265SessionParametersAddInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR>;
  using VideoEncodeH265SessionParametersCreateInfoKHR = InfoT<VkVideoEncodeH265SessionParametersCreateInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR>;
  using VideoEncodeH265SessionParametersGetInfoKHR = InfoT<VkVideoEncodeH265SessionParametersGetInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR>;
  using VideoEncodeH265SessionParametersFeedbackInfoKHR = InfoT<VkVideoEncodeH265SessionParametersFeedbackInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR>;
  using VideoEncodeH265PictureInfoKHR = InfoT<VkVideoEncodeH265PictureInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR>;
  using VideoEncodeH265NaluSliceSegmentInfoKHR = InfoT<VkVideoEncodeH265NaluSliceSegmentInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR>;
  using VideoEncodeH265RateControlInfoKHR = InfoT<VkVideoEncodeH265RateControlInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR>;
  using VideoEncodeH265QpKHR = DescriptionT<VkVideoEncodeH265QpKHR>;
  using VideoEncodeH265FrameSizeKHR = DescriptionT<VkVideoEncodeH265FrameSizeKHR>;
  using VideoEncodeH265GopRemainingFrameInfoKHR = InfoT<VkVideoEncodeH265GopRemainingFrameInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR>;
  using VideoEncodeH265RateControlLayerInfoKHR = InfoT<VkVideoEncodeH265RateControlLayerInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR>;
  using VideoEncodeH265ProfileInfoKHR = InfoT<VkVideoEncodeH265ProfileInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR>;
  using VideoEncodeH265DpbSlotInfoKHR = InfoT<VkVideoEncodeH265DpbSlotInfoKHR, VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR>;
  using PhysicalDeviceInheritedViewportScissorFeaturesNV = InfoT<VkPhysicalDeviceInheritedViewportScissorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV>;
  using CommandBufferInheritanceViewportScissorInfoNV = InfoT<VkCommandBufferInheritanceViewportScissorInfoNV, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV>;
  using PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT = InfoT<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT>;
  using PhysicalDeviceProvokingVertexFeaturesEXT = InfoT<VkPhysicalDeviceProvokingVertexFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT>;
  using PhysicalDeviceProvokingVertexPropertiesEXT = InfoT<VkPhysicalDeviceProvokingVertexPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT>;
  using PipelineRasterizationProvokingVertexStateCreateInfoEXT = InfoT<VkPipelineRasterizationProvokingVertexStateCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT>;
  using CuModuleCreateInfoNVX = InfoT<VkCuModuleCreateInfoNVX, VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX>;
  using CuFunctionCreateInfoNVX = InfoT<VkCuFunctionCreateInfoNVX, VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX>;
  using CuLaunchInfoNVX = InfoT<VkCuLaunchInfoNVX, VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX>;
  using PhysicalDeviceDescriptorBufferFeaturesEXT = InfoT<VkPhysicalDeviceDescriptorBufferFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT>;
  using PhysicalDeviceDescriptorBufferPropertiesEXT = InfoT<VkPhysicalDeviceDescriptorBufferPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT>;
  using PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT = InfoT<VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT>;
  using DescriptorAddressInfoEXT = InfoT<VkDescriptorAddressInfoEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT>;
  using DescriptorBufferBindingInfoEXT = InfoT<VkDescriptorBufferBindingInfoEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT>;
  using DescriptorBufferBindingPushDescriptorBufferHandleEXT = InfoT<VkDescriptorBufferBindingPushDescriptorBufferHandleEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT>;
  using DescriptorGetInfoEXT = InfoT<VkDescriptorGetInfoEXT, VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT>;
  using BufferCaptureDescriptorDataInfoEXT = InfoT<VkBufferCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT>;
  using ImageCaptureDescriptorDataInfoEXT = InfoT<VkImageCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT>;
  using ImageViewCaptureDescriptorDataInfoEXT = InfoT<VkImageViewCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT>;
  using SamplerCaptureDescriptorDataInfoEXT = InfoT<VkSamplerCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT>;
  using AccelerationStructureCaptureDescriptorDataInfoEXT = InfoT<VkAccelerationStructureCaptureDescriptorDataInfoEXT, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT>;
  using OpaqueCaptureDescriptorDataCreateInfoEXT = InfoT<VkOpaqueCaptureDescriptorDataCreateInfoEXT, VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT>;
  using PhysicalDeviceShaderIntegerDotProductFeaturesKHR = DescriptionT<VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR>;
  using PhysicalDeviceShaderIntegerDotProductPropertiesKHR = DescriptionT<VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR>;
  using PhysicalDeviceDrmPropertiesEXT = InfoT<VkPhysicalDeviceDrmPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT>;
  using PhysicalDeviceFragmentShaderBarycentricFeaturesKHR = InfoT<VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR>;
  using PhysicalDeviceFragmentShaderBarycentricPropertiesKHR = InfoT<VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR>;
  using PhysicalDeviceRayTracingMotionBlurFeaturesNV = InfoT<VkPhysicalDeviceRayTracingMotionBlurFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV>;
  using PhysicalDeviceRayTracingValidationFeaturesNV = InfoT<VkPhysicalDeviceRayTracingValidationFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV>;
  using AccelerationStructureGeometryMotionTrianglesDataNV = InfoT<VkAccelerationStructureGeometryMotionTrianglesDataNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV>;
  using AccelerationStructureMotionInfoNV = InfoT<VkAccelerationStructureMotionInfoNV, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV>;
  using SRTDataNV = DescriptionT<VkSRTDataNV>;
  using AccelerationStructureSRTMotionInstanceNV = DescriptionT<VkAccelerationStructureSRTMotionInstanceNV>;
  using AccelerationStructureMatrixMotionInstanceNV = DescriptionT<VkAccelerationStructureMatrixMotionInstanceNV>;
  using AccelerationStructureMotionInstanceNV = DescriptionT<VkAccelerationStructureMotionInstanceNV>;
  using MemoryGetRemoteAddressInfoNV = InfoT<VkMemoryGetRemoteAddressInfoNV, VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV>;
  using CudaModuleCreateInfoNV = InfoT<VkCudaModuleCreateInfoNV, VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV>;
  using CudaFunctionCreateInfoNV = InfoT<VkCudaFunctionCreateInfoNV, VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV>;
  using CudaLaunchInfoNV = InfoT<VkCudaLaunchInfoNV, VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV>;
  using PhysicalDeviceRGBA10X6FormatsFeaturesEXT = InfoT<VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT>;
  using FormatProperties3KHR = DescriptionT<VkFormatProperties3KHR>;
  using DrmFormatModifierPropertiesList2EXT = InfoT<VkDrmFormatModifierPropertiesList2EXT, VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT>;
  using DrmFormatModifierProperties2EXT = DescriptionT<VkDrmFormatModifierProperties2EXT>;
  using PipelineRenderingCreateInfoKHR = DescriptionT<VkPipelineRenderingCreateInfoKHR>;
  using RenderingInfoKHR = DescriptionT<VkRenderingInfoKHR>;
  using RenderingAttachmentInfoKHR = DescriptionT<VkRenderingAttachmentInfoKHR>;
  using RenderingFragmentShadingRateAttachmentInfoKHR = InfoT<VkRenderingFragmentShadingRateAttachmentInfoKHR, VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR>;
  using RenderingFragmentDensityMapAttachmentInfoEXT = InfoT<VkRenderingFragmentDensityMapAttachmentInfoEXT, VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT>;
  using PhysicalDeviceDynamicRenderingFeaturesKHR = DescriptionT<VkPhysicalDeviceDynamicRenderingFeaturesKHR>;
  using CommandBufferInheritanceRenderingInfoKHR = DescriptionT<VkCommandBufferInheritanceRenderingInfoKHR>;
  using AttachmentSampleCountInfoAMD = InfoT<VkAttachmentSampleCountInfoAMD, VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD>;
  using AttachmentSampleCountInfoNV = DescriptionT<VkAttachmentSampleCountInfoNV>;
  using MultiviewPerViewAttributesInfoNVX = InfoT<VkMultiviewPerViewAttributesInfoNVX, VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX>;
  using PhysicalDeviceImageViewMinLodFeaturesEXT = InfoT<VkPhysicalDeviceImageViewMinLodFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT>;
  using ImageViewMinLodCreateInfoEXT = InfoT<VkImageViewMinLodCreateInfoEXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT>;
  using PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT = InfoT<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT>;
  using PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM = DescriptionT<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM>;
  using PhysicalDeviceLinearColorAttachmentFeaturesNV = InfoT<VkPhysicalDeviceLinearColorAttachmentFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV>;
  using PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT = InfoT<VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT>;
  using PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT = InfoT<VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT>;
  using GraphicsPipelineLibraryCreateInfoEXT = InfoT<VkGraphicsPipelineLibraryCreateInfoEXT, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT>;
  using PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE = InfoT<VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE>;
  using DescriptorSetBindingReferenceVALVE = InfoT<VkDescriptorSetBindingReferenceVALVE, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE>;
  using DescriptorSetLayoutHostMappingInfoVALVE = InfoT<VkDescriptorSetLayoutHostMappingInfoVALVE, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE>;
  using PhysicalDeviceNestedCommandBufferFeaturesEXT = InfoT<VkPhysicalDeviceNestedCommandBufferFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT>;
  using PhysicalDeviceNestedCommandBufferPropertiesEXT = InfoT<VkPhysicalDeviceNestedCommandBufferPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT>;
  using PhysicalDeviceShaderModuleIdentifierFeaturesEXT = InfoT<VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT>;
  using PhysicalDeviceShaderModuleIdentifierPropertiesEXT = InfoT<VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT>;
  using PipelineShaderStageModuleIdentifierCreateInfoEXT = InfoT<VkPipelineShaderStageModuleIdentifierCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT>;
  using ShaderModuleIdentifierEXT = InfoT<VkShaderModuleIdentifierEXT, VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT>;
  using ImageCompressionControlEXT = InfoT<VkImageCompressionControlEXT, VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT>;
  using PhysicalDeviceImageCompressionControlFeaturesEXT = InfoT<VkPhysicalDeviceImageCompressionControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT>;
  using ImageCompressionPropertiesEXT = InfoT<VkImageCompressionPropertiesEXT, VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT>;
  using PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT = InfoT<VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT>;
  using ImageSubresource2KHR = InfoT<VkImageSubresource2KHR, VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR>;
  using ImageSubresource2EXT = DescriptionT<VkImageSubresource2EXT>;
  using SubresourceLayout2KHR = InfoT<VkSubresourceLayout2KHR, VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR>;
  using SubresourceLayout2EXT = DescriptionT<VkSubresourceLayout2EXT>;
  using RenderPassCreationControlEXT = InfoT<VkRenderPassCreationControlEXT, VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT>;
  using RenderPassCreationFeedbackInfoEXT = DescriptionT<VkRenderPassCreationFeedbackInfoEXT>;
  using RenderPassCreationFeedbackCreateInfoEXT = InfoT<VkRenderPassCreationFeedbackCreateInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT>;
  using RenderPassSubpassFeedbackInfoEXT = DescriptionT<VkRenderPassSubpassFeedbackInfoEXT>;
  using RenderPassSubpassFeedbackCreateInfoEXT = InfoT<VkRenderPassSubpassFeedbackCreateInfoEXT, VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT>;
  using PhysicalDeviceSubpassMergeFeedbackFeaturesEXT = InfoT<VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT>;
  using MicromapBuildInfoEXT = InfoT<VkMicromapBuildInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT>;
  using MicromapCreateInfoEXT = InfoT<VkMicromapCreateInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT>;
  using MicromapVersionInfoEXT = InfoT<VkMicromapVersionInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT>;
  using CopyMicromapInfoEXT = InfoT<VkCopyMicromapInfoEXT, VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT>;
  using CopyMicromapToMemoryInfoEXT = InfoT<VkCopyMicromapToMemoryInfoEXT, VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT>;
  using CopyMemoryToMicromapInfoEXT = InfoT<VkCopyMemoryToMicromapInfoEXT, VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT>;
  using MicromapBuildSizesInfoEXT = InfoT<VkMicromapBuildSizesInfoEXT, VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT>;
  using MicromapUsageEXT = DescriptionT<VkMicromapUsageEXT>;
  using MicromapTriangleEXT = DescriptionT<VkMicromapTriangleEXT>;
  using PhysicalDeviceOpacityMicromapFeaturesEXT = InfoT<VkPhysicalDeviceOpacityMicromapFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT>;
  using PhysicalDeviceOpacityMicromapPropertiesEXT = InfoT<VkPhysicalDeviceOpacityMicromapPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT>;
  using AccelerationStructureTrianglesOpacityMicromapEXT = InfoT<VkAccelerationStructureTrianglesOpacityMicromapEXT, VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT>;
  using PipelinePropertiesIdentifierEXT = InfoT<VkPipelinePropertiesIdentifierEXT, VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT>;
  using PhysicalDevicePipelinePropertiesFeaturesEXT = InfoT<VkPhysicalDevicePipelinePropertiesFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT>;
  using PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD = InfoT<VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD>;
  using ExternalMemoryAcquireUnmodifiedEXT = InfoT<VkExternalMemoryAcquireUnmodifiedEXT, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT>;
  using PhysicalDeviceNonSeamlessCubeMapFeaturesEXT = InfoT<VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT>;
  using PhysicalDevicePipelineRobustnessFeaturesEXT = InfoT<VkPhysicalDevicePipelineRobustnessFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT>;
  using PipelineRobustnessCreateInfoEXT = InfoT<VkPipelineRobustnessCreateInfoEXT, VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT>;
  using PhysicalDevicePipelineRobustnessPropertiesEXT = InfoT<VkPhysicalDevicePipelineRobustnessPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT>;
  using ImageViewSampleWeightCreateInfoQCOM = InfoT<VkImageViewSampleWeightCreateInfoQCOM, VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM>;
  using PhysicalDeviceImageProcessingFeaturesQCOM = InfoT<VkPhysicalDeviceImageProcessingFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM>;
  using PhysicalDeviceImageProcessingPropertiesQCOM = InfoT<VkPhysicalDeviceImageProcessingPropertiesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM>;
  using PhysicalDeviceTilePropertiesFeaturesQCOM = InfoT<VkPhysicalDeviceTilePropertiesFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM>;
  using TilePropertiesQCOM = InfoT<VkTilePropertiesQCOM, VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM>;
  using PhysicalDeviceAmigoProfilingFeaturesSEC = InfoT<VkPhysicalDeviceAmigoProfilingFeaturesSEC, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC>;
  using AmigoProfilingSubmitInfoSEC = InfoT<VkAmigoProfilingSubmitInfoSEC, VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC>;
  using PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT = InfoT<VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT>;
  using PhysicalDeviceDepthClampZeroOneFeaturesEXT = InfoT<VkPhysicalDeviceDepthClampZeroOneFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT>;
  using PhysicalDeviceAddressBindingReportFeaturesEXT = InfoT<VkPhysicalDeviceAddressBindingReportFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT>;
  using DeviceAddressBindingCallbackDataEXT = InfoT<VkDeviceAddressBindingCallbackDataEXT, VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT>;
  using PhysicalDeviceOpticalFlowFeaturesNV = InfoT<VkPhysicalDeviceOpticalFlowFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV>;
  using PhysicalDeviceOpticalFlowPropertiesNV = InfoT<VkPhysicalDeviceOpticalFlowPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV>;
  using OpticalFlowImageFormatInfoNV = InfoT<VkOpticalFlowImageFormatInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV>;
  using OpticalFlowImageFormatPropertiesNV = InfoT<VkOpticalFlowImageFormatPropertiesNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV>;
  using OpticalFlowSessionCreateInfoNV = InfoT<VkOpticalFlowSessionCreateInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV>;
  using OpticalFlowSessionCreatePrivateDataInfoNV = InfoT<VkOpticalFlowSessionCreatePrivateDataInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV>;
  using OpticalFlowExecuteInfoNV = InfoT<VkOpticalFlowExecuteInfoNV, VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV>;
  using PhysicalDeviceFaultFeaturesEXT = InfoT<VkPhysicalDeviceFaultFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT>;
  using DeviceFaultAddressInfoEXT = DescriptionT<VkDeviceFaultAddressInfoEXT>;
  using DeviceFaultVendorInfoEXT = DescriptionT<VkDeviceFaultVendorInfoEXT>;
  using DeviceFaultCountsEXT = InfoT<VkDeviceFaultCountsEXT, VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT>;
  using DeviceFaultInfoEXT = InfoT<VkDeviceFaultInfoEXT, VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT>;
  using DeviceFaultVendorBinaryHeaderVersionOneEXT = DescriptionT<VkDeviceFaultVendorBinaryHeaderVersionOneEXT>;
  using PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT = InfoT<VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT>;
  using DepthBiasInfoEXT = InfoT<VkDepthBiasInfoEXT, VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT>;
  using DepthBiasRepresentationInfoEXT = InfoT<VkDepthBiasRepresentationInfoEXT, VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT>;
  using DecompressMemoryRegionNV = DescriptionT<VkDecompressMemoryRegionNV>;
  using PhysicalDeviceShaderCoreBuiltinsPropertiesARM = InfoT<VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM>;
  using PhysicalDeviceShaderCoreBuiltinsFeaturesARM = InfoT<VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM>;
  using FrameBoundaryEXT = InfoT<VkFrameBoundaryEXT, VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT>;
  using PhysicalDeviceFrameBoundaryFeaturesEXT = InfoT<VkPhysicalDeviceFrameBoundaryFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT>;
  using PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT = InfoT<VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT>;
  using SurfacePresentModeEXT = InfoT<VkSurfacePresentModeEXT, VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT>;
  using SurfacePresentScalingCapabilitiesEXT = InfoT<VkSurfacePresentScalingCapabilitiesEXT, VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT>;
  using SurfacePresentModeCompatibilityEXT = InfoT<VkSurfacePresentModeCompatibilityEXT, VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT>;
  using PhysicalDeviceSwapchainMaintenance1FeaturesEXT = InfoT<VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT>;
  using SwapchainPresentFenceInfoEXT = InfoT<VkSwapchainPresentFenceInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT>;
  using SwapchainPresentModesCreateInfoEXT = InfoT<VkSwapchainPresentModesCreateInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT>;
  using SwapchainPresentModeInfoEXT = InfoT<VkSwapchainPresentModeInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT>;
  using SwapchainPresentScalingCreateInfoEXT = InfoT<VkSwapchainPresentScalingCreateInfoEXT, VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT>;
  using ReleaseSwapchainImagesInfoEXT = InfoT<VkReleaseSwapchainImagesInfoEXT, VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT>;
  using PhysicalDeviceDepthBiasControlFeaturesEXT = InfoT<VkPhysicalDeviceDepthBiasControlFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT>;
  using PhysicalDeviceRayTracingInvocationReorderFeaturesNV = InfoT<VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV>;
  using PhysicalDeviceRayTracingInvocationReorderPropertiesNV = InfoT<VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV>;
  using PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV = InfoT<VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV>;
  using PhysicalDeviceExtendedSparseAddressSpacePropertiesNV = InfoT<VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV>;
  using DirectDriverLoadingInfoLUNARG = InfoT<VkDirectDriverLoadingInfoLUNARG, VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG>;
  using DirectDriverLoadingListLUNARG = InfoT<VkDirectDriverLoadingListLUNARG, VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG>;
  using PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM = InfoT<VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM>;
  using PhysicalDeviceRayTracingPositionFetchFeaturesKHR = InfoT<VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR>;
  using DeviceImageSubresourceInfoKHR = InfoT<VkDeviceImageSubresourceInfoKHR, VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR>;
  using PhysicalDeviceShaderCorePropertiesARM = InfoT<VkPhysicalDeviceShaderCorePropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM>;
  using PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM = InfoT<VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM>;
  using MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM = InfoT<VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM, VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM>;
  using QueryLowLatencySupportNV = InfoT<VkQueryLowLatencySupportNV, VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV>;
  using MemoryMapInfoKHR = InfoT<VkMemoryMapInfoKHR, VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR>;
  using MemoryUnmapInfoKHR = InfoT<VkMemoryUnmapInfoKHR, VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR>;
  using PhysicalDeviceShaderObjectFeaturesEXT = InfoT<VkPhysicalDeviceShaderObjectFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT>;
  using PhysicalDeviceShaderObjectPropertiesEXT = InfoT<VkPhysicalDeviceShaderObjectPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT>;
  using ShaderCreateInfoEXT = InfoT<VkShaderCreateInfoEXT, VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT>;
  using PhysicalDeviceShaderTileImageFeaturesEXT = InfoT<VkPhysicalDeviceShaderTileImageFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT>;
  using PhysicalDeviceShaderTileImagePropertiesEXT = InfoT<VkPhysicalDeviceShaderTileImagePropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT>;
  using PhysicalDeviceCooperativeMatrixFeaturesKHR = InfoT<VkPhysicalDeviceCooperativeMatrixFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR>;
  using CooperativeMatrixPropertiesKHR = InfoT<VkCooperativeMatrixPropertiesKHR, VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR>;
  using PhysicalDeviceCooperativeMatrixPropertiesKHR = InfoT<VkPhysicalDeviceCooperativeMatrixPropertiesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR>;
  using BindMemoryStatusKHR = InfoT<VkBindMemoryStatusKHR, VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR>;
  using BindDescriptorSetsInfoKHR = InfoT<VkBindDescriptorSetsInfoKHR, VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO_KHR>;
  using PushConstantsInfoKHR = InfoT<VkPushConstantsInfoKHR, VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO_KHR>;
  using PushDescriptorSetInfoKHR = InfoT<VkPushDescriptorSetInfoKHR, VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO_KHR>;
  using PushDescriptorSetWithTemplateInfoKHR = InfoT<VkPushDescriptorSetWithTemplateInfoKHR, VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR>;
  using SetDescriptorBufferOffsetsInfoEXT = InfoT<VkSetDescriptorBufferOffsetsInfoEXT, VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT>;
  using BindDescriptorBufferEmbeddedSamplersInfoEXT = InfoT<VkBindDescriptorBufferEmbeddedSamplersInfoEXT, VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT>;
  using PhysicalDeviceCubicClampFeaturesQCOM = InfoT<VkPhysicalDeviceCubicClampFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM>;
  using PhysicalDeviceYcbcrDegammaFeaturesQCOM = InfoT<VkPhysicalDeviceYcbcrDegammaFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM>;
  using SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM = InfoT<VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM>;
  using PhysicalDeviceCubicWeightsFeaturesQCOM = InfoT<VkPhysicalDeviceCubicWeightsFeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM>;
  using SamplerCubicWeightsCreateInfoQCOM = InfoT<VkSamplerCubicWeightsCreateInfoQCOM, VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM>;
  using BlitImageCubicWeightsInfoQCOM = InfoT<VkBlitImageCubicWeightsInfoQCOM, VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM>;
  using PhysicalDeviceImageProcessing2FeaturesQCOM = InfoT<VkPhysicalDeviceImageProcessing2FeaturesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM>;
  using PhysicalDeviceImageProcessing2PropertiesQCOM = InfoT<VkPhysicalDeviceImageProcessing2PropertiesQCOM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM>;
  using SamplerBlockMatchWindowCreateInfoQCOM = InfoT<VkSamplerBlockMatchWindowCreateInfoQCOM, VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM>;
  using PhysicalDeviceDescriptorPoolOverallocationFeaturesNV = InfoT<VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV>;
  using PhysicalDeviceLayeredDriverPropertiesMSFT = InfoT<VkPhysicalDeviceLayeredDriverPropertiesMSFT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT>;
  using PhysicalDevicePerStageDescriptorSetFeaturesNV = InfoT<VkPhysicalDevicePerStageDescriptorSetFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV>;
  using LatencySleepModeInfoNV = InfoT<VkLatencySleepModeInfoNV, VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV>;
  using LatencySleepInfoNV = InfoT<VkLatencySleepInfoNV, VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV>;
  using SetLatencyMarkerInfoNV = InfoT<VkSetLatencyMarkerInfoNV, VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV>;
  using GetLatencyMarkerInfoNV = InfoT<VkGetLatencyMarkerInfoNV, VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV>;
  using LatencyTimingsFrameReportNV = InfoT<VkLatencyTimingsFrameReportNV, VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV>;
  using OutOfBandQueueTypeInfoNV = InfoT<VkOutOfBandQueueTypeInfoNV, VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV>;
  using LatencySubmissionPresentIdNV = InfoT<VkLatencySubmissionPresentIdNV, VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV>;
  using SwapchainLatencyCreateInfoNV = InfoT<VkSwapchainLatencyCreateInfoNV, VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV>;
  using LatencySurfaceCapabilitiesNV = InfoT<VkLatencySurfaceCapabilitiesNV, VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV>;
  using PhysicalDeviceCudaKernelLaunchFeaturesNV = InfoT<VkPhysicalDeviceCudaKernelLaunchFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV>;
  using PhysicalDeviceCudaKernelLaunchPropertiesNV = InfoT<VkPhysicalDeviceCudaKernelLaunchPropertiesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV>;
  using DeviceQueueShaderCoreControlCreateInfoARM = InfoT<VkDeviceQueueShaderCoreControlCreateInfoARM, VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM>;
  using PhysicalDeviceSchedulingControlsFeaturesARM = InfoT<VkPhysicalDeviceSchedulingControlsFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM>;
  using PhysicalDeviceSchedulingControlsPropertiesARM = InfoT<VkPhysicalDeviceSchedulingControlsPropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM>;
  using PhysicalDeviceRelaxedLineRasterizationFeaturesIMG = InfoT<VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG>;
  using PhysicalDeviceRenderPassStripedFeaturesARM = InfoT<VkPhysicalDeviceRenderPassStripedFeaturesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM>;
  using PhysicalDeviceRenderPassStripedPropertiesARM = InfoT<VkPhysicalDeviceRenderPassStripedPropertiesARM, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM>;
  using RenderPassStripeInfoARM = InfoT<VkRenderPassStripeInfoARM, VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM>;
  using RenderPassStripeBeginInfoARM = InfoT<VkRenderPassStripeBeginInfoARM, VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM>;
  using RenderPassStripeSubmitInfoARM = InfoT<VkRenderPassStripeSubmitInfoARM, VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM>;
  using PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR = InfoT<VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR>;
  using PhysicalDeviceShaderSubgroupRotateFeaturesKHR = InfoT<VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR>;
  using PhysicalDeviceShaderExpectAssumeFeaturesKHR = InfoT<VkPhysicalDeviceShaderExpectAssumeFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR>;
  using PhysicalDeviceShaderFloatControls2FeaturesKHR = InfoT<VkPhysicalDeviceShaderFloatControls2FeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR>;
  using PhysicalDeviceDynamicRenderingLocalReadFeaturesKHR = InfoT<VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR>;
  using RenderingAttachmentLocationInfoKHR = InfoT<VkRenderingAttachmentLocationInfoKHR, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR>;
  using RenderingInputAttachmentIndexInfoKHR = InfoT<VkRenderingInputAttachmentIndexInfoKHR, VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR>;
  using PhysicalDeviceShaderQuadControlFeaturesKHR = InfoT<VkPhysicalDeviceShaderQuadControlFeaturesKHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR>;
  using PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV = InfoT<VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV>;
  using PhysicalDeviceMapMemoryPlacedFeaturesEXT = InfoT<VkPhysicalDeviceMapMemoryPlacedFeaturesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT>;
  using PhysicalDeviceMapMemoryPlacedPropertiesEXT = InfoT<VkPhysicalDeviceMapMemoryPlacedPropertiesEXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT>;
  using MemoryMapPlacedInfoEXT = InfoT<VkMemoryMapPlacedInfoEXT, VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT>;
  using PhysicalDeviceRawAccessChainsFeaturesNV = InfoT<VkPhysicalDeviceRawAccessChainsFeaturesNV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV>;
#if defined(VK_VERSION_1_0)
  using BaseOutStructure = DescriptionT<VkBaseOutStructure>;
  using BaseInStructure = DescriptionT<VkBaseInStructure>;
  using ClearRect = DescriptionT<VkClearRect>;
  using ComponentMapping = DescriptionT<VkComponentMapping>;
  using PhysicalDeviceProperties = DescriptionT<VkPhysicalDeviceProperties>;
  using ExtensionProperties = DescriptionT<VkExtensionProperties>;
  using LayerProperties = DescriptionT<VkLayerProperties>;
  using ApplicationInfo = InfoT<VkApplicationInfo, VK_STRUCTURE_TYPE_APPLICATION_INFO>;
  using AllocationCallbacks = DescriptionT<VkAllocationCallbacks>;
  using DeviceQueueCreateInfo = InfoT<VkDeviceQueueCreateInfo, VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO>;
  using DeviceCreateInfo = InfoT<VkDeviceCreateInfo, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO>;
  using InstanceCreateInfo = InfoT<VkInstanceCreateInfo, VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO>;
  using QueueFamilyProperties = DescriptionT<VkQueueFamilyProperties>;
  using PhysicalDeviceMemoryProperties = DescriptionT<VkPhysicalDeviceMemoryProperties>;
  using MemoryAllocateInfo = InfoT<VkMemoryAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO>;
  using MemoryRequirements = DescriptionT<VkMemoryRequirements>;
  using SparseImageFormatProperties = DescriptionT<VkSparseImageFormatProperties>;
  using SparseImageMemoryRequirements = DescriptionT<VkSparseImageMemoryRequirements>;
  using MemoryType = DescriptionT<VkMemoryType>;
  using MemoryHeap = DescriptionT<VkMemoryHeap>;
  using MappedMemoryRange = InfoT<VkMappedMemoryRange, VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE>;
  using FormatProperties = DescriptionT<VkFormatProperties>;
  using ImageFormatProperties = DescriptionT<VkImageFormatProperties>;
  using DescriptorBufferInfo = DescriptionT<VkDescriptorBufferInfo>;
  using DescriptorImageInfo = DescriptionT<VkDescriptorImageInfo>;
  using WriteDescriptorSet = InfoT<VkWriteDescriptorSet, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET>;
  using CopyDescriptorSet = InfoT<VkCopyDescriptorSet, VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET>;
  using BufferCreateInfo = InfoT<VkBufferCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO>;
  using BufferViewCreateInfo = InfoT<VkBufferViewCreateInfo, VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO>;
  using ImageSubresource = DescriptionT<VkImageSubresource>;
  using ImageSubresourceLayers = DescriptionT<VkImageSubresourceLayers>;
  using ImageSubresourceRange = DescriptionT<VkImageSubresourceRange>;
  using MemoryBarrier = InfoT<VkMemoryBarrier, VK_STRUCTURE_TYPE_MEMORY_BARRIER>;
  using BufferMemoryBarrier = InfoT<VkBufferMemoryBarrier, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER>;
  using ImageMemoryBarrier = InfoT<VkImageMemoryBarrier, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER>;
  using ImageCreateInfo = InfoT<VkImageCreateInfo, VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO>;
  using SubresourceLayout = DescriptionT<VkSubresourceLayout>;
  using ImageViewCreateInfo = InfoT<VkImageViewCreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO>;
  using BufferCopy = DescriptionT<VkBufferCopy>;
  using SparseMemoryBind = DescriptionT<VkSparseMemoryBind>;
  using SparseImageMemoryBind = DescriptionT<VkSparseImageMemoryBind>;
  using SparseBufferMemoryBindInfo = DescriptionT<VkSparseBufferMemoryBindInfo>;
  using SparseImageOpaqueMemoryBindInfo = DescriptionT<VkSparseImageOpaqueMemoryBindInfo>;
  using SparseImageMemoryBindInfo = DescriptionT<VkSparseImageMemoryBindInfo>;
  using BindSparseInfo = InfoT<VkBindSparseInfo, VK_STRUCTURE_TYPE_BIND_SPARSE_INFO>;
  using ImageCopy = DescriptionT<VkImageCopy>;
  using ImageBlit = DescriptionT<VkImageBlit>;
  using BufferImageCopy = DescriptionT<VkBufferImageCopy>;
  using ImageResolve = DescriptionT<VkImageResolve>;
  using ShaderModuleCreateInfo = InfoT<VkShaderModuleCreateInfo, VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO>;
  using DescriptorSetLayoutBinding = DescriptionT<VkDescriptorSetLayoutBinding>;
  using DescriptorSetLayoutCreateInfo = InfoT<VkDescriptorSetLayoutCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO>;
  using DescriptorPoolSize = DescriptionT<VkDescriptorPoolSize>;
  using DescriptorPoolCreateInfo = InfoT<VkDescriptorPoolCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO>;
  using DescriptorSetAllocateInfo = InfoT<VkDescriptorSetAllocateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO>;
  using SpecializationMapEntry = DescriptionT<VkSpecializationMapEntry>;
  using SpecializationInfo = DescriptionT<VkSpecializationInfo>;
  using PipelineShaderStageCreateInfo = InfoT<VkPipelineShaderStageCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO>;
  using ComputePipelineCreateInfo = InfoT<VkComputePipelineCreateInfo, VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO>;
  using VertexInputBindingDescription = DescriptionT<VkVertexInputBindingDescription>;
  using VertexInputAttributeDescription = DescriptionT<VkVertexInputAttributeDescription>;
  using PipelineVertexInputStateCreateInfo = InfoT<VkPipelineVertexInputStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO>;
  using PipelineInputAssemblyStateCreateInfo = InfoT<VkPipelineInputAssemblyStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO>;
  using PipelineTessellationStateCreateInfo = InfoT<VkPipelineTessellationStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO>;
  using PipelineViewportStateCreateInfo = InfoT<VkPipelineViewportStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO>;
  using PipelineRasterizationStateCreateInfo = InfoT<VkPipelineRasterizationStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO>;
  using PipelineMultisampleStateCreateInfo = InfoT<VkPipelineMultisampleStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO>;
  using PipelineColorBlendAttachmentState = DescriptionT<VkPipelineColorBlendAttachmentState>;
  using PipelineColorBlendStateCreateInfo = InfoT<VkPipelineColorBlendStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO>;
  using PipelineDynamicStateCreateInfo = InfoT<VkPipelineDynamicStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO>;
  using StencilOpState = DescriptionT<VkStencilOpState>;
  using PipelineDepthStencilStateCreateInfo = InfoT<VkPipelineDepthStencilStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO>;
  using GraphicsPipelineCreateInfo = InfoT<VkGraphicsPipelineCreateInfo, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO>;
  using PipelineCacheCreateInfo = InfoT<VkPipelineCacheCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO>;
  using PipelineCacheHeaderVersionOne = DescriptionT<VkPipelineCacheHeaderVersionOne>;
  using PushConstantRange = DescriptionT<VkPushConstantRange>;
  using PipelineLayoutCreateInfo = InfoT<VkPipelineLayoutCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO>;
  using SamplerCreateInfo = InfoT<VkSamplerCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO>;
  using CommandPoolCreateInfo = InfoT<VkCommandPoolCreateInfo, VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO>;
  using CommandBufferAllocateInfo = InfoT<VkCommandBufferAllocateInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO>;
  using CommandBufferInheritanceInfo = InfoT<VkCommandBufferInheritanceInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO>;
  using CommandBufferBeginInfo = InfoT<VkCommandBufferBeginInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO>;
  using RenderPassBeginInfo = InfoT<VkRenderPassBeginInfo, VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO>;
  using ClearDepthStencilValue = DescriptionT<VkClearDepthStencilValue>;
  using ClearAttachment = DescriptionT<VkClearAttachment>;
  using AttachmentDescription = DescriptionT<VkAttachmentDescription>;
  using AttachmentReference = DescriptionT<VkAttachmentReference>;
  using SubpassDescription = DescriptionT<VkSubpassDescription>;
  using SubpassDependency = DescriptionT<VkSubpassDependency>;
  using RenderPassCreateInfo = InfoT<VkRenderPassCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO>;
  using EventCreateInfo = InfoT<VkEventCreateInfo, VK_STRUCTURE_TYPE_EVENT_CREATE_INFO>;
  using FenceCreateInfo = InfoT<VkFenceCreateInfo, VK_STRUCTURE_TYPE_FENCE_CREATE_INFO>;
  using PhysicalDeviceFeatures = DescriptionT<VkPhysicalDeviceFeatures>;
  using PhysicalDeviceSparseProperties = DescriptionT<VkPhysicalDeviceSparseProperties>;
  using PhysicalDeviceLimits = DescriptionT<VkPhysicalDeviceLimits>;
  using SemaphoreCreateInfo = InfoT<VkSemaphoreCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO>;
  using QueryPoolCreateInfo = InfoT<VkQueryPoolCreateInfo, VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO>;
  using FramebufferCreateInfo = InfoT<VkFramebufferCreateInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO>;
  using DrawIndirectCommand = DescriptionT<VkDrawIndirectCommand>;
  using DrawIndexedIndirectCommand = DescriptionT<VkDrawIndexedIndirectCommand>;
  using DispatchIndirectCommand = DescriptionT<VkDispatchIndirectCommand>;
  using SubmitInfo = InfoT<VkSubmitInfo, VK_STRUCTURE_TYPE_SUBMIT_INFO>;
#endif // VK_VERSION_1_0
#if defined(VK_VERSION_1_1)
  using PhysicalDeviceFeatures2 = InfoT<VkPhysicalDeviceFeatures2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2>;
  using PhysicalDeviceProperties2 = InfoT<VkPhysicalDeviceProperties2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2>;
  using FormatProperties2 = InfoT<VkFormatProperties2, VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2>;
  using ImageFormatProperties2 = InfoT<VkImageFormatProperties2, VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2>;
  using PhysicalDeviceImageFormatInfo2 = InfoT<VkPhysicalDeviceImageFormatInfo2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2>;
  using QueueFamilyProperties2 = InfoT<VkQueueFamilyProperties2, VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2>;
  using PhysicalDeviceMemoryProperties2 = InfoT<VkPhysicalDeviceMemoryProperties2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2>;
  using SparseImageFormatProperties2 = InfoT<VkSparseImageFormatProperties2, VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2>;
  using PhysicalDeviceSparseImageFormatInfo2 = InfoT<VkPhysicalDeviceSparseImageFormatInfo2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2>;
  using PhysicalDeviceVariablePointersFeatures = InfoT<VkPhysicalDeviceVariablePointersFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES>;
  using PhysicalDeviceVariablePointerFeatures = DescriptionT<VkPhysicalDeviceVariablePointerFeatures>;
  using ExternalMemoryProperties = DescriptionT<VkExternalMemoryProperties>;
  using PhysicalDeviceExternalImageFormatInfo = InfoT<VkPhysicalDeviceExternalImageFormatInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO>;
  using ExternalImageFormatProperties = InfoT<VkExternalImageFormatProperties, VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES>;
  using PhysicalDeviceExternalBufferInfo = InfoT<VkPhysicalDeviceExternalBufferInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO>;
  using ExternalBufferProperties = InfoT<VkExternalBufferProperties, VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES>;
  using PhysicalDeviceIDProperties = InfoT<VkPhysicalDeviceIDProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES>;
  using ExternalMemoryImageCreateInfo = InfoT<VkExternalMemoryImageCreateInfo, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO>;
  using ExternalMemoryBufferCreateInfo = InfoT<VkExternalMemoryBufferCreateInfo, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO>;
  using ExportMemoryAllocateInfo = InfoT<VkExportMemoryAllocateInfo, VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO>;
  using PhysicalDeviceExternalSemaphoreInfo = InfoT<VkPhysicalDeviceExternalSemaphoreInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO>;
  using ExternalSemaphoreProperties = InfoT<VkExternalSemaphoreProperties, VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES>;
  using ExportSemaphoreCreateInfo = InfoT<VkExportSemaphoreCreateInfo, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO>;
  using PhysicalDeviceExternalFenceInfo = InfoT<VkPhysicalDeviceExternalFenceInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO>;
  using ExternalFenceProperties = InfoT<VkExternalFenceProperties, VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES>;
  using ExportFenceCreateInfo = InfoT<VkExportFenceCreateInfo, VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO>;
  using PhysicalDeviceMultiviewFeatures = InfoT<VkPhysicalDeviceMultiviewFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES>;
  using PhysicalDeviceMultiviewProperties = InfoT<VkPhysicalDeviceMultiviewProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES>;
  using RenderPassMultiviewCreateInfo = InfoT<VkRenderPassMultiviewCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO>;
  using PhysicalDeviceGroupProperties = InfoT<VkPhysicalDeviceGroupProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES>;
  using MemoryAllocateFlagsInfo = InfoT<VkMemoryAllocateFlagsInfo, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO>;
  using BindBufferMemoryInfo = InfoT<VkBindBufferMemoryInfo, VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO>;
  using BindBufferMemoryDeviceGroupInfo = InfoT<VkBindBufferMemoryDeviceGroupInfo, VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO>;
  using BindImageMemoryInfo = InfoT<VkBindImageMemoryInfo, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO>;
  using BindImageMemoryDeviceGroupInfo = InfoT<VkBindImageMemoryDeviceGroupInfo, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO>;
  using DeviceGroupRenderPassBeginInfo = InfoT<VkDeviceGroupRenderPassBeginInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO>;
  using DeviceGroupCommandBufferBeginInfo = InfoT<VkDeviceGroupCommandBufferBeginInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO>;
  using DeviceGroupSubmitInfo = InfoT<VkDeviceGroupSubmitInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO>;
  using DeviceGroupBindSparseInfo = InfoT<VkDeviceGroupBindSparseInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO>;
  using DeviceGroupDeviceCreateInfo = InfoT<VkDeviceGroupDeviceCreateInfo, VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO>;
  using DescriptorUpdateTemplateEntry = DescriptionT<VkDescriptorUpdateTemplateEntry>;
  using DescriptorUpdateTemplateCreateInfo = InfoT<VkDescriptorUpdateTemplateCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO>;
  using InputAttachmentAspectReference = DescriptionT<VkInputAttachmentAspectReference>;
  using RenderPassInputAttachmentAspectCreateInfo = InfoT<VkRenderPassInputAttachmentAspectCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO>;
  using PhysicalDevice16BitStorageFeatures = InfoT<VkPhysicalDevice16BitStorageFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES>;
  using PhysicalDeviceSubgroupProperties = InfoT<VkPhysicalDeviceSubgroupProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES>;
  using BufferMemoryRequirementsInfo2 = InfoT<VkBufferMemoryRequirementsInfo2, VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2>;
  using ImageMemoryRequirementsInfo2 = InfoT<VkImageMemoryRequirementsInfo2, VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2>;
  using ImageSparseMemoryRequirementsInfo2 = InfoT<VkImageSparseMemoryRequirementsInfo2, VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2>;
  using MemoryRequirements2 = InfoT<VkMemoryRequirements2, VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2>;
  using SparseImageMemoryRequirements2 = InfoT<VkSparseImageMemoryRequirements2, VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2>;
  using PhysicalDevicePointClippingProperties = InfoT<VkPhysicalDevicePointClippingProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES>;
  using MemoryDedicatedRequirements = InfoT<VkMemoryDedicatedRequirements, VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS>;
  using MemoryDedicatedAllocateInfo = InfoT<VkMemoryDedicatedAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO>;
  using ImageViewUsageCreateInfo = InfoT<VkImageViewUsageCreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO>;
  using PipelineTessellationDomainOriginStateCreateInfo = InfoT<VkPipelineTessellationDomainOriginStateCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO>;
  using SamplerYcbcrConversionInfo = InfoT<VkSamplerYcbcrConversionInfo, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO>;
  using SamplerYcbcrConversionCreateInfo = InfoT<VkSamplerYcbcrConversionCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO>;
  using BindImagePlaneMemoryInfo = InfoT<VkBindImagePlaneMemoryInfo, VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO>;
  using ImagePlaneMemoryRequirementsInfo = InfoT<VkImagePlaneMemoryRequirementsInfo, VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO>;
  using PhysicalDeviceSamplerYcbcrConversionFeatures = InfoT<VkPhysicalDeviceSamplerYcbcrConversionFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES>;
  using SamplerYcbcrConversionImageFormatProperties = InfoT<VkSamplerYcbcrConversionImageFormatProperties, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES>;
  using ProtectedSubmitInfo = InfoT<VkProtectedSubmitInfo, VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO>;
  using PhysicalDeviceProtectedMemoryFeatures = InfoT<VkPhysicalDeviceProtectedMemoryFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES>;
  using PhysicalDeviceProtectedMemoryProperties = InfoT<VkPhysicalDeviceProtectedMemoryProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES>;
  using DeviceQueueInfo2 = InfoT<VkDeviceQueueInfo2, VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2>;
  using PhysicalDeviceMaintenance3Properties = InfoT<VkPhysicalDeviceMaintenance3Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES>;
  using DescriptorSetLayoutSupport = InfoT<VkDescriptorSetLayoutSupport, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT>;
  using PhysicalDeviceShaderDrawParametersFeatures = InfoT<VkPhysicalDeviceShaderDrawParametersFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES>;
  using PhysicalDeviceShaderDrawParameterFeatures = DescriptionT<VkPhysicalDeviceShaderDrawParameterFeatures>;
#endif // VK_VERSION_1_1
#if defined(VK_VERSION_1_2)
  using ConformanceVersion = DescriptionT<VkConformanceVersion>;
  using PhysicalDeviceDriverProperties = InfoT<VkPhysicalDeviceDriverProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES>;
  using PhysicalDeviceShaderSubgroupExtendedTypesFeatures = InfoT<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES>;
  using PhysicalDeviceSamplerFilterMinmaxProperties = InfoT<VkPhysicalDeviceSamplerFilterMinmaxProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES>;
  using SamplerReductionModeCreateInfo = InfoT<VkSamplerReductionModeCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO>;
  using ImageFormatListCreateInfo = InfoT<VkImageFormatListCreateInfo, VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO>;
  using PhysicalDeviceShaderFloat16Int8Features = InfoT<VkPhysicalDeviceShaderFloat16Int8Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES>;
  using PhysicalDeviceFloatControlsProperties = InfoT<VkPhysicalDeviceFloatControlsProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES>;
  using PhysicalDeviceHostQueryResetFeatures = InfoT<VkPhysicalDeviceHostQueryResetFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES>;
  using PhysicalDeviceDescriptorIndexingFeatures = InfoT<VkPhysicalDeviceDescriptorIndexingFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES>;
  using PhysicalDeviceDescriptorIndexingProperties = InfoT<VkPhysicalDeviceDescriptorIndexingProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES>;
  using DescriptorSetLayoutBindingFlagsCreateInfo = InfoT<VkDescriptorSetLayoutBindingFlagsCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO>;
  using DescriptorSetVariableDescriptorCountAllocateInfo = InfoT<VkDescriptorSetVariableDescriptorCountAllocateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO>;
  using DescriptorSetVariableDescriptorCountLayoutSupport = InfoT<VkDescriptorSetVariableDescriptorCountLayoutSupport, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT>;
  using AttachmentDescription2 = InfoT<VkAttachmentDescription2, VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2>;
  using AttachmentReference2 = InfoT<VkAttachmentReference2, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2>;
  using SubpassDescription2 = InfoT<VkSubpassDescription2, VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2>;
  using SubpassDependency2 = InfoT<VkSubpassDependency2, VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2>;
  using RenderPassCreateInfo2 = InfoT<VkRenderPassCreateInfo2, VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2>;
  using SubpassBeginInfo = InfoT<VkSubpassBeginInfo, VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO>;
  using SubpassEndInfo = InfoT<VkSubpassEndInfo, VK_STRUCTURE_TYPE_SUBPASS_END_INFO>;
  using PhysicalDeviceTimelineSemaphoreFeatures = InfoT<VkPhysicalDeviceTimelineSemaphoreFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES>;
  using PhysicalDeviceTimelineSemaphoreProperties = InfoT<VkPhysicalDeviceTimelineSemaphoreProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES>;
  using SemaphoreTypeCreateInfo = InfoT<VkSemaphoreTypeCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO>;
  using TimelineSemaphoreSubmitInfo = InfoT<VkTimelineSemaphoreSubmitInfo, VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO>;
  using SemaphoreWaitInfo = InfoT<VkSemaphoreWaitInfo, VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO>;
  using SemaphoreSignalInfo = InfoT<VkSemaphoreSignalInfo, VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO>;
  using PhysicalDevice8BitStorageFeatures = InfoT<VkPhysicalDevice8BitStorageFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES>;
  using PhysicalDeviceVulkanMemoryModelFeatures = InfoT<VkPhysicalDeviceVulkanMemoryModelFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES>;
  using PhysicalDeviceShaderAtomicInt64Features = InfoT<VkPhysicalDeviceShaderAtomicInt64Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES>;
  using PhysicalDeviceDepthStencilResolveProperties = InfoT<VkPhysicalDeviceDepthStencilResolveProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES>;
  using SubpassDescriptionDepthStencilResolve = InfoT<VkSubpassDescriptionDepthStencilResolve, VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE>;
  using ImageStencilUsageCreateInfo = InfoT<VkImageStencilUsageCreateInfo, VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO>;
  using PhysicalDeviceScalarBlockLayoutFeatures = InfoT<VkPhysicalDeviceScalarBlockLayoutFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES>;
  using PhysicalDeviceUniformBufferStandardLayoutFeatures = InfoT<VkPhysicalDeviceUniformBufferStandardLayoutFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES>;
  using PhysicalDeviceBufferDeviceAddressFeatures = InfoT<VkPhysicalDeviceBufferDeviceAddressFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES>;
  using BufferDeviceAddressInfo = InfoT<VkBufferDeviceAddressInfo, VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO>;
  using BufferOpaqueCaptureAddressCreateInfo = InfoT<VkBufferOpaqueCaptureAddressCreateInfo, VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO>;
  using PhysicalDeviceImagelessFramebufferFeatures = InfoT<VkPhysicalDeviceImagelessFramebufferFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES>;
  using FramebufferAttachmentsCreateInfo = InfoT<VkFramebufferAttachmentsCreateInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO>;
  using FramebufferAttachmentImageInfo = InfoT<VkFramebufferAttachmentImageInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO>;
  using RenderPassAttachmentBeginInfo = InfoT<VkRenderPassAttachmentBeginInfo, VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO>;
  using PhysicalDeviceSeparateDepthStencilLayoutsFeatures = InfoT<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES>;
  using AttachmentReferenceStencilLayout = InfoT<VkAttachmentReferenceStencilLayout, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT>;
  using AttachmentDescriptionStencilLayout = InfoT<VkAttachmentDescriptionStencilLayout, VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT>;
  using MemoryOpaqueCaptureAddressAllocateInfo = InfoT<VkMemoryOpaqueCaptureAddressAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO>;
  using DeviceMemoryOpaqueCaptureAddressInfo = InfoT<VkDeviceMemoryOpaqueCaptureAddressInfo, VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO>;
  using PhysicalDeviceVulkan11Features = InfoT<VkPhysicalDeviceVulkan11Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES>;
  using PhysicalDeviceVulkan11Properties = InfoT<VkPhysicalDeviceVulkan11Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES>;
  using PhysicalDeviceVulkan12Features = InfoT<VkPhysicalDeviceVulkan12Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES>;
  using PhysicalDeviceVulkan12Properties = InfoT<VkPhysicalDeviceVulkan12Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES>;
#endif // VK_VERSION_1_2
#if defined(VK_VERSION_1_3)
  using DevicePrivateDataCreateInfo = InfoT<VkDevicePrivateDataCreateInfo, VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO>;
  using PrivateDataSlotCreateInfo = InfoT<VkPrivateDataSlotCreateInfo, VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO>;
  using PhysicalDevicePrivateDataFeatures = InfoT<VkPhysicalDevicePrivateDataFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES>;
  using DeviceBufferMemoryRequirements = InfoT<VkDeviceBufferMemoryRequirements, VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS>;
  using DeviceImageMemoryRequirements = InfoT<VkDeviceImageMemoryRequirements, VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS>;
  using PhysicalDeviceInlineUniformBlockFeatures = InfoT<VkPhysicalDeviceInlineUniformBlockFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES>;
  using PhysicalDeviceInlineUniformBlockProperties = InfoT<VkPhysicalDeviceInlineUniformBlockProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES>;
  using WriteDescriptorSetInlineUniformBlock = InfoT<VkWriteDescriptorSetInlineUniformBlock, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK>;
  using DescriptorPoolInlineUniformBlockCreateInfo = InfoT<VkDescriptorPoolInlineUniformBlockCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO>;
  using PhysicalDeviceMaintenance4Features = InfoT<VkPhysicalDeviceMaintenance4Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES>;
  using PhysicalDeviceMaintenance4Properties = InfoT<VkPhysicalDeviceMaintenance4Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES>;
  using PhysicalDeviceTextureCompressionASTCHDRFeatures = InfoT<VkPhysicalDeviceTextureCompressionASTCHDRFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES>;
  using PipelineCreationFeedback = DescriptionT<VkPipelineCreationFeedback>;
  using PipelineCreationFeedbackCreateInfo = InfoT<VkPipelineCreationFeedbackCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO>;
  using PhysicalDeviceShaderDemoteToHelperInvocationFeatures = InfoT<VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES>;
  using PhysicalDeviceTexelBufferAlignmentProperties = InfoT<VkPhysicalDeviceTexelBufferAlignmentProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES>;
  using PhysicalDeviceSubgroupSizeControlFeatures = InfoT<VkPhysicalDeviceSubgroupSizeControlFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES>;
  using PhysicalDeviceSubgroupSizeControlProperties = InfoT<VkPhysicalDeviceSubgroupSizeControlProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES>;
  using PipelineShaderStageRequiredSubgroupSizeCreateInfo = InfoT<VkPipelineShaderStageRequiredSubgroupSizeCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO>;
  using PhysicalDevicePipelineCreationCacheControlFeatures = InfoT<VkPhysicalDevicePipelineCreationCacheControlFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES>;
  using PhysicalDeviceVulkan13Features = InfoT<VkPhysicalDeviceVulkan13Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES>;
  using PhysicalDeviceVulkan13Properties = InfoT<VkPhysicalDeviceVulkan13Properties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES>;
  using PhysicalDeviceToolProperties = InfoT<VkPhysicalDeviceToolProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES>;
  using PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures = InfoT<VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES>;
  using PhysicalDeviceImageRobustnessFeatures = InfoT<VkPhysicalDeviceImageRobustnessFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES>;
  using BufferCopy2 = InfoT<VkBufferCopy2, VK_STRUCTURE_TYPE_BUFFER_COPY_2>;
  using ImageCopy2 = InfoT<VkImageCopy2, VK_STRUCTURE_TYPE_IMAGE_COPY_2>;
  using ImageBlit2 = InfoT<VkImageBlit2, VK_STRUCTURE_TYPE_IMAGE_BLIT_2>;
  using BufferImageCopy2 = InfoT<VkBufferImageCopy2, VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2>;
  using ImageResolve2 = InfoT<VkImageResolve2, VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2>;
  using CopyBufferInfo2 = InfoT<VkCopyBufferInfo2, VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2>;
  using CopyImageInfo2 = InfoT<VkCopyImageInfo2, VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2>;
  using BlitImageInfo2 = InfoT<VkBlitImageInfo2, VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2>;
  using CopyBufferToImageInfo2 = InfoT<VkCopyBufferToImageInfo2, VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2>;
  using CopyImageToBufferInfo2 = InfoT<VkCopyImageToBufferInfo2, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2>;
  using ResolveImageInfo2 = InfoT<VkResolveImageInfo2, VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2>;
  using PhysicalDeviceShaderTerminateInvocationFeatures = InfoT<VkPhysicalDeviceShaderTerminateInvocationFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES>;
  using MemoryBarrier2 = InfoT<VkMemoryBarrier2, VK_STRUCTURE_TYPE_MEMORY_BARRIER_2>;
  using ImageMemoryBarrier2 = InfoT<VkImageMemoryBarrier2, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2>;
  using BufferMemoryBarrier2 = InfoT<VkBufferMemoryBarrier2, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2>;
  using DependencyInfo = InfoT<VkDependencyInfo, VK_STRUCTURE_TYPE_DEPENDENCY_INFO>;
  using SemaphoreSubmitInfo = InfoT<VkSemaphoreSubmitInfo, VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO>;
  using CommandBufferSubmitInfo = InfoT<VkCommandBufferSubmitInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO>;
  using SubmitInfo2 = InfoT<VkSubmitInfo2, VK_STRUCTURE_TYPE_SUBMIT_INFO_2>;
  using PhysicalDeviceSynchronization2Features = InfoT<VkPhysicalDeviceSynchronization2Features, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES>;
  using PhysicalDeviceShaderIntegerDotProductFeatures = InfoT<VkPhysicalDeviceShaderIntegerDotProductFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES>;
  using PhysicalDeviceShaderIntegerDotProductProperties = InfoT<VkPhysicalDeviceShaderIntegerDotProductProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES>;
  using FormatProperties3 = InfoT<VkFormatProperties3, VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3>;
  using PipelineRenderingCreateInfo = InfoT<VkPipelineRenderingCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO>;
  using RenderingInfo = InfoT<VkRenderingInfo, VK_STRUCTURE_TYPE_RENDERING_INFO>;
  using RenderingAttachmentInfo = InfoT<VkRenderingAttachmentInfo, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO>;
  using PhysicalDeviceDynamicRenderingFeatures = InfoT<VkPhysicalDeviceDynamicRenderingFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES>;
  using CommandBufferInheritanceRenderingInfo = InfoT<VkCommandBufferInheritanceRenderingInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO>;
#endif // VK_VERSION_1_3
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
  using AndroidSurfaceCreateInfoKHR = InfoT<VkAndroidSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR>;
  using ImportAndroidHardwareBufferInfoANDROID = InfoT<VkImportAndroidHardwareBufferInfoANDROID, VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID>;
  using AndroidHardwareBufferUsageANDROID = InfoT<VkAndroidHardwareBufferUsageANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID>;
  using AndroidHardwareBufferPropertiesANDROID = InfoT<VkAndroidHardwareBufferPropertiesANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID>;
  using MemoryGetAndroidHardwareBufferInfoANDROID = InfoT<VkMemoryGetAndroidHardwareBufferInfoANDROID, VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID>;
  using AndroidHardwareBufferFormatPropertiesANDROID = InfoT<VkAndroidHardwareBufferFormatPropertiesANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID>;
  using ExternalFormatANDROID = InfoT<VkExternalFormatANDROID, VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID>;
  using AndroidHardwareBufferFormatProperties2ANDROID = InfoT<VkAndroidHardwareBufferFormatProperties2ANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID>;
  using PhysicalDeviceExternalFormatResolveFeaturesANDROID = InfoT<VkPhysicalDeviceExternalFormatResolveFeaturesANDROID, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID>;
  using PhysicalDeviceExternalFormatResolvePropertiesANDROID = InfoT<VkPhysicalDeviceExternalFormatResolvePropertiesANDROID, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID>;
  using AndroidHardwareBufferFormatResolvePropertiesANDROID = InfoT<VkAndroidHardwareBufferFormatResolvePropertiesANDROID, VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID>;
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
  using DirectFBSurfaceCreateInfoEXT = InfoT<VkDirectFBSurfaceCreateInfoEXT, VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT>;
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_FUCHSIA)
  using ImagePipeSurfaceCreateInfoFUCHSIA = InfoT<VkImagePipeSurfaceCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA>;
  using ImportMemoryZirconHandleInfoFUCHSIA = InfoT<VkImportMemoryZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA>;
  using MemoryZirconHandlePropertiesFUCHSIA = InfoT<VkMemoryZirconHandlePropertiesFUCHSIA, VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA>;
  using MemoryGetZirconHandleInfoFUCHSIA = InfoT<VkMemoryGetZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA>;
  using ImportSemaphoreZirconHandleInfoFUCHSIA = InfoT<VkImportSemaphoreZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA>;
  using SemaphoreGetZirconHandleInfoFUCHSIA = InfoT<VkSemaphoreGetZirconHandleInfoFUCHSIA, VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA>;
  using ImportMemoryBufferCollectionFUCHSIA = InfoT<VkImportMemoryBufferCollectionFUCHSIA, VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA>;
  using BufferCollectionImageCreateInfoFUCHSIA = InfoT<VkBufferCollectionImageCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA>;
  using BufferCollectionBufferCreateInfoFUCHSIA = InfoT<VkBufferCollectionBufferCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA>;
  using BufferCollectionCreateInfoFUCHSIA = InfoT<VkBufferCollectionCreateInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA>;
  using BufferCollectionPropertiesFUCHSIA = InfoT<VkBufferCollectionPropertiesFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA>;
  using BufferConstraintsInfoFUCHSIA = InfoT<VkBufferConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA>;
  using SysmemColorSpaceFUCHSIA = InfoT<VkSysmemColorSpaceFUCHSIA, VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA>;
  using ImageFormatConstraintsInfoFUCHSIA = InfoT<VkImageFormatConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA>;
  using ImageConstraintsInfoFUCHSIA = InfoT<VkImageConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA>;
  using BufferCollectionConstraintsInfoFUCHSIA = InfoT<VkBufferCollectionConstraintsInfoFUCHSIA, VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA>;
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_GGP)
  using StreamDescriptorSurfaceCreateInfoGGP = InfoT<VkStreamDescriptorSurfaceCreateInfoGGP, VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP>;
  using PresentFrameTokenGGP = InfoT<VkPresentFrameTokenGGP, VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP>;
#endif // VK_USE_PLATFORM_GGP
#if defined(VK_USE_PLATFORM_IOS_MVK)
  using IOSSurfaceCreateInfoMVK = InfoT<VkIOSSurfaceCreateInfoMVK, VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK>;
#endif // VK_USE_PLATFORM_IOS_MVK
#if defined(VK_USE_PLATFORM_MACOS_MVK)
  using MacOSSurfaceCreateInfoMVK = InfoT<VkMacOSSurfaceCreateInfoMVK, VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK>;
#endif // VK_USE_PLATFORM_MACOS_MVK
#if defined(VK_USE_PLATFORM_METAL_EXT)
  using MetalSurfaceCreateInfoEXT = InfoT<VkMetalSurfaceCreateInfoEXT, VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT>;
  using ExportMetalObjectCreateInfoEXT = InfoT<VkExportMetalObjectCreateInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT>;
  using ExportMetalObjectsInfoEXT = InfoT<VkExportMetalObjectsInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT>;
  using ExportMetalDeviceInfoEXT = InfoT<VkExportMetalDeviceInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT>;
  using ExportMetalCommandQueueInfoEXT = InfoT<VkExportMetalCommandQueueInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT>;
  using ExportMetalBufferInfoEXT = InfoT<VkExportMetalBufferInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT>;
  using ImportMetalBufferInfoEXT = InfoT<VkImportMetalBufferInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT>;
  using ExportMetalTextureInfoEXT = InfoT<VkExportMetalTextureInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT>;
  using ImportMetalTextureInfoEXT = InfoT<VkImportMetalTextureInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT>;
  using ExportMetalIOSurfaceInfoEXT = InfoT<VkExportMetalIOSurfaceInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT>;
  using ImportMetalIOSurfaceInfoEXT = InfoT<VkImportMetalIOSurfaceInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT>;
  using ExportMetalSharedEventInfoEXT = InfoT<VkExportMetalSharedEventInfoEXT, VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT>;
  using ImportMetalSharedEventInfoEXT = InfoT<VkImportMetalSharedEventInfoEXT, VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT>;
#endif // VK_USE_PLATFORM_METAL_EXT
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
  using ScreenSurfaceCreateInfoQNX = InfoT<VkScreenSurfaceCreateInfoQNX, VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX>;
  using ImportScreenBufferInfoQNX = InfoT<VkImportScreenBufferInfoQNX, VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX>;
  using ScreenBufferPropertiesQNX = InfoT<VkScreenBufferPropertiesQNX, VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX>;
  using ScreenBufferFormatPropertiesQNX = InfoT<VkScreenBufferFormatPropertiesQNX, VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX>;
  using ExternalFormatQNX = InfoT<VkExternalFormatQNX, VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX>;
  using PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX = InfoT<VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX>;
#endif // VK_USE_PLATFORM_SCREEN_QNX
#if defined(VK_USE_PLATFORM_VI_NN)
  using ViSurfaceCreateInfoNN = InfoT<VkViSurfaceCreateInfoNN, VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN>;
#endif // VK_USE_PLATFORM_VI_NN
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
  using WaylandSurfaceCreateInfoKHR = InfoT<VkWaylandSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR>;
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
  using Win32SurfaceCreateInfoKHR = InfoT<VkWin32SurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR>;
  using ImportMemoryWin32HandleInfoNV = InfoT<VkImportMemoryWin32HandleInfoNV, VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV>;
  using ExportMemoryWin32HandleInfoNV = InfoT<VkExportMemoryWin32HandleInfoNV, VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV>;
  using Win32KeyedMutexAcquireReleaseInfoNV = InfoT<VkWin32KeyedMutexAcquireReleaseInfoNV, VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV>;
  using ImportMemoryWin32HandleInfoKHR = InfoT<VkImportMemoryWin32HandleInfoKHR, VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR>;
  using ExportMemoryWin32HandleInfoKHR = InfoT<VkExportMemoryWin32HandleInfoKHR, VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR>;
  using MemoryWin32HandlePropertiesKHR = InfoT<VkMemoryWin32HandlePropertiesKHR, VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR>;
  using MemoryGetWin32HandleInfoKHR = InfoT<VkMemoryGetWin32HandleInfoKHR, VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR>;
  using Win32KeyedMutexAcquireReleaseInfoKHR = InfoT<VkWin32KeyedMutexAcquireReleaseInfoKHR, VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR>;
  using ImportSemaphoreWin32HandleInfoKHR = InfoT<VkImportSemaphoreWin32HandleInfoKHR, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR>;
  using ExportSemaphoreWin32HandleInfoKHR = InfoT<VkExportSemaphoreWin32HandleInfoKHR, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR>;
  using D3D12FenceSubmitInfoKHR = InfoT<VkD3D12FenceSubmitInfoKHR, VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR>;
  using SemaphoreGetWin32HandleInfoKHR = InfoT<VkSemaphoreGetWin32HandleInfoKHR, VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR>;
  using ImportFenceWin32HandleInfoKHR = InfoT<VkImportFenceWin32HandleInfoKHR, VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR>;
  using ExportFenceWin32HandleInfoKHR = InfoT<VkExportFenceWin32HandleInfoKHR, VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR>;
  using FenceGetWin32HandleInfoKHR = InfoT<VkFenceGetWin32HandleInfoKHR, VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR>;
  using SurfaceFullScreenExclusiveInfoEXT = InfoT<VkSurfaceFullScreenExclusiveInfoEXT, VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT>;
  using SurfaceFullScreenExclusiveWin32InfoEXT = InfoT<VkSurfaceFullScreenExclusiveWin32InfoEXT, VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT>;
  using SurfaceCapabilitiesFullScreenExclusiveEXT = InfoT<VkSurfaceCapabilitiesFullScreenExclusiveEXT, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT>;
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
  using XcbSurfaceCreateInfoKHR = InfoT<VkXcbSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR>;
#endif // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_XLIB_KHR)
  using XlibSurfaceCreateInfoKHR = InfoT<VkXlibSurfaceCreateInfoKHR, VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR>;
#endif // VK_USE_PLATFORM_XLIB_KHR

  //
  // format metadata types and structs.
  //
  
  enum class ChannelName : uint8_t {
    Invalid = 0,
    R,
    G,
    B,
    A,
    D,
    S,
    E
  };

  enum class NumericFormat : uint8_t {
    Invalid = 0,
    SFIXED5,
    SFLOAT,
    UFLOAT,
    SINT,
    UINT,
    SNORM,
    UNORM,
    SSCALED,
    USCALED,
    SRGB
  };
  
  enum class CompressionScheme : uint8_t {
    Invalid = 0,
    ASTC,
    BC1,
    BC2,
    BC3,
    BC4,
    BC5,
    BC6H,
    BC7,
    EAC,
    ETC2,
    PVRTC1,
    PVRTC2
  };

  struct ChannelMetadata {
    static constexpr uint8_t kNoShift = 0xff;
    ChannelName name;
    NumericFormat numeric_format;
    uint8_t bit_count;
    uint8_t bit_shift;
    bool is_format_match(const ChannelMetadata& rhs, bool check_shift) const {
      return numeric_format == rhs.numeric_format && bit_count == rhs.bit_count && (!check_shift || bit_shift == rhs.bit_shift);
    }
    bool is_format_compatible(const ChannelMetadata& rhs, bool check_shift) const {
      const auto fmt = numeric_format == NumericFormat::USCALED ? NumericFormat::UINT : numeric_format;
      const auto rhs_fmt = rhs.numeric_format == NumericFormat::USCALED ? NumericFormat::UINT : rhs.numeric_format;
      return fmt == rhs_fmt && bit_count == rhs.bit_count && (!check_shift || bit_shift == rhs.bit_shift);
    }
    operator bool() const {
      return name != ChannelName::Invalid;
    }
    bool operator!() const {
      return name == ChannelName::Invalid;
    }    
  };
  
  struct UncompressedFormatMetadata {
    uint8_t size_bytes;
    uint8_t channel_count;
    ChannelMetadata channels[4];
    operator bool() const {
      return !!size_bytes;
    }
    bool operator!() const {
      return !size_bytes;
    }
    bool is_packed() const {
      return channels[0].bit_shift != ChannelMetadata::kNoShift;
    }
    bool is_rgb() const {
      return channels[0].name == ChannelName::R && channels[2].name == ChannelName::B && channel_count == 3;
    }
    bool is_ebgr() const {
      return channels[0].name == ChannelName::E && channels[1].name == ChannelName::B && channels[3].name == ChannelName::R;
    }    
    bool is_bgr() const {
      return channels[0].name == ChannelName::B && channels[2].name == ChannelName::R && channel_count == 3;
    }    
    bool is_rgba() const {
      return channels[0].name == ChannelName::R && channels[3].name == ChannelName::A;
    }
    bool is_abgr() const {
      return channels[0].name == ChannelName::A && channels[3].name == ChannelName::R;
    }
    bool is_bgra() const {
      return channels[0].name == ChannelName::B && channels[3].name == ChannelName::A;
    }        
    bool is_srgb() const {
      return channels[0].numeric_format == NumericFormat::SRGB;
    }
    bool has_channel(ChannelName ct) const {
      for (auto ci = 0; ci < channel_count; ++ci) {
        if (channels[ci].name == ct) {
          return true;
        }
      }
      return false;
    }
    bool has_depth() const {
      return has_channel(ChannelName::D);
    }
    bool has_stencil() const {
      return has_channel(ChannelName::S);
    }    
    bool is_depth_stencil() const {
      return has_depth() && has_stencil();
    }    
    bool has_numeric_format(NumericFormat nf) const {
      for (auto ci = 0; ci < channel_count; ++ci) {
        if (channels[ci].numeric_format == nf) {
          return true;
        }
      }
      return false;
    }
    bool is_homogenous() const {
      for (auto ci = 1; ci < channel_count; ++ci) {
        if (!channels[0].is_format_match(channels[ci], /*check_shift*/false)) {
          return false;
        }
      }
      return true;
    }
    bool is_compatible(const UncompressedFormatMetadata& rhs) const {
      for (uint32_t ci = 0, cc = channel_count > rhs.channel_count ? channel_count : rhs.channel_count; ci < cc; ++ci) {
        if (!channels[ci].is_format_compatible(rhs.channels[ci], /*check_shift*/true)) {
          return false;
        }
      }
      return true;
    }    
  };

  struct CompressedFormatMetadata {
    CompressionScheme compression;
    uint8_t block_width;
    uint8_t block_height;
    uint8_t block_size_bytes;
    // no need for separate channel metadata.
    // all block compressed formats are R, RG, RGB, or RGBA
    // with homogenous numeric formats and opaque bit distribution.
    // as this utility header is not for writing
    // compression/decompression libraries, this is sufficient.
    uint8_t channel_count;
    NumericFormat numeric_format;
    operator bool() const {
      return compression != CompressionScheme::Invalid;
    }
    bool operator!() const {
      return compression == CompressionScheme::Invalid;
    }    
    inline bool is_rgb() const {
      return channel_count == 3;
    }
    inline bool is_rgba() const {
      return channel_count == 4;
    }
    inline bool is_hdr() const {
      return numeric_format == NumericFormat::SFLOAT || numeric_format == NumericFormat::UFLOAT;
    }
  };

  struct VideoFormatMetadata {
    uint8_t block_width;
    uint8_t block_size_bytes;
    uint8_t channel_count;
    NumericFormat numeric_format;
    // implementation not complete. TBD at need.
    operator bool() const {
      return numeric_format != NumericFormat::Invalid;
    }
    bool operator!() const {
      return numeric_format == NumericFormat::Invalid;
    }
  };

  static constexpr VkFormat kLastBaseFormat = VK_FORMAT_ASTC_12x12_SRGB_BLOCK;

  //
  // function prototypes
  //

  VKU_PROTO const char* to_string(const VkRayTracingInvocationReorderModeNV v);
  VKU_PROTO const char* to_string(const VkDirectDriverLoadingModeLUNARG v);
  // VkBufferUsageFlagBits2KHR is type aliased. its to_string() must have a unique name.
  VKU_PROTO const char* buffer_usage_flag_bits2_khr_to_string(const VkBufferUsageFlagBits2KHR v);
  // VkPipelineCreateFlagBits2KHR is type aliased. its to_string() must have a unique name.
  VKU_PROTO const char* pipeline_create_flag_bits2_khr_to_string(const VkPipelineCreateFlagBits2KHR v);
  VKU_PROTO const char* to_string(const VkPresentModeKHR v);
  VKU_PROTO const char* to_string(const VkColorSpaceKHR v);
  VKU_PROTO const char* to_string(const VkDisplayPlaneAlphaFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkCompositeAlphaFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkSurfaceTransformFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkTimeDomainKHR v);
  VKU_PROTO const char* to_string(const VkDebugReportFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkDebugReportObjectTypeEXT v);
  VKU_PROTO const char* to_string(const VkDeviceMemoryReportEventTypeEXT v);
  VKU_PROTO const char* to_string(const VkRasterizationOrderAMD v);
  VKU_PROTO const char* to_string(const VkExternalMemoryHandleTypeFlagBitsNV v);
  VKU_PROTO const char* to_string(const VkExternalMemoryFeatureFlagBitsNV v);
  VKU_PROTO const char* to_string(const VkValidationCheckEXT v);
  VKU_PROTO const char* to_string(const VkValidationFeatureEnableEXT v);
  VKU_PROTO const char* to_string(const VkValidationFeatureDisableEXT v);
  VKU_PROTO const char* to_string(const VkLayerSettingTypeEXT v);
  VKU_PROTO const char* to_string(const VkIndirectCommandsLayoutUsageFlagBitsNV v);
  VKU_PROTO const char* to_string(const VkIndirectStateFlagBitsNV v);
  VKU_PROTO const char* to_string(const VkIndirectCommandsTokenTypeNV v);
  VKU_PROTO const char* to_string(const VkSurfaceCounterFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkDisplayPowerStateEXT v);
  VKU_PROTO const char* to_string(const VkDeviceEventTypeEXT v);
  VKU_PROTO const char* to_string(const VkDisplayEventTypeEXT v);
  VKU_PROTO const char* to_string(const VkDeviceGroupPresentModeFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkViewportCoordinateSwizzleNV v);
  VKU_PROTO const char* to_string(const VkDiscardRectangleModeEXT v);
  VKU_PROTO const char* to_string(const VkBlendOverlapEXT v);
  VKU_PROTO const char* to_string(const VkCoverageModulationModeNV v);
  VKU_PROTO const char* to_string(const VkCoverageReductionModeNV v);
  VKU_PROTO const char* to_string(const VkValidationCacheHeaderVersionEXT v);
  VKU_PROTO const char* to_string(const VkShaderInfoTypeAMD v);
  VKU_PROTO const char* to_string(const VkQueueGlobalPriorityKHR v);
  VKU_PROTO const char* to_string(const VkDebugUtilsMessageSeverityFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkDebugUtilsMessageTypeFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkConservativeRasterizationModeEXT v);
  VKU_PROTO const char* to_string(const VkConditionalRenderingFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkShadingRatePaletteEntryNV v);
  VKU_PROTO const char* to_string(const VkCoarseSampleOrderTypeNV v);
  VKU_PROTO const char* to_string(const VkGeometryInstanceFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkGeometryFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkBuildAccelerationStructureFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkAccelerationStructureCreateFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkCopyAccelerationStructureModeKHR v);
  VKU_PROTO const char* to_string(const VkBuildAccelerationStructureModeKHR v);
  VKU_PROTO const char* to_string(const VkAccelerationStructureTypeKHR v);
  VKU_PROTO const char* to_string(const VkGeometryTypeKHR v);
  VKU_PROTO const char* to_string(const VkAccelerationStructureMemoryRequirementsTypeNV v);
  VKU_PROTO const char* to_string(const VkAccelerationStructureBuildTypeKHR v);
  VKU_PROTO const char* to_string(const VkRayTracingShaderGroupTypeKHR v);
  VKU_PROTO const char* to_string(const VkAccelerationStructureCompatibilityKHR v);
  VKU_PROTO const char* to_string(const VkShaderGroupShaderKHR v);
  VKU_PROTO const char* to_string(const VkMemoryOverallocationBehaviorAMD v);
  VKU_PROTO const char* to_string(const VkDeviceDiagnosticsConfigFlagBitsNV v);
  VKU_PROTO const char* to_string(const VkPerformanceCounterScopeKHR v);
  // VkMemoryDecompressionMethodFlagBitsNV is type aliased. its to_string() must have a unique name.
  VKU_PROTO const char* memory_decompression_method_flag_bits_nv_to_string(const VkMemoryDecompressionMethodFlagBitsNV v);
  VKU_PROTO const char* to_string(const VkPerformanceCounterUnitKHR v);
  VKU_PROTO const char* to_string(const VkPerformanceCounterStorageKHR v);
  VKU_PROTO const char* to_string(const VkPerformanceCounterDescriptionFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkPerformanceConfigurationTypeINTEL v);
  VKU_PROTO const char* to_string(const VkQueryPoolSamplingModeINTEL v);
  VKU_PROTO const char* to_string(const VkPerformanceOverrideTypeINTEL v);
  VKU_PROTO const char* to_string(const VkPerformanceParameterTypeINTEL v);
  VKU_PROTO const char* to_string(const VkPerformanceValueTypeINTEL v);
  VKU_PROTO const char* to_string(const VkPipelineExecutableStatisticFormatKHR v);
  VKU_PROTO const char* to_string(const VkLineRasterizationModeKHR v);
  VKU_PROTO const char* to_string(const VkFragmentShadingRateCombinerOpKHR v);
  VKU_PROTO const char* to_string(const VkFragmentShadingRateNV v);
  VKU_PROTO const char* to_string(const VkFragmentShadingRateTypeNV v);
  VKU_PROTO const char* to_string(const VkSubpassMergeStatusEXT v);
  VKU_PROTO const char* to_string(const VkProvokingVertexModeEXT v);
  VKU_PROTO const char* to_string(const VkAccelerationStructureMotionInstanceTypeNV v);
  VKU_PROTO const char* to_string(const VkGraphicsPipelineLibraryFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkDeviceAddressBindingFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkDeviceAddressBindingTypeEXT v);
  VKU_PROTO const char* to_string(const VkFrameBoundaryFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkPresentScalingFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkPresentGravityFlagBitsEXT v);
  // VkPhysicalDeviceSchedulingControlsFlagBitsARM is type aliased. its to_string() must have a unique name.
  VKU_PROTO const char* physical_device_scheduling_controls_flag_bits_arm_to_string(const VkPhysicalDeviceSchedulingControlsFlagBitsARM v);
  VKU_PROTO const char* to_string(const VkVideoCodecOperationFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoChromaSubsamplingFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoComponentBitDepthFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoCapabilityFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoSessionCreateFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoDecodeH264PictureLayoutFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoCodingControlFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkQueryResultStatusKHR v);
  VKU_PROTO const char* to_string(const VkVideoDecodeUsageFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoDecodeCapabilityFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeUsageFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeContentFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeTuningModeKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeCapabilityFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeFeedbackFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeRateControlModeFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeH264CapabilityFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeH264StdFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeH264RateControlFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkHostImageCopyFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkVideoEncodeH265CapabilityFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeH265StdFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeH265RateControlFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeH265CtbSizeFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkVideoEncodeH265TransformBlockSizeFlagBitsKHR v);
  VKU_PROTO const char* to_string(const VkImageCompressionFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkImageCompressionFixedRateFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkPipelineRobustnessBufferBehaviorEXT v);
  VKU_PROTO const char* to_string(const VkPipelineRobustnessImageBehaviorEXT v);
  VKU_PROTO const char* to_string(const VkOpticalFlowGridSizeFlagBitsNV v);
  VKU_PROTO const char* to_string(const VkOpticalFlowUsageFlagBitsNV v);
  VKU_PROTO const char* to_string(const VkOpticalFlowPerformanceLevelNV v);
  VKU_PROTO const char* to_string(const VkOpticalFlowSessionBindingPointNV v);
  VKU_PROTO const char* to_string(const VkOpticalFlowSessionCreateFlagBitsNV v);
  VKU_PROTO const char* to_string(const VkOpticalFlowExecuteFlagBitsNV v);
  VKU_PROTO const char* to_string(const VkMicromapTypeEXT v);
  VKU_PROTO const char* to_string(const VkBuildMicromapFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkMicromapCreateFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkCopyMicromapModeEXT v);
  VKU_PROTO const char* to_string(const VkBuildMicromapModeEXT v);
  VKU_PROTO const char* to_string(const VkOpacityMicromapFormatEXT v);
  VKU_PROTO const char* to_string(const VkOpacityMicromapSpecialIndexEXT v);
  VKU_PROTO const char* to_string(const VkDepthBiasRepresentationEXT v);
  VKU_PROTO const char* to_string(const VkDeviceFaultAddressTypeEXT v);
  VKU_PROTO const char* to_string(const VkDeviceFaultVendorBinaryHeaderVersionEXT v);
  VKU_PROTO const char* to_string(const VkShaderCreateFlagBitsEXT v);
  VKU_PROTO const char* to_string(const VkShaderCodeTypeEXT v);
  VKU_PROTO const char* to_string(const VkScopeKHR v);
  VKU_PROTO const char* to_string(const VkComponentTypeKHR v);
  VKU_PROTO const char* to_string(const VkCubicFilterWeightsQCOM v);
  VKU_PROTO const char* to_string(const VkBlockMatchWindowCompareModeQCOM v);
  VKU_PROTO const char* to_string(const VkLayeredDriverUnderlyingApiMSFT v);
  VKU_PROTO const char* to_string(const VkLatencyMarkerNV v);
  VKU_PROTO const char* to_string(const VkOutOfBandQueueTypeNV v);
#if defined(VK_VERSION_1_0)
  VKU_PROTO const char* to_string(const VkImageLayout v);
  VKU_PROTO const char* to_string(const VkAttachmentLoadOp v);
  VKU_PROTO const char* to_string(const VkAttachmentStoreOp v);
  VKU_PROTO const char* to_string(const VkImageType v);
  VKU_PROTO const char* to_string(const VkImageTiling v);
  VKU_PROTO const char* to_string(const VkImageViewType v);
  VKU_PROTO const char* to_string(const VkCommandBufferLevel v);
  VKU_PROTO const char* to_string(const VkComponentSwizzle v);
  VKU_PROTO const char* to_string(const VkDescriptorType v);
  VKU_PROTO const char* to_string(const VkQueryType v);
  VKU_PROTO const char* to_string(const VkBorderColor v);
  VKU_PROTO const char* to_string(const VkPipelineBindPoint v);
  VKU_PROTO const char* to_string(const VkPipelineCacheHeaderVersion v);
  VKU_PROTO const char* to_string(const VkPrimitiveTopology v);
  VKU_PROTO const char* to_string(const VkSharingMode v);
  VKU_PROTO const char* to_string(const VkIndexType v);
  VKU_PROTO const char* to_string(const VkFilter v);
  VKU_PROTO const char* to_string(const VkSamplerMipmapMode v);
  VKU_PROTO const char* to_string(const VkSamplerAddressMode v);
  VKU_PROTO const char* to_string(const VkCompareOp v);
  VKU_PROTO const char* to_string(const VkPolygonMode v);
  VKU_PROTO const char* to_string(const VkFrontFace v);
  VKU_PROTO const char* to_string(const VkBlendFactor v);
  VKU_PROTO const char* to_string(const VkBlendOp v);
  VKU_PROTO const char* to_string(const VkStencilOp v);
  VKU_PROTO const char* to_string(const VkLogicOp v);
  VKU_PROTO const char* to_string(const VkInternalAllocationType v);
  VKU_PROTO const char* to_string(const VkSystemAllocationScope v);
  VKU_PROTO const char* to_string(const VkPhysicalDeviceType v);
  VKU_PROTO const char* to_string(const VkVertexInputRate v);
  VKU_PROTO const char* to_string(const VkFormat v);
  VKU_PROTO const char* to_string(const VkStructureType v);
  VKU_PROTO const char* to_string(const VkSubpassContents v);
  VKU_PROTO const char* to_string(const VkResult v);
  VKU_PROTO const char* to_string(const VkDynamicState v);
  VKU_PROTO const char* to_string(const VkObjectType v);
  VKU_PROTO const char* to_string(const VkQueueFlagBits v);
  VKU_PROTO const char* to_string(const VkCullModeFlagBits v);
  VKU_PROTO const char* to_string(const VkMemoryPropertyFlagBits v);
  VKU_PROTO const char* to_string(const VkMemoryHeapFlagBits v);
  VKU_PROTO const char* to_string(const VkAccessFlagBits v);
  VKU_PROTO const char* to_string(const VkBufferUsageFlagBits v);
  VKU_PROTO const char* to_string(const VkBufferCreateFlagBits v);
  VKU_PROTO const char* to_string(const VkShaderStageFlagBits v);
  VKU_PROTO const char* to_string(const VkImageUsageFlagBits v);
  VKU_PROTO const char* to_string(const VkImageCreateFlagBits v);
  VKU_PROTO const char* to_string(const VkPipelineCreateFlagBits v);
  VKU_PROTO const char* to_string(const VkColorComponentFlagBits v);
  VKU_PROTO const char* to_string(const VkFenceCreateFlagBits v);
  VKU_PROTO const char* to_string(const VkFormatFeatureFlagBits v);
  VKU_PROTO const char* to_string(const VkQueryControlFlagBits v);
  VKU_PROTO const char* to_string(const VkQueryResultFlagBits v);
  VKU_PROTO const char* to_string(const VkCommandBufferUsageFlagBits v);
  VKU_PROTO const char* to_string(const VkQueryPipelineStatisticFlagBits v);
  VKU_PROTO const char* to_string(const VkImageAspectFlagBits v);
  VKU_PROTO const char* to_string(const VkSparseImageFormatFlagBits v);
  VKU_PROTO const char* to_string(const VkSparseMemoryBindFlagBits v);
  VKU_PROTO const char* to_string(const VkPipelineStageFlagBits v);
  VKU_PROTO const char* to_string(const VkCommandPoolCreateFlagBits v);
  VKU_PROTO const char* to_string(const VkCommandPoolResetFlagBits v);
  VKU_PROTO const char* to_string(const VkCommandBufferResetFlagBits v);
  VKU_PROTO const char* to_string(const VkSampleCountFlagBits v);
  VKU_PROTO const char* to_string(const VkAttachmentDescriptionFlagBits v);
  VKU_PROTO const char* to_string(const VkStencilFaceFlagBits v);
  VKU_PROTO const char* to_string(const VkDescriptorPoolCreateFlagBits v);
  VKU_PROTO const char* to_string(const VkDependencyFlagBits v);
  VKU_PROTO const char* to_string(const VkVendorId v);
#endif // VK_VERSION_1_0
#if defined(VK_VERSION_1_1)
  VKU_PROTO const char* to_string(const VkDescriptorUpdateTemplateType v);
  VKU_PROTO const char* to_string(const VkSubgroupFeatureFlagBits v);
  VKU_PROTO const char* to_string(const VkExternalMemoryHandleTypeFlagBits v);
  VKU_PROTO const char* to_string(const VkExternalMemoryFeatureFlagBits v);
  VKU_PROTO const char* to_string(const VkExternalSemaphoreHandleTypeFlagBits v);
  VKU_PROTO const char* to_string(const VkExternalSemaphoreFeatureFlagBits v);
  VKU_PROTO const char* to_string(const VkSemaphoreImportFlagBits v);
  VKU_PROTO const char* to_string(const VkExternalFenceHandleTypeFlagBits v);
  VKU_PROTO const char* to_string(const VkExternalFenceFeatureFlagBits v);
  VKU_PROTO const char* to_string(const VkFenceImportFlagBits v);
  VKU_PROTO const char* to_string(const VkPeerMemoryFeatureFlagBits v);
  VKU_PROTO const char* to_string(const VkMemoryAllocateFlagBits v);
  VKU_PROTO const char* to_string(const VkPointClippingBehavior v);
  VKU_PROTO const char* to_string(const VkTessellationDomainOrigin v);
  VKU_PROTO const char* to_string(const VkSamplerYcbcrModelConversion v);
  VKU_PROTO const char* to_string(const VkSamplerYcbcrRange v);
  VKU_PROTO const char* to_string(const VkChromaLocation v);
#endif // VK_VERSION_1_1
#if defined(VK_VERSION_1_2)
  VKU_PROTO const char* to_string(const VkSemaphoreType v);
  VKU_PROTO const char* to_string(const VkSemaphoreWaitFlagBits v);
  VKU_PROTO const char* to_string(const VkSamplerReductionMode v);
  VKU_PROTO const char* to_string(const VkDescriptorBindingFlagBits v);
  VKU_PROTO const char* to_string(const VkDriverId v);
  VKU_PROTO const char* to_string(const VkResolveModeFlagBits v);
  VKU_PROTO const char* to_string(const VkShaderFloatControlsIndependence v);
#endif // VK_VERSION_1_2
#if defined(VK_VERSION_1_3)
  VKU_PROTO const char* to_string(const VkPipelineCreationFeedbackFlagBits v);
  VKU_PROTO const char* to_string(const VkToolPurposeFlagBits v);
  // VkAccessFlagBits2 is type aliased. its to_string() must have a unique name.
  VKU_PROTO const char* access_flag_bits2_to_string(const VkAccessFlagBits2 v);
  // VkPipelineStageFlagBits2 is type aliased. its to_string() must have a unique name.
  VKU_PROTO const char* pipeline_stage_flag_bits2_to_string(const VkPipelineStageFlagBits2 v);
  VKU_PROTO const char* to_string(const VkSubmitFlagBits v);
  // VkFormatFeatureFlagBits2 is type aliased. its to_string() must have a unique name.
  VKU_PROTO const char* format_feature_flag_bits2_to_string(const VkFormatFeatureFlagBits2 v);
  VKU_PROTO const char* to_string(const VkRenderingFlagBits v);
#endif // VK_VERSION_1_3
#if defined(VK_USE_PLATFORM_FUCHSIA)
  VKU_PROTO const char* to_string(const VkImageConstraintsInfoFlagBitsFUCHSIA v);
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
  VKU_PROTO const char* to_string(const VkExportMetalObjectTypeFlagBitsEXT v);
#endif // VK_USE_PLATFORM_METAL_EXT
#if defined(VK_USE_PLATFORM_WIN32_KHR)
  VKU_PROTO const char* to_string(const VkFullScreenExclusiveEXT v);
#endif // VK_USE_PLATFORM_WIN32_KHR

  // returns default initialized metadata for compressed or video formats
  VKU_PROTO UncompressedFormatMetadata get_uncompressed_format_metadata(VkFormat f);
  // returns default initialized metadata for uncompressed or video formats
  VKU_PROTO CompressedFormatMetadata get_compressed_format_metadata(VkFormat f);
  // returns default initialized metadata for non-video formats
  VKU_PROTO VideoFormatMetadata get_video_format_metadata(VkFormat f);


 //
  // function implementations
  //
  
#if defined(VKU_IMPLEMENT) || defined(VKU_INLINE_ALL)
  VKU_IMPL const char* to_string(const VkRayTracingInvocationReorderModeNV v) {
    switch(v) {
    case VK_RAY_TRACING_INVOCATION_REORDER_MODE_NONE_NV: return "VK_RAY_TRACING_INVOCATION_REORDER_MODE_NONE_NV";
    case VK_RAY_TRACING_INVOCATION_REORDER_MODE_REORDER_NV: return "VK_RAY_TRACING_INVOCATION_REORDER_MODE_REORDER_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDirectDriverLoadingModeLUNARG v) {
    switch(v) {
    case VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG: return "VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG";
    case VK_DIRECT_DRIVER_LOADING_MODE_INCLUSIVE_LUNARG: return "VK_DIRECT_DRIVER_LOADING_MODE_INCLUSIVE_LUNARG";
    default: break;
    }
    return nullptr;
  }
  // VkBufferUsageFlagBits2KHR is type aliased. its to_string() must have a unique name.
  VKU_IMPL const char* buffer_usage_flag_bits2_khr_to_string(const VkBufferUsageFlagBits2KHR v) {
    switch(v) {
    case VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT_KHR: return "VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT_KHR";
    case VK_BUFFER_USAGE_2_TRANSFER_DST_BIT_KHR: return "VK_BUFFER_USAGE_2_TRANSFER_DST_BIT_KHR";
    case VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT_KHR: return "VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT_KHR";
    case VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT_KHR: return "VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT_KHR";
    case VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT_KHR: return "VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT_KHR";
    case VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT_KHR: return "VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT_KHR";
    case VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT_KHR: return "VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT_KHR";
    case VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT_KHR: return "VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT_KHR";
    case VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT_KHR: return "VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT_KHR";
    case VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT: return "VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT";
    case VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR: return "VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR";
    case VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT: return "VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT";
    case VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT: return "VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT";
    case VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR: return "VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR";
    case VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR: return "VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR";
    case VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR: return "VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR";
    case VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR: return "VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR";
    case VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT_KHR: return "VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT_KHR";
    case VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR: return "VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR";
    case VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR: return "VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR";
    case VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT: return "VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT";
    case VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT: return "VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT";
    case VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT: return "VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT";
    case VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT: return "VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT";
    case VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT: return "VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  // VkPipelineCreateFlagBits2KHR is type aliased. its to_string() must have a unique name.
  VKU_IMPL const char* pipeline_create_flag_bits2_khr_to_string(const VkPipelineCreateFlagBits2KHR v) {
    switch(v) {
    case VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT_KHR: return "VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT_KHR";
    case VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT_KHR: return "VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT_KHR";
    case VK_PIPELINE_CREATE_2_DERIVATIVE_BIT_KHR: return "VK_PIPELINE_CREATE_2_DERIVATIVE_BIT_KHR";
    case VK_PIPELINE_CREATE_2_ENABLE_LEGACY_DITHERING_BIT_EXT: return "VK_PIPELINE_CREATE_2_ENABLE_LEGACY_DITHERING_BIT_EXT";
    case VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR: return "VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR";
    case VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT_KHR: return "VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT_KHR";
    case VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV: return "VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV";
    case VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR: return "VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR";
    case VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR: return "VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR";
    case VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_KHR: return "VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_KHR";
    case VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT_KHR: return "VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT_KHR";
    case VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT: return "VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT";
    case VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT: return "VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT";
    case VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR: return "VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR";
    case VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR: return "VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR";
    case VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR: return "VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR";
    case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR: return "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR";
    case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR: return "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR";
    case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR: return "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR";
    case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR: return "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR";
    case VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR: return "VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR";
    case VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV: return "VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV";
    case VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV: return "VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV";
    case VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR: return "VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT: return "VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT";
    case VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT: return "VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT";
    case VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT: return "VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
    case VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT: return "VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
    case VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT_EXT: return "VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT_EXT";
    case VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT_EXT: return "VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT_EXT";
    case VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV: return "VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV";
    case VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT: return "VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPresentModeKHR v) {
    switch(v) {
    case VK_PRESENT_MODE_IMMEDIATE_KHR: return "VK_PRESENT_MODE_IMMEDIATE_KHR";
    case VK_PRESENT_MODE_MAILBOX_KHR: return "VK_PRESENT_MODE_MAILBOX_KHR";
    case VK_PRESENT_MODE_FIFO_KHR: return "VK_PRESENT_MODE_FIFO_KHR";
    case VK_PRESENT_MODE_FIFO_RELAXED_KHR: return "VK_PRESENT_MODE_FIFO_RELAXED_KHR";
    case VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR: return "VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR";
    case VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR: return "VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkColorSpaceKHR v) {
    switch(v) {
    case VK_COLOR_SPACE_SRGB_NONLINEAR_KHR: return "VK_COLOR_SPACE_SRGB_NONLINEAR_KHR";
    case VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT: return "VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT";
    case VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT: return "VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT";
    case VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT: return "VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT";
    case VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT: return "VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT";
    case VK_COLOR_SPACE_BT709_LINEAR_EXT: return "VK_COLOR_SPACE_BT709_LINEAR_EXT";
    case VK_COLOR_SPACE_BT709_NONLINEAR_EXT: return "VK_COLOR_SPACE_BT709_NONLINEAR_EXT";
    case VK_COLOR_SPACE_BT2020_LINEAR_EXT: return "VK_COLOR_SPACE_BT2020_LINEAR_EXT";
    case VK_COLOR_SPACE_HDR10_ST2084_EXT: return "VK_COLOR_SPACE_HDR10_ST2084_EXT";
    case VK_COLOR_SPACE_DOLBYVISION_EXT: return "VK_COLOR_SPACE_DOLBYVISION_EXT";
    case VK_COLOR_SPACE_HDR10_HLG_EXT: return "VK_COLOR_SPACE_HDR10_HLG_EXT";
    case VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT: return "VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT";
    case VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT: return "VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT";
    case VK_COLOR_SPACE_PASS_THROUGH_EXT: return "VK_COLOR_SPACE_PASS_THROUGH_EXT";
    case VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT: return "VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT";
    case VK_COLOR_SPACE_DISPLAY_NATIVE_AMD: return "VK_COLOR_SPACE_DISPLAY_NATIVE_AMD";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDisplayPlaneAlphaFlagBitsKHR v) {
    switch(v) {
    case VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR: return "VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR";
    case VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR: return "VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR";
    case VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR: return "VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR";
    case VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR: return "VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCompositeAlphaFlagBitsKHR v) {
    switch(v) {
    case VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR: return "VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR";
    case VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR: return "VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR";
    case VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR: return "VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR";
    case VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR: return "VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSurfaceTransformFlagBitsKHR v) {
    switch(v) {
    case VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR: return "VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR";
    case VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR: return "VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR";
    case VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR: return "VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR";
    case VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR: return "VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR";
    case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR: return "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR";
    case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR: return "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR";
    case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR: return "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR";
    case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR: return "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR";
    case VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR: return "VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkTimeDomainKHR v) {
    switch(v) {
    case VK_TIME_DOMAIN_DEVICE_KHR: return "VK_TIME_DOMAIN_DEVICE_KHR";
    case VK_TIME_DOMAIN_CLOCK_MONOTONIC_KHR: return "VK_TIME_DOMAIN_CLOCK_MONOTONIC_KHR";
    case VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_KHR: return "VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_KHR";
    case VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_KHR: return "VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDebugReportFlagBitsEXT v) {
    switch(v) {
    case VK_DEBUG_REPORT_INFORMATION_BIT_EXT: return "VK_DEBUG_REPORT_INFORMATION_BIT_EXT";
    case VK_DEBUG_REPORT_WARNING_BIT_EXT: return "VK_DEBUG_REPORT_WARNING_BIT_EXT";
    case VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT: return "VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT";
    case VK_DEBUG_REPORT_ERROR_BIT_EXT: return "VK_DEBUG_REPORT_ERROR_BIT_EXT";
    case VK_DEBUG_REPORT_DEBUG_BIT_EXT: return "VK_DEBUG_REPORT_DEBUG_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDebugReportObjectTypeEXT v) {
    switch(v) {
    case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_CU_MODULE_NVX_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_CU_MODULE_NVX_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_CU_FUNCTION_NVX_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_CU_FUNCTION_NVX_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_MODULE_NV_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_MODULE_NV_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_FUNCTION_NV_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_FUNCTION_NV_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDeviceMemoryReportEventTypeEXT v) {
    switch(v) {
    case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT: return "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT";
    case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT: return "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT";
    case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT: return "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT";
    case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT: return "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT";
    case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT: return "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkRasterizationOrderAMD v) {
    switch(v) {
    case VK_RASTERIZATION_ORDER_STRICT_AMD: return "VK_RASTERIZATION_ORDER_STRICT_AMD";
    case VK_RASTERIZATION_ORDER_RELAXED_AMD: return "VK_RASTERIZATION_ORDER_RELAXED_AMD";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkExternalMemoryHandleTypeFlagBitsNV v) {
    switch(v) {
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkExternalMemoryFeatureFlagBitsNV v) {
    switch(v) {
    case VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV: return "VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV";
    case VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV: return "VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV";
    case VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV: return "VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkValidationCheckEXT v) {
    switch(v) {
    case VK_VALIDATION_CHECK_ALL_EXT: return "VK_VALIDATION_CHECK_ALL_EXT";
    case VK_VALIDATION_CHECK_SHADERS_EXT: return "VK_VALIDATION_CHECK_SHADERS_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkValidationFeatureEnableEXT v) {
    switch(v) {
    case VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT: return "VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT";
    case VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT: return "VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT";
    case VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT: return "VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT";
    case VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT: return "VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT";
    case VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT: return "VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkValidationFeatureDisableEXT v) {
    switch(v) {
    case VK_VALIDATION_FEATURE_DISABLE_ALL_EXT: return "VK_VALIDATION_FEATURE_DISABLE_ALL_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT: return "VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT: return "VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT: return "VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT: return "VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT: return "VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT: return "VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT: return "VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkLayerSettingTypeEXT v) {
    switch(v) {
    case VK_LAYER_SETTING_TYPE_BOOL32_EXT: return "VK_LAYER_SETTING_TYPE_BOOL32_EXT";
    case VK_LAYER_SETTING_TYPE_INT32_EXT: return "VK_LAYER_SETTING_TYPE_INT32_EXT";
    case VK_LAYER_SETTING_TYPE_INT64_EXT: return "VK_LAYER_SETTING_TYPE_INT64_EXT";
    case VK_LAYER_SETTING_TYPE_UINT32_EXT: return "VK_LAYER_SETTING_TYPE_UINT32_EXT";
    case VK_LAYER_SETTING_TYPE_UINT64_EXT: return "VK_LAYER_SETTING_TYPE_UINT64_EXT";
    case VK_LAYER_SETTING_TYPE_FLOAT32_EXT: return "VK_LAYER_SETTING_TYPE_FLOAT32_EXT";
    case VK_LAYER_SETTING_TYPE_FLOAT64_EXT: return "VK_LAYER_SETTING_TYPE_FLOAT64_EXT";
    case VK_LAYER_SETTING_TYPE_STRING_EXT: return "VK_LAYER_SETTING_TYPE_STRING_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkIndirectCommandsLayoutUsageFlagBitsNV v) {
    switch(v) {
    case VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV: return "VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV";
    case VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV: return "VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV";
    case VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV: return "VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkIndirectStateFlagBitsNV v) {
    switch(v) {
    case VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV: return "VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkIndirectCommandsTokenTypeNV v) {
    switch(v) {
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PIPELINE_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_PIPELINE_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSurfaceCounterFlagBitsEXT v) {
    switch(v) {
    case VK_SURFACE_COUNTER_VBLANK_BIT_EXT: return "VK_SURFACE_COUNTER_VBLANK_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDisplayPowerStateEXT v) {
    switch(v) {
    case VK_DISPLAY_POWER_STATE_OFF_EXT: return "VK_DISPLAY_POWER_STATE_OFF_EXT";
    case VK_DISPLAY_POWER_STATE_SUSPEND_EXT: return "VK_DISPLAY_POWER_STATE_SUSPEND_EXT";
    case VK_DISPLAY_POWER_STATE_ON_EXT: return "VK_DISPLAY_POWER_STATE_ON_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDeviceEventTypeEXT v) {
    switch(v) {
    case VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT: return "VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDisplayEventTypeEXT v) {
    switch(v) {
    case VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT: return "VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDeviceGroupPresentModeFlagBitsKHR v) {
    switch(v) {
    case VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR: return "VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR";
    case VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR: return "VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR";
    case VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR: return "VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR";
    case VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR: return "VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkViewportCoordinateSwizzleNV v) {
    switch(v) {
    case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDiscardRectangleModeEXT v) {
    switch(v) {
    case VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT: return "VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT";
    case VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT: return "VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBlendOverlapEXT v) {
    switch(v) {
    case VK_BLEND_OVERLAP_UNCORRELATED_EXT: return "VK_BLEND_OVERLAP_UNCORRELATED_EXT";
    case VK_BLEND_OVERLAP_DISJOINT_EXT: return "VK_BLEND_OVERLAP_DISJOINT_EXT";
    case VK_BLEND_OVERLAP_CONJOINT_EXT: return "VK_BLEND_OVERLAP_CONJOINT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCoverageModulationModeNV v) {
    switch(v) {
    case VK_COVERAGE_MODULATION_MODE_NONE_NV: return "VK_COVERAGE_MODULATION_MODE_NONE_NV";
    case VK_COVERAGE_MODULATION_MODE_RGB_NV: return "VK_COVERAGE_MODULATION_MODE_RGB_NV";
    case VK_COVERAGE_MODULATION_MODE_ALPHA_NV: return "VK_COVERAGE_MODULATION_MODE_ALPHA_NV";
    case VK_COVERAGE_MODULATION_MODE_RGBA_NV: return "VK_COVERAGE_MODULATION_MODE_RGBA_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCoverageReductionModeNV v) {
    switch(v) {
    case VK_COVERAGE_REDUCTION_MODE_MERGE_NV: return "VK_COVERAGE_REDUCTION_MODE_MERGE_NV";
    case VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV: return "VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkValidationCacheHeaderVersionEXT v) {
    switch(v) {
    case VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT: return "VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkShaderInfoTypeAMD v) {
    switch(v) {
    case VK_SHADER_INFO_TYPE_STATISTICS_AMD: return "VK_SHADER_INFO_TYPE_STATISTICS_AMD";
    case VK_SHADER_INFO_TYPE_BINARY_AMD: return "VK_SHADER_INFO_TYPE_BINARY_AMD";
    case VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD: return "VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkQueueGlobalPriorityKHR v) {
    switch(v) {
    case VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR: return "VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR";
    case VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR: return "VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR";
    case VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR: return "VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR";
    case VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR: return "VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDebugUtilsMessageSeverityFlagBitsEXT v) {
    switch(v) {
    case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT: return "VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT";
    case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT: return "VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT";
    case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT: return "VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT";
    case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT: return "VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDebugUtilsMessageTypeFlagBitsEXT v) {
    switch(v) {
    case VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT: return "VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT";
    case VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT: return "VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT";
    case VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT: return "VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT";
    case VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT: return "VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkConservativeRasterizationModeEXT v) {
    switch(v) {
    case VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT: return "VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT";
    case VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT: return "VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT";
    case VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT: return "VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkConditionalRenderingFlagBitsEXT v) {
    switch(v) {
    case VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT: return "VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkShadingRatePaletteEntryNV v) {
    switch(v) {
    case VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCoarseSampleOrderTypeNV v) {
    switch(v) {
    case VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV: return "VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV";
    case VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV: return "VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV";
    case VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV: return "VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV";
    case VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV: return "VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkGeometryInstanceFlagBitsKHR v) {
    switch(v) {
    case VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR: return "VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR";
    case VK_GEOMETRY_INSTANCE_TRIANGLE_FLIP_FACING_BIT_KHR: return "VK_GEOMETRY_INSTANCE_TRIANGLE_FLIP_FACING_BIT_KHR";
    case VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR: return "VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR";
    case VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR: return "VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR";
    case VK_GEOMETRY_INSTANCE_FORCE_OPACITY_MICROMAP_2_STATE_EXT: return "VK_GEOMETRY_INSTANCE_FORCE_OPACITY_MICROMAP_2_STATE_EXT";
    case VK_GEOMETRY_INSTANCE_DISABLE_OPACITY_MICROMAPS_EXT: return "VK_GEOMETRY_INSTANCE_DISABLE_OPACITY_MICROMAPS_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkGeometryFlagBitsKHR v) {
    switch(v) {
    case VK_GEOMETRY_OPAQUE_BIT_KHR: return "VK_GEOMETRY_OPAQUE_BIT_KHR";
    case VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR: return "VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBuildAccelerationStructureFlagBitsKHR v) {
    switch(v) {
    case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR: return "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR";
    case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR: return "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR";
    case VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR: return "VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR";
    case VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR: return "VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR";
    case VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR: return "VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR";
    case VK_BUILD_ACCELERATION_STRUCTURE_MOTION_BIT_NV: return "VK_BUILD_ACCELERATION_STRUCTURE_MOTION_BIT_NV";
    case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_UPDATE_EXT: return "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_UPDATE_EXT";
    case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISABLE_OPACITY_MICROMAPS_EXT: return "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISABLE_OPACITY_MICROMAPS_EXT";
    case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_DATA_UPDATE_EXT: return "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_DATA_UPDATE_EXT";
    case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DATA_ACCESS_KHR: return "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DATA_ACCESS_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkAccelerationStructureCreateFlagBitsKHR v) {
    switch(v) {
    case VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR: return "VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR";
    case VK_ACCELERATION_STRUCTURE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT: return "VK_ACCELERATION_STRUCTURE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT";
    case VK_ACCELERATION_STRUCTURE_CREATE_MOTION_BIT_NV: return "VK_ACCELERATION_STRUCTURE_CREATE_MOTION_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCopyAccelerationStructureModeKHR v) {
    switch(v) {
    case VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR: return "VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR";
    case VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR: return "VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR";
    case VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR: return "VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR";
    case VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR: return "VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBuildAccelerationStructureModeKHR v) {
    switch(v) {
    case VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR: return "VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR";
    case VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR: return "VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkAccelerationStructureTypeKHR v) {
    switch(v) {
    case VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR: return "VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR";
    case VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR: return "VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR";
    case VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR: return "VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkGeometryTypeKHR v) {
    switch(v) {
    case VK_GEOMETRY_TYPE_TRIANGLES_KHR: return "VK_GEOMETRY_TYPE_TRIANGLES_KHR";
    case VK_GEOMETRY_TYPE_AABBS_KHR: return "VK_GEOMETRY_TYPE_AABBS_KHR";
    case VK_GEOMETRY_TYPE_INSTANCES_KHR: return "VK_GEOMETRY_TYPE_INSTANCES_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkAccelerationStructureMemoryRequirementsTypeNV v) {
    switch(v) {
    case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV: return "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV";
    case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV: return "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV";
    case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV: return "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkAccelerationStructureBuildTypeKHR v) {
    switch(v) {
    case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR: return "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR";
    case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR: return "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR";
    case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR: return "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkRayTracingShaderGroupTypeKHR v) {
    switch(v) {
    case VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR: return "VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR";
    case VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR: return "VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR";
    case VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR: return "VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkAccelerationStructureCompatibilityKHR v) {
    switch(v) {
    case VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR: return "VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR";
    case VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR: return "VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkShaderGroupShaderKHR v) {
    switch(v) {
    case VK_SHADER_GROUP_SHADER_GENERAL_KHR: return "VK_SHADER_GROUP_SHADER_GENERAL_KHR";
    case VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR: return "VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR";
    case VK_SHADER_GROUP_SHADER_ANY_HIT_KHR: return "VK_SHADER_GROUP_SHADER_ANY_HIT_KHR";
    case VK_SHADER_GROUP_SHADER_INTERSECTION_KHR: return "VK_SHADER_GROUP_SHADER_INTERSECTION_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkMemoryOverallocationBehaviorAMD v) {
    switch(v) {
    case VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD: return "VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD";
    case VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD: return "VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD";
    case VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD: return "VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDeviceDiagnosticsConfigFlagBitsNV v) {
    switch(v) {
    case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV: return "VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV";
    case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV: return "VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV";
    case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV: return "VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV";
    case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_ERROR_REPORTING_BIT_NV: return "VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_ERROR_REPORTING_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPerformanceCounterScopeKHR v) {
    switch(v) {
    case VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR: return "VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR";
    case VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR: return "VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR";
    case VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR: return "VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR";
    default: break;
    }
    return nullptr;
  }
  // VkMemoryDecompressionMethodFlagBitsNV is type aliased. its to_string() must have a unique name.
  VKU_IMPL const char* memory_decompression_method_flag_bits_nv_to_string(const VkMemoryDecompressionMethodFlagBitsNV v) {
    switch(v) {
    case VK_MEMORY_DECOMPRESSION_METHOD_GDEFLATE_1_0_BIT_NV: return "VK_MEMORY_DECOMPRESSION_METHOD_GDEFLATE_1_0_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPerformanceCounterUnitKHR v) {
    switch(v) {
    case VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPerformanceCounterStorageKHR v) {
    switch(v) {
    case VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR";
    case VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR";
    case VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR";
    case VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR";
    case VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR";
    case VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPerformanceCounterDescriptionFlagBitsKHR v) {
    switch(v) {
    case VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR: return "VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR";
    case VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR: return "VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPerformanceConfigurationTypeINTEL v) {
    switch(v) {
    case VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL: return "VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkQueryPoolSamplingModeINTEL v) {
    switch(v) {
    case VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL: return "VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPerformanceOverrideTypeINTEL v) {
    switch(v) {
    case VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL: return "VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL";
    case VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL: return "VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPerformanceParameterTypeINTEL v) {
    switch(v) {
    case VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL: return "VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL";
    case VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL: return "VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPerformanceValueTypeINTEL v) {
    switch(v) {
    case VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL: return "VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL";
    case VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL: return "VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL";
    case VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL: return "VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL";
    case VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL: return "VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL";
    case VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL: return "VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPipelineExecutableStatisticFormatKHR v) {
    switch(v) {
    case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR: return "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR";
    case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR: return "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR";
    case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR: return "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR";
    case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR: return "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkLineRasterizationModeKHR v) {
    switch(v) {
    case VK_LINE_RASTERIZATION_MODE_DEFAULT_KHR: return "VK_LINE_RASTERIZATION_MODE_DEFAULT_KHR";
    case VK_LINE_RASTERIZATION_MODE_RECTANGULAR_KHR: return "VK_LINE_RASTERIZATION_MODE_RECTANGULAR_KHR";
    case VK_LINE_RASTERIZATION_MODE_BRESENHAM_KHR: return "VK_LINE_RASTERIZATION_MODE_BRESENHAM_KHR";
    case VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_KHR: return "VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkFragmentShadingRateCombinerOpKHR v) {
    switch(v) {
    case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR";
    case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR";
    case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR";
    case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR";
    case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkFragmentShadingRateNV v) {
    switch(v) {
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV: return "VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV";
    case VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV: return "VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV";
    case VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV: return "VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV";
    case VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV: return "VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV";
    case VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV: return "VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkFragmentShadingRateTypeNV v) {
    switch(v) {
    case VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV: return "VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV";
    case VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV: return "VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSubpassMergeStatusEXT v) {
    switch(v) {
    case VK_SUBPASS_MERGE_STATUS_MERGED_EXT: return "VK_SUBPASS_MERGE_STATUS_MERGED_EXT";
    case VK_SUBPASS_MERGE_STATUS_DISALLOWED_EXT: return "VK_SUBPASS_MERGE_STATUS_DISALLOWED_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SIDE_EFFECTS_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SIDE_EFFECTS_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SAMPLES_MISMATCH_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SAMPLES_MISMATCH_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_VIEWS_MISMATCH_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_VIEWS_MISMATCH_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_ALIASING_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_ALIASING_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPENDENCIES_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPENDENCIES_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_TOO_MANY_ATTACHMENTS_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_TOO_MANY_ATTACHMENTS_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INSUFFICIENT_STORAGE_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INSUFFICIENT_STORAGE_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPTH_STENCIL_COUNT_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPTH_STENCIL_COUNT_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_RESOLVE_ATTACHMENT_REUSE_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_RESOLVE_ATTACHMENT_REUSE_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SINGLE_SUBPASS_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SINGLE_SUBPASS_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_UNSPECIFIED_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_UNSPECIFIED_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkProvokingVertexModeEXT v) {
    switch(v) {
    case VK_PROVOKING_VERTEX_MODE_FIRST_VERTEX_EXT: return "VK_PROVOKING_VERTEX_MODE_FIRST_VERTEX_EXT";
    case VK_PROVOKING_VERTEX_MODE_LAST_VERTEX_EXT: return "VK_PROVOKING_VERTEX_MODE_LAST_VERTEX_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkAccelerationStructureMotionInstanceTypeNV v) {
    switch(v) {
    case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV: return "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV";
    case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV: return "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV";
    case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV: return "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkGraphicsPipelineLibraryFlagBitsEXT v) {
    switch(v) {
    case VK_GRAPHICS_PIPELINE_LIBRARY_VERTEX_INPUT_INTERFACE_BIT_EXT: return "VK_GRAPHICS_PIPELINE_LIBRARY_VERTEX_INPUT_INTERFACE_BIT_EXT";
    case VK_GRAPHICS_PIPELINE_LIBRARY_PRE_RASTERIZATION_SHADERS_BIT_EXT: return "VK_GRAPHICS_PIPELINE_LIBRARY_PRE_RASTERIZATION_SHADERS_BIT_EXT";
    case VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_SHADER_BIT_EXT: return "VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_SHADER_BIT_EXT";
    case VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_OUTPUT_INTERFACE_BIT_EXT: return "VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_OUTPUT_INTERFACE_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDeviceAddressBindingFlagBitsEXT v) {
    switch(v) {
    case VK_DEVICE_ADDRESS_BINDING_INTERNAL_OBJECT_BIT_EXT: return "VK_DEVICE_ADDRESS_BINDING_INTERNAL_OBJECT_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDeviceAddressBindingTypeEXT v) {
    switch(v) {
    case VK_DEVICE_ADDRESS_BINDING_TYPE_BIND_EXT: return "VK_DEVICE_ADDRESS_BINDING_TYPE_BIND_EXT";
    case VK_DEVICE_ADDRESS_BINDING_TYPE_UNBIND_EXT: return "VK_DEVICE_ADDRESS_BINDING_TYPE_UNBIND_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkFrameBoundaryFlagBitsEXT v) {
    switch(v) {
    case VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT: return "VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPresentScalingFlagBitsEXT v) {
    switch(v) {
    case VK_PRESENT_SCALING_ONE_TO_ONE_BIT_EXT: return "VK_PRESENT_SCALING_ONE_TO_ONE_BIT_EXT";
    case VK_PRESENT_SCALING_ASPECT_RATIO_STRETCH_BIT_EXT: return "VK_PRESENT_SCALING_ASPECT_RATIO_STRETCH_BIT_EXT";
    case VK_PRESENT_SCALING_STRETCH_BIT_EXT: return "VK_PRESENT_SCALING_STRETCH_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPresentGravityFlagBitsEXT v) {
    switch(v) {
    case VK_PRESENT_GRAVITY_MIN_BIT_EXT: return "VK_PRESENT_GRAVITY_MIN_BIT_EXT";
    case VK_PRESENT_GRAVITY_MAX_BIT_EXT: return "VK_PRESENT_GRAVITY_MAX_BIT_EXT";
    case VK_PRESENT_GRAVITY_CENTERED_BIT_EXT: return "VK_PRESENT_GRAVITY_CENTERED_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  // VkPhysicalDeviceSchedulingControlsFlagBitsARM is type aliased. its to_string() must have a unique name.
  VKU_IMPL const char* physical_device_scheduling_controls_flag_bits_arm_to_string(const VkPhysicalDeviceSchedulingControlsFlagBitsARM v) {
    switch(v) {
    case VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM: return "VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoCodecOperationFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_CODEC_OPERATION_NONE_KHR: return "VK_VIDEO_CODEC_OPERATION_NONE_KHR";
    case VK_VIDEO_CODEC_OPERATION_ENCODE_H264_BIT_KHR: return "VK_VIDEO_CODEC_OPERATION_ENCODE_H264_BIT_KHR";
    case VK_VIDEO_CODEC_OPERATION_ENCODE_H265_BIT_KHR: return "VK_VIDEO_CODEC_OPERATION_ENCODE_H265_BIT_KHR";
    case VK_VIDEO_CODEC_OPERATION_DECODE_H264_BIT_KHR: return "VK_VIDEO_CODEC_OPERATION_DECODE_H264_BIT_KHR";
    case VK_VIDEO_CODEC_OPERATION_DECODE_H265_BIT_KHR: return "VK_VIDEO_CODEC_OPERATION_DECODE_H265_BIT_KHR";
    case VK_VIDEO_CODEC_OPERATION_DECODE_AV1_BIT_KHR: return "VK_VIDEO_CODEC_OPERATION_DECODE_AV1_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoChromaSubsamplingFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_CHROMA_SUBSAMPLING_INVALID_KHR: return "VK_VIDEO_CHROMA_SUBSAMPLING_INVALID_KHR";
    case VK_VIDEO_CHROMA_SUBSAMPLING_MONOCHROME_BIT_KHR: return "VK_VIDEO_CHROMA_SUBSAMPLING_MONOCHROME_BIT_KHR";
    case VK_VIDEO_CHROMA_SUBSAMPLING_420_BIT_KHR: return "VK_VIDEO_CHROMA_SUBSAMPLING_420_BIT_KHR";
    case VK_VIDEO_CHROMA_SUBSAMPLING_422_BIT_KHR: return "VK_VIDEO_CHROMA_SUBSAMPLING_422_BIT_KHR";
    case VK_VIDEO_CHROMA_SUBSAMPLING_444_BIT_KHR: return "VK_VIDEO_CHROMA_SUBSAMPLING_444_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoComponentBitDepthFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_COMPONENT_BIT_DEPTH_INVALID_KHR: return "VK_VIDEO_COMPONENT_BIT_DEPTH_INVALID_KHR";
    case VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR: return "VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR";
    case VK_VIDEO_COMPONENT_BIT_DEPTH_10_BIT_KHR: return "VK_VIDEO_COMPONENT_BIT_DEPTH_10_BIT_KHR";
    case VK_VIDEO_COMPONENT_BIT_DEPTH_12_BIT_KHR: return "VK_VIDEO_COMPONENT_BIT_DEPTH_12_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoCapabilityFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_CAPABILITY_PROTECTED_CONTENT_BIT_KHR: return "VK_VIDEO_CAPABILITY_PROTECTED_CONTENT_BIT_KHR";
    case VK_VIDEO_CAPABILITY_SEPARATE_REFERENCE_IMAGES_BIT_KHR: return "VK_VIDEO_CAPABILITY_SEPARATE_REFERENCE_IMAGES_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoSessionCreateFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_SESSION_CREATE_PROTECTED_CONTENT_BIT_KHR: return "VK_VIDEO_SESSION_CREATE_PROTECTED_CONTENT_BIT_KHR";
    case VK_VIDEO_SESSION_CREATE_ALLOW_ENCODE_PARAMETER_OPTIMIZATIONS_BIT_KHR: return "VK_VIDEO_SESSION_CREATE_ALLOW_ENCODE_PARAMETER_OPTIMIZATIONS_BIT_KHR";
    case VK_VIDEO_SESSION_CREATE_INLINE_QUERIES_BIT_KHR: return "VK_VIDEO_SESSION_CREATE_INLINE_QUERIES_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoDecodeH264PictureLayoutFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR: return "VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR";
    case VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_INTERLEAVED_LINES_BIT_KHR: return "VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_INTERLEAVED_LINES_BIT_KHR";
    case VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_SEPARATE_PLANES_BIT_KHR: return "VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_SEPARATE_PLANES_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoCodingControlFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_CODING_CONTROL_RESET_BIT_KHR: return "VK_VIDEO_CODING_CONTROL_RESET_BIT_KHR";
    case VK_VIDEO_CODING_CONTROL_ENCODE_RATE_CONTROL_BIT_KHR: return "VK_VIDEO_CODING_CONTROL_ENCODE_RATE_CONTROL_BIT_KHR";
    case VK_VIDEO_CODING_CONTROL_ENCODE_QUALITY_LEVEL_BIT_KHR: return "VK_VIDEO_CODING_CONTROL_ENCODE_QUALITY_LEVEL_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkQueryResultStatusKHR v) {
    switch(v) {
    case VK_QUERY_RESULT_STATUS_ERROR_KHR: return "VK_QUERY_RESULT_STATUS_ERROR_KHR";
    case VK_QUERY_RESULT_STATUS_NOT_READY_KHR: return "VK_QUERY_RESULT_STATUS_NOT_READY_KHR";
    case VK_QUERY_RESULT_STATUS_COMPLETE_KHR: return "VK_QUERY_RESULT_STATUS_COMPLETE_KHR";
    case VK_QUERY_RESULT_STATUS_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_KHR: return "VK_QUERY_RESULT_STATUS_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoDecodeUsageFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_DECODE_USAGE_DEFAULT_KHR: return "VK_VIDEO_DECODE_USAGE_DEFAULT_KHR";
    case VK_VIDEO_DECODE_USAGE_TRANSCODING_BIT_KHR: return "VK_VIDEO_DECODE_USAGE_TRANSCODING_BIT_KHR";
    case VK_VIDEO_DECODE_USAGE_OFFLINE_BIT_KHR: return "VK_VIDEO_DECODE_USAGE_OFFLINE_BIT_KHR";
    case VK_VIDEO_DECODE_USAGE_STREAMING_BIT_KHR: return "VK_VIDEO_DECODE_USAGE_STREAMING_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoDecodeCapabilityFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR: return "VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR";
    case VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR: return "VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeUsageFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_USAGE_DEFAULT_KHR: return "VK_VIDEO_ENCODE_USAGE_DEFAULT_KHR";
    case VK_VIDEO_ENCODE_USAGE_TRANSCODING_BIT_KHR: return "VK_VIDEO_ENCODE_USAGE_TRANSCODING_BIT_KHR";
    case VK_VIDEO_ENCODE_USAGE_STREAMING_BIT_KHR: return "VK_VIDEO_ENCODE_USAGE_STREAMING_BIT_KHR";
    case VK_VIDEO_ENCODE_USAGE_RECORDING_BIT_KHR: return "VK_VIDEO_ENCODE_USAGE_RECORDING_BIT_KHR";
    case VK_VIDEO_ENCODE_USAGE_CONFERENCING_BIT_KHR: return "VK_VIDEO_ENCODE_USAGE_CONFERENCING_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeContentFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_CONTENT_DEFAULT_KHR: return "VK_VIDEO_ENCODE_CONTENT_DEFAULT_KHR";
    case VK_VIDEO_ENCODE_CONTENT_CAMERA_BIT_KHR: return "VK_VIDEO_ENCODE_CONTENT_CAMERA_BIT_KHR";
    case VK_VIDEO_ENCODE_CONTENT_DESKTOP_BIT_KHR: return "VK_VIDEO_ENCODE_CONTENT_DESKTOP_BIT_KHR";
    case VK_VIDEO_ENCODE_CONTENT_RENDERED_BIT_KHR: return "VK_VIDEO_ENCODE_CONTENT_RENDERED_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeTuningModeKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_TUNING_MODE_DEFAULT_KHR: return "VK_VIDEO_ENCODE_TUNING_MODE_DEFAULT_KHR";
    case VK_VIDEO_ENCODE_TUNING_MODE_HIGH_QUALITY_KHR: return "VK_VIDEO_ENCODE_TUNING_MODE_HIGH_QUALITY_KHR";
    case VK_VIDEO_ENCODE_TUNING_MODE_LOW_LATENCY_KHR: return "VK_VIDEO_ENCODE_TUNING_MODE_LOW_LATENCY_KHR";
    case VK_VIDEO_ENCODE_TUNING_MODE_ULTRA_LOW_LATENCY_KHR: return "VK_VIDEO_ENCODE_TUNING_MODE_ULTRA_LOW_LATENCY_KHR";
    case VK_VIDEO_ENCODE_TUNING_MODE_LOSSLESS_KHR: return "VK_VIDEO_ENCODE_TUNING_MODE_LOSSLESS_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeCapabilityFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_CAPABILITY_PRECEDING_EXTERNALLY_ENCODED_BYTES_BIT_KHR: return "VK_VIDEO_ENCODE_CAPABILITY_PRECEDING_EXTERNALLY_ENCODED_BYTES_BIT_KHR";
    case VK_VIDEO_ENCODE_CAPABILITY_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_DETECTION_BIT_KHR: return "VK_VIDEO_ENCODE_CAPABILITY_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_DETECTION_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeFeedbackFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BUFFER_OFFSET_BIT_KHR: return "VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BUFFER_OFFSET_BIT_KHR";
    case VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BYTES_WRITTEN_BIT_KHR: return "VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BYTES_WRITTEN_BIT_KHR";
    case VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_HAS_OVERRIDES_BIT_KHR: return "VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_HAS_OVERRIDES_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeRateControlModeFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DEFAULT_KHR: return "VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DEFAULT_KHR";
    case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DISABLED_BIT_KHR: return "VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DISABLED_BIT_KHR";
    case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_CBR_BIT_KHR: return "VK_VIDEO_ENCODE_RATE_CONTROL_MODE_CBR_BIT_KHR";
    case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_VBR_BIT_KHR: return "VK_VIDEO_ENCODE_RATE_CONTROL_MODE_VBR_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeH264CapabilityFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_H264_CAPABILITY_HRD_COMPLIANCE_BIT_KHR: return "VK_VIDEO_ENCODE_H264_CAPABILITY_HRD_COMPLIANCE_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR: return "VK_VIDEO_ENCODE_H264_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_CAPABILITY_ROW_UNALIGNED_SLICE_BIT_KHR: return "VK_VIDEO_ENCODE_H264_CAPABILITY_ROW_UNALIGNED_SLICE_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_CAPABILITY_DIFFERENT_SLICE_TYPE_BIT_KHR: return "VK_VIDEO_ENCODE_H264_CAPABILITY_DIFFERENT_SLICE_TYPE_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR: return "VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR: return "VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR: return "VK_VIDEO_ENCODE_H264_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_CAPABILITY_PER_SLICE_CONSTANT_QP_BIT_KHR: return "VK_VIDEO_ENCODE_H264_CAPABILITY_PER_SLICE_CONSTANT_QP_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_CAPABILITY_GENERATE_PREFIX_NALU_BIT_KHR: return "VK_VIDEO_ENCODE_H264_CAPABILITY_GENERATE_PREFIX_NALU_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeH264StdFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_H264_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_QPPRIME_Y_ZERO_TRANSFORM_BYPASS_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_QPPRIME_Y_ZERO_TRANSFORM_BYPASS_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_SCALING_MATRIX_PRESENT_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_SCALING_MATRIX_PRESENT_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_CHROMA_QP_INDEX_OFFSET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_CHROMA_QP_INDEX_OFFSET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_SECOND_CHROMA_QP_INDEX_OFFSET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_SECOND_CHROMA_QP_INDEX_OFFSET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_PIC_INIT_QP_MINUS26_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_PIC_INIT_QP_MINUS26_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_EXPLICIT_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_EXPLICIT_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_IMPLICIT_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_IMPLICIT_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_TRANSFORM_8X8_MODE_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_TRANSFORM_8X8_MODE_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_DIRECT_SPATIAL_MV_PRED_FLAG_UNSET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_DIRECT_SPATIAL_MV_PRED_FLAG_UNSET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_UNSET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_UNSET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_DIRECT_8X8_INFERENCE_FLAG_UNSET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_DIRECT_8X8_INFERENCE_FLAG_UNSET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_DISABLED_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_DISABLED_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_ENABLED_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_ENABLED_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_PARTIAL_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_PARTIAL_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_SLICE_QP_DELTA_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_SLICE_QP_DELTA_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR: return "VK_VIDEO_ENCODE_H264_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeH264RateControlFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_H264_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR: return "VK_VIDEO_ENCODE_H264_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_RATE_CONTROL_REGULAR_GOP_BIT_KHR: return "VK_VIDEO_ENCODE_H264_RATE_CONTROL_REGULAR_GOP_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR: return "VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR: return "VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR";
    case VK_VIDEO_ENCODE_H264_RATE_CONTROL_TEMPORAL_LAYER_PATTERN_DYADIC_BIT_KHR: return "VK_VIDEO_ENCODE_H264_RATE_CONTROL_TEMPORAL_LAYER_PATTERN_DYADIC_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkHostImageCopyFlagBitsEXT v) {
    switch(v) {
    case VK_HOST_IMAGE_COPY_MEMCPY_EXT: return "VK_HOST_IMAGE_COPY_MEMCPY_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeH265CapabilityFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_H265_CAPABILITY_HRD_COMPLIANCE_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CAPABILITY_HRD_COMPLIANCE_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CAPABILITY_ROW_UNALIGNED_SLICE_SEGMENT_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CAPABILITY_ROW_UNALIGNED_SLICE_SEGMENT_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CAPABILITY_DIFFERENT_SLICE_SEGMENT_TYPE_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CAPABILITY_DIFFERENT_SLICE_SEGMENT_TYPE_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CAPABILITY_PER_SLICE_SEGMENT_CONSTANT_QP_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CAPABILITY_PER_SLICE_SEGMENT_CONSTANT_QP_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_TILES_PER_SLICE_SEGMENT_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_TILES_PER_SLICE_SEGMENT_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_SLICE_SEGMENTS_PER_TILE_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_SLICE_SEGMENTS_PER_TILE_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeH265StdFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_H265_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_SAMPLE_ADAPTIVE_OFFSET_ENABLED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_SAMPLE_ADAPTIVE_OFFSET_ENABLED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_SCALING_LIST_DATA_PRESENT_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_SCALING_LIST_DATA_PRESENT_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_PCM_ENABLED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_PCM_ENABLED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_SPS_TEMPORAL_MVP_ENABLED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_SPS_TEMPORAL_MVP_ENABLED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_INIT_QP_MINUS26_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_INIT_QP_MINUS26_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_WEIGHTED_BIPRED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_WEIGHTED_BIPRED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_LOG2_PARALLEL_MERGE_LEVEL_MINUS2_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_LOG2_PARALLEL_MERGE_LEVEL_MINUS2_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_SIGN_DATA_HIDING_ENABLED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_SIGN_DATA_HIDING_ENABLED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_UNSET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_UNSET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_PPS_SLICE_CHROMA_QP_OFFSETS_PRESENT_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_PPS_SLICE_CHROMA_QP_OFFSETS_PRESENT_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_TRANSQUANT_BYPASS_ENABLED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_TRANSQUANT_BYPASS_ENABLED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_ENTROPY_CODING_SYNC_ENABLED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_ENTROPY_CODING_SYNC_ENABLED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENTS_ENABLED_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENTS_ENABLED_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENT_FLAG_SET_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENT_FLAG_SET_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_SLICE_QP_DELTA_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_SLICE_QP_DELTA_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR: return "VK_VIDEO_ENCODE_H265_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeH265RateControlFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_H265_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR: return "VK_VIDEO_ENCODE_H265_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_RATE_CONTROL_REGULAR_GOP_BIT_KHR: return "VK_VIDEO_ENCODE_H265_RATE_CONTROL_REGULAR_GOP_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR: return "VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR: return "VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_RATE_CONTROL_TEMPORAL_SUB_LAYER_PATTERN_DYADIC_BIT_KHR: return "VK_VIDEO_ENCODE_H265_RATE_CONTROL_TEMPORAL_SUB_LAYER_PATTERN_DYADIC_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeH265CtbSizeFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_H265_CTB_SIZE_16_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CTB_SIZE_16_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CTB_SIZE_32_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CTB_SIZE_32_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_CTB_SIZE_64_BIT_KHR: return "VK_VIDEO_ENCODE_H265_CTB_SIZE_64_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVideoEncodeH265TransformBlockSizeFlagBitsKHR v) {
    switch(v) {
    case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_4_BIT_KHR: return "VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_4_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_8_BIT_KHR: return "VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_8_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_16_BIT_KHR: return "VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_16_BIT_KHR";
    case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_32_BIT_KHR: return "VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_32_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkImageCompressionFlagBitsEXT v) {
    switch(v) {
    case VK_IMAGE_COMPRESSION_DEFAULT_EXT: return "VK_IMAGE_COMPRESSION_DEFAULT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_DEFAULT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_DEFAULT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_EXPLICIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_EXPLICIT_EXT";
    case VK_IMAGE_COMPRESSION_DISABLED_EXT: return "VK_IMAGE_COMPRESSION_DISABLED_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkImageCompressionFixedRateFlagBitsEXT v) {
    switch(v) {
    case VK_IMAGE_COMPRESSION_FIXED_RATE_NONE_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_NONE_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_1BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_1BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_2BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_2BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_3BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_3BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_4BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_4BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_5BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_5BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_6BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_6BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_7BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_7BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_8BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_8BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_9BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_9BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_10BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_10BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_11BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_11BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_12BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_12BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_13BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_13BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_14BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_14BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_15BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_15BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_16BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_16BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_17BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_17BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_18BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_18BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_19BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_19BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_20BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_20BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_21BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_21BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_22BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_22BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_23BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_23BPC_BIT_EXT";
    case VK_IMAGE_COMPRESSION_FIXED_RATE_24BPC_BIT_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_24BPC_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPipelineRobustnessBufferBehaviorEXT v) {
    switch(v) {
    case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT_EXT: return "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT_EXT";
    case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED_EXT: return "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED_EXT";
    case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_EXT: return "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_EXT";
    case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2_EXT: return "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPipelineRobustnessImageBehaviorEXT v) {
    switch(v) {
    case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT_EXT: return "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT_EXT";
    case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED_EXT: return "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED_EXT";
    case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_EXT: return "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_EXT";
    case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2_EXT: return "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkOpticalFlowGridSizeFlagBitsNV v) {
    switch(v) {
    case VK_OPTICAL_FLOW_GRID_SIZE_UNKNOWN_NV: return "VK_OPTICAL_FLOW_GRID_SIZE_UNKNOWN_NV";
    case VK_OPTICAL_FLOW_GRID_SIZE_1X1_BIT_NV: return "VK_OPTICAL_FLOW_GRID_SIZE_1X1_BIT_NV";
    case VK_OPTICAL_FLOW_GRID_SIZE_2X2_BIT_NV: return "VK_OPTICAL_FLOW_GRID_SIZE_2X2_BIT_NV";
    case VK_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_NV: return "VK_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_NV";
    case VK_OPTICAL_FLOW_GRID_SIZE_8X8_BIT_NV: return "VK_OPTICAL_FLOW_GRID_SIZE_8X8_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkOpticalFlowUsageFlagBitsNV v) {
    switch(v) {
    case VK_OPTICAL_FLOW_USAGE_UNKNOWN_NV: return "VK_OPTICAL_FLOW_USAGE_UNKNOWN_NV";
    case VK_OPTICAL_FLOW_USAGE_INPUT_BIT_NV: return "VK_OPTICAL_FLOW_USAGE_INPUT_BIT_NV";
    case VK_OPTICAL_FLOW_USAGE_OUTPUT_BIT_NV: return "VK_OPTICAL_FLOW_USAGE_OUTPUT_BIT_NV";
    case VK_OPTICAL_FLOW_USAGE_HINT_BIT_NV: return "VK_OPTICAL_FLOW_USAGE_HINT_BIT_NV";
    case VK_OPTICAL_FLOW_USAGE_COST_BIT_NV: return "VK_OPTICAL_FLOW_USAGE_COST_BIT_NV";
    case VK_OPTICAL_FLOW_USAGE_GLOBAL_FLOW_BIT_NV: return "VK_OPTICAL_FLOW_USAGE_GLOBAL_FLOW_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkOpticalFlowPerformanceLevelNV v) {
    switch(v) {
    case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_UNKNOWN_NV: return "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_UNKNOWN_NV";
    case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_SLOW_NV: return "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_SLOW_NV";
    case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_MEDIUM_NV: return "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_MEDIUM_NV";
    case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_FAST_NV: return "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_FAST_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkOpticalFlowSessionBindingPointNV v) {
    switch(v) {
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_UNKNOWN_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_UNKNOWN_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_INPUT_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_INPUT_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_REFERENCE_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_REFERENCE_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_HINT_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_HINT_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_FLOW_VECTOR_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_FLOW_VECTOR_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_FLOW_VECTOR_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_FLOW_VECTOR_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_COST_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_COST_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_COST_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_COST_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_GLOBAL_FLOW_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_GLOBAL_FLOW_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkOpticalFlowSessionCreateFlagBitsNV v) {
    switch(v) {
    case VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_HINT_BIT_NV: return "VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_HINT_BIT_NV";
    case VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_COST_BIT_NV: return "VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_COST_BIT_NV";
    case VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_GLOBAL_FLOW_BIT_NV: return "VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_GLOBAL_FLOW_BIT_NV";
    case VK_OPTICAL_FLOW_SESSION_CREATE_ALLOW_REGIONS_BIT_NV: return "VK_OPTICAL_FLOW_SESSION_CREATE_ALLOW_REGIONS_BIT_NV";
    case VK_OPTICAL_FLOW_SESSION_CREATE_BOTH_DIRECTIONS_BIT_NV: return "VK_OPTICAL_FLOW_SESSION_CREATE_BOTH_DIRECTIONS_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkOpticalFlowExecuteFlagBitsNV v) {
    switch(v) {
    case VK_OPTICAL_FLOW_EXECUTE_DISABLE_TEMPORAL_HINTS_BIT_NV: return "VK_OPTICAL_FLOW_EXECUTE_DISABLE_TEMPORAL_HINTS_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkMicromapTypeEXT v) {
    switch(v) {
    case VK_MICROMAP_TYPE_OPACITY_MICROMAP_EXT: return "VK_MICROMAP_TYPE_OPACITY_MICROMAP_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBuildMicromapFlagBitsEXT v) {
    switch(v) {
    case VK_BUILD_MICROMAP_PREFER_FAST_TRACE_BIT_EXT: return "VK_BUILD_MICROMAP_PREFER_FAST_TRACE_BIT_EXT";
    case VK_BUILD_MICROMAP_PREFER_FAST_BUILD_BIT_EXT: return "VK_BUILD_MICROMAP_PREFER_FAST_BUILD_BIT_EXT";
    case VK_BUILD_MICROMAP_ALLOW_COMPACTION_BIT_EXT: return "VK_BUILD_MICROMAP_ALLOW_COMPACTION_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkMicromapCreateFlagBitsEXT v) {
    switch(v) {
    case VK_MICROMAP_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT: return "VK_MICROMAP_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCopyMicromapModeEXT v) {
    switch(v) {
    case VK_COPY_MICROMAP_MODE_CLONE_EXT: return "VK_COPY_MICROMAP_MODE_CLONE_EXT";
    case VK_COPY_MICROMAP_MODE_SERIALIZE_EXT: return "VK_COPY_MICROMAP_MODE_SERIALIZE_EXT";
    case VK_COPY_MICROMAP_MODE_DESERIALIZE_EXT: return "VK_COPY_MICROMAP_MODE_DESERIALIZE_EXT";
    case VK_COPY_MICROMAP_MODE_COMPACT_EXT: return "VK_COPY_MICROMAP_MODE_COMPACT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBuildMicromapModeEXT v) {
    switch(v) {
    case VK_BUILD_MICROMAP_MODE_BUILD_EXT: return "VK_BUILD_MICROMAP_MODE_BUILD_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkOpacityMicromapFormatEXT v) {
    switch(v) {
    case VK_OPACITY_MICROMAP_FORMAT_2_STATE_EXT: return "VK_OPACITY_MICROMAP_FORMAT_2_STATE_EXT";
    case VK_OPACITY_MICROMAP_FORMAT_4_STATE_EXT: return "VK_OPACITY_MICROMAP_FORMAT_4_STATE_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkOpacityMicromapSpecialIndexEXT v) {
    switch(v) {
    case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_TRANSPARENT_EXT: return "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_TRANSPARENT_EXT";
    case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_OPAQUE_EXT: return "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_OPAQUE_EXT";
    case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_TRANSPARENT_EXT: return "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_TRANSPARENT_EXT";
    case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE_EXT: return "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDepthBiasRepresentationEXT v) {
    switch(v) {
    case VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORMAT_EXT: return "VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORMAT_EXT";
    case VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORCE_UNORM_EXT: return "VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORCE_UNORM_EXT";
    case VK_DEPTH_BIAS_REPRESENTATION_FLOAT_EXT: return "VK_DEPTH_BIAS_REPRESENTATION_FLOAT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDeviceFaultAddressTypeEXT v) {
    switch(v) {
    case VK_DEVICE_FAULT_ADDRESS_TYPE_NONE_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_NONE_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_READ_INVALID_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_READ_INVALID_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_WRITE_INVALID_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_WRITE_INVALID_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_EXECUTE_INVALID_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_EXECUTE_INVALID_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_UNKNOWN_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_UNKNOWN_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_INVALID_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_INVALID_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_FAULT_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_FAULT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDeviceFaultVendorBinaryHeaderVersionEXT v) {
    switch(v) {
    case VK_DEVICE_FAULT_VENDOR_BINARY_HEADER_VERSION_ONE_EXT: return "VK_DEVICE_FAULT_VENDOR_BINARY_HEADER_VERSION_ONE_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkShaderCreateFlagBitsEXT v) {
    switch(v) {
    case VK_SHADER_CREATE_LINK_STAGE_BIT_EXT: return "VK_SHADER_CREATE_LINK_STAGE_BIT_EXT";
    case VK_SHADER_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT: return "VK_SHADER_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT";
    case VK_SHADER_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT: return "VK_SHADER_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT";
    case VK_SHADER_CREATE_NO_TASK_SHADER_BIT_EXT: return "VK_SHADER_CREATE_NO_TASK_SHADER_BIT_EXT";
    case VK_SHADER_CREATE_DISPATCH_BASE_BIT_EXT: return "VK_SHADER_CREATE_DISPATCH_BASE_BIT_EXT";
    case VK_SHADER_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_EXT: return "VK_SHADER_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_EXT";
    case VK_SHADER_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT: return "VK_SHADER_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkShaderCodeTypeEXT v) {
    switch(v) {
    case VK_SHADER_CODE_TYPE_BINARY_EXT: return "VK_SHADER_CODE_TYPE_BINARY_EXT";
    case VK_SHADER_CODE_TYPE_SPIRV_EXT: return "VK_SHADER_CODE_TYPE_SPIRV_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkScopeKHR v) {
    switch(v) {
    case VK_SCOPE_DEVICE_KHR: return "VK_SCOPE_DEVICE_KHR";
    case VK_SCOPE_WORKGROUP_KHR: return "VK_SCOPE_WORKGROUP_KHR";
    case VK_SCOPE_SUBGROUP_KHR: return "VK_SCOPE_SUBGROUP_KHR";
    case VK_SCOPE_QUEUE_FAMILY_KHR: return "VK_SCOPE_QUEUE_FAMILY_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkComponentTypeKHR v) {
    switch(v) {
    case VK_COMPONENT_TYPE_FLOAT16_KHR: return "VK_COMPONENT_TYPE_FLOAT16_KHR";
    case VK_COMPONENT_TYPE_FLOAT32_KHR: return "VK_COMPONENT_TYPE_FLOAT32_KHR";
    case VK_COMPONENT_TYPE_FLOAT64_KHR: return "VK_COMPONENT_TYPE_FLOAT64_KHR";
    case VK_COMPONENT_TYPE_SINT8_KHR: return "VK_COMPONENT_TYPE_SINT8_KHR";
    case VK_COMPONENT_TYPE_SINT16_KHR: return "VK_COMPONENT_TYPE_SINT16_KHR";
    case VK_COMPONENT_TYPE_SINT32_KHR: return "VK_COMPONENT_TYPE_SINT32_KHR";
    case VK_COMPONENT_TYPE_SINT64_KHR: return "VK_COMPONENT_TYPE_SINT64_KHR";
    case VK_COMPONENT_TYPE_UINT8_KHR: return "VK_COMPONENT_TYPE_UINT8_KHR";
    case VK_COMPONENT_TYPE_UINT16_KHR: return "VK_COMPONENT_TYPE_UINT16_KHR";
    case VK_COMPONENT_TYPE_UINT32_KHR: return "VK_COMPONENT_TYPE_UINT32_KHR";
    case VK_COMPONENT_TYPE_UINT64_KHR: return "VK_COMPONENT_TYPE_UINT64_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCubicFilterWeightsQCOM v) {
    switch(v) {
    case VK_CUBIC_FILTER_WEIGHTS_CATMULL_ROM_QCOM: return "VK_CUBIC_FILTER_WEIGHTS_CATMULL_ROM_QCOM";
    case VK_CUBIC_FILTER_WEIGHTS_ZERO_TANGENT_CARDINAL_QCOM: return "VK_CUBIC_FILTER_WEIGHTS_ZERO_TANGENT_CARDINAL_QCOM";
    case VK_CUBIC_FILTER_WEIGHTS_B_SPLINE_QCOM: return "VK_CUBIC_FILTER_WEIGHTS_B_SPLINE_QCOM";
    case VK_CUBIC_FILTER_WEIGHTS_MITCHELL_NETRAVALI_QCOM: return "VK_CUBIC_FILTER_WEIGHTS_MITCHELL_NETRAVALI_QCOM";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBlockMatchWindowCompareModeQCOM v) {
    switch(v) {
    case VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MIN_QCOM: return "VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MIN_QCOM";
    case VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MAX_QCOM: return "VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MAX_QCOM";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkLayeredDriverUnderlyingApiMSFT v) {
    switch(v) {
    case VK_LAYERED_DRIVER_UNDERLYING_API_NONE_MSFT: return "VK_LAYERED_DRIVER_UNDERLYING_API_NONE_MSFT";
    case VK_LAYERED_DRIVER_UNDERLYING_API_D3D12_MSFT: return "VK_LAYERED_DRIVER_UNDERLYING_API_D3D12_MSFT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkLatencyMarkerNV v) {
    switch(v) {
    case VK_LATENCY_MARKER_SIMULATION_START_NV: return "VK_LATENCY_MARKER_SIMULATION_START_NV";
    case VK_LATENCY_MARKER_SIMULATION_END_NV: return "VK_LATENCY_MARKER_SIMULATION_END_NV";
    case VK_LATENCY_MARKER_RENDERSUBMIT_START_NV: return "VK_LATENCY_MARKER_RENDERSUBMIT_START_NV";
    case VK_LATENCY_MARKER_RENDERSUBMIT_END_NV: return "VK_LATENCY_MARKER_RENDERSUBMIT_END_NV";
    case VK_LATENCY_MARKER_PRESENT_START_NV: return "VK_LATENCY_MARKER_PRESENT_START_NV";
    case VK_LATENCY_MARKER_PRESENT_END_NV: return "VK_LATENCY_MARKER_PRESENT_END_NV";
    case VK_LATENCY_MARKER_INPUT_SAMPLE_NV: return "VK_LATENCY_MARKER_INPUT_SAMPLE_NV";
    case VK_LATENCY_MARKER_TRIGGER_FLASH_NV: return "VK_LATENCY_MARKER_TRIGGER_FLASH_NV";
    case VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_START_NV: return "VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_START_NV";
    case VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_END_NV: return "VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_END_NV";
    case VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_START_NV: return "VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_START_NV";
    case VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_END_NV: return "VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_END_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkOutOfBandQueueTypeNV v) {
    switch(v) {
    case VK_OUT_OF_BAND_QUEUE_TYPE_RENDER_NV: return "VK_OUT_OF_BAND_QUEUE_TYPE_RENDER_NV";
    case VK_OUT_OF_BAND_QUEUE_TYPE_PRESENT_NV: return "VK_OUT_OF_BAND_QUEUE_TYPE_PRESENT_NV";
    default: break;
    }
    return nullptr;
  }
#if defined(VK_VERSION_1_0)
  VKU_IMPL const char* to_string(const VkImageLayout v) {
    switch(v) {
    case VK_IMAGE_LAYOUT_UNDEFINED: return "VK_IMAGE_LAYOUT_UNDEFINED";
    case VK_IMAGE_LAYOUT_GENERAL: return "VK_IMAGE_LAYOUT_GENERAL";
    case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL: return "VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL";
    case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL: return "VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL";
    case VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL: return "VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL";
    case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL: return "VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL";
    case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL: return "VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL";
    case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL: return "VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL";
    case VK_IMAGE_LAYOUT_PREINITIALIZED: return "VK_IMAGE_LAYOUT_PREINITIALIZED";
    case VK_IMAGE_LAYOUT_PRESENT_SRC_KHR: return "VK_IMAGE_LAYOUT_PRESENT_SRC_KHR";
    case VK_IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR: return "VK_IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR";
    case VK_IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR: return "VK_IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR";
    case VK_IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR: return "VK_IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR";
    case VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR: return "VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR";
    case VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT: return "VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT";
    case VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR: return "VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR";
    case VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ_KHR: return "VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ_KHR";
    case VK_IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR: return "VK_IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR";
    case VK_IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR: return "VK_IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR";
    case VK_IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR: return "VK_IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR";
    case VK_IMAGE_LAYOUT_ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT: return "VK_IMAGE_LAYOUT_ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT";
    case VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL: return "VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL";
    case VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL: return "VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL";
    case VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL: return "VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL";
    case VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL: return "VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL";
    case VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL: return "VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL";
    case VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL: return "VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL";
    case VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL: return "VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL";
    case VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL: return "VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkAttachmentLoadOp v) {
    switch(v) {
    case VK_ATTACHMENT_LOAD_OP_LOAD: return "VK_ATTACHMENT_LOAD_OP_LOAD";
    case VK_ATTACHMENT_LOAD_OP_CLEAR: return "VK_ATTACHMENT_LOAD_OP_CLEAR";
    case VK_ATTACHMENT_LOAD_OP_DONT_CARE: return "VK_ATTACHMENT_LOAD_OP_DONT_CARE";
    case VK_ATTACHMENT_LOAD_OP_NONE_KHR: return "VK_ATTACHMENT_LOAD_OP_NONE_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkAttachmentStoreOp v) {
    switch(v) {
    case VK_ATTACHMENT_STORE_OP_STORE: return "VK_ATTACHMENT_STORE_OP_STORE";
    case VK_ATTACHMENT_STORE_OP_DONT_CARE: return "VK_ATTACHMENT_STORE_OP_DONT_CARE";
    case VK_ATTACHMENT_STORE_OP_NONE: return "VK_ATTACHMENT_STORE_OP_NONE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkImageType v) {
    switch(v) {
    case VK_IMAGE_TYPE_1D: return "VK_IMAGE_TYPE_1D";
    case VK_IMAGE_TYPE_2D: return "VK_IMAGE_TYPE_2D";
    case VK_IMAGE_TYPE_3D: return "VK_IMAGE_TYPE_3D";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkImageTiling v) {
    switch(v) {
    case VK_IMAGE_TILING_OPTIMAL: return "VK_IMAGE_TILING_OPTIMAL";
    case VK_IMAGE_TILING_LINEAR: return "VK_IMAGE_TILING_LINEAR";
    case VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT: return "VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkImageViewType v) {
    switch(v) {
    case VK_IMAGE_VIEW_TYPE_1D: return "VK_IMAGE_VIEW_TYPE_1D";
    case VK_IMAGE_VIEW_TYPE_2D: return "VK_IMAGE_VIEW_TYPE_2D";
    case VK_IMAGE_VIEW_TYPE_3D: return "VK_IMAGE_VIEW_TYPE_3D";
    case VK_IMAGE_VIEW_TYPE_CUBE: return "VK_IMAGE_VIEW_TYPE_CUBE";
    case VK_IMAGE_VIEW_TYPE_1D_ARRAY: return "VK_IMAGE_VIEW_TYPE_1D_ARRAY";
    case VK_IMAGE_VIEW_TYPE_2D_ARRAY: return "VK_IMAGE_VIEW_TYPE_2D_ARRAY";
    case VK_IMAGE_VIEW_TYPE_CUBE_ARRAY: return "VK_IMAGE_VIEW_TYPE_CUBE_ARRAY";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCommandBufferLevel v) {
    switch(v) {
    case VK_COMMAND_BUFFER_LEVEL_PRIMARY: return "VK_COMMAND_BUFFER_LEVEL_PRIMARY";
    case VK_COMMAND_BUFFER_LEVEL_SECONDARY: return "VK_COMMAND_BUFFER_LEVEL_SECONDARY";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkComponentSwizzle v) {
    switch(v) {
    case VK_COMPONENT_SWIZZLE_IDENTITY: return "VK_COMPONENT_SWIZZLE_IDENTITY";
    case VK_COMPONENT_SWIZZLE_ZERO: return "VK_COMPONENT_SWIZZLE_ZERO";
    case VK_COMPONENT_SWIZZLE_ONE: return "VK_COMPONENT_SWIZZLE_ONE";
    case VK_COMPONENT_SWIZZLE_R: return "VK_COMPONENT_SWIZZLE_R";
    case VK_COMPONENT_SWIZZLE_G: return "VK_COMPONENT_SWIZZLE_G";
    case VK_COMPONENT_SWIZZLE_B: return "VK_COMPONENT_SWIZZLE_B";
    case VK_COMPONENT_SWIZZLE_A: return "VK_COMPONENT_SWIZZLE_A";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDescriptorType v) {
    switch(v) {
    case VK_DESCRIPTOR_TYPE_SAMPLER: return "VK_DESCRIPTOR_TYPE_SAMPLER";
    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER: return "VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER";
    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE: return "VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE";
    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE: return "VK_DESCRIPTOR_TYPE_STORAGE_IMAGE";
    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER: return "VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER";
    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER: return "VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER";
    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER: return "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER";
    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER: return "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER";
    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC: return "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC";
    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC: return "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC";
    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT: return "VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT";
    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR: return "VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR";
    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV: return "VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV";
    case VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM: return "VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM";
    case VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM: return "VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM";
    case VK_DESCRIPTOR_TYPE_MUTABLE_EXT: return "VK_DESCRIPTOR_TYPE_MUTABLE_EXT";
    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK: return "VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkQueryType v) {
    switch(v) {
    case VK_QUERY_TYPE_OCCLUSION: return "VK_QUERY_TYPE_OCCLUSION";
    case VK_QUERY_TYPE_PIPELINE_STATISTICS: return "VK_QUERY_TYPE_PIPELINE_STATISTICS";
    case VK_QUERY_TYPE_TIMESTAMP: return "VK_QUERY_TYPE_TIMESTAMP";
    case VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR: return "VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR";
    case VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT: return "VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT";
    case VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR: return "VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR";
    case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR: return "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR";
    case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR: return "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR";
    case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV: return "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV";
    case VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL: return "VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL";
    case VK_QUERY_TYPE_VIDEO_ENCODE_FEEDBACK_KHR: return "VK_QUERY_TYPE_VIDEO_ENCODE_FEEDBACK_KHR";
    case VK_QUERY_TYPE_MESH_PRIMITIVES_GENERATED_EXT: return "VK_QUERY_TYPE_MESH_PRIMITIVES_GENERATED_EXT";
    case VK_QUERY_TYPE_PRIMITIVES_GENERATED_EXT: return "VK_QUERY_TYPE_PRIMITIVES_GENERATED_EXT";
    case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_BOTTOM_LEVEL_POINTERS_KHR: return "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_BOTTOM_LEVEL_POINTERS_KHR";
    case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SIZE_KHR: return "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SIZE_KHR";
    case VK_QUERY_TYPE_MICROMAP_SERIALIZATION_SIZE_EXT: return "VK_QUERY_TYPE_MICROMAP_SERIALIZATION_SIZE_EXT";
    case VK_QUERY_TYPE_MICROMAP_COMPACTED_SIZE_EXT: return "VK_QUERY_TYPE_MICROMAP_COMPACTED_SIZE_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBorderColor v) {
    switch(v) {
    case VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK: return "VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK";
    case VK_BORDER_COLOR_INT_TRANSPARENT_BLACK: return "VK_BORDER_COLOR_INT_TRANSPARENT_BLACK";
    case VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK: return "VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK";
    case VK_BORDER_COLOR_INT_OPAQUE_BLACK: return "VK_BORDER_COLOR_INT_OPAQUE_BLACK";
    case VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE: return "VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE";
    case VK_BORDER_COLOR_INT_OPAQUE_WHITE: return "VK_BORDER_COLOR_INT_OPAQUE_WHITE";
    case VK_BORDER_COLOR_FLOAT_CUSTOM_EXT: return "VK_BORDER_COLOR_FLOAT_CUSTOM_EXT";
    case VK_BORDER_COLOR_INT_CUSTOM_EXT: return "VK_BORDER_COLOR_INT_CUSTOM_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPipelineBindPoint v) {
    switch(v) {
    case VK_PIPELINE_BIND_POINT_GRAPHICS: return "VK_PIPELINE_BIND_POINT_GRAPHICS";
    case VK_PIPELINE_BIND_POINT_COMPUTE: return "VK_PIPELINE_BIND_POINT_COMPUTE";
    case VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR: return "VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR";
    case VK_PIPELINE_BIND_POINT_SUBPASS_SHADING_HUAWEI: return "VK_PIPELINE_BIND_POINT_SUBPASS_SHADING_HUAWEI";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPipelineCacheHeaderVersion v) {
    switch(v) {
    case VK_PIPELINE_CACHE_HEADER_VERSION_ONE: return "VK_PIPELINE_CACHE_HEADER_VERSION_ONE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPrimitiveTopology v) {
    switch(v) {
    case VK_PRIMITIVE_TOPOLOGY_POINT_LIST: return "VK_PRIMITIVE_TOPOLOGY_POINT_LIST";
    case VK_PRIMITIVE_TOPOLOGY_LINE_LIST: return "VK_PRIMITIVE_TOPOLOGY_LINE_LIST";
    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP: return "VK_PRIMITIVE_TOPOLOGY_LINE_STRIP";
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST";
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP";
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN";
    case VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY: return "VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY";
    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY: return "VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY";
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY";
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY";
    case VK_PRIMITIVE_TOPOLOGY_PATCH_LIST: return "VK_PRIMITIVE_TOPOLOGY_PATCH_LIST";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSharingMode v) {
    switch(v) {
    case VK_SHARING_MODE_EXCLUSIVE: return "VK_SHARING_MODE_EXCLUSIVE";
    case VK_SHARING_MODE_CONCURRENT: return "VK_SHARING_MODE_CONCURRENT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkIndexType v) {
    switch(v) {
    case VK_INDEX_TYPE_UINT16: return "VK_INDEX_TYPE_UINT16";
    case VK_INDEX_TYPE_UINT32: return "VK_INDEX_TYPE_UINT32";
    case VK_INDEX_TYPE_NONE_KHR: return "VK_INDEX_TYPE_NONE_KHR";
    case VK_INDEX_TYPE_UINT8_KHR: return "VK_INDEX_TYPE_UINT8_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkFilter v) {
    switch(v) {
    case VK_FILTER_NEAREST: return "VK_FILTER_NEAREST";
    case VK_FILTER_LINEAR: return "VK_FILTER_LINEAR";
    case VK_FILTER_CUBIC_EXT: return "VK_FILTER_CUBIC_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSamplerMipmapMode v) {
    switch(v) {
    case VK_SAMPLER_MIPMAP_MODE_NEAREST: return "VK_SAMPLER_MIPMAP_MODE_NEAREST";
    case VK_SAMPLER_MIPMAP_MODE_LINEAR: return "VK_SAMPLER_MIPMAP_MODE_LINEAR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSamplerAddressMode v) {
    switch(v) {
    case VK_SAMPLER_ADDRESS_MODE_REPEAT: return "VK_SAMPLER_ADDRESS_MODE_REPEAT";
    case VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT: return "VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT";
    case VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE: return "VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE";
    case VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER: return "VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER";
    case VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE: return "VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCompareOp v) {
    switch(v) {
    case VK_COMPARE_OP_NEVER: return "VK_COMPARE_OP_NEVER";
    case VK_COMPARE_OP_LESS: return "VK_COMPARE_OP_LESS";
    case VK_COMPARE_OP_EQUAL: return "VK_COMPARE_OP_EQUAL";
    case VK_COMPARE_OP_LESS_OR_EQUAL: return "VK_COMPARE_OP_LESS_OR_EQUAL";
    case VK_COMPARE_OP_GREATER: return "VK_COMPARE_OP_GREATER";
    case VK_COMPARE_OP_NOT_EQUAL: return "VK_COMPARE_OP_NOT_EQUAL";
    case VK_COMPARE_OP_GREATER_OR_EQUAL: return "VK_COMPARE_OP_GREATER_OR_EQUAL";
    case VK_COMPARE_OP_ALWAYS: return "VK_COMPARE_OP_ALWAYS";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPolygonMode v) {
    switch(v) {
    case VK_POLYGON_MODE_FILL: return "VK_POLYGON_MODE_FILL";
    case VK_POLYGON_MODE_LINE: return "VK_POLYGON_MODE_LINE";
    case VK_POLYGON_MODE_POINT: return "VK_POLYGON_MODE_POINT";
    case VK_POLYGON_MODE_FILL_RECTANGLE_NV: return "VK_POLYGON_MODE_FILL_RECTANGLE_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkFrontFace v) {
    switch(v) {
    case VK_FRONT_FACE_COUNTER_CLOCKWISE: return "VK_FRONT_FACE_COUNTER_CLOCKWISE";
    case VK_FRONT_FACE_CLOCKWISE: return "VK_FRONT_FACE_CLOCKWISE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBlendFactor v) {
    switch(v) {
    case VK_BLEND_FACTOR_ZERO: return "VK_BLEND_FACTOR_ZERO";
    case VK_BLEND_FACTOR_ONE: return "VK_BLEND_FACTOR_ONE";
    case VK_BLEND_FACTOR_SRC_COLOR: return "VK_BLEND_FACTOR_SRC_COLOR";
    case VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR: return "VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR";
    case VK_BLEND_FACTOR_DST_COLOR: return "VK_BLEND_FACTOR_DST_COLOR";
    case VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR: return "VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR";
    case VK_BLEND_FACTOR_SRC_ALPHA: return "VK_BLEND_FACTOR_SRC_ALPHA";
    case VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA: return "VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA";
    case VK_BLEND_FACTOR_DST_ALPHA: return "VK_BLEND_FACTOR_DST_ALPHA";
    case VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA: return "VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA";
    case VK_BLEND_FACTOR_CONSTANT_COLOR: return "VK_BLEND_FACTOR_CONSTANT_COLOR";
    case VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR: return "VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR";
    case VK_BLEND_FACTOR_CONSTANT_ALPHA: return "VK_BLEND_FACTOR_CONSTANT_ALPHA";
    case VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA: return "VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA";
    case VK_BLEND_FACTOR_SRC_ALPHA_SATURATE: return "VK_BLEND_FACTOR_SRC_ALPHA_SATURATE";
    case VK_BLEND_FACTOR_SRC1_COLOR: return "VK_BLEND_FACTOR_SRC1_COLOR";
    case VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR: return "VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR";
    case VK_BLEND_FACTOR_SRC1_ALPHA: return "VK_BLEND_FACTOR_SRC1_ALPHA";
    case VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA: return "VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBlendOp v) {
    switch(v) {
    case VK_BLEND_OP_ADD: return "VK_BLEND_OP_ADD";
    case VK_BLEND_OP_SUBTRACT: return "VK_BLEND_OP_SUBTRACT";
    case VK_BLEND_OP_REVERSE_SUBTRACT: return "VK_BLEND_OP_REVERSE_SUBTRACT";
    case VK_BLEND_OP_MIN: return "VK_BLEND_OP_MIN";
    case VK_BLEND_OP_MAX: return "VK_BLEND_OP_MAX";
    case VK_BLEND_OP_ZERO_EXT: return "VK_BLEND_OP_ZERO_EXT";
    case VK_BLEND_OP_SRC_EXT: return "VK_BLEND_OP_SRC_EXT";
    case VK_BLEND_OP_DST_EXT: return "VK_BLEND_OP_DST_EXT";
    case VK_BLEND_OP_SRC_OVER_EXT: return "VK_BLEND_OP_SRC_OVER_EXT";
    case VK_BLEND_OP_DST_OVER_EXT: return "VK_BLEND_OP_DST_OVER_EXT";
    case VK_BLEND_OP_SRC_IN_EXT: return "VK_BLEND_OP_SRC_IN_EXT";
    case VK_BLEND_OP_DST_IN_EXT: return "VK_BLEND_OP_DST_IN_EXT";
    case VK_BLEND_OP_SRC_OUT_EXT: return "VK_BLEND_OP_SRC_OUT_EXT";
    case VK_BLEND_OP_DST_OUT_EXT: return "VK_BLEND_OP_DST_OUT_EXT";
    case VK_BLEND_OP_SRC_ATOP_EXT: return "VK_BLEND_OP_SRC_ATOP_EXT";
    case VK_BLEND_OP_DST_ATOP_EXT: return "VK_BLEND_OP_DST_ATOP_EXT";
    case VK_BLEND_OP_XOR_EXT: return "VK_BLEND_OP_XOR_EXT";
    case VK_BLEND_OP_MULTIPLY_EXT: return "VK_BLEND_OP_MULTIPLY_EXT";
    case VK_BLEND_OP_SCREEN_EXT: return "VK_BLEND_OP_SCREEN_EXT";
    case VK_BLEND_OP_OVERLAY_EXT: return "VK_BLEND_OP_OVERLAY_EXT";
    case VK_BLEND_OP_DARKEN_EXT: return "VK_BLEND_OP_DARKEN_EXT";
    case VK_BLEND_OP_LIGHTEN_EXT: return "VK_BLEND_OP_LIGHTEN_EXT";
    case VK_BLEND_OP_COLORDODGE_EXT: return "VK_BLEND_OP_COLORDODGE_EXT";
    case VK_BLEND_OP_COLORBURN_EXT: return "VK_BLEND_OP_COLORBURN_EXT";
    case VK_BLEND_OP_HARDLIGHT_EXT: return "VK_BLEND_OP_HARDLIGHT_EXT";
    case VK_BLEND_OP_SOFTLIGHT_EXT: return "VK_BLEND_OP_SOFTLIGHT_EXT";
    case VK_BLEND_OP_DIFFERENCE_EXT: return "VK_BLEND_OP_DIFFERENCE_EXT";
    case VK_BLEND_OP_EXCLUSION_EXT: return "VK_BLEND_OP_EXCLUSION_EXT";
    case VK_BLEND_OP_INVERT_EXT: return "VK_BLEND_OP_INVERT_EXT";
    case VK_BLEND_OP_INVERT_RGB_EXT: return "VK_BLEND_OP_INVERT_RGB_EXT";
    case VK_BLEND_OP_LINEARDODGE_EXT: return "VK_BLEND_OP_LINEARDODGE_EXT";
    case VK_BLEND_OP_LINEARBURN_EXT: return "VK_BLEND_OP_LINEARBURN_EXT";
    case VK_BLEND_OP_VIVIDLIGHT_EXT: return "VK_BLEND_OP_VIVIDLIGHT_EXT";
    case VK_BLEND_OP_LINEARLIGHT_EXT: return "VK_BLEND_OP_LINEARLIGHT_EXT";
    case VK_BLEND_OP_PINLIGHT_EXT: return "VK_BLEND_OP_PINLIGHT_EXT";
    case VK_BLEND_OP_HARDMIX_EXT: return "VK_BLEND_OP_HARDMIX_EXT";
    case VK_BLEND_OP_HSL_HUE_EXT: return "VK_BLEND_OP_HSL_HUE_EXT";
    case VK_BLEND_OP_HSL_SATURATION_EXT: return "VK_BLEND_OP_HSL_SATURATION_EXT";
    case VK_BLEND_OP_HSL_COLOR_EXT: return "VK_BLEND_OP_HSL_COLOR_EXT";
    case VK_BLEND_OP_HSL_LUMINOSITY_EXT: return "VK_BLEND_OP_HSL_LUMINOSITY_EXT";
    case VK_BLEND_OP_PLUS_EXT: return "VK_BLEND_OP_PLUS_EXT";
    case VK_BLEND_OP_PLUS_CLAMPED_EXT: return "VK_BLEND_OP_PLUS_CLAMPED_EXT";
    case VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT: return "VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT";
    case VK_BLEND_OP_PLUS_DARKER_EXT: return "VK_BLEND_OP_PLUS_DARKER_EXT";
    case VK_BLEND_OP_MINUS_EXT: return "VK_BLEND_OP_MINUS_EXT";
    case VK_BLEND_OP_MINUS_CLAMPED_EXT: return "VK_BLEND_OP_MINUS_CLAMPED_EXT";
    case VK_BLEND_OP_CONTRAST_EXT: return "VK_BLEND_OP_CONTRAST_EXT";
    case VK_BLEND_OP_INVERT_OVG_EXT: return "VK_BLEND_OP_INVERT_OVG_EXT";
    case VK_BLEND_OP_RED_EXT: return "VK_BLEND_OP_RED_EXT";
    case VK_BLEND_OP_GREEN_EXT: return "VK_BLEND_OP_GREEN_EXT";
    case VK_BLEND_OP_BLUE_EXT: return "VK_BLEND_OP_BLUE_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkStencilOp v) {
    switch(v) {
    case VK_STENCIL_OP_KEEP: return "VK_STENCIL_OP_KEEP";
    case VK_STENCIL_OP_ZERO: return "VK_STENCIL_OP_ZERO";
    case VK_STENCIL_OP_REPLACE: return "VK_STENCIL_OP_REPLACE";
    case VK_STENCIL_OP_INCREMENT_AND_CLAMP: return "VK_STENCIL_OP_INCREMENT_AND_CLAMP";
    case VK_STENCIL_OP_DECREMENT_AND_CLAMP: return "VK_STENCIL_OP_DECREMENT_AND_CLAMP";
    case VK_STENCIL_OP_INVERT: return "VK_STENCIL_OP_INVERT";
    case VK_STENCIL_OP_INCREMENT_AND_WRAP: return "VK_STENCIL_OP_INCREMENT_AND_WRAP";
    case VK_STENCIL_OP_DECREMENT_AND_WRAP: return "VK_STENCIL_OP_DECREMENT_AND_WRAP";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkLogicOp v) {
    switch(v) {
    case VK_LOGIC_OP_CLEAR: return "VK_LOGIC_OP_CLEAR";
    case VK_LOGIC_OP_AND: return "VK_LOGIC_OP_AND";
    case VK_LOGIC_OP_AND_REVERSE: return "VK_LOGIC_OP_AND_REVERSE";
    case VK_LOGIC_OP_COPY: return "VK_LOGIC_OP_COPY";
    case VK_LOGIC_OP_AND_INVERTED: return "VK_LOGIC_OP_AND_INVERTED";
    case VK_LOGIC_OP_NO_OP: return "VK_LOGIC_OP_NO_OP";
    case VK_LOGIC_OP_XOR: return "VK_LOGIC_OP_XOR";
    case VK_LOGIC_OP_OR: return "VK_LOGIC_OP_OR";
    case VK_LOGIC_OP_NOR: return "VK_LOGIC_OP_NOR";
    case VK_LOGIC_OP_EQUIVALENT: return "VK_LOGIC_OP_EQUIVALENT";
    case VK_LOGIC_OP_INVERT: return "VK_LOGIC_OP_INVERT";
    case VK_LOGIC_OP_OR_REVERSE: return "VK_LOGIC_OP_OR_REVERSE";
    case VK_LOGIC_OP_COPY_INVERTED: return "VK_LOGIC_OP_COPY_INVERTED";
    case VK_LOGIC_OP_OR_INVERTED: return "VK_LOGIC_OP_OR_INVERTED";
    case VK_LOGIC_OP_NAND: return "VK_LOGIC_OP_NAND";
    case VK_LOGIC_OP_SET: return "VK_LOGIC_OP_SET";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkInternalAllocationType v) {
    switch(v) {
    case VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE: return "VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSystemAllocationScope v) {
    switch(v) {
    case VK_SYSTEM_ALLOCATION_SCOPE_COMMAND: return "VK_SYSTEM_ALLOCATION_SCOPE_COMMAND";
    case VK_SYSTEM_ALLOCATION_SCOPE_OBJECT: return "VK_SYSTEM_ALLOCATION_SCOPE_OBJECT";
    case VK_SYSTEM_ALLOCATION_SCOPE_CACHE: return "VK_SYSTEM_ALLOCATION_SCOPE_CACHE";
    case VK_SYSTEM_ALLOCATION_SCOPE_DEVICE: return "VK_SYSTEM_ALLOCATION_SCOPE_DEVICE";
    case VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE: return "VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPhysicalDeviceType v) {
    switch(v) {
    case VK_PHYSICAL_DEVICE_TYPE_OTHER: return "VK_PHYSICAL_DEVICE_TYPE_OTHER";
    case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: return "VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU";
    case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU: return "VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU";
    case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU: return "VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU";
    case VK_PHYSICAL_DEVICE_TYPE_CPU: return "VK_PHYSICAL_DEVICE_TYPE_CPU";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVertexInputRate v) {
    switch(v) {
    case VK_VERTEX_INPUT_RATE_VERTEX: return "VK_VERTEX_INPUT_RATE_VERTEX";
    case VK_VERTEX_INPUT_RATE_INSTANCE: return "VK_VERTEX_INPUT_RATE_INSTANCE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkFormat v) {
    switch(v) {
    case VK_FORMAT_UNDEFINED: return "VK_FORMAT_UNDEFINED";
    case VK_FORMAT_R4G4_UNORM_PACK8: return "VK_FORMAT_R4G4_UNORM_PACK8";
    case VK_FORMAT_R4G4B4A4_UNORM_PACK16: return "VK_FORMAT_R4G4B4A4_UNORM_PACK16";
    case VK_FORMAT_B4G4R4A4_UNORM_PACK16: return "VK_FORMAT_B4G4R4A4_UNORM_PACK16";
    case VK_FORMAT_R5G6B5_UNORM_PACK16: return "VK_FORMAT_R5G6B5_UNORM_PACK16";
    case VK_FORMAT_B5G6R5_UNORM_PACK16: return "VK_FORMAT_B5G6R5_UNORM_PACK16";
    case VK_FORMAT_R5G5B5A1_UNORM_PACK16: return "VK_FORMAT_R5G5B5A1_UNORM_PACK16";
    case VK_FORMAT_B5G5R5A1_UNORM_PACK16: return "VK_FORMAT_B5G5R5A1_UNORM_PACK16";
    case VK_FORMAT_A1R5G5B5_UNORM_PACK16: return "VK_FORMAT_A1R5G5B5_UNORM_PACK16";
    case VK_FORMAT_R8_UNORM: return "VK_FORMAT_R8_UNORM";
    case VK_FORMAT_R8_SNORM: return "VK_FORMAT_R8_SNORM";
    case VK_FORMAT_R8_USCALED: return "VK_FORMAT_R8_USCALED";
    case VK_FORMAT_R8_SSCALED: return "VK_FORMAT_R8_SSCALED";
    case VK_FORMAT_R8_UINT: return "VK_FORMAT_R8_UINT";
    case VK_FORMAT_R8_SINT: return "VK_FORMAT_R8_SINT";
    case VK_FORMAT_R8_SRGB: return "VK_FORMAT_R8_SRGB";
    case VK_FORMAT_R8G8_UNORM: return "VK_FORMAT_R8G8_UNORM";
    case VK_FORMAT_R8G8_SNORM: return "VK_FORMAT_R8G8_SNORM";
    case VK_FORMAT_R8G8_USCALED: return "VK_FORMAT_R8G8_USCALED";
    case VK_FORMAT_R8G8_SSCALED: return "VK_FORMAT_R8G8_SSCALED";
    case VK_FORMAT_R8G8_UINT: return "VK_FORMAT_R8G8_UINT";
    case VK_FORMAT_R8G8_SINT: return "VK_FORMAT_R8G8_SINT";
    case VK_FORMAT_R8G8_SRGB: return "VK_FORMAT_R8G8_SRGB";
    case VK_FORMAT_R8G8B8_UNORM: return "VK_FORMAT_R8G8B8_UNORM";
    case VK_FORMAT_R8G8B8_SNORM: return "VK_FORMAT_R8G8B8_SNORM";
    case VK_FORMAT_R8G8B8_USCALED: return "VK_FORMAT_R8G8B8_USCALED";
    case VK_FORMAT_R8G8B8_SSCALED: return "VK_FORMAT_R8G8B8_SSCALED";
    case VK_FORMAT_R8G8B8_UINT: return "VK_FORMAT_R8G8B8_UINT";
    case VK_FORMAT_R8G8B8_SINT: return "VK_FORMAT_R8G8B8_SINT";
    case VK_FORMAT_R8G8B8_SRGB: return "VK_FORMAT_R8G8B8_SRGB";
    case VK_FORMAT_B8G8R8_UNORM: return "VK_FORMAT_B8G8R8_UNORM";
    case VK_FORMAT_B8G8R8_SNORM: return "VK_FORMAT_B8G8R8_SNORM";
    case VK_FORMAT_B8G8R8_USCALED: return "VK_FORMAT_B8G8R8_USCALED";
    case VK_FORMAT_B8G8R8_SSCALED: return "VK_FORMAT_B8G8R8_SSCALED";
    case VK_FORMAT_B8G8R8_UINT: return "VK_FORMAT_B8G8R8_UINT";
    case VK_FORMAT_B8G8R8_SINT: return "VK_FORMAT_B8G8R8_SINT";
    case VK_FORMAT_B8G8R8_SRGB: return "VK_FORMAT_B8G8R8_SRGB";
    case VK_FORMAT_R8G8B8A8_UNORM: return "VK_FORMAT_R8G8B8A8_UNORM";
    case VK_FORMAT_R8G8B8A8_SNORM: return "VK_FORMAT_R8G8B8A8_SNORM";
    case VK_FORMAT_R8G8B8A8_USCALED: return "VK_FORMAT_R8G8B8A8_USCALED";
    case VK_FORMAT_R8G8B8A8_SSCALED: return "VK_FORMAT_R8G8B8A8_SSCALED";
    case VK_FORMAT_R8G8B8A8_UINT: return "VK_FORMAT_R8G8B8A8_UINT";
    case VK_FORMAT_R8G8B8A8_SINT: return "VK_FORMAT_R8G8B8A8_SINT";
    case VK_FORMAT_R8G8B8A8_SRGB: return "VK_FORMAT_R8G8B8A8_SRGB";
    case VK_FORMAT_B8G8R8A8_UNORM: return "VK_FORMAT_B8G8R8A8_UNORM";
    case VK_FORMAT_B8G8R8A8_SNORM: return "VK_FORMAT_B8G8R8A8_SNORM";
    case VK_FORMAT_B8G8R8A8_USCALED: return "VK_FORMAT_B8G8R8A8_USCALED";
    case VK_FORMAT_B8G8R8A8_SSCALED: return "VK_FORMAT_B8G8R8A8_SSCALED";
    case VK_FORMAT_B8G8R8A8_UINT: return "VK_FORMAT_B8G8R8A8_UINT";
    case VK_FORMAT_B8G8R8A8_SINT: return "VK_FORMAT_B8G8R8A8_SINT";
    case VK_FORMAT_B8G8R8A8_SRGB: return "VK_FORMAT_B8G8R8A8_SRGB";
    case VK_FORMAT_A8B8G8R8_UNORM_PACK32: return "VK_FORMAT_A8B8G8R8_UNORM_PACK32";
    case VK_FORMAT_A8B8G8R8_SNORM_PACK32: return "VK_FORMAT_A8B8G8R8_SNORM_PACK32";
    case VK_FORMAT_A8B8G8R8_USCALED_PACK32: return "VK_FORMAT_A8B8G8R8_USCALED_PACK32";
    case VK_FORMAT_A8B8G8R8_SSCALED_PACK32: return "VK_FORMAT_A8B8G8R8_SSCALED_PACK32";
    case VK_FORMAT_A8B8G8R8_UINT_PACK32: return "VK_FORMAT_A8B8G8R8_UINT_PACK32";
    case VK_FORMAT_A8B8G8R8_SINT_PACK32: return "VK_FORMAT_A8B8G8R8_SINT_PACK32";
    case VK_FORMAT_A8B8G8R8_SRGB_PACK32: return "VK_FORMAT_A8B8G8R8_SRGB_PACK32";
    case VK_FORMAT_A2R10G10B10_UNORM_PACK32: return "VK_FORMAT_A2R10G10B10_UNORM_PACK32";
    case VK_FORMAT_A2R10G10B10_SNORM_PACK32: return "VK_FORMAT_A2R10G10B10_SNORM_PACK32";
    case VK_FORMAT_A2R10G10B10_USCALED_PACK32: return "VK_FORMAT_A2R10G10B10_USCALED_PACK32";
    case VK_FORMAT_A2R10G10B10_SSCALED_PACK32: return "VK_FORMAT_A2R10G10B10_SSCALED_PACK32";
    case VK_FORMAT_A2R10G10B10_UINT_PACK32: return "VK_FORMAT_A2R10G10B10_UINT_PACK32";
    case VK_FORMAT_A2R10G10B10_SINT_PACK32: return "VK_FORMAT_A2R10G10B10_SINT_PACK32";
    case VK_FORMAT_A2B10G10R10_UNORM_PACK32: return "VK_FORMAT_A2B10G10R10_UNORM_PACK32";
    case VK_FORMAT_A2B10G10R10_SNORM_PACK32: return "VK_FORMAT_A2B10G10R10_SNORM_PACK32";
    case VK_FORMAT_A2B10G10R10_USCALED_PACK32: return "VK_FORMAT_A2B10G10R10_USCALED_PACK32";
    case VK_FORMAT_A2B10G10R10_SSCALED_PACK32: return "VK_FORMAT_A2B10G10R10_SSCALED_PACK32";
    case VK_FORMAT_A2B10G10R10_UINT_PACK32: return "VK_FORMAT_A2B10G10R10_UINT_PACK32";
    case VK_FORMAT_A2B10G10R10_SINT_PACK32: return "VK_FORMAT_A2B10G10R10_SINT_PACK32";
    case VK_FORMAT_R16_UNORM: return "VK_FORMAT_R16_UNORM";
    case VK_FORMAT_R16_SNORM: return "VK_FORMAT_R16_SNORM";
    case VK_FORMAT_R16_USCALED: return "VK_FORMAT_R16_USCALED";
    case VK_FORMAT_R16_SSCALED: return "VK_FORMAT_R16_SSCALED";
    case VK_FORMAT_R16_UINT: return "VK_FORMAT_R16_UINT";
    case VK_FORMAT_R16_SINT: return "VK_FORMAT_R16_SINT";
    case VK_FORMAT_R16_SFLOAT: return "VK_FORMAT_R16_SFLOAT";
    case VK_FORMAT_R16G16_UNORM: return "VK_FORMAT_R16G16_UNORM";
    case VK_FORMAT_R16G16_SNORM: return "VK_FORMAT_R16G16_SNORM";
    case VK_FORMAT_R16G16_USCALED: return "VK_FORMAT_R16G16_USCALED";
    case VK_FORMAT_R16G16_SSCALED: return "VK_FORMAT_R16G16_SSCALED";
    case VK_FORMAT_R16G16_UINT: return "VK_FORMAT_R16G16_UINT";
    case VK_FORMAT_R16G16_SINT: return "VK_FORMAT_R16G16_SINT";
    case VK_FORMAT_R16G16_SFLOAT: return "VK_FORMAT_R16G16_SFLOAT";
    case VK_FORMAT_R16G16B16_UNORM: return "VK_FORMAT_R16G16B16_UNORM";
    case VK_FORMAT_R16G16B16_SNORM: return "VK_FORMAT_R16G16B16_SNORM";
    case VK_FORMAT_R16G16B16_USCALED: return "VK_FORMAT_R16G16B16_USCALED";
    case VK_FORMAT_R16G16B16_SSCALED: return "VK_FORMAT_R16G16B16_SSCALED";
    case VK_FORMAT_R16G16B16_UINT: return "VK_FORMAT_R16G16B16_UINT";
    case VK_FORMAT_R16G16B16_SINT: return "VK_FORMAT_R16G16B16_SINT";
    case VK_FORMAT_R16G16B16_SFLOAT: return "VK_FORMAT_R16G16B16_SFLOAT";
    case VK_FORMAT_R16G16B16A16_UNORM: return "VK_FORMAT_R16G16B16A16_UNORM";
    case VK_FORMAT_R16G16B16A16_SNORM: return "VK_FORMAT_R16G16B16A16_SNORM";
    case VK_FORMAT_R16G16B16A16_USCALED: return "VK_FORMAT_R16G16B16A16_USCALED";
    case VK_FORMAT_R16G16B16A16_SSCALED: return "VK_FORMAT_R16G16B16A16_SSCALED";
    case VK_FORMAT_R16G16B16A16_UINT: return "VK_FORMAT_R16G16B16A16_UINT";
    case VK_FORMAT_R16G16B16A16_SINT: return "VK_FORMAT_R16G16B16A16_SINT";
    case VK_FORMAT_R16G16B16A16_SFLOAT: return "VK_FORMAT_R16G16B16A16_SFLOAT";
    case VK_FORMAT_R32_UINT: return "VK_FORMAT_R32_UINT";
    case VK_FORMAT_R32_SINT: return "VK_FORMAT_R32_SINT";
    case VK_FORMAT_R32_SFLOAT: return "VK_FORMAT_R32_SFLOAT";
    case VK_FORMAT_R32G32_UINT: return "VK_FORMAT_R32G32_UINT";
    case VK_FORMAT_R32G32_SINT: return "VK_FORMAT_R32G32_SINT";
    case VK_FORMAT_R32G32_SFLOAT: return "VK_FORMAT_R32G32_SFLOAT";
    case VK_FORMAT_R32G32B32_UINT: return "VK_FORMAT_R32G32B32_UINT";
    case VK_FORMAT_R32G32B32_SINT: return "VK_FORMAT_R32G32B32_SINT";
    case VK_FORMAT_R32G32B32_SFLOAT: return "VK_FORMAT_R32G32B32_SFLOAT";
    case VK_FORMAT_R32G32B32A32_UINT: return "VK_FORMAT_R32G32B32A32_UINT";
    case VK_FORMAT_R32G32B32A32_SINT: return "VK_FORMAT_R32G32B32A32_SINT";
    case VK_FORMAT_R32G32B32A32_SFLOAT: return "VK_FORMAT_R32G32B32A32_SFLOAT";
    case VK_FORMAT_R64_UINT: return "VK_FORMAT_R64_UINT";
    case VK_FORMAT_R64_SINT: return "VK_FORMAT_R64_SINT";
    case VK_FORMAT_R64_SFLOAT: return "VK_FORMAT_R64_SFLOAT";
    case VK_FORMAT_R64G64_UINT: return "VK_FORMAT_R64G64_UINT";
    case VK_FORMAT_R64G64_SINT: return "VK_FORMAT_R64G64_SINT";
    case VK_FORMAT_R64G64_SFLOAT: return "VK_FORMAT_R64G64_SFLOAT";
    case VK_FORMAT_R64G64B64_UINT: return "VK_FORMAT_R64G64B64_UINT";
    case VK_FORMAT_R64G64B64_SINT: return "VK_FORMAT_R64G64B64_SINT";
    case VK_FORMAT_R64G64B64_SFLOAT: return "VK_FORMAT_R64G64B64_SFLOAT";
    case VK_FORMAT_R64G64B64A64_UINT: return "VK_FORMAT_R64G64B64A64_UINT";
    case VK_FORMAT_R64G64B64A64_SINT: return "VK_FORMAT_R64G64B64A64_SINT";
    case VK_FORMAT_R64G64B64A64_SFLOAT: return "VK_FORMAT_R64G64B64A64_SFLOAT";
    case VK_FORMAT_B10G11R11_UFLOAT_PACK32: return "VK_FORMAT_B10G11R11_UFLOAT_PACK32";
    case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32: return "VK_FORMAT_E5B9G9R9_UFLOAT_PACK32";
    case VK_FORMAT_D16_UNORM: return "VK_FORMAT_D16_UNORM";
    case VK_FORMAT_X8_D24_UNORM_PACK32: return "VK_FORMAT_X8_D24_UNORM_PACK32";
    case VK_FORMAT_D32_SFLOAT: return "VK_FORMAT_D32_SFLOAT";
    case VK_FORMAT_S8_UINT: return "VK_FORMAT_S8_UINT";
    case VK_FORMAT_D16_UNORM_S8_UINT: return "VK_FORMAT_D16_UNORM_S8_UINT";
    case VK_FORMAT_D24_UNORM_S8_UINT: return "VK_FORMAT_D24_UNORM_S8_UINT";
    case VK_FORMAT_D32_SFLOAT_S8_UINT: return "VK_FORMAT_D32_SFLOAT_S8_UINT";
    case VK_FORMAT_BC1_RGB_UNORM_BLOCK: return "VK_FORMAT_BC1_RGB_UNORM_BLOCK";
    case VK_FORMAT_BC1_RGB_SRGB_BLOCK: return "VK_FORMAT_BC1_RGB_SRGB_BLOCK";
    case VK_FORMAT_BC1_RGBA_UNORM_BLOCK: return "VK_FORMAT_BC1_RGBA_UNORM_BLOCK";
    case VK_FORMAT_BC1_RGBA_SRGB_BLOCK: return "VK_FORMAT_BC1_RGBA_SRGB_BLOCK";
    case VK_FORMAT_BC2_UNORM_BLOCK: return "VK_FORMAT_BC2_UNORM_BLOCK";
    case VK_FORMAT_BC2_SRGB_BLOCK: return "VK_FORMAT_BC2_SRGB_BLOCK";
    case VK_FORMAT_BC3_UNORM_BLOCK: return "VK_FORMAT_BC3_UNORM_BLOCK";
    case VK_FORMAT_BC3_SRGB_BLOCK: return "VK_FORMAT_BC3_SRGB_BLOCK";
    case VK_FORMAT_BC4_UNORM_BLOCK: return "VK_FORMAT_BC4_UNORM_BLOCK";
    case VK_FORMAT_BC4_SNORM_BLOCK: return "VK_FORMAT_BC4_SNORM_BLOCK";
    case VK_FORMAT_BC5_UNORM_BLOCK: return "VK_FORMAT_BC5_UNORM_BLOCK";
    case VK_FORMAT_BC5_SNORM_BLOCK: return "VK_FORMAT_BC5_SNORM_BLOCK";
    case VK_FORMAT_BC6H_UFLOAT_BLOCK: return "VK_FORMAT_BC6H_UFLOAT_BLOCK";
    case VK_FORMAT_BC6H_SFLOAT_BLOCK: return "VK_FORMAT_BC6H_SFLOAT_BLOCK";
    case VK_FORMAT_BC7_UNORM_BLOCK: return "VK_FORMAT_BC7_UNORM_BLOCK";
    case VK_FORMAT_BC7_SRGB_BLOCK: return "VK_FORMAT_BC7_SRGB_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK: return "VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK: return "VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK: return "VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK: return "VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK: return "VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK: return "VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK";
    case VK_FORMAT_EAC_R11_UNORM_BLOCK: return "VK_FORMAT_EAC_R11_UNORM_BLOCK";
    case VK_FORMAT_EAC_R11_SNORM_BLOCK: return "VK_FORMAT_EAC_R11_SNORM_BLOCK";
    case VK_FORMAT_EAC_R11G11_UNORM_BLOCK: return "VK_FORMAT_EAC_R11G11_UNORM_BLOCK";
    case VK_FORMAT_EAC_R11G11_SNORM_BLOCK: return "VK_FORMAT_EAC_R11G11_SNORM_BLOCK";
    case VK_FORMAT_ASTC_4x4_UNORM_BLOCK: return "VK_FORMAT_ASTC_4x4_UNORM_BLOCK";
    case VK_FORMAT_ASTC_4x4_SRGB_BLOCK: return "VK_FORMAT_ASTC_4x4_SRGB_BLOCK";
    case VK_FORMAT_ASTC_5x4_UNORM_BLOCK: return "VK_FORMAT_ASTC_5x4_UNORM_BLOCK";
    case VK_FORMAT_ASTC_5x4_SRGB_BLOCK: return "VK_FORMAT_ASTC_5x4_SRGB_BLOCK";
    case VK_FORMAT_ASTC_5x5_UNORM_BLOCK: return "VK_FORMAT_ASTC_5x5_UNORM_BLOCK";
    case VK_FORMAT_ASTC_5x5_SRGB_BLOCK: return "VK_FORMAT_ASTC_5x5_SRGB_BLOCK";
    case VK_FORMAT_ASTC_6x5_UNORM_BLOCK: return "VK_FORMAT_ASTC_6x5_UNORM_BLOCK";
    case VK_FORMAT_ASTC_6x5_SRGB_BLOCK: return "VK_FORMAT_ASTC_6x5_SRGB_BLOCK";
    case VK_FORMAT_ASTC_6x6_UNORM_BLOCK: return "VK_FORMAT_ASTC_6x6_UNORM_BLOCK";
    case VK_FORMAT_ASTC_6x6_SRGB_BLOCK: return "VK_FORMAT_ASTC_6x6_SRGB_BLOCK";
    case VK_FORMAT_ASTC_8x5_UNORM_BLOCK: return "VK_FORMAT_ASTC_8x5_UNORM_BLOCK";
    case VK_FORMAT_ASTC_8x5_SRGB_BLOCK: return "VK_FORMAT_ASTC_8x5_SRGB_BLOCK";
    case VK_FORMAT_ASTC_8x6_UNORM_BLOCK: return "VK_FORMAT_ASTC_8x6_UNORM_BLOCK";
    case VK_FORMAT_ASTC_8x6_SRGB_BLOCK: return "VK_FORMAT_ASTC_8x6_SRGB_BLOCK";
    case VK_FORMAT_ASTC_8x8_UNORM_BLOCK: return "VK_FORMAT_ASTC_8x8_UNORM_BLOCK";
    case VK_FORMAT_ASTC_8x8_SRGB_BLOCK: return "VK_FORMAT_ASTC_8x8_SRGB_BLOCK";
    case VK_FORMAT_ASTC_10x5_UNORM_BLOCK: return "VK_FORMAT_ASTC_10x5_UNORM_BLOCK";
    case VK_FORMAT_ASTC_10x5_SRGB_BLOCK: return "VK_FORMAT_ASTC_10x5_SRGB_BLOCK";
    case VK_FORMAT_ASTC_10x6_UNORM_BLOCK: return "VK_FORMAT_ASTC_10x6_UNORM_BLOCK";
    case VK_FORMAT_ASTC_10x6_SRGB_BLOCK: return "VK_FORMAT_ASTC_10x6_SRGB_BLOCK";
    case VK_FORMAT_ASTC_10x8_UNORM_BLOCK: return "VK_FORMAT_ASTC_10x8_UNORM_BLOCK";
    case VK_FORMAT_ASTC_10x8_SRGB_BLOCK: return "VK_FORMAT_ASTC_10x8_SRGB_BLOCK";
    case VK_FORMAT_ASTC_10x10_UNORM_BLOCK: return "VK_FORMAT_ASTC_10x10_UNORM_BLOCK";
    case VK_FORMAT_ASTC_10x10_SRGB_BLOCK: return "VK_FORMAT_ASTC_10x10_SRGB_BLOCK";
    case VK_FORMAT_ASTC_12x10_UNORM_BLOCK: return "VK_FORMAT_ASTC_12x10_UNORM_BLOCK";
    case VK_FORMAT_ASTC_12x10_SRGB_BLOCK: return "VK_FORMAT_ASTC_12x10_SRGB_BLOCK";
    case VK_FORMAT_ASTC_12x12_UNORM_BLOCK: return "VK_FORMAT_ASTC_12x12_UNORM_BLOCK";
    case VK_FORMAT_ASTC_12x12_SRGB_BLOCK: return "VK_FORMAT_ASTC_12x12_SRGB_BLOCK";
    case VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG: return "VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG";
    case VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG: return "VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG";
    case VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG: return "VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG";
    case VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG: return "VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG";
    case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG: return "VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG";
    case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG: return "VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG";
    case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG: return "VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG";
    case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG: return "VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG";
    case VK_FORMAT_R16G16_SFIXED5_NV: return "VK_FORMAT_R16G16_SFIXED5_NV";
    case VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR: return "VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR";
    case VK_FORMAT_A8_UNORM_KHR: return "VK_FORMAT_A8_UNORM_KHR";
    case VK_FORMAT_G8B8G8R8_422_UNORM: return "VK_FORMAT_G8B8G8R8_422_UNORM";
    case VK_FORMAT_B8G8R8G8_422_UNORM: return "VK_FORMAT_B8G8R8G8_422_UNORM";
    case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM: return "VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM";
    case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM: return "VK_FORMAT_G8_B8R8_2PLANE_420_UNORM";
    case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM: return "VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM";
    case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM: return "VK_FORMAT_G8_B8R8_2PLANE_422_UNORM";
    case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM: return "VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM";
    case VK_FORMAT_R10X6_UNORM_PACK16: return "VK_FORMAT_R10X6_UNORM_PACK16";
    case VK_FORMAT_R10X6G10X6_UNORM_2PACK16: return "VK_FORMAT_R10X6G10X6_UNORM_2PACK16";
    case VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16: return "VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16";
    case VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16: return "VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16";
    case VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16: return "VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16";
    case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16: return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16";
    case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16: return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16";
    case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16: return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16";
    case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16: return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16";
    case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16: return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16";
    case VK_FORMAT_R12X4_UNORM_PACK16: return "VK_FORMAT_R12X4_UNORM_PACK16";
    case VK_FORMAT_R12X4G12X4_UNORM_2PACK16: return "VK_FORMAT_R12X4G12X4_UNORM_2PACK16";
    case VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16: return "VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16";
    case VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16: return "VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16";
    case VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16: return "VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16";
    case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16: return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16";
    case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16: return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16";
    case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16: return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16";
    case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16: return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16";
    case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16: return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16";
    case VK_FORMAT_G16B16G16R16_422_UNORM: return "VK_FORMAT_G16B16G16R16_422_UNORM";
    case VK_FORMAT_B16G16R16G16_422_UNORM: return "VK_FORMAT_B16G16R16G16_422_UNORM";
    case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM: return "VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM";
    case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM: return "VK_FORMAT_G16_B16R16_2PLANE_420_UNORM";
    case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM: return "VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM";
    case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM: return "VK_FORMAT_G16_B16R16_2PLANE_422_UNORM";
    case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM: return "VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM";
    case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM: return "VK_FORMAT_G8_B8R8_2PLANE_444_UNORM";
    case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16: return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16";
    case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16: return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16";
    case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM: return "VK_FORMAT_G16_B16R16_2PLANE_444_UNORM";
    case VK_FORMAT_A4R4G4B4_UNORM_PACK16: return "VK_FORMAT_A4R4G4B4_UNORM_PACK16";
    case VK_FORMAT_A4B4G4R4_UNORM_PACK16: return "VK_FORMAT_A4B4G4R4_UNORM_PACK16";
    case VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK";
    case VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK: return "VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkStructureType v) {
    switch(v) {
    case VK_STRUCTURE_TYPE_APPLICATION_INFO: return "VK_STRUCTURE_TYPE_APPLICATION_INFO";
    case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO: return "VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO: return "VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO: return "VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_SUBMIT_INFO: return "VK_STRUCTURE_TYPE_SUBMIT_INFO";
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO: return "VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO";
    case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE: return "VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE";
    case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO: return "VK_STRUCTURE_TYPE_BIND_SPARSE_INFO";
    case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO: return "VK_STRUCTURE_TYPE_FENCE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO: return "VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO: return "VK_STRUCTURE_TYPE_EVENT_CREATE_INFO";
    case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO: return "VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO";
    case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO: return "VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO";
    case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO: return "VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO";
    case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO: return "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO";
    case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO: return "VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO: return "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO: return "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO";
    case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO: return "VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO: return "VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET: return "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET";
    case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET: return "VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET";
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO: return "VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO";
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO: return "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO";
    case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO: return "VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO";
    case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO: return "VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO";
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER: return "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER";
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER: return "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER";
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER: return "VK_STRUCTURE_TYPE_MEMORY_BARRIER";
    case VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO: return "VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO: return "VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR: return "VK_STRUCTURE_TYPE_PRESENT_INFO_KHR";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: return "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR";
    case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR: return "VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR: return "VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR";
    case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD";
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT: return "VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT";
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT: return "VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT";
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT: return "VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT";
    case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR: return "VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR";
    case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR: return "VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR";
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV: return "VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX: return "VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX";
    case VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX: return "VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX";
    case VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX: return "VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR";
    case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD: return "VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD";
    case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: return "VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR";
    case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT: return "VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT";
    case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD: return "VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD";
    case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX: return "VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX";
    case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP: return "VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV";
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV: return "VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV";
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV";
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV: return "VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV";
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV: return "VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV";
    case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT: return "VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT";
    case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN: return "VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR";
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR: return "VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR";
    case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR: return "VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR";
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR";
    case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR: return "VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR";
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR: return "VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR";
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: return "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR";
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: return "VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR";
    case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR: return "VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR";
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR: return "VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR";
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR: return "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR";
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR: return "VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT: return "VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT";
    case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR: return "VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT: return "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT";
    case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT: return "VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT";
    case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT: return "VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT";
    case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT: return "VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE: return "VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_HDR_METADATA_EXT: return "VK_STRUCTURE_TYPE_HDR_METADATA_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG";
    case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR: return "VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR";
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR: return "VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR";
    case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR: return "VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR";
    case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR: return "VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR";
    case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR: return "VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR: return "VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR";
    case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR: return "VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR";
    case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR: return "VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR";
    case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR: return "VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR";
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR: return "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR";
    case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR: return "VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR: return "VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR: return "VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR: return "VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR: return "VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR: return "VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR";
    case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK: return "VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK";
    case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK: return "VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK";
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT: return "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT";
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT: return "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT";
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT: return "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT";
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT: return "VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT";
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID: return "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID";
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID: return "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID";
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID: return "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID";
    case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID: return "VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID";
    case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID: return "VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID";
    case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID: return "VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID";
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID: return "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID";
    case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: return "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: return "VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR: return "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR";
    case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR: return "VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR";
    case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR: return "VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR";
    case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR: return "VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT: return "VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT";
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT: return "VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT";
    case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_GEOMETRY_NV: return "VK_STRUCTURE_TYPE_GEOMETRY_NV";
    case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV: return "VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV";
    case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV: return "VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV";
    case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV: return "VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV: return "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT";
    case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT";
    case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD: return "VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR";
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD: return "VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP: return "VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV";
    case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV: return "VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL";
    case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL: return "VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL";
    case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL: return "VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL";
    case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL: return "VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL";
    case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL: return "VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL";
    case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL: return "VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL";
    case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL: return "VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD: return "VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD: return "VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD";
    case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: return "VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR: return "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR";
    case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR: return "VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT: return "VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT: return "VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV";
    case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV: return "VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT: return "VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT";
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT: return "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT";
    case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT: return "VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT";
    case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR: return "VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR: return "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR: return "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR: return "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT: return "VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT";
    case VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT: return "VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT";
    case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT: return "VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT";
    case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT: return "VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT";
    case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT: return "VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT";
    case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT: return "VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT";
    case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT: return "VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT";
    case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT: return "VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT";
    case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR: return "VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR";
    case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR: return "VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT: return "VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT: return "VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT";
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT: return "VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT";
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT: return "VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT: return "VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT: return "VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT: return "VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV: return "VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV";
    case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV: return "VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV";
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV: return "VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM";
    case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM: return "VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT: return "VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT";
    case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT: return "VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT: return "VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV";
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV: return "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_PRESENT_ID_KHR: return "VK_STRUCTURE_TYPE_PRESENT_ID_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR";
    case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV";
    case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV: return "VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV: return "VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT: return "VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT: return "VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT: return "VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT: return "VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT";
    case VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT: return "VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT: return "VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT";
    case VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT: return "VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT: return "VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT";
    case VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT: return "VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT: return "VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT";
    case VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT: return "VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV: return "VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV";
    case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV: return "VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT: return "VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT: return "VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT";
    case VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT: return "VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT";
    case VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT: return "VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT";
    case VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT: return "VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT";
    case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT: return "VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT: return "VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM: return "VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT: return "VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT";
    case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT: return "VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT";
    case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT: return "VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT: return "VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT";
    case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT: return "VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT: return "VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA: return "VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA";
    case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA: return "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA: return "VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA: return "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA";
    case VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI: return "VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI";
    case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV: return "VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT: return "VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT: return "VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT";
    case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT: return "VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX: return "VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT: return "VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT";
    case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT: return "VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT";
    case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT: return "VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT";
    case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT: return "VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT";
    case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT: return "VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT: return "VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM: return "VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM";
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM: return "VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM";
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM: return "VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM";
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM: return "VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM";
    case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM: return "VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV";
    case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV: return "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV";
    case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV: return "VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT: return "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT: return "VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG: return "VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG";
    case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG: return "VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT: return "VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV: return "VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV";
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV: return "VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV";
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV: return "VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID";
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID: return "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR: return "VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR";
    case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR: return "VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR";
    case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR: return "VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR";
    case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR: return "VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT";
    case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM";
    case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM: return "VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC";
    case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC: return "VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT: return "VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV: return "VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV";
    case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV: return "VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV";
    case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV: return "VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV";
    case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV: return "VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV";
    case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV: return "VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV";
    case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV: return "VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV";
    case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV: return "VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV: return "VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV";
    case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV: return "VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM";
    case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM: return "VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR: return "VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM";
    case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM: return "VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM";
    case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM: return "VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM";
    case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM: return "VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM";
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM: return "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX: return "VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX";
    case VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX: return "VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX";
    case VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX: return "VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX";
    case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX: return "VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_KHR: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR: return "VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR";
    case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR: return "VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR";
    case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO_KHR: return "VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO_KHR";
    case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO_KHR: return "VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO_KHR";
    case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO_KHR: return "VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO_KHR";
    case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR: return "VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR";
    case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT: return "VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT";
    case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT: return "VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES";
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO: return "VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO";
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO: return "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES";
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS: return "VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS";
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO: return "VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO";
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO: return "VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO";
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO: return "VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO";
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO: return "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2: return "VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2";
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2: return "VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2";
    case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2: return "VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2";
    case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2: return "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2";
    case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2: return "VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2";
    case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2: return "VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2";
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2: return "VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2: return "VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2";
    case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2: return "VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES";
    case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO: return "VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO: return "VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES";
    case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO: return "VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES";
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2: return "VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2";
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO: return "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO";
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO: return "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO";
    case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO: return "VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO";
    case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO: return "VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES";
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES: return "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO";
    case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES: return "VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO";
    case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES: return "VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES";
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO: return "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO";
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO: return "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO: return "VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO";
    case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES: return "VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES";
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO: return "VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO: return "VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO";
    case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES: return "VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES";
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO: return "VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO";
    case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2: return "VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2";
    case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2: return "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2";
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2: return "VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2";
    case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2: return "VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2";
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2: return "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2";
    case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO: return "VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO";
    case VK_STRUCTURE_TYPE_SUBPASS_END_INFO: return "VK_STRUCTURE_TYPE_SUBPASS_END_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES";
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE: return "VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES";
    case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO: return "VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES";
    case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO: return "VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES";
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO: return "VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO";
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO: return "VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO";
    case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO: return "VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES";
    case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT: return "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT";
    case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT: return "VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES";
    case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO: return "VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO: return "VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO";
    case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO: return "VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO";
    case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO: return "VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES";
    case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO: return "VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO";
    case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO: return "VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO";
    case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO: return "VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO";
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO: return "VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES";
    case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES";
    case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO: return "VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO: return "VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES";
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2: return "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2";
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2: return "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2";
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2: return "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2";
    case VK_STRUCTURE_TYPE_DEPENDENCY_INFO: return "VK_STRUCTURE_TYPE_DEPENDENCY_INFO";
    case VK_STRUCTURE_TYPE_SUBMIT_INFO_2: return "VK_STRUCTURE_TYPE_SUBMIT_INFO_2";
    case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO: return "VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES";
    case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2: return "VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2";
    case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2: return "VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2";
    case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2: return "VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2";
    case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2: return "VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2";
    case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2: return "VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2";
    case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2: return "VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2";
    case VK_STRUCTURE_TYPE_BUFFER_COPY_2: return "VK_STRUCTURE_TYPE_BUFFER_COPY_2";
    case VK_STRUCTURE_TYPE_IMAGE_COPY_2: return "VK_STRUCTURE_TYPE_IMAGE_COPY_2";
    case VK_STRUCTURE_TYPE_IMAGE_BLIT_2: return "VK_STRUCTURE_TYPE_IMAGE_BLIT_2";
    case VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2: return "VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2";
    case VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2: return "VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES";
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK: return "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO: return "VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES";
    case VK_STRUCTURE_TYPE_RENDERING_INFO: return "VK_STRUCTURE_TYPE_RENDERING_INFO";
    case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO: return "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES";
    case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3: return "VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES";
    case VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS: return "VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS";
    case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS: return "VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSubpassContents v) {
    switch(v) {
    case VK_SUBPASS_CONTENTS_INLINE: return "VK_SUBPASS_CONTENTS_INLINE";
    case VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS: return "VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS";
    case VK_SUBPASS_CONTENTS_INLINE_AND_SECONDARY_COMMAND_BUFFERS_EXT: return "VK_SUBPASS_CONTENTS_INLINE_AND_SECONDARY_COMMAND_BUFFERS_EXT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkResult v) {
    switch(v) {
    case VK_SUCCESS: return "VK_SUCCESS";
    case VK_NOT_READY: return "VK_NOT_READY";
    case VK_TIMEOUT: return "VK_TIMEOUT";
    case VK_EVENT_SET: return "VK_EVENT_SET";
    case VK_EVENT_RESET: return "VK_EVENT_RESET";
    case VK_INCOMPLETE: return "VK_INCOMPLETE";
    case VK_ERROR_OUT_OF_HOST_MEMORY: return "VK_ERROR_OUT_OF_HOST_MEMORY";
    case VK_ERROR_OUT_OF_DEVICE_MEMORY: return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
    case VK_ERROR_INITIALIZATION_FAILED: return "VK_ERROR_INITIALIZATION_FAILED";
    case VK_ERROR_DEVICE_LOST: return "VK_ERROR_DEVICE_LOST";
    case VK_ERROR_MEMORY_MAP_FAILED: return "VK_ERROR_MEMORY_MAP_FAILED";
    case VK_ERROR_LAYER_NOT_PRESENT: return "VK_ERROR_LAYER_NOT_PRESENT";
    case VK_ERROR_EXTENSION_NOT_PRESENT: return "VK_ERROR_EXTENSION_NOT_PRESENT";
    case VK_ERROR_FEATURE_NOT_PRESENT: return "VK_ERROR_FEATURE_NOT_PRESENT";
    case VK_ERROR_INCOMPATIBLE_DRIVER: return "VK_ERROR_INCOMPATIBLE_DRIVER";
    case VK_ERROR_TOO_MANY_OBJECTS: return "VK_ERROR_TOO_MANY_OBJECTS";
    case VK_ERROR_FORMAT_NOT_SUPPORTED: return "VK_ERROR_FORMAT_NOT_SUPPORTED";
    case VK_ERROR_FRAGMENTED_POOL: return "VK_ERROR_FRAGMENTED_POOL";
    case VK_ERROR_UNKNOWN: return "VK_ERROR_UNKNOWN";
    case VK_ERROR_SURFACE_LOST_KHR: return "VK_ERROR_SURFACE_LOST_KHR";
    case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
    case VK_SUBOPTIMAL_KHR: return "VK_SUBOPTIMAL_KHR";
    case VK_ERROR_OUT_OF_DATE_KHR: return "VK_ERROR_OUT_OF_DATE_KHR";
    case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
    case VK_ERROR_VALIDATION_FAILED_EXT: return "VK_ERROR_VALIDATION_FAILED_EXT";
    case VK_ERROR_INVALID_SHADER_NV: return "VK_ERROR_INVALID_SHADER_NV";
    case VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR: return "VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR";
    case VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR: return "VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR";
    case VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR: return "VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR";
    case VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR: return "VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR";
    case VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR: return "VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR";
    case VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR: return "VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR";
    case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: return "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT";
    case VK_ERROR_NOT_PERMITTED_KHR: return "VK_ERROR_NOT_PERMITTED_KHR";
    case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT: return "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";
    case VK_THREAD_IDLE_KHR: return "VK_THREAD_IDLE_KHR";
    case VK_THREAD_DONE_KHR: return "VK_THREAD_DONE_KHR";
    case VK_OPERATION_DEFERRED_KHR: return "VK_OPERATION_DEFERRED_KHR";
    case VK_OPERATION_NOT_DEFERRED_KHR: return "VK_OPERATION_NOT_DEFERRED_KHR";
    case VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR: return "VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR";
    case VK_ERROR_COMPRESSION_EXHAUSTED_EXT: return "VK_ERROR_COMPRESSION_EXHAUSTED_EXT";
    case VK_INCOMPATIBLE_SHADER_BINARY_EXT: return "VK_INCOMPATIBLE_SHADER_BINARY_EXT";
    case VK_ERROR_OUT_OF_POOL_MEMORY: return "VK_ERROR_OUT_OF_POOL_MEMORY";
    case VK_ERROR_INVALID_EXTERNAL_HANDLE: return "VK_ERROR_INVALID_EXTERNAL_HANDLE";
    case VK_ERROR_FRAGMENTATION: return "VK_ERROR_FRAGMENTATION";
    case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS: return "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS";
    case VK_PIPELINE_COMPILE_REQUIRED: return "VK_PIPELINE_COMPILE_REQUIRED";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDynamicState v) {
    switch(v) {
    case VK_DYNAMIC_STATE_VIEWPORT: return "VK_DYNAMIC_STATE_VIEWPORT";
    case VK_DYNAMIC_STATE_SCISSOR: return "VK_DYNAMIC_STATE_SCISSOR";
    case VK_DYNAMIC_STATE_LINE_WIDTH: return "VK_DYNAMIC_STATE_LINE_WIDTH";
    case VK_DYNAMIC_STATE_DEPTH_BIAS: return "VK_DYNAMIC_STATE_DEPTH_BIAS";
    case VK_DYNAMIC_STATE_BLEND_CONSTANTS: return "VK_DYNAMIC_STATE_BLEND_CONSTANTS";
    case VK_DYNAMIC_STATE_DEPTH_BOUNDS: return "VK_DYNAMIC_STATE_DEPTH_BOUNDS";
    case VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK: return "VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK";
    case VK_DYNAMIC_STATE_STENCIL_WRITE_MASK: return "VK_DYNAMIC_STATE_STENCIL_WRITE_MASK";
    case VK_DYNAMIC_STATE_STENCIL_REFERENCE: return "VK_DYNAMIC_STATE_STENCIL_REFERENCE";
    case VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV: return "VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV";
    case VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT: return "VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT";
    case VK_DYNAMIC_STATE_DISCARD_RECTANGLE_ENABLE_EXT: return "VK_DYNAMIC_STATE_DISCARD_RECTANGLE_ENABLE_EXT";
    case VK_DYNAMIC_STATE_DISCARD_RECTANGLE_MODE_EXT: return "VK_DYNAMIC_STATE_DISCARD_RECTANGLE_MODE_EXT";
    case VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT: return "VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT";
    case VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR: return "VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR";
    case VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV: return "VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV";
    case VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV: return "VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV";
    case VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_ENABLE_NV: return "VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_ENABLE_NV";
    case VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV: return "VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV";
    case VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR: return "VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR";
    case VK_DYNAMIC_STATE_VERTEX_INPUT_EXT: return "VK_DYNAMIC_STATE_VERTEX_INPUT_EXT";
    case VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT: return "VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT";
    case VK_DYNAMIC_STATE_LOGIC_OP_EXT: return "VK_DYNAMIC_STATE_LOGIC_OP_EXT";
    case VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT: return "VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT";
    case VK_DYNAMIC_STATE_DEPTH_CLAMP_ENABLE_EXT: return "VK_DYNAMIC_STATE_DEPTH_CLAMP_ENABLE_EXT";
    case VK_DYNAMIC_STATE_POLYGON_MODE_EXT: return "VK_DYNAMIC_STATE_POLYGON_MODE_EXT";
    case VK_DYNAMIC_STATE_RASTERIZATION_SAMPLES_EXT: return "VK_DYNAMIC_STATE_RASTERIZATION_SAMPLES_EXT";
    case VK_DYNAMIC_STATE_SAMPLE_MASK_EXT: return "VK_DYNAMIC_STATE_SAMPLE_MASK_EXT";
    case VK_DYNAMIC_STATE_ALPHA_TO_COVERAGE_ENABLE_EXT: return "VK_DYNAMIC_STATE_ALPHA_TO_COVERAGE_ENABLE_EXT";
    case VK_DYNAMIC_STATE_ALPHA_TO_ONE_ENABLE_EXT: return "VK_DYNAMIC_STATE_ALPHA_TO_ONE_ENABLE_EXT";
    case VK_DYNAMIC_STATE_LOGIC_OP_ENABLE_EXT: return "VK_DYNAMIC_STATE_LOGIC_OP_ENABLE_EXT";
    case VK_DYNAMIC_STATE_COLOR_BLEND_ENABLE_EXT: return "VK_DYNAMIC_STATE_COLOR_BLEND_ENABLE_EXT";
    case VK_DYNAMIC_STATE_COLOR_BLEND_EQUATION_EXT: return "VK_DYNAMIC_STATE_COLOR_BLEND_EQUATION_EXT";
    case VK_DYNAMIC_STATE_COLOR_WRITE_MASK_EXT: return "VK_DYNAMIC_STATE_COLOR_WRITE_MASK_EXT";
    case VK_DYNAMIC_STATE_TESSELLATION_DOMAIN_ORIGIN_EXT: return "VK_DYNAMIC_STATE_TESSELLATION_DOMAIN_ORIGIN_EXT";
    case VK_DYNAMIC_STATE_RASTERIZATION_STREAM_EXT: return "VK_DYNAMIC_STATE_RASTERIZATION_STREAM_EXT";
    case VK_DYNAMIC_STATE_CONSERVATIVE_RASTERIZATION_MODE_EXT: return "VK_DYNAMIC_STATE_CONSERVATIVE_RASTERIZATION_MODE_EXT";
    case VK_DYNAMIC_STATE_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT: return "VK_DYNAMIC_STATE_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT";
    case VK_DYNAMIC_STATE_DEPTH_CLIP_ENABLE_EXT: return "VK_DYNAMIC_STATE_DEPTH_CLIP_ENABLE_EXT";
    case VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_ENABLE_EXT: return "VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_ENABLE_EXT";
    case VK_DYNAMIC_STATE_COLOR_BLEND_ADVANCED_EXT: return "VK_DYNAMIC_STATE_COLOR_BLEND_ADVANCED_EXT";
    case VK_DYNAMIC_STATE_PROVOKING_VERTEX_MODE_EXT: return "VK_DYNAMIC_STATE_PROVOKING_VERTEX_MODE_EXT";
    case VK_DYNAMIC_STATE_LINE_RASTERIZATION_MODE_EXT: return "VK_DYNAMIC_STATE_LINE_RASTERIZATION_MODE_EXT";
    case VK_DYNAMIC_STATE_LINE_STIPPLE_ENABLE_EXT: return "VK_DYNAMIC_STATE_LINE_STIPPLE_ENABLE_EXT";
    case VK_DYNAMIC_STATE_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT: return "VK_DYNAMIC_STATE_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT";
    case VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_ENABLE_NV: return "VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_ENABLE_NV";
    case VK_DYNAMIC_STATE_VIEWPORT_SWIZZLE_NV: return "VK_DYNAMIC_STATE_VIEWPORT_SWIZZLE_NV";
    case VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_ENABLE_NV: return "VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_ENABLE_NV";
    case VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_LOCATION_NV: return "VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_LOCATION_NV";
    case VK_DYNAMIC_STATE_COVERAGE_MODULATION_MODE_NV: return "VK_DYNAMIC_STATE_COVERAGE_MODULATION_MODE_NV";
    case VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_ENABLE_NV: return "VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_ENABLE_NV";
    case VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_NV: return "VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_NV";
    case VK_DYNAMIC_STATE_SHADING_RATE_IMAGE_ENABLE_NV: return "VK_DYNAMIC_STATE_SHADING_RATE_IMAGE_ENABLE_NV";
    case VK_DYNAMIC_STATE_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV: return "VK_DYNAMIC_STATE_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV";
    case VK_DYNAMIC_STATE_COVERAGE_REDUCTION_MODE_NV: return "VK_DYNAMIC_STATE_COVERAGE_REDUCTION_MODE_NV";
    case VK_DYNAMIC_STATE_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT: return "VK_DYNAMIC_STATE_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT";
    case VK_DYNAMIC_STATE_LINE_STIPPLE_KHR: return "VK_DYNAMIC_STATE_LINE_STIPPLE_KHR";
    case VK_DYNAMIC_STATE_CULL_MODE: return "VK_DYNAMIC_STATE_CULL_MODE";
    case VK_DYNAMIC_STATE_FRONT_FACE: return "VK_DYNAMIC_STATE_FRONT_FACE";
    case VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY: return "VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY";
    case VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT: return "VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT";
    case VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT: return "VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT";
    case VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE: return "VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE";
    case VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE: return "VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE";
    case VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE: return "VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE";
    case VK_DYNAMIC_STATE_DEPTH_COMPARE_OP: return "VK_DYNAMIC_STATE_DEPTH_COMPARE_OP";
    case VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE: return "VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE";
    case VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE: return "VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE";
    case VK_DYNAMIC_STATE_STENCIL_OP: return "VK_DYNAMIC_STATE_STENCIL_OP";
    case VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE: return "VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE";
    case VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE: return "VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE";
    case VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE: return "VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkObjectType v) {
    switch(v) {
    case VK_OBJECT_TYPE_UNKNOWN: return "VK_OBJECT_TYPE_UNKNOWN";
    case VK_OBJECT_TYPE_INSTANCE: return "VK_OBJECT_TYPE_INSTANCE";
    case VK_OBJECT_TYPE_PHYSICAL_DEVICE: return "VK_OBJECT_TYPE_PHYSICAL_DEVICE";
    case VK_OBJECT_TYPE_DEVICE: return "VK_OBJECT_TYPE_DEVICE";
    case VK_OBJECT_TYPE_QUEUE: return "VK_OBJECT_TYPE_QUEUE";
    case VK_OBJECT_TYPE_SEMAPHORE: return "VK_OBJECT_TYPE_SEMAPHORE";
    case VK_OBJECT_TYPE_COMMAND_BUFFER: return "VK_OBJECT_TYPE_COMMAND_BUFFER";
    case VK_OBJECT_TYPE_FENCE: return "VK_OBJECT_TYPE_FENCE";
    case VK_OBJECT_TYPE_DEVICE_MEMORY: return "VK_OBJECT_TYPE_DEVICE_MEMORY";
    case VK_OBJECT_TYPE_BUFFER: return "VK_OBJECT_TYPE_BUFFER";
    case VK_OBJECT_TYPE_IMAGE: return "VK_OBJECT_TYPE_IMAGE";
    case VK_OBJECT_TYPE_EVENT: return "VK_OBJECT_TYPE_EVENT";
    case VK_OBJECT_TYPE_QUERY_POOL: return "VK_OBJECT_TYPE_QUERY_POOL";
    case VK_OBJECT_TYPE_BUFFER_VIEW: return "VK_OBJECT_TYPE_BUFFER_VIEW";
    case VK_OBJECT_TYPE_IMAGE_VIEW: return "VK_OBJECT_TYPE_IMAGE_VIEW";
    case VK_OBJECT_TYPE_SHADER_MODULE: return "VK_OBJECT_TYPE_SHADER_MODULE";
    case VK_OBJECT_TYPE_PIPELINE_CACHE: return "VK_OBJECT_TYPE_PIPELINE_CACHE";
    case VK_OBJECT_TYPE_PIPELINE_LAYOUT: return "VK_OBJECT_TYPE_PIPELINE_LAYOUT";
    case VK_OBJECT_TYPE_RENDER_PASS: return "VK_OBJECT_TYPE_RENDER_PASS";
    case VK_OBJECT_TYPE_PIPELINE: return "VK_OBJECT_TYPE_PIPELINE";
    case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT: return "VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT";
    case VK_OBJECT_TYPE_SAMPLER: return "VK_OBJECT_TYPE_SAMPLER";
    case VK_OBJECT_TYPE_DESCRIPTOR_POOL: return "VK_OBJECT_TYPE_DESCRIPTOR_POOL";
    case VK_OBJECT_TYPE_DESCRIPTOR_SET: return "VK_OBJECT_TYPE_DESCRIPTOR_SET";
    case VK_OBJECT_TYPE_FRAMEBUFFER: return "VK_OBJECT_TYPE_FRAMEBUFFER";
    case VK_OBJECT_TYPE_COMMAND_POOL: return "VK_OBJECT_TYPE_COMMAND_POOL";
    case VK_OBJECT_TYPE_SURFACE_KHR: return "VK_OBJECT_TYPE_SURFACE_KHR";
    case VK_OBJECT_TYPE_SWAPCHAIN_KHR: return "VK_OBJECT_TYPE_SWAPCHAIN_KHR";
    case VK_OBJECT_TYPE_DISPLAY_KHR: return "VK_OBJECT_TYPE_DISPLAY_KHR";
    case VK_OBJECT_TYPE_DISPLAY_MODE_KHR: return "VK_OBJECT_TYPE_DISPLAY_MODE_KHR";
    case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT: return "VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT";
    case VK_OBJECT_TYPE_VIDEO_SESSION_KHR: return "VK_OBJECT_TYPE_VIDEO_SESSION_KHR";
    case VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR: return "VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR";
    case VK_OBJECT_TYPE_CU_MODULE_NVX: return "VK_OBJECT_TYPE_CU_MODULE_NVX";
    case VK_OBJECT_TYPE_CU_FUNCTION_NVX: return "VK_OBJECT_TYPE_CU_FUNCTION_NVX";
    case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT: return "VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT";
    case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR: return "VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR";
    case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT: return "VK_OBJECT_TYPE_VALIDATION_CACHE_EXT";
    case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV: return "VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV";
    case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL: return "VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL";
    case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR: return "VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR";
    case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV: return "VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV";
    case VK_OBJECT_TYPE_CUDA_MODULE_NV: return "VK_OBJECT_TYPE_CUDA_MODULE_NV";
    case VK_OBJECT_TYPE_CUDA_FUNCTION_NV: return "VK_OBJECT_TYPE_CUDA_FUNCTION_NV";
    case VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA: return "VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA";
    case VK_OBJECT_TYPE_MICROMAP_EXT: return "VK_OBJECT_TYPE_MICROMAP_EXT";
    case VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV: return "VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV";
    case VK_OBJECT_TYPE_SHADER_EXT: return "VK_OBJECT_TYPE_SHADER_EXT";
    case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION: return "VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION";
    case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE: return "VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE";
    case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT: return "VK_OBJECT_TYPE_PRIVATE_DATA_SLOT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkQueueFlagBits v) {
    switch(v) {
    case VK_QUEUE_GRAPHICS_BIT: return "VK_QUEUE_GRAPHICS_BIT";
    case VK_QUEUE_COMPUTE_BIT: return "VK_QUEUE_COMPUTE_BIT";
    case VK_QUEUE_TRANSFER_BIT: return "VK_QUEUE_TRANSFER_BIT";
    case VK_QUEUE_SPARSE_BINDING_BIT: return "VK_QUEUE_SPARSE_BINDING_BIT";
    case VK_QUEUE_VIDEO_DECODE_BIT_KHR: return "VK_QUEUE_VIDEO_DECODE_BIT_KHR";
    case VK_QUEUE_VIDEO_ENCODE_BIT_KHR: return "VK_QUEUE_VIDEO_ENCODE_BIT_KHR";
    case VK_QUEUE_OPTICAL_FLOW_BIT_NV: return "VK_QUEUE_OPTICAL_FLOW_BIT_NV";
    case VK_QUEUE_PROTECTED_BIT: return "VK_QUEUE_PROTECTED_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCullModeFlagBits v) {
    switch(v) {
    case VK_CULL_MODE_NONE: return "VK_CULL_MODE_NONE";
    case VK_CULL_MODE_FRONT_BIT: return "VK_CULL_MODE_FRONT_BIT";
    case VK_CULL_MODE_BACK_BIT: return "VK_CULL_MODE_BACK_BIT";
    case VK_CULL_MODE_FRONT_AND_BACK: return "VK_CULL_MODE_FRONT_AND_BACK";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkMemoryPropertyFlagBits v) {
    switch(v) {
    case VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT: return "VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT";
    case VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT: return "VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT";
    case VK_MEMORY_PROPERTY_HOST_COHERENT_BIT: return "VK_MEMORY_PROPERTY_HOST_COHERENT_BIT";
    case VK_MEMORY_PROPERTY_HOST_CACHED_BIT: return "VK_MEMORY_PROPERTY_HOST_CACHED_BIT";
    case VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT: return "VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT";
    case VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD: return "VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD";
    case VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD: return "VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD";
    case VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV: return "VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV";
    case VK_MEMORY_PROPERTY_PROTECTED_BIT: return "VK_MEMORY_PROPERTY_PROTECTED_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkMemoryHeapFlagBits v) {
    switch(v) {
    case VK_MEMORY_HEAP_DEVICE_LOCAL_BIT: return "VK_MEMORY_HEAP_DEVICE_LOCAL_BIT";
    case VK_MEMORY_HEAP_MULTI_INSTANCE_BIT: return "VK_MEMORY_HEAP_MULTI_INSTANCE_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkAccessFlagBits v) {
    switch(v) {
    case VK_ACCESS_INDIRECT_COMMAND_READ_BIT: return "VK_ACCESS_INDIRECT_COMMAND_READ_BIT";
    case VK_ACCESS_INDEX_READ_BIT: return "VK_ACCESS_INDEX_READ_BIT";
    case VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT: return "VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT";
    case VK_ACCESS_UNIFORM_READ_BIT: return "VK_ACCESS_UNIFORM_READ_BIT";
    case VK_ACCESS_INPUT_ATTACHMENT_READ_BIT: return "VK_ACCESS_INPUT_ATTACHMENT_READ_BIT";
    case VK_ACCESS_SHADER_READ_BIT: return "VK_ACCESS_SHADER_READ_BIT";
    case VK_ACCESS_SHADER_WRITE_BIT: return "VK_ACCESS_SHADER_WRITE_BIT";
    case VK_ACCESS_COLOR_ATTACHMENT_READ_BIT: return "VK_ACCESS_COLOR_ATTACHMENT_READ_BIT";
    case VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT: return "VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT";
    case VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT: return "VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT";
    case VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT: return "VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT";
    case VK_ACCESS_TRANSFER_READ_BIT: return "VK_ACCESS_TRANSFER_READ_BIT";
    case VK_ACCESS_TRANSFER_WRITE_BIT: return "VK_ACCESS_TRANSFER_WRITE_BIT";
    case VK_ACCESS_HOST_READ_BIT: return "VK_ACCESS_HOST_READ_BIT";
    case VK_ACCESS_HOST_WRITE_BIT: return "VK_ACCESS_HOST_WRITE_BIT";
    case VK_ACCESS_MEMORY_READ_BIT: return "VK_ACCESS_MEMORY_READ_BIT";
    case VK_ACCESS_MEMORY_WRITE_BIT: return "VK_ACCESS_MEMORY_WRITE_BIT";
    case VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT: return "VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT";
    case VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT: return "VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT";
    case VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT: return "VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT";
    case VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT: return "VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT";
    case VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT: return "VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT";
    case VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR: return "VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR";
    case VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR: return "VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR";
    case VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT: return "VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT";
    case VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR: return "VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR";
    case VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV: return "VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV";
    case VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV: return "VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV";
    case VK_ACCESS_NONE: return "VK_ACCESS_NONE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBufferUsageFlagBits v) {
    switch(v) {
    case VK_BUFFER_USAGE_TRANSFER_SRC_BIT: return "VK_BUFFER_USAGE_TRANSFER_SRC_BIT";
    case VK_BUFFER_USAGE_TRANSFER_DST_BIT: return "VK_BUFFER_USAGE_TRANSFER_DST_BIT";
    case VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT: return "VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT";
    case VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT: return "VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT";
    case VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT: return "VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT";
    case VK_BUFFER_USAGE_STORAGE_BUFFER_BIT: return "VK_BUFFER_USAGE_STORAGE_BUFFER_BIT";
    case VK_BUFFER_USAGE_INDEX_BUFFER_BIT: return "VK_BUFFER_USAGE_INDEX_BUFFER_BIT";
    case VK_BUFFER_USAGE_VERTEX_BUFFER_BIT: return "VK_BUFFER_USAGE_VERTEX_BUFFER_BIT";
    case VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT: return "VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT";
    case VK_BUFFER_USAGE_VIDEO_DECODE_SRC_BIT_KHR: return "VK_BUFFER_USAGE_VIDEO_DECODE_SRC_BIT_KHR";
    case VK_BUFFER_USAGE_VIDEO_DECODE_DST_BIT_KHR: return "VK_BUFFER_USAGE_VIDEO_DECODE_DST_BIT_KHR";
    case VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT: return "VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT";
    case VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT: return "VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT";
    case VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT: return "VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT";
    case VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR: return "VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR";
    case VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR: return "VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR";
    case VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR: return "VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR";
    case VK_BUFFER_USAGE_VIDEO_ENCODE_DST_BIT_KHR: return "VK_BUFFER_USAGE_VIDEO_ENCODE_DST_BIT_KHR";
    case VK_BUFFER_USAGE_VIDEO_ENCODE_SRC_BIT_KHR: return "VK_BUFFER_USAGE_VIDEO_ENCODE_SRC_BIT_KHR";
    case VK_BUFFER_USAGE_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT: return "VK_BUFFER_USAGE_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT";
    case VK_BUFFER_USAGE_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT: return "VK_BUFFER_USAGE_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT";
    case VK_BUFFER_USAGE_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT: return "VK_BUFFER_USAGE_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT";
    case VK_BUFFER_USAGE_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT: return "VK_BUFFER_USAGE_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT";
    case VK_BUFFER_USAGE_MICROMAP_STORAGE_BIT_EXT: return "VK_BUFFER_USAGE_MICROMAP_STORAGE_BIT_EXT";
    case VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT: return "VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkBufferCreateFlagBits v) {
    switch(v) {
    case VK_BUFFER_CREATE_SPARSE_BINDING_BIT: return "VK_BUFFER_CREATE_SPARSE_BINDING_BIT";
    case VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT: return "VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT";
    case VK_BUFFER_CREATE_SPARSE_ALIASED_BIT: return "VK_BUFFER_CREATE_SPARSE_ALIASED_BIT";
    case VK_BUFFER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT: return "VK_BUFFER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT";
    case VK_BUFFER_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR: return "VK_BUFFER_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR";
    case VK_BUFFER_CREATE_PROTECTED_BIT: return "VK_BUFFER_CREATE_PROTECTED_BIT";
    case VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT: return "VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkShaderStageFlagBits v) {
    switch(v) {
    case VK_SHADER_STAGE_VERTEX_BIT: return "VK_SHADER_STAGE_VERTEX_BIT";
    case VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT: return "VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT";
    case VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT: return "VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT";
    case VK_SHADER_STAGE_GEOMETRY_BIT: return "VK_SHADER_STAGE_GEOMETRY_BIT";
    case VK_SHADER_STAGE_FRAGMENT_BIT: return "VK_SHADER_STAGE_FRAGMENT_BIT";
    case VK_SHADER_STAGE_COMPUTE_BIT: return "VK_SHADER_STAGE_COMPUTE_BIT";
    case VK_SHADER_STAGE_ALL_GRAPHICS: return "VK_SHADER_STAGE_ALL_GRAPHICS";
    case VK_SHADER_STAGE_ALL: return "VK_SHADER_STAGE_ALL";
    case VK_SHADER_STAGE_RAYGEN_BIT_KHR: return "VK_SHADER_STAGE_RAYGEN_BIT_KHR";
    case VK_SHADER_STAGE_ANY_HIT_BIT_KHR: return "VK_SHADER_STAGE_ANY_HIT_BIT_KHR";
    case VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR: return "VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR";
    case VK_SHADER_STAGE_MISS_BIT_KHR: return "VK_SHADER_STAGE_MISS_BIT_KHR";
    case VK_SHADER_STAGE_INTERSECTION_BIT_KHR: return "VK_SHADER_STAGE_INTERSECTION_BIT_KHR";
    case VK_SHADER_STAGE_CALLABLE_BIT_KHR: return "VK_SHADER_STAGE_CALLABLE_BIT_KHR";
    case VK_SHADER_STAGE_TASK_BIT_EXT: return "VK_SHADER_STAGE_TASK_BIT_EXT";
    case VK_SHADER_STAGE_MESH_BIT_EXT: return "VK_SHADER_STAGE_MESH_BIT_EXT";
    case VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI: return "VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI";
    case VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI: return "VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkImageUsageFlagBits v) {
    switch(v) {
    case VK_IMAGE_USAGE_TRANSFER_SRC_BIT: return "VK_IMAGE_USAGE_TRANSFER_SRC_BIT";
    case VK_IMAGE_USAGE_TRANSFER_DST_BIT: return "VK_IMAGE_USAGE_TRANSFER_DST_BIT";
    case VK_IMAGE_USAGE_SAMPLED_BIT: return "VK_IMAGE_USAGE_SAMPLED_BIT";
    case VK_IMAGE_USAGE_STORAGE_BIT: return "VK_IMAGE_USAGE_STORAGE_BIT";
    case VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT: return "VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT";
    case VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT: return "VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT";
    case VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT: return "VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT";
    case VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT: return "VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT";
    case VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR: return "VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR";
    case VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR: return "VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR";
    case VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR: return "VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR";
    case VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT: return "VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT";
    case VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR: return "VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT: return "VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT";
    case VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR: return "VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR";
    case VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR: return "VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR";
    case VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR: return "VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR";
    case VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT: return "VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
    case VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI: return "VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI";
    case VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM: return "VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM";
    case VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM: return "VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkImageCreateFlagBits v) {
    switch(v) {
    case VK_IMAGE_CREATE_SPARSE_BINDING_BIT: return "VK_IMAGE_CREATE_SPARSE_BINDING_BIT";
    case VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT: return "VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT";
    case VK_IMAGE_CREATE_SPARSE_ALIASED_BIT: return "VK_IMAGE_CREATE_SPARSE_ALIASED_BIT";
    case VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT: return "VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT";
    case VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT: return "VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT";
    case VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV: return "VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV";
    case VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT: return "VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT";
    case VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT: return "VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT";
    case VK_IMAGE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT: return "VK_IMAGE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT";
    case VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT: return "VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT";
    case VK_IMAGE_CREATE_2D_VIEW_COMPATIBLE_BIT_EXT: return "VK_IMAGE_CREATE_2D_VIEW_COMPATIBLE_BIT_EXT";
    case VK_IMAGE_CREATE_FRAGMENT_DENSITY_MAP_OFFSET_BIT_QCOM: return "VK_IMAGE_CREATE_FRAGMENT_DENSITY_MAP_OFFSET_BIT_QCOM";
    case VK_IMAGE_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR: return "VK_IMAGE_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR";
    case VK_IMAGE_CREATE_ALIAS_BIT: return "VK_IMAGE_CREATE_ALIAS_BIT";
    case VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT: return "VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT";
    case VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT: return "VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT";
    case VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT: return "VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT";
    case VK_IMAGE_CREATE_EXTENDED_USAGE_BIT: return "VK_IMAGE_CREATE_EXTENDED_USAGE_BIT";
    case VK_IMAGE_CREATE_PROTECTED_BIT: return "VK_IMAGE_CREATE_PROTECTED_BIT";
    case VK_IMAGE_CREATE_DISJOINT_BIT: return "VK_IMAGE_CREATE_DISJOINT_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPipelineCreateFlagBits v) {
    switch(v) {
    case VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT: return "VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT";
    case VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT: return "VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT";
    case VK_PIPELINE_CREATE_DERIVATIVE_BIT: return "VK_PIPELINE_CREATE_DERIVATIVE_BIT";
    case VK_PIPELINE_CREATE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR: return "VK_PIPELINE_CREATE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case VK_PIPELINE_CREATE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT: return "VK_PIPELINE_CREATE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT";
    case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR: return "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR";
    case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR: return "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR";
    case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR: return "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR";
    case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR: return "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR";
    case VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR: return "VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR";
    case VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR: return "VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR";
    case VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR: return "VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR";
    case VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV: return "VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV";
    case VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR: return "VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR";
    case VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR: return "VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR";
    case VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV: return "VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV";
    case VK_PIPELINE_CREATE_LIBRARY_BIT_KHR: return "VK_PIPELINE_CREATE_LIBRARY_BIT_KHR";
    case VK_PIPELINE_CREATE_DESCRIPTOR_BUFFER_BIT_EXT: return "VK_PIPELINE_CREATE_DESCRIPTOR_BUFFER_BIT_EXT";
    case VK_PIPELINE_CREATE_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT: return "VK_PIPELINE_CREATE_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT";
    case VK_PIPELINE_CREATE_LINK_TIME_OPTIMIZATION_BIT_EXT: return "VK_PIPELINE_CREATE_LINK_TIME_OPTIMIZATION_BIT_EXT";
    case VK_PIPELINE_CREATE_RAY_TRACING_ALLOW_MOTION_BIT_NV: return "VK_PIPELINE_CREATE_RAY_TRACING_ALLOW_MOTION_BIT_NV";
    case VK_PIPELINE_CREATE_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT: return "VK_PIPELINE_CREATE_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
    case VK_PIPELINE_CREATE_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT: return "VK_PIPELINE_CREATE_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
    case VK_PIPELINE_CREATE_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT: return "VK_PIPELINE_CREATE_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT";
    case VK_PIPELINE_CREATE_NO_PROTECTED_ACCESS_BIT_EXT: return "VK_PIPELINE_CREATE_NO_PROTECTED_ACCESS_BIT_EXT";
    case VK_PIPELINE_CREATE_PROTECTED_ACCESS_ONLY_BIT_EXT: return "VK_PIPELINE_CREATE_PROTECTED_ACCESS_ONLY_BIT_EXT";
    case VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT: return "VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT";
    case VK_PIPELINE_CREATE_DISPATCH_BASE_BIT: return "VK_PIPELINE_CREATE_DISPATCH_BASE_BIT";
    case VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT: return "VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT";
    case VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT: return "VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkColorComponentFlagBits v) {
    switch(v) {
    case VK_COLOR_COMPONENT_R_BIT: return "VK_COLOR_COMPONENT_R_BIT";
    case VK_COLOR_COMPONENT_G_BIT: return "VK_COLOR_COMPONENT_G_BIT";
    case VK_COLOR_COMPONENT_B_BIT: return "VK_COLOR_COMPONENT_B_BIT";
    case VK_COLOR_COMPONENT_A_BIT: return "VK_COLOR_COMPONENT_A_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkFenceCreateFlagBits v) {
    switch(v) {
    case VK_FENCE_CREATE_SIGNALED_BIT: return "VK_FENCE_CREATE_SIGNALED_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkFormatFeatureFlagBits v) {
    switch(v) {
    case VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT: return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT";
    case VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT: return "VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT";
    case VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT: return "VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT";
    case VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT: return "VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT";
    case VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT: return "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT";
    case VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT: return "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT";
    case VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT: return "VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT";
    case VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT: return "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT";
    case VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT: return "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT";
    case VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT: return "VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT";
    case VK_FORMAT_FEATURE_BLIT_SRC_BIT: return "VK_FORMAT_FEATURE_BLIT_SRC_BIT";
    case VK_FORMAT_FEATURE_BLIT_DST_BIT: return "VK_FORMAT_FEATURE_BLIT_DST_BIT";
    case VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT: return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT";
    case VK_FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR: return "VK_FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR";
    case VK_FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR: return "VK_FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR";
    case VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR: return "VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR";
    case VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT: return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT";
    case VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT: return "VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT";
    case VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR: return "VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case VK_FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR: return "VK_FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR";
    case VK_FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR: return "VK_FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR";
    case VK_FORMAT_FEATURE_TRANSFER_SRC_BIT: return "VK_FORMAT_FEATURE_TRANSFER_SRC_BIT";
    case VK_FORMAT_FEATURE_TRANSFER_DST_BIT: return "VK_FORMAT_FEATURE_TRANSFER_DST_BIT";
    case VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT: return "VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT";
    case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT: return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT";
    case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT: return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT";
    case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT: return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT";
    case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT: return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT";
    case VK_FORMAT_FEATURE_DISJOINT_BIT: return "VK_FORMAT_FEATURE_DISJOINT_BIT";
    case VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT: return "VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT";
    case VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT: return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkQueryControlFlagBits v) {
    switch(v) {
    case VK_QUERY_CONTROL_PRECISE_BIT: return "VK_QUERY_CONTROL_PRECISE_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkQueryResultFlagBits v) {
    switch(v) {
    case VK_QUERY_RESULT_64_BIT: return "VK_QUERY_RESULT_64_BIT";
    case VK_QUERY_RESULT_WAIT_BIT: return "VK_QUERY_RESULT_WAIT_BIT";
    case VK_QUERY_RESULT_WITH_AVAILABILITY_BIT: return "VK_QUERY_RESULT_WITH_AVAILABILITY_BIT";
    case VK_QUERY_RESULT_PARTIAL_BIT: return "VK_QUERY_RESULT_PARTIAL_BIT";
    case VK_QUERY_RESULT_WITH_STATUS_BIT_KHR: return "VK_QUERY_RESULT_WITH_STATUS_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCommandBufferUsageFlagBits v) {
    switch(v) {
    case VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT: return "VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT";
    case VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT: return "VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT";
    case VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT: return "VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkQueryPipelineStatisticFlagBits v) {
    switch(v) {
    case VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT: return "VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT: return "VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT: return "VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT: return "VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT: return "VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT: return "VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT: return "VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT: return "VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT: return "VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT: return "VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT: return "VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT";
    case VK_QUERY_PIPELINE_STATISTIC_TASK_SHADER_INVOCATIONS_BIT_EXT: return "VK_QUERY_PIPELINE_STATISTIC_TASK_SHADER_INVOCATIONS_BIT_EXT";
    case VK_QUERY_PIPELINE_STATISTIC_MESH_SHADER_INVOCATIONS_BIT_EXT: return "VK_QUERY_PIPELINE_STATISTIC_MESH_SHADER_INVOCATIONS_BIT_EXT";
    case VK_QUERY_PIPELINE_STATISTIC_CLUSTER_CULLING_SHADER_INVOCATIONS_BIT_HUAWEI: return "VK_QUERY_PIPELINE_STATISTIC_CLUSTER_CULLING_SHADER_INVOCATIONS_BIT_HUAWEI";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkImageAspectFlagBits v) {
    switch(v) {
    case VK_IMAGE_ASPECT_COLOR_BIT: return "VK_IMAGE_ASPECT_COLOR_BIT";
    case VK_IMAGE_ASPECT_DEPTH_BIT: return "VK_IMAGE_ASPECT_DEPTH_BIT";
    case VK_IMAGE_ASPECT_STENCIL_BIT: return "VK_IMAGE_ASPECT_STENCIL_BIT";
    case VK_IMAGE_ASPECT_METADATA_BIT: return "VK_IMAGE_ASPECT_METADATA_BIT";
    case VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT: return "VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT";
    case VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT: return "VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT";
    case VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT: return "VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT";
    case VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT: return "VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT";
    case VK_IMAGE_ASPECT_PLANE_0_BIT: return "VK_IMAGE_ASPECT_PLANE_0_BIT";
    case VK_IMAGE_ASPECT_PLANE_1_BIT: return "VK_IMAGE_ASPECT_PLANE_1_BIT";
    case VK_IMAGE_ASPECT_PLANE_2_BIT: return "VK_IMAGE_ASPECT_PLANE_2_BIT";
    case VK_IMAGE_ASPECT_NONE: return "VK_IMAGE_ASPECT_NONE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSparseImageFormatFlagBits v) {
    switch(v) {
    case VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT: return "VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT";
    case VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT: return "VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT";
    case VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT: return "VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSparseMemoryBindFlagBits v) {
    switch(v) {
    case VK_SPARSE_MEMORY_BIND_METADATA_BIT: return "VK_SPARSE_MEMORY_BIND_METADATA_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPipelineStageFlagBits v) {
    switch(v) {
    case VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT: return "VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT";
    case VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT: return "VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT";
    case VK_PIPELINE_STAGE_VERTEX_INPUT_BIT: return "VK_PIPELINE_STAGE_VERTEX_INPUT_BIT";
    case VK_PIPELINE_STAGE_VERTEX_SHADER_BIT: return "VK_PIPELINE_STAGE_VERTEX_SHADER_BIT";
    case VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT: return "VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT";
    case VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT: return "VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT";
    case VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT: return "VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT";
    case VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT: return "VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT";
    case VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT: return "VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT";
    case VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT: return "VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT";
    case VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT: return "VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT";
    case VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT: return "VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT";
    case VK_PIPELINE_STAGE_TRANSFER_BIT: return "VK_PIPELINE_STAGE_TRANSFER_BIT";
    case VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT: return "VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT";
    case VK_PIPELINE_STAGE_HOST_BIT: return "VK_PIPELINE_STAGE_HOST_BIT";
    case VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT: return "VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT";
    case VK_PIPELINE_STAGE_ALL_COMMANDS_BIT: return "VK_PIPELINE_STAGE_ALL_COMMANDS_BIT";
    case VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT: return "VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT";
    case VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT: return "VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT";
    case VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR: return "VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR";
    case VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR: return "VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR";
    case VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT: return "VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT";
    case VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR: return "VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV: return "VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV";
    case VK_PIPELINE_STAGE_TASK_SHADER_BIT_EXT: return "VK_PIPELINE_STAGE_TASK_SHADER_BIT_EXT";
    case VK_PIPELINE_STAGE_MESH_SHADER_BIT_EXT: return "VK_PIPELINE_STAGE_MESH_SHADER_BIT_EXT";
    case VK_PIPELINE_STAGE_NONE: return "VK_PIPELINE_STAGE_NONE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCommandPoolCreateFlagBits v) {
    switch(v) {
    case VK_COMMAND_POOL_CREATE_TRANSIENT_BIT: return "VK_COMMAND_POOL_CREATE_TRANSIENT_BIT";
    case VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT: return "VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT";
    case VK_COMMAND_POOL_CREATE_PROTECTED_BIT: return "VK_COMMAND_POOL_CREATE_PROTECTED_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCommandPoolResetFlagBits v) {
    switch(v) {
    case VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT: return "VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkCommandBufferResetFlagBits v) {
    switch(v) {
    case VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT: return "VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSampleCountFlagBits v) {
    switch(v) {
    case VK_SAMPLE_COUNT_1_BIT: return "VK_SAMPLE_COUNT_1_BIT";
    case VK_SAMPLE_COUNT_2_BIT: return "VK_SAMPLE_COUNT_2_BIT";
    case VK_SAMPLE_COUNT_4_BIT: return "VK_SAMPLE_COUNT_4_BIT";
    case VK_SAMPLE_COUNT_8_BIT: return "VK_SAMPLE_COUNT_8_BIT";
    case VK_SAMPLE_COUNT_16_BIT: return "VK_SAMPLE_COUNT_16_BIT";
    case VK_SAMPLE_COUNT_32_BIT: return "VK_SAMPLE_COUNT_32_BIT";
    case VK_SAMPLE_COUNT_64_BIT: return "VK_SAMPLE_COUNT_64_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkAttachmentDescriptionFlagBits v) {
    switch(v) {
    case VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT: return "VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkStencilFaceFlagBits v) {
    switch(v) {
    case VK_STENCIL_FACE_FRONT_BIT: return "VK_STENCIL_FACE_FRONT_BIT";
    case VK_STENCIL_FACE_BACK_BIT: return "VK_STENCIL_FACE_BACK_BIT";
    case VK_STENCIL_FACE_FRONT_AND_BACK: return "VK_STENCIL_FACE_FRONT_AND_BACK";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDescriptorPoolCreateFlagBits v) {
    switch(v) {
    case VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT: return "VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT";
    case VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_EXT: return "VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_EXT";
    case VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_SETS_BIT_NV: return "VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_SETS_BIT_NV";
    case VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_POOLS_BIT_NV: return "VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_POOLS_BIT_NV";
    case VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT: return "VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDependencyFlagBits v) {
    switch(v) {
    case VK_DEPENDENCY_BY_REGION_BIT: return "VK_DEPENDENCY_BY_REGION_BIT";
    case VK_DEPENDENCY_FEEDBACK_LOOP_BIT_EXT: return "VK_DEPENDENCY_FEEDBACK_LOOP_BIT_EXT";
    case VK_DEPENDENCY_DEVICE_GROUP_BIT: return "VK_DEPENDENCY_DEVICE_GROUP_BIT";
    case VK_DEPENDENCY_VIEW_LOCAL_BIT: return "VK_DEPENDENCY_VIEW_LOCAL_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkVendorId v) {
    switch(v) {
    case VK_VENDOR_ID_VIV: return "VK_VENDOR_ID_VIV";
    case VK_VENDOR_ID_VSI: return "VK_VENDOR_ID_VSI";
    case VK_VENDOR_ID_KAZAN: return "VK_VENDOR_ID_KAZAN";
    case VK_VENDOR_ID_CODEPLAY: return "VK_VENDOR_ID_CODEPLAY";
    case VK_VENDOR_ID_MESA: return "VK_VENDOR_ID_MESA";
    case VK_VENDOR_ID_POCL: return "VK_VENDOR_ID_POCL";
    case VK_VENDOR_ID_MOBILEYE: return "VK_VENDOR_ID_MOBILEYE";
    default: break;
    }
    return nullptr;
  }
#endif // VK_VERSION_1_0
#if defined(VK_VERSION_1_1)
  VKU_IMPL const char* to_string(const VkDescriptorUpdateTemplateType v) {
    switch(v) {
    case VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET: return "VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET";
    case VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS_KHR: return "VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSubgroupFeatureFlagBits v) {
    switch(v) {
    case VK_SUBGROUP_FEATURE_BASIC_BIT: return "VK_SUBGROUP_FEATURE_BASIC_BIT";
    case VK_SUBGROUP_FEATURE_VOTE_BIT: return "VK_SUBGROUP_FEATURE_VOTE_BIT";
    case VK_SUBGROUP_FEATURE_ARITHMETIC_BIT: return "VK_SUBGROUP_FEATURE_ARITHMETIC_BIT";
    case VK_SUBGROUP_FEATURE_BALLOT_BIT: return "VK_SUBGROUP_FEATURE_BALLOT_BIT";
    case VK_SUBGROUP_FEATURE_SHUFFLE_BIT: return "VK_SUBGROUP_FEATURE_SHUFFLE_BIT";
    case VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT: return "VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT";
    case VK_SUBGROUP_FEATURE_CLUSTERED_BIT: return "VK_SUBGROUP_FEATURE_CLUSTERED_BIT";
    case VK_SUBGROUP_FEATURE_QUAD_BIT: return "VK_SUBGROUP_FEATURE_QUAD_BIT";
    case VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV: return "VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV";
    case VK_SUBGROUP_FEATURE_ROTATE_BIT_KHR: return "VK_SUBGROUP_FEATURE_ROTATE_BIT_KHR";
    case VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT_KHR: return "VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT_KHR";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkExternalMemoryHandleTypeFlagBits v) {
    switch(v) {
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_RDMA_ADDRESS_BIT_NV: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_RDMA_ADDRESS_BIT_NV";
    case VK_EXTERNAL_MEMORY_HANDLE_TYPE_SCREEN_BUFFER_BIT_QNX: return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_SCREEN_BUFFER_BIT_QNX";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkExternalMemoryFeatureFlagBits v) {
    switch(v) {
    case VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT: return "VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT";
    case VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT: return "VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT";
    case VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT: return "VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkExternalSemaphoreHandleTypeFlagBits v) {
    switch(v) {
    case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT: return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT";
    case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT: return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT";
    case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT: return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT";
    case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT: return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT";
    case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT: return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT";
    case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA: return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkExternalSemaphoreFeatureFlagBits v) {
    switch(v) {
    case VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT: return "VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT";
    case VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT: return "VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSemaphoreImportFlagBits v) {
    switch(v) {
    case VK_SEMAPHORE_IMPORT_TEMPORARY_BIT: return "VK_SEMAPHORE_IMPORT_TEMPORARY_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkExternalFenceHandleTypeFlagBits v) {
    switch(v) {
    case VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT: return "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT";
    case VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT: return "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT";
    case VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT: return "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT";
    case VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT: return "VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkExternalFenceFeatureFlagBits v) {
    switch(v) {
    case VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT: return "VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT";
    case VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT: return "VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkFenceImportFlagBits v) {
    switch(v) {
    case VK_FENCE_IMPORT_TEMPORARY_BIT: return "VK_FENCE_IMPORT_TEMPORARY_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPeerMemoryFeatureFlagBits v) {
    switch(v) {
    case VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT: return "VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT";
    case VK_PEER_MEMORY_FEATURE_COPY_DST_BIT: return "VK_PEER_MEMORY_FEATURE_COPY_DST_BIT";
    case VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT: return "VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT";
    case VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT: return "VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkMemoryAllocateFlagBits v) {
    switch(v) {
    case VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT: return "VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT";
    case VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT: return "VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT";
    case VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT: return "VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkPointClippingBehavior v) {
    switch(v) {
    case VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES: return "VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES";
    case VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY: return "VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkTessellationDomainOrigin v) {
    switch(v) {
    case VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT: return "VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT";
    case VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT: return "VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSamplerYcbcrModelConversion v) {
    switch(v) {
    case VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY";
    case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY";
    case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709";
    case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601";
    case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSamplerYcbcrRange v) {
    switch(v) {
    case VK_SAMPLER_YCBCR_RANGE_ITU_FULL: return "VK_SAMPLER_YCBCR_RANGE_ITU_FULL";
    case VK_SAMPLER_YCBCR_RANGE_ITU_NARROW: return "VK_SAMPLER_YCBCR_RANGE_ITU_NARROW";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkChromaLocation v) {
    switch(v) {
    case VK_CHROMA_LOCATION_COSITED_EVEN: return "VK_CHROMA_LOCATION_COSITED_EVEN";
    case VK_CHROMA_LOCATION_MIDPOINT: return "VK_CHROMA_LOCATION_MIDPOINT";
    default: break;
    }
    return nullptr;
  }
#endif // VK_VERSION_1_1
#if defined(VK_VERSION_1_2)
  VKU_IMPL const char* to_string(const VkSemaphoreType v) {
    switch(v) {
    case VK_SEMAPHORE_TYPE_BINARY: return "VK_SEMAPHORE_TYPE_BINARY";
    case VK_SEMAPHORE_TYPE_TIMELINE: return "VK_SEMAPHORE_TYPE_TIMELINE";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSemaphoreWaitFlagBits v) {
    switch(v) {
    case VK_SEMAPHORE_WAIT_ANY_BIT: return "VK_SEMAPHORE_WAIT_ANY_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSamplerReductionMode v) {
    switch(v) {
    case VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE: return "VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE";
    case VK_SAMPLER_REDUCTION_MODE_MIN: return "VK_SAMPLER_REDUCTION_MODE_MIN";
    case VK_SAMPLER_REDUCTION_MODE_MAX: return "VK_SAMPLER_REDUCTION_MODE_MAX";
    case VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_RANGECLAMP_QCOM: return "VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_RANGECLAMP_QCOM";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDescriptorBindingFlagBits v) {
    switch(v) {
    case VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT: return "VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT";
    case VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT: return "VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT";
    case VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT: return "VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT";
    case VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT: return "VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkDriverId v) {
    switch(v) {
    case VK_DRIVER_ID_AMD_PROPRIETARY: return "VK_DRIVER_ID_AMD_PROPRIETARY";
    case VK_DRIVER_ID_AMD_OPEN_SOURCE: return "VK_DRIVER_ID_AMD_OPEN_SOURCE";
    case VK_DRIVER_ID_MESA_RADV: return "VK_DRIVER_ID_MESA_RADV";
    case VK_DRIVER_ID_NVIDIA_PROPRIETARY: return "VK_DRIVER_ID_NVIDIA_PROPRIETARY";
    case VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS: return "VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS";
    case VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA: return "VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA";
    case VK_DRIVER_ID_IMAGINATION_PROPRIETARY: return "VK_DRIVER_ID_IMAGINATION_PROPRIETARY";
    case VK_DRIVER_ID_QUALCOMM_PROPRIETARY: return "VK_DRIVER_ID_QUALCOMM_PROPRIETARY";
    case VK_DRIVER_ID_ARM_PROPRIETARY: return "VK_DRIVER_ID_ARM_PROPRIETARY";
    case VK_DRIVER_ID_GOOGLE_SWIFTSHADER: return "VK_DRIVER_ID_GOOGLE_SWIFTSHADER";
    case VK_DRIVER_ID_GGP_PROPRIETARY: return "VK_DRIVER_ID_GGP_PROPRIETARY";
    case VK_DRIVER_ID_BROADCOM_PROPRIETARY: return "VK_DRIVER_ID_BROADCOM_PROPRIETARY";
    case VK_DRIVER_ID_MESA_LLVMPIPE: return "VK_DRIVER_ID_MESA_LLVMPIPE";
    case VK_DRIVER_ID_MOLTENVK: return "VK_DRIVER_ID_MOLTENVK";
    case VK_DRIVER_ID_COREAVI_PROPRIETARY: return "VK_DRIVER_ID_COREAVI_PROPRIETARY";
    case VK_DRIVER_ID_JUICE_PROPRIETARY: return "VK_DRIVER_ID_JUICE_PROPRIETARY";
    case VK_DRIVER_ID_VERISILICON_PROPRIETARY: return "VK_DRIVER_ID_VERISILICON_PROPRIETARY";
    case VK_DRIVER_ID_MESA_TURNIP: return "VK_DRIVER_ID_MESA_TURNIP";
    case VK_DRIVER_ID_MESA_V3DV: return "VK_DRIVER_ID_MESA_V3DV";
    case VK_DRIVER_ID_MESA_PANVK: return "VK_DRIVER_ID_MESA_PANVK";
    case VK_DRIVER_ID_SAMSUNG_PROPRIETARY: return "VK_DRIVER_ID_SAMSUNG_PROPRIETARY";
    case VK_DRIVER_ID_MESA_VENUS: return "VK_DRIVER_ID_MESA_VENUS";
    case VK_DRIVER_ID_MESA_DOZEN: return "VK_DRIVER_ID_MESA_DOZEN";
    case VK_DRIVER_ID_MESA_NVK: return "VK_DRIVER_ID_MESA_NVK";
    case VK_DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA: return "VK_DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA";
    case VK_DRIVER_ID_MESA_AGXV: return "VK_DRIVER_ID_MESA_AGXV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkResolveModeFlagBits v) {
    switch(v) {
    case VK_RESOLVE_MODE_NONE: return "VK_RESOLVE_MODE_NONE";
    case VK_RESOLVE_MODE_SAMPLE_ZERO_BIT: return "VK_RESOLVE_MODE_SAMPLE_ZERO_BIT";
    case VK_RESOLVE_MODE_AVERAGE_BIT: return "VK_RESOLVE_MODE_AVERAGE_BIT";
    case VK_RESOLVE_MODE_MIN_BIT: return "VK_RESOLVE_MODE_MIN_BIT";
    case VK_RESOLVE_MODE_MAX_BIT: return "VK_RESOLVE_MODE_MAX_BIT";
    case VK_RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_ANDROID: return "VK_RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_ANDROID";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkShaderFloatControlsIndependence v) {
    switch(v) {
    case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY: return "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY";
    case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL: return "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL";
    case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE: return "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE";
    default: break;
    }
    return nullptr;
  }
#endif // VK_VERSION_1_2
#if defined(VK_VERSION_1_3)
  VKU_IMPL const char* to_string(const VkPipelineCreationFeedbackFlagBits v) {
    switch(v) {
    case VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT: return "VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT";
    case VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT: return "VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT";
    case VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT: return "VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkToolPurposeFlagBits v) {
    switch(v) {
    case VK_TOOL_PURPOSE_VALIDATION_BIT: return "VK_TOOL_PURPOSE_VALIDATION_BIT";
    case VK_TOOL_PURPOSE_PROFILING_BIT: return "VK_TOOL_PURPOSE_PROFILING_BIT";
    case VK_TOOL_PURPOSE_TRACING_BIT: return "VK_TOOL_PURPOSE_TRACING_BIT";
    case VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT: return "VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT";
    case VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT: return "VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT";
    case VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT: return "VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT";
    case VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT: return "VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
  // VkAccessFlagBits2 is type aliased. its to_string() must have a unique name.
  VKU_IMPL const char* access_flag_bits2_to_string(const VkAccessFlagBits2 v) {
    switch(v) {
    case VK_ACCESS_2_NONE: return "VK_ACCESS_2_NONE";
    case VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT: return "VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT";
    case VK_ACCESS_2_INDEX_READ_BIT: return "VK_ACCESS_2_INDEX_READ_BIT";
    case VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT: return "VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT";
    case VK_ACCESS_2_UNIFORM_READ_BIT: return "VK_ACCESS_2_UNIFORM_READ_BIT";
    case VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT: return "VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT";
    case VK_ACCESS_2_SHADER_READ_BIT: return "VK_ACCESS_2_SHADER_READ_BIT";
    case VK_ACCESS_2_SHADER_WRITE_BIT: return "VK_ACCESS_2_SHADER_WRITE_BIT";
    case VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT: return "VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT";
    case VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT: return "VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT";
    case VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT: return "VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT";
    case VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT: return "VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT";
    case VK_ACCESS_2_TRANSFER_READ_BIT: return "VK_ACCESS_2_TRANSFER_READ_BIT";
    case VK_ACCESS_2_TRANSFER_WRITE_BIT: return "VK_ACCESS_2_TRANSFER_WRITE_BIT";
    case VK_ACCESS_2_HOST_READ_BIT: return "VK_ACCESS_2_HOST_READ_BIT";
    case VK_ACCESS_2_HOST_WRITE_BIT: return "VK_ACCESS_2_HOST_WRITE_BIT";
    case VK_ACCESS_2_MEMORY_READ_BIT: return "VK_ACCESS_2_MEMORY_READ_BIT";
    case VK_ACCESS_2_MEMORY_WRITE_BIT: return "VK_ACCESS_2_MEMORY_WRITE_BIT";
    case VK_ACCESS_2_SHADER_SAMPLED_READ_BIT: return "VK_ACCESS_2_SHADER_SAMPLED_READ_BIT";
    case VK_ACCESS_2_SHADER_STORAGE_READ_BIT: return "VK_ACCESS_2_SHADER_STORAGE_READ_BIT";
    case VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT: return "VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT";
    case VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR: return "VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR";
    case VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR: return "VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR";
    case VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR: return "VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR";
    case VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR: return "VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR";
    case VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT: return "VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT";
    case VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT: return "VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT";
    case VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT: return "VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT";
    case VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT: return "VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT";
    case VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_NV: return "VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_NV";
    case VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_NV: return "VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_NV";
    case VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR: return "VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR";
    case VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR: return "VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR";
    case VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR: return "VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR";
    case VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT: return "VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT";
    case VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT: return "VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT";
    case VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT: return "VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT";
    case VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI: return "VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI";
    case VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR: return "VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR";
    case VK_ACCESS_2_MICROMAP_READ_BIT_EXT: return "VK_ACCESS_2_MICROMAP_READ_BIT_EXT";
    case VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT: return "VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT";
    case VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV: return "VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV";
    case VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV: return "VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  // VkPipelineStageFlagBits2 is type aliased. its to_string() must have a unique name.
  VKU_IMPL const char* pipeline_stage_flag_bits2_to_string(const VkPipelineStageFlagBits2 v) {
    switch(v) {
    case VK_PIPELINE_STAGE_2_NONE: return "VK_PIPELINE_STAGE_2_NONE";
    case VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT: return "VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT";
    case VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT: return "VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT";
    case VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT: return "VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT";
    case VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT: return "VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT";
    case VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT: return "VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT";
    case VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT: return "VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT";
    case VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT: return "VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT";
    case VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT: return "VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT";
    case VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT: return "VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT";
    case VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT: return "VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT";
    case VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT: return "VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT";
    case VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT: return "VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT";
    case VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT: return "VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT";
    case VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT: return "VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT";
    case VK_PIPELINE_STAGE_2_HOST_BIT: return "VK_PIPELINE_STAGE_2_HOST_BIT";
    case VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT: return "VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT";
    case VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT: return "VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT";
    case VK_PIPELINE_STAGE_2_COPY_BIT: return "VK_PIPELINE_STAGE_2_COPY_BIT";
    case VK_PIPELINE_STAGE_2_RESOLVE_BIT: return "VK_PIPELINE_STAGE_2_RESOLVE_BIT";
    case VK_PIPELINE_STAGE_2_BLIT_BIT: return "VK_PIPELINE_STAGE_2_BLIT_BIT";
    case VK_PIPELINE_STAGE_2_CLEAR_BIT: return "VK_PIPELINE_STAGE_2_CLEAR_BIT";
    case VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT: return "VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT";
    case VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT: return "VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT";
    case VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT: return "VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT";
    case VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR: return "VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR";
    case VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR: return "VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR";
    case VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT: return "VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT";
    case VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT: return "VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT";
    case VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV: return "VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV";
    case VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR: return "VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR: return "VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR";
    case VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR: return "VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR";
    case VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT: return "VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT";
    case VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT: return "VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT";
    case VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT: return "VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT";
    case VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI: return "VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI";
    case VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI: return "VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI";
    case VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR: return "VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR";
    case VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT: return "VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT";
    case VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI: return "VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI";
    case VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV: return "VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkSubmitFlagBits v) {
    switch(v) {
    case VK_SUBMIT_PROTECTED_BIT: return "VK_SUBMIT_PROTECTED_BIT";
    default: break;
    }
    return nullptr;
  }
  // VkFormatFeatureFlagBits2 is type aliased. its to_string() must have a unique name.
  VKU_IMPL const char* format_feature_flag_bits2_to_string(const VkFormatFeatureFlagBits2 v) {
    switch(v) {
    case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT: return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT";
    case VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT: return "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT";
    case VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT: return "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT";
    case VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT: return "VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT";
    case VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT: return "VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT";
    case VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT: return "VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT";
    case VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT: return "VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT";
    case VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT: return "VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT";
    case VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT: return "VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT";
    case VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT: return "VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT";
    case VK_FORMAT_FEATURE_2_BLIT_SRC_BIT: return "VK_FORMAT_FEATURE_2_BLIT_SRC_BIT";
    case VK_FORMAT_FEATURE_2_BLIT_DST_BIT: return "VK_FORMAT_FEATURE_2_BLIT_DST_BIT";
    case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT: return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT";
    case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT: return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT";
    case VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT: return "VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT";
    case VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT: return "VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT";
    case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT: return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT";
    case VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT: return "VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT";
    case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT: return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT";
    case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT: return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT";
    case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT: return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT";
    case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT: return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT";
    case VK_FORMAT_FEATURE_2_DISJOINT_BIT: return "VK_FORMAT_FEATURE_2_DISJOINT_BIT";
    case VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT: return "VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT";
    case VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT: return "VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT";
    case VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT: return "VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT";
    case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT: return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT";
    case VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR: return "VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR";
    case VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR: return "VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR";
    case VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR: return "VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR";
    case VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT: return "VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT";
    case VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR: return "VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT_EXT: return "VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT_EXT";
    case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR: return "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR";
    case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR: return "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR";
    case VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV: return "VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV";
    case VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM: return "VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM";
    case VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM: return "VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM";
    case VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM: return "VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM";
    case VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM: return "VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM";
    case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV: return "VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV";
    case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV: return "VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV";
    case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV: return "VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV";
    default: break;
    }
    return nullptr;
  }
  VKU_IMPL const char* to_string(const VkRenderingFlagBits v) {
    switch(v) {
    case VK_RENDERING_CONTENTS_SECONDARY_COMMAND_BUFFERS_BIT: return "VK_RENDERING_CONTENTS_SECONDARY_COMMAND_BUFFERS_BIT";
    case VK_RENDERING_SUSPENDING_BIT: return "VK_RENDERING_SUSPENDING_BIT";
    case VK_RENDERING_RESUMING_BIT: return "VK_RENDERING_RESUMING_BIT";
    case VK_RENDERING_CONTENTS_INLINE_BIT_EXT: return "VK_RENDERING_CONTENTS_INLINE_BIT_EXT";
    case VK_RENDERING_ENABLE_LEGACY_DITHERING_BIT_EXT: return "VK_RENDERING_ENABLE_LEGACY_DITHERING_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
#endif // VK_VERSION_1_3
#if defined(VK_USE_PLATFORM_FUCHSIA)
  VKU_IMPL const char* to_string(const VkImageConstraintsInfoFlagBitsFUCHSIA v) {
    switch(v) {
    case VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_RARELY_FUCHSIA: return "VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_RARELY_FUCHSIA";
    case VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_OFTEN_FUCHSIA: return "VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_OFTEN_FUCHSIA";
    case VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_RARELY_FUCHSIA: return "VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_RARELY_FUCHSIA";
    case VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_OFTEN_FUCHSIA: return "VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_OFTEN_FUCHSIA";
    case VK_IMAGE_CONSTRAINTS_INFO_PROTECTED_OPTIONAL_FUCHSIA: return "VK_IMAGE_CONSTRAINTS_INFO_PROTECTED_OPTIONAL_FUCHSIA";
    default: break;
    }
    return nullptr;
  }
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
  VKU_IMPL const char* to_string(const VkExportMetalObjectTypeFlagBitsEXT v) {
    switch(v) {
    case VK_EXPORT_METAL_OBJECT_TYPE_METAL_DEVICE_BIT_EXT: return "VK_EXPORT_METAL_OBJECT_TYPE_METAL_DEVICE_BIT_EXT";
    case VK_EXPORT_METAL_OBJECT_TYPE_METAL_COMMAND_QUEUE_BIT_EXT: return "VK_EXPORT_METAL_OBJECT_TYPE_METAL_COMMAND_QUEUE_BIT_EXT";
    case VK_EXPORT_METAL_OBJECT_TYPE_METAL_BUFFER_BIT_EXT: return "VK_EXPORT_METAL_OBJECT_TYPE_METAL_BUFFER_BIT_EXT";
    case VK_EXPORT_METAL_OBJECT_TYPE_METAL_TEXTURE_BIT_EXT: return "VK_EXPORT_METAL_OBJECT_TYPE_METAL_TEXTURE_BIT_EXT";
    case VK_EXPORT_METAL_OBJECT_TYPE_METAL_IOSURFACE_BIT_EXT: return "VK_EXPORT_METAL_OBJECT_TYPE_METAL_IOSURFACE_BIT_EXT";
    case VK_EXPORT_METAL_OBJECT_TYPE_METAL_SHARED_EVENT_BIT_EXT: return "VK_EXPORT_METAL_OBJECT_TYPE_METAL_SHARED_EVENT_BIT_EXT";
    default: break;
    }
    return nullptr;
  }
#endif // VK_USE_PLATFORM_METAL_EXT
#if defined(VK_USE_PLATFORM_WIN32_KHR)
  VKU_IMPL const char* to_string(const VkFullScreenExclusiveEXT v) {
    switch(v) {
    case VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT: return "VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT";
    case VK_FULL_SCREEN_EXCLUSIVE_ALLOWED_EXT: return "VK_FULL_SCREEN_EXCLUSIVE_ALLOWED_EXT";
    case VK_FULL_SCREEN_EXCLUSIVE_DISALLOWED_EXT: return "VK_FULL_SCREEN_EXCLUSIVE_DISALLOWED_EXT";
    case VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT: return "VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT";
    default: break;
    }
    return nullptr;
  }
#endif // VK_USE_PLATFORM_WIN32_KHR

  VKU_IMPL UncompressedFormatMetadata get_uncompressed_format_metadata(VkFormat f) {
    switch(f) {
    case VK_FORMAT_R4G4_UNORM_PACK8: return {1, 2, {{ChannelName::R, NumericFormat::UNORM, 4, 4}, {ChannelName::G, NumericFormat::UNORM, 4, 0}}};
    case VK_FORMAT_R4G4B4A4_UNORM_PACK16: return {2, 4, {{ChannelName::R, NumericFormat::UNORM, 4, 12}, {ChannelName::G, NumericFormat::UNORM, 4, 8}, {ChannelName::B, NumericFormat::UNORM, 4, 4}, {ChannelName::A, NumericFormat::UNORM, 4, 0}}};
    case VK_FORMAT_B4G4R4A4_UNORM_PACK16: return {2, 4, {{ChannelName::B, NumericFormat::UNORM, 4, 12}, {ChannelName::G, NumericFormat::UNORM, 4, 8}, {ChannelName::R, NumericFormat::UNORM, 4, 4}, {ChannelName::A, NumericFormat::UNORM, 4, 0}}};
    case VK_FORMAT_R5G6B5_UNORM_PACK16: return {2, 3, {{ChannelName::R, NumericFormat::UNORM, 5, 11}, {ChannelName::G, NumericFormat::UNORM, 6, 5}, {ChannelName::B, NumericFormat::UNORM, 5, 0}}};
    case VK_FORMAT_B5G6R5_UNORM_PACK16: return {2, 3, {{ChannelName::B, NumericFormat::UNORM, 5, 11}, {ChannelName::G, NumericFormat::UNORM, 6, 5}, {ChannelName::R, NumericFormat::UNORM, 5, 0}}};
    case VK_FORMAT_R5G5B5A1_UNORM_PACK16: return {2, 4, {{ChannelName::R, NumericFormat::UNORM, 5, 11}, {ChannelName::G, NumericFormat::UNORM, 5, 6}, {ChannelName::B, NumericFormat::UNORM, 5, 1}, {ChannelName::A, NumericFormat::UNORM, 1, 0}}};
    case VK_FORMAT_B5G5R5A1_UNORM_PACK16: return {2, 4, {{ChannelName::B, NumericFormat::UNORM, 5, 11}, {ChannelName::G, NumericFormat::UNORM, 5, 6}, {ChannelName::R, NumericFormat::UNORM, 5, 1}, {ChannelName::A, NumericFormat::UNORM, 1, 0}}};
    case VK_FORMAT_A1R5G5B5_UNORM_PACK16: return {2, 4, {{ChannelName::A, NumericFormat::UNORM, 1, 15}, {ChannelName::R, NumericFormat::UNORM, 5, 10}, {ChannelName::G, NumericFormat::UNORM, 5, 5}, {ChannelName::B, NumericFormat::UNORM, 5, 0}}};
    case VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR: return {2, 4, {{ChannelName::A, NumericFormat::UNORM, 1, 15}, {ChannelName::B, NumericFormat::UNORM, 5, 10}, {ChannelName::G, NumericFormat::UNORM, 5, 5}, {ChannelName::R, NumericFormat::UNORM, 5, 0}}};
    case VK_FORMAT_A8_UNORM_KHR: return {1, 1, {{ChannelName::A, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8_UNORM: return {1, 1, {{ChannelName::R, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8_SNORM: return {1, 1, {{ChannelName::R, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8_USCALED: return {1, 1, {{ChannelName::R, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8_SSCALED: return {1, 1, {{ChannelName::R, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8_UINT: return {1, 1, {{ChannelName::R, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8_SINT: return {1, 1, {{ChannelName::R, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8_SRGB: return {1, 1, {{ChannelName::R, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8_UNORM: return {2, 2, {{ChannelName::R, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8_SNORM: return {2, 2, {{ChannelName::R, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8_USCALED: return {2, 2, {{ChannelName::R, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8_SSCALED: return {2, 2, {{ChannelName::R, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8_UINT: return {2, 2, {{ChannelName::R, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8_SINT: return {2, 2, {{ChannelName::R, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8_SRGB: return {2, 2, {{ChannelName::R, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8_UNORM: return {3, 3, {{ChannelName::R, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8_SNORM: return {3, 3, {{ChannelName::R, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8_USCALED: return {3, 3, {{ChannelName::R, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8_SSCALED: return {3, 3, {{ChannelName::R, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8_UINT: return {3, 3, {{ChannelName::R, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8_SINT: return {3, 3, {{ChannelName::R, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8_SRGB: return {3, 3, {{ChannelName::R, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8_UNORM: return {3, 3, {{ChannelName::B, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8_SNORM: return {3, 3, {{ChannelName::B, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8_USCALED: return {3, 3, {{ChannelName::B, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8_SSCALED: return {3, 3, {{ChannelName::B, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8_UINT: return {3, 3, {{ChannelName::B, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8_SINT: return {3, 3, {{ChannelName::B, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8_SRGB: return {3, 3, {{ChannelName::B, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8A8_UNORM: return {4, 4, {{ChannelName::R, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8A8_SNORM: return {4, 4, {{ChannelName::R, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8A8_USCALED: return {4, 4, {{ChannelName::R, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8A8_SSCALED: return {4, 4, {{ChannelName::R, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8A8_UINT: return {4, 4, {{ChannelName::R, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8A8_SINT: return {4, 4, {{ChannelName::R, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R8G8B8A8_SRGB: return {4, 4, {{ChannelName::R, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8A8_UNORM: return {4, 4, {{ChannelName::B, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::UNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8A8_SNORM: return {4, 4, {{ChannelName::B, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SNORM, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8A8_USCALED: return {4, 4, {{ChannelName::B, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::USCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8A8_SSCALED: return {4, 4, {{ChannelName::B, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SSCALED, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8A8_UINT: return {4, 4, {{ChannelName::B, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8A8_SINT: return {4, 4, {{ChannelName::B, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B8G8R8A8_SRGB: return {4, 4, {{ChannelName::B, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::R, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SRGB, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_A8B8G8R8_UNORM_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::UNORM, 8, 24}, {ChannelName::B, NumericFormat::UNORM, 8, 16}, {ChannelName::G, NumericFormat::UNORM, 8, 8}, {ChannelName::R, NumericFormat::UNORM, 8, 0}}};
    case VK_FORMAT_A8B8G8R8_SNORM_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::SNORM, 8, 24}, {ChannelName::B, NumericFormat::SNORM, 8, 16}, {ChannelName::G, NumericFormat::SNORM, 8, 8}, {ChannelName::R, NumericFormat::SNORM, 8, 0}}};
    case VK_FORMAT_A8B8G8R8_USCALED_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::USCALED, 8, 24}, {ChannelName::B, NumericFormat::USCALED, 8, 16}, {ChannelName::G, NumericFormat::USCALED, 8, 8}, {ChannelName::R, NumericFormat::USCALED, 8, 0}}};
    case VK_FORMAT_A8B8G8R8_SSCALED_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::SSCALED, 8, 24}, {ChannelName::B, NumericFormat::SSCALED, 8, 16}, {ChannelName::G, NumericFormat::SSCALED, 8, 8}, {ChannelName::R, NumericFormat::SSCALED, 8, 0}}};
    case VK_FORMAT_A8B8G8R8_UINT_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::UINT, 8, 24}, {ChannelName::B, NumericFormat::UINT, 8, 16}, {ChannelName::G, NumericFormat::UINT, 8, 8}, {ChannelName::R, NumericFormat::UINT, 8, 0}}};
    case VK_FORMAT_A8B8G8R8_SINT_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::SINT, 8, 24}, {ChannelName::B, NumericFormat::SINT, 8, 16}, {ChannelName::G, NumericFormat::SINT, 8, 8}, {ChannelName::R, NumericFormat::SINT, 8, 0}}};
    case VK_FORMAT_A8B8G8R8_SRGB_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::SRGB, 8, 24}, {ChannelName::B, NumericFormat::SRGB, 8, 16}, {ChannelName::G, NumericFormat::SRGB, 8, 8}, {ChannelName::R, NumericFormat::SRGB, 8, 0}}};
    case VK_FORMAT_A2R10G10B10_UNORM_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::UNORM, 2, 30}, {ChannelName::R, NumericFormat::UNORM, 10, 20}, {ChannelName::G, NumericFormat::UNORM, 10, 10}, {ChannelName::B, NumericFormat::UNORM, 10, 0}}};
    case VK_FORMAT_A2R10G10B10_SNORM_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::SNORM, 2, 30}, {ChannelName::R, NumericFormat::SNORM, 10, 20}, {ChannelName::G, NumericFormat::SNORM, 10, 10}, {ChannelName::B, NumericFormat::SNORM, 10, 0}}};
    case VK_FORMAT_A2R10G10B10_USCALED_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::USCALED, 2, 30}, {ChannelName::R, NumericFormat::USCALED, 10, 20}, {ChannelName::G, NumericFormat::USCALED, 10, 10}, {ChannelName::B, NumericFormat::USCALED, 10, 0}}};
    case VK_FORMAT_A2R10G10B10_SSCALED_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::SSCALED, 2, 30}, {ChannelName::R, NumericFormat::SSCALED, 10, 20}, {ChannelName::G, NumericFormat::SSCALED, 10, 10}, {ChannelName::B, NumericFormat::SSCALED, 10, 0}}};
    case VK_FORMAT_A2R10G10B10_UINT_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::UINT, 2, 30}, {ChannelName::R, NumericFormat::UINT, 10, 20}, {ChannelName::G, NumericFormat::UINT, 10, 10}, {ChannelName::B, NumericFormat::UINT, 10, 0}}};
    case VK_FORMAT_A2R10G10B10_SINT_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::SINT, 2, 30}, {ChannelName::R, NumericFormat::SINT, 10, 20}, {ChannelName::G, NumericFormat::SINT, 10, 10}, {ChannelName::B, NumericFormat::SINT, 10, 0}}};
    case VK_FORMAT_A2B10G10R10_UNORM_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::UNORM, 2, 30}, {ChannelName::B, NumericFormat::UNORM, 10, 20}, {ChannelName::G, NumericFormat::UNORM, 10, 10}, {ChannelName::R, NumericFormat::UNORM, 10, 0}}};
    case VK_FORMAT_A2B10G10R10_SNORM_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::SNORM, 2, 30}, {ChannelName::B, NumericFormat::SNORM, 10, 20}, {ChannelName::G, NumericFormat::SNORM, 10, 10}, {ChannelName::R, NumericFormat::SNORM, 10, 0}}};
    case VK_FORMAT_A2B10G10R10_USCALED_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::USCALED, 2, 30}, {ChannelName::B, NumericFormat::USCALED, 10, 20}, {ChannelName::G, NumericFormat::USCALED, 10, 10}, {ChannelName::R, NumericFormat::USCALED, 10, 0}}};
    case VK_FORMAT_A2B10G10R10_SSCALED_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::SSCALED, 2, 30}, {ChannelName::B, NumericFormat::SSCALED, 10, 20}, {ChannelName::G, NumericFormat::SSCALED, 10, 10}, {ChannelName::R, NumericFormat::SSCALED, 10, 0}}};
    case VK_FORMAT_A2B10G10R10_UINT_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::UINT, 2, 30}, {ChannelName::B, NumericFormat::UINT, 10, 20}, {ChannelName::G, NumericFormat::UINT, 10, 10}, {ChannelName::R, NumericFormat::UINT, 10, 0}}};
    case VK_FORMAT_A2B10G10R10_SINT_PACK32: return {4, 4, {{ChannelName::A, NumericFormat::SINT, 2, 30}, {ChannelName::B, NumericFormat::SINT, 10, 20}, {ChannelName::G, NumericFormat::SINT, 10, 10}, {ChannelName::R, NumericFormat::SINT, 10, 0}}};
    case VK_FORMAT_R16_UNORM: return {2, 1, {{ChannelName::R, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16_SNORM: return {2, 1, {{ChannelName::R, NumericFormat::SNORM, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16_USCALED: return {2, 1, {{ChannelName::R, NumericFormat::USCALED, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16_SSCALED: return {2, 1, {{ChannelName::R, NumericFormat::SSCALED, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16_UINT: return {2, 1, {{ChannelName::R, NumericFormat::UINT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16_SINT: return {2, 1, {{ChannelName::R, NumericFormat::SINT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16_SFLOAT: return {2, 1, {{ChannelName::R, NumericFormat::SFLOAT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16_UNORM: return {4, 2, {{ChannelName::R, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16_SNORM: return {4, 2, {{ChannelName::R, NumericFormat::SNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SNORM, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16_USCALED: return {4, 2, {{ChannelName::R, NumericFormat::USCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::USCALED, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16_SSCALED: return {4, 2, {{ChannelName::R, NumericFormat::SSCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SSCALED, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16_UINT: return {4, 2, {{ChannelName::R, NumericFormat::UINT, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16_SINT: return {4, 2, {{ChannelName::R, NumericFormat::SINT, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16_SFLOAT: return {4, 2, {{ChannelName::R, NumericFormat::SFLOAT, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SFLOAT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16_UNORM: return {6, 3, {{ChannelName::R, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16_SNORM: return {6, 3, {{ChannelName::R, NumericFormat::SNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SNORM, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16_USCALED: return {6, 3, {{ChannelName::R, NumericFormat::USCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::USCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::USCALED, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16_SSCALED: return {6, 3, {{ChannelName::R, NumericFormat::SSCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SSCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SSCALED, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16_UINT: return {6, 3, {{ChannelName::R, NumericFormat::UINT, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UINT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16_SINT: return {6, 3, {{ChannelName::R, NumericFormat::SINT, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SINT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16_SFLOAT: return {6, 3, {{ChannelName::R, NumericFormat::SFLOAT, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SFLOAT, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SFLOAT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16A16_UNORM: return {8, 4, {{ChannelName::R, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16A16_SNORM: return {8, 4, {{ChannelName::R, NumericFormat::SNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SNORM, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16A16_USCALED: return {8, 4, {{ChannelName::R, NumericFormat::USCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::USCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::USCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::USCALED, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16A16_SSCALED: return {8, 4, {{ChannelName::R, NumericFormat::SSCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SSCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SSCALED, 16, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SSCALED, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16A16_UINT: return {8, 4, {{ChannelName::R, NumericFormat::UINT, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UINT, 16, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::UINT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16A16_SINT: return {8, 4, {{ChannelName::R, NumericFormat::SINT, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SINT, 16, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SINT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R16G16B16A16_SFLOAT: return {8, 4, {{ChannelName::R, NumericFormat::SFLOAT, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SFLOAT, 16, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SFLOAT, 16, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SFLOAT, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32_UINT: return {4, 1, {{ChannelName::R, NumericFormat::UINT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32_SINT: return {4, 1, {{ChannelName::R, NumericFormat::SINT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32_SFLOAT: return {4, 1, {{ChannelName::R, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32G32_UINT: return {8, 2, {{ChannelName::R, NumericFormat::UINT, 32, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32G32_SINT: return {8, 2, {{ChannelName::R, NumericFormat::SINT, 32, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32G32_SFLOAT: return {8, 2, {{ChannelName::R, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32G32B32_UINT: return {12, 3, {{ChannelName::R, NumericFormat::UINT, 32, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 32, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UINT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32G32B32_SINT: return {12, 3, {{ChannelName::R, NumericFormat::SINT, 32, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 32, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SINT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32G32B32_SFLOAT: return {12, 3, {{ChannelName::R, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32G32B32A32_UINT: return {16, 4, {{ChannelName::R, NumericFormat::UINT, 32, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 32, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UINT, 32, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::UINT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32G32B32A32_SINT: return {16, 4, {{ChannelName::R, NumericFormat::SINT, 32, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 32, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SINT, 32, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SINT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R32G32B32A32_SFLOAT: return {16, 4, {{ChannelName::R, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64_UINT: return {8, 1, {{ChannelName::R, NumericFormat::UINT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64_SINT: return {8, 1, {{ChannelName::R, NumericFormat::SINT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64_SFLOAT: return {8, 1, {{ChannelName::R, NumericFormat::SFLOAT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64G64_UINT: return {16, 2, {{ChannelName::R, NumericFormat::UINT, 64, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64G64_SINT: return {16, 2, {{ChannelName::R, NumericFormat::SINT, 64, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64G64_SFLOAT: return {16, 2, {{ChannelName::R, NumericFormat::SFLOAT, 64, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SFLOAT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64G64B64_UINT: return {24, 3, {{ChannelName::R, NumericFormat::UINT, 64, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 64, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UINT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64G64B64_SINT: return {24, 3, {{ChannelName::R, NumericFormat::SINT, 64, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 64, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SINT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64G64B64_SFLOAT: return {24, 3, {{ChannelName::R, NumericFormat::SFLOAT, 64, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SFLOAT, 64, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SFLOAT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64G64B64A64_UINT: return {32, 4, {{ChannelName::R, NumericFormat::UINT, 64, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::UINT, 64, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::UINT, 64, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::UINT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64G64B64A64_SINT: return {32, 4, {{ChannelName::R, NumericFormat::SINT, 64, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SINT, 64, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SINT, 64, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SINT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R64G64B64A64_SFLOAT: return {32, 4, {{ChannelName::R, NumericFormat::SFLOAT, 64, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SFLOAT, 64, ChannelMetadata::kNoShift}, {ChannelName::B, NumericFormat::SFLOAT, 64, ChannelMetadata::kNoShift}, {ChannelName::A, NumericFormat::SFLOAT, 64, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_B10G11R11_UFLOAT_PACK32: return {4, 3, {{ChannelName::B, NumericFormat::UFLOAT, 10, 22}, {ChannelName::G, NumericFormat::UFLOAT, 11, 11}, {ChannelName::R, NumericFormat::UFLOAT, 11, 0}}};
    case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32: return {4, 4, {{ChannelName::E, NumericFormat::SINT, 5, 27}, {ChannelName::B, NumericFormat::UFLOAT, 9, 18}, {ChannelName::G, NumericFormat::UFLOAT, 9, 9}, {ChannelName::R, NumericFormat::UFLOAT, 9, 0}}};
    case VK_FORMAT_D16_UNORM: return {2, 1, {{ChannelName::D, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_X8_D24_UNORM_PACK32: return {4, 1, {{ChannelName::D, NumericFormat::UNORM, 24, 8}}};
    case VK_FORMAT_D32_SFLOAT: return {4, 1, {{ChannelName::D, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_S8_UINT: return {1, 1, {{ChannelName::S, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_D16_UNORM_S8_UINT: return {3, 2, {{ChannelName::D, NumericFormat::UNORM, 16, ChannelMetadata::kNoShift}, {ChannelName::S, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_D24_UNORM_S8_UINT: return {4, 2, {{ChannelName::D, NumericFormat::UNORM, 24, ChannelMetadata::kNoShift}, {ChannelName::S, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_D32_SFLOAT_S8_UINT: return {5, 2, {{ChannelName::D, NumericFormat::SFLOAT, 32, ChannelMetadata::kNoShift}, {ChannelName::S, NumericFormat::UINT, 8, ChannelMetadata::kNoShift}}};
    case VK_FORMAT_R10X6_UNORM_PACK16: return {2, 1, {{ChannelName::R, NumericFormat::UNORM, 10, 6}}};
    case VK_FORMAT_R10X6G10X6_UNORM_2PACK16: return {4, 2, {{ChannelName::R, NumericFormat::UNORM, 10, 22}, {ChannelName::G, NumericFormat::UNORM, 10, 6}}};
    case VK_FORMAT_R12X4_UNORM_PACK16: return {2, 1, {{ChannelName::R, NumericFormat::UNORM, 12, 4}}};
    case VK_FORMAT_R12X4G12X4_UNORM_2PACK16: return {4, 2, {{ChannelName::R, NumericFormat::UNORM, 12, 20}, {ChannelName::G, NumericFormat::UNORM, 12, 4}}};
    case VK_FORMAT_A4R4G4B4_UNORM_PACK16: return {2, 4, {{ChannelName::A, NumericFormat::UNORM, 4, 12}, {ChannelName::R, NumericFormat::UNORM, 4, 8}, {ChannelName::G, NumericFormat::UNORM, 4, 4}, {ChannelName::B, NumericFormat::UNORM, 4, 0}}};
    case VK_FORMAT_A4B4G4R4_UNORM_PACK16: return {2, 4, {{ChannelName::A, NumericFormat::UNORM, 4, 12}, {ChannelName::B, NumericFormat::UNORM, 4, 8}, {ChannelName::G, NumericFormat::UNORM, 4, 4}, {ChannelName::R, NumericFormat::UNORM, 4, 0}}};
    case VK_FORMAT_R16G16_SFIXED5_NV: return {4, 2, {{ChannelName::R, NumericFormat::SFIXED5, 16, ChannelMetadata::kNoShift}, {ChannelName::G, NumericFormat::SFIXED5, 16, ChannelMetadata::kNoShift}}};
    default: break;
    }
    return {};
  }

  VKU_IMPL CompressedFormatMetadata get_compressed_format_metadata(VkFormat f) {
    switch(f) {
    case VK_FORMAT_BC1_RGB_UNORM_BLOCK: return {CompressionScheme::BC1, 4, 4, 8, 3, NumericFormat::UNORM};
    case VK_FORMAT_BC1_RGB_SRGB_BLOCK: return {CompressionScheme::BC1, 4, 4, 8, 3, NumericFormat::SRGB};
    case VK_FORMAT_BC1_RGBA_UNORM_BLOCK: return {CompressionScheme::BC1, 4, 4, 8, 4, NumericFormat::UNORM};
    case VK_FORMAT_BC1_RGBA_SRGB_BLOCK: return {CompressionScheme::BC1, 4, 4, 8, 4, NumericFormat::SRGB};
    case VK_FORMAT_BC2_UNORM_BLOCK: return {CompressionScheme::BC2, 4, 4, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_BC2_SRGB_BLOCK: return {CompressionScheme::BC2, 4, 4, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_BC3_UNORM_BLOCK: return {CompressionScheme::BC3, 4, 4, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_BC3_SRGB_BLOCK: return {CompressionScheme::BC3, 4, 4, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_BC4_UNORM_BLOCK: return {CompressionScheme::BC4, 4, 4, 8, 1, NumericFormat::UNORM};
    case VK_FORMAT_BC4_SNORM_BLOCK: return {CompressionScheme::BC4, 4, 4, 8, 1, NumericFormat::SNORM};
    case VK_FORMAT_BC5_UNORM_BLOCK: return {CompressionScheme::BC5, 4, 4, 16, 2, NumericFormat::UNORM};
    case VK_FORMAT_BC5_SNORM_BLOCK: return {CompressionScheme::BC5, 4, 4, 16, 2, NumericFormat::SNORM};
    case VK_FORMAT_BC6H_UFLOAT_BLOCK: return {CompressionScheme::BC6H, 4, 4, 16, 3, NumericFormat::UFLOAT};
    case VK_FORMAT_BC6H_SFLOAT_BLOCK: return {CompressionScheme::BC6H, 4, 4, 16, 3, NumericFormat::SFLOAT};
    case VK_FORMAT_BC7_UNORM_BLOCK: return {CompressionScheme::BC7, 4, 4, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_BC7_SRGB_BLOCK: return {CompressionScheme::BC7, 4, 4, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK: return {CompressionScheme::ETC2, 4, 4, 8, 3, NumericFormat::UNORM};
    case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK: return {CompressionScheme::ETC2, 4, 4, 8, 3, NumericFormat::SRGB};
    case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK: return {CompressionScheme::ETC2, 4, 4, 8, 4, NumericFormat::UNORM};
    case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK: return {CompressionScheme::ETC2, 4, 4, 8, 4, NumericFormat::SRGB};
    case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK: return {CompressionScheme::ETC2, 4, 4, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK: return {CompressionScheme::ETC2, 4, 4, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_EAC_R11_UNORM_BLOCK: return {CompressionScheme::EAC, 4, 4, 8, 1, NumericFormat::UNORM};
    case VK_FORMAT_EAC_R11_SNORM_BLOCK: return {CompressionScheme::EAC, 4, 4, 8, 1, NumericFormat::SNORM};
    case VK_FORMAT_EAC_R11G11_UNORM_BLOCK: return {CompressionScheme::EAC, 4, 4, 16, 2, NumericFormat::UNORM};
    case VK_FORMAT_EAC_R11G11_SNORM_BLOCK: return {CompressionScheme::EAC, 4, 4, 16, 2, NumericFormat::SNORM};
    case VK_FORMAT_ASTC_4x4_UNORM_BLOCK: return {CompressionScheme::ASTC, 4, 4, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_4x4_SRGB_BLOCK: return {CompressionScheme::ASTC, 4, 4, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_5x4_UNORM_BLOCK: return {CompressionScheme::ASTC, 5, 4, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_5x4_SRGB_BLOCK: return {CompressionScheme::ASTC, 5, 4, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_5x5_UNORM_BLOCK: return {CompressionScheme::ASTC, 5, 5, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_5x5_SRGB_BLOCK: return {CompressionScheme::ASTC, 5, 5, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_6x5_UNORM_BLOCK: return {CompressionScheme::ASTC, 6, 5, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_6x5_SRGB_BLOCK: return {CompressionScheme::ASTC, 6, 5, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_6x6_UNORM_BLOCK: return {CompressionScheme::ASTC, 6, 6, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_6x6_SRGB_BLOCK: return {CompressionScheme::ASTC, 6, 6, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_8x5_UNORM_BLOCK: return {CompressionScheme::ASTC, 8, 5, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_8x5_SRGB_BLOCK: return {CompressionScheme::ASTC, 8, 5, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_8x6_UNORM_BLOCK: return {CompressionScheme::ASTC, 8, 6, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_8x6_SRGB_BLOCK: return {CompressionScheme::ASTC, 8, 6, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_8x8_UNORM_BLOCK: return {CompressionScheme::ASTC, 8, 8, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_8x8_SRGB_BLOCK: return {CompressionScheme::ASTC, 8, 8, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_10x5_UNORM_BLOCK: return {CompressionScheme::ASTC, 10, 5, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_10x5_SRGB_BLOCK: return {CompressionScheme::ASTC, 10, 5, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_10x6_UNORM_BLOCK: return {CompressionScheme::ASTC, 10, 6, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_10x6_SRGB_BLOCK: return {CompressionScheme::ASTC, 10, 6, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_10x8_UNORM_BLOCK: return {CompressionScheme::ASTC, 10, 8, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_10x8_SRGB_BLOCK: return {CompressionScheme::ASTC, 10, 8, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_10x10_UNORM_BLOCK: return {CompressionScheme::ASTC, 10, 10, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_10x10_SRGB_BLOCK: return {CompressionScheme::ASTC, 10, 10, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_12x10_UNORM_BLOCK: return {CompressionScheme::ASTC, 12, 10, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_12x10_SRGB_BLOCK: return {CompressionScheme::ASTC, 12, 10, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_12x12_UNORM_BLOCK: return {CompressionScheme::ASTC, 12, 12, 16, 4, NumericFormat::UNORM};
    case VK_FORMAT_ASTC_12x12_SRGB_BLOCK: return {CompressionScheme::ASTC, 12, 12, 16, 4, NumericFormat::SRGB};
    case VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG: return {CompressionScheme::PVRTC1, 8, 4, 8, 4, NumericFormat::UNORM};
    case VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG: return {CompressionScheme::PVRTC1, 4, 4, 8, 4, NumericFormat::UNORM};
    case VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG: return {CompressionScheme::PVRTC2, 8, 4, 8, 4, NumericFormat::UNORM};
    case VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG: return {CompressionScheme::PVRTC2, 4, 4, 8, 4, NumericFormat::UNORM};
    case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG: return {CompressionScheme::PVRTC1, 8, 4, 8, 4, NumericFormat::SRGB};
    case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG: return {CompressionScheme::PVRTC1, 4, 4, 8, 4, NumericFormat::SRGB};
    case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG: return {CompressionScheme::PVRTC2, 8, 4, 8, 4, NumericFormat::SRGB};
    case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG: return {CompressionScheme::PVRTC2, 4, 4, 8, 4, NumericFormat::SRGB};
    case VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 4, 4, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 5, 4, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 5, 5, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 6, 5, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 6, 6, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 8, 5, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 8, 6, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 8, 8, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 10, 5, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 10, 6, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 10, 8, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 10, 10, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 12, 10, 16, 4, NumericFormat::SFLOAT};
    case VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK: return {CompressionScheme::ASTC, 12, 12, 16, 4, NumericFormat::SFLOAT};
    default: break;
    }
    return {};
  }

  VKU_IMPL VideoFormatMetadata get_video_format_metadata(VkFormat f) {
    switch(f) {
    case VK_FORMAT_G8B8G8R8_422_UNORM: return {2, 4, 3, NumericFormat::UNORM};
    case VK_FORMAT_B8G8R8G8_422_UNORM: return {2, 4, 3, NumericFormat::UNORM};
    case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM: return {1, 3, 3, NumericFormat::UNORM};
    case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM: return {1, 3, 3, NumericFormat::UNORM};
    case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM: return {1, 3, 3, NumericFormat::UNORM};
    case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM: return {1, 3, 3, NumericFormat::UNORM};
    case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM: return {1, 3, 3, NumericFormat::UNORM};
    case VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16: return {1, 8, 4, NumericFormat::UNORM};
    case VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16: return {2, 8, 3, NumericFormat::UNORM};
    case VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16: return {2, 8, 3, NumericFormat::UNORM};
    case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16: return {1, 8, 4, NumericFormat::UNORM};
    case VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16: return {2, 8, 3, NumericFormat::UNORM};
    case VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16: return {2, 8, 3, NumericFormat::UNORM};
    case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G16B16G16R16_422_UNORM: return {2, 8, 3, NumericFormat::UNORM};
    case VK_FORMAT_B16G16R16G16_422_UNORM: return {2, 8, 3, NumericFormat::UNORM};
    case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM: return {1, 3, 3, NumericFormat::UNORM};
    case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16: return {1, 6, 3, NumericFormat::UNORM};
    case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM: return {1, 6, 3, NumericFormat::UNORM};
    default: break;
    }
    return {};
  }

#endif // VKU_IMPLEMENT || VKU_INLINE_ALL
} // end namespace vku

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
  VKU_PROTO VkFormat vanilla_format_for(uint32_t channel_count, NumericFormat nf, uint32_t channel_bit_count, bool packed=false);

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

  VKU_IMPL VkFormat vanilla_format_for(uint32_t channel_count, NumericFormat nf, uint32_t channel_bit_count, bool packed) {
    // 0 is VK_FORMAT_UNDEFINED, start at 1
    for (uint32_t fi = 1, fe = uint32_t(kLastBaseFormat) + 1; fi < fe; ++fi) {
      const auto f = VkFormat(fi);
      if (UncompressedFormatMetadata md = get_uncompressed_format_metadata(f)) {
        if ( md.channel_count == channel_count &&
             md.is_homogenous() &&
             md.has_numeric_format(nf) &&
             md.channels[0].bit_count == channel_bit_count &&
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

  inline bool is_extended_format(VkFormat fmt) {
    return uint32_t(fmt) > 1000000000u;
  }

  // returns the extension number which introduce the given format
  inline uint32_t get_format_extension(VkFormat fmt) {
    return !is_extended_format(fmt) ? 0u : ((uint32_t(fmt) - 1000000000u) / 1000u) + 1u;
  }

  inline uint32_t get_uncompressed_mip_size_bytes(VkFormat format, uvec2 image_size, uint32_t mip, uint32_t array_len=1) {
    return get_uncompressed_mip_texel_count(image_size, mip, array_len) * get_uncompressed_format_metadata(format).size_bytes;
  }

  inline uint32_t get_uncompressed_mip_byte_offset(VkFormat format, const uvec2& image_size, uint32_t mip, uint32_t array_len=1) {
    return get_uncompressed_image_texel_count(image_size, mip, array_len) * get_uncompressed_format_metadata(format).size_bytes;
  }

  inline VkFormatFeatureFlags image_usage_to_format_feature_flags(VkImageUsageFlags usage) {
    VkFormatFeatureFlags flags = 0;
    if (usage & VK_IMAGE_USAGE_TRANSFER_SRC_BIT) { flags |= VK_FORMAT_FEATURE_TRANSFER_SRC_BIT; }
    if (usage & VK_IMAGE_USAGE_TRANSFER_DST_BIT) { flags |= VK_FORMAT_FEATURE_TRANSFER_DST_BIT; }
    if (usage & VK_IMAGE_USAGE_SAMPLED_BIT) { flags |= VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT; }
    if (usage & VK_IMAGE_USAGE_STORAGE_BIT) { flags |= VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT; }
    if (usage & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT) { flags |= VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT; }
    if (usage & VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT) { flags |= VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT; }
    return flags;
  }
} // namespace vku

