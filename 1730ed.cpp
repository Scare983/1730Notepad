#include <ncurses.h>
#include <cstdlib>
#include "GUI.cpp"
#include "Menuscreen.cpp"
using namespace std;

int main (int argc,  char *argv[]) {
GUI gui = GUI(argc, argv);
return EXIT_SUCCESS;
/*
	initscr();
	keypad(stdscr,true);
	noecho();

	int c = getch();

	if(c == KEY_F(1)){ //112 = f1
		Menuscreen screen = Menuscreen(stdscr);
			if(!screen.isNCursesOpen()) {
			endwin();
			return EXIT_SUCCESS;
			}
	}


refresh();

endwin();
return EXIT_SUCCESS;

*/


}
