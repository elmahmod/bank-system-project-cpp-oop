#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../objects/clsBankClient.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsTotalBalanceScreen : protected clsScreen
{
private:
    static void _printClientRecordLine(clsBankClient client)
    {
        cout << setw(8) << "" << "| "
             << left << setw(20) << client.getAccountNumber();
        cout << "| " << left << setw(25) << client.fullName();
        cout << "| " << left << setw(12) << client.getBalance();
    }

public:
    static void showTotalBalance()
    {
        vector<clsBankClient> vClients = clsBankClient::loadClientsDataFromFile();

        _drawScreenHeader("Total Balance Screen", "(" + to_string(vClients.size()) + ") Clients.");

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;

        cout << setw(8) << "" << "| " << left << setw(20) << "Account Number";
        cout << "| " << left << setw(25) << "Client Name";
        cout << "| " << left << setw(12) << "Balance" << endl;

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
        {
            for (clsBankClient &client : vClients)
            {
                _printClientRecordLine(client);
                cout << endl;
            }
        }

        cout << right << setw(115) << "Total Balance: " << clsBankClient::getTotalBalance() << endl;
        cout << setw(8) << "" << string(110, '_') << endl
             << endl;
    }
};
