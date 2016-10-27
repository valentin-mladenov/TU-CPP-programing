//
// Created by hudson on 24.10.2016 г..
//

#ifndef LAPTOP_OOD_CLAPTOP_H
#define LAPTOP_OOD_CLAPTOP_H

#include <string>


class CLaptop {
private:
    std::string m_strProducer;
    int m_iScreenSize;
public:
    CLaptop();
    CLaptop(int screenSize);
    CLaptop(std::string producer, int screenSize);
    CLaptop(const CLaptop &obj);
    ~CLaptop();

    std::string getProducer();
    int getScreenSize();
    friend std::ostream& operator<< (std::ostream &out, const CLaptop &obj);
    friend std::istream& operator>> (std::istream &in, CLaptop &obj);
    friend bool operator== (const CLaptop &obj1, const CLaptop &obj2);
    friend bool operator< (const CLaptop &obj1, const CLaptop &obj2);
    CLaptop& operator= (const CLaptop &obj);
};


#endif //LAPTOP_OOD_CLAPTOP_H
