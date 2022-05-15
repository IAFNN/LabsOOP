//
// Created by User on 23.04.2022.
//

#include "BankDepositMTV.h"
 BankDepositMTV::BankDepositMTV(double money, double rate, int depositTerm) {
    this->money = money;
    this->rate = rate;
    this->depositTermInMonths = depositTerm;
}

double BankDepositMTV::getMoney() {
    return money;
}

double BankDepositMTV::getRate() {
    return rate;
}
int BankDepositMTV::getDepositTermInMonths() {
    return depositTermInMonths;
}

void BankDepositMTV::setMoney(double money) {
    this->money = money;
}

void BankDepositMTV::setRate(double rate) {
    this->rate = rate;
}

void BankDepositMTV::setDepositTermInMonths(int depositTerm) {
    this->depositTermInMonths = depositTerm;
}

double BankDepositMTV::calculateProfitInDepositTerm() {
    double profit = getMoney();
    for(int i = getDepositTermInMonths(); i > 0; i--){
        profit *= (getRate() / 100) + 1;
    }
    return profit;
}

double BankDepositMTV::calculateProfitInGivenTerm(int term) {
    double profit = getMoney();
    for(int i = term; i > 0; i--){
        profit *= (getRate() / 100) + 1;
    }
    return profit;
}




