#pragma once
#include <iostream>
#include <limits>
using namespace std;

class clsInputValidate
{
private:
public:
    // is number between
    template <typename T>
    static bool isNumberBetween(T target, T from, T to)
    {
        return target >= from && target <= to;
    }

    // read double, integer number
    static int readIntNumber(const string &message)
    {
        int number = 0;
        cout << message;
        cin >> number;

        while (cin.fail())
        {
            cout << "Invalid input, Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> number;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return number;
    }

    static double readDblNumber(const string &message)
    {
        double number = 0;
        cout << message;
        cin >> number;

        while (cin.fail())
        {
            cout << "Invalid input, Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> number;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return number;
    }

    // read integer, double number between
    static int readIntNumberBetween(int from, int to, const string &message)
    {
        int number = readIntNumber(message);
        while (number < from || number > to)
        {
            number = readIntNumber("Number isn't within range, Enter again: ");
        }
        return number;
    }

    static double readDblNumberBetween(double from, double to, const string &message)
    {
        double number = readDblNumber(message);
        while (!isNumberBetween(number, from, to))
        {
            number = readDblNumber("Number isn't within range, Enter again: ");
        }
        return number;
    }

    // read string
    static string readString(const string &message)
    {
        string s;
        cout << message;
        getline(cin >> ws, s);
        return s;
    }

    static bool confirmAction(const string &message)
    {
        char answer;

        do
        {
            cout << message;
            answer = cin.get();
            answer = tolower(answer);

            if (answer != '\n')
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (answer != 'y' && answer != 'n' && answer != '\n');

        return answer == 'y' || answer == '\n';
    }
};
