// scaffold
#include <ncurses.h>

int main()
{
	initscr();
	addstr("Skeleton NCurses Prog.");
	refresh();
	getch();
	endwin();
	return 0;
}