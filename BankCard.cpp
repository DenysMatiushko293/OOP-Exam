# define _CRT_SECURE_NO_WARNINGS
# include "iostream"
# include "string"
# include "algorithm"
# include "iterator"
# include "vector"
# include "Header.h"
# include "BankCard.h"
using namespace std;

//setters
void BankCard::SetID(string iD) { cardID = iD; }
void BankCard::SetCurrency(string cur) { currency = cur; }
void BankCard::SetBalance(double bal) { balance = bal; }
//getters
string BankCard::GetID() { return cardID; }
string BankCard::GetCurrency() { return currency; }
double BankCard::GetBalance() { return balance; }
//methods
void BankCard::rechargeBalance(double rec) { balance += rec; }
void BankCard::decreasebyCost(double cost) { balance -= cost; }
