#include "vku/vku.h"
#include "test.h"

int checks = 0;
int failures = 0;

void spot_check_format_to_str() {
  CHECK(!strcmp(vku::to_string(VK_FORMAT_UNDEFINED), "VK_FORMAT_UNDEFINED"));
  CHECK(!strcmp(vku::to_string(VK_FORMAT_R8G8B8A8_SRGB), "VK_FORMAT_R8G8B8A8_SRGB"));
  CHECK(!strcmp(vku::to_string(VK_FORMAT_A2B10G10R10_SINT_PACK32), "VK_FORMAT_A2B10G10R10_SINT_PACK32"));
  CHECK(!strcmp(vku::to_string(VK_FORMAT_ASTC_12x12_SRGB_BLOCK), "VK_FORMAT_ASTC_12x12_SRGB_BLOCK"));
  CHECK(!vku::to_string(VkFormat(~0u)));
  CHECK(!strcmp(vku::to_string(VkFormat(~0u), "UNDEFINED"), "UNDEFINED"));
}

void spot_check_get_format_metadata() {
  {
    auto md = vku::get_uncompressed_format_metadata(VK_FORMAT_R4G4_UNORM_PACK8);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_R4G4_UNORM_PACK8));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_R4G4_UNORM_PACK8));
    CHECK(md);
    CHECK(!md == false);
    CHECK(md.is_packed());
    CHECK(!md.is_depth_stencil());
    CHECK(!md.has_depth());
    CHECK(!md.has_stencil());
    CHECK(md.has_numeric_format(vku::NumericFormat::UNORM));
    CHECK(!md.has_numeric_format(vku::NumericFormat::UINT));
    CHECK(!md.is_rgb());
    CHECK(!md.is_rgba());
    CHECK(!md.is_srgb());
    CHECK(md.is_homogenous());
    CHECK(md.channel_count == 2);
    CHECK(md.size_bytes == 1);
    CHECK(md.channels[0].type == vku::ChannelType::R);
    CHECK(md.channels[0].numeric_format == vku::NumericFormat::UNORM);
    CHECK(md.channels[0].bit_count == 4);
    CHECK(md.channels[0].bit_shift == 4);
    CHECK(md.channels[1].type == vku::ChannelType::G);
    CHECK(md.channels[1].numeric_format == vku::NumericFormat::UNORM);
    CHECK(md.channels[1].bit_count == 4);
    CHECK(md.channels[1].bit_shift == 0);
    CHECK(md.channels[2].type == vku::ChannelType::Invalid);
    CHECK(md.channels[2].numeric_format == vku::NumericFormat::Invalid);
    CHECK(md.channels[3].type == vku::ChannelType::Invalid);
    CHECK(md.channels[3].numeric_format == vku::NumericFormat::Invalid);
  }
  {   
    auto md = vku::get_uncompressed_format_metadata(VK_FORMAT_R10X6G10X6_UNORM_2PACK16);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_R10X6G10X6_UNORM_2PACK16));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_R10X6G10X6_UNORM_2PACK16));
    CHECK(md);
    CHECK(!md == false);
    CHECK(md.is_packed());
    CHECK(!md.is_depth_stencil());
    CHECK(!md.has_depth());
    CHECK(!md.has_stencil());
    CHECK(md.has_numeric_format(vku::NumericFormat::UNORM));
    CHECK(!md.has_numeric_format(vku::NumericFormat::UINT));
    CHECK(!md.is_rgb());
    CHECK(!md.is_rgba());
    CHECK(!md.is_srgb());
    CHECK(md.is_homogenous());
    CHECK(md.channel_count == 2);
    CHECK(md.size_bytes == 4);
    CHECK(md.channels[0].type == vku::ChannelType::R);
    CHECK(md.channels[0].numeric_format == vku::NumericFormat::UNORM);
    CHECK(md.channels[0].bit_count == 10);
    CHECK(md.channels[0].bit_shift == 22);
    CHECK(md.channels[1].type == vku::ChannelType::G);
    CHECK(md.channels[1].numeric_format == vku::NumericFormat::UNORM);
    CHECK(md.channels[1].bit_count == 10);
    CHECK(md.channels[1].bit_shift == 6);
    CHECK(md.channels[2].type == vku::ChannelType::Invalid);
    CHECK(md.channels[2].numeric_format == vku::NumericFormat::Invalid);
    CHECK(md.channels[3].type == vku::ChannelType::Invalid);
    CHECK(md.channels[3].numeric_format == vku::NumericFormat::Invalid);
  }
  {
    auto md = vku::get_uncompressed_format_metadata(VK_FORMAT_D16_UNORM);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_D16_UNORM));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_D16_UNORM));
    CHECK(md);
    CHECK(!md == false);
    CHECK(!md.is_packed());
    CHECK(!md.is_depth_stencil());
    CHECK(md.has_depth());
    CHECK(!md.has_stencil());
    CHECK(md.has_numeric_format(vku::NumericFormat::UNORM));
    CHECK(!md.has_numeric_format(vku::NumericFormat::UINT));
    CHECK(!md.is_rgb());
    CHECK(!md.is_rgba());
    CHECK(!md.is_srgb());
    CHECK(md.is_homogenous());
    CHECK(md.channel_count == 1);
    CHECK(md.size_bytes == 2);
    CHECK(md.channels[0].type == vku::ChannelType::D);
    CHECK(md.channels[0].numeric_format == vku::NumericFormat::UNORM);
    CHECK(md.channels[0].bit_count == 16);
    CHECK(md.channels[0].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[1].type == vku::ChannelType::Invalid);
    CHECK(md.channels[1].numeric_format == vku::NumericFormat::Invalid);
    CHECK(md.channels[2].type == vku::ChannelType::Invalid);
    CHECK(md.channels[2].numeric_format == vku::NumericFormat::Invalid);
    CHECK(md.channels[3].type == vku::ChannelType::Invalid);
    CHECK(md.channels[3].numeric_format == vku::NumericFormat::Invalid);
  }
  {
    auto md = vku::get_uncompressed_format_metadata(VK_FORMAT_S8_UINT);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_S8_UINT));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_S8_UINT));
    CHECK(md);
    CHECK(!md == false);
    CHECK(!md.is_packed());
    CHECK(!md.is_depth_stencil());
    CHECK(!md.has_depth());
    CHECK(md.has_stencil());
    CHECK(md.has_numeric_format(vku::NumericFormat::UINT));
    CHECK(!md.has_numeric_format(vku::NumericFormat::UNORM));
    CHECK(!md.is_rgb());
    CHECK(!md.is_rgba());
    CHECK(!md.is_srgb());
    CHECK(md.is_homogenous());
    CHECK(md.channel_count == 1);
    CHECK(md.size_bytes == 1);
    CHECK(md.channels[0].type == vku::ChannelType::S);
    CHECK(md.channels[0].numeric_format == vku::NumericFormat::UINT);
    CHECK(md.channels[0].bit_count == 8);
    CHECK(md.channels[0].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[1].type == vku::ChannelType::Invalid);
    CHECK(md.channels[1].numeric_format == vku::NumericFormat::Invalid);
    CHECK(md.channels[2].type == vku::ChannelType::Invalid);
    CHECK(md.channels[2].numeric_format == vku::NumericFormat::Invalid);
    CHECK(md.channels[3].type == vku::ChannelType::Invalid);
    CHECK(md.channels[3].numeric_format == vku::NumericFormat::Invalid);
  }
  {
    auto md = vku::get_uncompressed_format_metadata(VK_FORMAT_D16_UNORM_S8_UINT);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_D16_UNORM_S8_UINT));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_D16_UNORM_S8_UINT));
    CHECK(md);
    CHECK(!md == false);
    CHECK(!md.is_packed());
    CHECK(md.is_depth_stencil());
    CHECK(md.has_depth());
    CHECK(md.has_stencil());
    CHECK(md.has_numeric_format(vku::NumericFormat::UNORM));
    CHECK(md.has_numeric_format(vku::NumericFormat::UINT));
    CHECK(!md.is_rgb());
    CHECK(!md.is_rgba());
    CHECK(!md.is_srgb());
    CHECK(!md.is_homogenous());
    CHECK(md.channel_count == 2);
    CHECK(md.size_bytes == 3);
    CHECK(md.channels[0].type == vku::ChannelType::D);
    CHECK(md.channels[0].numeric_format == vku::NumericFormat::UNORM);
    CHECK(md.channels[0].bit_count == 16);
    CHECK(md.channels[0].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[1].type == vku::ChannelType::S);
    CHECK(md.channels[1].numeric_format == vku::NumericFormat::UINT);
    CHECK(md.channels[1].bit_count == 8);
    CHECK(md.channels[1].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[2].type == vku::ChannelType::Invalid);
    CHECK(md.channels[2].numeric_format == vku::NumericFormat::Invalid);
    CHECK(md.channels[3].type == vku::ChannelType::Invalid);
    CHECK(md.channels[3].numeric_format == vku::NumericFormat::Invalid);
  }
  {
    auto md = vku::get_uncompressed_format_metadata(VK_FORMAT_R8G8B8_SRGB);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_R8G8B8_SRGB));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_R8G8B8_SRGB));
    CHECK(md);
    CHECK(!md == false);
    CHECK(!md.is_packed());
    CHECK(!md.is_depth_stencil());
    CHECK(!md.has_depth());
    CHECK(!md.has_stencil());
    CHECK(md.has_numeric_format(vku::NumericFormat::SRGB));
    CHECK(!md.has_numeric_format(vku::NumericFormat::SFLOAT));
    CHECK(md.is_rgb());
    CHECK(!md.is_rgba());
    CHECK(md.is_srgb());
    CHECK(md.is_homogenous());
    CHECK(md.channel_count == 3);
    CHECK(md.size_bytes == 3);
    CHECK(md.channels[0].type == vku::ChannelType::R);
    CHECK(md.channels[0].numeric_format == vku::NumericFormat::SRGB);
    CHECK(md.channels[0].bit_count == 8);
    CHECK(md.channels[0].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[1].type == vku::ChannelType::G);
    CHECK(md.channels[1].numeric_format == vku::NumericFormat::SRGB);
    CHECK(md.channels[1].bit_count == 8);
    CHECK(md.channels[1].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[2].type == vku::ChannelType::B);
    CHECK(md.channels[2].numeric_format == vku::NumericFormat::SRGB);
    CHECK(md.channels[2].bit_count == 8);
    CHECK(md.channels[2].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[3].type == vku::ChannelType::Invalid);
    CHECK(md.channels[3].numeric_format == vku::NumericFormat::Invalid);
    CHECK(md.channels[3].bit_count == 0);
  }
  {
    auto md = vku::get_uncompressed_format_metadata(VK_FORMAT_B8G8R8A8_SSCALED);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_B8G8R8A8_SSCALED));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_B8G8R8A8_SSCALED));
    CHECK(md);
    CHECK(!md == false);
    CHECK(!md.is_packed());
    CHECK(!md.is_depth_stencil());
    CHECK(!md.has_depth());
    CHECK(!md.has_stencil());
    CHECK(md.has_numeric_format(vku::NumericFormat::SSCALED));
    CHECK(!md.has_numeric_format(vku::NumericFormat::USCALED));
    CHECK(!md.is_rgb());
    CHECK(!md.is_rgba());
    CHECK(md.is_bgra());
    CHECK(!md.is_srgb());
    CHECK(md.is_homogenous());
    CHECK(md.channel_count == 4);
    CHECK(md.size_bytes == 4);
    CHECK(md.channels[0].type == vku::ChannelType::B);
    CHECK(md.channels[0].numeric_format == vku::NumericFormat::SSCALED);
    CHECK(md.channels[0].bit_count == 8);
    CHECK(md.channels[0].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[1].type == vku::ChannelType::G);
    CHECK(md.channels[1].numeric_format == vku::NumericFormat::SSCALED);
    CHECK(md.channels[1].bit_count == 8);
    CHECK(md.channels[1].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[2].type == vku::ChannelType::R);
    CHECK(md.channels[2].numeric_format == vku::NumericFormat::SSCALED);
    CHECK(md.channels[2].bit_count == 8);
    CHECK(md.channels[2].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[3].type == vku::ChannelType::A);
    CHECK(md.channels[3].numeric_format == vku::NumericFormat::SSCALED);
    CHECK(md.channels[3].bit_count == 8);
    CHECK(md.channels[3].bit_shift == vku::ChannelMetadata::kNoShift);
  }
  {
    auto md = vku::get_uncompressed_format_metadata(VK_FORMAT_E5B9G9R9_UFLOAT_PACK32);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_E5B9G9R9_UFLOAT_PACK32));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_E5B9G9R9_UFLOAT_PACK32));
    CHECK(md);
    CHECK(!md == false);
    CHECK(md.is_packed());
    CHECK(!md.is_depth_stencil());
    CHECK(!md.has_depth());
    CHECK(!md.has_stencil());
    CHECK(md.has_numeric_format(vku::NumericFormat::UFLOAT));
    CHECK(md.has_numeric_format(vku::NumericFormat::SINT));
    CHECK(!md.has_numeric_format(vku::NumericFormat::SFLOAT));
    CHECK(md.is_ebgr());
    CHECK(!md.is_rgb());
    CHECK(!md.is_rgba());
    CHECK(!md.is_srgb());
    CHECK(!md.is_homogenous());
    CHECK(md.channel_count == 4);
    CHECK(md.size_bytes == 4);
    CHECK(md.channels[0].type == vku::ChannelType::E);
    CHECK(md.channels[0].numeric_format == vku::NumericFormat::SINT);
    CHECK(md.channels[0].bit_count == 5);
    CHECK(md.channels[0].bit_shift == 27);
    CHECK(md.channels[1].type == vku::ChannelType::B);
    CHECK(md.channels[1].numeric_format == vku::NumericFormat::UFLOAT);
    CHECK(md.channels[1].bit_count == 9);
    CHECK(md.channels[1].bit_shift == 18);
    CHECK(md.channels[2].type == vku::ChannelType::G);
    CHECK(md.channels[2].numeric_format == vku::NumericFormat::UFLOAT);
    CHECK(md.channels[2].bit_count == 9);
    CHECK(md.channels[2].bit_shift == 9);
    CHECK(md.channels[3].type == vku::ChannelType::R);
    CHECK(md.channels[3].numeric_format == vku::NumericFormat::UFLOAT);
    CHECK(md.channels[3].bit_count == 9);
    CHECK(md.channels[3].bit_shift == 0);
  }
  {
    auto md = vku::get_uncompressed_format_metadata(VK_FORMAT_R64G64B64A64_SFLOAT);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_R64G64B64A64_SFLOAT));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_R64G64B64A64_SFLOAT));
    CHECK(md);
    CHECK(!md == false);
    CHECK(!md.is_packed());
    CHECK(!md.is_depth_stencil());
    CHECK(!md.has_depth());
    CHECK(!md.has_stencil());
    CHECK(md.has_numeric_format(vku::NumericFormat::SFLOAT));
    CHECK(!md.is_rgb());
    CHECK(md.is_rgba());
    CHECK(!md.is_srgb());
    CHECK(md.is_homogenous());
    CHECK(md.channel_count == 4);
    CHECK(md.size_bytes == 32);
    CHECK(md.channels[0].type == vku::ChannelType::R);
    CHECK(md.channels[0].numeric_format == vku::NumericFormat::SFLOAT);
    CHECK(md.channels[0].bit_count == 64);
    CHECK(md.channels[0].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[1].type == vku::ChannelType::G);
    CHECK(md.channels[1].numeric_format == vku::NumericFormat::SFLOAT);
    CHECK(md.channels[1].bit_count == 64);
    CHECK(md.channels[1].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[2].type == vku::ChannelType::B);
    CHECK(md.channels[2].numeric_format == vku::NumericFormat::SFLOAT);
    CHECK(md.channels[2].bit_count == 64);
    CHECK(md.channels[2].bit_shift == vku::ChannelMetadata::kNoShift);
    CHECK(md.channels[3].type == vku::ChannelType::A);
    CHECK(md.channels[3].numeric_format == vku::NumericFormat::SFLOAT);
    CHECK(md.channels[3].bit_count == 64);
    CHECK(md.channels[3].bit_shift == vku::ChannelMetadata::kNoShift);
  }
  {
    auto md = vku::get_compressed_format_metadata(VK_FORMAT_BC1_RGB_UNORM_BLOCK);
    CHECK(!vku::get_uncompressed_format_metadata(VK_FORMAT_BC1_RGB_UNORM_BLOCK));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_BC1_RGB_UNORM_BLOCK));
    CHECK(md);
    CHECK(!md == false);
    CHECK(!md.is_hdr());
    CHECK(!md.is_rgba());
    CHECK(md.is_rgb());
    CHECK(md.channel_count == 3);
    CHECK(md.block_size_bytes == 8);
    CHECK(md.block_width == 4 && md.block_height == 4);
    CHECK(md.numeric_format == vku::NumericFormat::UNORM);
  }
  {
    auto md = vku::get_compressed_format_metadata(VK_FORMAT_ASTC_5x4_SRGB_BLOCK);
    CHECK(!vku::get_uncompressed_format_metadata(VK_FORMAT_ASTC_5x4_SRGB_BLOCK));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_ASTC_5x4_SRGB_BLOCK));
    CHECK(md);
    CHECK(!md == false);
    CHECK(!md.is_hdr());
    CHECK(md.is_rgba());
    CHECK(!md.is_rgb());
    CHECK(md.channel_count == 4);
    CHECK(md.block_size_bytes == 16);
    CHECK(md.block_width == 5 && md.block_height == 4);
    CHECK(md.numeric_format == vku::NumericFormat::SRGB);
  }
  {
    auto md = vku::get_compressed_format_metadata(VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK);
    CHECK(!vku::get_uncompressed_format_metadata(VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK));
    CHECK(!vku::get_video_format_metadata(VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK));
    CHECK(md);
    CHECK(!md == false);
    CHECK(md.is_hdr());
    CHECK(md.is_rgba());
    CHECK(!md.is_rgb());
    CHECK(md.channel_count == 4);
    CHECK(md.block_size_bytes == 16);
    CHECK(md.block_width == 12 && md.block_height == 12);
    CHECK(md.numeric_format == vku::NumericFormat::SFLOAT);
  }
  {
    auto md = vku::get_video_format_metadata(VK_FORMAT_G8B8G8R8_422_UNORM);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_G8B8G8R8_422_UNORM));
    CHECK(!vku::get_uncompressed_format_metadata(VK_FORMAT_G8B8G8R8_422_UNORM));
    CHECK(md.block_size_bytes == 4);
    CHECK(md.block_width == 2);
    CHECK(md.channel_count == 3);
    CHECK(md.numeric_format == vku::NumericFormat::UNORM);
  }
  {
    auto md = vku::get_video_format_metadata(VK_FORMAT_B16G16R16G16_422_UNORM);
    CHECK(!vku::get_compressed_format_metadata(VK_FORMAT_B16G16R16G16_422_UNORM));
    CHECK(!vku::get_uncompressed_format_metadata(VK_FORMAT_B16G16R16G16_422_UNORM));
    CHECK(md.block_size_bytes == 8);
    CHECK(md.block_width == 2);
    CHECK(md.channel_count == 3);
    CHECK(md.numeric_format == vku::NumericFormat::UNORM);
  }
}

