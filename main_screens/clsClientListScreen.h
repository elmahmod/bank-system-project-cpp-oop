#pragma once
#include <iostream>
#include "../inheritance_screen/clsScreen.h"
#include "../objects/clsBankClient.h"
using namespace std;

class clsClientListScreen : protected clsScreen
{
private:
    static void _printClientRecordLine(clsBankClient client)
    {
        cout << setw(8) << "" << "| "
             << left << setw(20) << client.getAccountNumber();
        cout << "| " << left << setw(20) << client.fullName();
        cout << "| " << left << setw(15) << client.getPhone();
        cout << "| " << left << setw(20) << client.getEmail();
        cout << "| " << left << setw(12) << client.getPinCode();
        cout << "| " << left << setw(12) << client.getBalance();
    }

public:
    static void showClientList()
    {
        vector<clsBankClient> vClients = clsBankClient::loadClientsDataFromFile();

        _drawScreenHeader("Client List Screen", "(" + to_string(vClients.size()) + ") Clients.");

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;

        cout << setw(8) << "" << "| " << left << setw(20) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(15) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance" << endl;

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!\n";
        else
        {
            for (clsBankClient &client : vClients)
            {
                _printClientRecordLine(client);
                cout << endl;
            }
        }

        cout << setw(8) << "" << string(110, '_') << endl
             << endl;
    }

};