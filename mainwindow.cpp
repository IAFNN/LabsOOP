//
// Created by User on 04.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <iostream>
#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    numberController = new NumberController<Fraction>();
    connect(ui->enter, SIGNAL(clicked(bool)), this, SLOT(enter()));
    connect(ui->add, SIGNAL(clicked(bool)), this, SLOT(add()));
    connect(ui->subtract, SIGNAL(clicked(bool)), this, SLOT(subtract()));
    connect(ui->multiply, SIGNAL(clicked(bool)), this, SLOT(multiply()));
    connect(ui->divide, SIGNAL(clicked(bool)), this, SLOT(divide()));
}

MainWindow::~MainWindow() {
    delete numberController;
    delete ui;
}

void MainWindow::enter() {
    numberController->setNumber(new Fraction(ui->numeral->text().toDouble(), ui->denominator->text().toDouble()));
    numberController->print(ui->output);
}

void MainWindow::add() {
    numberController->add(new Fraction(ui->numeral->text().toDouble(), ui->denominator->text().toDouble()));
    numberController->print(ui->output);
}

void MainWindow::subtract() {
    numberController->subtract(new Fraction(ui->numeral->text().toDouble(), ui->denominator->text().toDouble()));
    numberController->print(ui->output);
}

void MainWindow::multiply() {
    numberController->multiply(new Fraction(ui->numeral->text().toDouble(), ui->denominator->text().toDouble()));
    numberController->print(ui->output);
}

void MainWindow::divide() {
    numberController->divide(new Fraction(ui->numeral->text().toDouble(), ui->denominator->text().toDouble()));
    numberController->print(ui->output);
}