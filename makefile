CC = g++
CompileParms = -c -Wall -std=c++14
OBJS = hexdump.o general.o

all: main.o $(OBJS)
	g++ -Wall -o ascii main.o $(OBJS)
check: test.o $(OBJS)
	g++ -Wall -o check test.o $(OBJS)
	./check
hexdump.o: hexdump.cc hexdump.h
	$(CC) $(CompileParms) hexdump.cc
general.o: general.cc general.h
	$(CC) $(CompileParms) general.cc
main.o: main.cc
	$(CC) $(CompileParms) main.cc
test.o: test.cc
	$(CC) $(CompileParms) test.cc