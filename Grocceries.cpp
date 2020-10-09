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
using namespace std;

//setters
void Grocceries::SetName(string nam) { name = nam; }
void Grocceries::SetName(char *nam) { name.append(nam); }
void Grocceries::SetPrice(double prc) { price = prc; }
void Grocceries::SetUnit(string unt) { unit = unt; }
void Grocceries::SetCurrency(string cur) { currency=cur; }
void Grocceries::SetUnit(char *unt) { unit.append(unt); }
void Grocceries::SetQuantity(double quan) { quantity = quan; }
//getters
string Grocceries::GetCategory() { return category; }
string Grocceries::GetName() { return name; }
double Grocceries::GetPrice() { return price; }
string Grocceries::GetUnit() { return unit; }
double Grocceries::GetQuantity() { return quantity; }
string Grocceries::GetCurrency() { return currency; }
double Grocceries::GetTotal() { return total; }
//method
double Grocceries::totalCost() { double costTotal = price * quantity; return costTotal; }
void Grocceries::ShowExpence() { cout <<"\n\tThe groccery named: "<<name<<" with price "<<price<<" "<<currency<<" per "<<unit<<" with total quantity "<<quantity<<" "<<unit<<"."<<endl; }
void Grocceries::Initial(string nam, double prc, string unt, double quan) { name = nam; price = prc; unit = unt; quantity = quan; total = price * quantity; }
void Grocceries::Initial( char* nam, double prc, char* unt, double quan) { name.append(nam); price = prc; unit.append(unt); quantity = quan; total = price * quantity;
}