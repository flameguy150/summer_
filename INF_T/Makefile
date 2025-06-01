# Compiler
CXX = g++

# Compiler flags
# CXXFLAGS = -std=c++17 -Wall -g -Iinclude

# # Linker flags
# LDFLAGS = -L/usr/local/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# If using Apple Silicon (M1/M2/M3), replace the above two lines with:
CXXFLAGS = -std=c++17 -Wall -g -Iinclude -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Output binary name
TARGET = main

# Source files
SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files to create the binary
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Clean rule
clean:
	rm -f $(TARGET)
