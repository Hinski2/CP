# Makefile
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra 

# Nazwa pliku wykonywalnego
TARGET = solution1

# Pliki źródłowe
SOURCES = solution1.cpp
HEADERS = my_standard_utils.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)