#pragma once
#include <iostream>
using namespace std;

class clsScreen
{
protected:
    static void _drawScreenHeader(string title, string subTitle = "")
    {
        cout << setw(37) << left << "" << string(60, '_') << endl << endl;
        cout << setw(37 + (60 - title.length()) / 2) << left << "" << title << endl;

        if (subTitle != "")
            cout << setw(37) << left << "" << subTitle << endl;

        cout << setw(37) << left << "" << string(60, '_') << endl << endl;
    }
};
