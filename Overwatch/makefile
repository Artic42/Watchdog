#Constant definitions

CC = gcc
CFLAGS = -c -g -Wall
IPATH = -ISource/Header

#default make file, makes the full application

bin/Overwatch.app: Source/Overwatch.c bin/FIFO.o
	$(CC) -g -Wall $(IPATH) Source/Overwatch.c bin/FIFO.o -o bin/Overwatch.app
	@echo "Overwatch Builded"

#Subordinate objects of the application

bin/FIFO.o: Source/FIFO.c Source/Header/FIFO.h
	$(CC) $(CFLAGS) $(IPATH) Source/FIFO.c -o bin/FIFO.o
	@echo "FIFO Builded"

#Abreviated command

Overwatch: bin/Overwatch.app
FIFO: bin/FIFO.o

#Run the program

Run: bin/Overwatch.app
	@bin/Overwatch.app

Debug: bin/Overwatch.app
	gdb bin/Overwatch.app

clean: 
	rm -f bin/*
