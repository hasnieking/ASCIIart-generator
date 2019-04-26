CC = g++
CompileParms = -c -Wall -std=c++14
OBJS = hexdump.o

all: main.o $(OBJS)
	g++ -Wall -o ascii main.o $(OBJS)
hexdump.o: hexdump.cc hexdump.h
	$(CC) $(CompileParms) hexdump.cc
main.o: main.cc
	$(CC) $(CompileParms) main.cc