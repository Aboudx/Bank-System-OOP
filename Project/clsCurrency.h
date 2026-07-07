#pragma once
#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;

class clsCurrency
{
private:

	enum enMode { eEmptyMode = 0, eUpdateMode = 1 };
    enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

    static clsCurrency _ConvertLineRecordToCurrencyObject(string CurrencyLine)
    {
        vector<string>vCurrency = clsString::Split(CurrencyLine, "#//#");

        return clsCurrency(enMode::eUpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));
    }

    static vector<clsCurrency>_LoadCurrencyDataFromFile()
    {
        vector<clsCurrency>vCurrencies;

        fstream MyFile;

        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string sLine;

            while (getline(MyFile, sLine))
            {
                clsCurrency Currency = _ConvertLineRecordToCurrencyObject(sLine);
                vCurrencies.push_back(Currency);
            }
            MyFile.close();
            return vCurrencies;
        }
        return vCurrencies;
    }

    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {
        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.Country() + Seperator;
        stCurrencyRecord += Currency.CurrencyCode() + Seperator;
        stCurrencyRecord += Currency.CurrencyName() + Seperator;
        stCurrencyRecord += to_string(Currency.Rate());

        return stCurrencyRecord;

    }

    static void _SaveCurrencyDataToFile(vector<clsCurrency>& vCurrencies)
    {
        fstream MyFile;

        MyFile.open("Currencies.txt", ios::out);

        if (MyFile.is_open())
        {
            string CurrencyDataLine = "";
            for (clsCurrency& C : vCurrencies)
            {
                CurrencyDataLine = _ConverCurrencyObjectToLine(C);
                MyFile << CurrencyDataLine << endl;
            }

            MyFile.close();
        }

    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
    }

    void _Update()
    {
        vector<clsCurrency>_vCurrencies = _LoadCurrencyDataFromFile();

        for (clsCurrency& C : _vCurrencies)
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                break;  
            }
        }

        _SaveCurrencyDataToFile(_vCurrencies);
    }


public:
    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::eEmptyMode);
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    float Rate()
    {
        return _Rate;
    }

    static clsCurrency FindCurrencyByCode(string CurrencyCode)
    {
        fstream MyFile;

        vector<clsCurrency>vCurrencies;
        CurrencyCode = clsString::UpperAllString(CurrencyCode);
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string sLine;

            while (getline(MyFile, sLine))
            {
                clsCurrency Currency = _ConvertLineRecordToCurrencyObject(sLine);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }

        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindCurrencyByCountry(string CountryName)
    {
        CountryName = clsString::UpperAllString(CountryName);
        vector<clsCurrency>vCurrencies;

        fstream MyFile;

        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string sLine;

            while (getline(MyFile, sLine))
            {
                clsCurrency Currency = _ConvertLineRecordToCurrencyObject(sLine);
                if (clsString::UpperAllString(Currency.Country()) == CountryName)
                {
                    MyFile.close();
                    return Currency;
                }
            }
        }

        return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency Currency = FindCurrencyByCode(CurrencyCode);
        return (!Currency.IsEmpty());
    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencyDataFromFile();
    }

    float ConvertToUSD(float Amount)
    {
        return (float)(Amount / Rate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.CurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return (float)(AmountInUSD * Currency2.Rate());

    }
};
