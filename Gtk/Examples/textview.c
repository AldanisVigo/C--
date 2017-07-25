/*
 * 	Author: Aldanis Vigo
 *  Description: This is an example showing the use of a Text View widget within GTK-3.0+
 */
#include <gtk/gtk.h>

//Declare widgets
GtkWidget *text_view_one;
GtkTextBuffer *text_view_one_buffer;
GtkWidget *window_one;

void initialize_widgets(){
		//Create the window
		window_one = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		
		//Set the title of the window
		gtk_window_set_title(GTK_WINDOW(window_one), "Text View Example");
		//Set the window size
		gtk_window_set_default_size(GTK_WINDOW(window_one),200,200);
		//Attach destroy signal to gtk_main_quit callback function
		g_signal_connect(GTK_CONTAINER(window_one), "destroy", G_CALLBACK(gtk_main_quit), NULL);
		
		//Create a text view
		text_view_one = gtk_text_view_new();
		//Get the buffer for the text view
		text_view_one_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view_one));
		//Set the text in the text view's buffer
		gtk_text_buffer_set_text(text_view_one_buffer,"Hello this is some text inside a text view.", -1);
	
		//Add the text view inside the window_one container
		gtk_container_add(GTK_CONTAINER(window_one),text_view_one);
		
		//Show all the widgets
		gtk_widget_show_all(window_one);
}
int main(int argc, char **argv){
	//Initialize GTK
	gtk_init(&argc, &argv);
	//Create the widgets
	initialize_widgets();
	//Execute gtk main entry function 
	gtk_main();
	return 0;
}
