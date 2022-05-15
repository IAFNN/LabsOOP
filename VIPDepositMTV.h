//
// Created by User on 24.04.2022.
//

#ifndef LAB8OOP_VIPDEPOSITMTV_H
#define LAB8OOP_VIPDEPOSITMTV_H
#include "MonthlyDepositMTV.h"

class VIPDepositMTV : public MonthlyDepositMTV{
private:
    double rateIncreaseCoef;
    double maxMoneyForIncreasing;
public:
    VIPDepositMTV() = default;
    VIPDepositMTV(double money, double rate, int depositTerm, double rateIncreaseCoef, double maxMoney);
    double getRateIncreaseCoef();
    double getMaxMoney();
    void setMaxMoney(double maxMoney);
    void setRateIncreaseCoef(double increaseCoef);
    void increaseRate(double money);
    void putMoney(double money);
    QString print() override;
    void writeToFile(QString filepath) override;
};


#endif //LAB8OOP_VIPDEPOSITMTV_H
