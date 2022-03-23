//
// Created by User on 19.03.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_closeFile.h" resolved

#include "closefileMTV.h"
#include "ui_closeFile.h"
#include "notepadMTV.h"

closeFile::closeFile(QWidget *parent, Notepad* sender, bool isBeforeClosing) :
        QDialog(parent), ui(new Ui::closeFile) {
    ui->setupUi(this);
    this->sender = sender;
    this->isBeforeClosing = isBeforeClosing;
    connect(ui->save, SIGNAL(clicked(bool)), this, SLOT(save()));
    connect(ui->notSave, SIGNAL(clicked(bool)), this, SLOT(notSave()));
    setWindowModality(Qt::ApplicationModal);
}

closeFile::~closeFile() {
    delete ui;
}

void closeFile::save() {
    close();
    sender->save(isBeforeClosing);
}
void closeFile::notSave() {
    close();
    if(isBeforeClosing) {
        sender->close();
    }
}