//
// Created by User on 09.04.2022.
//

#include "Polynom.h"
#include <cmath>
#include <cctype>
#include <sstream>

double Polynom::calculateInX(double x) {
    return this->a * x * x + this->b * x + this->c;
}
double Polynom::calculateDerivativeInX(double x) {
    return (calculateInX(x + DX) - calculateInX(x)) / DX;
}
double Polynom::calculateIntegralInX(double n, double lowerIntegrationLimit, double higherIntegrationLimit){
    double step = (higherIntegrationLimit - lowerIntegrationLimit) / n;
    double seriesSum = 0;
    for(double x = lowerIntegrationLimit + step / 2; x < higherIntegrationLimit; x += step){
        seriesSum += calculateInX(x);
    }
    return step * seriesSum;
}
struct root Polynom::calculateRoot() {
    double D = this->b * this->b - 4 * this->a * this->c;
    struct root root;
    root.x1 = (-1 * this->b + sqrt(D)) / 2 * this->a;
    root.x2 = (-1 * this->b - sqrt(D)) / 2 * this->a;
    return root;
}
void Polynom::addPolynom(Polynom *polynom) {
    this->a += polynom->a;
    this->b += polynom->b;
    this->c += polynom->c;
}
void Polynom::substractPolynom(Polynom *polynom) {
    this->a -= polynom->a;
    this->b -= polynom->b;
    this->c -= polynom->c;
}
void Polynom::setA(double a) {
    this->a = a;
}
void Polynom::setB(double b) {
    this->b = b;
}
void Polynom::setC(double c) {
    this->c = c;
}
double Polynom::getA() {
    return this->a;
}
double Polynom::getB() {
    return this->b;
}
double Polynom::getC() {
    return this->c;
}
Polynom::Polynom() = default;
Polynom::Polynom(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}
Polynom::Polynom(Polynom *polynom) {
    this->a = polynom->a;
    this->b = polynom->b;
    this->c = polynom->c;
}
void Polynom::display(QLabel* polynomLabel) {
    QString* polynom = new QString(QString::number(this->a) + "x ^ 2 + " + QString::number(this->b) + "x + " + QString::number(this->c) + " = 0");
    polynomLabel->setText(*polynom);
}
void Polynom::enter(QLineEdit* polynomLineEdit) {
    std::string polynom = polynomLineEdit->text().toStdString();
    polynomLineEdit->clear();
    std::string coefficients[3];
    size_t pos;
    for(int i = 0; i < 3; i++){
        pos = polynom.find('+');
        coefficients[i] = polynom.substr(0, pos);
        polynom.erase(0, pos + 1);
    }
    this->a = std::stod(coefficients[0]);
    this->b = std::stod(coefficients[1]);
    this->c = std::stod(coefficients[2]);
}