void spot_check_format_for() {
  CHECK(vku::vanilla_format_for(3, vku::NumericFormat::SRGB, 10, true) == VK_FORMAT_UNDEFINED);
  CHECK(vku::vanilla_format_for(3, vku::NumericFormat::SRGB, 8, false) == VK_FORMAT_R8G8B8_SRGB);
  CHECK(vku::vanilla_format_for(4, vku::NumericFormat::SFLOAT, 16, false) == VK_FORMAT_R16G16B16A16_SFLOAT);
  CHECK(vku::vanilla_format_for(2, vku::NumericFormat::UINT, 16, false) == VK_FORMAT_R16G16_UINT);
  CHECK(vku::vanilla_format_for(1, vku::NumericFormat::SFLOAT, 32, false) == VK_FORMAT_R32_SFLOAT);
  CHECK(vku::vanilla_format_for(2, vku::NumericFormat::SFLOAT, 64, false) == VK_FORMAT_R64G64_SFLOAT);
  CHECK(vku::vanilla_format_for(4, vku::NumericFormat::SNORM, 8, true) == VK_FORMAT_A8B8G8R8_SNORM_PACK32);
}

void spot_check_image_size_bytes() {
  CHECK(vku::get_uncompressed_mip_count(vku::uvec2{ 2, 1 }) == 1);
  CHECK(vku::get_uncompressed_mip_count(vku::uvec2{ 2, 2 }) == 2);
  CHECK(vku::get_uncompressed_mip_count(vku::uvec2{ 2, 4 }) == 2);
  CHECK(vku::get_uncompressed_mip_count(vku::uvec2{ 15, 20 }) == 4);
  CHECK(vku::get_uncompressed_mip_count(vku::uvec2{ 17, 20 }) == 5);
  CHECK(vku::get_uncompressed_image_size_bytes(VK_FORMAT_R16G16B16_SFLOAT, vku::uvec2{ 19, 20 }, false, 2) == 4560);
  CHECK(vku::get_uncompressed_image_size_bytes(VK_FORMAT_R16G16B16_SFLOAT, vku::uvec2{ 19, 20 }, true, 2) == 5940);
}


int main() {
  checks = 0;
  failures = 0;
  // force reference to module2.obj
  module2();

  spot_check_format_to_str();
  spot_check_get_format_metadata();
  spot_check_format_for();
  spot_check_image_size_bytes();

  if (failures) {
    fprintf(stderr, "FAILED %d/%d checks.\n", failures, checks);
  } else {
    printf("passed all %d checks.\n", checks);
  }
  return failures ? 1 : 0;
}
