#include <ncurses.h>

int main(void)
{
	WINDOW *tinkie;
	MEVENT mwhat;
	int ch,row,col;
	
	initscr();
	noecho();
	mousemask(ALL_MOUSE_EVENTS,NULL);

	tinkie = newwin(LINES-4,COLS-4,2,1);
	keypad(tinkie,TRUE);

	while(1)
	{
		ch = wgetch(tinkie);
		if( ch == KEY_MOUSE )
		{
			getmouse(&mwhat);
			row = mwhat.y;
			col = mwhat.x;
			wmouse_trafo(tinkie,&row,&col,FALSE);
			mvwaddch(tinkie,row,col,'*');
			refresh();
			continue;
		}
		if( ch == '\n' )
			break;
	}
	
	endwin();
	return 0;
}

/*
(Step 0)
Sprint, build something that works as quickly as possible

(Step 1)
that separate concerns into functions for the object-oriented aspect of the project

(Step 2)
Debug

(Step 3)
Customize, for extra design aspects
*/

/*

*/

/*
Editor TUI (40 points):
In addition to the editable text area, the main editor window needs to include text for the menu, the title, and the name of the file currently open in the editor.


Hypothesis:
	The editable text area is a subwindow that takes keyboard events.
	Menu is a clickable region with mouse-click listener.
	will utilize open, read, write, lseek, and close to read in the text to a buffer then save it.


*/



/*
F1 Menu (20 points): If the user presses the F1 key (or fn-F1 on a Mac), then your editor needs to create a window
somewhere in the terminal screen that allows the user to select from the following options:
{ Open: This option should prompt the user to enter in a filename. After the user presses return/enter, your editor
should attempt to open the file for editing. If an unsaved file is open in the editor when the user chooses this
option, then your editor needs to ask the user whether or not they want to save their changes before opening the
other le.
{ Save: This option should attempt to save the file currently open in the editor. The mode of the le should not be
changed by your editor.
{ Save As: This option should prompt the user to enter in a new filename and attempt to save the le currently
open in the editor to that new lename. If the le already exists, then your editor should ask the user if they want
to overwrite the existing le.
{ Exit: This option should exit your editor. If an unsaved le is open in the editor when the user chooses this option,
then your editor needs to ask the user whether or not they want to save their changes before exiting.
*/