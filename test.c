
/**
 * `test.c' - debug.c
 *
 * copyright (c) 2014 joseph werle <joseph.werle@gmail.com>
 */

#include "debug.h"


debug_init(active)
debug_init(inactive)

int
main (void) {
  debug_t debug = debug_get(active);
  debug_t debug2 = debug_get(inactive);

  debug("should see this");
  debug2("should not see this");
  return 0;
}
