//
// Created by User on 11.05.2022.
//

#ifndef LAB12OOP_DIVIDINGONZEROEXCEPTION_H
#define LAB12OOP_DIVIDINGONZEROEXCEPTION_H
#include <stdexcept>

class DividingOnZeroException : public std::exception{
public:
    DividingOnZeroException() = default;
};


#endif //LAB12OOP_DIVIDINGONZEROEXCEPTION_H
