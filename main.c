#include <ncurses.h>
#include <string.h>
int main() {
	//Initialize
	initscr();
	noecho();
	cbreak();

	//Get screen size
	int yMax, xMax;
	getmaxyx(stdscr,yMax,xMax);

	//Create window and draw box
	int margin = 1;
	WINDOW* inputwin = newwin(yMax-margin,xMax-margin,margin,margin);
	box(inputwin, 0, 0);
	int boxY,boxX;
	getmaxyx(inputwin, boxY, boxX);
	printw("%d x %d\n",boxX,boxY);


	//Print title
	char title[] = " Conway's Game of Life! ";
	attron(A_REVERSE);
	int titleLength = strlen(title);
	mvprintw(0,xMax/2-titleLength/2,title);
	
	refresh();
	wrefresh(inputwin);

	getch();
	endwin();
	return 0;
}