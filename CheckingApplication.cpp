/*CheckingApplication.cpp
Name:			Nathaniel Wilcox
Email:			nwilcox2015@my.fit.edu
Date:			04/24/2020
Project:		Checking Account
Description:	Simulates monthly withdrawal of a checking account over 5 months
Algorithm:
  - Create two checking accounts
    - Account 1: $500.00
    - Account 2: $725.00
  - Loop that withdraws 10% for 5 iterations
    - for(int i = 0; i < 5; i++){
        withdraw acc * 0.1;
      }
  - Display account information to shell
*/

#include "CheckingAccount.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>


using namespace std;

int main()
{
    //Variable Initialization and Class call from header file
    string fN, lN;
    double money1 = 500.00;
    double money2 = 725.00;

    //Obtains Names of account holders from user, then builds the objects
    cout << "Enter the First name of the first account holder: ";
    cin >> fN;
    cout << "Last name of first account holder: ";
    cin >> lN;
    CheckingAccount CheckingAcc1(500.00, 0.10, fN, lN);

    cout << "Enter the First name of the second account holder: ";
    cin >> fN;
    cout << "Last name of second account holder: ";
    cin >> lN;
    CheckingAccount CheckingAcc2(725.00, 0.10, fN, lN);


    //Print original account values to shell
    cout << "Account 1 Original Balance: $" << money1 << endl;
    cout << "Account 1 owner: " << CheckingAcc1.getFirstName() + " " + CheckingAcc1.getLastName() << endl;
    cout << "Account 2 Original Balance: $" << money2 << endl;
    cout << "Account 1 owner: " << CheckingAcc2.getFirstName() + " " + CheckingAcc2.getLastName() << endl;

    //For loop that runs 5 times and withdraws 10% of Checking Accounts each time
    for (int i = 0; i < 5; i++) {
        //Takes Account balance, and withdraws 10%
        cout << "Withdrawing: $" << CheckingAcc1.getBalance() * CheckingAcc1.getPercentage() << " from Account 1" << endl;
        money1 = money1 - (CheckingAcc1.getBalance() * CheckingAcc1.getPercentage());
        CheckingAcc1.setBalance(money1);

        //Takes Account balance, and withdraws 10%
        cout << "Withdrawing: $" << CheckingAcc2.getBalance() * CheckingAcc1.getPercentage() << " from Account 2" << endl;
        money2 = money2 - (CheckingAcc2.getBalance() * CheckingAcc1.getPercentage());
        CheckingAcc2.setBalance(money2);

        //Prints out account ballance per iteration
        cout << "Account 1: $" << money1 << endl;
        cout << "Account 2: $" << money2 << endl;
    }

    //Print final values to shell
    cout << "The final account balances are as follows:" << endl;
    cout << CheckingAcc1.getFirstName() + " " + CheckingAcc1.getLastName() << "has $" << money1 << endl;
    cout << CheckingAcc2.getFirstName() + " " + CheckingAcc2.getLastName() << "has $" << money2 << endl;
    //Prints percentage being withdrawn every time
    cout << "The percentage of money being withdrawn every time from Account 1 was " << (CheckingAcc1.getPercentage() * 100) << "%" << endl;
    cout << "The percentage of money being withdrawn every time from Account 2 was " << (CheckingAcc2.getPercentage() * 100) << "%" << endl;

    cout << "Goodbye!";
    return 0;
}

