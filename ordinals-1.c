/*

* Author: Nathaniel Wilcox, nwilcox2015@my.fit.edu

* Course: CSE 1001, Section E2 Fall 2019

* Project: ordinal.c

*/


#include <stdio.h>
#include<math.h>

int main(void) {

	int unum;
	int ord;
	int sum = 0;		//initializing variables needed//


	do
	{
		printf("Enter a value between 0 and 65535(negative to quit):");	//User input//
		scanf("%d", &unum);



			if (ord == 1){	//Handles ordinals//

				printf("%dst Value: %d\n", ord, unum);

			} else if (ord == 2){

				printf("%dnd Value: %d\n", ord, unum);

			} else if (ord == 3){

				printf("%drd Value: %d\n", ord, unum);

			} else if (4 >= ord && ord <= 19){

				printf("%dth Value: %d\n", ord, unum);

			}else if (ord == 21){

				printf("%dst Value: %d\n", ord, unum);

			} else if (ord == 22){

				printf("%dnd Value: %d\n", ord, unum);

			} else if (ord == 23){

				printf("%drd Value: %d\n", ord, unum);

			} else if{

				printf("%dth Value: %d\n", ord, unum);
				
			}	else{
				
				printf("The value you entered does not work, please try again.");
				
			}
			sum = sum + unum;

		ord++;
		
	}while(unum > 0);	//sentinal vallue
	
	printf("The sum of all the numbers entered is: %d\n", sum-unum);

return 0;
}