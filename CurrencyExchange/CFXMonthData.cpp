//
// Created by hudso on 21.1.2017 г..
//

#include "CFXMonthData.h"
#include <iostream>     // std::cerr
#include <fstream>      // std::ifstream
#include <stdlib.h>
#include <cstdlib>
#include <sstream>

CFXMonthData::CFXMonthData(std::string fileName) {
    std::ifstream file;
    std::string line;
    file.exceptions (std::ifstream::badbit);

    // Opening a file in constructor is almost certainly a bad idea.
    // Very few cases when opening a file during construction is appropriate.
    file.open(fileName);
    if (!file) {
        file.close();
        throw std::ifstream::failure("File not found!!!");
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        file.close();
        throw std::ifstream::failure("File is empty!!!");
    }

    while (!file.eof() && getline(file, line)) {
        if (!line.empty()){
            std::string monthDelimiter = ":";
            int foundMonthDelimiter = line.find(monthDelimiter);

            if (foundMonthDelimiter == -1) {
                file.close();
                throw std::ifstream::failure("No month name in file!!!");
            }

            this->monthName = line.substr(0, foundMonthDelimiter);

            std::string dateExchanges = line.substr(++foundMonthDelimiter, line.length());

            std::string dateDelimiter = ",";
            unsigned int pos = 0;

            if(dateExchanges.empty()) {
                file.close();
                throw std::ifstream::failure("No exchange rate data!!!");
            }

            while (true) {
                char* pEnd;

                pos = (dateExchanges.find(dateDelimiter) == -1)
                        ? dateExchanges.length()
                        : dateExchanges.find(dateDelimiter);

                std::string currentDate = dateExchanges.substr(0, pos);

                std::string dataDelimiter = " ";
                unsigned int currentDateDelimiter = currentDate.find(dataDelimiter);

                std::string dateString = currentDate.substr(0, currentDateDelimiter);

                int date = (int) std::strtod(dateString.c_str(), &pEnd);

                if (dateString.find_first_not_of("0123456789") != std::string::npos) {
                    dateExchanges.erase(0, (++pos));
                    printf("fail - the following characters are not part of a int: %s\n", dateString.c_str());
                    continue;
                }

                std::string exchangeString = currentDate.substr(++currentDateDelimiter, currentDate.length());

                double exchangeRate = std::strtod(exchangeString.c_str(), &pEnd);

                if (exchangeString.find_first_not_of("0123456789.") != std::string::npos) {
                    dateExchanges.erase(0, (++pos));
                    printf("fail - the following characters are not part of a double: %s\n", exchangeString.c_str());
                    continue;
                }

                this->exchangeRates.push_back(CFXDayData(date, exchangeRate));

                if (pos == dateExchanges.length()) break;

                dateExchanges.erase(0, (++pos));
            }
        }
    }

    file.close();
}

CFXMonthData::CFXMonthData(std::vector<CFXDayData> exchangeRates) {
    this->exchangeRates = exchangeRates;
}

std::string CFXMonthData::getMonthName() {
    return this->monthName;
}

void CFXMonthData::setMonthName(std::string monthName) {
    this->monthName = monthName;
}

double CFXMonthData::differenceOfRatesMonthly(double coefficient) {
    double out = 0;

    CFXMonthData differenceDayToDay = this->differenceInRatesDayToDay();

    for (CFXDayData difference: differenceDayToDay.exchangeRates) {
        out += difference.getExchangeRate();
    }

    return out * coefficient;
}

CFXMonthData CFXMonthData::differenceInRatesDayToDay() {
    std::vector<CFXDayData> out = std::vector<CFXDayData>();

    for(std::vector<CFXDayData>::size_type i = 1; i != this->exchangeRates.size(); i++) {

        int previous = i;

        double difference = this->exchangeRates[i].operator-(this->exchangeRates[--previous]);

        out.push_back(CFXDayData(this->exchangeRates[i].getDayOfMonth(), difference));
    }

    return CFXMonthData(out);
}

std::ostream& operator<< (std::ostream &out, const CFXMonthData &obj){
    out << "Month: " << obj.monthName << std::endl;

    for(std::vector<CFXDayData>::size_type i = 0; i != obj.exchangeRates.size(); i++) {
        out << obj.exchangeRates[i];
    }

    return out;
}

std::istream& operator>> (std::istream &in, CFXMonthData &obj){
    std::string fileName;

    in >> fileName;

    obj = CFXMonthData(fileName);
}

