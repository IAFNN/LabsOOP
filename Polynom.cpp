#include "Polynom.h"
#include <cmath>
#include <cctype>
#include <sstream>
int Polynom::countInstances = 0;
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
struct root Polynom::operator()() {
    double D = this->b * this->b - 4 * this->a * this->c;
    struct root root{};
    root.x1 = (-1 * this->b + sqrt(D)) / 2 * this->a;
    root.x2 = (-1 * this->b - sqrt(D)) / 2 * this->a;
    return root;
}
Polynom operator*(Polynom& polynom, double scalar) {
    polynom.a *= scalar;
    polynom.b *= scalar;
    polynom.c *= scalar;
    return polynom;
}
Polynom Polynom::operator!() {
    this->a *= -1;
    this->b *= -1;
    this->c *= -1;
    return *this;
}
Polynom Polynom::operator+(Polynom& polynom) {
    this->a += polynom.a;
    this->b += polynom.b;
    this->c += polynom.c;
    return *this;
}
Polynom Polynom::operator-(Polynom& polynom) {
    this->a -= polynom.a;
    this->b -= polynom.b;
    this->c -= polynom.c;
    return *this;
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
void Polynom::setInstanceCount(int instanceCount) {
    Polynom::countInstances = instanceCount;
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
int Polynom::getInstanceCount() {
    return Polynom::countInstances;
}
Polynom::Polynom() {
    Polynom::countInstances++;
}
Polynom::Polynom(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
    Polynom::countInstances++;
}
Polynom::Polynom(Polynom *polynom) {
    this->a = polynom->a;
    this->b = polynom->b;
    this->c = polynom->c;
    Polynom::countInstances++;
}
void operator>>(Polynom& polynom, QLabel& polynomLabel) {
    QString* polynomStr = new QString(QString::number(polynom.a) + "x ^ 2 + " + QString::number(polynom.b) + "x + " + QString::number(polynom.c) + " = 0");
    polynomLabel.setText(*polynomStr);
}
Polynom operator<<(Polynom& polynom, QLineEdit& polynomLineEdit) {
    std::string polynomStr = polynomLineEdit.text().toStdString();
    polynomLineEdit.clear();
    std::string coefficients[3];
    size_t pos;
    for(int i = 0; i < 3; i++){
        pos = polynomStr.find('+');
        coefficients[i] = polynomStr.substr(0, pos);
        polynomStr.erase(0, pos + 1);
    }
    polynom.a = std::stod(coefficients[0]);
    polynom.b = std::stod(coefficients[1]);
    polynom.c = std::stod(coefficients[2]);
    return polynom;
}
bool operator==(Polynom& polynom1, Polynom& polynom2){
    if(polynom1.a == polynom2.a && polynom1.b == polynom2.b && polynom1.c == polynom2.c){
        return true;
    }else{
        return false;
    }
}
double Polynom::operator[](int index) {
    switch (index) {
        case 0:
            return this->a;
        case 1:
            return this->b;
        case 2:
            return this->c;
        default:
            return 0;
    }
}