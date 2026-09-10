#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsManageUsersScreen : protected clsScreen
{
    enum enManageUsersMenuOption
    {
        eListUsers = 1,
        eAddNewUser,
        eDeleteUser,
        eUpdateUser,
        eFindUser,
        eBackToMainMenu
    };

    static enManageUsersMenuOption _readenManageUsersMenuOption(const string &message)
    {
        int option = clsInputValidate::readIntNumberBetween(1, 6, message);
        return static_cast<enManageUsersMenuOption>(option);
    }

private:
    static void _showAllUsersScreen()
    {
        cout << "\n\tList Users Screen will be here soon . . .\n";
    }

    static void _showAddNewUserScreen()
    {
        cout << "\n\tAdd New User Screen will be here soon . . .\n";
    }

    static void _showDeleteUserScreen()
    {
        cout << "\n\tDelete User Screen will be here soon . . .\n";
    }

    static void _showUpdateUserScreen()
    {
        cout << "\n\tUpdate User Screen will be here soon . . .\n";
    }

    static void _showFindUserScreen()
    {
        cout << "\n\tFind User Screen will be here soon . . .\n";
    }

    static void _performManageUsersMenuOption(enManageUsersMenuOption option)
    {
        system("cls");

        switch (option)
        {
        case eListUsers:
            _showAllUsersScreen();
            break;

        case eAddNewUser:
            _showAddNewUserScreen();
            break;

        case eDeleteUser:
            _showDeleteUserScreen();
            break;

        case eUpdateUser:
            _showUpdateUserScreen();
            break;

        case eFindUser:
            _showFindUserScreen();
            break;

        case eBackToMainMenu:
            break;
        }
    }

public:
    static void showManageUsersMenu()
    {
        enManageUsersMenuOption option;
        do
        {
            system("cls");
            _drawScreenHeader("Manage Users Screen");

            cout << setw(37) << left << "" << string(60, '=') << endl;
            cout << setw(62) << left << "" << "Main Menu" << endl;
            cout << setw(37) << left << "" << string(60, '=') << endl;

            cout << setw(37) << left << "" << "\t[1] Show User List." << endl;
            cout << setw(37) << left << "" << "\t[2] Add New User." << endl;
            cout << setw(37) << left << "" << "\t[3] Delete User." << endl;
            cout << setw(37) << left << "" << "\t[4] Update User Info." << endl;
            cout << setw(37) << left << "" << "\t[5] Find User." << endl;
            cout << setw(37) << left << "" << "\t[6] Main Menu." << endl;
            cout << setw(37) << left << "" << string(60, '=') << endl;
            cout << setw(37) << left << "";

            option = _readenManageUsersMenuOption("choose what do you want to do? ");
            _performManageUsersMenuOption(option);

            if (option != eBackToMainMenu)
            {
                cout << endl;
                system("pause");
            }

        } while (option != eBackToMainMenu);
    }
};
