/* Assignment4.cpp
Name:			    Nathaniel Wilcox
Email:			  nwilcox2015@my.fit.edu
Date:			    03/26/2020
Project:		  Calculating Wages
Description:	Uses file input to read employee information into program and sorts based on wages
Algorithm:
*Read input file
* Store information into 2d array
* Send wage information into separate variable
* Use following logic for calculating wages:
** If Hours Worked <= 40
**  Wage = Pay Rate * Hours Worked
** Else
**  Wage = Pay Rate*40 +((Hours Worked - 40)* Pay Rate * 1.5)
* Display sorted by wage list of employees
* Display total wages
*/
//Library Headers
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple <string, string, int, float, int, float> employee;


int main() {
    //variable initialization
    vector<employee> data;
    string firstName[10], lastName[10], name[100];
    int employeeID, j = 0;
    float wage, payRate, hoursWorked;
    char c;
    //Open file to be used
    ifstream myFile;
    myFile.open("Assignment4.txt");
    //Check if file was successfully opened
    if (myFile.is_open()) {
        cout << "File opened successfully, proceeding with program." << endl;
    }

    //Count lines to figure out how many tuples will need to be created by reading through file
    while (myFile.get(c)) {
        if (c == '\n') {
            j++;
        }
    }
    string line;

    do {
        //read each field of file, use getLine method, using ':' as delimiter, last field must use '\n' as delimiter
        getline(myFile, line);
        string delimiter = "\n";
        make_tuple(firstName, lastName, employeeID, payRate, hoursWorked);
    } while (myFile.eof());

    sort(data.begin(), data.end());

    //Print vectors to shell
    for (vector<employee>::iterator iter = data.begin(); iter != data.end(); iter++) {
        cout << "Name: " << get<0>(*iter);
        cout << "Employee ID: " << get<1>(*iter);
        cout << "Pay rate: $" << get<2>(*iter);
        //Calculate wage based on logic provided in algorithm
        if (get<2>(*iter) <= 40) {
            wage = payRate * 40;
        }
        else {
            wage = (payRate * 40 + ((hoursWorked)-40) * (payRate * 1.5));
        }
        //Print out final wage
        cout << "Wage: " << get<4>(*iter);
        //Close file
        myFile.close();
        return 0;
    }
}
