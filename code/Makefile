##
# Basic Makefile for C
##

###############################################################################
# Variables
###############################################################################

# Compiler Options
CC = gcc
CC_FLAGS = -Wall

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

# Build BSG tests
test%: test%.c $(OBJS) $(HEADERS)
	$(CC) $(CC_FLAGS) $< -o $@ $(OBJS)

# Build and Run tests
.PHONY: test
test: $(TEST_BIN)
	./test_vehicle
	./test_bsg
	./test_battery

# Auxiliar Roles --------------------------------------------------------------

# Remove generated files
.PHONY: clear
clear:
	-rm -vf ${OBJS} ${BIN} ${TEST_BIN}
