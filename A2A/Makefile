# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -g

# Output file name
TARGET = main

# Default rule
all: $(TARGET)

# How to build the target
$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

# Clean up build files
clean:
	rm -f $(TARGET)
