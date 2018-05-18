GTEST_INCLUDE_DIR = ~/googletest/googletest/include/
GTEST_LIB_DIR = ~/googletest/libgtest.a

INCLUDE_DIR = include
LIBS = -pthread $(GTEST_LIB_DIR)

CXX = g++
CXXFLAGS = -std=c++11

all: program

program : main.o data_stream.o
	$(CXX) -o program main.o data_stream.o $(LIBS)

main.o :
	$(CXX) -c main.cpp -isystem $(GTEST_INCLUDE_DIR) -I$(INCLUDE_DIR)

data_stream.o :
	$(CXX) -c src/data_stream.cpp -I$(INCLUDE_DIR)

clean:
	rm -f main.o data_stream.o program
