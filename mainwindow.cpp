//
// Created by User on 01.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "IDComparator.h"
#include "NameComparator.h"
#include "PriceComparator.h"

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0, 80);
    ui->tableWidget->setColumnWidth(1, 237);
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->verticalHeader()->setVisible(false);
    array = new Array();
    connect(ui->add, SIGNAL(clicked(bool)), this, SLOT(addElement()));
    connect(ui->sortId, SIGNAL(clicked(bool)), this, SLOT(sortId()));
    connect(ui->sortName, SIGNAL(clicked(bool)), this, SLOT(sortName()));
    connect(ui->sortprice, SIGNAL(clicked(bool)), this, SLOT(sortPrice()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addElement() {
    int numberOfElements = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(++numberOfElements);
    ui->tableWidget->setItem(numberOfElements - 1, 0, new QTableWidgetItem(QString::number(++idOfLastElement)));
    ui->tableWidget->setItem(numberOfElements - 1, 1, new QTableWidgetItem(ui->name->text()));
    ui->tableWidget->setItem(numberOfElements - 1, 2, new QTableWidgetItem(ui->price->text()));
    array->addElement(new Item(idOfLastElement, ui->price->text().toDouble(), ui->name->text()));
    return;
}

void MainWindow::sortId() {
    array->sort(*(new IDComparator()));
    update();
}

void MainWindow::sortName() {
    array->sort(*(new NameComparator()));
    update();
}

void MainWindow::sortPrice() {
    array->sort(*(new PriceComparator()));
    update();
}

void MainWindow::update() {
    for(int i = 0; i < array->getSize(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(array->getArray()[i].getID())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(array->getArray()[i].getName()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(array->getArray()[i].getPrice())));
    }
}