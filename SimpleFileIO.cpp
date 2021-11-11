/* SimpleFileIO.cpp
Name:			    Nathaniel Wilcox
Email:			  nwilcox2015@my.fit.edu
Date:		 	    03/27/2020
Project:		  Menu and Switch Statement
Description:	Allows the user to choose what function they wish to perform
Algorithm:
*Read number from Numbers.txt
*Output Heading to Table.txt
*while
**Add number to sum
**Output number and square root to output file
*exit from while loop
*Display sum to shell
*/

#include <stdio.h>                                                   //Library Headers
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
  double next, sum = 0;                                             //Variable declaration
  double root;
  int count = 0;

  ifstream inStream;                                                //Open input file
  inStream.open("Numbers.txt");
  if(inStream.fail()){                                              //Failure exit safety
    cout << "Input file opening failed.\n";
    exit(1);
  }

  ofstream outStream;                                              //Open output file
  outStream.open("Table.txt");
  if(outStream.fail()){                                           //Failure exit safety
    cout << "Output file opening failed.\n";
    exit(1);
  }

  outStream.setf(ios::fixed);                                     //Sets output format
  outStream.setf(ios::showpoint);
  outStream.precision(2);

  while(inStream >> next){                                        //Read through input file, prints number, square root and adds to sum
    sum +=next;
    cout << "Number: " << next << endl;
    root = sqrt(next);
    cout << "Root: " << root << endl;
    count++;
  }
  cout << endl;
  cout << "The sum of all the numbers is: " << sum;               //Prints sum of numbers to shell

}
