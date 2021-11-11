#include <string>
#include "CheckingAccount.h"


using namespace std;
//File declaring class object CheckingAccount

//Constructor with parameters that initialize all instance variables
CheckingAccount::CheckingAccount(double b, double p, string fN, string lN)
{
	balance = b;
	percentage = p;
	fName = fN;
	lName = lN;
}
//Get and Set methods for each instance variable
double CheckingAccount::getBalance()
{
	return balance;
}

void CheckingAccount::setBalance(double b)
{
	balance = b;
}

double CheckingAccount::getPercentage()
{
	return percentage;
}

void CheckingAccount::setPercentage(double p)
{
	percentage = p;
}

string CheckingAccount::getFirstName()
{
	return fName;
}

void CheckingAccount::setFirstName(string fN)
{
	fName = fN;
}

string CheckingAccount::getLastName()
{
	return lName;
}

void CheckingAccount::setLastName(string lN)
{
	lName = lN;
}