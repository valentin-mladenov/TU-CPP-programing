#include <iostream>
#include <fstream>
#include "CFXMonthData.h"

using namespace std;

int main() {
    try {
        // III.1
        // C:\Users\hudso\OneDrive\Documents\GitHub\TU-CPP-programing\CurrencyExchange\february.txt
        string fileName;
        cout << "Full path of file:" << endl;
        cin >> fileName;

        CFXMonthData fromFile = CFXMonthData(fileName);

        // III.2
        cout << fromFile;

        // III.3
        CFXMonthData differenceDayToDay = fromFile.differenceInRatesDayToDay();

        // III.4
        cout << differenceDayToDay;

        // III.5
        double differenceMonthly = fromFile.differenceOfRatesMonhtly(1);
        cout << differenceMonthly;
    }
    // III.6
    catch (std::ifstream::failure e) {
        std::cerr << "Exception opening/reading/closing file:" << endl << e.what() << endl;
    }

    return 0;
}
