#include <ncurses.h>
#include <string.h>
#include "grid.c"
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
	//WINDOW* gamewin = newwin(yMax-margin,xMax-margin,margin,margin);
	WINDOW* gamewin = newwin(15,15,margin,margin);

	box(gamewin, 0, 0);
	int boxY,boxX;
	getmaxyx(gamewin, boxY, boxX);
	printw("%d x %d\n",boxX,boxY);

	//Draw grid
	int gridX = 500;
	int gridY = 500;

	srand(time(NULL));
    char grid[gridX][gridY];
    char (*q)[gridX] = grid;
    createArray(gridX,gridY,q);

	for (int i=0;i<gridX;i++) {

		for (int j=0;j<gridY;j++) {

			if (!(grid[i][j] == 0)) {
				mvwaddch(gamewin,j+1,i+1,'#');
				
			}
		

		}
	}


	//Print title
	char title[] = " Conway's Game of Life! ";
	attron(A_REVERSE);
	int titleLength = strlen(title);
	mvprintw(0,xMax/2-titleLength/2,title);
	
	refresh();
	wrefresh(gamewin);

	getch();
	endwin();
	return 0;
}
void draw() {
	
}