#pragma once
#include <iostream>
#include "../objects/clsCurrency.h"
#include "../inheritance_screen/clsScreen.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:
    enum enFindType
    {
        Code = 1,
        Country = 2
    };

    static enFindType _readFindTypeOption(const string &message)
    {
        int option = 0;
        clsInputValidate::readIntNumberBetween(1, 2, message);
        return static_cast<enFindType>(option);
    }

    static void _printCurrency(clsCurrency currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << currency.getCountry();
        cout << "\nCode       : " << currency.getCurrencyCode();
        cout << "\nName       : " << currency.getCurrencyName();
        cout << "\nRate(1$) = : " << currency.getRate();

        cout << "\n_____________________________\n";
    }

    static void _showResult(clsCurrency currency)
    {
        if (!currency.isEmpty())
        {
            cout << "\nCurrency Found\n";
            _printCurrency(currency);
        }
        else
        {
            cout << "\nCurrency not found\n";
        }
    }

public:
    static void showFindCurrency()
    {
        _drawScreenHeader("Find Screen");

        enFindType option = _readFindTypeOption("\nFind By: [1] Code or [2] Country: ");

        if (option == enFindType::Country)
        {
            clsCurrency currency = clsCurrency::findByCountry(clsInputValidate::readString("\nPlease enter currency country: "));
            _showResult(currency);
        }
        else
        {
            clsCurrency currency = clsCurrency::findByCode(clsInputValidate::readString("\nPlease enter currency code: "));
            _showResult(currency);
        }
    }
};