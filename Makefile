# Makefile for LeetCode C++ solutions
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
BUILDDIR := build
UTILS := scripts/utils.sh

.PHONY: help build test clean

# Default target
help:
	@echo "Usage:"
	@echo "  make build <filename>  - Compile"
	@echo "  make test <filename>   - Compile and run"
	@echo "  make clean             - Remove build directory"
	@echo ""
	@echo "Example: make test array_list"

# Always available
clean:
	@rm -rf $(BUILDDIR)

# Check if we have a filename
ifneq ($(words $(MAKECMDGOALS)),2)
  # Only run help/clean without filename
  ifneq ($(filter clean help,$(MAKECMDGOALS)),)
    # Targets already defined above
  else ifneq ($(filter build test,$(MAKECMDGOALS)),)
    # Missing filename for build/test
    $(error Please specify a filename! Example: make test array_list)
  endif
else
  # Get filename
  FILE := $(lastword $(MAKECMDGOALS))
  SRC := $(shell $(UTILS) find_source $(FILE))
  
  # Check source exists
  ifeq ($(SRC),)
    $(error $(FILE).cpp not found in easy/medium/hard/)
  endif
  
  EXEC := $(BUILDDIR)/$(FILE)
  
  build:
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)
  
  test: build
	@./$(EXEC)
endif

# Ignore filename as a target
%:
	@:
