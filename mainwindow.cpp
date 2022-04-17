
#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->getFromLineEdit, SIGNAL(clicked(bool)), this, SLOT(getLineEdit()));
    connect(ui->chooseSlotInTable, SIGNAL(clicked(bool)), this, SLOT(changeSlotInTable()));
    connect(ui->getFromTable, SIGNAL(clicked(bool)), this, SLOT(getFromTable()));
    connect(ui->putInTable, SIGNAL(clicked(bool)), this, SLOT(putInTable()));
    connect(ui->editLineEdit, SIGNAL(clicked(bool)), this, SLOT(editInLineEdit()));
    connect(ui->saveLineEdit, SIGNAL(clicked(bool)), this, SLOT(saveLineEdit()));
    connect(ui->EditTextEdit, SIGNAL(clicked(bool)), this, SLOT(editInTextEdit()));
    connect(ui->saveTextEdit, SIGNAL(clicked(bool)), this, SLOT(saveTextEdit()));
    connect(ui->deleteSymbol, SIGNAL(clicked(bool)), this, SLOT(deleteSymbol()));
    connect(ui->replace, SIGNAL(clicked(bool)), this, SLOT(replace()));
    connect(ui->sort, SIGNAL(clicked(bool)), this, SLOT(sort()));
    connect(ui->insert, SIGNAL(clicked(bool)), this, SLOT(insert()));
    connect(ui->changeSize, SIGNAL(clicked(bool)), this, SLOT(changeSize()));
    connect(ui->concat, SIGNAL(clicked(bool)), this, SLOT(concatenate()));
    connect(ui->checkIsBigger, SIGNAL(clicked(bool)), this, SLOT(isBigger()));
    connect(ui->checkIsEqual, SIGNAL(clicked(bool)), this, SLOT(isEqual()));
    this->string = new String();
    string->setLabelToDisplay(ui->mainLabel);
    ui->saveLineEdit->setVisible(false);
    ui->saveTextEdit->setVisible(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::getLineEdit() {
    *string << *(ui->mainLineEdit);
}
void MainWindow::getFromTable() {
    *string << *(ui->tableWidget);
}
void MainWindow::changeSlotInTable() {
    string->setI(ui->iGetTable->text().toInt());
    string->setJ(ui->jGetTable->text().toInt());
}
void MainWindow::putInTable() {
    *string >> *(ui->tableWidget);
}
void MainWindow::editInLineEdit() {
    *string >> *(ui->mainLineEdit);
    ui->editLineEdit->setVisible(false);
    ui->saveLineEdit->setVisible(true);
}
void MainWindow::saveLineEdit() {
    strcpy(string->getString(), ui->mainLineEdit->text().toStdString().c_str());
    ui->saveLineEdit->setVisible(false);
    ui->editLineEdit->setVisible(true);
    *string >> *(ui->mainLabel);
    ui->mainLineEdit->clear();
}
void MainWindow::editInTextEdit() {
    *string >> *(ui->mainTextEdit);
    ui->EditTextEdit->setVisible(false);
    ui->saveTextEdit->setVisible(true);
}
void MainWindow::saveTextEdit() {
    strcpy(string->getString(), ui->mainTextEdit->toPlainText().toStdString().c_str());
    ui->saveTextEdit->setVisible(false);
    ui->EditTextEdit->setVisible(true);
    *string >> *(ui->mainLabel);
    ui->mainTextEdit->clear();
}
void MainWindow::deleteSymbol() {
    string->deleteSymbol(ui->iDeleteSymbol->text().toInt());
    *string >> *(ui->mainLabel);
}
void MainWindow::replace() {
    string->replaceSymbols(ui->c1Replace->text().toStdString().c_str()[0], ui->c2Replace->text().toStdString().c_str()[0]);
    *string >> *(ui->mainLabel);
}
void MainWindow::sort() {
    string->sort();
    *string >> *(ui->mainLabel);
}
void MainWindow::insert() {
    String* stringToInsert = new String();
    stringToInsert->setI(string->getI());
    stringToInsert->setJ(string->getJ());
    stringToInsert->setLabelToDisplay(ui->mainLabel);
    *stringToInsert << *(ui->tableWidget);
    string->insertStringAtPosition(ui->nInsert->text().toInt(), stringToInsert);
    *string >> *(ui->mainLabel);
}
void MainWindow::changeSize() {
    string->changeSize(ui->nChangeSize->text().toInt());
    *string >> *(ui->mainLabel);
}
void MainWindow::concatenate() {
    String* stringToCat = new String();
    stringToCat->setI(string->getI());
    stringToCat->setJ(string->getJ());
    stringToCat->setLabelToDisplay(ui->mainLabel);
    *stringToCat << *(ui->tableWidget);
    string->setString((*string + *stringToCat)->getString());
    *string >> *(ui->mainLabel);
}
void MainWindow::isBigger() {
    String* stringToCompare = new String();
    stringToCompare->setI(string->getI());
    stringToCompare->setJ(string->getJ());
    stringToCompare->setLabelToDisplay(ui->mainLabel);
    *stringToCompare << *(ui->tableWidget);
    if(*stringToCompare > *string){
        ui->isBigger->setText("Yes");
    }else{
        ui->isBigger->setText("No");
    }
    *string >> *(ui->mainLabel);
}
void MainWindow::isEqual() {
    String* stringToCompare = new String();
    stringToCompare->setI(string->getI());
    stringToCompare->setJ(string->getJ());
    stringToCompare->setLabelToDisplay(ui->mainLabel);
    *stringToCompare << *(ui->tableWidget);
    if(*stringToCompare == *string){
        ui->isEqual->setText("Yes");
    }else{
        ui->isEqual->setText("No");
    }
    *string >> *(ui->mainLabel);
}