//
// Created by User on 11.05.2022.
//

#include "SquareRootOfNegativeNumberException.h"

std::string SquareRootOfNegativeNumberException::getMessage() {
    return message;
}
SquareRootOfNegativeNumberException::SquareRootOfNegativeNumberException(std::string message) {
    this->message = message;
}