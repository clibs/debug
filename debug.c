
/**
 * `debug.c' - debug.c
 *
 * copyright (c) 2014 joseph werle <joseph.werle@gmail.com>
 */

#include <string.h>
#include <strsplit/strsplit.h>
#include "debug.h"

int
debug_enabled (const char *name) {
  char *d = getenv("DEBUG");
  size_t size = 0;
  char **debugs = NULL;
  int i = 0;
  if (NULL == d) { return 0; }
  debugs = calloc(1, sizeof(char));
  size = strsplit(d, debugs, ",");
  if (0 == size) { return free(debugs), 0; }
  for (i = 0; i < size; ++i) {
    if (0 == strcmp(name, debugs[i])) {
      return free(debugs), 1;
    }
  }
  return 0;
}
