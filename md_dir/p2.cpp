#include <ncurses.h>

/*
Development Steps
#0 initial ncurses window
#1 Editor TUI
#2 F1 Menu
#3 Extra Credit
*/

// Global Variables

WINDOW *F1Menu;// #2
int COL2 = 38;	//#1 variable for COL2, testing mvaddstr
//int MENUMAX = 6;//#2 options for the menu **NOT WORKING

/*
 #2
 drawmenu
 needed to select menu items

void drawmenu(int item)
{
	int c;
	char mainmenu[] = "Main Menu";
	char menu[MENUMAX][21] = {		// 6
		"Open",
		"Save",
		"Save As",
		"Poop",
		"Icecream",
		"Exit"
	};

	clear();
	addstr(mainmenu);
	for(c=0;c<MENUMAX;c++)
	{
		if( c==item )
			attron(A_REVERSE);	// highlight selection
		mvaddstr(3+(c*2),20,menu[c]);
		attroff(A_REVERSE);		// remove highlight
	}
	mvaddstr(17,25,"Use arrow keys to move; Enter to select:");// enter functionality not designed
	refresh();
}
*/


// prototype: only needed since it is place before main
void showF1Menu(void);// #2

int main()
{

	int key;		//#2 key for the menu
	int menuitem = 0;	//#2 menu items

	int ch;// #2
	initscr();// #0
	
	/**
	 * Build F1Menu
	 */
	if((F1Menu = newwin(10,30,4,26)) == NULL)
	{
		addstr("Unable to allocate window memory\n");
		endwin();
		return(1);
	}// end if
	keypad(stdscr, true);
	mvwaddstr(F1Menu,1,1,"Menu Screen");
	mvwaddstr(F1Menu,3,1,"Press [ ~ ] to quit");
	mvwaddstr(F1Menu,5,1,"Press [ENTER] to go back");





	box(F1Menu,0,0); // end BuildF1Menu





	/* now start the program loop */
	mvaddstr(0,0,"F1: Menu");//#1, testing mvaddstr
	mvaddstr(0,COLS/2,"CSCI 1730 Editor! Press [ctrl+c] to exit");// #1, testing mvaddstr
	//mvprintw(11,COL2, "test", "test");// #1, testing mvprintw
	
	/**
	 * #2
	 * F1Menu
	 */
	refresh();
	noecho();
	do
	{
		ch = getch();
		refresh();
		if(ch == KEY_F(1))
			showF1Menu();
		else
			addch(ch);
	} while (ch != '~');
	
	
	
	
/*
  Menu Items

drawmenu(menuitem);
keypad(stdscr,TRUE);
noecho();			// Disable echo
do
{
	key = getch();
	switch(key)
	{
		case KEY_DOWN:
			menuitem++;
			if(menuitem > MENUMAX-1) menuitem = 0;
			break;
		case KEY_UP:
			menuitem--;
			if(menuitem < 0) menuitem = MENUMAX-1;
			break;
		default:
			break;
	}
	drawmenu(menuitem);
} while(key != '\n');

echo();				/ re-enable echo 
*/


	refresh();// #0
	getch();  // #0
	endwin(); // #0
	return 0; // #0
}

/**
 * #2
 * showF1Menu
 * displays F1Menu after F1 key is pressed, fn+F1 on MAC
 */
void showF1Menu(void)
{
	touchwin(F1Menu); // force update
	wrefresh(F1Menu);
	getchar();		  // wait for key press
	touchwin(stdscr); // forces character update
	refresh();
}


