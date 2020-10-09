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
using namespace std;

//setters
void DebetCard::SetMonth(string mont) { month = mont; }
void DebetCard::SetYear(int yea) { year = yea; }
void DebetCard::SetCardID(string ID) { cardID = ID; }
void DebetCard::SetCurrency(string cur) { currency = cur; }
void DebetCard::SetBalance(double bal) { balance = bal; }
//getters
string DebetCard::GetMonth() { return month; }
int DebetCard::GetYear() { return year; }
string DebetCard::GetCardID() { return cardID; }
string DebetCard::GetCurrency() { return currency; }
double DebetCard::GetBalance() { return balance; }
//methods
void DebetCard::rechargebalance(double bal) { balance += bal; }
void DebetCard::decreaseBalance(double cost) { if ((balance - cost) > 0)balance -= cost; else { cout << "\nTransaction DENIED - issuficient balance"<<endl; } }
void DebetCard::showBalance() { cout << "\nThe balance of card No " << cardID << " is " << balance << " " << currency << endl; }
void DebetCard:: Initial(string mont, int yea, string ID, string cur)
{
	month = mont;
	year = yea;
	type = "Debet";
	cardID = ID;
	currency = cur;
}