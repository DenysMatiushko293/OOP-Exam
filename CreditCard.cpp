# define _CRT_SECURE_NO_WARNINGS
# include "iostream"
# include "ctime"
#include "cstring"
# include "vector"
# include "iterator"
# include "algorithm"
# include "string"
# include"Header.h"
# include "AbstractCard.h"
# include "DebetCard.h"
# include "CreditCard.h"
using namespace std;

//setters
void CreditCard::SetMonth(string mont) { month = mont; }
void CreditCard::SetYear(int yea) { year = yea; }
void CreditCard::SetCardID(string ID) { cardID = ID; }
void CreditCard::SetCurrency(string cur) { currency = cur; }
void CreditCard::SetBalance(double bal) { balance = bal; }
void CreditCard::SetCreditLimit(double lim) { creditLimit = lim; }
//getters
string CreditCard::GetMonth() { return month; }
int CreditCard::GetYear() { return year; }
string CreditCard::GetCardID() { return cardID; }
string CreditCard::GetCurrency() { return currency; }
double CreditCard::GetBalance() { return balance; }
double CreditCard::GetCreditLimit() { return creditLimit; }
//methods
void CreditCard::rechargebalance(double bal) { balance += bal; }
void CreditCard::decreaseBalance(double cost) { if ((balance - cost) > 0)balance -= cost; else { cout << "\nTransaction DENIED - issuficient balance" << endl; } }
void CreditCard::showBalance() { cout << "\nThe available balance of credit card No " << cardID << " is " << balance << " " << currency << endl; }
void CreditCard::Initial(string mont, int yea, string ID, string cur, double lim)
{
	month = mont;
	year = yea;
	type = "Credit";
	cardID = ID;
	currency = cur;
	creditLimit = lim;
}