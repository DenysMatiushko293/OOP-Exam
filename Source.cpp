# define _CRT_SECURE_NO_WARNINGS
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

bool CardAvailCheck(vector<AbstractCard*>&CardList)
{
	bool check;
	if (CardList.size() == 0)
	{
		cout << "\nYou don't have any bank cards - please, go to \"Add card\" and create first one" << endl;
		check = false;
		cin.get(); system("cls");
		return check;
	}
	else { check = true; return check; }
}

void ShowCardList(vector<AbstractCard*>&CardList)
{
	cout << "\nAs per given date, you have following bank cards, as listed below: " << endl << endl;
	for (int i = 0; i < CardList.size(); i++)
	{
		cout << "\nCard No: " << CardList[i]->GetCardID() << "; type of card: " << CardList[i]->GetType() << "; expires on: " << CardList[i]->GetMonth() << " \\ " << CardList[i]->GetYear();
	}
}

void AddingDebetCard(vector<AbstractCard*>&CardList, map<string, string>&CardLogg)
{
	string ID;
	string cur;
	string mon;
	int yea;
	DebetCard * debetCard = new DebetCard;
	cout << "\nPLease, input card identification number (16 digits on the front side): "; cin >> ID;
	cout << "\nPlease, input currency of the debet card: "; cin >> cur;
	cout << "\nPLease, input year, when card expires: "; cin >> yea;
	cout << "\nPlease, input month, when card expires: "; cin >> mon;
	debetCard->Initial(mon, yea, ID, cur);
	CardList.push_back(debetCard);
	CardLoggMes1(debetCard, CardLogg);
	CardLogging(CardLogg);
}



void AddingCreditCard(vector<AbstractCard*>&CardList, map<string, string>&CardLogg)
{
	string ID;
	string cur;
	string mon;
	int yea;
	double lim;
	CreditCard* creditCard = new CreditCard;
	cout << "\nPLease, input card identification number (16 digits on the front side): "; cin >> ID;
	cout << "\nPlease, input currency of the credit card: "; cin >> cur;
	cout << "\nPLease, input year, when card expires: "; cin >> yea;
	cout << "\nPlease, input month, when card expires: "; cin >> mon;
	cout << "\nPLease, input credit limit for the card: "; cin >> lim;
	creditCard->Initial(mon, yea, ID, cur, lim);
	CardList.push_back(creditCard);
	CardLoggMes11(creditCard, CardLogg);
	CardLogging(CardLogg);
}

void ViewBalanceCredCard(vector<AbstractCard*>&CardList)
{
	for (int i = 0; i < CardList.size(); i++)
	{
		if (CardList[i]->GetType() == "Credit")
			cout << "\nCredit card No: " << CardList[i]->GetCardID() << " has " << CardList[i]->GetBalance() << " " << CardList[i]->GetCurrency() << " on its balance";
	}
}

void ViewBalanceDebCard(vector<AbstractCard*>&CardList)
{
	for (int i = 0; i < CardList.size(); i++)
	{
		if (CardList[i]->GetType() == "Debet")
			cout << "\nCredit card No: " << CardList[i]->GetCardID() << " has " << CardList[i]->GetBalance() << " " << CardList[i]->GetCurrency() << " on its balance";
	}
}

void ViewBalanceALLCards(vector<AbstractCard*>&CardList)
{
	for (int i = 0; i < CardList.size(); i++)
	{
		cout << "\nCredit card No: " << CardList[i]->GetCardID() << " has " << CardList[i]->GetBalance() << " " << CardList[i]->GetCurrency() << " on its balance";
	}
}

void RechargeCredit(vector<AbstractCard*>&CardList, map<string, string>&CardLog)
{
	double bal; char*sum = new char;
	string numero;
	CreditCard buffer;
	cout << "\nPLease, input sum you want to put on balance of credit card: "; cin >> bal;
	cout << "\nPlease, input number of card you want to recharge: "; cin >> numero;
	for (int i = 0; i < CardList.size(); i++)
	{
		if (CardList[i]->GetCardID() == numero)
		{
			CardList[i]->SetBalance(bal);
			double check = CardList[i]->GetBalance();
			if (check != 0)
			{
				cout << "\nBalance refilled successfully!!! ";
				string message1, tim; char*number = new char[8]; 
				time_t seconds = time(NULL);
				struct tm* time = gmtime(&seconds);
				tim.append(asctime(time));
				message1.append(" ");
				message1.append(CardList[i]->GetType());
				message1.append(" ");
				message1.append("Card number");
				message1.append(" ");
				message1.append(CardList[i]->GetCardID());
				message1.append(" ");
				message1.append("was recharged for ");
				message1.append(" ");
				message1.append(_itoa(bal, sum, 10));
				message1.append(" ");
				message1.append(CardList[i]->GetCurrency());
				message1.append("\n");
				CardLog.insert(pair<string, string>(tim, message1));
				CardLogging11(CardLog, tim);
			}
			else cout << "\nUnknown error happened  - please try later";
		}
	}

}

