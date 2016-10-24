// IzpitOOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CLaptop.h"
#include "CLaptopShop.h"
#include "IzpitOOP.h"
#include <iostream>
#include <string>


int main()
{

	CLaptopConstructorDemonstration();
	CLaptopInOutDemonstration();
	CLaptopComparisonDemonstration();
	CLaptopShopDemonstration();	

	return 0;
}

//Демонстрира конструкторите в класа. В последния случай се приравняват два обекта, което извиква предифинирания оператор за присвояване
//Той е предифиниран така, че да прави deep coppy и не копира побитово обекта, а заделя памет в heap-а и пренасочва указателя към него,
//което се вижда при проверка на адресите на указателя, които са различни
void CLaptopConstructorDemonstration()
{
	std::system("CLS");
	std::cout << std::endl << "Constructors Demonstration: " << std::endl;

	CLaptop laptop1;				//Извиква се Конструктора по подразбиране без параметри	
	CLaptop laptop2(17);			//Извиква се конструктора с един параметър int
	CLaptop laptop3("Asus", 15);	//Извиква се конструктора с 2 параметъра string/int
	CLaptop laptop4 = laptop3;		//Извиква се конструктора за копие, който прави deap coppy

	std::cout
		<< "Laptop 1:" << std::endl
		<< laptop1 << std::endl

		<< "Laptop 2:" << std::endl
		<< laptop2 << std::endl

		<< "Laptop 3:" << std::endl
		<< laptop3 << std::endl
		<< "Address of screen size pointer to heap: " << laptop3.GetScreenSize() << std::endl	//Адреса на указателя на laptop3

		<< "Laptop 4:" << std::endl
		<< laptop4 << std::endl
		<< "Address of screen size pointer to heap: " << laptop4.GetScreenSize();				//Адреса на указателя на laptop4


	std::cout << std::endl << std::endl;
	std::system("PAUSE");
}

//Демонстрира предифинираните оператори за изместване в и от поток (в случая istream и ostream)
void CLaptopInOutDemonstration()
{
	std::system("CLS");
	std::cout << std::endl << "IN/OUT Demonstration: " << std::endl;

	CLaptop laptop1;

	std::cout << "Enter first vendor and then screen size: " << std::endl;
	std::cin >> laptop1;

	std::cout << std::endl
		<< "Your laptop is: " << std::endl
		<< laptop1;

	std::cout << std::endl << std::endl;
	std::system("PAUSE");

}

//Демонстрира предифинираните оператори за сравнение между обектите, които сравнват размерите на екраните им
void CLaptopComparisonDemonstration()
{
	std::system("CLS");
	std::cout << std::endl << "Comparison Demonstration: " << std::endl;


	CLaptop laptop1("Asus", 17);
	CLaptop laptop2("Asus", 15);
	CLaptop laptop3("HP", 17);


	std::cout << std::boolalpha << (laptop1 < laptop2) << std::endl;
	std::cout << std::boolalpha << (laptop1 <= laptop2) << std::endl;
	std::cout << std::boolalpha << (laptop1 > laptop2) << std::endl;
	std::cout << std::boolalpha << (laptop1 >= laptop2) << std::endl;
	std::cout << std::boolalpha << (laptop1 < laptop3) << std::endl;
	std::cout << std::boolalpha << (laptop1 <= laptop3) << std::endl;
	std::cout << std::boolalpha << (laptop1 > laptop3) << std::endl;
	std::cout << std::boolalpha << (laptop1 >= laptop3);

	std::cout << std::endl << std::endl;
	std::system("PAUSE");
}

//Демонстрира класа CLaptopShop и неговите методи
void CLaptopShopDemonstration()
{
	std::system("CLS");
	std::cout << std::endl << "CLaptopShop Demonstration: " << std::endl;

	CLaptopShop laptopShop;

	laptopShop.AddLaptop(CLaptop("Asus", 17));
	laptopShop.AddLaptop(CLaptop("Asus", 15));
	laptopShop.AddLaptop(CLaptop("HP", 17));
	laptopShop.AddLaptop(CLaptop("HP", 15));
	laptopShop.AddLaptop(CLaptop("HP", 15));
	laptopShop.AddLaptop(CLaptop("Lenovo", 17));
	laptopShop.AddLaptop(CLaptop("Lenovo", 17));
	laptopShop.AddLaptop(CLaptop("Dell", 15));
	laptopShop.AddLaptop(CLaptop("Dell", 15));
	laptopShop.AddLaptop(CLaptop("Sony", 15));
	laptopShop.AddLaptop(CLaptop("Sony", 17));
	laptopShop.AddLaptop(CLaptop("Sony", 15));
	laptopShop.AddLaptop(CLaptop("Acer", 17));
	laptopShop.AddLaptop(CLaptop("Acer", 15));
	laptopShop.AddLaptop(CLaptop("Acer", 17));

	laptopShop.Show();
	std::cout << std::endl;

	int countByProducer;
	laptopShop.MaxSalesByProducer("Asus", countByProducer);
	std::cout << "Max sales by Producer 'Asus': " << countByProducer << std::endl;

	int countByScreenSize;
	laptopShop.MaxSalesByScreenSize(17, countByScreenSize);
	std::cout << "Max sales by Screen Size '17': " << countByScreenSize;

	std::cout << std::endl << std::endl;
	std::system("PAUSE");
}

