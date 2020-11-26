#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rows = 4;
int columns = 5;

void createArray(int rows, int columns, int (*grid)[rows]) {
    for (int col=0; col<columns;col++){
        for(int row=0;row<rows;row++) {
            grid[row][col] = rand() % 2;
            printf("%d",grid[row][col]);
        }
        printf("\n");
    }
}
void main() {
    srand(time(NULL));
    int grid[rows][columns];
    int (*q)[rows] = grid;

    createArray(rows,columns,q);
    printf("\n%d\n",q[1][1]);

}
