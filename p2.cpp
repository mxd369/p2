#include <ncurses.h>

int main()
{
	initscr();// #0
	mvaddstr(0,0,"F1: Menu");//#0 && #2
	mvaddstr(0,COLS/2,"CSCI 1730 Editor!");// #0

	
	//KEY_F(1); //#2

	refresh();// #0
	getch();  // #0
	endwin(); // #0
	return 0; // #0
}
/*
Development Steps
#0 initial ncurses window
#1 Editor TUI
#2 F1 Menu
#3 Extra Credit
*/
