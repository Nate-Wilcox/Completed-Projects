/*
Name:			Nathaniel Wilcox

Date:			February 23, 2020

Project:		Doggie Day Care

Description:	Providing pricing on a doggie daycare

Algorithm:
* Find out how many dogs will be input
* collect information from user regarding themselves and each dog
* calculate the weekly cost
* Then print to the screen all information entered and the cost accordingly
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{																		//Initializing variables
    int userChoice;
    int dogCount;
    cout << "How many dogs are you inputting? ";
    cin >> dogCount;
    string ownerName[dogCount];
    string dogName[dogCount];
    string dogBreed[dogCount];
    int ownerID[dogCount];
    int dogAge[dogCount];
    int dogWgt[dogCount];
    int price = 0;
    int count = 0;
    int i;

    cout << "Enter all the information asked" << endl;
    cout << "Would you like to begin?(0 for yes, -1 to exit) ";
    cin >> userChoice;
																		//begin loop asking for information
    do{
        float cost = 0;
        if (userChoice == 0){
          for(i = 0;i < dogCount;i++){
            cout << "ID number: ";
            cin >> ownerID[i];
            cout << "Owner's name: ";
            cin >> ownerName[i];
            cout << "Dog's name: ";
            cin >> dogName[i];
            cout << "Dog breed: ";
            cin >> dogBreed[i];
            cout << "Dog's age: ";
            cin >> dogAge[i];
            cout << "Dog's weight: ";
            cin >> dogWgt[i];
            count++;
          }																//Add cost each loop
              if (dogWgt[i] <= 15){
              cost = cost + 55;
              } else if (dogWgt[i] <= 30){
                  cost = cost + 75;
              } else if (dogWgt[i] <= 80){
                  cost = cost + 105;
              } else {
                  cost = cost + 125;
              }
          if(count == dogCount){
            cout << "Total daycare entries: " << count << " and total weekly cost wil be: $" << cost << endl;
            for(int k = 0; k < dogCount;k++){
              if (dogWgt[k] <= 15){
                price = price + 55;
              } else if (dogWgt[k] <= 30 && dogWgt[k] > 15){
                  price = price + 75;
              } else if (dogWgt[k] <= 80 && dogWgt[k] > 30){
                  price = price + 105;
              } else{
                  price = price + 125;
              }
              cout << "Owner ID:" << ownerID[k] << endl;
              cout << "Owner Name:" << ownerName[k] << endl;
              cout << "Dog Name:" << dogName[k] << endl;
              cout << "Dog Breed:" << dogBreed[k] << endl;
              cout << "Dog Age:" << dogAge[k] << endl;
              cout << "Dog Weight:" << dogWgt[k] << endl;
              cout << "Price for service:" << price << endl;
            }
            userChoice = -1;
          }
        } else if (userChoice == -1 ){
            cout << "Thank you for coming in!";
            break;
        } else{
            cout << "invalid input, please enter 0 to continue or -1 to exit" << endl;
            cout << "Would you like to continue?(0 for yes, -1 to exit) ";
            cin >> userChoice;
        }
        if (dogWgt[i] <= 15){
        cost += 55;
        } else if (dogWgt[i] <= 30){
            cost += 75;
        } else if (dogWgt[i] <= 80){
            cost += 105;
        } else {
            cost += 125;
        }
    }while (count < dogCount);
  }
