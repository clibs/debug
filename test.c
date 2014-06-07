
/**
 * `test.c' - debug.c
 *
 * copyright (c) 2014 joseph werle <joseph.werle@gmail.com>
 */

#include "debug.h"

debug_init(foobar)
debug_init(foo_bar)
debug_init(foobaz)
debug_init(active)
debug_init(inactive)

debug_t debug;
debug_t debug2;
debug_t debug3;
debug_t debug4;
debug_t debug5;

int
main (void) {
  debug = debug_get(active);
  debug2 = debug_get(inactive);

  debug("should see this");
  debug2("should not see this");

  debug3 = debug_get(foobar);
  debug4 = debug_get(foo_bar);
  debug5 = debug_get(foobaz);

  debug3("should see this");
  debug4("should see this");
  debug5("should not see this");

  return 0;
}
