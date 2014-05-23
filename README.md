debug
=====

Conditional debug logging for C

## install

```sh
$ clib install debug
```

## usage

```c

#include "debug.h"

debug_init(app)
debug_init(connection)
debug_init(error)

debug_t app_debug;
debug_t conn_debug;
debug_t err_debug;

int
main (void) {
  app_debug = debug_get(app);
  conn_debug = debug_get(connection);
  err_debug = debug_get(error);

  app_debug("starting application '%s'", "wooooo");

  // more logic later..
  return 0;
}
```

```sh
$ DEBUG=app ./program
app - starting application 'wooooo'
```

## license

MIT
