//
// Created by hudson on 17.10.2016 г.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;
int winnerDigits[10] = { 0, 111, 222, 333, 444, 555, 666, 777, 888, 999 };

int main() {
    int command, haveEnoughMoney, tempBet = 0, bet = 0, tempMoney = 0, money = 0, number;
    double seconds;
    time_t start;
    bool exists;

    while (true) {
        cout << endl << endl << "Main Menu" << endl;
        cout << endl << "Current amount of money: " << money << endl;
        cout << "Current bet: " << bet << endl << endl;
        cout << "1 -  ADD MONEY" << endl;
        cout << "2 -  ADD BET" << endl;
        cout << "3 -  PLAY" << endl;
        cout << "4 -  EXIT" << endl;
        cout << "\n\n Chose command (1-4): ";
        cin >> command;

        // clear console
        if (system("CLS")) system("clear");

        switch (command) {
            case 1:
                cout << "Invest up to 200: ";
                cin >> tempMoney;

                if (tempMoney > 0 && tempMoney < 201) {
                    money += tempMoney;
                } else {
                    cout << "Incorrect amount. Must be from 1 to 200. ";
                }

                break;
            case 2:
                cout << "Bet up to 10: ";
                cin >> tempBet;

                haveEnoughMoney = money - tempBet;

                if ((tempBet > 0 || tempBet < 11) && (haveEnoughMoney >= 0)) {
                    bet = tempBet;
                    money -= bet;
                } else if (haveEnoughMoney < 0) {
                    cout << (money - tempBet) << "Not enough money for that bet.";
                } else {
                    cout << (money - tempBet) << "Incorrect amount. Must be from 1 to 10. ";
                }

                break;
            case 3:
                if(bet == 0){
                    cout  << "Place a bet. Current bet is 0.";
                    break;
                }

                seconds = 3 + ( rand() % ( 10 - 3 + 1 ) );
                start = time(0);

                while (difftime(time(0), start) <= seconds) {
                    number = rand() % 1000;
                    cout << "\r" << number;
                }

                exists = find(begin(winnerDigits), end(winnerDigits), number) != end(winnerDigits);

                if (exists) {
                    money = money + (bet * 10);
                    cout << "\nWIN!!!";
                } else {
                    cout << "\nYou have lost.";
                }
                bet = 0;
                break;
            case 4:
                return 0;
            default:
                cout << "What are you doing chose from 1, 2, 3, or 4. I****.";
                break;
        }
    }
}
