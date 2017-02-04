//
// Created by hudson on 21.1.2017 г..
//

#include "CFXDayData.h"
#include <sstream>

CFXDayData::CFXDayData() : CFXDayData(0, 0) { }

CFXDayData::CFXDayData(int dayOfMonth, double exchangeRate) {
    this->dayOfMonth = dayOfMonth;
    this->exchangeRate =exchangeRate;
}

CFXDayData::CFXDayData(const CFXDayData &copyObj) {
    this->exchangeRate = copyObj.exchangeRate;
    this->dayOfMonth = copyObj.dayOfMonth;
}

int CFXDayData::getDayOfMonth() {
    return this->dayOfMonth;
}

void CFXDayData::setDayOfMonth(int dayOfMonth) {
    this->dayOfMonth = dayOfMonth;
}

double CFXDayData::getExchangeRate() {
    return this->exchangeRate;
}

void CFXDayData::setExchangeRate(double exchangeRate) {
    this->exchangeRate = exchangeRate;
}

std::ostream& operator<<(std::ostream &out, const CFXDayData &obj) {
    out << "Day of Month: " << obj.dayOfMonth << ", Exchange rate: " << obj.exchangeRate << " GBP/USD" << std::endl;
    return out;
}

std::istream& operator>>(std::istream &in, CFXDayData &obj) {
    in >> obj.dayOfMonth;
    in >> obj.exchangeRate;
}

bool operator<(const CFXDayData &obj1, const CFXDayData &obj2) {
    return obj1.dayOfMonth < obj2.dayOfMonth;
}

double CFXDayData::operator+(const CFXDayData obj) {
    return this->exchangeRate + obj.exchangeRate;
}

double CFXDayData::operator-(const CFXDayData obj) {
    return this->exchangeRate - obj.exchangeRate;
}
