#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:
    string _value;

    // invert letter case
    static char inverLetterCase(char letter)
    {
        return isupper(letter) ? tolower(letter) : toupper(letter);
    }

    static bool isVowel(char letter)
    {
        letter = tolower(letter);

        return (letter == 'a') ||
               (letter == 'e') ||
               (letter == 'i') ||
               (letter == 'o') ||
               (letter == 'u');
    }

public:

    clsString()
    {
        _value = "";
    }

    clsString(string value)
    {
        _value = value;
    }

    // set
    void setValue(string value)
    {
        _value = value;
    }

    // get
    string getValue()
    {
        return _value;
    }

    // count words
    static int countWords(string text)
    {
        int counter = 0;
        string word;
        size_t pos;
        string delimiter = " ";

        while ((pos = text.find(delimiter)) != string::npos)
        {
            word = text.substr(0, pos);

            if (!word.empty())
                counter++;

            text.erase(0, pos + delimiter.length());
        }

        if (!text.empty())
            counter++;

        return counter;
    }

    int countWords()
    {
        return countWords(_value);
    }

    // count small letters
    static int countSmallLetters(string text)
    {
        int counter = 0;

        for (int i = 0; i < text.length(); i++)
        {
            if (islower(text[i]))
                counter++;
        }

        return counter;
    }

    int countSmallLetters()
    {
        return countSmallLetters(_value);
    }

    // count capital letters
    static int countCapitalLetters(string text)
    {
        int counter = 0;

        for (int i = 0; i < text.length(); i++)
        {
            if (isupper(text[i]))
                counter++;
        }

        return counter;
    }

    int countCapitalLetters()
    {
        return countCapitalLetters(_value);
    }

    // count specific letter
    static int countTargetLetters(string text, char target)
    {
        int counter = 0;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == target)
                counter++;
        }

        return counter;
    }

    int countTargetLetters(char target)
    {
        return countTargetLetters(_value, target);
    }

    // count vowels
    static int countVowels(string text)
    {
        int counter = 0;

        for (int i = 0; i < text.length(); i++)
        {
            if (isVowel(text[i]))
                counter++;
        }

        return counter;
    }

    int countVowels()
    {
        return countVowels(_value);
    }

    // length
    static int length(string text)
    {
        return text.length();
    }

    int length()
    {
        return length(_value);
    }

    // upper first letter of each word
    static string upperFirstLetterOfEachWord(string text)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ' ' && isFirstLetter)
            {
                text[i] = toupper(text[i]);
            }

            isFirstLetter = (text[i] == ' ') ? true : false;
        }

        return text;
    }

    void upperFirstLetterOfEachWord()
    {
        _value = upperFirstLetterOfEachWord(_value);
    }

    // lower first letter of each word
    static string lowerFirstLetterOfEachWord(string text)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ' ' && isFirstLetter)
            {
                text[i] = tolower(text[i]);
            }

            isFirstLetter = (text[i] == ' ') ? true : false;
        }

        return text;
    }

    void lowerFirstLetterOfEachWord()
    {
        _value = lowerFirstLetterOfEachWord(_value);
    }

    // upper all string
    static string upperAllString(string text)
    {
        for (int i = 0; i < text.length(); i++)
        {
            text[i] = toupper(text[i]);
        }

        return text;
    }

    void upperAllString()
    {
        _value = upperAllString(_value);
    }

    // lower all string
    static string lowerAllString(string text)
    {
        for (int i = 0; i < text.length(); i++)
        {
            text[i] = tolower(text[i]);
        }

        return text;
    }

    void lowerAllString()
    {
        _value = lowerAllString(_value);
    }

    // invert all letters case
    static string invertAllLettersCase(string text)
    {
        for (int i = 0; i < text.length(); i++)
        {
            text[i] = inverLetterCase(text[i]);
        }

        return text;
    }

    void invertAllLettersCase()
    {
        _value = invertAllLettersCase(_value);
    }

    // split
    static vector<string> split(string text, string delimiter)
    {
        vector<string> vTokens;
        string word;
        size_t pos;

        while ((pos = text.find(delimiter)) != string::npos)
        {
            word = text.substr(0, pos);

            if (!word.empty())
                vTokens.push_back(word);

            text.erase(0, pos + delimiter.length());
        }

        if (!text.empty())
            vTokens.push_back(text);

        return vTokens;
    }

    vector<string> split(string delimiter)
    {
        return split(_value, delimiter);
    }

    // trim left
    static string trimLeft(string text)
    {
        string trimmed;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ' ')
            {
                trimmed = text.substr(i);
                break;
            }
        }

        return trimmed;
    }

    void trimLeft()
    {
        _value = trimLeft(_value);
    }

    // trim right
    static string trimRight(string text)
    {
        string trimmed;

        for (int i = text.length() - 1; i >= 0; i--)
        {
            if (text[i] != ' ')
            {
                trimmed = text.substr(0, i + 1);
                break;
            }
        }

        return trimmed;
    }

    void trimRight()
    {
        _value = trimRight(_value);
    }

    // trim
    static string trim(string text)
    {
        return trimLeft(trimRight(text));
    }

    void trim()
    {
        _value = trim(_value);
    }

    // join string
    static string join(const vector<string>& vTokens, string delimiter)
    {
        string text;

        for (const string& token : vTokens)
        {
            text += token + delimiter;
        }

        if (!text.empty())
            text = text.substr(0, text.length() - delimiter.length());

        return text;
    }

    // reverse string
    static string reverseString(string text)
    {
        vector<string> vTokens = split(text, " ");
        string reversedText = "";

        vector<string>::iterator iter = vTokens.end();

        while (iter != vTokens.begin())
        {
            --iter;

            reversedText += *iter + " ";
        }

        if (!reversedText.empty())
            reversedText = reversedText.substr(0, reversedText.length() - 1);

        return reversedText;
    }

    void reverseString()
    {
        _value = reverseString(_value);
    }

    // replace word
    static string replaceWord(string text, string word, string replaceTo)
    {
        vector<string> vTokens = split(text, " ");

        for (string& s : vTokens)
        {
            if (s == word)
                s = replaceTo;
        }

        return join(vTokens, " ");
    }

    void replaceWord(string word, string replaceTo)
    {
        _value = replaceWord(_value, word, replaceTo);
    }

    // remove punctuations
    static string removePunctuations(string text)
    {
        string rp;

        for (int i = 0; i < text.length(); i++)
        {
            if (!ispunct(text[i]))
                rp += text[i];
        }

        return rp;
    }

    void removePunctuations()
    {
        _value = removePunctuations(_value);
    }
};