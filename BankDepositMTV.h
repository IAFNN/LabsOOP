//
// Created by User on 23.04.2022.
//

#ifndef LAB8OOP_BANKDEPOSITMTV_H
#define LAB8OOP_BANKDEPOSITMTV_H
#include <QString>

class BankDepositMTV {
private:
    double money;
    double rate;
    int depositTermInMonths;
public:
    double getMoney();
    double getRate();
    int getDepositTermInMonths();
    void setMoney(double money);
    void setRate(double rate);
    void setDepositTermInMonths(int depositTerm);
    BankDepositMTV() = default;
    BankDepositMTV(double money, double rate, int depositTerm);
    double calculateProfitInDepositTerm();
    double calculateProfitInGivenTerm(int term);
    virtual double payMoney() = 0;
    virtual QString print() = 0;
    virtual void writeToFile(QString filepath) = 0;
};


#endif //LAB8OOP_BANKDEPOSITMTV_H
