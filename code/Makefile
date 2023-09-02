##
# Basic Makefile for C
##

# Compiler Options
CC = gcc
CC_FLAGS = -Wall

##
# Recipes
##
.PHONY: build
build: bsg test_bsg

# Compile
bsg: bsg.c bsg.h
	$(CC) $(CC_FLAGS) bsg.c -o bsg

# Compile
test_bsg: test_bsg.c bsg.h
	$(CC) $(CC_FLAGS) test_bsg.c -o test_bsg

# Build and Run tests
.PHONY: test
test: test_bsg
	./$<

# Clear Generated Files
clear:
	@rm -v bsg test_bsg