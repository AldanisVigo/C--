#include <gtk/gtk.h>
//Function Prototypes

//Widget declarations
GtkBuilder *gtkBuilder;
GtkWidget *window;
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
//Open Button Signal Callback
void btn_open_clicked(GtkWidget *widget, gpointer *pointer){
	sendMessage("Open Clicked", window);
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
	sendMessage("About Clicked", window);
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
