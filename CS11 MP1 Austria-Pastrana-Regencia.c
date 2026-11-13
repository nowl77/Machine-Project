#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define gridX 15
#define gridY 15

#define snakeX 13
#define snakeY 13

//Defines the length of the snake
int length = 1;

//Checks whether the game is over
bool isGameOver = false;

int i = 1, j = 1;

void border(){

}


char movement(char move){
    int k, l;

    char snake[gridX][gridY];

    switch(move){
        case 'd':
            j++;

            //Dictates which array is border and head
            for(k = 0; k<gridX; k++){
                for(l = 0; l<gridY; l++){
                    if(k == 0 || k == gridX - 1 || l == 0 || l == gridY - 1){
                        snake[k][l] = '#';
                    }
                    else if(k == i && l == j){
                        snake[k][l] = '@';       //<-- Prints the head
                    }
                    else{
                        snake[k][l] = ' ';
                    }
                }
            }

            //Prints grid and head
            for(k = 0; k < gridX; k++){
                for(l = 0; l < gridY; l++){
                    printf("%c  ", snake[k][l]);
                }
                printf("\n");
            }
            break;
        
        case 'w':
            i--;

            //Dictates which array is border and head
            for(k = 0; k<gridX; k++){
                for(l = 0; l<gridY; l++){
                    if(k == 0 || k == gridX - 1 || l == 0 || l == gridY - 1){
                        snake[k][l] = '#';
                    }
                    else if(k == i && l == j){
                        snake[k][l] = '@';       //<-- Prints the head
                    }
                    else{
                        snake[k][l] = ' ';
                    }
                }
            }

            //Prints grid and head
            for(k = 0; k < gridX; k++){
                for(l = 0; l < gridY; l++){
                    printf("%c  ", snake[k][l]);
                }
                printf("\n");
            }
            break;
            
        case 'a':
            j--;

            //Dictates which array is border and head
            for(k = 0; k<gridX; k++){
                for(l = 0; l<gridY; l++){
                    if(k == 0 || k == gridX - 1 || l == 0 || l == gridY - 1){
                        snake[k][l] = '#';
                    }
                    else if(k == i && l == j){
                        snake[k][l] = '@';       //<-- Prints the head
                    }
                    else{
                        snake[k][l] = ' ';
                    }
                }
            }

            //Prints grid and head
            for(k = 0; k < gridX; k++){
                for(l = 0; l < gridY; l++){
                    printf("%c  ", snake[k][l]);
                }
                printf("\n");
            }
            break;

        case 's':
            i++;

            //Dictates which array is border and head
            for(k = 0; k<gridX; k++){
                for(l = 0; l<gridY; l++){
                    if(k == 0 || k == gridX - 1 || l == 0 || l == gridY - 1){
                        snake[k][l] = '#';
                    }
                    else if(k == i && l == j){
                        snake[k][l] = '@';       //<-- Prints the head
                    }
                    else{
                        snake[k][l] = ' ';
                    }
                }
            }

            //Prints grid and head
            for(k = 0; k < gridX; k++){
                for(l = 0; l < gridY; l++){
                    printf("%c  ", snake[k][l]);
                }
                printf("\n");
            }
            break;

        default:
    }  
}


int main(){

    int i,j;
    char grid[gridX][gridY];

    //Decides which X and Y will have borders
    for(i = 0; i<gridX; i++){
        for(j = 0; j<gridY; j++){
            if(i == 0 || i == gridX - 1 || j == 0 || j == gridY - 1){
                grid[i][j] = '#';
            }
            else if(i == 1 && j == 1){
                grid[i][j] = '@';       //<-- Prints the head
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
    
    while(isGameOver == false){

        //Asks the user for input
        char direction [50];
        fgets(direction, sizeof(direction), stdin);
        movement(direction[0]);

    }
    return 0;
}