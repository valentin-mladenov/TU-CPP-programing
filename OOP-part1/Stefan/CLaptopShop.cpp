#include "stdafx.h"
#include "CLaptopShop.h"
#include <vector>
#include <iostream>
#include <string>


CLaptopShop::CLaptopShop() {}

CLaptopShop::~CLaptopShop() {}

CLaptopShop::CLaptopShop(std::vector<CLaptop> vctr)
{
	m_vSales = vctr;
}

//Метод за добавяне на лаптоп
void CLaptopShop::AddLaptop(CLaptop &element)
{
	m_vSales.push_back(element);
}

//Визуализация на всички лаптопи, като се използва
//вече предефинирания оператор за изместване в ostream '<<'
void CLaptopShop::Show()
{
	for each (auto element in m_vSales)
	{
		std::cout << element << std::endl;
	}
}

//Метод за преброяване на всички лаптопи по даден производител
void CLaptopShop::MaxSalesByProducer(IN std::string strProducer, OUT int& nNum)
{
	nNum = 0;

	for each (CLaptop element in m_vSales)
	{
		std::string b = element.GetProducer();
		if (b == strProducer)
		{
			nNum++;
		}
	}
}

//Метод за преброяване на всички лаптопи по размер на екрана
void CLaptopShop::MaxSalesByScreenSize(IN const int& nScreenSize, OUT int& nNum)
{
	nNum = 0;

	for each (auto element in m_vSales)
	{
		if (*element.GetScreenSize() == nScreenSize)
		{
			nNum++;
		}
	}
}
