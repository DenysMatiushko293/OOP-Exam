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
using namespace std;

//setters
void Houseware::SetName(string nam) { name = nam; }
void Houseware::SetName(char *nam) { name.append(nam); }
void Houseware::SetPrice(double prc) { price = prc; }
void Houseware::SetUnit(string unt) { unit = unt; }
void Houseware::SetCurrency(string cur) { currency = cur; }
void Houseware::SetUnit(char *unt) { unit.append(unt); }
void Houseware::SetQuantity(double quan) { quantity = quan; }
//getters
string Houseware::GetCategory() { return category; }
string Houseware::GetName() { return name; }
double Houseware::GetPrice() { return price; }
string Houseware::GetUnit() { return unit; }
double Houseware::GetQuantity() { return quantity; }
string Houseware::GetCurrency() { return currency; }
double Houseware::GetTotal() { return total; }
//method
double Houseware::totalCost() { double costTotal = price * quantity; return costTotal; }
void Houseware::ShowExpence() { cout << "\nThe groccery named: " << name << " with price " << price << " " << currency << " per " << unit << " with total quantity " << quantity << " " << unit << "." << endl; }
void Houseware::Initial(string nam, double prc, string unt, double quan) { name = nam; price = prc; unit = unt; quantity = quan; total = price * quantity;}
void Houseware::Initial(char* nam, double prc, char* unt, double quan) { name.append(nam); price = prc; unit.append(unt); quantity = quan; total = price * quantity; }