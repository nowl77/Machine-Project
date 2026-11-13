#include <stdio.h>
#include <string.h>

#define gridX 15
#define gridY 15

#define snakeX 13
#define snakeY 13

//Defines the length of the snake
int length = 1;




int main(){

    int i,j;
    char grid[gridX][gridY];

    //Decides which X and Y will have borders
    for(i = 0; i<gridX; i++){
        for(j = 0; j<gridY; j++){
            if(i == 0 || i == gridX - 1 || j == 0 || j == gridY - 1){
                grid[i][j] = '#';
            }
            else{
                grid[i][j] = ' ';
            }
        }
    }

    //Prints the borders
    for(i = 0; i < gridX; i++){
        for(j = 0; j < gridY; j++){
            printf("%c  ", grid[i][j]);
        }
        printf("\n");
    }
    

    //Asks the user for input

    return 0;
}