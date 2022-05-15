//
// Created by User on 24.04.2022.
//

#include <fstream>
#include "MonthlyDepositMTV.h"
MonthlyDepositMTV::MonthlyDepositMTV(double money, double rate, int depositTerm) : BankDepositMTV(money, rate, depositTerm){}

double MonthlyDepositMTV::payMoney() {
    setMoney(getMoney() * ((getRate() / 100) + 1));
    setDepositTermInMonths(getDepositTermInMonths() - 1);
    if(getDepositTermInMonths() == 0){
        setRate(0);
    }
    return getMoney();
}

QString MonthlyDepositMTV::print() {
    return QString("Monthly deposit");
}
void MonthlyDepositMTV::writeToFile(QString filepath) {
    std::ofstream file;
    file.open(filepath.toStdString());
    file << "Money: " << getMoney() << "\nDeposit rate: " << getRate() << "\nDeposit term: " << getDepositTermInMonths();
    file.close();
}