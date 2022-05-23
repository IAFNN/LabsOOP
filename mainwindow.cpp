//
// Created by User on 01.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "IDComparatorMTV.h"
#include "NameComparatorMTV.h"
#include "PriceComparatorMTV.h"

MainWindowMTV::MainWindowMTV(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0, 80);
    ui->tableWidget->setColumnWidth(1, 237);
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->verticalHeader()->setVisible(false);
    array = new ArrayMTV();
    connect(ui->add, SIGNAL(clicked(bool)), this, SLOT(addElement()));
    connect(ui->sortId, SIGNAL(clicked(bool)), this, SLOT(sortId()));
    connect(ui->sortName, SIGNAL(clicked(bool)), this, SLOT(sortName()));
    connect(ui->sortprice, SIGNAL(clicked(bool)), this, SLOT(sortPrice()));
}

MainWindowMTV::~MainWindowMTV() {
    delete ui;
}

void MainWindowMTV::addElement() {
    int numberOfElements = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(++numberOfElements);
    ui->tableWidget->setItem(numberOfElements - 1, 0, new QTableWidgetItem(QString::number(++idOfLastElement)));
    ui->tableWidget->setItem(numberOfElements - 1, 1, new QTableWidgetItem(ui->name->text()));
    ui->tableWidget->setItem(numberOfElements - 1, 2, new QTableWidgetItem(ui->price->text()));
    array->addElement(new ItemMTV(idOfLastElement, ui->price->text().toDouble(), ui->name->text()));
}

void MainWindowMTV::sortId() {
    array->sort(*(new IDComparatorMTV()));
    updateData();
}

void MainWindowMTV::sortName() {
    array->sort(*(new NameComparatorMTV()));
    updateData();
}

void MainWindowMTV::sortPrice() {
    array->sort(*(new PriceComparatorMTV()));
    updateData();
}

void MainWindowMTV::updateData() {
    for(int i = 0; i < array->getSize(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(array->getArray()[i].getID())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(array->getArray()[i].getName()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(array->getArray()[i].getPrice())));
    }
}