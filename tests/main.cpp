#include "vku/vku.h"
#include "test.h"

int checks = 0;
int failures = 0;

int main() {
  checks = 0;
  failures = 0;

  CHECK(!strcmp(vku::to_string(VK_FORMAT_UNDEFINED), "VK_FORMAT_UNDEFINED"));
  CHECK(!strcmp(vku::to_string(VK_FORMAT_R8G8B8A8_SRGB), "VK_FORMAT_R8G8B8A8_SRGB"));
  CHECK(!strcmp(vku::to_string(VK_FORMAT_A2B10G10R10_SINT_PACK32), "VK_FORMAT_A2B10G10R10_SINT_PACK32"));
  CHECK(!strcmp(vku::to_string(VK_FORMAT_ASTC_12x12_SRGB_BLOCK), "VK_FORMAT_ASTC_12x12_SRGB_BLOCK"));
  CHECK(!vku::to_string(VkFormat(~0u)));
  CHECK(!strcmp(vku::to_string(VkFormat(~0u), "UNDEFINED"), "UNDEFINED"));

  module2();

  if (failures) {
    fprintf(stderr, "FAILED %d/%d checks.\n", failures, checks);
  } else {
    printf("passed all %d checks.\n", checks);
  }
  return failures ? 1 : 0;
}
