#include <gtk/gtk.h>
#include <iostream>
using namespace std;

static void button_clicked(GtkWidget* widget, gpointer data){
	cout << "You said hello!" << endl;
}

int main(int argc, char** argv){
	gtk_init(&argc,&argv);
	GtkWidget *window, *button;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button = gtk_button_new_with_label("Click Me");
	//Window Close Handler
	g_signal_connect(window,"delete_event", G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),NULL);	
	gtk_container_add(GTK_CONTAINER(window),button);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
