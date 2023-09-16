##
# Basic Makefile for C
##

###############################################################################
# Variables
###############################################################################

# Compiler Options
CC = gcc
CODE_QUALITY_FLAGS := -Wall -Werror -Wpedantic 
DEBUG_FLAGS := -ggdb -fprofile-arcs
COVERAGE_FLAGS_BUILD := -ftest-coverage 
COVERAGE_FLAGS_LD := -lgcov
CC_FLAGS = -fPIC $(CODE_QUALITY_FLAGS) $(DEBUG_FLAGS)

# Get Makefile directory (enables using it as reference for relative paths)
MAKEFILE_DIR:=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

# Build files and directories
BIN := main
TEST_BIN := $(patsubst %.c,%, $(wildcard test_*.c))
SRCS := $(wildcard *.c)
HEADERS := $(wildcard *.h)
OBJS := $(filter-out test% main%, $(patsubst %.c,%.o, $(SRCS)))
LIB := libbsg.so
LIB_DIR := $(MAKEFILE_DIR)

# Coverage Files
SRCS_DIR := $(MAKEFILE_DIR)
COV_SRCS := $(filter-out test% main%, $(SRCS))
GCOV_FILES := $(patsubst %.c,%.c.gcov, $(SRCS))
GCDA_FILES := $(patsubst %.c,%.gcda, $(SRCS))
GCNO_FILES := $(patsubst %.c,%.gcno, $(SRCS))
LCOV_REPORT_DIR := $(MAKEFILE_DIR)/lcov_report
LCOV_REPORT_INFO := $(LCOV_REPORT_DIR)/coverage.info
LCOV_REPORT_HTML := $(LCOV_REPORT_DIR)/index.html
GCOVR_REPORT_DIR := $(MAKEFILE_DIR)/gcovr_report
GCOVR_REPORT_HTML := $(GCOVR_REPORT_DIR)/coverage.html

###############################################################################
# Rules
###############################################################################

# Build -----------------------------------------------------------------------

# Build all source files
.PHONY: build
build: $(TEST_BIN) main

# Build BSG objects
%.o: %.c %.h
	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS_BUILD) -c $<

# Build BSG bin
$(BIN): main.c $(LIB)
	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS_LD) $< -o $@ $(OBJS)
#	$(CC) -L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) $(CC_FLAGS) $(COVERAGE_FLAGS_LD) -o $@  $< -lbsg

# Lib -------------------------------------------------------------------------

# Create shared library
.PHONY: lib
lib: $(LIB)

$(LIB): $(OBJS) $(HEADERS)
	$(CC) -shared -o $@ $^

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
	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS_LD)  $< -o $@ $(OBJS)

# Build and Run tests
.PHONY: test
test: $(TEST_BIN)
	./test_system

# Test Coverage ---------------------------------------------------------------

# deps: gcc, lcov, gcovr

# Generate GCOV Report
.PHONY: coverage
coverage: $(GCOV_FILES)

$(GCOV_FILES): gcov_coverage

# Run code coverage
.PHONY: gcov_coverage
gcov_coverage: test
	gcov $(SRCS)

# Create report directories
$(LCOV_REPORT_DIR) $(GCOVR_REPORT_DIR):
	mkdir -p $@

# Generate LCOV reports
.PHONY: lcov-report
lcov-report: $(LCOV_REPORT_HTML)

# Generate LCOV info report
$(LCOV_REPORT_INFO): $(LCOV_REPORT_DIR) coverage
	lcov --capture --directory $(SRCS_DIR) --output-file $@

# Generate LCOV html report
$(LCOV_REPORT_HTML): $(LCOV_REPORT_INFO) $(LCOV_REPORT_DIR)
	genhtml $< --output-directory $(LCOV_REPORT_DIR)

# Generate GCOVR report
.PHONY: gcovr-report
gcovr-report: $(GCOVR_REPORT_HTML) coverage

# Generate GCOVR html report
$(GCOVR_REPORT_HTML): $(GCOVR_REPORT_DIR)
	gcovr --root $(SRCS_DIR) --html --html-details --output $(GCOVR_REPORT_HTML)

.PHONY: clear-coverage
clear-coverage:
	-rm -rf $(GCDA_FILES)
	-rm -rf $(GCNO_FILES)
	-rm -rf $(GCOV_FILES)
	-rm -rf $(LCOV_REPORT_DIR) $(GCOVR_REPORT_DIR)

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
