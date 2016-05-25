I compiled this in Ubuntu. Depends on GTK+. The latest version at the time is GTK3. I installed it using the command:

	sudo apt-get install libgtk-3-dev
	
To compile gtk3 programs here's the macro:
	
	g++ file.cpp -o file.out `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`
