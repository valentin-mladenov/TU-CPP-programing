#include "stdafx.h"
#include "CLaptop.h"

//Конструктора по подразбиране алокира памет и записва 
//стойности по подразбиране за променливите
CLaptop::CLaptop()
{
	m_strProducer = "";
	m_npScreenSize = new int;
	*m_npScreenSize = 0;
}

//Конструктор с 2 параметъра. Алокира памет и записва 
//стойностите на параметрите
CLaptop::CLaptop(std::string oem, int screenSize)
{
	assert(screenSize >= 0);
	m_strProducer = oem;
	m_npScreenSize = new int;
	*m_npScreenSize = screenSize;
}

//Конструктор с един параметър (screenSize)
//Извиква конструктора с 2 параметъра, като на първия задава
//празен стринг
CLaptop::CLaptop(int screenSize) : CLaptop("", screenSize) {}

//Конструктор за копие. Прави deap coppy на обекта,
//като алокира памет, пренасочва указателите и копира полетата
CLaptop::CLaptop(const CLaptop &obj)
{
	m_strProducer = obj.m_strProducer;
	m_npScreenSize = new int;
	*m_npScreenSize = *obj.m_npScreenSize;
}

//Деструктор, който освобождава паметта
CLaptop::~CLaptop()
{
	delete	m_npScreenSize;
}

//Гетър за връщане на стойността на размера на екрана
//Връща не самата стойност, а указателя към паметта. Така
//имаме достъп до самия указател и можем да проверим адреса на клетката
//за тестови цели
int * CLaptop::GetScreenSize()
{
	return this->m_npScreenSize;
}

//Гетер за производителя
std::string CLaptop::GetProducer()
{
	return m_strProducer;
}

///////////////////////////////////////
//Предифиниране на операторите за достъп присвояване и сравнение



std::ostream& operator<< (std::ostream &out, const CLaptop &obj)
{
	out << "Vendor: " << obj.m_strProducer << std::endl
		<< "Screen Size: " << *obj.m_npScreenSize << "\"";
	return out;
}

std::istream& operator >> (std::istream &in, CLaptop &obj)
{
	in >> obj.m_strProducer;
	in >> *obj.m_npScreenSize;

	return in;
}

CLaptop& CLaptop::operator= (const CLaptop &obj)
{
	if (m_npScreenSize) delete m_npScreenSize;

	m_strProducer = obj.m_strProducer;

	m_npScreenSize = new int;
	m_npScreenSize = obj.m_npScreenSize;

	return *this;
}

bool operator> (const CLaptop &obj1, const CLaptop &obj2)
{
	return *obj1.m_npScreenSize > *obj2.m_npScreenSize;
}

bool operator>= (const CLaptop &obj1, const CLaptop &obj2)
{
	return *obj1.m_npScreenSize >= *obj2.m_npScreenSize;
}

bool operator< (const CLaptop &obj1, const CLaptop &obj2)
{
	return *obj1.m_npScreenSize < *obj2.m_npScreenSize;
}

bool operator<= (const CLaptop &obj1, const CLaptop &obj2)
{
	return *obj1.m_npScreenSize <= *obj2.m_npScreenSize;
}

