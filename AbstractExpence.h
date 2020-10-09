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
using namespace std;

class AbstractExpence
{
protected:
	string category;
	string name;
	double price;
	string unit;
	double quantity;
	double total;
	public:
		double totalCost() {}
		void ShowExpence() {}
	virtual void Initial(char* nam, double prc, char* unt, double quan, double tot) { name.append(nam); price = prc; unit.append(unt); quantity = quan; total = tot; }
	~AbstractExpence() {}
};
