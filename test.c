
/**
 * `test.c' - debug.c
 *
 * copyright (c) 2014 joseph werle <joseph.werle@gmail.com>
 */

#include "debug.h"

debug_init(active)
debug_init(inactive)

debug_t debug;
debug_t debug2;

int
main (void) {
  debug = debug_get(active);
  debug2 = debug_get(inactive);

  debug("should see this");
  debug2("should not see this");
  return 0;
}
