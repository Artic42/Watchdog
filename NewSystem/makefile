#Constant definitions
CC = gcc
CFLAGSR = -Wall
CFLAGSD = -g $(CFLAGSR)
OFLAGSR = -c $(CFALGSR)
OFLAGSD = -c $(CFLAGSD)
IPATH = -ISource/Header -I/home/artic/.bin/clib

#Path to different forlders
Binaries = bin
Sources = Source
Headers = Source/Header

#Default make order, it should build the entire application on realease

#Entire application compilation for debug
all: watchdog.app readInput.app

#Subordinate objects both in realease and debug
watchdog.app: $(Sources)/watchdog.c $(Headers)/watchdog.h
	$(CC) $(CFLAGSR) $(IPATH) $(Sources)/watchdog.c -o watchdog.app

readInput.app: $(Sources)/readInput.c
	$(CC) $(CFLAGSR) $(IPATH) $(Sources)/readInput.c -o readInput.app -lpigpio -lrt

#Abreviated commands
clean:
	rm -f Binaries/*.o
	rm *.app

install:
	cp watchdog.app ~/
	cp readInput.app ~/
