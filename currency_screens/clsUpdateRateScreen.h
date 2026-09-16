#pragma once
#include <iostream>
#include "../objects/clsCurrency.h"
#include "../inheritance_screen/clsScreen.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsUpdateRateScreen : protected clsScreen
{
private:
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

    static string _readCurrrencyCode(const string &message)
    {
        string currnecyCode = clsInputValidate::readString(message);

        while (!clsCurrency::isCurrencyExist(currnecyCode))
        {
            currnecyCode = clsInputValidate::readString(
                "\nCurrency with Code [" + currnecyCode +
                "] does not exist, enter another one: ");
        }

        return currnecyCode;
    }

public:
    static void showUpdateRate()
    {
        _drawScreenHeader("Update Rate Screen");

        clsCurrency currency = clsCurrency::findByCode(_readCurrrencyCode("\nPlease enter currency country: "));

        _printCurrency(currency);

        if (clsInputValidate::confirmAction("\nAre you sure you want to update the rate of this currency? (y/n): "))
        {
            float newRate = clsInputValidate::readDblNumber("Enter new Rate: ");
            while (newRate <= 0)
            {
                newRate = clsInputValidate::readDblNumber("Enter a valid Rate: ");
            }

            currency.updateRate(newRate);

            cout << "\nCurrency Rate updated successfully :)\n";
            _printCurrency(currency);
        }
    }
};