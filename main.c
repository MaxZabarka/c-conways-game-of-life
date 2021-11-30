#include <string.h>
#include "grid.c"
#include <time.h>
#include <unistd.h>

void clear()
{
	printf("\e[1;1H\e[2J");
}
int main()
{

	//Draw grid
	int rows = 20;
	int columns = 20;

	int **grid;
	int **newgrid;

	//Allocate memory
	grid = malloc(rows * sizeof(*grid));
	for (int i = 0; i < rows; i++)
	{
		grid[i] = malloc(columns * sizeof(grid[0]));
	}
	createArray(rows, columns, grid);
	newgrid = malloc(rows * sizeof(*newgrid));
	for (int i = 0; i < rows; i++)
	{
		newgrid[i] = malloc(columns * sizeof(newgrid[0]));
	}


	while (1)
	{
		clear();
		drawGrid(rows, columns, grid);
		advance(rows, columns, grid, &newgrid);
		swap(&grid, &newgrid);
		usleep(100 * 1000);
	}

	free(grid);
	return 0;
}
