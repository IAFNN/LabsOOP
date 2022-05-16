//
// Created by User on 04.05.2022.
//

#include "Fraction.h"

Fraction::Fraction(double numeral, double denominator) {
    this->numeral = numeral;
    this->denominator = denominator;
}

double Fraction::getDenominator() {
    return denominator;
}

double Fraction::getNumeral() {
    return numeral;
}

void Fraction::setDenominator(double denominator) {
    this->denominator = denominator;
}

void Fraction::setNumeral(double numeral) {
    this->numeral = numeral;
}

std::string Fraction::toString() {
    return QString(QString::number(numeral) + "\n---------------\n" + QString::number(denominator)).toStdString();
}

Number* Fraction::add(Number *number) {
    Fraction* fraction = dynamic_cast<Fraction*>(number);
    double coef = fraction->denominator / denominator;
    denominator *= coef;
    numeral *= coef;
    numeral += fraction->numeral;
    return this;
}

Number * Fraction::subtract(Number *number) {
    Fraction* fraction = dynamic_cast<Fraction*>(number);
    double coef = fraction->denominator / denominator;
    denominator *= coef;
    numeral *= coef;
    numeral -= fraction->numeral;
    return this;
}

Number * Fraction::multiply(Number *number) {
    Fraction* fraction = dynamic_cast<Fraction*>(number);
    numeral *= fraction->numeral;
    denominator *= fraction->denominator;
    return this;
}

Number * Fraction::divide(Number *number) {
    Fraction* fraction = dynamic_cast<Fraction*>(number);
    double temp = fraction->numeral;
    fraction->numeral = fraction->denominator;
    fraction->denominator = temp;
    numeral *= fraction->numeral;
    denominator *= fraction->denominator;
    return this;
}