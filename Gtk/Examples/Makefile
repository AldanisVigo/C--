CC = gcc
PKGCONFIGCFLAGS = `pkg-config --cflags gtk+-3.0`
PKGCONFIGLIBS = `pkg-config --libs gtk+-3.0`
TARGET = menu textview

all: $(TARGET).c
	gcc $(PKGCONFIGCFLAGS) $(TARGET).c -o $(TARGET).exe $(PKGCONFIGLIBS)

clean: $(TARGET).exe
	rm $(TARGET).exe

run: $(TARGET).exe
	./$(TARGET).exe
	
	
