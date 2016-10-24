#pragma once
#include <string>
#include <cassert>

//Клас който описва лаптоп.
//Съдържа 2 полета, като и двете са в динамичната памет. Първото е клас от тип std::string,
//който сам се грижи за заделянето и освобождаването. Вторият е *int, за който класа CLaptop
//алокира и деалокира памет и се грижи за предотвратяването на memory leaks
class CLaptop
{
	//Constructors
public:
	CLaptop();
	CLaptop(std::string oem, int screenSize);
	CLaptop(int screenSize);
	CLaptop(const CLaptop &obj);
	~CLaptop();

	//Public Member Functions
public:
	int* GetScreenSize();
	std::string GetProducer();

	//Operator Overload
public:
	friend std::ostream& operator<< (std::ostream &out, const CLaptop &obj);
	friend std::istream& operator >> (std::istream &in, CLaptop &obj);
	CLaptop& operator= (const CLaptop &str);
	friend bool operator> (const CLaptop &obj1, const CLaptop &obj2);
	friend bool operator>= (const CLaptop &obj1, const CLaptop &obj2);
	friend bool operator< (const CLaptop &obj1, const CLaptop &obj2);
	friend bool operator<= (const CLaptop &obj1, const CLaptop &obj2);

	//Private fields
private:
	std::string m_strProducer;	//OEM
	int *m_npScreenSize;		//Screen size in Inch
};
