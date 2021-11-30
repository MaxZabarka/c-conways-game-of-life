#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ioctl.h>

void randomizeGrid(int rows, int columns, int **grid)
{
    for (int col = 0; col < columns; col++)
    {
        for (int row = 0; row < rows; row++)
        {  
            // 30% of tiles will be alive
            grid[row][col] = rand() % 3 == 0;
        }
    }
}

void swapGrid(int ***a, int ***b)
{
    int **tmp = *a;
    *a = *b;
    *b = tmp;
}

static inline int getElement(int rows, int columns, int **board, int i, int j)
{
    return board[(i + rows) % rows][(j + columns) % columns];
}

void drawGrid(int gridX, int gridY, int **grid)
{
    printf("%s", " ┌");
    for (int i = 0; i < gridY; i++)
    {
        printf("%s", "──");
    }
    printf("%s", "┐\n");
    for (int i = 0; i < gridX; i++)
    {
        printf("%s", " │");
        for (int j = 0; j < gridY; j++)
        {
            if (grid[i][j] == 0)
            {
                printf("%s", "  ");
            }
            else
            {
                printf("%s", "██");
            }
        }
        printf("%s", "│");
        printf("%c", '\n');
    }
    printf("%s", " └");
    for (int i = 0; i < gridY; i++)
    {
        printf("%s", "──");
    }
    printf("%s", "┘\n");
}

int **advance(int rows, int columns, int **grid, int ***newgrid)
{

    int touchingcount;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            touchingcount = getElement(rows, columns, grid, i + 1, j + 0) +
                            //Top right
                            getElement(rows, columns, grid, i + 1, j + 1) +
                            //Up
                            getElement(rows, columns, grid, i + 0, j + 1) +
                            //Top left
                            getElement(rows, columns, grid, i - 1, j + 1) +
                            //Left
                            getElement(rows, columns, grid, i - 1, j + 0) +
                            //Bottom Left
                            getElement(rows, columns, grid, i - 1, j - 1) +
                            //Down
                            getElement(rows, columns, grid, i + 0, j - 1) +
                            //Bottom Right
                            getElement(rows, columns, grid, i + 1, j - 1);
            if (grid[i][j] == 1)
            {
                if (touchingcount == 2 || touchingcount == 3)
                {
                    (*newgrid)[i][j] = 1;
                }
                else
                {
                    (*newgrid)[i][j] = 0;
                }
            }
            else
            {
                if (touchingcount == 3)
                {
                    (*newgrid)[i][j] = 1;
                }
                else
                {
                    (*newgrid)[i][j] = 0;
                }
            }
        }
    }
}