#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../objects/clsBankClient.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
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

    static void _readNewClient(clsBankClient &client)
    {
        cout << endl;
        client.setFirstName(clsInputValidate::readString("Enter First Name: "));
        client.setLastName(clsInputValidate::readString("Enter Last Name: "));
        client.setEmail(clsInputValidate::readString("Enter Email: "));
        client.setPhone(clsInputValidate::readString("Enter Phone: "));
        client.setPinCode(clsInputValidate::readString("Enter Pin Code: "));
        client.setBalance(clsInputValidate::readDblNumber("Enter Balance: "));
    }

public:
    static void showAddNewClient()
    {
        _drawScreenHeader("Add Client Screen");
        
        string accountNumber = clsInputValidate::readString("\nPlease enter Account Number: ");

        while (clsBankClient::isClientExist(accountNumber))
        {
            accountNumber = clsInputValidate::readString("\nClient with Account Number [" + accountNumber + "] already exists, enter another one: ");
        }

        clsBankClient newClient = clsBankClient::getAddClientObj(accountNumber);
        _readNewClient(newClient);

        switch (newClient.save())
        {
        case clsBankClient::svFailed:
        {
            cout << "\nError, client was not saved, please try again.\n";
            break;
        }
        case clsBankClient::svSucceeded:
        {
            cout << "\nClient added successfully :)\n";
            _printClientData(newClient);
            break;
        }
        case clsBankClient::svClientExist:
        {
            cout << "\nError, a client with Account Number [" << accountNumber << "] already exists.\n";
            break;
        }
        }
    }
};