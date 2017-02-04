//
// Created by hudso on 4.2.2017 г..
//

#ifndef CURRENCYEXCHANGE_CHECKER_H
#define CURRENCYEXCHANGE_CHECKER_H

#include <string>

class Checker {
public:
    static bool String2Int(const std::string& str, int& result);

private:
    // Disallow creating an instance of this object
    Checker() {}
};


#endif //CURRENCYEXCHANGE_CHECKER_H
