//
// Created by hudso on 4.2.2017 г..
//

#include "Checker.h"
#include <cstdlib>
#include <climits>
#include <stdexcept>

bool Checker::String2Int(const std::string &str, int &result) {
    char* endPtr = 0;
    errno = 0;

    const long longval = std::strtol(str.c_str(), &endPtr, 10);

    if ((longval == LONG_MIN || longval == LONG_MAX) && errno == ERANGE)
    {
        return false;
    }

    if (sizeof(long) > sizeof(int)) // let the optimizer do its job
    {
        if (longval > INT_MAX || longval < INT_MIN) // needed for example on linux x64
            return false;
    }

    result = static_cast<int>(longval);
    return endPtr == str.c_str() + str.size(); // ensure the whole string was parsed
}
