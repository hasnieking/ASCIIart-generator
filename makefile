CC = g++
CompileParms = -c -g -Wall -std=c++14
OBJS = hexdump.o general.o bmp.o image.o picture.o

all: main.o $(OBJS)
	g++ -Wall -o ascii main.o $(OBJS)
check: test.o $(OBJS)
	g++ -Wall -o check test.o $(OBJS)
	./check
hexdump.o: hexdump.cc hexdump.h
	$(CC) $(CompileParms) hexdump.cc
general.o: general.cc general.h
	$(CC) $(CompileParms) general.cc
bmp.o: bmp.cc bmp.h
	$(CC) $(CompileParms) bmp.cc
image.o: image.cc image.h
	$(CC) $(CompileParms) image.cc
picture.o: picture.cc picture.h
	$(CC) $(CompileParms) picture.cc
main.o: main.cc
	$(CC) $(CompileParms) main.cc
test.o: test.cc
	$(CC) $(CompileParms) test.cc
clean:
	rm *.o ascii check -f