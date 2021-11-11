/* Assignment2.cpp
Name:			Nathaniel Wilcox
Email:			nwilcox2015@my.fit.edu
Date:			03/24/2020
Project:		Menu and Switch Statement
Description:	Allows the user to choose what function they wish to perform
Algorithm:
* Print main menu out to shell
* Ask user for their Choice(switch statement)
* Based on user input call to cooresponding Function
* Return result to shell
*/
#include <stdio.h>                                                                //Library headers
#include <cmath>
#include <iostream>
using namespace std;

double sqrt();                                                                    //Function declarations
double pow();
double cbrt();
double hypot();



int main() {

    int pc;
    double res;
    do {                                                                          //Main menu for user ease of understanding
        cout << "1) Process Square Root Funtion" << endl;
        cout << "2) Process Power Funciton" << endl;
        cout << "3) Process Cude Root Funcion" << endl;
        cout << "4) Process Hypotenuse Function" << endl;
        cout << "5) Quit" << endl;
        cout << "Select a Choice (Please input number for choice): ";
        cin >> pc;                                                                //User input

        switch (pc) {                                                             //Switch statement to go off of user input
        case 1:
            sqrt();                                                               //Calls square root function
            cout << endl << endl;
            break;
        case 2:
            pow();                                                                //Calls power function
            cout << endl << endl;
            break;
        case 3:
            cbrt();                                                               //Calls cube root function
            cout << endl << endl;
            break;
        case 4:
            hypot();                                                              //Calls hypotenuse function
            cout << endl << endl;
            break;
        default:
            cout << "Thank you, have a nice day!" << endl;
            break;
        }
    } while (pc != 5);
}

                                                                                  //Functions to be called in main
double sqrt() {
    double num, result;
    cout << "Enter a number to square root: ";
    cin >> num;
    result = sqrt(num);
    cout << "Square Root of " << num << " is = " << result;
    return result;
}
double pow() {
    int num, exp;
    double result;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the power of that number: ";
    cin >> exp;
    result = pow(num, exp);
    cout << num << " ^ " << exp << " = " << result;
    return result;
}
double cbrt() {
    double num, result;
    cout << "Enter a number to cube root: ";
    cin >> num;
    result = cbrt(num);
    cout << "The Cubic Root of " << num << " is " << result;
    return result;
}
double hypot() {
    double x_side, y_side;
    double result;
    cout << "Enter one side length: ";
    cin >> x_side;
    cout << "Enter the length of the other side: ";
    cin >> y_side;
    result = hypot(x_side, y_side);
    cout << "The hypotenuse of " << x_side << " and " << y_side << " is " << result;
    return result;
}
