#include <iostream>
#include "CLaptop.h"
#include "CLaptopShop.h"

using namespace std;

int main()
{
    CLaptopShop *shop = new CLaptopShop();
    CLaptop laptop,
    laptop3,
    laptop2 = CLaptop("Asus", 15);
    int a;

    cin >> laptop;

    shop->addSale(laptop);
    shop->addSale(laptop2);

    cout << "Laptop: " << laptop << endl;

    laptop3 = laptop;

    shop->addSale(laptop3);

    cout << "Laptop3: " << laptop3 << endl;

    if (laptop2 == laptop){
        cout << "Laptop and Laptop2 are same size." << endl;
    } else if(laptop < laptop2) {
        cout << "Laptop2 is larger than Laptop." << endl;
    }

    cout << "Laptop: " << laptop << endl;
    cout << "Laptop2: " << laptop2 << endl;

    cout << shop->print() << endl;


    cin>>a;

    return 0;
}
