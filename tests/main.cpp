#define VKU_IMPLEMENT
#include "vku/vku.h"
#include "test.h"

int checks = 0;
int failures = 0;

// TODO: generate test cases
int main() {
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

  if (failures) {
    fprintf(stderr, "FAILED %d/%d checks.\n", failures, checks);
  } else {
    printf("passed all %d checks.\n", checks);
  }
  return failures ? 1 : 0;
}
