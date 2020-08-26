#include "ncurses.h"
#include <iostream>
using namespace std;
class Menuscreen{
private:
bool NCursesOpen = true;
public:
 Menuscreen(WINDOW* stdscr) {
 WINDOW *w;
    char list[5][15] = { "Open", "Save", "Save As", "Close Menu", "Exit" };
    char item[7];
    int ch, i = 1;
 
    
    w = newwin( 10, 30, 0,0 ); // create a new window
    box( w, 0, 0 ); // sets default borders for the window
    sprintf( item ," %-7s", "My Menu ");
    mvwprintw(w, i+-1,2, "%s", item);
		
// now print all the menu items and highlight the first one
    for( i=0; i<5; i++ ) {
        if( i == 0 ) 
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT );
        sprintf(item, "%-7s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item );
    }
 
    wrefresh( w ); // update the terminal screen
 
    i = 0;
    noecho(); // disable echoing of characters on the screen
    keypad( w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.
     
       // get the input
	   bool menuOn = true;
    while(menuOn){ 
         ch = wgetch(w);
                // right pad with spaces to make the items appear with even width.
            sprintf(item, "%-7s",  list[i]); 
            mvwprintw( w, i+1, 2, "%s", item ); 
              // use a variable to increment or decrement the value based on the input.
            switch( ch ) {
                case KEY_UP:
                            i--;
                            i = ( i<0 ) ? 4 : i;
                            break;
                case KEY_DOWN:
                            i++;
                            i = ( i>4 ) ? 0 : i;//if i surpasses the last option, 
                            break;
							
				case 10: //e10 = enter, KEY_ENTER does not work.
					menuOn = false;
						if(true) {//if open is highlighted
							
							break;
						}
						
						if(true) {//if save is highlighted
							
							
							break;
						}
						
						
						if(true) { //if save as is highlighted
							
							
							break;
						}
						
						if(true) { //Close Menu is highlighted
							
						
							break;
						}
						
						if(true) { //Exit is highlighted
							
							NCursesOpen = false;
							break;
						}
					break;		
							
            }
            // now highlight the next item in the list.
            wattron( w, A_STANDOUT );
             
            sprintf(item, "%-7s",  list[i]);
            mvwprintw( w, i+1, 2, "%s", item);
            wattroff( w, A_STANDOUT );
    }
 
    delwin( w );
 }
 
 
 bool isNCursesOpen()  {
	 return NCursesOpen;
 }
 
 
 
 
 
};
