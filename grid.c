#include <stdio.h>
int main() {
    int xSize, ySize;
    xSize = 3;
    ySize = 3;
    int grid[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int (*grid_pointer)[xSize] = grid;
    

    printf("%d\n",**grid_pointer);
    //Advance by 1 integer
    *(*grid_pointer)+=1;
    printf("%d\n",**grid_pointer);
    //Advance by 1 row
    *(grid_pointer+=1);
    printf("%d\n",**grid_pointer);


    // for (;**grid_pointer<10;grid_pointer++) {
    //     printf("%d\n",**grid_pointer);
    // }
}