#pragma once
#include <iostream>
#include "../inheritance_screen/clsScreen.h"
#include "../objects/clsBankClient.h"
#include "../libraries/clsInputValidate.h"
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:
    static void _printTransferLogRecordLine(clsBankClient::stTransferRegisterRecord transferLog)
    {
        cout << setw(8) << "" << "| "
             << left << setw(23) << transferLog.dateTime;
        cout << "| " << left << setw(12) << transferLog.sourceAccNumber;
        cout << "| " << left << setw(12) << transferLog.destinationAccNumber;
        cout << "| " << left << setw(12) << transferLog.transferAmount;
        cout << "| " << left << setw(12) << transferLog.srcBalanceAfter;
        cout << "| " << left << setw(12) << transferLog.srcBalanceBefore;
        cout << "| " << left << setw(15) << transferLog.username;
    }

public:
    static void showTransferLog()
    {
        vector<clsBankClient::stTransferRegisterRecord> vTransferLogRecords =
            clsBankClient::getTransferRegisterList();

        _drawScreenHeader(
            "Transfer Log List Screen",
            "(" + to_string(vTransferLogRecords.size()) + ") Records."
        );

        cout << setw(8) << "" << string(115, '_') << endl
             << endl;

        cout << setw(8) << "" << "| "
             << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(12) << "s.Acct";
        cout << "| " << left << setw(12) << "d.Acct";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(12) << "s.Balance";
        cout << "| " << left << setw(12) << "s.Before";
        cout << "| " << left << setw(15) << "User" << endl;

        cout << setw(8) << "" << string(115, '_') << endl
             << endl;

        if (vTransferLogRecords.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!\n";
        else
        {
            for (clsBankClient::stTransferRegisterRecord &record : vTransferLogRecords)
            {
                _printTransferLogRecordLine(record);
                cout << endl;
            }
        }

        cout << setw(8) << "" << string(115, '_') << endl
             << endl;
    }
};