/*
* Author: Nathaniel Wilcox, nwilcox2015@my.fit.edu
* Course: CSE 1001, Section E2 Fall 2019
* Filename: memory.c
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_board(char board[][4], char c_inplay[9], char clear_board[][4]);
void fill_board(char board[][4],char *c_inplay, char *alpha);
void check_value(int coord1, int coord2, char board[][4], int points, char clear_board[][4], char c_inplay[9], int x1, int y1, int x2, int y2);


int main(void)
{
                      //Setting main variables or variable to be called later
  char pc;
  char board[4][4];
  char c_inplay[9];
  char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char clear_board[4][4] = {{'$','$','$','$'},
  {'$','$','$','$'},
  {'$','$','$','$'},
  {'$','$','$','$'}};

  
  printf("Welcome to the Memory Game!\n");
  
  
  fill_board(board, c_inplay, alpha);
  print_board(board, c_inplay, clear_board);
  int points= 0;

  while(points < 8){

  printf("Choose an option.\n\n- (F)Find a match \n- Quit(Q)\n\nEnter your choice here: ");                  //Prompts user for response to either start game of exit program
  scanf(" %c", &pc);

    if(toupper(pc) =='F'){
      
      int x1;
      int y1;
      int x2;
      int y2;
      int coord1;
      int coord2;

      /*for(int a = 0; a < 8; a++){           //For testing purposes to see letters in use
        printf("%c ", c_inplay[a]);
      }
      printf("\n");*/

    /*printf("  0 1 2 3\n");                  //For testing purposes to see the numbers in use for board
    for(int row = 0; row < 4; row++){
        printf("%d|", row);
        for(int col = 0; col < 4; col++){
          printf("%d|", board[row][col]);
        }
      printf("\n");
    }
    printf("\n");*/
      
      printf("Pick first card(row, column): ");
      scanf("%d, %d", &x1, &y1);
      printf("\n");
      
      printf("Choose another card(row, column): ");
      scanf("%d, %d", &x2, &y2);
      printf("\n");

      coord1 = board[x1][y1];
      coord2 = board[x2][y2];

      printf("Line 64: You picked (%d , %d)\n", coord1, coord2);

      check_value(coord1, coord2, board, points, clear_board, c_inplay, x1, y1, x2, y2);
      if(coord1 == coord2){
        points++;
      }else if(coord1 != coord2){
        printf("You gained 0 points.\n");
      }
    }else if(toupper(pc) == 'Q'){
      printf("You have a total of %d points.\n", points);
      printf("Godbye, thank you for playing my memory game!");
      break;    
    }
  }if(points == 8){
    printf("Congratulations, you win!");
    printf("Your total points: %d", points);
  }
}

void fill_board(char board[][4], char c_inplay[9], char *alpha)                   //Function used to fill board with numbers(8 letters placed twice)
{
  srand(time (0));
  int iteration[] = {2,2,2,2,2,2,2,2};

  for(int row = 0; row < 4; row++){
      for(int col = 0; col < 4; col++){
        int flag = 1;
        do{
          int num = rand() % 8;
          if(iteration[num] > 0){
            board[row][col] = num;
            iteration[num] -= 1;
            flag = 0;
          }
        }while(flag == 1);
      }
    printf("\n");
  }
  printf("\n");

  int count = 0;
  char NL;
  while(count < 8){
    int flag = 0;
    NL = alpha[rand() % 26];
    for(int i = 0; i < count; i++){
      if(NL == c_inplay[i]){
        flag = 1;
      }
    }
    if(flag == 0){
      c_inplay[count] = NL;
      count++;
    }
  }
}

void print_board(char board[][4], char c_inplay[9], char clear_board[][4])                   //Prints board with card backs to the screen
{
  printf("  0 1 2 3\n");
  for(int row = 0; row < 4; row++){
    printf("%d|", row);
    for(int col = 0; col < 4; col++){
      printf("%c|", clear_board[row][col]);
      }
    printf("\n");
  }
  printf("\n");
}

void check_value(int coord1, int coord2, char board[][4], int points, char clear_board[][4], char c_inplay[9], int x1, int y1, int x2, int y2)                   //Function that compares the user input values with the 2d array and then flips the cards to show if correct or incorrect
{
  coord1 = board[x1][y1];
  coord2 = board[x2][y2];
  int row, col;

  if(coord1 == coord2){                           //conditional statement if the player chose the correct set of coordinates
    printf("Thats a match! \n");
    points += 1;
    printf("You now have %d points\n", points);
    
    
    clear_board[x1][y1] = c_inplay[coord1];         //Flips the cards and prints the updated board to the screen
    clear_board[x2][y2] = c_inplay[coord2];

    printf("  0 1 2 3\n");
    for(row = 0; row < 4; row++){
        printf("%d|", row);
        for(col = 0; col < 4; col++){
          printf("%c|", clear_board[row][col]);
        }
      printf("\n");
    }
    printf("\n");

  }else if(coord1 != coord2){                     //conditional statement if the player chooses the incorrect set of coordinates
    printf("The cards do not match! Tray again!\n");

                                        //Flips the cards to show the player which cards they chose and then flips them back to the previous board
    clear_board[x1][y1] = c_inplay[coord1];
    clear_board[x2][y2] = c_inplay[coord2];

    printf("  0 1 2 3\n");
    for(int row = 0; row < 4; row++){
        printf("%d|", row);
        for(int col = 0; col < 4; col++){
          printf("%c|", clear_board[row][col]);
        }
      printf("\n");
    }
    printf("\n");

    clear_board[x1][y1] = '$';
    clear_board[x2][y2] = '$';



  }else{
    printf("Not within bounds, try again!");
  }
}