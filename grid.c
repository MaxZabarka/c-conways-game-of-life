#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Usage

    //Set seed
    srand(time(NULL));

    //Dimensions
    int rows = 100;
    int columns = 100;
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

void createArray(int rows, int columns, int **grid) {
    for (int col=0; col<columns;col++){
        for(int row=0;row<rows;row++) {
            grid[row][col] = rand() % 2;
        }
    }
}
void freeArray(int rows, int **x) {
    for (int i = 0; i < rows; i++) {
        free(x[i]);
    }
    free(x);
}
