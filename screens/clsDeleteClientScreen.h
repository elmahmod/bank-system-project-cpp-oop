#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../objects/clsBankClient.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
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
    static void showDeleteClientScreen()
    {
        _drawScreenHeader("Delete Screen");
        string accountNumber = clsInputValidate::readString("Please enter Account Number: ");

        while (!clsBankClient::isClientExist(accountNumber))
        {
            accountNumber = clsInputValidate::readString("Client with Account Number [" + accountNumber + "] already exists, enter another one: ");
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        _printClientData(client);

        if (clsInputValidate::confirmAction("do yo want to delete this client? [y-n]: "))
        {
            client.Delete();
            _printClientData(client);
        }
        else
        {
            cout << "\nDeletion has been canceled\n";
        }
    }
};