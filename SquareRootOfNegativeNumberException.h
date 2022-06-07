//
// Created by User on 11.05.2022.
//

#ifndef LAB12OOP_SQUAREROOTOFNEGATIVENUMBEREXCEPTION_H
#define LAB12OOP_SQUAREROOTOFNEGATIVENUMBEREXCEPTION_H
#include <stdexcept>

class SquareRootOfNegativeNumberException : public std::exception{
private:
    std::string message;
public:
    std::string getMessage();
    SquareRootOfNegativeNumberException() = default;
    explicit SquareRootOfNegativeNumberException(std::string message);
};


#endif //LAB12OOP_SQUAREROOTOFNEGATIVENUMBEREXCEPTION_H
