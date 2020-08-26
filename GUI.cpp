#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include  <string.h>
using namespace::std;
class GUI {
public:

GUI(const int argc,  char * argv[]){

initscr();
	

const char *filename = argv[1];
ifstream r, r1;
int numlines = 1; 
int height, width;
string line = "";
string * storage = nullptr;
storage = new string[560];
int i;

r.open(filename);
if((r.rdstate() & std::ifstream::failbit) !=0) {
while(numlines < 560) {
storage[numlines] = " ";
numlines++;
}
goto startOfCode;

//happens if cannot open a file with that name
}
r1.open(filename);

while( getline(r,line)){
numlines++;
} 



for(int j = 0; j < numlines; j++){
getline(r1,line);
storage[j] = line;
}
 i =numlines;
while(numlines < 560) {
storage[numlines] = " ";
numlines++;
}



startOfCode:
getmaxyx(stdscr, height, width); 


/*for(int i = numlines ; i < 560; i++) {
wmove(
line = "k";
storage[i] = line;

}*/
WINDOW * win=newpad(numlines,width);

refresh();
wrefresh(win);


start_color();			/* Start color 			*/
init_pair(1, COLOR_RED, COLOR_BLACK);
 attron(COLOR_PAIR(1));


mvprintw(height-2,0,"F1: Menu");
mvprintw(height-1, width/2-4,  filename);
	mvprintw(height-2, width/2-8,  "1730ed Text Editor");
 attroff(COLOR_PAIR(1));
height = height -2;





refresh();

for(int i = 0; i < 560; i++){
mvwaddstr(win, i, 0, storage[i].c_str());
//waddstr(win,"k");

if(i >=numlines) {

waddstr(win,"k");
}

}
int y = 0;
int x = 0;
wmove(win, x,y);

int start = 0;

prefresh(win,start,0,0,0,height-1,width);

int length[560];
for(int i =0; i < 560; i++) {
length[i] = strlen(storage[i].c_str());

}
loop:
int value;
keypad(win, true);

//length[0] = strlen(storage[y].c_str());

int KEY = wgetch(win);

int breakout=0;
while(breakout==0){

switch(KEY){
case KEY_UP: 
if(start > 0) {
start--;
}
if(y !=0) {
y--;
}
if(x>length[y]) {
wmove(win,y,length[y]);
x = length[y];
}


wmove(win, y,x);
  
prefresh(win,start,0,0,0,height-1,width);

KEY = wgetch(win);
break;

case KEY_DOWN:



if( y > height-2) {
start++;
}
y++;
//length[y] = strlen(storage[y].c_str());
wmove(win, y,x);
if(x>length[y]) {
wmove(win,y,length[y]);
x = length[y];
}


prefresh(win,start,0,0,0,height-1,width);
KEY = wgetch(win);
break;

case KEY_RIGHT:
//length[y] = strlen(storage[y].c_str());
if( x<length[y]) {
x++;
wmove(win,y,x);
}
if(x>length[y]) {
wmove(win,y,length[y]);
}
prefresh(win,start,0,0,0,height-1,width);
KEY = wgetch(win);
break;



case KEY_LEFT:
//length[y] = strlen(storage[y].c_str());
if( x>0) {
x--;
}
wmove(win,y,x);
prefresh(win,start,0,0,0,height-1,width);
KEY =wgetch(win);
break;

case KEY_F(1):
goto endloop;
break;

case 8://backspace
mvwdelch(win, y,x);
if(x >0) {
x--;

}
wmove(win,y,x);
length[y]--;


KEY = wgetch(win);
prefresh(win,start,0,0,0,height-1,width);
break;

default: 
goto otherloop;

break;
}
}

//////////////

otherloop:
//add given chars

goto loop;
/////////////
endloop:




//refresh();
delete [] storage;

endwin();

}
};
