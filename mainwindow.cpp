//
// Created by User on 11.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <cstring>

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    expression = new Expression();
    connect(ui->setN, SIGNAL(clicked(bool)), this, SLOT(setN()));
    connect(ui->setM, SIGNAL(clicked(bool)), this, SLOT(setM()));
    connect(ui->setK, SIGNAL(clicked(bool)), this, SLOT(setK()));
    connect(ui->setX, SIGNAL(clicked(bool)), this, SLOT(setX()));
    connect(ui->setNVector, SIGNAL(clicked(bool)), this, SLOT(setNVector()));
    connect(ui->setMVector, SIGNAL(clicked(bool)), this, SLOT(setMVector()));
    connect(ui->setKVector, SIGNAL(clicked(bool)), this, SLOT(setKVector()));
    connect(ui->calculate, SIGNAL(clicked(bool)), this, SLOT(calculate()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete expression;
}

void MainWindow::setN() {
    try{
        expression->setN(ui->nEdit->text().toInt());
    } catch (std::range_error& e) {
        ui->exception->setText(QString(e.what()));
    }
}

void MainWindow::setM() {
    try{
        expression->setM(ui->mEdit->text().toInt());
    } catch (std::range_error& e) {
        ui->exception->setText(QString(e.what()));
    }
}

void MainWindow::setK() {
    try{
        expression->setK(ui->kEdit->text().toInt());
    }catch (std::range_error& e){
        ui->exception->setText(QString(e.what()));
    }
}

void MainWindow::setX() {
    expression->setX(ui->xLineEdit->text().toDouble());
}

void MainWindow::setNVector() {
    QStringList numbers = ui->nVectorEdit->text().split(' ');
    std::vector<double> numbersVector;
    for(QStringList::iterator iter = numbers.begin(); iter != numbers.end(); iter++){
        std::string temp = iter->toStdString();
        if(std::any_of(temp.begin(), temp.end(), [](char const& c){
            return std::isalpha(c);
        })){
            std::string message = "N vector contains letters";
            Expression::writeToLogFile(message);
            ui->exception->setText(QString(message.c_str()));
            return;
        }
        if(strcmp("2147483647", iter->toStdString().c_str()) < 0 || strcmp("-2147483648", iter->toStdString().c_str()) < 0){
            std::string message = "Integer overflow";
            Expression::writeToLogFile(message);
            ui->exception->setText(QString(message.c_str()));
            return;
        }
        numbersVector.push_back(iter->toDouble());
    }
    try {
        expression->setNVector(numbersVector);
    } catch (std::invalid_argument& e) {
        ui->exception->setText(QString(e.what()));
    }
}
void MainWindow::setMVector() {
    QStringList numbers = ui->mVectorEdit->text().split(' ');
    std::vector<double> numbersVector;
    for(QString iter : numbers){
        std::string temp = iter.toStdString();
        if(std::any_of(temp.begin(), temp.end(), [](char const& c){
            return std::isalpha(c);
        })){
            std::string message = "M vector contains letters";
            Expression::writeToLogFile(message);
            ui->exception->setText(QString(message.c_str()));
            return;
        }
        if(strcmp("2147483647", iter.toStdString().c_str()) < 0 || strcmp("-2147483648", iter.toStdString().c_str()) < 0){
            std::string message = "Integer overflow";
            Expression::writeToLogFile(message);
            ui->exception->setText(QString(message.c_str()));
            return;
        }
        numbersVector.push_back(iter.toDouble());
    }
    try {
        expression->setMVector(numbersVector);
    } catch (std::invalid_argument& e) {
        ui->exception->setText(QString(e.what()));
    }
}
void MainWindow::setKVector() {
    QStringList numbers = ui->kVectorEdit->text().split(' ');
    std::vector<double> numbersVector;
    for(QString iter : numbers){
        std::string temp = iter.toStdString();
        if(std::any_of(temp.begin(), temp.end(), [](char const& c){
            return std::isalpha(c);
        })){
            std::string message = "K vector contains letters";
            Expression::writeToLogFile(message);
            ui->exception->setText(QString(message.c_str()));
            return;
        }
        if(strcmp("2147483647", iter.toStdString().c_str()) < 0 || strcmp("-2147483648", iter.toStdString().c_str()) < 0){
            std::string message = "Integer overflow";
            Expression::writeToLogFile(message);
            ui->exception->setText(QString(message.c_str()));
            return;
        }
        numbersVector.push_back(iter.toDouble());
    }
    try {
        expression->setKVector(numbersVector);
    } catch (std::invalid_argument& e) {
        ui->exception->setText(QString(e.what()));
    }
}

void MainWindow::calculate() {
    try{
        ui->result->setText(QString::number(expression->calculate()));
    } catch (DividingOnZeroException& e) {
        std::string message = "Dividing on zero occurred\nduring calculation";
        Expression::writeToLogFile(message);
        ui->exception->setText(QString(message.c_str()));
    } catch (SquareRootOfNegativeNumberException& e) {
        ui->exception->setText(QString(e.getMessage().c_str()));
    } catch (LogarithmOfNegativeNumberException& e) {
        ui->exception->setText(QString(e.getMessage().c_str()));
    } catch(std::out_of_range& e){
        ui->exception->setText(QString(e.what()));
    }
}