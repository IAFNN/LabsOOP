//
// Created by User on 26.04.2022.
//

#ifndef LAB8OOP_MAINWINDOW_H
#define LAB8OOP_MAINWINDOW_H

#include <QTabWidget>
#include "DefaultDepositMTV.h"
#include "VIPDepositMTV.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowMTV; }
QT_END_NAMESPACE

class MainWindowMTV : public QTabWidget {
Q_OBJECT

public:
    explicit MainWindowMTV(QWidget *parent = nullptr);

    ~MainWindowMTV() override;

private:
    DefaultDepositMTV* defaultDeposit;
    MonthlyDepositMTV* monthlyDeposit;
    VIPDepositMTV* vipDeposit;
    Ui::MainWindowMTV *ui;
    void updateDataDefault();
    void updateDataMonthly();
    void updateDataVIP();
private slots:
    void createDefault();
    void calculateDefault();
    void getMoneyDefault();
    void writeToFileDefault();
    void calculateInNMonthsDefault();
    void createMonthly();
    void calculateMonthly();
    void getMoneyMonthly();
    void writeToFileMonthly();
    void calculateInNMonthsMonthly();
    void createVIP();
    void calculateVIP();
    void getMoneyVIP();
    void writeToFileVIP();
    void calculateInNMonthsVIP();
    void putMoney();
};


#endif //LAB8OOP_MAINWINDOW_H
