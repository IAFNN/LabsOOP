//
// Created by User on 26.04.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindowMTV::MainWindowMTV(QWidget *parent) :
        QTabWidget(parent), ui(new Ui::MainWindowMTV) {
    ui->setupUi(this);
    defaultDeposit = new DefaultDepositMTV();
    monthlyDeposit = new MonthlyDepositMTV();
    vipDeposit = new VIPDepositMTV();
    this->setTabText(0, defaultDeposit->print());
    this->setTabText(1, monthlyDeposit->print());
    this->setTabText(2, vipDeposit->print());
    connect(ui->create, SIGNAL(clicked(bool)), this, SLOT(createDefault()));
    connect(ui->calculate, SIGNAL(clicked(bool)), this, SLOT(calculateDefault()));
    connect(ui->payMoney, SIGNAL(clicked(bool)), this, SLOT(getMoneyDefault()));
    connect(ui->writeToFile, SIGNAL(clicked(bool)), this, SLOT(writeToFileDefault()));
    connect(ui->calculateInNMonths, SIGNAL(clicked(bool)), this, SLOT(calculateInNMonthsDefault()));
    connect(ui->create_2, SIGNAL(clicked(bool)), this, SLOT(createMonthly()));
    connect(ui->calculate_2, SIGNAL(clicked(bool)), this, SLOT(calculateMonthly()));
    connect(ui->payMoney_2, SIGNAL(clicked(bool)), this, SLOT(getMoneyMonthly()));
    connect(ui->writeToFile_2, SIGNAL(clicked(bool)), this, SLOT(writeToFileMonthly()));
    connect(ui->calculateInNMonths_2, SIGNAL(clicked(bool)), this, SLOT(calculateInNMonthsMonthly()));
    connect(ui->create_3, SIGNAL(clicked(bool)), this, SLOT(createVIP()));
    connect(ui->calculate_3, SIGNAL(clicked(bool)), this, SLOT(calculateVIP()));
    connect(ui->payMoney_3, SIGNAL(clicked(bool)), this, SLOT(getMoneyVIP()));
    connect(ui->writeToFile_3, SIGNAL(clicked(bool)), this, SLOT(writeToFileVIP()));
    connect(ui->calculateInNMonths_3, SIGNAL(clicked(bool)), this, SLOT(calculateInNMonthsVIP()));
    connect(ui->put, SIGNAL(clicked(bool)), this, SLOT(putMoney()));
}

MainWindowMTV::~MainWindowMTV() {
    delete ui;
    delete defaultDeposit;
    delete monthlyDeposit;
    delete vipDeposit;
}

void MainWindowMTV::createDefault() {
    double money = ui->moneyEnter->text().toDouble();
    ui->moneyEnter->clear();
    defaultDeposit->setMoney(money);
    double rate = ui->rateEnter->text().toDouble();
    ui->rateEnter->clear();
    defaultDeposit->setRate(rate);
    int term = ui->termEnter->text().toInt();
    ui->termEnter->clear();
    defaultDeposit->setDepositTermInMonths(term);
    updateDataDefault();
}

void MainWindowMTV::calculateDefault() {
    ui->calculated->setText(QString::number(defaultDeposit->calculateProfitInDepositTerm()));
}

void MainWindowMTV::getMoneyDefault() {
    ui->paidMoney->setText(QString::number(defaultDeposit->payMoney()));
    updateDataDefault();
}

void MainWindowMTV::updateDataDefault() {
    ui->money->setText(QString::number(defaultDeposit->getMoney()));
    ui->rate->setText(QString::number(defaultDeposit->getRate()));
    ui->term->setText(QString::number(defaultDeposit->getDepositTermInMonths()));
}

void MainWindowMTV::writeToFileDefault() {
    defaultDeposit->writeToFile(QString("data.txt"));
}

