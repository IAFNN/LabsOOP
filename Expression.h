//
// Created by User on 11.05.2022.
//

#ifndef LAB12OOP_EXPRESSION_H
#define LAB12OOP_EXPRESSION_H
#include <vector>
#include <stdexcept>
#include "SquareRootOfNegativeNumberException.h"
#include "LogarithmOfNegativeNumberException.h"
#include "DividingOnZeroException.h"
#include <cmath>

class Expression {
private:
    int n;
    int m;
    int k;
    double x;
    std::vector<double> nVector;
    std::vector<double> mVector;
    std::vector<double> kVector;
public:
    Expression() = default;
    double calculate();
    void setN(int n);
    void setM(int m);
    void setK(int k);
    void setX(double x);
    void setNVector(std::vector<double> nVector);
    void setMVector(std::vector<double> mVector);
    void setKVector(std::vector<double> kVector);
    static void writeToLogFile(const std::string& message);
};


#endif //LAB12OOP_EXPRESSION_H
