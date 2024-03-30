# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -Wextra -pedantic

# Source directory
SRC_DIR = src/

# Test directory
TEST_DIR = test/

# Include directory
INC_DIR = include/

# Source files
SOURCES = $(wildcard $(SRC_DIR)*.cpp)

# Test files
TEST_SOURCES = $(wildcard $(TEST_DIR)*.cpp)

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)%.cpp=%.o)

# Test Object files, excluding main.o
TEST_OBJECTS = $(filter-out main.o, $(OBJECTS))

# Target executable program name
TARGET = audio_track_library.exe

# Test Target
TEST_TARGET = test.exe

# Build target
.PHONY: all
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	@echo "Creating target executable: $@"
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(OBJECTS) -o $@

# Compile object files from source files
%.o: $(SRC_DIR)%.cpp
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Test target
.PHONY: test
test: $(TEST_TARGET)
	@echo "Running test executable"
	./$(TEST_TARGET)

# Create the test executable
$(TEST_TARGET): $(TEST_OBJECTS) $(TEST_SOURCES)
	@echo "Creating test executable: $@"
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -I$(TEST_DIR) $(TEST_OBJECTS) $(TEST_SOURCES) -o $@

# Clean up
.PHONY: clean
clean:
	@echo "Cleaning up project files"
	rm -f $(OBJECTS) $(TARGET) $(TEST_TARGET)

# Run the executable
.PHONY: run
run:
	@echo "Running $(TARGET) with the specified filename"
	./$(TARGET) $(FILE)