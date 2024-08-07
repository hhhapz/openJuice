CXX = g++-12
CXXFLAGS = -std=c++20 -Wall -g -MMD
LDFLAGS = 
SELF_DIR := $(shell pwd)
DIRECTORIES = src src/board src/cards src/player src/player/characters src/utility
INC = $(addprefix -I$(SELF_DIR)/,$(DIRECTORIES)) -I$(SELF_DIR)/.
BUILD_DIR = bin
EXEC = openJuice

# Find all source files in the source directory
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Generate a list of corresponding object files in the build directory
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Dependency files
DEPENDS = $(OBJECTS:.o=.d)

# Default target
all: $(EXEC)

# Linking object files to create the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compiling each source file into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPENDS)

.PHONY: clean 
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

# Create the build directory if it does not exist
$(shell mkdir -p $(BUILD_DIR))
