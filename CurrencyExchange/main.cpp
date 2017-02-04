#include <iostream>
#include <fstream>
#include "CFXMonthData.h"
#include "Checker.h"

using namespace std;

int main() {
    string fileName;
    string in;
    int coefficient;
    bool isInt = false;

    try {
        // III.1 Създава обект - CFXMonthData от файл.
        // C:\Users\hudso\OneDrive\Documents\GitHub\TU-CPP-programing\CurrencyExchange\february.txt
        // C:\Users\hudso\OneDrive\Documents\GitHub\TU-CPP-programing\CurrencyExchange\empty.txt
        // C:\Users\hudso\OneDrive\Documents\GitHub\TU-CPP-programing\CurrencyExchange\malformed.txt
        cout << "Full path of file:" << endl;
        cin >> fileName;

        CFXMonthData fromFile = CFXMonthData(fileName);

        // III.2 Извежда информацията за обекта на конзола (II.2.в.2)
        cout << fromFile;

        // III.3 Образува обект чрез (II.2.б.3)
        CFXMonthData differenceDayToDay = fromFile.differenceInRatesDayToDay();

        // III.4 извежда обекта (III.3)
        cout << differenceDayToDay;

        // III.5 Изчислява и извежда резултата от (II.2.б.4)
        while (!isInt) {
            cout << endl << "Input coefficient: ";
            cin >> in;

            isInt = Checker::String2Int(in, coefficient);

            if (!isInt) cout << "INCORRECT INPUT. NOT A NUMBER." << endl;
        }

        double differenceMonthly = fromFile.differenceOfRatesMonthly(coefficient);
        cout << endl << "Month difference: " << differenceMonthly << endl;
    }
    // III.6 Обработва изключение
    catch (std::ifstream::failure e) {
        std::cerr << "Exception opening/reading/closing file:" << endl << e.what() << endl;
    }

    cin >> in;
    return 0;
}
