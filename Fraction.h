//
// Created by User on 04.05.2022.
//

#ifndef LAB10OOP_FRACTION_H
#define LAB10OOP_FRACTION_H
#include "NumberController.h"

class Fraction : public Number{
private:
    double numeral;
    double denominator;
public:
    Fraction() = default;
    Fraction(double numeral, double denominator);
    double getNumeral();
    double getDenominator();
    void setNumeral(double numeral);
    void setDenominator(double denominator);
    std::string toString() override;
    Number* add(Number* number) override;
    Number* subtract(Number *number) override;
    Number* multiply(Number *number) override;
    Number* divide(Number *number) override;
};


#endif //LAB10OOP_FRACTION_H
