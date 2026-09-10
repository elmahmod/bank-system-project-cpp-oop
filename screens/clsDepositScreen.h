#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../objects/clsBankClient.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsDepositScreen : protected clsScreen
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
    static void showDeposit()
    {
        _drawScreenHeader("Deposit Screen");

        string accountNumber = clsInputValidate::readString("Please enter Account Number: ");

        while (!clsBankClient::isClientExist(accountNumber))
        {
            accountNumber = clsInputValidate::readString("Client with Account Number [" + accountNumber + "] does not exists, enter another one: ");
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        _printClientData(client);

        double ammount = clsInputValidate::readDblNumber("Please enter deposit ammount: ");

        if (clsInputValidate::confirmAction("Are you sure you want to deposit this amount? [y-n]: "))
        {
            if (client.deposit(ammount))
            {
                cout << "\nAmount deposited successfully :)\n";
                cout << "New Balance is: " << client.getBalance() << endl;
            }
            else
            {
                cout << "\nInvalid deposit amount.\n";
            }
        }
        else
        {
            cout << "\nDeposit has been canceled.\n";
        }
    }
};