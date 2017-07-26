# Makefile for Glade + Gtk3 Text Editor Example
CC = gcc
CFLAGS = -Wall -g -rdynamic `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`
TARGET = main

all: compile_main run_main

compile_main: $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET).exe $(LDFLAGS)

run_main: $(TARGET).exe
	./$(TARGET).exe

clean: $(TARGET).exe
	rm $(TRAGET).exe

#finito
