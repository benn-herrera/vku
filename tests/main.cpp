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

  if (failures) {
    fprintf(stderr, "FAILED %d/%d checks.\n", failures, checks);
  } else {
    printf("passed all %d checks.\n", checks);
  }
  return failures ? 1 : 0;
}
