#pragma once
#include <iostream>
#include <string>
using namespace std;

struct stTransferLog
{
    string sDateTime;
    string sSourceAccountNumber;
    string sDecAccountNumber;
    double sAmount;
    double sSourceBalance;
    double sDecBalance;
    string sUserName;
};