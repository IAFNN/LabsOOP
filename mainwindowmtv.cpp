//
// Created by User on 08.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindowMTV.h" resolved

#include "mainwindowmtv.h"
#include "ui_MainWindowMTV.h"

const int NEGATIVE_INFINITY = -10000000;
const int POSITIVE_INFINITY = 10000000;
const auto CONDITION = [](std::vector<double>& container){
    std::vector<double> elements;
    for(double& iter : container){
        if(iter > 100){
            elements.push_back(iter);
        }
    }
    return elements;
};
MainWindowMTV::MainWindowMTV(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindowMTV) {
    ui->setupUi(this);
    connect(ui->put, SIGNAL(clicked(bool)), this, SLOT(put()));
    connect(ui->edit, SIGNAL(clicked(bool)), this, SLOT(edit()));
    connect(ui->delete_2, SIGNAL(clicked(bool)), this, SLOT(deleteElement()));
    connect(ui->print, SIGNAL(clicked(bool)), this, SLOT(print()));
    connect(ui->step6, SIGNAL(clicked(bool)), this, SLOT(step6()));
    connect(ui->sort, SIGNAL(clicked(bool)), this, SLOT(sort()));
    connect(ui->find, SIGNAL(clicked(bool)), this, SLOT(find()));
    connect(ui->step13, SIGNAL(clicked(bool)), this, SLOT(step13()));
    connect(ui->step15, SIGNAL(clicked(bool)), this, SLOT(step15()));
    connect(ui->step17, SIGNAL(clicked(bool)), this, SLOT(step17()));
}

MainWindowMTV::~MainWindowMTV() {
    delete ui;
}

void MainWindowMTV::put() {
    if(ui->firstContainer->isChecked()) {
        ui->listWidget->addItem(QString::number(ui->lineEdit->text().toDouble()));
        firstContainer.push_back(ui->lineEdit->text().toDouble());
    }
    if(ui->secondContainer->isChecked()){
        ui->listWidget_2->insertItem(0, QString::number(ui->lineEdit->text().toDouble()));
        secondContainer.push(ui->lineEdit->text().toDouble());
    }
}


void MainWindowMTV::edit() {
    int index = ui->listWidget->currentRow();
    ui->listWidget->takeItem(index);
    firstContainer.erase(firstContainer.cbegin() + index);
    firstContainer.insert(firstContainer.cbegin() + index, ui->lineEdit->text().toDouble());
    ui->listWidget->insertItem(index, ui->lineEdit->text());
}

void MainWindowMTV::deleteElement() {
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void MainWindowMTV::print() {
    QString* text = new QString();
    if(ui->firstContainer->isChecked()) {
        for (std::vector<double>::iterator iter = firstContainer.begin(); iter != firstContainer.end(); iter++) {
            text->append(QString::number(*iter) + "\t");
        }
    }else{
        std::stack<double> copy(secondContainer);
        for(int i = 0; i < secondContainer.size(); i++){
            text->append(QString::number(copy.top()) + "\t");
            copy.pop();
        }
    }
    ui->output->setText(*text);
    delete text;
}

void MainWindowMTV::step6() {
    std::vector<double>::iterator begin = firstContainer.begin() + ui->listWidget->currentRow() + 1;
    firstContainer.erase(begin, begin + ui->nEdit->text().toInt());
    int size = secondContainer.size();
    for(int i = 0; i < size; i++){
        firstContainer.insert(begin + i, secondContainer.top());
        secondContainer.pop();
    }
    ui->listWidget_2->clear();
    refreshFirstContainer();
}

void MainWindowMTV::refreshFirstContainer() {
    ui->listWidget->clear();
    for(int i = 0; i < firstContainer.size(); i++){
        ui->listWidget->addItem(QString::number(*(firstContainer.begin() + i)));
    }
}

void MainWindowMTV::sortVector(std::vector<double> vector, bool increasingOrder) {
    for (int i = 0; i < vector.size(); i++){
        double extreme;
        std::vector<double>::iterator extremeElement;
        if(!increasingOrder){
            extreme = NEGATIVE_INFINITY;
            for(int i2 = i; i2 < vector.size(); i2++){
                if(*(vector.begin() + i2) > extreme){
                    extreme = *(vector.begin() + i2);
                    extremeElement = vector.begin() + i2;
                }
            }
        }else{
            extreme = POSITIVE_INFINITY;
            for(int i2 = i; i2 < vector.size(); i2++){
                if((*vector.begin() + i2) < extreme){
                   extreme = *(vector.begin() + i2);
                   extremeElement = vector.begin() + i2;
                }
            }
        }
        vector.erase(extremeElement);
        vector.insert(vector.begin() + i, extreme);
    }
}
void MainWindowMTV::sort() {
    sortVector(firstContainer, false);
    refreshFirstContainer();
}

void MainWindowMTV::find() {
    ui->listWidget_2->clear();
    std::vector<double> elements = CONDITION(firstContainer);
    ui->found->setText(QString::number(*(elements.begin())));
    for(std::vector<double>::iterator iter = elements.end() - 1; iter != elements.begin() - 1; iter--){
        secondContainer.push(*iter);
        ui->listWidget_2->insertItem(0, QString::number(*iter));
    }
}

void MainWindowMTV::refreshSecondContainer() {
    ui->listWidget_2->clear();
    std::stack<double> copy(secondContainer);
    for(int i = 0; i < secondContainer.size(); i++){
        ui->listWidget_2->addItem(QString::number(copy.top()));
        copy.pop();
    }
}

void MainWindowMTV::step13() {
    sortVector(firstContainer, true);
    refreshFirstContainer();
    std::vector<double> stackCopy;
    refreshSecondContainer();
    for(int i = 0; ui->listWidget_2->count(); i++){
        stackCopy.push_back(ui->listWidget_2->item(i)->text().toDouble());
    }
    sortVector(stackCopy, true);
    refreshSecondContainer();
}

void MainWindowMTV::step15() {
    thirdContainer = firstContainer;
    for(int i = 0; i < secondContainer.size(); i++) {
        thirdContainer.push_back(ui->listWidget_2->item(i)->text().toDouble());
    }
    for(double& iter : thirdContainer){
        ui->listWidget_3->addItem(QString::number(iter));
    }
}

void MainWindowMTV::step17() {
    std::vector<double> elements = CONDITION(thirdContainer);
    ui->counted->setText(QString::number(elements.size()));
}