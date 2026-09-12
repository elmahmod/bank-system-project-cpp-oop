#pragma once
#include <iostream>
#include "../inheritance_screen/clsScreen.h"
#include "../objects/clsBankClient.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
    static void _printClientRecordLine(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << client.fullName();
        cout << "\nAcc. Number : " << client.getAccountNumber();
        cout << "\nBalance     : " << client.getBalance();
        cout << "\n___________________\n";
    }

    static bool _isValidTransferAmount(clsBankClient &client, double amount)
    {
        if (amount > client.getBalance())
        {
            cout << "\nAmount exceeds the available balance. " << endl;
            return false;
        }

        if (amount <= 0)
        {
            cout << "\nAmount must be greater than zero. " << endl;
            return false;
        }
        return true;
    }

    static double _readAmount(clsBankClient sourceClient)
    {
        double amount = clsInputValidate::readDblNumber("\nEnter transfer amount: ");
        while (!_isValidTransferAmount(sourceClient, amount))
        {
            amount = clsInputValidate::readDblNumber("Enter another amount: ");
        }
        return amount;
    }

    static string _readAccountNumber(string message)
    {
        string accountNumber = clsInputValidate::readString(message);

        while (!clsBankClient::isClientExist(accountNumber))
        {
            accountNumber = clsInputValidate::readString(
                "\nClient with Account Number [" + accountNumber +
                "] does not exist, enter another one: ");
        }

        return accountNumber;
    }

public:
    static void showTransfer()
    {
        _drawScreenHeader("Transfer Screen");

        clsBankClient sourceClient = clsBankClient::find(_readAccountNumber("\nPlease enter account number to transfer from: "));
        _printClientRecordLine(sourceClient);

        clsBankClient toClient = clsBankClient::find(_readAccountNumber("\nPlease enter account number to transfer to: "));
        _printClientRecordLine(toClient);

        if (sourceClient.getAccountNumber() == toClient.getAccountNumber())
        {
            cout << "\nYou cannot transfer money to the same account.\n";
            return;
        }

        double transferAmount = _readAmount(sourceClient);

        if (clsInputValidate::confirmAction("\nAre you sure you want to perform this operation? (y-n): "))
        {
            if (sourceClient.transfer(toClient, transferAmount))
            {
                cout << "\nTransfer done successfully :)\n";
                _printClientRecordLine(sourceClient);
                _printClientRecordLine(toClient);
            }
            else
            {
                cout << "\nTransfer has been canceled.\n";
            }
        }
    }
};