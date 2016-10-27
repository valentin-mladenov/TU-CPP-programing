//
// Created by hudson on 24.10.2016 г..
//

#include "CLaptop.h"
#include <string>
#include <iostream>


CLaptop::CLaptop()
{
    this->m_iScreenSize = 0;
    this->m_strProducer = "";
};

CLaptop::CLaptop(int screenSize) : CLaptop("", screenSize) {};

CLaptop::CLaptop(std::string producer, int screenSize)
{
    this->m_iScreenSize = screenSize;
    this->m_strProducer = producer;
};

CLaptop::CLaptop(const CLaptop &obj)
{
    this->m_iScreenSize = obj.m_iScreenSize;
    this->m_strProducer = obj.m_strProducer;
};

CLaptop::~CLaptop(){};

std::string CLaptop::getProducer()
{
    return this->m_strProducer;
};

int CLaptop::getScreenSize()
{
    return this->m_iScreenSize;
};

std::ostream& operator<< (std::ostream &out, const CLaptop &obj)
{
    return out
            << "Producer: "
            << obj.m_strProducer
            << ", with screen size: "
            << obj.m_iScreenSize;
};

std::istream& operator>> (std::istream &in, CLaptop &obj)
{
    return in >> obj.m_strProducer >> obj.m_iScreenSize;
};

bool operator== (const CLaptop &obj1, const CLaptop &obj2)
{
    return obj1.m_iScreenSize == obj2.m_iScreenSize;
};

bool operator < (const CLaptop &obj1, const CLaptop &obj2)
{
    return obj1.m_iScreenSize < obj2.m_iScreenSize;
};

CLaptop& CLaptop::operator= (const CLaptop &obj)
{
    this->m_iScreenSize = obj.m_iScreenSize;
    this->m_strProducer = obj.m_strProducer;

    return *this;
};
