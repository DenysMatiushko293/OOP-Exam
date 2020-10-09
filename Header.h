#pragma once
# include "iostream"
# include "locale"
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
# include "CardFactory.h"
# include "CreditFactory.h"
# include "ctime"
# include "fstream"
# include "DebetFactory.h"
# include "map"
using namespace std;

bool CardAvailCheck(vector<AbstractCard*>&CardList);
void ShowCardList(vector<AbstractCard*>&CardList);
void AddingDebetCard(vector<AbstractCard*>&CardList, map<string, string>&CardLogg);
void AddingCreditCard(vector<AbstractCard*>&CardList, map<string, string>&CardLogg);
void ViewBalanceCredCard(vector<AbstractCard*>&CardList);
void ViewBalanceDebCard(vector<AbstractCard*>&CardList);
void ViewBalanceALLCards(vector<AbstractCard*>&CardList);
void RechargeCredit(vector<AbstractCard*>&CardList, map<string, string>&CardLog);
void RechargeDebit(vector<AbstractCard*>&CardList, map<string, string>&CardLog);
void PurchaseGrossery(vector <AbstractCard*> &CardList, vector <AbstractExpence*> &PurchList, map<string, string>&CardLogg);
void AdjustBalance(vector<AbstractCard*>&CardList, Grocceries* product, bool &succes, map<string, string>&CardLogg);
void ShowPurchList(vector <AbstractExpence*> &PurchList);
void PurchaseHousWare(vector <AbstractCard*> &CardList, vector <AbstractExpence*> &PurchList, map<string, string>&CardLogg);
void AdjustBalanceHW(vector<AbstractCard*>&CardList, Houseware* product, bool &succes, map<string, string>&CardLogg);
void PurchaseService(vector <AbstractCard*> &CardList, vector <AbstractExpence*> &PurchList, map<string, string>&CardLogg);
void AdjustBalanceSV(vector<AbstractCard*>&CardList, Services* product, bool &succes, map<string, string>&CardLogg);
void CardLogging(map<string, string>&CardLogg);
void CardLogging11(map<string, string>&CardLogg, string tim);
void CardLoggMes1(DebetCard * debetCard, map<string, string>&CardLogg);
void CardLoggMes11(CreditCard * creditCard, map<string, string>&CardLog);

