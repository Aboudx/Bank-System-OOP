#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen:protected clsScreen
{
private:
    static void _PrintClientInfo(clsBankClient Client)
	{
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
	}

    
    static void _IsClientExistToTransfer(string &AccountNumber)
    {
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            cout << "Please Enter Right UserName? ";
            cin >> AccountNumber;
        }
    }

public:
    static void ShowTransferScreen()
    {
        string Title = "\t  Transfer Screen";
        clsScreen::_DrawScreenHeader(Title);


        cout << "\nPlease Enter Account Number to Transfer From? ";
        string AccountNumber = "";
        cin >> AccountNumber;
         
        _IsClientExistToTransfer(AccountNumber);
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(Client1);

        cout << "\nPlease Enter Account Number to Transfer To? ";
        cin >> AccountNumber;

        _IsClientExistToTransfer(AccountNumber);
        clsBankClient Client2 = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(Client2);

        cout << "Enter Transfer Ammount? ";
        double TransferAmount = clsInputValidate::ReadDblNumber();
        
        while(!Client1.Withdraw(TransferAmount))
        {
            cout << "Amount Exceeds the available Balance, Enter another Amount? ";
            TransferAmount = clsInputValidate::ReadDblNumber();
        }

        cout << "\nAre you sure you want to perform this transaction? y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client2.Deposit(TransferAmount);
            cout << "\nTransfer Done Successfully\n\n";

            clsBankClient::RegisterLogTransfer(TransferAmount, Client1, Client2);
            _PrintClientInfo(Client1);
            _PrintClientInfo(Client2);
        }
        else
        {
            Client1.Deposit(TransferAmount);
            cout << "\nOperation was cancelled.\n";
        }

    }

};