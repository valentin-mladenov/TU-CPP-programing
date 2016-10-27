//
// Created by hudso on 25.10.2016 г..
//

#include "CLaptopShop.h"
#include <sstream>

CLaptopShop::CLaptopShop() {
}

CLaptopShop::CLaptopShop(std::vector<CLaptop> &laptops) {
    this->m_vSales = laptops;
}

CLaptopShop::~CLaptopShop() {}


void CLaptopShop::addSale(CLaptop laptop) {
    this->m_vSales.push_back(laptop);
}

std::string CLaptopShop::print() {
    std::stringstream ss;
    for (int i = 0; i < this->m_vSales.size(); ++i) {
        ss << this->m_vSales[i] << std::endl;
    }

    return ss.str();
}


void CLaptopShop::maxSalesBySize(int &size, int &count) {
    for (int i = 0; i < this->m_vSales.size(); ++i) {
        if (this->m_vSales[i].getScreenSize() == size) ++count;
    }
}

void CLaptopShop::maxSalesByProducer(std::string &producer, int &count) {
    for (int i = 0; i < this->m_vSales.size(); ++i) {
        if (this->m_vSales[i].getProducer() == producer) ++count;
    }
}
