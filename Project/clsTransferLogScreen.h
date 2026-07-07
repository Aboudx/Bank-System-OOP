#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "stTransferLog.h"

class clsTransferLogScreen :protected clsScreen
{
	static void _PrintTransferInfo(stTransferLog TransferLog)
	{
        cout << setw(8) << left << "" << "| " << setw(25) << left << TransferLog.sDateTime;
        cout << "| " << setw(12) << left << TransferLog.sSourceAccountNumber;
        cout << "| " << setw(12) << left << TransferLog.sDecAccountNumber;
        cout << "| " << setw(13) << left << TransferLog.sAmount;
        cout << "| " << setw(10) << left << TransferLog.sSourceBalance;
        cout << "| " << setw(12) << left << TransferLog.sDecBalance;
        cout << "| " << setw(12) << left << TransferLog.sUserName << endl;
	}
public:
    static void ShowTransferLogScreen()
    {
        vector<stTransferLog>vTransferLogList = clsBankClient::GetTransferLogList();

        string Title = "\t Transfer Log Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogList.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date Time";
        cout << "| " << left << setw(12) << "s.AccN";
        cout << "| " << left << setw(12) << "D.AccN";
        cout << "| " << left << setw(13) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(12) << "D.Balance";
        cout << "| " << left << setw(12) << "User Name";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vTransferLogList.size() == 0)
            cout << "\t\t\t\tNo Transfer Logs Available In the System!";
        else
        for (stTransferLog TransferLog : vTransferLogList)
        {
            _PrintTransferInfo(TransferLog);
        }


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

