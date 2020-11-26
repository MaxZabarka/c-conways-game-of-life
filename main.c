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
	WINDOW* gamewin = newwin(yMax-margin,xMax-margin,margin,margin);
	//WINDOW* gamewin = newwin(15,15,margin,margin);

	box(gamewin, 0, 0);
	int boxY,boxX;
	getmaxyx(gamewin, boxY, boxX);

	//Draw grid
	int gridX = boxX-2;
	int gridY = boxY-2;

    //Set seed
    srand(time(NULL));

    int** grid;

    //Allocate memory
    grid = malloc(gridX * sizeof(*grid));
    for (int i = 0; i < gridX; i++) {
        grid[i] = malloc(gridY * sizeof(grid[0]));
    }

	createArray(gridX,gridY,grid);


	for (int i=0;i<gridX;i++) {

		for (int j=0;j<gridY;j++) {

			if (!(grid[i][j] == 0)) {
				mvwaddch(gamewin,j+1,i+1,'#');
			
			}
		}
	}


	//Print title and dimensions

	char title[] = " Conway's Game of Life! ";
	attron(A_REVERSE);
	int titleLength = strlen(title);
	mvprintw(0,0,"%d x %d\n",boxX,boxY);
	mvprintw(0,xMax/2-titleLength/2,title);

	refresh();
	wrefresh(gamewin);

	getch();
	endwin();
	free(grid);
	return 0;
}
void draw() {
	
}