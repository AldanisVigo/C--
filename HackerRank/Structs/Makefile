CC = g++
CFLAGS = -Wall -g 
PROG = main

all:$(PROG)

$(PROG):$(PROG).cpp
	$(CC) $(CFLAGS) $(PROG).cpp -o $(PROG).out

run:
	./$(PROG).out

clean:
	rm $(PROG).out

