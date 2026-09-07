#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "../libraries/clsString.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode
    };
    enMode _mode;

    string _accountNumber, _pinCode;
    double _balance;

    static clsBankClient _convertLineToClientObject(string line)
    {
        vector<string> vClientData = clsString::split(line, "#//#");
        return clsBankClient(UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

public:
    clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, double balance)
        : clsPerson(firstName, lastName, email, phone)
    {
        _mode = mode;
        _accountNumber = accountNumber;
        _pinCode = pinCode;
        _balance = balance;
    }

    // set
    void setPinCode(string pinCode) { _pinCode = pinCode; }
    void setBalance(double balance) { _balance = balance; }

    // get
    string getAccountNumber() { return _accountNumber; } // read only
    string getPinCode() { return _pinCode; }
    double getBalance() { return _balance; }

    static vector<clsBankClient> loadClientsDataFromFile()
    {
        vector<clsBankClient> vClients;
        ifstream file("clients.txt");

        if (file.is_open())
        {
            string line = "";
            while (getline(file, line))
            {
                vClients.push_back(_convertLineToClientObject(line));
            }
            file.close();
        }
        else
        {
            cout << "\nFile not founded\n";
        }

        return vClients;
    }

    
};