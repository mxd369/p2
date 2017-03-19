#include <ncurses.h>

int main()
{
	initscr();// #0
	addstr("F1 Menu");//#2
	printw("CSCI 1730 Editor!");// #0
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
*/
