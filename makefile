# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -Wextra -pedantic

# Source directory
SRC_DIR = src/

# Include directory
INC_DIR = include/

# Source files
SOURCES = $(wildcard $(SRC_DIR)*.cpp)

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)%.cpp=%.o)

# Target executable program name
TARGET = audio_track_library.exe

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

# Clean up
.PHONY: clean
clean:
	@echo "Cleaning up project files"
	rm -f $(OBJECTS) $(TARGET)

# Run the executable
.PHONY: run
run:
	@echo "Running $(TARGET) with the specified filename"
	./$(TARGET) $(FILE)