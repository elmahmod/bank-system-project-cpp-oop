#pragma once
#include <iostream>
#include "../inheritance_screen/clsScreen.h"
#include "../objects/clsCurrency.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
using namespace std;

class clsCurrencyScreen : protected clsScreen
{
private:
    enum enCurrencyMenuOption
    {
        eListCurrencies = 1,
        eFindCurrency,
        eUpdateRate,
        eCurrencyCalculator,
        eBackToMainMenu
    };

    static enCurrencyMenuOption _readCurrencyMenuOption(const string &message)
    {
        int option = clsInputValidate::readIntNumberBetween(1, 5, message);
        return static_cast<enCurrencyMenuOption>(option);
    }

    static void _showAllCurrenciesScreen()
    {
        clsCurrenciesListScreen::showCurrenciesList();
    }

    static void _showFindCurrencyScreen()
    {
    }

    static void _showUpdateRateScreen()
    {
    }

    static void _showCurrencyCalculatorScreen()
    {
    }

    static void _performMainMenuOption(enCurrencyMenuOption option)
    {
        system("cls");

        switch (option)
        {
        case eListCurrencies:
            _showAllCurrenciesScreen();
            break;

        case eFindCurrency:
            _showFindCurrencyScreen();
            break;

        case eUpdateRate:
            _showUpdateRateScreen();
            break;

        case eCurrencyCalculator:
            _showCurrencyCalculatorScreen();
            break;

        case eBackToMainMenu:
            break;
        }
    }

public:
    static void showCurrency()
    {
        enCurrencyMenuOption option;
        do
        {
            system("cls");
            _drawScreenHeader("Currency Screen");

            cout << setw(37) << left << "" << string(60, '=') << endl;
            cout << setw(62) << left << "" << "Currency Menu" << endl;
            cout << setw(37) << left << "" << string(60, '=') << endl;

            cout << setw(37) << left << "" << "\t[1] Show Currencies List." << endl;
            cout << setw(37) << left << "" << "\t[2] Find Currency." << endl;
            cout << setw(37) << left << "" << "\t[3] Update Rate." << endl;
            cout << setw(37) << left << "" << "\t[4] Currency Calculator." << endl;
            cout << setw(37) << left << "" << "\t[5] Main Menu." << endl;
            cout << setw(37) << left << "" << string(60, '=') << endl;
            cout << setw(37) << left << "";

            option = _readCurrencyMenuOption("choose what do you want to do? ");
            _performMainMenuOption(option);

            if (option != eBackToMainMenu)
            {
                cout << endl;
                system("pause");
            }

        } while (option != eBackToMainMenu);
    }
};
