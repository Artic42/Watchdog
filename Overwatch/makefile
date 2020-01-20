#Constant definitions

CC = gcc
CFLAGS = -c -Wall
IPATH = -ISource/Hearder

#default make file, makes the full application

bin/Overwatch.app: Source/Overwatch.c bin/FIFO.o
	$(CC) $(CFLAG) $(IPATH) Source/Overwatch.c bin/FIFO.o -o bin/Overwatch.app
	@echo "Overwatch Builded"

#Subordinate objects of the application

bin/FIFO.o: Source/FIFO.c Source/Header/FIFO.h
	$(CC) $(CFLAG) $(IPATH) Source/FIFO.c -o bin/FIFO.o
	@echo "FIFO Builded"


