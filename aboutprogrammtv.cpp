//
// Created by User on 23.02.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AboutProgramMTV.h" resolved

#include "aboutprogrammtv.h"
#include "ui_AboutProgramMTV.h"


AboutProgramMTV::AboutProgramMTV(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::AboutProgramMTV) {
    ui->setupUi(this);
    this->setFixedSize(this->width(), this -> height());
}

AboutProgramMTV::~AboutProgramMTV() {
    delete ui;
}

