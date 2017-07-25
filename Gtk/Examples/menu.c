/*
	Author: Aldanis Vigo
	Title: Gtk-3.0 Menu Example
	Description - This is an example of GTK-3.0 menu widget and it's 
	features.
*/
#include <gtk/gtk.h>

//Function Prototypes
void initialize_gui();

//Widget declarations
GtkWidget *window_one;
GtkWidget *menu_one;
GtkWidget *vertical_box_one;
GtkWidget *menu_one_file_menu_option;
GtkWidget *menu_one_file_menu;
GtkWidget *menu_one_file_menu_quit_option;
GtkWidget *button;

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
			break;
	}
}
void button_clicked(GtkWidget* widget, gpointer* pointer){
	sendMessage("Hello, you clicked me!",window_one);
}
void initialize_gui(){
	//Initialize the window_one widget
	window_one = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//Set the window title
	gtk_window_set_title(GTK_WINDOW(window_one),"GTK-3.0 Menu Exmaple");
	//Set the window size
	gtk_window_set_default_size(GTK_WINDOW(window_one),200,200);
	//Attach the destroy signal to the gtk_main_quit callback
	g_signal_connect(G_OBJECT(window_one), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	//Initialize vertical_box_one widget
	vertical_box_one = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	//Pack the vertical_box_one widget into the window_one widget
	gtk_container_add(GTK_CONTAINER(window_one),vertical_box_one);
	//Initialize the menu_one widget
	menu_one = gtk_menu_bar_new();
	//Pack the menu_one widget into the vertical_box_one widget
	gtk_box_pack_start(GTK_BOX(vertical_box_one),menu_one,FALSE,FALSE,1);
	//Create FILE menu item
	menu_one_file_menu_option = gtk_menu_item_new_with_label("FILE");
	//Create FILE menu
	menu_one_file_menu = gtk_menu_new();
	//Set the gtk_one_file_menu as the menu_one_file_menu_option's submenu
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_one_file_menu_option), menu_one_file_menu);
	//Create QUIT submenu item
	menu_one_file_menu_quit_option = gtk_menu_item_new_with_label("QUIT");
	//Attach a signal from the QUIT submenu's activate event to the gtk_main_quit callback
	g_signal_connect(G_OBJECT (menu_one_file_menu_quit_option), "activate",G_CALLBACK (gtk_main_quit),NULL);
	//Attach the menu_one_file_menu_quit_option to the menu_one_file_menu menu
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_one_file_menu), menu_one_file_menu_quit_option);
	//Attach the FILE menu item to the menu bar
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_one), menu_one_file_menu_option);
	
	//Create button
	button = gtk_button_new_with_label("Click Me");
	//Create button click handler
	g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), NULL);
	//Pack the button into the vertical box
	gtk_box_pack_start(GTK_BOX(vertical_box_one),button,TRUE,TRUE,1);
	
	//Show everything
	gtk_widget_show_all(window_one);
	
}
int main(int argc, char** argv){
	//Initialize GTK-3.0
	gtk_init(&argc,&argv);
	//Create the gui components
	initialize_gui();
	//Run the main entry point for gtk application
	gtk_main();
	return 0;
}
