#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsUpdateCurrencyScreen :protected clsScreen
{
private:
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

public:

	static void ShowUpdateCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("\Update Currency Screen");

		string CurrencyCode = "";

		cout << "\n Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\Currency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency C = clsCurrency::FindCurrencyByCode(CurrencyCode);

		_PrintCurrencyCard(C);


		char Answer = 'n';
		cout << "\nAre you sure you want to update this Currency y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate Currency Rate:";
			cout << "\n____________________\n";

			cout << "\nEnter New Rate : ";
			float Rate = clsInputValidate::ReadFloatNumber();

			C.UpdateRate(Rate);

			cout << "\Currency Rate Updated Successfully (: ...\n";

			_PrintCurrencyCard(C);
		}
	}
};


	