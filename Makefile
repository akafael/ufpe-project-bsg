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
SRCS_DIR := $(realpath $(MAKEFILE_DIR)/code)
BIN_DIR := $(SRCS_DIR)

# Build files and directories
BIN := $(abspath $(BIN_DIR)/main)
TEST_SRC := $(wildcard $(SRCS_DIR)/test_*.c)
TEST_BIN := $(patsubst $(SRCS_DIR)/%.c,$(BIN_DIR)/%, $(TEST_SRC))
SRCS := $(wildcard $(SRCS_DIR)/*.c)
HEADERS := $(wildcard $(SRCS_DIR)/*.h)
OBJS := $(patsubst %.c,%.o, $(filter-out $(TEST_SRC) $(SRCS_DIR)/main.c, $(SRCS)))

# Test lib dir
TEST_LIB_DIR := $(abspath $(SRCS_DIR)/utest)
TEST_LIB_HEADER := $(abspath $(TEST_LIB_DIR)/utest.h)

# Docs
DOCS_DIR := $(realpath $(MAKEFILE_DIR)/docs)
DOCS_HTML_DIR := $(abspath $(DOCS_DIR)/doxygen)
DOCS_HTML_PAGE := $(abspath $(DOCS_HTML_DIR)/index.html)

# Lib
LIB_DIR := $(SRCS_DIR)
LIB := $(LIB_DIR)/libbsg.so

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
COV_TARGET := 80

# CSV data
CSV_DATA_DIR := ${SRCS_DIR}/data

###############################################################################
# Rules
###############################################################################

# Build -----------------------------------------------------------------------

# Build all source files
.PHONY: build
build: $(TEST_BIN) $(BIN)

# Build BSG objects
%.o: %.c %.h
	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS_BUILD) -c $< -o $@

# Build BSG bin
$(BIN): $(SRCS_DIR)/main.c $(LIB)
#	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS_LD) $< -o $@ $(OBJS)
	$(CC) -L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) $(CC_FLAGS) $(COVERAGE_FLAGS_LD) -o $@  $< -lbsg

# Lib -------------------------------------------------------------------------

# Create shared library
.PHONY: lib
lib: $(LIB)

$(LIB): $(OBJS) $(HEADERS)
	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS_LD) -shared -o $@ $(OBJS)

# Run -------------------------------------------------------------------------

# Build and Run binary
.PHONY: run
run: $(BIN) clear-coverage
	$< $(CSV_DATA_DIR)/inputSignal.csv $(CSV_DATA_DIR)/outputSignal.csv

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
	$(BIN_DIR)/test_calibration
	$(BIN_DIR)/test_engine
	$(BIN_DIR)/test_vehicle
	$(BIN_DIR)/test_bsg
	$(BIN_DIR)/test_battery
	$(BIN_DIR)/test_csvutils

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
	cd $(SRCS_DIR) && \
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
	@rm -rf $(GCDA_FILES) $(SRCS_DIR)/*.gcda
	@rm -rf $(GCNO_FILES) $(SRCS_DIR)/*.gcno
	@rm -rf $(GCOV_FILES) $(SRCS_DIR)/*.gcov
	@rm -rf $(LCOV_REPORT_DIR) $(GCOVR_REPORT_DIR)

# Documentation ---------------------------------------------------------------
# Build Documentation using Doxygen
.PHONY: docs
docs: $(DOCS_HTML_PAGE)

# Build HTML Code documentation
$(DOCS_HTML_PAGE): $(SRCS_DIR)/Doxyfile $(SRCS) $(HEADERS)
	cd $(SRCS_DIR) && \
	doxygen $<

# Remove generated files from documentation
.PHONY: clear-docs
clear-docs:
	@rm -rfv $(DOCS_HTML_DIR)

# Auxiliar Roles --------------------------------------------------------------

# Remove generated files
.PHONY: clear
clear:
	@rm -vf $(SRCS_DIR)/*.o
	@rm -vf $(LIB)
	@rm -vf ${BIN} ${TEST_BIN}
