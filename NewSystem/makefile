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
watchdog.app: $(Sources)/watchdog.c $(Headers)/watchdog.h
	$(CC) $(CFLAGSR) $(IPATH) $(Sources)/watchdog.c -o watchdog.app

#Entire application compilation for debug


#Subordinate objects both in realease and debug


#Abreviated commands
clean:
	rm -f Binaries/*.o
	rm watchdog.app

run: watchdog.app
	./watchdog.app
