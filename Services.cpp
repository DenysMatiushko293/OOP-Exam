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
# include "AbstractExpence.h"
# include "Grocceries.h"
# include "Houseware.h"
# include "Services.h"
using namespace std;

//setters
void Services::SetName(string nam) { name = nam; }
void Services::SetName(char *nam) { name.append(nam); }
void Services::SetPrice(double prc) { price = prc; }
void Services::SetUnit(string unt) { unit = unt; }
void Services::SetCurrency(string cur) { currency = cur; }
void Services::SetUnit(char *unt) { unit.append(unt); }
void Services::SetQuantity(double quan) { quantity = quan; }
//getters
string Services::GetCategory() { return category; }
string Services::GetName() { return name; }
double Services::GetPrice() { return price; }
string Services::GetUnit() { return unit; }
double Services::GetQuantity() { return quantity; }
string Services::GetCurrency() { return currency; }
double Services::GetTotal() { return total; }
//method
double Services::totalCost() { double costTotal = price * quantity; return costTotal; }
void Services::ShowExpence() { cout << "\nThe groccery named: " << name << " with price " << price << " " << currency << " per " << unit << " with total quantity " << quantity << " " << unit << "." << endl; }
void Services::Initial(string nam, double prc, string unt, double quan) { name = nam; price = prc; unit = unt; quantity = quan; total = price * quantity;}
void Services::Initial(char* nam, double prc, char* unt, double quan) {  name.append(nam); price = prc; unit.append(unt); quantity = quan; total = price * quantity;}