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

int main()
{
	//block with variables
	vector <AbstractCard*> CardList;
	vector <AbstractExpence*>PurchList;
	map<string, string>CardLogg;
	

	cout << "\t\t\tWELCOME TO PERSONAL FINANCE MANAGEMENT SYSTEM !!!" << endl;
	char menu = ' ';
	while (menu != 'x')
	{
		cout << "\n=============================================MAIN MENU====================================";
		cout << "\n\tIf you want to enter to the BankCards menu - press 1";
		cout << "\n\tIf you want to record expences - press 2";
		cout << "\n\tIf you want to create report - press 3";
		cout << "\n\tIf you want to rank expences by sum - press 4";
		cout << "\n\tIf you want to review all records - press 5";
		cout << "\n\tTo quit the program - press 0";
		cout << "\n==========================================================================================\n";
		cout << "Please, select desired activity: "; cin >> menu;
		cin.get(); system("cls");
		switch (menu)
		{
		case '1':
		{
			cout << "\n=========================================BANK CARD MENU====================================" << endl << endl;
			char menuBC = ' ';
			while (menuBC != 'x')
			{
				cout << "\n\tIf you want to check your Bank Cards - press 1";
				cout << "\n\tIf you want to add Bank card - press 2";
				cout << "\n\tIf you want to view balance - press 3";
				cout << "\n\tIf you want to recharge balance - press 4";
				cout << "\n\tTo quit the program - press 0" << endl << endl;
				cout << "\n==========================================================================================\n";
				cout << "Please, select desired activity: "; cin >> menuBC;
				cin.get(); system("cls");
				switch (menuBC)
				{
				case '1':
				{
					cout << "=======================CHECKING OF BANK CARDS============================" << endl << endl;
					if (!CardAvailCheck(CardList)) break;
					else ShowCardList(CardList);

					cout << "\n==========================================================================================\n" << endl;
					cin.get(); system("cls");
					break;
				}
				case'2':
				{
					cout << "=======================ADDING BANK CARD============================" << endl << endl;
					char menuCard = ' ';
					while (menuCard != 'z')
					{
						cout << "\n\tIf you want to add Credit Crad - press 1";
						cout << "\n\tIf you want to add Debet card - press 2";
						cout << "\n\tTo quit the program - press 0" << endl << endl;
						cout << "\n==========================================================================================\n";
						cout << "Please, select desired activity: "; cin >> menuCard;
						cin.get(); system("cls");
						switch (menuCard)
						{
						case '1':
						{
							AddingCreditCard(CardList, CardLogg);
							cin.get(); system("cls");
							break;
						}
						case'2':
						{
							AddingDebetCard(CardList, CardLogg);
							cin.get(); system("cls");
							break;
						}
						case'0':
						{
							menuCard = 'z';
							break;
						}
						default:
							cout << "\nWrong key - please, try again!!!!" << endl << endl;
							cin.get(); system("cls");
							break;
						}
					}
					cout << "\n==========================================================================================\n" << endl;
					cin.get(); system("cls");
					break;
				}
				case'3':
				{
					cout << "=======================REVIEW OF BALANCE============================" << endl << endl;
					char menuBal = ' ';
					while (menuBal != 'z')
					{
						cout << "\n\tIf you want to check balance of Credit Crad - press 1";
						cout << "\n\tIf you want to check balance of Debet card - press 2";
						cout << "\n\tIf you want to view balances of ALL cards - press 3";
						cout << "\n\tTo quit the program - press 0" << endl << endl;
						cout << "\n==========================================================================================\n";
						cout << "Please, select desired activity: "; cin >> menuBal;
						cin.get(); system("cls");
						switch (menuBal)
						{
						case '1':
						{
							ViewBalanceCredCard(CardList);
							cin.get(); system("cls");
							break;
						}
						case'2':
						{
							ViewBalanceDebCard(CardList);
							cin.get(); system("cls");
							break;
						}
						case'3':
						{
							ViewBalanceALLCards(CardList);
							cin.get(); system("cls");
							break;
						}
						case'0':
						{
							menuBal = 'z';
							break;
						}
						default:
							cout << "\nWrong key - please, try again!!!!" << endl << endl;
							cin.get(); system("cls");
							break;
						}
					}
					cout << "\n==========================================================================================\n" << endl;
					cin.get(); system("cls");
					break;
				}
				case'4':
				{
					cout << "=======================RECHARGING CARD============================" << endl << endl;
					char menuBalance = ' ';
					while (menuBalance != 'z')
					{
						cout << "\n\tIf you want to put money to Credit Crad - press 1";
						cout << "\n\tIf you want to put money to Debet card - press 2";
						cout << "\n\tTo quit the program - press 0" << endl << endl;
						cout << "\n==========================================================================================\n";
						cout << "Please, select desired activity: "; cin >> menuBalance;
						cin.get(); system("cls");
						switch (menuBalance)
						{
						case '1':
						{
							RechargeCredit(CardList, CardLogg);
							cin.get(); system("cls");
							break;
						}
						case'2':
						{
							RechargeDebit(CardList, CardLogg);
							cin.get(); system("cls");
							break;
						}
						case'0':
						{
							menuBalance = 'z';
							break;
						}
						default:
							cout << "\nWrong key - please, try again!!!!" << endl << endl;
							cin.get(); system("cls");
							break;
						}
						cout << "\n==========================================================================================\n" << endl;
						break;
					}
				}
				case'0':
				{
					menuBC = 'x';
					break;
				}
				default:
					cout << "\nWrong key - please, try again!!!!" << endl << endl;
					break;
				}

			}
			cin.get(); system("cls");
			break;
		}
		case'2':
		{
			cout << "=======================RECORDING OF EXPENCES============================" << endl << endl;
			char menuExp = ' ';
			while (menuExp != 'z')
			{
				cout << "\n\tIf you want to buy grocceries - press 1";
				cout << "\n\tIf you want to buy houseware - press 2";
				cout << "\n\tIf you want to buy a service - press 3";
				cout << "\n\tIf you want to buy a service - press 4";
				cout << "\n\tTo return to main menu - press 0";
				cout << "\n==========================================================================================\n";
				cout << "Please, select desired activity: "; cin >> menuExp;
				cin.get(); system("cls");
				switch (menuExp)
				{
				case '1':
				{
					cout << "=======================PURCHASING GROSSERIES============================" << endl << endl;
					PurchaseGrossery(CardList, PurchList, CardLogg);
					ShowPurchList(PurchList);
					cin.get(); system("cls");
						cout << "\n==========================================================================================\n" << endl;
						cin.get(); system("cls");
						break;
					
				}
				case '2':
				{
					cout << "=======================PURCHASING HOUSEWARES============================" << endl << endl;
					PurchaseHousWare(CardList, PurchList, CardLogg);
					ShowPurchList(PurchList);
					cin.get(); system("cls");
					cout << "\n==========================================================================================\n" << endl;
					cin.get(); system("cls");
					break;
				}
				case '3':
				{
					cout << "=======================PURCHASING SERVICES============================" << endl << endl;
					PurchaseService(CardList, PurchList, CardLogg);
					ShowPurchList(PurchList);
					cin.get(); system("cls");
					cout << "\n==========================================================================================\n" << endl;
					cin.get(); system("cls");
					break;
				}
				case '4':
				{
					cout << "=======================PURCHASE LIST============================" << endl << endl;
					ShowPurchList(PurchList);
					cin.get(); system("cls");
					break;
				}
				case'0':
					menuExp = 'z';
					break;
				default:
					break;
				}
				}

				cout << "\n==========================================================================================\n" << endl;
				break;
			}
		case'3':
		{
			cout << "=======================CALCULATION OF SURFACE AREA============================" << endl << endl;

			cout << "\n==========================================================================================\n" << endl;
			break;
		}
		case'4':
		{
			cout << "=======================COMPARISON OF TYPES=================================" << endl << endl;

			cout << "\n==========================================================================================\n" << endl;
			break;
		}

		case'0':
		{
			menu = 'x';
			cout << "\n\n=======================THANK YOU FOR USING OUR PROGRAM!!!!======================================\n";
			break;
		}
		default:
			cout << "\nWrong key - please, try again!!!!" << endl << endl;
			break;
		}
		}


		cin.get();
		cin.get();
}
