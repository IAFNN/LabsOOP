//
// Created by User on 11.05.2022.
//

#ifndef LAB12OOP_LOGARITHMOFNEGATIVENUMBEREXCEPTION_H
#define LAB12OOP_LOGARITHMOFNEGATIVENUMBEREXCEPTION_H
#include <stdexcept>

class LogarithmOfNegativeNumberException : public std::exception{
private:
    std::string message;
public:
    std::string getMessage();
    LogarithmOfNegativeNumberException() = default;
    explicit LogarithmOfNegativeNumberException(std::string message);
};


#endif //LAB12OOP_LOGARITHMOFNEGATIVENUMBEREXCEPTION_H
