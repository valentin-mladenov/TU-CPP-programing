#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif

using namespace std;

const int maxSubscribers = 30;
struct subscriber {
    string firstName;
    string lastName;
    string adress;
    string phoneNumber;
    double payment;
} *subscribers[maxSubscribers];

int addSubscriber (string subscribe)
{
    stringstream ss(subscribe);
    string token;
    vector<string> vect;

    while(getline(ss, token, ';')) {
        vect.push_back(token);
    }


    for (int i = 0; i < maxSubscribers; ++i) {
        if (subscribers[i] == nullptr){
            double d = strtod(vect.at(4).c_str(), NULL);

            subscribers[i] = new subscriber;
            subscribers[i]->firstName = vect.at(0);
            subscribers[i]->lastName = vect.at(1);
            subscribers[i]->adress = vect.at(2);
            subscribers[i]->phoneNumber = vect.at(3);
            subscribers[i]->payment = d;

            return 1;
        }
    }

    return 0;
}

void init(subscriber *subscribers[maxSubscribers])
{
    for (int i = 0; i < maxSubscribers; ++i) {
        subscribers[i] = nullptr;
    }

    ifstream data;
    string subscribe;

    data.open("C:\\Users\\hudso\\OneDrive\\Documents\\GitHub\\TU-CPP-programing\\subscribers\\subscribers.csv");
    if (data.is_open()) {
        while (!data.eof()) {
            getline (data, subscribe, '\n');

            if (subscribe == "") continue;

            int addSuccess = addSubscriber(subscribe);

            string out = addSuccess ? "DONE!" : "FAIL!";

            cout << out;
        }
    }

    data.close();
}

void print (subscriber *sub){
    cout <<
    sub->firstName << " " <<
    sub->lastName << ", " <<
    sub->adress << ", " <<
    sub->phoneNumber << ", " <<
    sub->payment << endl;
}

void subscribersOver100 ()
{
    for (int i = 0; i < maxSubscribers; ++i) {
        if (subscribers[i] != nullptr && subscribers[i]->payment > 100.0){
            print(subscribers[i]);
        }
    }
}

int main() {
    int command, addSuccess;
    string subscribe;

    init(subscribers);

    while (true) {
        cout << endl << endl << "Main Menu" << endl;
        cout << "1 -  ADD SUBSCRIBER" << endl;
        cout << "2 -  SUBSCRIBERS PAYMENT OVER 100" << endl;
        cout << "3 -  ALL SUBSCRIBERS PAYMENTS UP" << endl;
        cout << "4 -  EXIT" << endl;
        cout << "\n\n Chose command (1-4): ";
        cin >> command;

        // clear console
        if (system("CLS")) system("clear");

        switch (command) {
            case 1:
                cin >> subscribe;

                addSuccess = addSubscriber(subscribe);

                if(addSuccess){
                    ofstream file;
                    file.open ("C:\\Users\\hudso\\OneDrive\\Documents\\GitHub\\TU-CPP-programing\\subscribers\\subscribers.csv", ios_base::app);
                    file << subscribe << '\n';
                    file.close();

                    cout << "DONE";
                } else {
                    cout << "Too many subscribers.";
                }

                break;
            case 2:
                subscribersOver100();
                break;
            case 3:
                subscriber *swap;

                for (int c = 0 ; c < ( maxSubscribers - 1 ); c++)
                {
                    for (int d = 0 ; d < (maxSubscribers - c - 1); d++)
                    {
                        if (subscribers[d + 1] == nullptr) break;

                        if (subscribers[d]->payment < subscribers[d + 1]->payment) /* For decreasing order use < */
                        {
                            swap = subscribers[d];
                            subscribers[d] = subscribers[d + 1];
                            subscribers[d + 1] = swap;
                        }
                    }
                }

                for (int i = 0; i < maxSubscribers; ++i) {
                    if (subscribers[i] == nullptr) break;

                    print(subscribers[i]);
                }

                break;
            case 4:
                return 0;
            default:
                cout << "What are you doing chose from 1, 2, 3, or 4. I****.";
                break;
        }
    }
}
