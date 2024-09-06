CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = main

SOURCES = main.cpp h26x_parser.cpp

OBJECTS = $(SOURCES:.cpp=.o)

HEADERS = -I.

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "--- BUILD SUCCESS ---"

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS) image264.h264 image265.h265 image264.jpg image265.jpg

run: all
	@./$(TARGET)

image-h264:
	ffmpeg -i image264.h264 -q:v 2 image264.jpg

image-h265:
	ffmpeg -i image265.h265 -q:v 2 image265.jpg

.PHONY: all clean run image-h264 image-h265
