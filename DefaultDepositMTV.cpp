//
// Created by User on 24.04.2022.
//

#include <fstream>
#include "DefaultDepositMTV.h"

double DefaultDepositMTV::payMoney() {
    double profit = calculateProfitInDepositTerm();
    setMoney(0);
    setDepositTermInMonths(0);
    setRate(0);
    return profit;
}
DefaultDepositMTV::DefaultDepositMTV(double money, double rate, int depositTerm) : BankDepositMTV(money, rate, depositTerm){}

QString DefaultDepositMTV::print() {
    return QString("Default Deposit");
}

void DefaultDepositMTV::writeToFile(QString filepath) {
    std::ofstream file;
    file.open(filepath.toStdString());
    file << "Money: " << getMoney() << "\nDeposit rate: " << getRate() << "\nDeposit term: " << getDepositTermInMonths();
    file.close();
}
