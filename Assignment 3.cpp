/* Assignment3.cpp
Name:			    Nathaniel Wilcox
Email:			  nwilcox2015@my.fit.edu
Date:			    03/26/2020
Project:		  Calculating Hypotenuse
Description:	Allows the user to choose what function they wish to perform
Algorithm:
* Take user input on whether they wish to start/continue the program
* If the user says yes:
** Have user enter both sides of the triangle
**Call the hypotenuse function to get length of third side
**Return hypotenuse to shell
*If user says no:
**Wish them a nice day and end the program
*/
#include <iostream>                                                                     //Library Headers
#include <cmath>
using namespace std;

void CalculateHypotenuse(int side1, int side2, double& hypotenuse);                     //Function declaration


int main() {
    int num1, num2;
    double num3;
    char pc;
    cout << "Enter a 'Y' or a'y' if you would like to proceed('N' or 'n' to cancel): ";//User input to start loop or exit
    cin >> pc;

    if (pc == 'y' || pc == 'Y') {
        cout << "Enter the first side of the triangle: ";                               //User inputs the two sides of a triangle
        cin >> num1;
        cout << "Enter the second side: ";
        cin >> num2;
        CalculateHypotenuse(num1, num2, num3);                                          //Function call
    }
    else if (pc == 'n' || pc == 'N') {
        cout << "Thank you, have a nice day!";                                          //Exit call
    }
    else {
        cout << "ERROR: invalid response" << endl << "Please restart the program";      //Default/Error log
    }

    return 0;
}

void CalculateHypotenuse(int side1, int side2, double& hypotenuse) {                    //Function to be called in main
    hypotenuse = hypot(side1, side2);
    cout << "Hypotenuse is = " << hypotenuse << endl;
    return;
}
