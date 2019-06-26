CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all test debug release clean run

all: exec

release : CFLAGS += -O3
release : gol

debug : CFLAGS += -g -O0
debug : gol

exec: main.o gol.o
	$(CC) main.o gol.o -o exec
main.o: main.c gol.h
	$(CC) -c main.c
gol.o: gol.h gol.c
	$(CC) -c gol.c
run: exec
	./exec
clean: clean
	rm main.o gol.o exec 
