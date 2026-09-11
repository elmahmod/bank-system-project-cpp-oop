#pragma once
#include <iostream>
#include "../inheritance_screen/clsScreen.h"
#include "../objects/clsBankClient.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{
private:
    static void _printClientData(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.getFirstName();
        cout << "\nLastName    : " << client.getLastName();
        cout << "\nFull Name   : " << client.fullName();
        cout << "\nEmail       : " << client.getEmail();
        cout << "\nPhone       : " << client.getPhone();
        cout << "\nAcc. Number : " << client.getAccountNumber();
        cout << "\nPin Code    : " << client.getPinCode();
        cout << "\nBalance     : " << client.getBalance();
        cout << "\n___________________\n";
    }

public:
    static void showWithdraw()
    {
        _drawScreenHeader("Withdraw Screen");

        string accountNumber = clsInputValidate::readString("\nPlease enter Account Number: ");

        while (!clsBankClient::isClientExist(accountNumber))
        {
            accountNumber = clsInputValidate::readString("\nClient with Account Number [" + accountNumber + "] does not exist, enter another one: ");
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        _printClientData(client);

        double ammount = clsInputValidate::readDblNumber("\nPlease enter withdraw ammount: ");

        if (clsInputValidate::confirmAction("\nAre you sure you want to withdraw this ammount? [y-n]: "))
        {
            if (client.withdraw(ammount))
            {
                cout << "\nammount withdrawn successfully :)\n";
                cout << "New Balance is: " << client.getBalance() << endl;
            }
            else
            {
                cout << "\nInvalid withdraw ammount.\n";
                cout << "\nYour balance is: " << client.getBalance() << endl;
            }
        }
        else
        {
            cout << "\nWithdraw has been canceled.\n";
        }
    }
};