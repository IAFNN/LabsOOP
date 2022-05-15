//
// Created by User on 24.04.2022.
//

#ifndef LAB8OOP_MONTHLYDEPOSITMTV_H
#define LAB8OOP_MONTHLYDEPOSITMTV_H
#include "BankDepositMTV.h"

class MonthlyDepositMTV : public BankDepositMTV{
public:
    double payMoney() override;
    MonthlyDepositMTV() = default;
    MonthlyDepositMTV(double money, double rate, int depositTerm);
    QString print() override;
    void writeToFile(QString filepath) override;
};


#endif //LAB8OOP_MONTHLYDEPOSITMTV_H
