CC      := clang
CFLAGS  := -std=c11 -Wall -Wextra -Wpedantic
OPT     := -O3 -march=native
DBG     := -O0 -g -fsanitize=address,undefined -fno-omit-frame-pointer

SRC     := $(wildcard src/*.c)
HDR     := $(wildcard src/*.h)
BUILD   := build
LIB     := $(BUILD)/libffengine.dylib

.PHONY: all debug test clean

all: $(LIB)

$(LIB): $(SRC) $(HDR) | $(BUILD)
	$(CC) $(CFLAGS) $(OPT) -dynamiclib $(SRC) -o $@

# Tests always build with sanitizers so grid out-of-bounds writes crash loudly.
$(BUILD)/test: $(SRC) $(HDR) tests/*.c | $(BUILD)
	$(CC) $(CFLAGS) $(DBG) $(SRC) tests/*.c -o $@

test: $(BUILD)/test
	./$(BUILD)/test

debug: CFLAGS += $(DBG)
debug: OPT :=
debug: $(LIB)

$(BUILD):
	mkdir -p $@

clean:
	rm -rf $(BUILD)
