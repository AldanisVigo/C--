PROG = main
CC = g++
GTK = `pkg-config --libs gtk+-3.0' 'pkg-config --cflags gtk+-3.0`

all: main

$(PROG):$(PROG).cpp
	$(CC) $(PROG).cpp -o $(PROG).out $(GTK)

run:
	./$(PROG).out

clean:
	rm $(PROG).out
