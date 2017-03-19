/*
getwin() is the companion function to putwin(),
which saves WINDOW data to disk.
*/

/*
WINDOW *getwin(FILE * filep);

getwin()
putwin()

filep is a FILE variable representing a file opened for reading on disk
*/
#include <ncurses.h>
#include <stdlib.h>

#define FILENAME "WINDOW.dat"

void bomb(char *message);

int main(void)
{
	FILE *wfile;
	WINDOW * win;
	int r;
	
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE,COLOR_RED);

	addstr("Press Enter to read the window from disk:\n");
	refresh();
	getch();

/* open the file */
	wfile = fopen(FILENAME, "r");
	if ( wfile == NULL)
		bomb("Error reading file\n");

/* write the window's data */
	win = getwin(wfile);
	if( win == NULL)
		bomb("Unable to read/create window\n");
	fclose(wfile);
	wrefresh(win);
	getch();

	endwin();
	return 0;
}

void bomb(char *message)
{
	endwin();
	puts(message);
	exit(1);
	
}