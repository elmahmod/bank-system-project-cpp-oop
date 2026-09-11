#pragma once
#include <iostream>
#include "../objects/clsUser.h"
#include "../inheritance_screen/clsScreen.h"
using namespace std;

class clsFindUserScreen : protected clsScreen
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
    static void showFindUser()
    {
        _drawScreenHeader("Find User Screen");

        string username = clsInputValidate::readString("\nPlease enter username: ");

        while (!clsUser::isUserExist(username))
        {
            username = clsInputValidate::readString("\nUser with username [" + username + "] does not exist, enter another one: ");
        }

        clsUser user = clsUser::find(username);

        if (user.isEmpty())
        {
            cout << "\nUser not found.\n";
            return;
        }

        _printUserData(user);
    }
};