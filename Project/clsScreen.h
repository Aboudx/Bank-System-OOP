#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;
class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\033[35m" << "\n\t\t\t\t\t______________________________________\n\n" << "\033[0m";
        cout << "\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\033[35m" << "\n\t\t\t\t\t______________________________________\n\n" << "\033[0m";
        
        clsDate Date;
        cout << "\033[32m" << "\t\t\t\t\tUser: " << "\033[0m" << CurrentUser.UserName << endl;
        cout << "\033[33m" << "\t\t\t\t\tDate: " << "\033[0m";
        cout << "\033[36m"; Date.Print(); cout << "\033[0m";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};