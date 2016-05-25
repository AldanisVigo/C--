CC = g++
CFLAGS = -Wall 
LFLAGS = -L/usr/lib -lmysqlcppconn
INCLUDES = -I/usr/include/cppconn
PROG = main
OBJS = 

all: main

$(PROG):
	$(CC) $(CFLAGS) $(INCLUDES) -o $(PROG) $(PROG).cpp $(LFLAGS) 
