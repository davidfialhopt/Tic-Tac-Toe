#include "functions.h"
#include <stdio.h>
#include <stdbool.h>

const char PLAYER = 'X';
const char COMPUTER = 'Y';
char board [3][3];





void printboard()
{
     printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
     printf("_____|_____|______\n");
     printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
     printf("_____|_____|______\n");
     printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
     printf("     |     |    \n");
     printf("\n");

}

void resetboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

bool clear()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return true;
            }
          
        }
    }
    return false;
}

char play()
{
    int x;
    int y;
    
       do
       {
       printf("Type Row Number [1-3]:  ");
       scanf("%i", &x);
       }while(x != 1 && x != 2 && x != 3);

       do
       {
       printf("Type Column Number [1-3]:  ");
       scanf("%i", &y);
       }while(y != 1 && y != 2 && y != 3);
       

      if (board[x - 1][y - 1] == ' ') 
        board[x - 1][y - 1] = PLAYER;  
    
    else
    {
        printf("Space is already occupied! Choose an open space.\n");
        return play();  
    }

    return PLAYER; 
}
bool winner()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == board[i][j + 1] == board[i][j + 2])
            {
                printf("%c IS THE WINNER!\n", board[i][j]);
                return true;
            }
            else if (board[i][j] == board[i + 1][j] == board[i + 2][j])
            {
                printf("%c IS THE WINNER!\n", board[i][j]);
                return true;
            }
            else if ((board[i][j] == board[i + 1][j + 1] == board[i + 2][j + 2]) || (board[i][j + 2] == board[i + 1][j + 1] == board[i + 2][j]))
            {
                printf("%c IS THE WINNER!\n", board[i][j]);
                return true;

            }
        }
    }
    return false;


}


