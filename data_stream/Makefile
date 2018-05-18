all: program

program : main.o data_stream.o
	g++ -o program main.o data_stream.o

main.o : main.cpp
	g++ -c main.cpp -Iinclude

data_stream.o : data_stream.cpp
	g++ -c src/data_stream.cpp -Iinclude

clean:
	rm main.o data_stream.o program
