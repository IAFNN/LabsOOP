//
// Created by User on 09.04.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    polynom = new Polynom();
    connect(ui->display, SIGNAL(clicked(bool)), this, SLOT(display()));
    connect(ui->enter, SIGNAL(clicked(bool)), this, SLOT(enter()));
    connect(ui->add, SIGNAL(clicked(bool)), this, SLOT(addPolynom()));
    connect(ui->substract, SIGNAL(clicked(bool)), this, SLOT(substractPolynom()));
    connect(ui->derive, SIGNAL(clicked(bool)), this, SLOT(derive()));
    connect(ui->calculateIntegral, SIGNAL(clicked(bool)), this, SLOT(calculateIntegral()));
    connect(ui->calculateRoots, SIGNAL(clicked(bool)), this, SLOT(calculateRoots()));
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::display() {
    polynom->display(ui->polynom);
}
void MainWindow::enter() {
    polynom->enter(ui->enterLineEdit);
}
void MainWindow::addPolynom() {
    Polynom* polynomToAdd = new Polynom();
    polynomToAdd->enter(ui->enterLineEdit);
    polynom->addPolynom(polynomToAdd);
}
void MainWindow::substractPolynom() {
    Polynom* polynomToSubstract = new Polynom();
    polynomToSubstract->enter(ui->enterLineEdit);
    polynom->substractPolynom(polynomToSubstract);
}
void MainWindow::derive() {
    ui->derivative->setText(QString::number(polynom->calculateDerivativeInX(ui->xLineEdit->text().toDouble())));
    ui->xLineEdit->clear();
}
void MainWindow::calculateIntegral() {
    ui->Integral->setText(QString::number(polynom->calculateIntegralInX(ui->nLineEdit->text().toDouble(), ui->aLineEdit->text().toDouble(), ui->cLineEdit->text().toDouble())));
    ui->aLineEdit->clear();
    ui->cLineEdit->clear();
    ui->nLineEdit->clear();
}
void MainWindow::calculateRoots() {
    struct root roots = polynom->calculateRoot();
    ui->x1->setText(QString::number(roots.x1));
    ui->x2->setText(QString::number(roots.x2));
}