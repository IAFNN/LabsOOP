//
// Created by User on 24.04.2022.
//

#include <fstream>
#include "VIPDepositMTV.h"
 VIPDepositMTV::VIPDepositMTV(double money, double rate, int depositTerm, double rateIncreaseCoef, double maxMoney) : MonthlyDepositMTV(money, rate, depositTerm) {
    this->rateIncreaseCoef = rateIncreaseCoef;
    this->maxMoneyForIncreasing = maxMoney;
}

double VIPDepositMTV::getRateIncreaseCoef() {
    return rateIncreaseCoef;
}

void VIPDepositMTV::setRateIncreaseCoef(double increaseCoef) {
    this->rateIncreaseCoef = increaseCoef;
}

double VIPDepositMTV::getMaxMoney() {
    return maxMoneyForIncreasing;
}

void VIPDepositMTV::setMaxMoney(double maxMoney) {
    this->maxMoneyForIncreasing = maxMoney;
}

void VIPDepositMTV::putMoney(double money) {
    double moneySmallerThanMaxMoney = getMaxMoney() - getMoney();
    if(moneySmallerThanMaxMoney > money){
        moneySmallerThanMaxMoney = money;
    }
    if(moneySmallerThanMaxMoney > 0) {
        increaseRate(moneySmallerThanMaxMoney);
    }
    setMoney(getMoney() + money);
}

void VIPDepositMTV::increaseRate(double money) {
    setRate(getRate() + money * getRateIncreaseCoef());
}

QString VIPDepositMTV::print() {
    return QString("VIP Deposit");
}
void VIPDepositMTV::writeToFile(QString filepath) {
    std::ofstream file;
    file.open(filepath.toStdString());
    file << "Money: " << getMoney() << "\nDeposit rate: " << getRate() << "\nDeposit term: " << getDepositTermInMonths() << "\nRate increase coefficient: " << getRateIncreaseCoef() << "\nMaximum money before increasing stops: " << getMaxMoney();
    file.close();
}