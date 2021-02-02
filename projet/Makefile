CC=gcc
CFLAGS=-Wall

all: main

dico.o: dico.c 
	$(CC) $(CFLAGS) -g -c dico.c

word.o: word.c
	$(CC) $(CFLAGS) -g -c word.c

maillon.o: maillon.c 
	$(CC) $(CFLAGS) -g -c maillon.c

main.o: main.c
	$(CC) $(CFLAGS) -g -c main.c

main: dico.o word.o maillon.o main.o
	$(CC) $^ -o $@

clean: 
	-rm *.o main

