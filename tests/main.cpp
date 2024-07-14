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
  CHECK(bool(vku::get_uncompressed_format_metadata(VK_FORMAT_BC1_RGB_UNORM_BLOCK)) == false);
  CHECK(!vku::get_uncompressed_format_metadata(VK_FORMAT_BC1_RGB_UNORM_BLOCK));
  CHECK(bool(vku::get_video_format_metadata(VK_FORMAT_BC1_RGB_UNORM_BLOCK)) == false);
  CHECK(!vku::get_video_format_metadata(VK_FORMAT_BC1_RGB_UNORM_BLOCK));

  {
    auto md = vku::get_uncompressed_format_metadata(VK_FORMAT_R4G4_UNORM_PACK8);
    CHECK(md);
    CHECK(!md == false);
    CHECK(md.is_packed());
    CHECK(!md.is_depth_stencil());
    CHECK(!md.has_depth());
    CHECK(!md.has_stencil());
    CHECK(md.has_numeric_format(vku::NumericFormat::UNORM));
    CHECK(!md.is_rgb());
    CHECK(!md.is_rgba());
    CHECK(!md.is_srgb());
    CHECK(md.is_homogenous());
    CHECK(md.channel_count == 2);
    CHECK(md.channels[0].numeric_format == vku::NumericFormat::UNORM);
    CHECK(md.channels[0].bit_count == 4);
    CHECK(md.channels[0].bit_shift == 4);
    CHECK(md.channels[1].numeric_format == vku::NumericFormat::UNORM);
    CHECK(md.channels[1].bit_count == 4);
    CHECK(md.channels[1].bit_shift == 0);
    CHECK(md.channels[2].numeric_format == vku::NumericFormat::Invalid);
    CHECK(md.channels[3].numeric_format == vku::NumericFormat::Invalid);
  }
  {
    auto md = vku::get_compressed_format_metadata(VK_FORMAT_BC1_RGB_UNORM_BLOCK);
    CHECK(md);
    CHECK(!md == false);
    CHECK(md.channel_count == 3);
    CHECK(md.numeric_format == vku::NumericFormat::UNORM);
  }
}


int main() {
  checks = 0;
  failures = 0;
  // force reference to module2.obj
  module2();

  spot_check_format_to_str();

  if (failures) {
    fprintf(stderr, "FAILED %d/%d checks.\n", failures, checks);
  } else {
    printf("passed all %d checks.\n", checks);
  }
  return failures ? 1 : 0;
}
