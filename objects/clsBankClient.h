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
        UpdateMode,
        AddMode
    };
    enMode _mode;

    string _accountNumber, _pinCode;
    double _balance;
    bool _markedForDeletion = false;

    static clsBankClient _convertLineToClientObject(string line)
    {
        vector<string> vClientData = clsString::split(line, "#//#");
        return clsBankClient(UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static string _convertClientObjectToLine(clsBankClient client, string separator = "#//#")
    {
        string line = "";
        line = client.getFirstName() + separator;
        line += client.getLastName() + separator;
        line += client.getEmail() + separator;
        line += client.getPhone() + separator;
        line += client.getAccountNumber() + separator;
        line += client.getPinCode() + separator;
        line += to_string(client.getBalance());
        return line;
    }

    void _addDataLineToFile(string dataLine)
    {
        ofstream file("clients.txt", ios::app);

        if (file.is_open())
        {
            file << dataLine << endl;
            file.close();
        }
    }

    void _addNew()
    {
        _addDataLineToFile(_convertClientObjectToLine(*this));
    }

    static clsBankClient _getEmptyClientObj()
    {
        return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
    }

    static void _saveClientsDataToFile(vector<clsBankClient> vClients)
    {
        ofstream file("clients.txt");

        if (file.is_open())
        {
            for (clsBankClient &client : vClients)
            {
                if (!client._markedForDeletion)
                    file << _convertClientObjectToLine(client) << endl;
            }
            file.close();
        }
        else
        {
            cout << "\nFile not found.\n";
        }
    }

    void _update()
    {
        vector<clsBankClient> vClients = loadClientsDataFromFile();

        for (clsBankClient &client : vClients)
        {
            if (client._accountNumber == this->_accountNumber)
            {
                client = *this;
                _saveClientsDataToFile(vClients);
                return;
            }
        }
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
                if (line != "")
                    vClients.push_back(_convertLineToClientObject(line));
            }
            file.close();
        }
        else
        {
            cout << "\nFile not found.\n";
        }

        return vClients;
    }

    enum enSaveResult
    {
        svFailed = 0,
        svSucceeded,
        svClientExist
    };

    enSaveResult save()
    {
        switch (_mode)
        {
        case EmptyMode:
        {
            return svFailed;
        }
        case UpdateMode:
        {
            _update();
            return svSucceeded;
        }
        case AddMode:
        {
            if (isClientExist(_accountNumber))
            {
                return svClientExist;
            }
            _addNew();
            _mode = UpdateMode;
            return svSucceeded;
        }
        }
        return svFailed;
    }

    static bool isClientExist(string accountNumber)
    {
        vector<clsBankClient> vClients = loadClientsDataFromFile();

        for (clsBankClient &client : vClients)
        {
            if (client._accountNumber == accountNumber)
            {
                return true;
            }
        }
        return false;
    }

    static clsBankClient getAddClientObj(string accountNumber)
    {
        return clsBankClient(AddMode, "", "", "", "", accountNumber, "", 0);
    }

    static clsBankClient find(string accountNumber)
    {
        vector<clsBankClient> vClients = loadClientsDataFromFile();

        for (clsBankClient &client : vClients)
        {
            if (client._accountNumber == accountNumber)
            {
                return client;
            }
        }
        return _getEmptyClientObj();
    }

    bool Delete()
    {
        vector<clsBankClient> vClients = loadClientsDataFromFile();

        for (clsBankClient &client : vClients)
        {
            if (client._accountNumber == this->_accountNumber)
            {
                client._markedForDeletion = true;
                _saveClientsDataToFile(vClients);

                *this = _getEmptyClientObj();
                return true;
            }
        }
        return false;
    }

    bool isEmpty()
    {
        return _mode == EmptyMode;
    }

    bool deposit(double ammount)
    {
        if (ammount <= 0)
            return false;

        this->_balance += ammount;
        save();
        return true;
    }

    bool withdraw(double ammount)
    {
        if (ammount > this->_balance || ammount <= 0)
            return false;

        _balance -= ammount;
        save();
        return true;
    }

    static double getTotalBalance()
    {
        vector<clsBankClient> vClients = loadClientsDataFromFile();
        double totalBalance = 0;

        for (clsBankClient &client : vClients)
        {
            totalBalance += client._balance;
        }
        return totalBalance;
    }
};