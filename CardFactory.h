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

using namespace std;

class CardFactory
{
public:
	virtual AbstractCard* createCard() = 0;
	virtual ~CardFactory() {}
};
