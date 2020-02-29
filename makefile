#Constant definitions

CC = gcc
CFLAGSR = -Wall
CFLAGSD = -g $(CFLAGSR)
OFLAGSR = -c $(CFLAGSR)
OFLAGSD = -c $(CFLAGSD)
IPATH = -ISource/Header

#Path to diferent modules

OWBinaries = Overwatch/bin
OWSources = Overwatch/Source
OWHeaders = Overwatch/Source/Header

#default make file, makes the full application


#Subordinate objects of the application Overwatch for Debug

$(OWBinaries)/OverwatchDebug.app: $(OWSources)/Overwatch.c $(OWBinaries)/FIFODebug.o $(OWBinaries)/MessageCreatorDebug.o
	@$(CC) $(CFLAGSD) -I$(OWHeaders) $(OWSources)/Overwatch.c $(OWBinaries)/FIFO.o -o $(OWBinaries)/OverwatchDebug.app
	@echo "Overwatch Builded"

$(OWBinaries)/FIFODebug.o: $(OWSources)/FIFO.c $(OWHeaders)/FIFO.h
	@$(CC) $(OFLAGSD)  -I$(OWHeaders) $(OWSources)/FIFO.c -o $(OWBinaries)/FIFODebug.o
	@echo "FIFO Builded"

$(OWBineries)/MessageCreatorDebug.o: $(OWSource)/MessageCreator.c $(OWHeaders)/MessageCreator.h
	@$(CC) $(OFLAGSD)  -I$(OWHeaders) $(OWSources)/MessageCreator.c -o $(OWBinaries)/MessageCreatorDebug.o
	@echo "Message Creator Builded"


#Subordinate objects of the application Overwatch for realease 

$(OWBinaries)/Overwatch.app: $(OWSources)/Overwatch.c $(OWBinaries)/FIFO.o $(OWBinaries)/MessageCreator.o
	@$(CC) $(CFLAGSR) -I$(OWHeaders) $(OWSources)/Overwatch.c $(OWBinaries)/FIFO.o -o $(OWBinaries)/Overwatch.app
	@echo "Overwatch Builded"

$(OWBinaries)/FIFO.o: $(OWSources)/FIFO.c $(OWHeaders)/FIFO.h
	@$(CC) $(OFLAGSR)  -I$(OWHeaders) $(OWSources)/FIFO.c -o $(OWBinaries)/FIFO.o
	@echo "FIFO Builded"

$(OWBineries)/MessageCreator.o: $(OWSource)/MessageCreator.c $(OWHeaders)/MessageCreator.h
	@$(CC) $(OFLAGSR)  -I$(OWHeaders) $(OWSources)/MessageCreator.c -o $(OWBinaries)/MessageCreator.o
	@echo "Message Creator Builded"

#Abreviated command

Overwatch: $(OWBinaries)/Overwatch.app
FIFO: $(OWBinaries)/FIFO.o

#Run the program

Run: $(OWBinaries)/Overwatch.app
	@$(OWBinaries)/Overwatch.app

Debug: $(OWBinaries)/OverwatchDebug.app
	@gdb $(OWBinaries)/OverwatchDebug.app

clean: 
	@rm -f $(OWBinaries)/*
