# Written by Aldanis Vigo 
PROG = main
CFLAGS = -Wall -g
CC = g++


all:$(PROG) run

$(PROG):main.cpp 
	$(CC) $(CFLAGS) $(PROG).cpp -o $(PROG).out

clean:
	rm $(PROG).out

run:
	./$(PROG).out
