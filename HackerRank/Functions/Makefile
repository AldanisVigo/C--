CC = g++
CFLAGS = -std=c++0x -Wall -g
PROG = main

all:$(PROG) run

$(PROG):main.cpp
	$(CC) $(CFLAGS) $(PROG).cpp -o $(PROG).out

clean:
	rm $(PROG).out

run:
	./$(PROG).out
