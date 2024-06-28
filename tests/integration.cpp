#include "vku/vku.h"
#include <assert.h>

void noop() {  
}

// TODO: generate test
int main() {
  VkImage vi = VK_NULL_HANDLE;
  vku::Image ui; (void)ui;
  assert(!ui);

  ui = vi;
  vi = ui;
  if (ui == vi) {
    noop();
  }
  if (vi != ui) {
    noop();
  }
  VkFlags vflags = 0;
  vku::Flags uflags;
  assert(!uflags);
  return 0;
}
