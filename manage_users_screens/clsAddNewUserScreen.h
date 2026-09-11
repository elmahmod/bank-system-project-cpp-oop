#pragma once
#include <iostream>
#include "../objects/clsUser.h"
#include "../inheritance_screen/clsScreen.h"
using namespace std;

class clsAddNewUserScreen : protected clsScreen
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

    static void _readNewUser(clsUser &user)
    {
        cout << endl;
        user.setFirstName(clsInputValidate::readString("Enter First Name: "));
        user.setLastName(clsInputValidate::readString("Enter Last Name: "));
        user.setEmail(clsInputValidate::readString("Enter Email: "));
        user.setPhone(clsInputValidate::readString("Enter Phone: "));
        user.setPassword(clsInputValidate::readString("Enter Password: "));
        cout << "Enter permssions:\n";
        user.setPermissions(_readPermission());
    }

    static int _readPermission()
    {
        int permission = 0;
        if (clsInputValidate::confirmAction("Do you want to give full access? (y/n): "))
            return clsUser::enPermissions::pALL;

        if (clsInputValidate::confirmAction("Access to Show clients list? (y/n): "))
            permission |= clsUser::enPermissions::pListClient;

        if (clsInputValidate::confirmAction("Access to Add new client? (y/n): "))
            permission |= clsUser::enPermissions::pAddNewClient;

        if (clsInputValidate::confirmAction("Access to Delete client? (y/n): "))
            permission |= clsUser::enPermissions::pDeleteClient;

        if (clsInputValidate::confirmAction("Access to Update client? (y/n): "))
            permission |= clsUser::enPermissions::pUpdateClient;

        if (clsInputValidate::confirmAction("Access to Find client? (y/n): "))
            permission |= clsUser::enPermissions::pFindClient;

        if (clsInputValidate::confirmAction("Access to Transactions? (y/n): "))
            permission |= clsUser::enPermissions::pTransactions;

        if (clsInputValidate::confirmAction("Access to Manage Users? (y/n): "))
            permission |= clsUser::enPermissions::pManageUsers;

        return permission;

        // 0 0 0 0 -> 1:,,  1:,,  1:w  1:r (with acess)
        // 1 -> 0 0 0 1
        // 2 -> 0 0 1 0
        // 4 -> 0 1 0 0
        // 8 -> 1 0 0 0
        // example 3 = -> 0 0 1 1 (has to acess) to write and read

        // when reading use |
        // when confirming use &
        // 0 0 1 1 & write( 0 0 1 0 ) = 0 0 1 0 == write ( has eccess to write)
    }

public:
    static void showAddNewUser()
    {
        _drawScreenHeader("Add User Screen");

        string username = clsInputValidate::readString("\nPlease enter username: ");

        while (clsUser::isUserExist(username))
        {
            username = clsInputValidate::readString("\nUser with username [" + username + "] already exists, enter another one: ");
        }

        clsUser newUser = clsUser::getAddUserObject(username);
        _readNewUser(newUser);

        switch (newUser.save())
        {
        case clsUser::svFailed:
        {
            cout << "\nError, User was not saved, please try again.\n";
            break;
        }
        case clsUser::svSucceeded:
        {
            cout << "\nUser added successfully :)\n";
            _printUserData(newUser);
            break;
        }
        case clsUser::svUserExist:
        {
            cout << "\nError, a User with username [" << username << "] already exists.\n";
            break;
        }
        }
    }
};