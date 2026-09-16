#pragma once
#include <iostream>
#include "../objects/clsCurrency.h"
#include "../inheritance_screen/clsScreen.h"
using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
private:
    static void _printCurrencyRecordLine(clsCurrency currency)
    {
        cout << setw(8) << "" << "| "
             << left << setw(30) << currency.getCountry();
        cout << "| " << left << setw(12) << currency.getCurrencyCode();
        cout << "| " << left << setw(45) << currency.getCurrencyName();
        cout << "| " << left << setw(12) << currency.getRate();
    }

public:
    static void showCurrenciesList()
    {
        vector<clsCurrency> vCurrencies = clsCurrency::getCurrencyList();

        _drawScreenHeader("Currency List Screen", "(" + to_string(vCurrencies.size()) + ") Currencies.");

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;

        cout << setw(8) << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(12) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(12) << "Rate/(1$)\n";

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!\n";
        else
        {
            for (clsCurrency &currency : vCurrencies)
            {
                _printCurrencyRecordLine(currency);
                cout << endl;
            }
        }

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;
    }
};