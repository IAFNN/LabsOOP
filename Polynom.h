#ifndef LAB6OOP_POLYNOM_H
#define LAB6OOP_POLYNOM_H
#include <QLabel>
#include <QLineEdit>

struct root{
    double x1;
    double x2;
};
class Polynom {
private:
    double a;
    double b;
    double c;
    static int countInstances;
public:
    Polynom();
    Polynom(double a, double b, double c);
    Polynom(Polynom* polynom);
    const double DX = 0.0001;
    double calculateInX(double x);
    double calculateDerivativeInX(double x);
    double calculateIntegralInX(double n, double lowerIntegrationLimit, double higherIntegrationLimit);
    struct root operator()();
    Polynom operator!();
    Polynom operator+(Polynom& polynom);
    Polynom operator-(Polynom& polynom);
    friend Polynom operator*(Polynom& polynom, double scalar);
    friend Polynom operator<<(Polynom& polynom, QLineEdit& polynomLineEdit);
    friend void operator>>(Polynom& polynom, QLabel& polynomLabel);
    double operator[](int index);
    friend bool operator==(Polynom& polynom1, Polynom& polynom2);
    void setA(double a);
    void setB(double b);
    void setC(double c);
    static void setInstanceCount(int instanceCount);
    double getA();
    double getB();
    double getC();
    static int getInstanceCount();
};
#endif