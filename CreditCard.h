#pragma once
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

class CreditCard :public AbstractCard
{
private:
	double creditLimit;
public:
	CreditCard()
	{
		month = "noWay";
		year = 2222;
		type = "Credit";
		cardID = "Debet card 16 digit ID";
		currency = "UAH";
		balance = 0;
	}
	~CreditCard() {}
	//setters
	void SetMonth(string mont);
	void SetYear(int yea);
	void SetCardID(string ID);
	void SetCurrency(string cur);
	void SetBalance(double bal);
	void SetCreditLimit(double lim);
	//getters
	string GetMonth();
	int GetYear();
	string GetType() { return type; }
	string GetCardID();
	string GetCurrency();
	double GetBalance();
	double GetCreditLimit();
	//methods
	void rechargebalance(double bal);
	void decreaseBalance(double cost);
	void showBalance();
	void Initial(string mont, int yea, string ID, string cur, double lim);
};
