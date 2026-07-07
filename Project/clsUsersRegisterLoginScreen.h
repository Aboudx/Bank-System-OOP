#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "UserLoginRegister.h"

class clsUsersRegisterLoginScreen :protected clsScreen
{
private:

    static void _PrintUserRegisterLoginRecord(stUserLoginRegister User)
    {
        cout << setw(8) << left << "" << "| " << setw(40) << left << User.sDateRegister;
        cout << "| " << setw(25) << left << User.sUserName;
        cout << "| " << setw(14) << left << User.sPassword;
        cout << "| " << setw(12) << left << User.sPermissions;
    }

public:
    static void ShowUsersRegisterLoginList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pShowRegisterUsers))
        {
            return;// this will exit the function and it will not continue
        }

        vector <stUserLoginRegister> vUsers = clsUser::GetUsersLoginRegisterList();

        string Title = "\t  User Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Register Date";
        cout << "| " << left << setw(25) << "User Name";
        cout << "| " << left << setw(14) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (stUserLoginRegister User : vUsers)
            {

                _PrintUserRegisterLoginRecord(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
};

