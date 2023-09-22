##
# Project Makefile to automate all project steps
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
SRCS_DIR := $(MAKEFILE_DIR)

# Build files and directories
BIN := main
TEST_SRC := $(wildcard test_*.c)
TEST_BIN := $(patsubst %.c,%, $(TEST_SRC))
SRCS := $(wildcard *.c)
HEADERS := $(wildcard *.h)
OBJS := $(patsubst %.c,%.o, $(filter-out $(TEST_SRC) main.c, $(SRCS)))

# Test lib dir
TEST_LIB_DIR := $(abspath $(SRCS_DIR)/utest)
TEST_LIB_HEADER := $(abspath $(TEST_LIB_DIR)/utest.h)

# Docs
DOCS_DIR := $(realpath $(MAKEFILE_DIR)/../docs)
DOCS_HTML_DIR := $(abspath $(DOCS_DIR)/doxygen)
DOCS_HTML_PAGE := $(abspath $(DOCS_HTML_DIR)/index.html)

# Lib
LIB := libbsg.so
LIB_DIR := $(MAKEFILE_DIR)

# Coverage Files
COV_SRCS := $(filter-out test% main%, $(SRCS))
GCOV_FILES := $(patsubst %.c,%.c.gcov, $(SRCS))
GCDA_FILES := $(patsubst %.c,%.gcda, $(SRCS))
GCNO_FILES := $(patsubst %.c,%.gcno, $(SRCS))
LCOV_REPORT_DIR := $(abspath $(DOCS_DIR)/lcov)
LCOV_REPORT_INFO := $(abspath $(LCOV_REPORT_DIR)/coverage.info)
LCOV_REPORT_HTML := $(abspath $(LCOV_REPORT_DIR)/index.html)
GCOVR_REPORT_DIR := $(abspath $(DOCS_DIR)/gcovr)
GCOVR_REPORT_HTML := $(abspath $(GCOVR_REPORT_DIR)/index.html)

# Coverage target
COV_TARGET := 50

# CSV data
CSV_DATA_DIR := ${MAKEFILE_DIR}/data

###############################################################################
# Rules
###############################################################################

# Build -----------------------------------------------------------------------

# Build all source files
.PHONY: build
build: $(TEST_BIN) main

# Build BSG objects
%.o: %.c %.h
	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS_BUILD) -c $< -o $@

# Build BSG bin
$(BIN): main.c $(LIB)
	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS_LD) $< -o $@ $(OBJS)
#	$(CC) -L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) $(CC_FLAGS) $(COVERAGE_FLAGS_LD) -o $@  $< -lbsg

# Lib -------------------------------------------------------------------------

# Create shared library
.PHONY: lib
lib: $(LIB)

$(LIB): $(OBJS) $(HEADERS)
	$(CC) -shared -o $@ $(OBJS)

# Run -------------------------------------------------------------------------

# Build and Run binary
.PHONY: run
run: $(BIN) 
	./$< $(CSV_DATA_DIR)/inputSignal.csv $(CSV_DATA_DIR)/outputSignal.csv

# Tests -----------------------------------------------------------------------

# Install test lib
.PHONY: testlib
testlib: $(TEST_LIB_HEADER)

# Ensure utest.h is available
$(TEST_LIB_HEADER):
	git submodule update --init --recursive

# Build BSG tests
test%: test%.c $(OBJS) $(HEADERS) testlib
	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS_LD)  $< -o $@ $(OBJS)

# Build and Run tests
.PHONY: test
test: $(TEST_BIN)
	./test_calibration
	./test_vehicle
	./test_bsg
	./test_battery
	./test_csvutils

# Test Coverage ---------------------------------------------------------------

# deps: gcc, lcov, gcovr

# Generate Coverage reports
.PHONY: coverage
coverage: lcov-report gcovr-report

# Generate GCOV Report
.PHONY: gcov_output
gcov_output: $(GCOV_FILES)

$(GCOV_FILES): gcov_coverage

# Run code coverage
.PHONY: gcov_coverage
gcov_coverage:
	gcov $(SRCS)

# Create report directories
$(LCOV_REPORT_DIR) $(GCOVR_REPORT_DIR):
	mkdir -p $@

# Generate LCOV reports
.PHONY: lcov-report
lcov-report: $(LCOV_REPORT_HTML)

# Generate LCOV info report
$(LCOV_REPORT_INFO): $(LCOV_REPORT_DIR) gcov_coverage
	lcov --capture --rc lcov_branch_coverage=1 \
	     --directory $(SRCS_DIR) \
		 --output-file $@

# Generate LCOV html report
$(LCOV_REPORT_HTML): $(LCOV_REPORT_INFO) $(LCOV_REPORT_DIR)
	genhtml $< --branch-coverage --output-directory $(LCOV_REPORT_DIR)

# Generate GCOVR report
.PHONY: gcovr-report
gcovr-report: $(GCOVR_REPORT_HTML) gcov_coverage

# Generate GCOVR html report
$(GCOVR_REPORT_HTML): $(GCOVR_REPORT_DIR)
	cd $(SRCS_DIR) && \
	gcovr -v --sort-percentage --print-summary --branches \
		  --fail-under-line $(COV_TARGET) \
		  --fail-under-branch $(COV_TARGET) \
		  --exclude ".*test_.*" \
		  --exclude $(TEST_LIB_DIR) \
		  --html-details --html -o $(GCOVR_REPORT_HTML)

.PHONY: clear-coverage
clear-coverage:
	-rm -rf $(GCDA_FILES)
	-rm -rf $(GCNO_FILES)
	-rm -rf $(GCOV_FILES)
	-rm -rf $(LCOV_REPORT_DIR) $(GCOVR_REPORT_DIR)

# Documentation ---------------------------------------------------------------
# Build Documentation using Doxygen
.PHONY: docs
docs: $(DOCS_HTML_PAGE)

# Build HTML Code documentation
$(DOCS_HTML_PAGE): Doxyfile $(SRCS) $(HEADERS)
	doxygen Doxyfile

# Remove generated files from documentation
.PHONY: clear-docs
clear-docs:
	-rm -rfv $(DOCS_HTML_DIR)

# Auxiliar Roles --------------------------------------------------------------

# Remove generated files
.PHONY: clear
clear: clear-coverage
	-rm -vf ${OBJS} ${BIN} ${TEST_BIN}
