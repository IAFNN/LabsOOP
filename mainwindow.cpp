#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
int result;
std::string firstNumberStr;
std::string secondNumberStr;
bool isFirstnumber = true;
enum Operations {
    plus,
    minus,
    divide,
    multiply
};
Operations operation;
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plusButton_clicked()
{
    ui->operation->setText("+");
    operation = plus;
    isFirstnumber = false;
}


void MainWindow::on_minusButton_clicked()
{
    ui->operation->setText("-");
    operation = minus;
    isFirstnumber = false;
}


void MainWindow::on_multiplyButton_clicked()
{
    ui->operation->setText("*");
    operation = multiply;
    isFirstnumber = false;
}


void MainWindow::on_divideButton_clicked()
{
    ui->operation->setText("/");
    operation = divide;
    isFirstnumber = false;
}

void MainWindow::on_calculateButton_clicked()
{
    int firstNumber = ui->firstNumber->text().toInt();
    int secondNumber = ui->secondNumber->text().toInt();
    switch(operation){
        case plus:
            ui->result->setText(*(new QString(std::to_string(firstNumber + secondNumber).c_str())));
            break;
        case minus:
            ui->result->setText(*(new QString(std::to_string(firstNumber - secondNumber).c_str())));
            break;
        case multiply:
            ui->result->setText(*(new QString(std::to_string(firstNumber * secondNumber).c_str())));
            break;
        case divide:
            ui->result->setText(*(new QString(std::to_string(((double)firstNumber) / secondNumber).c_str())));
            break;
    }
}
void MainWindow::on_clearButton_clicked(){
    ui->operation->setText(*(new QString("")));
    ui->result->setText(*(new QString("")));
    ui->firstNumber->clear();
    ui->secondNumber->clear();
    firstNumberStr = "";
    secondNumberStr = "";
    isFirstnumber = true;
}
void MainWindow::on_buttonClicked() {
    QPushButton* button = (QPushButton*) sender();
    if(isFirstnumber){
        firstNumberStr.append(button->accessibleName().toStdString());
        ui -> firstNumber ->setText(*(new QString(firstNumberStr.c_str())));
    }else{
        secondNumberStr.append(button->accessibleName().toStdString());
        ui -> secondNumber ->setText(*(new QString(secondNumberStr.c_str())));
    }
}
