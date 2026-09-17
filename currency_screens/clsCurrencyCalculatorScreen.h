#pragma once
#include <iostream>
#include "../objects/clsCurrency.h"
#include "../inheritance_screen/clsScreen.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
    static void _printCurrency(clsCurrency currency)
    {
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
    static void showCurrencyCalculator()
    {
        do
        {
            system("cls");
            _drawScreenHeader("Currency Calculator Screen");

            clsCurrency currency1 = clsCurrency::findByCode(_readCurrrencyCode("\nPlease enter currency1 code: "));
            clsCurrency currency2 = clsCurrency::findByCode(_readCurrrencyCode("\nPlease enter currency2 code: "));

            float amount = clsInputValidate::readDblNumber("\nEnter amount to exchange: ");

            cout << "\nConvert From: \n";
            _printCurrency(currency1);
            cout << amount << " " << currency1.getCurrencyCode() << " = " << currency1.convertToUSD(amount) << " USD\n";

            if (currency2.getCurrencyCode() != "USD")
            {
                cout << "\nConvert from USD to: \n";
                _printCurrency(currency2);
                cout << amount << " " << currency1.getCurrencyCode() << " = " << currency1.convertToAnotherCurrency(amount, currency2) << " " << currency2.getCurrencyCode() << endl;
            }

        } while (clsInputValidate::confirmAction("\nDo you want to perform another calculation? y/n: "));
    }
};