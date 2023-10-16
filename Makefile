
# Makefile for C++ Project

# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -std=c++11 -g

# Source Files
SOURCES = Author.cpp Book.cpp Entity.cpp EntityWithBooks.cpp Genre.cpp Library.cpp Patron.cpp main.cpp 

# Object Files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable Name
EXECUTABLE = libraryManagementSystem

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencies
Book.o: Book.h
Library.o: Library.h

clean:
# remove csv files aswells
	rm -f $(OBJECTS) $(EXECUTABLE) *.csv

