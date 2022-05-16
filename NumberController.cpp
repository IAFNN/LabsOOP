//
// Created by User on 06.05.2022.
//

#include "NumberController.h"
#include "Fraction.h"

template<typename T>
void NumberController<T>::add(T *secondNumber) {
    number = dynamic_cast<Fraction*>(number->add(secondNumber));
}

template<typename T>
void NumberController<T>::subtract(T *secondNumber) {
    number = dynamic_cast<Fraction*>(number->subtract(secondNumber));
}
template<typename T>
void NumberController<T>::divide(T *secondNumber) {
    number = dynamic_cast<Fraction*>(number->divide(secondNumber));
}

template<typename T>
void NumberController<T>::multiply(T *secondNumber) {
    number = dynamic_cast<Fraction*>(number->multiply(secondNumber));
}

template<typename T>
void NumberController<T>::print(QLabel *label) {
    label->setText(QString(number->toString().c_str()));
}

template<typename T>
NumberController<T>::NumberController(T *number) {
    this->number = number;
}

template<typename T>
T *NumberController<T>::getNumber() {
    return number;
}

template<typename T>
void NumberController<T>::setNumber(T *number) {
    this->number = number;
}

template class NumberController<Fraction>;

