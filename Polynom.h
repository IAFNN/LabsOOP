//
// Created by User on 09.04.2022.
//

#ifndef LAB5OOP_POLYNOM_H
#define LAB5OOP_POLYNOM_H

struct root{
    double x1;
    double x2;
};
class Polynom {
private:
    double a;
    double b;
    double c;
public:
    Polynom();
    Polynom(double a, double b, double c);
    Polynom(Polynom* polynom);
    const double DX = 0.0001;
    double calculateInX(double x);
    double calculateDerivativeInX(double x);
    double calculateIntegralInX(double n, double lowerIntegrationLimit, double higherIntegrationLimit);
    struct root calculateRoot();
    void addPolynom(Polynom* polynom);
    void substractPolynom(Polynom* polynom);
    void setA(double a);
    void setB(double b);
    void setC(double c);
    double getA();
    double getB();
    double getC();

};


#endif //LAB5OOP_POLYNOM_H
