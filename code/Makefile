##
# Basic Makefile for C
##

###############################################################################
# Variables
###############################################################################

# Compiler Options
CC = gcc
CC_FLAGS = -Wall -ggdb -Werror -Wpedantic

# Get Makefile directory (enables using it as reference for relative paths)
MAKEFILE_DIR:=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

BIN := main
TEST_BIN := $(patsubst %.c,%, $(wildcard test_*.c))
SRCS := $(wildcard *.c)
HEADERS := $(wildcard *.h)
OBJS := $(filter-out test% main%, $(patsubst %.c,%.o, $(SRCS)))

###############################################################################
# Rules
###############################################################################

# Build -----------------------------------------------------------------------

# Build all source files
.PHONY: build
build: $(TEST_BIN) main

# Build BSG objects
%.o: %.c %.h
	$(CC) $(CC_FLAGS) -c $<

# Build BSG bin
$(BIN): main.c $(OBJS) $(HEADERS)
	$(CC) $(CC_FLAGS) $< -o $@ $(OBJS)

# Run -------------------------------------------------------------------------

# Build and Run binary
.PHONY: run
run: $(BIN)
	./$<

# Tests -----------------------------------------------------------------------

# Install test lib
.PHONY: testlib
testlib: utest/utest.h

# Ensure utest.h is available
utest/utest.h:
	git submodule update --init --recursive

# Build BSG tests
test%: test%.c $(OBJS) $(HEADERS) utest/utest.h
	$(CC) $(CC_FLAGS) $< -o $@ $(OBJS)

# Build and Run tests
.PHONY: test
test: $(TEST_BIN)
	./test_vehicle
	./test_bsg
	./test_battery
	./test_csvutils

# Documentation ---------------------------------------------------------------
# Build Documentation using Doxygen
.PHONY: docs
docs: ../docs/html/index.html

# Build HTML Code documentation
../docs/html/index.html: Doxyfile $(SRCS) $(HEADERS)
	doxygen Doxyfile

# Remove generated files from documentation
.PHONY: clear-docs
clear-docs:
	-rm -rfv ../docs/html
	-rm -rfv ../docs/latex

# Auxiliar Roles --------------------------------------------------------------

# Remove generated files
.PHONY: clear
clear:
	-rm -vf ${OBJS} ${BIN} ${TEST_BIN}
