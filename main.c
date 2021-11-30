#include <ncurses.h>
#include <string.h>
#include "grid.c"
#include <time.h>
#include <stdlib.h>

int main()
{
	//Initialize
	initscr();
	noecho();
	cbreak();
	srand(time(NULL));

	//Get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	//Create window and draw box
	int margin = 1;
	WINDOW *gamewin = newwin(yMax - margin, xMax - margin, margin, margin);
	//WINDOW* gamewin = newwin(15,15,margin,margin);

	box(gamewin, 0, 0);
	int boxY, boxX;
	getmaxyx(gamewin, boxY, boxX);

	//Draw grid
	int rows = boxX - 2;
	int columns = boxY - 2;

	int **grid;
	int **newgrid;

	//Allocate memory
	grid = malloc(rows * sizeof(*grid));
	for (int i = 0; i < rows; i++)
	{
		grid[i] = malloc(columns * sizeof(grid[0]));
	}

	newgrid = malloc(rows * sizeof(*newgrid));
	for (int i = 0; i < rows; i++)
	{
		newgrid[i] = malloc(columns * sizeof(newgrid[0]));
	}
	grid[0][0] = 1;
	grid[0][1] = 1;
	grid[0][2] = 1;

	grid[1][0] = 1;
	grid[1][1] = 0;
	grid[1][2] = 0;

	grid[2][0] = 0;
	grid[2][1] = 1;
	grid[2][2] = 0;

	// printGrid(rows, columns, grid);

	//Print title and dimensions
	char title[] = " Conway's Game of Life! ";
	attron(A_REVERSE);
	int titleLength = strlen(title);
	mvprintw(0, 0, "%d x %d\n", boxX, boxY);
	mvprintw(0, xMax / 2 - titleLength / 2, title);

	refresh();
	wrefresh(gamewin);

	while (1)
	{
		usleep( 1000*1000);
		drawGrid(rows, columns, grid, gamewin);
		advance(rows, columns, grid, &newgrid);
		swap(&grid, &newgrid);
	}

	getch();
	endwin();
	free(grid);
	return 0;
}
