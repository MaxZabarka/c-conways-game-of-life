#include <stdio.h>
int main() {
    int xSize, ySize;
    xSize = 3;
    ySize = 3;
    int grid[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int (*grid_pointer)[xSize] = grid;
    
    for (int col = 0; col<ySize;col++){
        printf("[");
        for(int row=0;row<xSize;row++) {
            printf("%d, ",**grid_pointer);
            *(*grid_pointer)+=1;
        }
        printf("]\n");


        *(*grid_pointer)-=3;
        *(grid_pointer+=1);
    }
}