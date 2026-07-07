#pragma once
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iostream>
using namespace std;

class clsFindCurrencyScreen :protected clsScreen
{
private:
	enum enFindType { eByCode = 1, eByCountry = 2 };

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "Currency Card: " << endl;
		cout << "\n__________________________________\n";
		cout << "Country      : " << Currency.Country() << endl;
		cout << "Currency Name: " << Currency.CurrencyName() << endl;
		cout << "Currency Code: " << Currency.CurrencyCode() << endl;
		cout << "Currency Rate: " << Currency.Rate() << endl;
		cout << "__________________________________\n";
	}

	static short _ReadFindCurrencyOption()
	{
		cout << "Find By :[1] Code or [2] Country ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 2? ");
		return Choice;
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}
public:
	static void ShowFindCurrencyScreen()
	{

		clsScreen::_DrawScreenHeader("\tFind Currency Screen");

		string InputCurrToSearch = "";
		enFindType FindType = enFindType(_ReadFindCurrencyOption());
		
		if (FindType == enFindType::eByCode)
		{
			cout << "Enter Country Code : ";
			InputCurrToSearch = clsInputValidate::ReadString();
			clsCurrency C = clsCurrency::FindCurrencyByCode(InputCurrToSearch);

			_ShowResults(C);
			
		}
		else if (FindType == enFindType::eByCountry)
		{

			cout << "Enter Country Name : ";
			InputCurrToSearch = clsInputValidate::ReadString();
			clsCurrency C = clsCurrency::FindCurrencyByCountry(InputCurrToSearch);

			_ShowResults(C);
		}

	}
};

