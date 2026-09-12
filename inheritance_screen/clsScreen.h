#pragma once
#include <iostream>
#include <iomanip>
#include "../login_screens/global.h"
#include "../libraries/clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _drawScreenHeader(string title, string subTitle = "")
    {
        cout << setw(54) << left << "" << string(25, '_') << endl
             << endl;
        cout << setw(37 + (60 - title.length()) / 2) << left << "" << title << endl;

        if (subTitle != "")
        {
        }
        cout << setw(60) << left << "" << subTitle << endl << endl;
        
        cout << setw(54) << "" << "User: " << currentUser.getUsername() << endl;
        cout << setw(54) << "" << "Date: " << clsDate::dateToString(clsDate()) << endl;

        cout << setw(54) << left << "" << string(25, '_') << endl
             << endl;
    }

    static bool checkPermssions(clsUser::enPermissions permissions)
    {
        if (!currentUser.hasPermissions(permissions))
        {
            cout << "\n\nAccess Denied!\n\n";
            return false;
        }
        return true;
    }
};
