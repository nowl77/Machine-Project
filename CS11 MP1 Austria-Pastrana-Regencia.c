#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define gridX 15
#define gridY 15


//Defines the length of the snake
int length = 1;

//Checks whether the game is over
bool isGameOver = false;

//Value inside arrays in movement()
int i = 1, j = 1;

int rowFood, colFood;
char food[gridX][gridY];

void foodFunction(){
    srand(time(NULL));

    int minFood = 1, maxFood = 10;
    int foodInBoard = rand() % (maxFood - minFood + 1) + minFood;

    int iFood = 0;

    while(iFood < foodInBoard){  //<-- Keeps printing until it reaches random "max" food
        rowFood = rand() % (13 - 1 + 1) + 1;
        colFood = rand() % (13 - 1 + 1) + 1;

        /*
            rowFood & colFood can give the same number multiple times, meaning multiple
            food can be printed in the same coordinate.

            Code below checks if food is printed in a coordinate, to avoid multiple food
        */ 
        if(food[rowFood][colFood] != 'F' && !(rowFood == 1 && colFood == 1)){
            food[rowFood][colFood] = 'F';  //<-- Prints the food but will not print at (1, 1)
            iFood++;
        }
    }
}


void movement(char move){
    int k, l;

    char snake[gridX][gridY];

    switch(move){
        case 'd':
            j++;
            break;
        
        case 'w':
            i--;
            break;
            
        case 'a':
            j--;
            break;

        case 's':
            i++;
            break;
        default:
            break;
    }

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
}


int main(){

    int row, col;
    char grid[gridX][gridY];

    foodFunction();
    //Decides which X and Y will have borders
    for(row = 0; row<gridX; row++){
        for(col = 0; col<gridY; col++){
            if(row == 0 || row == gridX - 1 || col == 0 || col == gridY - 1){
                grid[row][col] = '#';
            }
            else if(row == 1 && col == 1){
                grid[row][col] = '@';       //<-- Prints the head
            }
            else if(food[row][col]=='F'){
                grid[row][col] = 'F';
            }
            else{
                grid[row][col] = ' ';
            }
        }
    }

    //Prints the borders
    for(row = 0; row < gridX; row++){
        for(col = 0; col < gridY; col++){
            printf("%c  ", grid[row][col]);
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