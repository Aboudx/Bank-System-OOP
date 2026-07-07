#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalcScreen.h"
using namespace std;

class clsCurrencyScreen :protected clsScreen
{
private:
	enum enCurrencyMenue { eList = 1, eFind = 2, eUpdate = 3, eCurrencyCalc = 4, eMainMenue = 5 };

    static short ReadCurrencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void GoBackToCurrencyExchageMenue()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menue...";
        system("pause>0");
        ShowCurrencyExchangeMenue();

    }
    
    static void _ShowCurrenciesList()
    {
        // cout << "\n Currencies List Screen will be here.\n";
        clsCurrenciesListScreen::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
        // cout << "\n  Find Currency Screen will be here.\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyScreen()
    {
        // cout << "\n Update Currency Screen will be here.\n";
        clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        // cout << "\n Currency Calculator Screen will be here.\n";
        clsCurrencyCalcScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrencyExchangeMenueOption(enCurrencyMenue CurrencyMenueOption)
    {
        switch (CurrencyMenueOption)
        {
        case clsCurrencyScreen::eList:
            system("cls");
            _ShowCurrenciesList();
            GoBackToCurrencyExchageMenue();

            break;
        case clsCurrencyScreen::eFind:
            system("cls");
            _ShowFindCurrencyScreen();
            GoBackToCurrencyExchageMenue();

            break;
        case clsCurrencyScreen::eUpdate:
            system("cls");
            _ShowUpdateCurrencyScreen();
            GoBackToCurrencyExchageMenue();

            break;
        case clsCurrencyScreen::eCurrencyCalc:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            GoBackToCurrencyExchageMenue();

            break;
        case clsCurrencyScreen::eMainMenue:

            //do nothing here the main screen will handle it :-) ;

            break;
        }
    }

public:

    static void ShowCurrencyExchangeMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\Currency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenueOption(enCurrencyMenue(ReadCurrencyExchangeMenueOption()));
    }
};