void MainWindowMTV::calculateInNMonthsDefault() {
    ui->calculated->setText(QString::number(defaultDeposit->calculateProfitInGivenTerm(ui->NLineEdit->text().toInt())));
}
void MainWindowMTV::createMonthly() {
    double money = ui->moneyEnter_2->text().toDouble();
    ui->moneyEnter_2->clear();
    monthlyDeposit->setMoney(money);
    double rate = ui->rateEnter_2->text().toDouble();
    ui->rateEnter_2->clear();
    monthlyDeposit->setRate(rate);
    int term = ui->termEnter_2->text().toInt();
    ui->termEnter_2->clear();
    monthlyDeposit->setDepositTermInMonths(term);
    updateDataMonthly();
}

void MainWindowMTV::calculateMonthly() {
    ui->calculated_2->setText(QString::number(monthlyDeposit->calculateProfitInDepositTerm()));
}

void MainWindowMTV::getMoneyMonthly() {
    ui->paidMoney_2->setText(QString::number(monthlyDeposit->payMoney()));
    updateDataMonthly();
}

void MainWindowMTV::updateDataMonthly(){
    ui->money_2->setText(QString::number(monthlyDeposit->getMoney()));
    ui->rate_2->setText(QString::number(monthlyDeposit->getRate()));
    ui->term_2->setText(QString::number(monthlyDeposit->getDepositTermInMonths()));
}

void MainWindowMTV::writeToFileMonthly() {
    monthlyDeposit->writeToFile(QString("data.txt"));
}

void MainWindowMTV::calculateInNMonthsMonthly() {
    ui->calculated_2->setText(QString::number(monthlyDeposit->calculateProfitInGivenTerm(ui->NLineEdit_2->text().toInt())));
}
void MainWindowMTV::updateDataVIP(){
    ui->money_3->setText(QString::number(vipDeposit->getMoney()));
    ui->rate_3->setText(QString::number(vipDeposit->getRate()));
    ui->term_3->setText(QString::number(vipDeposit->getDepositTermInMonths()));
    ui->rateIncreasing->setText(QString::number(vipDeposit->getRateIncreaseCoef()));
    ui->term_5->setText(QString::number(vipDeposit->getMaxMoney()));
}
void MainWindowMTV::createVIP(){
    double money = ui->moneyEnter_3->text().toDouble();
    ui->moneyEnter_3->clear();
    vipDeposit->setMoney(money);
    double rate = ui->rateEnter_3->text().toDouble();
    ui->rateEnter_3->clear();
    vipDeposit->setRate(rate);
    int term = ui->termEnter_3->text().toInt();
    ui->termEnter_3->clear();
    vipDeposit->setDepositTermInMonths(term);
    double rateIncreasingCoef = ui->rateIncreasingLineEdit->text().toDouble();
    ui->rateIncreasingLineEdit->clear();
    vipDeposit->setRateIncreaseCoef(rateIncreasingCoef);
    double maxMoney = ui->maxMoneyLineEdit->text().toDouble();
    ui->maxMoneyLineEdit->clear();
    vipDeposit->setMaxMoney(maxMoney);
    updateDataVIP();
}
void MainWindowMTV::calculateVIP() {
    ui->calculated_3->setText(QString::number(vipDeposit->calculateProfitInDepositTerm()));
}
void MainWindowMTV::getMoneyVIP() {
    ui->paidMoney_3->setText(QString::number(vipDeposit->payMoney()));
    updateDataVIP();
}
void MainWindowMTV::writeToFileVIP() {
    vipDeposit->writeToFile(QString("data.txt"));
}
void MainWindowMTV::calculateInNMonthsVIP() {
    ui->calculated_3->setText(QString::number(vipDeposit->calculateProfitInGivenTerm(ui->NLineEdit_3->text().toInt())));
}

void MainWindowMTV::putMoney() {
    vipDeposit->putMoney(ui->moneyEnter_3->text().toDouble());
    updateDataVIP();
}