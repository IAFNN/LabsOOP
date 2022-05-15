//
// Created by User on 24.04.2022.
//

#ifndef LAB8OOP_DEFAULTDEPOSITMTV_H
#define LAB8OOP_DEFAULTDEPOSITMTV_H
#include "BankDepositMTV.h"

class DefaultDepositMTV : public BankDepositMTV{
public:
    double payMoney() override;
    DefaultDepositMTV() = default;
    DefaultDepositMTV(double money, double rate, int depositTerm);
    QString print() override;
    void writeToFile(QString filepath) override;
};


#endif //LAB8OOP_DEFAULTDEPOSITMTV_H
