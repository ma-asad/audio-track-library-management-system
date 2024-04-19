# Purpose: Makefile for the audio track library project.

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -Wextra -pedantic

# Source directory
SRC_DIR = ./src/

# Test directory
TEST_DIR = ./test/

# Include directory
INC_DIR = ./include/

# Object directory
BUILD_DIR = ./build/

# Source files
SOURCES = $(wildcard $(SRC_DIR)*.cpp)

# Test files
TEST_SOURCES = $(wildcard $(TEST_DIR)*.cpp)

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)%.cpp=$(BUILD_DIR)%.o)

# Test Object files, excluding main.o
TEST_OBJECTS = $(filter-out $(BUILD_DIR)main.o, $(OBJECTS))

# Target executable program name
TARGET = audio_track_library.exe

# Test Targets
TEST_TARGETS = $(TEST_SOURCES:$(TEST_DIR)%.cpp=$(BUILD_DIR)%_test.exe)

# Test target
test: $(TEST_TARGET)

# Build target
.PHONY: all
all: $(BUILD_DIR) $(TARGET) 

$(BUILD_DIR):
	@echo "Creating build directory: $@"
	mkdir -p $@

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	@echo "Creating target executable: $@"
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(OBJECTS) -o $@

# Compile object files from source files
$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp | $(BUILD_DIR)
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Link test object files and test sources to create the test executables
$(BUILD_DIR)%_test.exe: $(TEST_DIR)%.cpp $(TEST_OBJECTS)
	@echo "Creating test executable: $@"
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -I$(TEST_DIR) $(TEST_OBJECTS) $< -o $@

# Clean up
.PHONY: clean
clean:
	@echo "Cleaning up project files"
	rm -rf $(OBJECTS) $(TARGET) $(TEST_TARGET) $(BUILD_DIR)

# Run the executable
.PHONY: run
run: $(TARGET)
	@echo "Running $(TARGET)"
	./$(TARGET)

# Run the test executables
.PHONY: test
test: $(TEST_TARGETS)
	@echo "Running test executables"
	$(foreach test, $(TEST_TARGETS), ./$(test);)

# Run a specific test executable, make run_test test=filename
.PHONY: run_test
run_test: $(BUILD_DIR)$(test)_test.exe
	@echo "Building and running test executable: $<"
	$<