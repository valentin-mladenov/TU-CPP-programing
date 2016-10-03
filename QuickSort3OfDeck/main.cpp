//
// Created by hudson on 3.10.2016 г..
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>

#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>

#endif

using namespace std;

void load(string file, double_list *doubleList)
{
    ifstream data;
    string integers;

    data.open("C:\\Users\\hudso\\OneDrive\\Documents\\GitHub\\TU-CPP-programing\\subscribers\\" + file + ".csv");
    while (data.is_open() && !data.eof()) {
        getline (data, integers, '\n');

        if (integers == "") continue;

        stringstream ss(integers);
        string token;

        while(getline(ss, token, ',')) {
            int key = atoi(token.c_str());

            doubleList->create_list(key);
        }
    }
    data.close();

    cout << "DONE!";
}

int main() {
    int command;
    string fileName;

    int choice, element, position;
    double_list *doubleList;

    while (true) {
        cout << endl << endl << "Main Menu" << endl;
        cout << "1 -  GET INTEGERS FROM FILE." << endl;
        cout << "2 -  LOAD INTEGERS IN DOUBLE CONNECTED LIST." << endl;
        cout << "3 -  USE QUICK SORT" << endl;
        cout << "4 -  USE QUICK SORT 3" << endl;
        cout << "5 -  WRITHE THE RESULT." << endl;
        cout << "6 -  EXIT" << endl;
        cout << "\n\n Chose command (1-4): ";
        cin >> command;

        // clear console
        if (system("CLS")) system("clear");

        switch (command) {
            case 1:
                cout << "Available files with integers. 100, 500, 1000, 5000, 10000, 50000, 100000. Type one of those digits.";
                cin >> fileName;

                load(fileName, doubleList);

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                return 0;
            default:
                cout << "What are you doing chose from 1, 2, 3, 4, 5 or 6. I****.";
                break;
        }
    }
}
