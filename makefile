CXXFLAGS = -g -Wall -Wextra -pedantic

# Source directory
SRC_DIR = src/

# Test directory
TEST_DIR = test/

# Include directory
INC_DIR = include/

# Object directory
BUILD_DIR = build/

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

# Test Target
TEST_TARGET = $(BUILD_DIR)test.exe

# Test target
test: $(TEST_TARGET)

# Build target
.PHONY: all
all: $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

$(BUILD_DIR):
	@echo "Creating build directory: $@"
	mkdir -p $@

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	@echo "Creating target executable: $@"
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(OBJECTS) -o $@

# Compile object files from source files
$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(TEST_TARGET): $(TEST_OBJECTS) $(TEST_SOURCES)
	@echo "Creating test executable: $@"
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(TEST_OBJECTS) $(TEST_SOURCES) -o $@

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

# Run the test executable
.PHONY: runtest
runtest: $(TEST_TARGET)
	@echo "Running test executable"
	./$(TEST_TARGET)