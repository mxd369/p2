/*
You should challenge yourself to figure out how you may implement this without going into details first - 
(What is the very first thing I need to do to implement scrolling ? ) 
Open the specified file.
(Then what?)
I would need some sort of storage to read in the file.
(What is scrolling?) 
Displaying different areas of the content relative to the terminal size. 
(How to do it in the most simplest of ways?)
Erase the screen and print the new lines as required.
 
So now we know what we are supposed to do. Input a file, Store the contents, Display the sections as required. 
 
How may we go about implementing it?

Use the resources provided and search for the parts - 
1) Opening a file (google says ifstream, check an example program)
2) Storing a file (What are the issues? size of file? number of lines? datastructure?)
3) Displaying in ncurses (How to display a single line in ncurses?)
4) Erasing in ncurses?
 
If you have the answer to these you can implement the scrolling problem

The first program is very basic and inefficient - 
It does what I described above, open a file, store it, display sections of it as needed. (This is scrolling no matter how inefficient it is). 
 
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace::std; 
 
int main(const int argc, const char * argv[]){
//Step1 - Open a file
initscr();
ifstream r, r1;
r.open(argv[1]);
r1.open(argv[1]);
//Step2 - calculate the number of lines in file and store the lines in a string 
int numlines = 0; 


int height, width;
getmaxyx(stdscr, height, width); 

string line;
while( getline(r,line)){
numlines++;
} 
string * storage = nullptr; 
storage = new string[numlines];


for(int j = 0; j < numlines; j++){
getline(r1,line);
storage[j] = line;
}
 
//Step 3 Print to a ncurses window
 
WINDOW * win=newwin(height,width,0,0);
for(int i = 0; i < numlines; i++){
wprintw(win, storage[i].c_str());
wprintw(win, "\n");
}
refresh();
 
//Now you have the initial screen starting from the line 1 (or 0 however you prefer) till the amount of display the //terminal permits.
 */
/* What do you need next? Some way to get the user input to see if they requested scrolling. How may you do this, simple have an infinite loop (untill they exit) which will scroll up or down as needed)
*/
/*
int start = 0;
keypad(win, true); // set KEYPAD on
int KEY = wgetch(win); // get user input
int breakout=0;//control loop for user to breakout if they hit anything other than up and down keys
while(breakout==0){
switch(KEY){
case KEY_UP: 
if(start >= 0)
{start--;
werase(win);

erase the old texts printed into the window and reprint as follows, notice how I am changing the start location. This is all thats required to mimic scrolling i.e. reprint based on the current location the user wants to view from*/

/*
for(int i = start; i < numlines; i++){ 
wprintw(win, storage[i].c_str());
wprintw(win, "\n");
}

refresh();
}
KEY = wgetch(win);
break;

case KEY_DOWN:
if(start < numlines){
werase(win);
start++;
for(int i = start; i < numlines; i++){
wprintw(win, storage[i].c_str());
wprintw(win, "\n");
}

refresh();

}

KEY = wgetch(win);
break;

default:

breakout=1;
break;
}
}

delete [] storage; 
endwin(); 
return 0;
}
*/

#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace::std;
int main(const int argc, const char * argv[]){

initscr();
ifstream r, r1;
r.open(argv[1]);
r1.open(argv[1]);
int numlines = 0; 


int height, width;
getmaxyx(stdscr, height, width); 

string line;
while( getline(r,line)){
numlines++;
} 
string * storage = nullptr; 
storage = new string[numlines];


for(int j = 0; j < numlines; j++){
getline(r1,line);
storage[j] = line;
}
WINDOW * win=newwin(height,width,0,0);
for(int i = 0; i < numlines; i++){
wprintw(win, storage[i].c_str());
wprintw(win, "\n");
}
int start = 0;
refresh();

keypad(win, true);
int KEY = wgetch(win);
int breakout=0;
while(breakout==0){
switch(KEY){
case KEY_UP: 
if(start >= 0)
{start--;
werase(win);
for(int i = start; i < numlines; i++){
wprintw(win, storage[i].c_str());
wprintw(win, "\n");
}

refresh();
}
KEY = wgetch(win);
break;

case KEY_DOWN:
if(start < numlines){
werase(win);
start++;
for(int i = start; i < numlines; i++){
wprintw(win, storage[i].c_str());
wprintw(win, "\n");
}

refresh();

}

KEY = wgetch(win);
break;

default:

breakout=1;
break;
}
}

delete [] storage;

endwin();
return 0;
}