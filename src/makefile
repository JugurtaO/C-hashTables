CC=gcc
CFLAGS=-g -Wall -c
LDFLAGS=-g -Wall -o

exe=main

all:$(exe)

hash_table.o: hash_table.c  hash_table.h
main.o:main.c hash_table.h

%.o:%.c
	$(CC) $(CFLAGS) $<


main: main.o hash_table.o  

%:%.o
	$(CC) $(LDFLAGS) $@ $^
clean:
	rm -f  *.o $(exe)


