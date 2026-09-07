#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
private:
    string _firstName, _lastName, _email, _phone;

public:
    clsPerson(string firstName, string lastName, string email, string phone)
    {
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phone = phone;
    }

    string fullName()
    {
        return _firstName + " " + _lastName;
    }

    // set
    void setFirstName(string firstName) { _firstName = firstName; }
    void setLastName(string lastName) { _lastName = lastName; }
    void setEmail(string email) { _email = email; }
    void setPhone(string phone) { _phone = phone; }

    // get
    string getFirstName() { return _firstName; }
    string getLastName() { return _lastName; }
    string getEmail() { return _email; }
    string getPhone() { return _phone; }
};