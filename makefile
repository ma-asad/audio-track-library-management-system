# Makefile for Audio Track Library Management System

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -Wextra -pedantic

# Source files
SOURCES = main.cpp AudioTrack.cpp AudioLibrary.cpp

# Header files
HEADERS = AudioTrack.h AudioLibrary.h

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Target executable program name
TARGET = audio_track_library.exe

# Build target
.PHONY: all
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	@echo "Creating target executable: $@"
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Compile object files from source files and headers
%.o: %.cpp $(HEADERS)
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $<

# Clean up
.PHONY: clean
clean:
	@echo "Cleaning up project files"
	rm -f $(OBJECTS) $(TARGET)

# Run the executable
.PHONY: run
run: $(TARGET)
	@echo "Running $(TARGET)"
	./$(TARGET)