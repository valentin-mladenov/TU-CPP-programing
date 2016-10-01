#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <string>
#include <array>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

using namespace std;
int winnerDigits[10] = { 0, 111, 222, 333, 444, 555, 666, 777, 888, 999 };

int main() {
    int command, tempBet = 0, bet = 0, tempMoney = 0, money = 0, number = 0;
    string breakInput;

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

                int areEnoughMoney;
                areEnoughMoney = money - tempBet;

                if ((tempBet > 0 || tempBet < 11) && (areEnoughMoney >= 0)) {
                    bet = tempBet;
                } else if (areEnoughMoney < 0) {
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
                while (cin.get()!='\n')
                    ;

                //breakInput = 1;
                while (true) {
                    // array<char, 1> buffer;
                    // cin.clear();
                    //cin.ignore(1, '\n');
                    //cin.readsome(buffer.data(), 1);

                    auto result = cin.get() != -52;
                    //cout<<cin.get()<<endl;
                    //cout<<"check "<<result<<endl;
//
                    if (result) break;

                    number = rand() % 1000;
                    cout << "\r" << number;
#ifdef WIN32
                    Sleep(100);
#else
                    sleep(200);
#endif // win32
                }

                bool exists;
                exists = find(begin(winnerDigits), end(winnerDigits), number) != end(winnerDigits);

                if (exists) {
                    money = money + (bet * 10);
                    cout << "WIN!!!";
                } else {
                    money -= bet;
                    cout << "You have lost.";
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
