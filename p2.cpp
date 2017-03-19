#include <ncurses.h>

int main()
{
	initscr();
	printw("Bye World!");
	refresh();
	getch();
	endwin();
	return 0;
}