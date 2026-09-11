#pragma once
#include <iostream>
#include "../inheritance_screen/clsScreen.h"
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
        string accountNumber = clsInputValidate::readString("\nPlease enter Account Number: ");

        while (!clsBankClient::isClientExist(accountNumber))
        {
            accountNumber = clsInputValidate::readString("\nClient with Account Number [" + accountNumber + "] does not exist, enter another one: ");
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        _printClientData(client);

        if (clsInputValidate::confirmAction("\nDo you want to delete this client? [y-n]: "))
        {
            if (client.Delete())
            {
                cout << "\nClient deleted successfully.\n";
                _printClientData(client);
            }
            else
                cout << "\nError: Client was not deleted.\n";
        }
        else
        {
            cout << "\nDeletion has been canceled\n";
        }
    }
};