#include <ncurses.h>

int main()
{
	initscr();
	printw("CSCI 1730 Editor!");
	refresh();
	getch();
	endwin();
	return 0;
}