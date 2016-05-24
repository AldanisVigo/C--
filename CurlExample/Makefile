#Author:  Aldanis Vigo 
#Datetime: Tuesday, May 24th, 2016 @ 1:07PM
#Licence: Use at your own will
CC = g++
PROG = main
OBJS = curly.o
CFLAGS = -Wall -g
CURL = -lcurl
all: curly.o $(PROG) 

$(PROG):$(PROG).cpp $(OBJS)
	$(CC) $(CURL) $(CFLAGS) $(OBJS) $(PROG).cpp -o $(PROG).out

curly.o: curly.h curly.cpp
	$(CC)  -c $(CURL)  curly.cpp

run:
	./$(PROG).out

clean:
	rm $(OBJS)
	rm $(PROG).out
	rm -rf $(PROG).out.dSYM  
