# Makefile for creating executable file

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -Wextra -pedantic

# Target executable program name
TARGET = audio-library

# Object dependencies files
OBJS = main.o validation.o

# Header dependencies files
HEADERS = main.h validation.h

# Build target
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Creating target for the program"
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile object file which depends on cpp file and headers
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

# Clean up
.PHONY: clean
clean:
	@echo "Clean up Project"
	rm -f $(OBJS) $(TARGET)