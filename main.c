#include <string.h>
#include "grid.c"
#include <sys/time.h>
#include <unistd.h>

#define SPEED 100

long long current_timestamp()
{
	struct timeval te;
	gettimeofday(&te, NULL);
	long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return milliseconds;
}

void get_window_size(int *rows, int *cols)
{
	struct winsize ws;
	ioctl(0, TIOCGWINSZ, &ws);
	*rows = ws.ws_row;
	*cols = ws.ws_col;
}

void clear()
{
	printf("\e[1;1H\e[2J");
}
int main()
{

	int rows;
	int columns;

	get_window_size(&rows, &columns);

	rows = rows-3;
	columns = (columns / 2)-2;

	int **grid;
	int **newgrid;

	//Allocate memory
	grid = malloc(rows * sizeof(*grid));
	for (int i = 0; i < rows; i++)
	{
		grid[i] = malloc(columns * sizeof(grid[0]));
	}
	randomizeGrid(rows, columns, grid);
	newgrid = malloc(rows * sizeof(*newgrid));
	for (int i = 0; i < rows; i++)
	{
		newgrid[i] = malloc(columns * sizeof(newgrid[0]));
	}

	unsigned long start_time;
	while (1)
	{
		start_time = current_timestamp();
		clear();
		drawGrid(rows, columns, grid);
		advance(rows, columns, grid, &newgrid);
		swapGrid(&grid, &newgrid);
		while (current_timestamp() < start_time + SPEED)
		{
		}
		// usleep(100 * 1000);
	}

	free(grid);
	return 0;
}
