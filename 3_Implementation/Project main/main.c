

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include"ttc.h"
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';



int main()
{
   char winner = ' ';
   char response = ' ';

   do
   {
      winner = ' ';
      response = ' ';
      resetBoard();

      while(winner == ' ' && checkFreeSpaces() != 0)
      {
         printBoard();

         playerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }

         computerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }

      printBoard();
      printWinner(winner);

      printf("\nWould you like to play again? (Y/N): ");
      //scanf("%c");
      scanf("%c", &response);
      response = toupper(response);
   } while (response == 'Y');

   printf("Thanks for playing!");

   return 0;
}

