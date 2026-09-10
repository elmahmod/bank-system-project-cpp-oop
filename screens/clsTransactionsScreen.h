#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../objects/clsBankClient.h"
#include "../libraries/clsInputValidate.h"
#include "screens/clsDepositScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionsMenuOption
    {
        eDeposit = 1,
        eWithdraw,
        eShowTotalBalance,
        eBackToMainMenu
    };

    static enTransactionsMenuOption _readTransactionsMenuOption(const string &message)
    {
        int option = 0;
        option = clsInputValidate::readIntNumberBetween(1, 4, message);
        return static_cast<enTransactionsMenuOption>(option);
    }

    static void _showDepositScreen()
    {
        // cout << "\n\tDeposit Menu will be here soon . . .\n";
        clsDepositScreen::showDeposit();
    }

    static void _showWithdrawScreen()
    {
        cout << "\n\tWithdraw Menu will be here soon . . .\n";
    }

    static void _showTotalBalanceScreen()
    {
        cout << "\n\tTotal Balance Screen Will be here . . .\n";
    }

    static void _performTransactionsMenuOption(enTransactionsMenuOption option)
    {
        system("cls");

        switch (option)
        {
        case eDeposit:
            _showDepositScreen();
            break;

        case eWithdraw:
            _showWithdrawScreen();
            break;

        case eShowTotalBalance:
            _showTotalBalanceScreen();
            break;

        case eBackToMainMenu:
            break;
        }
    }

public:
    static void showTransactionsMenu()
    {

        enTransactionsMenuOption option;
        do
        {
            system("cls");
            _drawScreenHeader("Transactions Screen");

            cout << setw(37) << left << "" << string(60, '=') << endl;
            cout << setw(58) << left << "" << "Transactions Menu" << endl;
            cout << setw(37) << left << "" << string(60, '=') << endl;

            cout << setw(37) << left << "" << "\t[1] Deposit." << endl;
            cout << setw(37) << left << "" << "\t[2] Withdraw." << endl;
            cout << setw(37) << left << "" << "\t[3] Total Balance." << endl;
            cout << setw(37) << left << "" << "\t[4] Main Menu." << endl;
            cout << setw(37) << left << "" << string(60, '=') << endl;
            cout << setw(37) << left << "";

            option = _readTransactionsMenuOption("choose what do you want to do? ");
            _performTransactionsMenuOption(option);

            if (option != eBackToMainMenu)
                system("pause");

        } while (option != eBackToMainMenu);
    }
};