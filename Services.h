#pragma once
# include "iostream"
# include "ctime"
#include "cstring"
# include "vector"
# include "iterator"
# include "algorithm"
# include "string"
# include "Header.h"
# include "AbstractCard.h"
# include "DebetCard.h"
# include "CreditCard.h"
# include "AbstractExpence.h"
# include "Grocceries.h"
# include "Houseware.h"
using namespace std;

class Services : public AbstractExpence
{
protected:
	string currency;
public:
	Services()
	{
		category = "Services";
		name = "Abstract Services";
		price = 0;
		currency = "UAH";
		unit = "measurement unit";
		quantity = 0;
	}
	~Services() {}
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
