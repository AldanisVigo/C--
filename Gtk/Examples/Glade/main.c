#include <gtk/gtk.h>
#include <stdlib.h>

//Function Prototypes

//Widget declarations
GtkBuilder *gtkBuilder;
GtkWidget *window;
GtkWidget *about_dialog;
GtkWidget *file_chooser_dialog;
GtkWidget *textview;
GtkTextBuffer *textview_buffer;

void sendMessage(gchar *message,GtkWidget* window){
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window),GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,"%s",message);
	gint result = gtk_dialog_run (GTK_DIALOG(dialog));
	switch(result){
		case GTK_RESPONSE_OK:
			gtk_grab_remove(GTK_WIDGET(dialog));
			gtk_widget_destroy(GTK_WIDGET(dialog));
			break;
		default:
			gtk_grab_remove(GTK_WIDGET(dialog));
			gtk_widget_destroy(GTK_WIDGET(dialog));
			break;
	}
}
//Close Open File Dialog
void close_open_file_dialog(GtkWidget *widget, gpointer *pointer){
	gtk_grab_remove(GTK_WIDGET(file_chooser_dialog));
	gtk_widget_destroy(GTK_WIDGET(file_chooser_dialog));
}
//Open Sesame on Open File Dialog Clicked
void open_file_clicked(GtkWidget *widget, gpointer *pointer){
	gchar *filename;
	GtkFileChooser *fileChooser = GTK_FILE_CHOOSER(file_chooser_dialog);
	filename = gtk_file_chooser_get_filename(fileChooser);
	gchar *file_buffer = 0;
	long length;
	FILE * f = fopen (filename, "rb");
	if (f){
		fseek (f, 0, SEEK_END);
		length = ftell (f);
		fseek (f, 0, SEEK_SET);
		file_buffer = malloc (length);
		if (file_buffer){
			fread ((char*)file_buffer, 1, length, f);
		}
		fclose (f);
	}
	if (file_buffer){
		gtk_text_buffer_set_text(textview_buffer,file_buffer,-1);
		gtk_grab_remove(GTK_WIDGET(file_chooser_dialog));
		gtk_widget_destroy(GTK_WIDGET(file_chooser_dialog));
	}
}
//Open Button Signal Callback
void btn_open_clicked(GtkWidget *widget, gpointer *pointer){
	//sendMessage("Open Clicked", window);
	gtkBuilder = gtk_builder_new_from_file("gladeFormOne.glade");
	file_chooser_dialog = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"filechooserdialog1"));
	gtk_builder_connect_signals(gtkBuilder, NULL);
	
	//Add callbacks for the dialog action buttons
	//Get Me Outta Heaaa
	gtk_builder_add_callback_symbol(gtkBuilder, "close_open_file_dialog", G_CALLBACK(close_open_file_dialog));	
	//Open Sesame
	gtk_builder_add_callback_symbol(gtkBuilder, "open_file_clicked", G_CALLBACK(open_file_clicked));
	
	gint result = gtk_dialog_run (GTK_DIALOG(file_chooser_dialog));
	switch(result){
		case GTK_RESPONSE_DELETE_EVENT:
			gtk_grab_remove(GTK_WIDGET(file_chooser_dialog));
			gtk_widget_destroy(GTK_WIDGET(file_chooser_dialog));
			break;
		default:
			break;
	}
	g_object_unref(G_OBJECT(gtkBuilder));
}
//Save Button Signal Callback
void btn_save_clicked(GtkWidget *widget, gpointer *pointer){
	sendMessage("Save Clicked", window);
	
}
//Edit/Cut Signal Callback
void edit_cut(GtkWidget *widget, gpointer *pointer){
	sendMessage("Cut Clicked", window);
}
//Edit/Copy Signal Callback
void edit_copy(GtkWidget *widget, gpointer *pointer){
	sendMessage("Copy Clicked", window);
}
//Edit/Paste Signal Callback
void edit_paste(GtkWidget *widget, gpointer *pointer){
	sendMessage("Paste Clicked", window);
}
//Edit/Delete Signal Callback
void edit_delete(GtkWidget *widget, gpointer *pointer){
	sendMessage("Delete Clicked", window);
}
//Help/About dialog Callback
void help_about(GtkWidget *widget, gpointer *pointer){
	gtkBuilder = gtk_builder_new_from_file("gladeFormOne.glade");
	about_dialog = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"aboutdialog1"));
	gtk_builder_connect_signals(gtkBuilder, NULL);
	
	gint result = gtk_dialog_run (GTK_DIALOG(about_dialog));
	switch(result){
		case GTK_RESPONSE_DELETE_EVENT:
			gtk_grab_remove(GTK_WIDGET(about_dialog));
			gtk_widget_destroy(GTK_WIDGET(about_dialog));
			break;
		default:
			break;
	}
	g_object_unref(G_OBJECT(gtkBuilder));
}
void init_gui(){
	//Widget definitions
	gtkBuilder = gtk_builder_new_from_file("gladeFormOne.glade");
	window = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"window1"));
	gtk_builder_connect_signals( gtkBuilder, NULL );
	
	//Attach callback function for open button
	gtk_builder_add_callback_symbol(gtkBuilder, "btn_open_clicked", G_CALLBACK(btn_open_clicked));
	//Attach callback function for save button 
	gtk_builder_add_callback_symbol(gtkBuilder, "btn_save_clicked", G_CALLBACK(btn_save_clicked));
	
	//Attach the edit menu signals
	//Edit/Cut
	gtk_builder_add_callback_symbol(gtkBuilder, "edit_cut", G_CALLBACK(edit_cut));	
	//Edit/Copy
	gtk_builder_add_callback_symbol(gtkBuilder, "edit_copy", G_CALLBACK(edit_copy));
	//Edit/Paste
	gtk_builder_add_callback_symbol(gtkBuilder, "edit_paste", G_CALLBACK(edit_paste));
	//Edit/Delete
	gtk_builder_add_callback_symbol(gtkBuilder, "edit_delete", G_CALLBACK(edit_delete));
	//Attach the help menu signals
	
	//Help/About
	gtk_builder_add_callback_symbol(gtkBuilder, "help_about", G_CALLBACK(help_about));
	
	//Text View and Buffer
	textview = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"editor_area"));
	textview_buffer = GTK_TEXT_BUFFER(gtk_builder_get_object(gtkBuilder,"textbuffer2"));

	//Unreference the GtkBuilder object
	g_object_unref(G_OBJECT(gtkBuilder));
	gtk_widget_show(window);
}

int main(int argc, char **argv){
	gtk_init(&argc,&argv);
	init_gui();
	gtk_main();  
	return 0;
}
