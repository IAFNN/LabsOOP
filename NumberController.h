//
// Created by User on 06.05.2022.
//

#ifndef LAB10OOP_NUMBERCONTROLLER_H
#define LAB10OOP_NUMBERCONTROLLER_H
#include <QString>
#include "Number.h"
#include <QLabel>

template <typename T>
class NumberController {
private:
    static_assert(std::is_base_of<Number, T>::value, "Incorrect generic class");
    T* number;
public:
    NumberController() = default;
    NumberController(T* number);
    void add(T* secondNumber);
    void subtract(T* secondNumber);
    void multiply(T* secondNumber);
    void divide(T* secondNumber);
    void print(QLabel* label);
    T* getNumber();
    void setNumber(T* number);
};


#endif //LAB10OOP_NUMBERCONTROLLER_H
