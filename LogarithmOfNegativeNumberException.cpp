//
// Created by User on 11.05.2022.
//

#include "LogarithmOfNegativeNumberException.h"

std::string LogarithmOfNegativeNumberException::getMessage() {
    return message;
}
LogarithmOfNegativeNumberException::LogarithmOfNegativeNumberException(std::string message) {
    this->message = message;
}