#pragma once
#include <iostream>
#include "../inheritance_screen/clsScreen.h"
#include "../objects/clsBankClient.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:
    static void _printLoginRegisterRecordLine(clsUser::stLoginRegisterRecord loginRegister)
    {
        cout << setw(8) << "" << "| "
             << left << setw(30) << loginRegister.dateTime;
        cout << "| " << left << setw(20) << loginRegister.username;
        cout << "| " << left << setw(15) << loginRegister.password;
        cout << "| " << left << setw(12) << loginRegister.permissions;
    }

public:
    static void showLoginRegister()
    {
        if (!clsScreen::checkPermssions(clsUser::enPermissions::pLoginRegister))
            return;

        vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecords = clsUser::getLoginRegisterList();

        _drawScreenHeader("Login Register List Screen", "(" + to_string(vLoginRegisterRecords.size()) + ") Records.");

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;

        cout << setw(8) << "" << "| " << left << setw(30) << "Date/Time";
        cout << "| " << left << setw(20) << "username";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(12) << "Permissions" << endl;

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;

        if (vLoginRegisterRecords.size() == 0)
            cout << "\t\t\t\tNo Login Registers Available In the System!\n";
        else
        {
            for (clsUser::stLoginRegisterRecord &record : vLoginRegisterRecords)
            {
                _printLoginRegisterRecordLine(record);
                cout << endl;
            }
        }

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;
    }
};