/*
* Author: Nathaniel Wilcox, nwilcox2015@my.fit.edu
* Course: CSE 1001, Section E2 Fall 2019
* Filename: war.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *T_deck, int n);
int check_hand(int index1,int index2);
int deal_hand(int *T_deck, int *p1_hand, int *p2_hand, int index1, int index2);
void battle(int *p1_hand, int *p2_hand, int index1, int index2);

int main(void){
	
	//Variable initialization
	int T_deck[52];	
	int p1_hand[52];
	int p2_hand[52];
	int index1 = 0;
	int index2 = 0;
	int d_deck[52];
	int n = 52;
	char pchoice;
	
	printf("Welcome to War! \nShuffling deck... \nDealing cards...\n");
	
	//Fill deck with values to prepare for card values
    for(int i = 0; i < 52; i++){
    T_deck[i] = i;
    d_deck[i] = 0;
    }
    
	//Function to shuffle cards in total deck
	shuffle(&T_deck[0], n);
	deal_hand( &T_deck[0], &p1_hand[0], &p2_hand[0], index1, index2);

	while(index1 < 52 || index2 < 5){

    //Prompt for user to start the round or exit the game
    printf("\nWould you like to play(p) or exit(e):%c", pchoice);
    scanf("%c", &pchoice);

      if(pchoice == 'p'){
        
    
        //Display the player's top deck card value for visual comparison
		
        printf("Player 1's card is: %d\n", (p1_hand[0]%13)+2);
        printf("Player 2's card is: %d\n", (p2_hand[0]%13)+2);
        
        //Conditional statements that move cards won into winner's deck
        if(p1_hand[0]%13 > p2_hand[0]%13){
          printf("Player 1 wins this round! Awarding cards to Player 1...\n");
          p1_hand[51] = p1_hand[0];
          index1 = index1 + 1;
          p1_hand[51] = p2_hand[0];
          index1 = index1 + 1;
			
		//Increments entire array down 1
          for(int i = 0; i < 51; i++){
            p1_hand[i] = p1_hand[i+1];
            p2_hand[i] = p2_hand[i+1];
          }
          index1 = index1 + 1;
          index2 = index2 - 1;
          p1_hand[51] = -1;
          p2_hand[51] = -1;
        }else if(p1_hand[0]%13 < p2_hand[0]%13){
          printf("Player 2 wins this round! Awarding cards to Player 2...\n");
          p2_hand[51] = p1_hand[0];
          index2 = index2 + 1;
          p2_hand[51] = p2_hand[0];
          index2 = index2 + 1;

          for(int i = 0; i < 51; i++){
            p1_hand[i] = p1_hand[i+1];
            p2_hand[i] = p2_hand[i+1];
          }

          index1 = index1 - 1;
          index2 = index2 + 1;
          p1_hand[51] = -1;
          p2_hand[51] = -1;
        }else if(p1_hand[0]%13 == p2_hand[0]%13){

          printf("It's a battle, War!\n");
          
          battle(p1_hand, p2_hand, index1, index2);
          check_hand(index1, index2);
        }else{
			//catch all conditional
          printf("error");
        }
        
      }else if(pchoice == 'e'){
          
          //Checks how many cards are in each player's deck to determine if there is a winner
          check_hand(index1, index2);
          printf("Goodbye! Thank you for playing War!");
          break;
        }
   }


}

//functions to be called in main

//shuffles deck values
void shuffle(int *T_deck, int n){
    srand((unsigned) time(NULL));
    if (n > 1) {
        int i, k, t;
        for (i = 0; i < (n - 1); i++) {
            k = i + rand() / (RAND_MAX / (n - i) + 1);
            t = T_deck[k];
            T_deck[k] = T_deck[i];
            T_deck[i] = t;
        }
    }
}

//determines winner based on empty space in hand
int check_hand(int index1,int index2){

  if (index1 == 52){
      printf("Player 2 wins!\n");
  }else if(index2 == 52){
      printf("Player 1 wins!\n");
  } else{
      printf("This game is a tie!\n");
  }
  return 0;
}

//puts shuffled values of total deck into each player's hand(26 each)	
int deal_hand(int *T_deck, int *p1_hand, int *p2_hand, int index1, int index2){

  for(int a = 0; a < 52; a++){
      p1_hand[a] = -1;
      p2_hand[a] = -1;
  }
    
	for(int i = 0; i <= 25; i++){
		p1_hand[i] = T_deck[i];
		index1++;
	}
	
	for(int t = 26; t <=52; t++){
		p2_hand[t-26] = T_deck[t];
		index2++;
	}

  return 0;
}

//loop for battle, only called if card values match
void battle(int *p1_hand, int *p2_hand, int index1, int index2){

    int d_deck[6];
    
    for(int i=0; i < 3; i++){
        d_deck[i] = p1_hand[i];
        index1++;
    }

    for(int i = 3; i < 6; i++){
        d_deck[i] = p2_hand[i];
        index2++;
    }
    
    if(p1_hand[4]%13 > p2_hand[4]%13){
		printf("Player 1 wins this round!");
		p1_hand[51] = p1_hand[0];
		index1++;
		p1_hand[51] = p2_hand[0];
		index1++;
        p1_hand[51] = d_deck[0];
        index1 = index1 + 6;

		for(int i = 0; i < 52; i++){
			p1_hand[i] = p1_hand[i+1];
			p2_hand[i] = p2_hand[i+1];
			//Puts the cards from the down deck into the player's hand
           for(int r = 0; r < 6; r++){
                p1_hand[index1] = d_deck[r];
                index1++;
                index2--;
            }
		}

		p1_hand[51] = -1;
		p2_hand[51] = -1;
	}else if(p1_hand[4]%13 < p2_hand[4]%13){
		printf("Player 2 wins this round!");
		p2_hand[51] = p1_hand[0];
		index2++;
		p2_hand[51] = p2_hand[0];
		index2++;
        p1_hand[51] = d_deck[0];
        index1 = index1 + 6;

		for(int i = 0; i < 52; i++){
			p1_hand[i] = p1_hand[i+1];
			p2_hand[i] = p2_hand[i+1];
            for(int r = 0; r < 6; r++){
                p2_hand[index2] = d_deck[r];
                index2++;
                index1--;
                }
		}

		p1_hand[51] = -1;
		p2_hand[51] = -1;
	}else{
	    printf("error");
	}
}
