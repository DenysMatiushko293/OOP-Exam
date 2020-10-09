#pragma once
# define _CRT_SECURE_NO_WARNINGS
# include "iostream"
# include "ctime"
#include "cstring"
# include "vector"
# include "string"
# include "iterator"
# include "algorithm"
# include"Header.h"
using namespace std;

class AbstractCard
{
protected:
	string type;
	string cardID;
	string currency;
	double balance;
	string month;
	int year;
public:
	//setters
	AbstractCard() {}
	virtual ~AbstractCard() {}
	void SetMonth(string mont) { month = mont; }
	void SetYear(int yea) { year = yea; }
	void SetCardID(string ID) { cardID = ID; }
	void SetCurrency(string cur) { currency = cur; }
	void SetBalance(double bal) { balance = bal; }
	//getters
	string GetMonth() { return month; }
	int GetYear() { return year; }
	string GetType() { return type; }
	string GetCardID() { return cardID; }
	string GetCurrency() { return currency; }
	double GetBalance() { return balance; }
	
	void rechargeBalance() {}
	void decreaseBalance() {}
	virtual void showBalance() = 0;
	
};
