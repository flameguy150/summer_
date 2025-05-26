# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude -Itests

# Source files in src/
SRCS = $(wildcard src/*.cpp)

# Main source file (exclude from tests)
MAIN_SRC = src/main.cpp

# All other source files (used in both main and test)
COMMON_SRCS = $(filter-out $(MAIN_SRC), $(SRCS))

# Executable names
TARGET = main
TEST_TARGET = test

# Test files
TEST_SRCS = tests/test.cpp

# Default rule: build the main program
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Build test runner (exclude main.cpp)
test: $(TEST_SRCS) $(COMMON_SRCS)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) $(COMMON_SRCS) -o $(TEST_TARGET)

# Clean rule
clean:
	rm -f $(TARGET) $(TEST_TARGET)
