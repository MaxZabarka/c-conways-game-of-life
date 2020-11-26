#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// int **createArray(int rows,int columns) {
//     int xSize, ySize;
//     xSize = rows;
//     ySize = columns;
//     int grid[xSize][ySize];
//     int (*grid_pointer)[xSize] = grid;
//     srand(time(NULL));

//     for (int col = 0; col<ySize;col++){
//         printf("[");
//         for(int row=0;row<xSize;row++) {
//             **grid_pointer = rand() % 2;

//             printf("%d, ",**grid_pointer);
//             *(*grid_pointer)+=1;
//         }
//         printf("]\n");
//         *(*grid_pointer)-=3;
//         *(grid_pointer+=1);
//     }
//     return grid;
// }
void createArray(int rows, int columns,int grid[3][3]) {
    grid[0][0] = 10;
    // for (int col=0; col<columns;col++){
    //     for(int row=0;row<rows;row++) {
    //         grid[row][col] = rand() % 2;
    //         printf("%d",grid[row][col]);
    //     }
    //     printf("\n");
    // }
}
void main() {
    int rows = 3;
    int columns = 3;
    
    int grid[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int (*q)[][3] = grid;

    printf("%d\n",**q);
    // grid[0][0] = 4;
    // printf("%d\n",grid[0][0]);
    // createArray(3,3,grid);
    // printf("%d\n",grid[0][0]);

    // srand(time(NULL));

   // printf("%d",grid[0][0]);
}
