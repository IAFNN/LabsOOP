#include "mainwindowMTV.h"
#include "./ui_mainwindowMTV.h"
#include <string>
std::string firstNumberStr;
std::string secondNumberStr;
bool isFirstNumber = true;
enum Operations {
    plus,
    minus,
    divide,
    multiply
};
Operations operation;
MainWindowMTV::MainWindowMTV(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindowMTV)
{
    ui->setupUi(this);
    this->setFixedSize(400, 500);
    for(int i = 0; i < 10; i++){
        QPushButton* button = new QPushButton(this);
        button->setFixedSize(100, 100);
        if(i == 9){
            button->setText(*(new QString("0")));
            button->setAccessibleName(*(new QString("0")));
        }else {
            button->setText(*(new QString(std::to_string(i + 1).c_str())));
            button->setAccessibleName(*(new QString(std::to_string(i + 1).c_str())));
        }
        button->move((i / 4) * 100, (i % 4) * 100 + 100);
        connect(button, SIGNAL(clicked()), this, SLOT(on_buttonClicked()));
    }
}

MainWindowMTV::~MainWindowMTV()
{
    delete ui;
}

void MainWindowMTV::on_plusButtonMTV_clicked()
{
    ui->operationMTV->setText("+");
    operation = plus;
    isFirstNumber = false;
}


void MainWindowMTV::on_minusButtonMTV_clicked()
{
    ui->operationMTV->setText("-");
    operation = minus;
    isFirstNumber = false;
}


void MainWindowMTV::on_multiplyButtonMTV_clicked()
{
    ui->operationMTV->setText("*");
    operation = multiply;
    isFirstNumber = false;
}


void MainWindowMTV::on_divideButtonMTV_clicked()
{
    ui->operationMTV->setText("/");
    operation = divide;
    isFirstNumber = false;
}

void MainWindowMTV::on_calculateButtonMTV_clicked()
{
    int firstNumber = ui->firstNumberMTV->text().toInt();
    int secondNumber = ui->secondNumberMTV->text().toInt();
    switch(operation){
        case plus:
            ui->resultMTV->setText(*(new QString(std::to_string(firstNumber + secondNumber).c_str())));
            break;
        case minus:
            ui->resultMTV->setText(*(new QString(std::to_string(firstNumber - secondNumber).c_str())));
            break;
        case multiply:
            ui->resultMTV->setText(*(new QString(std::to_string(firstNumber * secondNumber).c_str())));
            break;
        case divide:
            ui->resultMTV->setText(*(new QString(std::to_string(((double)firstNumber) / secondNumber).c_str())));
            break;
    }
}
void MainWindowMTV::on_clearButtonMTV_clicked(){
    ui->operationMTV->setText(*(new QString("")));
    ui->resultMTV->setText(*(new QString("")));
    ui->firstNumberMTV->clear();
    ui->secondNumberMTV->clear();
    firstNumberStr = "";
    secondNumberStr = "";
    isFirstNumber = true;
}
void MainWindowMTV::on_buttonClicked() {
    QPushButton* button = (QPushButton*) sender();
    if(isFirstNumber){
        firstNumberStr.append(button->accessibleName().toStdString());
        ui -> firstNumberMTV->setText(*(new QString(firstNumberStr.c_str())));
    }else{
        secondNumberStr.append(button->accessibleName().toStdString());
        ui -> secondNumberMTV->setText(*(new QString(secondNumberStr.c_str())));
    }
}
