#pragma once
#include <iostream>
#include "../objects/clsUser.h"
#include "../inheritance_screen/clsScreen.h"
using namespace std;

class clsUsersListScreen : protected clsScreen
{
private:
    static void _printUserRecordLine(clsUser user)
    {
        cout << setw(8) << "" << "| "
             << left << setw(20) << user.getUsername();
        cout << "| " << left << setw(20) << user.fullName();
        cout << "| " << left << setw(15) << user.getPhone();
        cout << "| " << left << setw(20) << user.getEmail();
        cout << "| " << left << setw(12) << user.getPassword();
        cout << "| " << left << setw(12) << user.getPermissions();
    }

public:
    static void showUsersList()
    {
        vector<clsUser> vUsers = clsUser::getUsersList();

        _drawScreenHeader("User List Screen", "(" + to_string(vUsers.size()) + ") Users.");

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;

        cout << setw(8) << "" << "| " << left << setw(20) << "Username";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(15) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(12) << "Permissions" << endl;

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!\n";
        else
        {
            for (clsUser &user : vUsers)
            {
                _printUserRecordLine(user);
                cout << endl;
            }
        }

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;
    }
};