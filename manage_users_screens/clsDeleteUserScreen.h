#pragma once
#include <iostream>
#include "../objects/clsUser.h"
#include "../inheritance_screen/clsScreen.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:
    static void _printUserData(clsUser user)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << user.getFirstName();
        cout << "\nLastName    : " << user.getLastName();
        cout << "\nFull Name   : " << user.fullName();
        cout << "\nEmail       : " << user.getEmail();
        cout << "\nPhone       : " << user.getPhone();
        cout << "\nUsername    : " << user.getUsername();
        cout << "\nPassword    : " << user.getPassword();
        cout << "\nPermissions : " << user.getPermissions();
        cout << "\n___________________\n";
    }

public:

    static void showDeleteUser()
    {
        _drawScreenHeader("Delete Screen");
        string username = clsInputValidate::readString("\nPlease enter username: ");

        while (!clsUser::isUserExist(username))
        {
            username = clsInputValidate::readString("\nUser with username [" + username + "] does not exist, enter another one: ");
        }

        clsUser user = clsUser::find(username);
        _printUserData(user);

        if (clsInputValidate::confirmAction("\nDo you want to delete this user? [y-n]: "))
        {
            if (user.Delete())
            {
                cout << "\nUser deleted successfully.\n";
                _printUserData(user);
            }
            else
                cout << "\nError: User was not deleted.\n";
        }
        else
        {
            cout << "\nDeletion has been canceled\n";
        }
    }
};