#pragma once
//Header file defining the class object CheckingAccount
#include <string>

using namespace std;

class CheckingAccount
{
	//Public methods and variables
	public:
		CheckingAccount(double b, double p, string fN, string lN);
		double getBalance();
		void setBalance(double b);
		double getPercentage();
		void setPercentage(double p);
		string getFirstName();
		void setFirstName(string fN);
		string getLastName();
		void setLastName(string lN);

	//private variable
	private:
		double balance;
		double percentage;
		string fName;
		string lName;

};