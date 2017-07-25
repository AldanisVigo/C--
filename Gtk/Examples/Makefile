#
# Author: Aldanis Vigo
# Description:
# Makefile for GTK Examples
#
CC = gcc
CFLAGS += -g -Wall -Wextra $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS += $(shell pkg-config --libs gtk+-3.0)

all: menu_example textview_example 

menu_example: menu.c
	$(CC) $(CFLAGS) menu.c -o menu.exe $(LDFLAGS)

clean_menu_example: menu.exe
	rm menu.exe menu.o
	
textview_example: textview.c
	$(CC) $(CFLAGS) textview.c -o textview.exe $(LDFLAGS)

clean_textview_example:
	rm textview.exe textview.o
	
run_menu_example: menu.exe
	./menu.exe
	
run_textview_example: textview.exe
	./textview.exe

clean_all:
	rm menu.exe textview.exe menu.o textview.o
run_all: menu.exe textview.exe
	./menu.exe;./textview.exe
	
	
