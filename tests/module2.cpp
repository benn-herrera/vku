#include "vku/vku.h"
#include "test.h"

void module2() {
  VkImage vi = VK_NULL_HANDLE;
  vku::Image ui; (void)ui;
  CHECK(!ui);

  ui = vi;
  vi = ui;
  CHECK(ui == vi);
  CHECK((ui != vi) == false);
  VkFlags vflags = 0;
  vku::Flags uflags;
  CHECK(!uflags);

  CHECK(!strcmp(vku::to_string(VK_FORMAT_UNDEFINED), "VK_FORMAT_UNDEFINED"));
  CHECK(!strcmp(vku::to_string(VK_FORMAT_R8G8B8A8_SRGB), "VK_FORMAT_R8G8B8A8_SRGB"));
  CHECK(!strcmp(vku::to_string(VK_FORMAT_A2B10G10R10_SINT_PACK32), "VK_FORMAT_A2B10G10R10_SINT_PACK32"));
  CHECK(!strcmp(vku::to_string(VK_FORMAT_ASTC_12x12_SRGB_BLOCK), "VK_FORMAT_ASTC_12x12_SRGB_BLOCK"));
  CHECK(!vku::to_string(VkFormat(vku::Format::kInvalid)));
}
