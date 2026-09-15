#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../libraries/clsString.h"
using namespace std;

class clsCurrency
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1
    };

    enMode _mode;
    string _country;
    string _currencyName;
    string _currencyCode;
    float _rate;

    static clsCurrency _convertLineToCurrencyObject(string line)
    {
        vector<string> vData = clsString::split(line, "#//#");

        return clsCurrency(UpdateMode, vData[0], vData[1], vData[2], stof(vData[3]));
    }

    static vector<clsCurrency> _loadCurennciesDataFromFile()
    {
        vector<clsCurrency> vCurrencyData;
        ifstream file("files/currencies.txt");

        if (file.is_open())
        {
            string line = "";

            while (getline(file, line))
            {
                vCurrencyData.push_back(_convertLineToCurrencyObject(line));
            }
        }
        return vCurrencyData;
    }

    string _convertCurrencyObjectToLine(clsCurrency currency, string separator = "#//#")
    {
        string dataLine = "";
        dataLine += currency.getCountry() + separator;
        dataLine += currency.getCurrencyCode() + separator;
        dataLine += currency.getCurrencyName() + separator;
        dataLine += to_string(currency.getRate());

        return dataLine;
    }

    void _saveCurrencyDataToFile(vector<clsCurrency> vCurrencies)
    {
        ofstream file("files/currencies.txt");

        if (file.is_open())
        {
            for (clsCurrency &currency : vCurrencies)
            {
                file << _convertCurrencyObjectToLine(currency) << endl;
            }
        }
    }

    void _update()
    {
        vector<clsCurrency> vCurrencies = _loadCurennciesDataFromFile();

        for (clsCurrency &currency : vCurrencies)
        {
            if (currency.getCurrencyCode() == getCurrencyCode())
            {
                currency = *this;
                break;
            }
        }

        _saveCurrencyDataToFile(vCurrencies);
    }

    static clsCurrency _getEmptyCurrencyObject()
    {
        return clsCurrency(EmptyMode, "", "", "", 0);
    }

public:
    clsCurrency(enMode mode, string country, string currencyCode, string currencyName, float rate)
    {
        _mode = mode;
        _country = country;
        _currencyName = currencyName;
        _currencyCode = currencyCode;
        _rate = rate;
    }

    void setRate(float rate) { _rate = rate; }
    float getRate() { return _rate; }

    // read-only
    string getCurrencyName() { return _currencyName; }
    string getCurrencyCode() { return _currencyCode; }
    string getCountry() { return _country; }

    void updateRate(float rate)
    {
        setRate(rate);
        _update();
    }

    static clsCurrency findByCode(string currencyCode)
    {
        vector<clsCurrency> vCurrencies = _loadCurennciesDataFromFile();

        currencyCode = clsString::upperAllString(currencyCode);

        for (clsCurrency &currency : vCurrencies)
        {
            if (clsString::upperAllString(currency.getCurrencyCode()) == currencyCode)
            {
                return currency;
            }
        }

        return _getEmptyCurrencyObject();
    }

    static clsCurrency findByCountry(string currencyCountry)
    {
        vector<clsCurrency> vCurrencies = _loadCurennciesDataFromFile();

        currencyCountry = clsString::upperAllString(currencyCountry);

        for (clsCurrency &currency : vCurrencies)
        {
            if (clsString::upperAllString(currency.getCountry()) == currencyCountry)
            {
                return currency;
            }
        }

        return _getEmptyCurrencyObject();
    }

    bool isEmpty()
    {
        return _mode == EmptyMode;
    }

    static bool isCurrencyExist(string currencyCode)
    {
        clsCurrency currency = findByCode(currencyCode);
        return !currency.isEmpty();
    }

    static vector<clsCurrency> getCurrencyList()
    {
        return _loadCurennciesDataFromFile();
    }
};