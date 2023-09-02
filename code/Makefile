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
MAKEFILE_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

###############################################################################
# Rules
###############################################################################

# Print help for Makefile commands
.PHONY: help
help:
	@echo "Use: make -f Makefile [OPTION]"
	@echo "\nOPTIONS"
	@sed Makefile -n -e "N;s/^# \(.*\)\n.PHONY:\(.*\)/ \2:\1/p;D" | column -ts:
	@echo ""


# Build -----------------------------------------------------------------------

.PHONY: build
build: test_bsg main

# Build BSG lib
bsg.o: bsg.c bsg.h
	$(CC) $(CC_FLAGS) -c bsg.c

# Build BSG bin
main: bsg.o
	$(CC) $(CC_FLAGS) main.c -o main $^

# Tests -----------------------------------------------------------------------

# Build BSG test
test_bsg: test_bsg.c bsg.h bsg.o
	$(CC) $(CC_FLAGS) test_bsg.c -o test_bsg bsg.o

# Build and Run tests
.PHONY: test
test: test_bsg
	./$<

# Auxiliar Roles --------------------------------------------------------------

# Clear Generated Files
clear:
	@rm -v bsg test_bsg