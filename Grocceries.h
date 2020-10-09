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
# include "CreditCard.h"
# include "AbstractExpence.h"
using namespace std;

class Grocceries :public AbstractExpence
{
protected:
	string currency;
public:
	Grocceries()
	{
		category = "Grocceries";
		name = "Abstract groccery";
		price = 0;
		currency = "UAH";
		unit = "measurement unit";
		quantity = 0;
		total = price * quantity;
	}
	~Grocceries() {}
	//setters
	void SetName(string nam);
	void SetName(char *nam);
	void SetPrice(double prc);
	void SetCurrency(string cur);
	void SetUnit(string unt);
	void SetUnit(char *unt);
	void SetQuantity(double quan);
	//getters
	string GetCategory();
	string GetName();
	double GetPrice();
	string GetCurrency();
	string GetUnit();
	double GetQuantity();
	double GetTotal();
	//method
	double totalCost();
	void ShowExpence();
	void Initial(string nam, double prc, string unt, double quan);
	void Initial(char* nam, double prc, char* unt, double quan);
};
