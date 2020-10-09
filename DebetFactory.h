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
using namespace std;

class DebetFactory : public CardFactory
{
public:
	AbstractCard* createCard()
	{
		return new DebetCard;
	}

};