void RechargeDebit(vector<AbstractCard*>&CardList, map<string, string>&CardLog)
{
	double bal;
	string numero; char*sum = new char;
	cout << "\nPLease, input sum you want to put on balance of debet card: "; cin >> bal;
	cout << "\nPlease, input number of card you want to recharge: "; cin >> numero;
	for (int i = 0; i < CardList.size(); i++)
	{
		if (CardList[i]->GetCardID() == numero)
		{
			CardList[i]->SetBalance(bal);
			double check = CardList[i]->GetBalance();
			if (check != 0)
			{
				cout << "\nBalance refilled successfully!!! ";
				string message1, tim; char*number = new char[8];
				time_t seconds = time(NULL);
				struct tm* time = gmtime(&seconds);
				tim.append(asctime(time));
				message1.append(" ");
				message1.append(CardList[i]->GetType());
				message1.append(" ");
				message1.append("Card number");
				message1.append(" ");
				message1.append(CardList[i]->GetCardID());
				message1.append(" ");
				message1.append("was recharged for ");
				message1.append(" ");
				message1.append(_itoa(bal, sum, 10));
				message1.append(" ");
				message1.append(CardList[i]->GetCurrency());
				message1.append("\n");
				CardLog.insert(pair<string, string>(tim, message1));
				CardLogging11(CardLog, tim);
			}
			else cout << "\nUnknown error happened  - please try later";
		}
	}

}

void PurchaseGrossery(vector <AbstractCard*> &CardList, vector <AbstractExpence*> &PurchList, map<string, string>&CardLogg)
{
	string nam; double prc; string cur; string unt; double quan; bool success = false;
	Grocceries* product = new Grocceries;
	cout << "\nPLease, input name of product you want to purchase: "; cin >> nam;
	cout << "\nPLease, input price of product you want to purchase: "; cin >> prc;
	cout << "\nPLease, input currency product price: "; cin >> cur;
	cout << "\nPLease, input unit of product measurement: "; cin >> unt;
	cout << "\nPLease, input number of product inuts you want to purchase : "; cin >> quan;
	product->Initial(nam, prc, cur, quan);
	AdjustBalance(CardList, product, success, CardLogg);
	if (success)PurchList.push_back(product); CardLogging(CardLogg);
}

void AdjustBalance(vector<AbstractCard*>&CardList, Grocceries* product, bool &succes, map<string, string>&CardLogg)
{
	double total = (product->GetPrice())*(product->GetQuantity()); string tim;
	cout << "\nAt the moment you have following cards: " << endl;
	int size = CardList.size();
	for (int i = 0; i < size; i++)
	{
		cout << "Card: " << CardList[i]->GetCardID() << "; Type: " << CardList[i]->GetType() << ", Balance: " << CardList[i]->GetBalance() << " " << CardList[i]->GetCurrency() << endl;
	}
	string card; string message; char *sum = new char;
	cout << "\nPlease, input card you want to pay: "; cin >> card;
	for (int i = 0; i < size; i++)
	{
		if (CardList[i]->GetCardID() == card)
		{
			if (CardList[i]->GetBalance() > total)
			{
				CardList[i]->SetBalance((CardList[i]->GetBalance()) - total);
				cout << "\nTransaction SUCCESSFUL";
				cin.get(); system("cls");
				succes = true;
				message.append(CardList[i]->GetCardID());
				message.append(" ");
				message.append(_itoa(total*(-1), sum, 10));
				message.append(" ");
				message.append(CardList[i]->GetCurrency());
				message.append(" ");
				message.append(product->GetCategory());
				message.append(" ");
				message.append(product->GetName());
				message.append(" ");
				message.append(_itoa(product->GetPrice(), sum, 10));
				message.append(" ");
				message.append(product->GetCurrency());
				message.append(" ");
				message.append(_itoa(product->GetQuantity(), sum, 10));
				message.append(" ");
				message.append(product->GetUnit());
				message.append(" ");
				message.append(_itoa(CardList[i]->GetBalance(), sum, 10));
				message.append(" ");
				message.append(CardList[i]->GetCurrency());
				message.append("\n");
				string tim; char*number = new char[8];
				time_t seconds = time(NULL);
				struct tm* time = gmtime(&seconds);
				tim.append(asctime(time));
				CardLogg.insert(pair<string, string>(tim, message));
				CardLogging11(CardLogg, tim);
			}
			else { cout << "\nOperation DENIED - you do not have sufficient balance on this card"; cin.get(); system("cls"); succes = false; }
		}
	}
}

