all: program

program : main.o data_stream.o
	g++ -o program main.o data_stream.o ~/googletest/libgtest.a -pthread

main.o :
	g++ -c main.cpp -isystem ~/googletest/googletest/include/ -Iinclude

data_stream.o :
	g++ -c src/data_stream.cpp -Iinclude

clean:
	rm main.o data_stream.o program
