CC := clang
CFLAGS ?= -Wpedantic

BIN := numfun
FILES := $(shell echo *.c)
CLEANUP := $(BIN) a.out *.o *.a

EXAMPLE_X ?= 14.42
EXAMPLE_Y ?= 97.13

build: $(FILES)
	$(CC) $(CFLAGS) -o $(BIN) $(FILES)

example: build
	$(PWD)/$(BIN) $(EXAMPLE_X) $(EXAMPLE_Y)

clean:
	@rm -f $(CLEANUP)

.PHONY: clean

