//
// Created by User on 05.05.2022.
//

#ifndef LAB10OOP_NUMBER_H
#define LAB10OOP_NUMBER_H
#include <string>

class Number {
public:
    virtual Number* add(Number* number) = 0;
    virtual Number* subtract(Number* number) = 0;
    virtual Number* multiply(Number* number) = 0;
    virtual Number* divide(Number* number) = 0;
    virtual std::string toString() = 0;
};


#endif //LAB10OOP_NUMBER_H