void ShowPurchList(vector <AbstractExpence*> &PurchList)
{
	int size = PurchList.size();
	for (int i = 0; i < size; i++)
	{
		PurchList[i]->ShowExpence();
	}

}

void PurchaseHousWare(vector <AbstractCard*> &CardList, vector <AbstractExpence*> &PurchList, map<string, string>&CardLogg)
{
	string nam; double prc; string cur; string unt; double quan; bool success = false;
	Houseware* product = new Houseware;
	cout << "\nPLease, input name of product you want to purchase: "; cin >> nam;
	cout << "\nPLease, input price of product you want to purchase: "; cin >> prc;
	cout << "\nPLease, input currency product price: "; cin >> cur;
	cout << "\nPLease, input unit of product measurement: "; cin >> unt;
	cout << "\nPLease, input number of product inuts you want to purchase : "; cin >> quan;
	product->Initial(nam, prc, cur, quan);
	AdjustBalanceHW(CardList, product, success, CardLogg);
	if (success)PurchList.push_back(product);
}
void AdjustBalanceHW(vector<AbstractCard*>&CardList, Houseware* product, bool &succes, map<string, string>&CardLogg)
{
	double total = (product->GetPrice())*(product->GetQuantity()); string tim;
	cout << "\nAt the moment you have following cards: " << endl;
	int size = CardList.size();
	for (int i = 0; i < size; i++)
	{
		cout << "Card: " << CardList[i]->GetCardID() << "; Type: " << CardList[i]->GetType() << ", Balance: " << CardList[i]->GetBalance() << " " << CardList[i]->GetCurrency() << endl;
	}
	string card; string message; char *sum = new char;
	cout << "\nPlease, input card you want to pay: "; cin >> card;
	for (int i = 0; i < size; i++)
	{
		if (CardList[i]->GetCardID() == card)
		{
			if (CardList[i]->GetBalance() > total)
			{
				CardList[i]->SetBalance((CardList[i]->GetBalance()) - total);
				cout << "\nTransaction SUCCESSFUL";
				cin.get(); system("cls");
				succes = true;
				message.append(CardList[i]->GetCardID());
				message.append(" ");
				message.append(_itoa(total*(-1), sum, 10));
				message.append(" ");
				message.append(CardList[i]->GetCurrency());
				message.append(" ");
				message.append(product->GetCategory());
				message.append(" ");
				message.append(product->GetName());
				message.append(" ");
				message.append(_itoa(product->GetPrice(), sum, 10));
				message.append(" ");
				message.append(product->GetCurrency());
				message.append(" ");
				message.append(_itoa(product->GetQuantity(), sum, 10));
				message.append(" ");
				message.append(product->GetUnit());
				message.append(" ");
				message.append(_itoa(CardList[i]->GetBalance(), sum, 10));
				message.append(" ");
				message.append(CardList[i]->GetCurrency());
				message.append("\n");
				string message1, tim; char*number = new char[8];
				time_t seconds = time(NULL);
				struct tm* time = gmtime(&seconds);
				tim.append(asctime(time));
				CardLogg.insert(pair<string, string>(tim, message));
				CardLogging11(CardLogg, tim);
			}
			else { cout << "\nOperation DENIED - you do not have sufficient balance on this card"; cin.get(); system("cls"); succes = false; }
		}
	}
}
void PurchaseService(vector <AbstractCard*> &CardList, vector <AbstractExpence*> &PurchList, map<string, string>&CardLogg)
{
	string nam; double prc; string cur; string unt; double quan; bool success = false;
	Services* product = new Services;
	cout << "\nPLease, input name of product you want to purchase: "; cin >> nam;
	cout << "\nPLease, input price of product you want to purchase: "; cin >> prc;
	cout << "\nPLease, input currency product price: "; cin >> cur;
	cout << "\nPLease, input unit of product measurement: "; cin >> unt;
	cout << "\nPLease, input number of product inuts you want to purchase : "; cin >> quan;
	product->Initial(nam, prc, cur, quan);
	AdjustBalanceSV(CardList, product, success, CardLogg);
	if (success)PurchList.push_back(product);
}
void AdjustBalanceSV(vector<AbstractCard*>&CardList, Services* product, bool &succes, map<string, string>&CardLogg)
{
	double total = (product->GetPrice())*(product->GetQuantity()); string tim;
	cout << "\nAt the moment you have following cards: " << endl;
	int size = CardList.size();
	for (int i = 0; i < size; i++)
	{
		cout << "Card: " << CardList[i]->GetCardID() << "; Type: " << CardList[i]->GetType() << ", Balance: " << CardList[i]->GetBalance() << " " << CardList[i]->GetCurrency() << endl;
	}
	string card; string message; char *sum = new char;
	cout << "\nPlease, input card you want to pay: "; cin >> card;
	for (int i = 0; i < size; i++)
	{
		if (CardList[i]->GetCardID() == card)
		{
			if (CardList[i]->GetBalance() > total)
			{
				CardList[i]->SetBalance((CardList[i]->GetBalance()) - total);
				cout << "\nTransaction SUCCESSFUL";
				cin.get(); system("cls");
				succes = true;
				message.append(CardList[i]->GetCardID());
				message.append(" ");
				message.append(_itoa(total*(-1), sum, 10));
				message.append(" ");
				message.append(CardList[i]->GetCurrency());
				message.append(" ");
				message.append(product->GetCategory());
				message.append(" ");
				message.append(product->GetName());
				message.append(" ");
				message.append(_itoa(product->GetPrice(), sum, 10));
				message.append(" ");
				message.append(product->GetCurrency());
				message.append(" ");
				message.append(_itoa(product->GetQuantity(), sum, 10));
				message.append(" ");
				message.append(product->GetUnit());
				message.append(" ");
				message.append(_itoa(CardList[i]->GetBalance(), sum, 10));
				message.append(" ");
				message.append(CardList[i]->GetCurrency());
				message.append("\n");
				string tim; char*number = new char[8];
				time_t seconds = time(NULL);
				struct tm* time = gmtime(&seconds);
				tim.append(asctime(time));
				CardLogg.insert(pair<string, string>(tim, message));
				CardLogging11(CardLogg, tim);
			}
			else { cout << "\nOperation DENIED - you do not have sufficient balance on this card"; cin.get(); system("cls"); succes = false; }
		}
	}
}


