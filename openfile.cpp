//
// Created by User on 20.03.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_OpenFile.h" resolved

#include "openfile.h"
#include "ui_OpenFile.h"


OpenFile::OpenFile(QWidget *parent, mainWindow* creator) :
        QWidget(parent), ui(new Ui::OpenFile) {
    ui->setupUi(this);
    this->creator = creator;
    connect(ui->open, SIGNAL(clicked(bool)), this, SLOT(open()));
    connect(ui->cancel, SIGNAL(clicked(bool)), this, SLOT(cancel()));
}

OpenFile::~OpenFile() {
    delete ui;
}

void OpenFile::open() {
    creator->showOpened(ui->lineEdit->text().toStdString());
    close();
}
void OpenFile::cancel() {
    close();
}