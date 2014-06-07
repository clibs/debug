
CC ?= cc
VALGRIND ?= valgrind
OS ?= $(shell uname)

SRC = debug.c $(wildcard deps/*/*.c)
OBJS = $(SRC:.c=.o)
TESTS = test.c

PREFIX ?= /usr/local
MAN1PREFIX ?= /usr/local/share/man1
MAN2PREFIX ?= /usr/local/share/man2
MAN3PREFIX ?= /usr/local/share/man3

MAN_FILES = man/*.{1,2,3}
MAN_TPLS = man/*.md

VERSION = 0.0.1
VERSION_MAJOR = 0
VERSION_MINOR = 0
VERSION_PATCH = 1

CFLAGS += -std=c99 -Wall -O2 -fvisibility=hidden -fPIC -pedantic -Ideps
LDFLAGS += -o $(TARGET_DSOLIB) -shared $(TARGET_DSO).$(VERSION_MAJOR)

ifeq ($(OS), Darwin)
	LDFLAGS += -lc -Wl,-install_name,$(TARGET_DSO)
endif

all: $(OBJS)

$(OBJS):
	@echo $(@)
	@echo $(OBJS)
	$(CC) $(CFLAGS) -c -o $@ $(@:.o=.c)

test: $(OBJS) $(TESTS)

$(TESTS):
	 $(CC) $(OBJS) $(@) $(CFLAGS) -o $(@:.c=)
	 DEBUG=active,*bar ./$(@:.c=)
	rm -f $(@:.c=)

$(MAN_FILES): $(MAN_TPLS)

$(MAN_TPLS):
	 curl -# -F page=@$(@) -o $(@:%.md=%) http://mantastic.herokuapp.com

clean:
	rm -f $(OBJS) $(BIN) $(TARGET_STATIC) $(TARGET_DSO) $(TARGET_DSOLIB) *.so*

.PHONY: $(MAN_FILES) $(TESTS) $(BIN) test
