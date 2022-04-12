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
    connect(ui->multiply, SIGNAL(clicked(bool)), this, SLOT(multiply()));
    connect(ui->getCoefficient, SIGNAL(clicked(bool)), this, SLOT(getCoefficent()));
    connect(ui->calculateRoots, SIGNAL(clicked(bool)), this, SLOT(calculateRoots()));
    connect(ui->inverse, SIGNAL(clicked(bool)), this, SLOT(inverse()));
    connect(ui->isEvenButton, SIGNAL(clicked(bool)), this, SLOT(isEven()));
    connect(ui->update, SIGNAL(clicked(bool)), this, SLOT(updateNumberOfInstances()));
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::display() {
    operator>>(*polynom, *(ui->polynom));
}
void MainWindow::enter() {
    polynom = new Polynom(operator<<(*polynom, *(ui->enterLineEdit)));
}
void MainWindow::addPolynom() {
    Polynom* polynomToAdd = new Polynom();
    polynomToAdd = new Polynom(operator<<(*polynomToAdd, *(ui->enterLineEdit)));
    polynom = new Polynom(*polynom + *polynomToAdd);
    operator>>(*polynom, *(ui->polynom));
}
void MainWindow::substractPolynom() {
    Polynom* polynomToSubstract = new Polynom();
    polynomToSubstract = new Polynom(operator<<(*polynomToSubstract, *(ui->enterLineEdit)));
    polynom = new Polynom(*polynom - *polynomToSubstract);
    operator>>(*polynom, *(ui->polynom));
}
void MainWindow::multiply() {
    polynom = new Polynom(*polynom * ui->xLineEdit->text().toDouble());
    operator>>(*polynom, *(ui->polynom));
}
void MainWindow::getCoefficent() {
    ui->coefficient->setText(QString::number((*polynom)[ui->iLineEdit->text().toInt()]));
}
void MainWindow::calculateRoots() {
    struct root roots = (*polynom)();
    ui->x1->setText(QString::number(roots.x1));
    ui->x2->setText(QString::number(roots.x2));
}
void MainWindow::inverse() {
    !(*polynom);
    operator>>(*polynom, *(ui->polynom));
}
void MainWindow::isEven() {
    Polynom* polynomToCompare = new Polynom();
    polynomToCompare = new Polynom(operator<<(*polynomToCompare, *(ui->enterLineEdit)));
    bool isEven = *polynomToCompare == *polynom;
    if(isEven){
        ui->isEven->setText("Yes");
    }else{
        ui->isEven->setText("No");
    }
}
void MainWindow::updateNumberOfInstances() {
    ui->numberOfInstances->setText(QString::number(Polynom::getInstanceCount()));
}