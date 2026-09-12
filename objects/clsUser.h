#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "../libraries/clsString.h"
#include "../libraries/clsInputValidate.h"
#include "../libraries/clsDate.h"
using namespace std;

class clsUser : public clsPerson
{

public:
    struct stLoginRegisterRecord
    {
        string dateTime;
        string username;
        string password;
        int permissions;
    };

private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode,
        AddNewMode
    };

    enMode _mode;
    string _username;
    string _password;
    int _permissions;
    bool _markedForDeletion = false;

    static clsUser _convertLineToUserObject(string line)
    {
        vector<string> vUserData = clsString::split(line, "#//#");
        return clsUser(UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
    }

    static string _convertUserObjectToLine(clsUser user, string separator = "#//#")
    {
        string line = "";
        line = user.getFirstName() + separator;
        line += user.getLastName() + separator;
        line += user.getEmail() + separator;
        line += user.getPhone() + separator;
        line += user.getUsername() + separator;
        line += user.getPassword() + separator;
        line += to_string(user.getPermissions());
        return line;
    }

    static stLoginRegisterRecord _convertLoginRegisterLineToRecord(string line)
    {
        stLoginRegisterRecord record;
        vector<string> loginRegisterDataLine = clsString::split(line, "#//#");

        record.dateTime = loginRegisterDataLine[0];
        record.username = loginRegisterDataLine[1];
        record.password = loginRegisterDataLine[2];
        record.permissions = stoi(loginRegisterDataLine[3]);

        return record;
    }

    void _addDataLineToFile(string dataLine)
    {
        ofstream file("files/users.txt", ios::app);

        if (file.is_open())
            file << dataLine << endl;
    }

    static vector<clsUser> _loadUsersDataFromFile()
    {
        vector<clsUser> vUsers;
        ifstream file("files/users.txt");

        if (file.is_open())
        {
            string line = "";
            while (getline(file, line))
            {
                if (line != "")
                    vUsers.push_back(_convertLineToUserObject(line));
            }
            file.close();
        }
        else
        {
            cout << "\nFile not found.\n";
        }

        return vUsers;
    }

    static void _saveUsersDataToFile(vector<clsUser> vUsers)
    {
        ofstream file("files/users.txt");

        if (file.is_open())
        {
            for (clsUser &user : vUsers)
            {
                if (!user._markedForDeletion)
                    file << _convertUserObjectToLine(user) << endl;
            }
        }
        else
        {
            cout << "\nFile not found.\n";
        }
    }

    void _addNew()
    {
        _addDataLineToFile(_convertUserObjectToLine(*this));
    }

    static clsUser _getEmptyUserObject()
    {
        return clsUser(EmptyMode, "", "", "", "", "", "", 0);
    }

    void _update()
    {
        vector<clsUser> vUsers = _loadUsersDataFromFile();

        for (clsUser &user : vUsers)
        {
            if (user._username == this->_username)
            {
                user = *this;
                _saveUsersDataToFile(vUsers);
                return;
            }
        }
    }

    string _getLoginRecordLine(string separator = "#//#")
    {
        string line = "";
        line += clsDate::getSystemDateTimeString() + separator;
        line += _username + separator;
        line += _password + separator;
        line += to_string(_permissions);
        return line;
    }

public:
    clsUser(enMode mode, string firstName, string lastName, string email, string phone, string username, string password, int permissions)
        : clsPerson(firstName, lastName, email, phone)
    {
        _mode = mode;
        _username = username;
        _password = password;
        _permissions = permissions;
    }

    // set
    // void setUsername(string username) { _username = username; }
    void setPassword(string password) { _password = password; }
    void setPermissions(int permissions) { _permissions = permissions; }

    // get
    string getUsername() { return _username; }
    string getPassword() { return _password; }
    int getPermissions() { return _permissions; }

    enum enPermissions
    {
        pListClient = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClient = 8,
        pFindClient = 16,
        pTransactions = 32,
        pManageUsers = 64,
        pALL = -1
    };

    static bool isUserExist(string username)
    {
        vector<clsUser> vUsers = _loadUsersDataFromFile();

        for (clsUser &user : vUsers)
        {
            if (user._username == username)
            {
                return true;
            }
        }
        return false;
    }

    static clsUser getAddUserObject(string username)
    {
        return clsUser(AddNewMode, "", "", "", "", username, "", 0);
    }

    static clsUser find(string username)
    {
        vector<clsUser> vUsers = _loadUsersDataFromFile();

        for (clsUser &user : vUsers)
        {
            if (user._username == username)
            {
                return user;
            }
        }
        return _getEmptyUserObject();
    }

    static clsUser find(string username, string password)
    {
        vector<clsUser> vUsers = _loadUsersDataFromFile();

        for (clsUser &user : vUsers)
        {
            if (user._username == username && user._password == password)
            {
                return user;
            }
        }
        return _getEmptyUserObject();
    }

    bool Delete()
    {
        vector<clsUser> vUsers = _loadUsersDataFromFile();

        for (clsUser &user : vUsers)
        {
            if (user._username == this->_username)
            {
                user._markedForDeletion = true;
                _saveUsersDataToFile(vUsers);

                *this = _getEmptyUserObject();
                return true;
            }
        }
        return false;
    }

    bool isEmpty()
    {
        return _mode == EmptyMode;
    }

    static vector<clsUser> getUsersList()
    {
        return _loadUsersDataFromFile();
    }

    enum enSaveResult
    {
        svFailed = 0,
        svSucceeded,
        svUserExist
    };

    enSaveResult save()
    {
        switch (_mode)
        {
        case EmptyMode:
            return svFailed;
        case UpdateMode:
        {
            _update();
            return svSucceeded;
        }
        case AddNewMode:
        {
            if (isUserExist(_username))
            {
                return svUserExist;
            }

            _addNew();
            _mode = UpdateMode;
            return svSucceeded;
        }
        }
        return svFailed;
    }

    bool hasPermissions(enPermissions permssions)
    {
        if (permssions == enPermissions::pALL)
            return true;

        return (permssions & _permissions) == permssions;
    }

    void loginRegister()
    {
        ofstream file("files/logins.txt", ios::app);

        if (file.is_open())
        {
            file << _getLoginRecordLine() << endl;
        }
    }

    static vector<stLoginRegisterRecord> getLoginRegisterList()
    {
        vector<stLoginRegisterRecord> vLoginRegisterRecords;
        ifstream file("files/logins.txt");

        if (file.is_open())
        {
            string line = "";
            while (getline(file, line))
            {
                vLoginRegisterRecords.push_back(_convertLoginRegisterLineToRecord(line));
            }
        }
        return vLoginRegisterRecords;
    }
};