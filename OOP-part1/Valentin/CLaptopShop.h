//
// Created by hudso on 25.10.2016 г..
//

#ifndef LAPTOP_OOD_CLAPTOPSHOP_H
#define LAPTOP_OOD_CLAPTOPSHOP_H

#include <vector>
#include "CLaptop.h"

class CLaptopShop {
private:
    std::vector<CLaptop> m_vSales;
public:
    CLaptopShop();
    CLaptopShop(std::vector<CLaptop> &laptops);
    ~CLaptopShop();

    void addSale(CLaptop laptop);
    std::string print();
    void maxSalesByProducer(std::string &producer, int &count);
    void maxSalesBySize(int &screenSize, int &count);
};


#endif //LAPTOP_OOD_CLAPTOPSHOP_H
