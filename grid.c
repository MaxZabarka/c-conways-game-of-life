#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ioctl.h>

/*Usage

    //Set seed
    srand(time(NULL));

    //Dimensions
    int rows = 100;
    int columns = 200;
    int** x;

    //Allocate memory
    x = malloc(rows * sizeof(*x));
    for (int i = 0; i < rows; i++) {
        x[i] = malloc(columns * sizeof(x[0]));
    }

    //Populate with random 1s and 0's
    createArray(rows,columns,x);
    free(x);
*/

void createArray(int rows, int columns, int **grid)
{
    for (int col = 0; col < columns; col++)
    {
        for (int row = 0; row < rows; row++)
        {

            // grid[row][col] = 0;

            grid[row][col] = rand() % 2;
        }
    }
}
void swap(int ***a, int ***b)
{
    int **tmp = *a;
    *a = *b;
    *b = tmp;
}
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}
int GetElement(int rows, int columns, int **board, int i, int j)
{
    return board[(i + rows) % rows][(j + columns) % columns];
}

void freeArray(int rows, int **x)
{
    for (int i = 0; i < rows; i++)
    {
        free(x[i]);
    }
    free(x);
}
void drawGrid(int gridX, int gridY, int **grid)
{
    printf("%s", "┌");
    for (int i = 0; i < gridY; i++)
    {
        printf("%s", "──");
    }
    printf("%s", "┐\n");
    for (int i = 0; i < gridX; i++)
    {
        printf("%s", "│");
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
    printf("%s", "└");
    for (int i = 0; i < gridY; i++)
    {
        printf("%s", "──");
    }
    printf("%s", "┘\n");
}
void printGrid(int gridX, int gridY, int **grid)
{
    for (int i = 0; i < gridX; i++)
    {
        for (int j = 0; j < gridY; j++)
        {
            if (!(grid[i][j] == 0))
            {
                printf("██");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("--------\n");
}

int **advance(int rows, int columns, int **grid, int ***newgrid)
{

    int touchingcount;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            /**** SPAGHETTI INCOMING *****/
            //right

            //Right
            touchingcount = GetElement(rows, columns, grid, i + 1, j + 0) +
                            //Top right
                            GetElement(rows, columns, grid, i + 1, j + 1) +
                            //Up
                            GetElement(rows, columns, grid, i + 0, j + 1) +
                            //Top left
                            GetElement(rows, columns, grid, i - 1, j + 1) +
                            //Left
                            GetElement(rows, columns, grid, i - 1, j + 0) +
                            //Bottom Left
                            GetElement(rows, columns, grid, i - 1, j - 1) +
                            //Down
                            GetElement(rows, columns, grid, i + 0, j - 1) +
                            //Bottom Right
                            GetElement(rows, columns, grid, i + 1, j - 1);
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

void test()
{
    //Set seed
    srand(time(NULL));

    //Dimensions
    int rows = 10;
    int columns = 10;
    int **grid;
    int **newgrid;

    //Allocate memory
    grid = malloc(rows * sizeof(*grid));
    for (int i = 0; i < rows; i++)
    {
        grid[i] = malloc(columns * sizeof(grid[0]));
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

    // grid[0][0] = 1;
    // grid[0][1] = 1;
    // grid[0][2] = 0;

    // grid[1][0] = 1;
    // grid[1][1] = 0;
    // grid[1][2] = 1;

    // grid[2][0] = 0;
    // grid[2][1] = 0;
    // grid[2][2] = 0;

    // grid[3][0] = 0;
    // grid[3][1] = 1;
    // grid[3][2] = 0;

    //Allocate memory for newgrid grid
    newgrid = malloc(rows * sizeof(*newgrid));
    for (int i = 0; i < rows; i++)
    {
        newgrid[i] = malloc(columns * sizeof(newgrid[0]));
    }
    //printf("%d\n",mod(-1,5));
    //Populate with random 1s and 0's
    //createArray(rows,columns,grid);
    printGrid(rows, columns, grid);
    advance(rows, columns, grid, &newgrid);
    swap(&grid, &newgrid);

    printGrid(rows, columns, grid);
    advance(rows, columns, grid, &newgrid);
    swap(&grid, &newgrid);

    // printGrid(rows,columns,grid);

    // advance(rows,columns,grid,&newgrid);
    // grid = newgrid;
    // printGrid(rows,columns,grid);

    // advance(rows,columns,grid,&newgrid);
    // grid = newgrid;
    // printGrid(rows,columns,grid);

    // advance(rows,columns,grid,&newgrid);
    // grid = newgrid;
    // printGrid(rows,columns,grid);

    // advance(rows,columns,grid,&newgrid);
    // grid = newgrid;
    // printGrid(rows,columns,grid);
    // advance(rows,columns,grid,&newgrid);
    // grid = newgrid;
    // printGrid(rows,columns,grid);
    // advance(rows,columns,grid,&newgrid);
    // grid = newgrid;
    // printGrid(rows,columns,grid);

    free(grid);
}
