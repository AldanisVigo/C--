MAC OSX USERS:

	In order for this to work you must have libcurl installed. 
	1. Install libcurl

		a.Go to https://curl.haxx.se/download.html

		b.Download latest curl package curl-x.xx.x.tar.gz

		c.Navigate to download directory with terminal
			cd /Path/To/Download/Directory

		d.Extract the contents using command:
			tar -zxvf curl-x.xx.x.tar.gz
		
		e.Navigate to the extracted directory
			cd curl-x-xx-x

		f.Configure installation  using command
			./configure

		g.Make the libcurl library using command
			make

		h.Test the make using the command
			make test

		i.If test passes then install the library using the command
			sudo make install

		j. It's gonna ask you for your root username and password then hit enter and wallah.

		k. Now check if it installed by making sure these files exist
			/usr/local/lib/libcurl.a
			/usr/local/lib/libcurl.dylib
			/usr/local/include/curl

		l. If they do you  are set my friend.		


	2. Now make the program by running
		make
	
	3. Now you can run it using 
		make run



	If you have any questions please leave me a message on my facebook page
	https://www.facebook.com/VigoEngineering

