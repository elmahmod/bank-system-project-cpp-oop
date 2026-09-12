#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class clsScreen
{
protected:
    static void _drawScreenHeader(string title, string subTitle = "")
    {
        cout << setw(54) << left << "" << string(25, '_') << endl << endl;
        cout << setw(37 + (60 - title.length()) / 2) << left << "" << title << endl;

        if (subTitle != "")
            cout << setw(60) << left << "" << subTitle << endl;

        cout << setw(54) << left << "" << string(25, '_') << endl << endl;
    }

    
};
