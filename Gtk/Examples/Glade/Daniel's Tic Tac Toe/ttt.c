/*
 *	@author: Aldanis Vigo
 *	@date: July 29th 2017
 *	Description: Daniel's Dinosaur Tic Tac Toe game.
*/

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//Object Declarations
//Main GUI Builder Declaration
GtkBuilder *gtkBuilder;

//Spash Screen Object Declarations
GtkWidget *splash_screen;
GtkWidget *loading_bar;
gint bar_timeout_resource;

//Player Info Dialog Object Declarations
GtkWidget *player_info_dialog;
GtkWidget *player_one_name;
GtkWidget *player_two_name;

//Main Game Window Object Declarations
GtkWidget *main_window;
GtkWidget *top_left_button;
GtkWidget *top_middle_button;
GtkWidget *top_right_button;
GtkWidget *middle_left_button;
GtkWidget *middle_button;
GtkWidget *middle_right_button;
GtkWidget *bottom_left_button;
GtkWidget *bottom_middle_button;
GtkWidget *bottom_right_button;
GtkWidget *status_label;
int current_player;
#define PLAYER_ONE 0
#define PLAYER_TWO 1
char players[2][50];
int  game_board[3][3];

/*
 * Creates a message dialog and displays it with the specified message
*/
void sendMessage(const gchar *message,GtkWidget* window){
	//Create a dialog window
	GtkWidget *dialog;
	//Instantiate the dialog window
	dialog = gtk_message_dialog_new(GTK_WINDOW(window),GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,"%s",message);
	//Integer to store the result of running the dialog
	gint result = gtk_dialog_run (GTK_DIALOG(dialog));
	//Check the result
	switch(result){
		//If the user clicks the OK button
		case GTK_RESPONSE_OK:
			//Delete the message dialog
			gtk_grab_remove(GTK_WIDGET(dialog));
			gtk_widget_destroy(GTK_WIDGET(dialog));
			break;
		default:
			//Delete the message dialog
			gtk_grab_remove(GTK_WIDGET(dialog));
			gtk_widget_destroy(GTK_WIDGET(dialog));
			break;
	}
}
/*
 * Function returns the symbol corresponding to the current player
*/
char* symbol(){ 	
	char* symbol;
	if(current_player == PLAYER_ONE){
		symbol = "X";
		current_player =  PLAYER_TWO;
	}else{
		symbol = "O";
		current_player = PLAYER_ONE;
	}
	return symbol;
}
void youWin(){
		char winning_msg[100] = "Player ";
		strcat(winning_msg,(char*)players[1 - current_player]);
		strcat(winning_msg," wins!");
		//gtk_widget_hide(main_window);
		sendMessage(winning_msg, main_window);
}
void markWin(GtkWidget* btn1,GtkWidget* btn2, GtkWidget* btn3){
		GtkStyleContext *css_style_context;
		css_style_context = gtk_widget_get_style_context(btn1);
		gtk_style_context_add_class(css_style_context,"winning_piece");
		css_style_context = gtk_widget_get_style_context(btn2);
		gtk_style_context_add_class(css_style_context,"winning_piece");
		css_style_context = gtk_widget_get_style_context(btn3);
		gtk_style_context_add_class(css_style_context,"winning_piece");
		g_object_unref(css_style_context);
		youWin();
}
void checkWin(){
	//Check top horizontal
	if((game_board[0][0] == game_board[0][1]) && (game_board[0][1] == game_board[0][2]) && (game_board[0][0] < 2)){
		markWin(top_left_button,top_middle_button,top_right_button);
	}
	//Check middle horizonal
	if((game_board[1][0] == game_board[1][1]) && (game_board[1][1] == game_board[1][2]) && (game_board[1][0] < 2)){
		markWin(middle_left_button,middle_button,middle_right_button);
	}
	//Check bottom horizontal
	if((game_board[2][0] == game_board[2][1]) && (game_board[2][1] == game_board[2][2]) && (game_board[2][0] < 2)){
		markWin(bottom_left_button,bottom_middle_button,bottom_right_button);
	}
	//Check Vertical Left
	if((game_board[0][0] == game_board[1][0]) && (game_board[1][0] == game_board[2][0]) && (game_board[0][0] < 2)){
		markWin(top_left_button,middle_left_button,bottom_left_button);
	}
	//Check Vertical Middle
	if((game_board[0][1] == game_board[1][1]) && (game_board[1][1] == game_board[2][1]) && (game_board[0][1] < 2)){
		markWin(top_middle_button,middle_button,bottom_middle_button);
	}
	//Check Vertical Right
	if((game_board[0][2] == game_board[1][2]) && (game_board[1][2] == game_board[2][2]) && (game_board[0][2] < 2)){
		markWin(top_right_button,middle_right_button,bottom_right_button);
	}
	//Check Diagonal Right
	if((game_board[0][0] == game_board[1][1]) && (game_board[1][1] == game_board[2][2]) && (game_board[0][0] < 2)){
		markWin(top_left_button,middle_button,bottom_right_button);
	}
	//Check Diagonal Left
	if((game_board[0][2] == game_board[1][1]) && (game_board[1][1] == game_board[2][0]) && (game_board[0][2] < 2)){
		markWin(top_right_button,middle_button,bottom_left_button);
	}
}
void make_a_play(GtkWidget* widget){
	char msg[100] = "Player ";
	if(gtk_button_get_label(GTK_BUTTON(widget)) > 0){
		const char* onit = gtk_button_get_label(GTK_BUTTON(widget));
		int belongsto;
		if(strcmp(onit,"O")){
			belongsto = PLAYER_ONE;
		}else if(strcmp(onit,"X")){
			belongsto = PLAYER_TWO;
		}
		strcat(msg,players[belongsto]);
		strcat(msg," played here already.");
		sendMessage(msg,main_window);
	}
	else{
		//char markup[255] = "<span style='font-weight: bold;font-size: large; color:red;'>";
		//strcat(markup,symbol());
		//strcat(markup,"</span>");
		gtk_button_set_label(GTK_BUTTON(widget),symbol());
		checkWin();
	}
}
/*
 * Top Left Gameboard Button Clicked Callback Function
*/
void top_left_clicked(GtkWidget* widget, gpointer *pointer){	
	game_board[0][0] = current_player;
	make_a_play(widget);
}
/*
 * Top Center Gameboard Button Clicked Callback Function
*/
void top_center_clicked(GtkWidget* widget, gpointer *pointer){
	game_board[0][1] = current_player;
	make_a_play(widget);
}
/*
 * Top Right Gameboard Button Clicked Callback Function
*/
void top_right_clicked(GtkWidget* widget, gpointer *pointer){
	game_board[0][2] = current_player;
	make_a_play(widget);
}
/*
 * Center Left Gameboard Button Clicked Callback Function
*/
void center_left_clicked(GtkWidget* widget, gpointer *pointer){
	game_board[1][0] = current_player;
	make_a_play(widget);
}
/*
 * Center Gameboard Button Clicked Callback Function
*/
void center_clicked(GtkWidget* widget, gpointer *pointer){
	game_board[1][1] = current_player;
	make_a_play(widget);
}
/*
 * Center Right Gameboard Button Clicked Callback Function
*/
void center_right_clicked(GtkWidget* widget, gpointer *pointer){
	game_board[1][2] = current_player;
	make_a_play(widget);
}
/*
 * Bottom Left Gameboard Button Clicked Callback Function
*/
void bottom_left_clicked(GtkWidget* widget, gpointer *pointer){
	game_board[2][0] = current_player;
	make_a_play(widget);
}
/*
 * Bottom Center Gameboard Button Clicked Callback Function
*/
void bottom_center_clicked(GtkWidget* widget, gpointer *pointer){
	game_board[2][1] = current_player;
	make_a_play(widget);
}
/*
 * Bottom Right Gameboard Button Clicked Callback Function
*/
void bottom_right_clicked(GtkWidget* widget, gpointer *pointer){
	game_board[2][2] = current_player;
	make_a_play(widget);
}
/*
 * Initialization sub-function that initializes the main game window
*/
void init_game_window(const gchar* p_one,const char* p_two){
	//Reference the main game wrindow
	main_window = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"game_window"));
			
	//Reference the game status label
	status_label = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"game_status_label"));
	
	//Reference the gameboard buttons
	top_left_button = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"top_left"));
	top_middle_button = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"top_center"));
	top_right_button = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"top_right"));
	middle_left_button = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"center_left"));
	middle_button = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"center"));
	middle_right_button = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"center_right"));
	bottom_left_button = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"bottom_left"));
	bottom_middle_button = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"bottom_center"));
	bottom_right_button = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"bottom_right"));
	
	//Attach callback functions to all the signals from the buttons on the board
	gtk_builder_add_callback_symbol(gtkBuilder,"top_left_clicked", G_CALLBACK(top_left_clicked));
	gtk_builder_add_callback_symbol(gtkBuilder,"top_center_clicked", G_CALLBACK(top_center_clicked));
	gtk_builder_add_callback_symbol(gtkBuilder,"top_right_clicked", G_CALLBACK(top_right_clicked));
	gtk_builder_add_callback_symbol(gtkBuilder,"center_left_clicked", G_CALLBACK(center_left_clicked));
	gtk_builder_add_callback_symbol(gtkBuilder,"center_clicked", G_CALLBACK(center_clicked));
	gtk_builder_add_callback_symbol(gtkBuilder,"center_right_clicked", G_CALLBACK(center_right_clicked));
	gtk_builder_add_callback_symbol(gtkBuilder,"bottom_left_clicked", G_CALLBACK(bottom_left_clicked));
	gtk_builder_add_callback_symbol(gtkBuilder,"bottom_right_clicked", G_CALLBACK(bottom_right_clicked));
	
	//Assign the turn to the first player within a string variable
	char status_message[100] = "Turn:";
	strcat(status_message,(char*)p_one);
	//Attach the scores for each player
	strcat(status_message," Score: ");
	strcat(status_message,(char*)p_one);
	strcat(status_message,"[0] / ");
	strcat(status_message,(char*)p_two);
	strcat(status_message,"[0]");
	
	char theturn_message[100] = "It is your turn ";
	strcat(theturn_message,(char*)p_one);
	
	//Set the global player variables
	strcpy(players[PLAYER_ONE],(char*)p_one);
	strcpy(players[PLAYER_TWO],(char*)p_two);
	current_player = PLAYER_ONE;
	
	sendMessage(theturn_message,main_window);
	//Attach the string variable to the status message label
	gtk_label_set_text(GTK_LABEL(status_label),status_message);
	
	//Clear out the game board
	memset(game_board,5,sizeof game_board);

	//Show the main game window
	gtk_widget_show(main_window);
}
/*
 * Sub-function that checks the values of they palyer one and two name entries for validity, then executes the initialization of the main game window 
 * when the user clicks the start game button
*/
void play_game(GtkWidget* widget, gpointer* builder){
	//Buffer for player one's name
	GtkEntryBuffer *player_one_name_buffer;
	//Buffer for player two's name
	GtkEntryBuffer *player_two_name_buffer;
	//Get the buffer from the entry for player one
	player_one_name_buffer = gtk_entry_get_buffer(GTK_ENTRY(player_one_name));
	//Get the text from the player one buffer
	const gchar* str_player_one_name = gtk_entry_buffer_get_text(player_one_name_buffer);
	//Get the buffer from the entry for player two
	player_two_name_buffer = gtk_entry_get_buffer(GTK_ENTRY(player_two_name));
	//Get the text from the player two buffer
	const gchar* str_player_two_name = gtk_entry_buffer_get_text(player_two_name_buffer);
	//g_object_unref(player_one_name_buffer);
	//g_object_unref(player_two_name_buffer);
	//Check that the players names are not equal and that there is a name in both entries
	if(strcmp(str_player_one_name,"") & strcmp(str_player_two_name,"")){
		if(str_player_one_name != str_player_two_name){
			//Initialize the game window and pass it the names of the players
			gtk_widget_hide(GTK_WIDGET(player_info_dialog));
			init_game_window(str_player_one_name,str_player_two_name);
		}else{
			sendMessage("Please make sure that the players names are distinct.", player_info_dialog);
		}
	}else{
		sendMessage("Please enter a name for both players.", player_info_dialog);
	}
}
void btn_quit_game_clicked(GtkWidget *widget,gpointer pointer){
	gtk_main_quit();
} 
/*
 * Initialization sub-function for initializing and displaying the player information dialog after the splash screen has beed displayed
*/
static int bar_value = 0;
void init_player_information_dialog(gpointer pointer){
	//Get a reference to the player information dialog
	player_info_dialog = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"player_info_dialog"));
	//gtk_window_set_transient_for(GTK_WINDOW(player_info_dialog),NULL);
	//Get a reference to the player 1 name
	player_one_name = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"player_one_name"));
	//Get a reference to the player 2 name
	player_two_name = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"player_two_name"));
	//Add callback function for the play game button
	gtk_builder_add_callback_symbol(gtkBuilder,"play_game", G_CALLBACK(play_game));
	//Show the player information dialog
	gint result = gtk_dialog_run(GTK_DIALOG(player_info_dialog));
	//Check the result
	switch(result){
		//If the user clicks the exit button
		case GTK_RESPONSE_DELETE_EVENT:
			//Delete the message dialog
			g_source_remove(bar_timeout_resource);
			gtk_grab_remove(GTK_WIDGET(player_info_dialog));
			gtk_widget_destroy(GTK_WIDGET(player_info_dialog));
			gtk_main_quit(); 
			break;
		default:
			//Delete the message dialog
			g_source_remove(bar_timeout_resource); 
			gtk_grab_remove(GTK_WIDGET(player_info_dialog));
			gtk_widget_destroy(GTK_WIDGET(player_info_dialog));
			//gtk_main_quit();
			break;
	}
}
/*
 * Timeout function used to increment the loading bar at the bottom of the splash screen every 300mS
*/
static gboolean increase_splash_screen_level_bar(gpointer data){
	//Increment the bar as long as we are not at the end
	if(bar_value <= 10)
		gtk_level_bar_set_value(GTK_LEVEL_BAR(loading_bar),bar_value++);
	
	//Once we get to the end of the bar
	if(bar_value == 11){
		//Destroy the splash screen
		gtk_grab_remove(GTK_WIDGET(splash_screen));
		gtk_widget_destroy(GTK_WIDGET(splash_screen));
		//Stop the timeout		
		g_source_remove(bar_timeout_resource); 
		//Show the player information dialog
		init_player_information_dialog(gtkBuilder);
	}
	return TRUE;
}
/*
 * Callback Function for the splash screen's close button on the top right
*/
void close_splash_window(GtkWidget *widget, gpointer* pointer){
	//Destroy the splash screen
	gtk_grab_remove(GTK_WIDGET(splash_screen));
	gtk_widget_destroy(GTK_WIDGET(splash_screen));
	//Stop the timeout		
	g_source_remove(bar_timeout_resource); 
	//Show the player information dialog
	init_player_information_dialog(gtkBuilder);
}
/*
 *  Initialization sub-function for initializing and displaying the splash screen
*/
void init_splash_screen(){
	//Reference the splash screen from the Glade file
	splash_screen = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"splash_screen"));
	//Reference the splash screen's level bar from the Glade file
	loading_bar = GTK_WIDGET(gtk_builder_get_object(gtkBuilder,"loading_bar"));
	//Set the mode for the level bar to discrete
	gtk_level_bar_set_mode(GTK_LEVEL_BAR(loading_bar),GTK_LEVEL_BAR_MODE_DISCRETE);
	//Set the minimum value of the level bar to 0
	gtk_level_bar_set_min_value(GTK_LEVEL_BAR(loading_bar),0);
	//Set the maximum value of the level bar to 10
	gtk_level_bar_set_max_value(GTK_LEVEL_BAR(loading_bar),10);
	gtk_builder_add_callback_symbol(gtkBuilder, "close_splash_window", G_CALLBACK(close_splash_window));	
	//Add a callback for the splash window's close button
	gtk_widget_show(splash_screen);
	//Add a timeout function to update the value of the level bar
	bar_timeout_resource = g_timeout_add(300,increase_splash_screen_level_bar,NULL);
}
/*
 * Main GUI initialization routine
*/
void init_gui(){
	gtkBuilder = gtk_builder_new_from_file("gui.glade");
	//Connect all the signals from the Glade file with this implementation code
	gtk_builder_connect_signals(gtkBuilder, NULL);
	
	//Connect CSS File
	GtkCssProvider *cssProvider = gtk_css_provider_new ();
    gtk_css_provider_load_from_path(cssProvider,"style.css",NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	//Create and initialize the splash screen
	init_splash_screen();
	gtk_main();
}
/*
 * Main program entry point
*/
int main(int argc, char **argv){
	gtk_init(&argc,&argv);
	init_gui();
	return 0;
}

