#pragma once
#include <vector>
#include "CLaptop.h"


//Клас описващ магазин за лаптопи, който съдържа вектор с обекти 
//от тип CLaptop
class CLaptopShop
{
	//Constructors
public:
	CLaptopShop();
	CLaptopShop(std::vector<CLaptop> vctr);
	~CLaptopShop();

	//Public member functions
public:
	void AddLaptop(CLaptop &element);
	void Show();
	void MaxSalesByProducer(IN std::string strProducer, OUT int& nNum);
	void MaxSalesByScreenSize(IN const int& nScreenSize, OUT int& nNum);

	//Private fields
private:
	std::vector<CLaptop> m_vSales;
};
