CC = g++
CFLAGS = -std=c++0x -Wall -g
PROG = main

all:$(PROG) run

$(PROG):$(PROG).cpp
	$(CC) $(CFLAGS) $(PROG).cpp -o $(PROG).out

clean:
	rm $(PROG).out

run:
	./$(PROG).out
