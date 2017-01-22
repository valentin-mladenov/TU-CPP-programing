//
// Created by hudson on 21.1.2017 г..
//

#ifndef CURRENCYEXCHANGE_CFXDAYDATA_H
#define CURRENCYEXCHANGE_CFXDAYDATA_H

#pragma once
#include <string>
#include <cassert>

class CFXDayData {
private:
    int dayOfMonth;
    double exchangeRate;

public:
    // Constructors
    CFXDayData();
    CFXDayData(int dayOfMonth, double exchangeRate);
    CFXDayData(const CFXDayData &copyObj);

    // Member Functions
    int getDayOfMonth();
    void setDayOfMonth(int dayOfMonth);

    double getExchangeRate();
    void setExchangeRate(double exchangeRate);

    //Operator Overload
    friend bool operator< (const CFXDayData &obj1, const CFXDayData &obj2);
    double operator+(const CFXDayData obj1);
    double operator-(const CFXDayData obj1);
    friend std::ostream& operator<<(std::ostream &out, const CFXDayData &obj);
    friend std::istream& operator>>(std::istream &in, CFXDayData &obj);
};


#endif //CURRENCYEXCHANGE_CFXDAYDATA_H