void CardLoggMes1(DebetCard * debetCard, map<string, string>&CardLog)
{
	string message1, tim; char*number = new char[8];
	time_t seconds = time(NULL);
	struct tm* time = gmtime(&seconds);
	tim.append(asctime(time));
	message1.append(" ");
	message1.append(debetCard->GetType());
	message1.append(" ");
	message1.append("Card number");
	message1.append(" ");
	message1.append(debetCard->GetCardID());
	message1.append(" ");
	message1.append("was created\n");
	CardLog.insert(pair<string, string>(tim, message1));

}

void CardLoggMes11(CreditCard * creditCard, map<string, string>&CardLog)
{
	string message1, tim; char*number = new char[8];
	time_t seconds = time(NULL);
	struct tm* time = gmtime(&seconds);
	tim.append(asctime(time));
	message1.append(" ");
	message1.append(creditCard->GetType());
	message1.append(" ");
	message1.append("Card number");
	message1.append(" ");
	message1.append(creditCard->GetCardID());
	message1.append(" ");
	message1.append("was created\n");
	CardLog.insert(pair<string, string>(tim, message1));

}



void CardLogging(map<string, string>&CardLogg)
{
		string key; string value; int counter = 0;
		auto it = CardLogg.rbegin();
		std::fstream myFile("CardLogFile.txt", ios::out | ios::app);
		int size_key = (*it).first.size();
		int size_value = (*it).second.length();
		char *firsT = new char[size_key];
		char *seconD = new char[size_value];
		strcpy(firsT, (*it).first.c_str());
		strcpy(seconD, (*it).second.c_str());
		myFile.write((char*)firsT, size_key * sizeof(char));
		myFile.write(" ", sizeof(char));
		myFile.write((char*)seconD, size_value * sizeof(char));
		myFile.write(" ", sizeof(char));
		myFile.close();
		key.erase();
		value.erase();
		counter++;
		FILE *count = fopen("CounterCards.txt", "wt");
		char *c = new char[8];
		_itoa(counter, c, 10);
		fputs(c, count);
		fclose(count);
}
void CardLogging11(map<string, string>&CardLogg, string tim)
{
	string key; string value; int counter = 0;
	auto it = CardLogg.rbegin();
	std::fstream myFile("CardLogFile.txt", ios::out | ios::app);
	int size_key = (*it).first.size();
	int size_value = (*it).second.length();
	char *firsT = new char[size_key];
	char *seconD = new char[size_value];
	strcpy(firsT, (*it).first.c_str());
	strcpy(seconD, (*it).second.c_str());
	myFile.write((char*)firsT, size_key * sizeof(char));
	myFile.write(" ", sizeof(char));
	myFile.write((char*)seconD, size_value * sizeof(char));
	myFile.write(" ", sizeof(char));
	myFile.close();
	key.erase();
	value.erase();
	counter++;
	FILE *count = fopen("CounterCards.txt", "wt");
	char *c = new char[8];
	_itoa(counter, c, 10);
	fputs(c, count);
	fclose(count);
}