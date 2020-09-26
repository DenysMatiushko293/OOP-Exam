#pragma once
# define _CRT_SECURE_NO_WARNINGS
# include "iostream"
# include "string"
# include "algorithm"
# include "iterator"
# include "vector"
# include "Header.h"
# include "BankCard.h"
using namespace std;
class BankCard
{
protected:
	string cardID;
	string currency;
	double balance;
public:
	BankCard()
	{
		cardID = "AbstractCard";
		currency = "UAH";
		balance = 0;
	}
	BankCard(string iD)
	{
		cardID = iD;
		currency = "UAH";
		balance = 0;
	}
	BankCard(string iD, string cur)
	{
		cardID = iD;
		currency = cur;
		balance = 0;
	}
	BankCard(string iD, string cur, double bal)
	{
		cardID = iD;
		currency = cur;
		balance = bal;
	}

	~BankCard() {}
	//setters
	void SetID(string iD);
	void SetCurrency(string cur);
	void SetBalance(double bal);
	//getters
	string GetID();
	string GetCurrency();
	double GetBalance();
	//methods
	void rechargeBalance(double rec);
	void decreasebyCost(double cost);
};
