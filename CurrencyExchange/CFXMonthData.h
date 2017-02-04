//
// Created by hudso on 21.1.2017 г..
//

#ifndef CURRENCYEXCHANGE_CFXMONTHDATA_H
#define CURRENCYEXCHANGE_CFXMONTHDATA_H

#pragma once
#include <string>
#include <cassert>
#include <vector>

#include "CFXDayData.h"

class CFXMonthData {
private:
    std::string monthName;
    std::vector<CFXDayData> exchangeRates = std::vector<CFXDayData>();

public:
    // Constructors
    CFXMonthData(std::string fileName);
    CFXMonthData(std::vector<CFXDayData> exchangeRates);

    // Member Functions
    std::string getMonthName();
    void setMonthName(std::string monthName);
    CFXMonthData differenceInRatesDayToDay();
    double differenceOfRatesMonthly(double coefficient);

    //Operator Overload
    friend std::ostream& operator<<(std::ostream &out, const CFXMonthData &obj);
    friend std::istream& operator>>(std::istream &in, CFXMonthData &obj);
};


#endif //CURRENCYEXCHANGE_CFXMONTHDATA_H
