#pragma once
#include <iostream>
#include "screens/clsScreen.h"
#include "screens/clsClientListScreen.h"
#include "screens/clsAddNewClientScreen.h"
#include "screens/clsDeleteClientScreen.h"
#include "screens/clsUpdateClientScreen.h"
#include "screens/clsFindClientScreen.h"
#include "screens/clsTransactionsScreen.h"
#include "screens/clsManageUsersScreen.h"
#include "libraries/clsInputValidate.h"

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenuOptions
    {
        eListClients = 1,
        eAddNewClient,
        eDeleteClient,
        eUpdateClient,
        eFindClient,
        eShowTransactionsMenu,
        eManageUsers,
        eExit
    };

    static enMainMenuOptions _readMainMenuOption(const string &message)
    {
        int option = 0;
        option = clsInputValidate::readIntNumberBetween(1, 8, message);
        return static_cast<enMainMenuOptions>(option);
    }

    static void _showAllClientsScreen()
    {
        // cout << "\n\tShow Client List Screen will be here soon . . .\n";
        clsClientListScreen::showClientList();
    }

    static void _showAddNewClientScreen()
    {
        // cout << "\n\tAdd New Client Screen will be here soon . . .\n";
        clsAddNewClientScreen::showAddNewClient();
    }

    static void _showDeleteClientScreen()
    {
        // cout << "\n\tDelete Client Screen will be here soon . . .\n";
        clsDeleteClientScreen::showDeleteClientScreen();
    }

    static void _showUpdateClientScreen()
    {
        // cout << "\n\tUpdate Client Screen will be here soon . . .\n";
        clsUpdateClientScreen::showUpdateClient();
    }

    static void _showFindClientScreen()
    {
        // cout << "\n\tFind Client Screen will be here soon . . .\n";
        clsFindClientScreen::showFindClient();
    }

    static void _showTransactionsMenu()
    {
        // cout << "\n\tTransactions Menu will be here soon . . .\n";
        clsTransactionsScreen::showTransactionsMenu();
    }

    static void _showManageUsersMenu()
    {
        cout << "\n\tManage Users Menu will be here soon . . .\n";
        clsManageUsersScreen::showManageUsersMenu();
    }

    static void _showEndScreen()
    {
        cout << "\n\tEnd Screen Will be here . . .\n";
    }

    static void _performMainMenuOption(enMainMenuOptions option)
    {
        system("cls");
        switch (option)
        {
        case eListClients:
            _showAllClientsScreen();
            break;

        case eAddNewClient:
            _showAddNewClientScreen();
            break;

        case eDeleteClient:
            _showDeleteClientScreen();
            break;

        case eUpdateClient:
            _showUpdateClientScreen();
            break;

        case eFindClient:
            _showFindClientScreen();
            break;

        case eShowTransactionsMenu:
            _showTransactionsMenu();
            break;

        case eManageUsers:
            _showManageUsersMenu();
            break;

        case eExit:
            _showEndScreen();
            break;
        }
    }

public:
    static void showMainMenu()
    {
        enMainMenuOptions option;
        do
        {
            system("cls");
            _drawScreenHeader("Main Screen");

            cout << setw(37) << left << "" << string(60, '=') << endl;
            cout << setw(62) << left << "" << "Main Menu" << endl;
            cout << setw(37) << left << "" << string(60, '=') << endl;

            cout << setw(37) << left << "" << "\t[1] Show Client List." << endl;
            cout << setw(37) << left << "" << "\t[2] Add New Client." << endl;
            cout << setw(37) << left << "" << "\t[3] Delete Client." << endl;
            cout << setw(37) << left << "" << "\t[4] Update Client Info." << endl;
            cout << setw(37) << left << "" << "\t[5] Find Client." << endl;
            cout << setw(37) << left << "" << "\t[6] Transactions." << endl;
            cout << setw(37) << left << "" << "\t[7] Manage Users." << endl;
            cout << setw(37) << left << "" << "\t[8] Logout." << endl;
            cout << setw(37) << left << "" << string(60, '=') << endl;
            cout << setw(37) << left << "";

            option = _readMainMenuOption("choose what do you want to do? ");
            _performMainMenuOption(option);

            if (option != eExit && option != eShowTransactionsMenu && option != eManageUsers)
            {
                cout << endl;
                system("pause");
            }

        } while (option != eExit);
    }

}; // end line
