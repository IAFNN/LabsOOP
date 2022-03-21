//
// Created by User on 19.03.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_saveAs.h" resolved

#include "saveasMTV.h"
#include "ui_saveAs.h"
saveAs::saveAs(QWidget *parent, mainWindow* creator) :
        QDialog(parent), ui(new Ui::saveAs) {
    ui->setupUi(this);
    this->creator = creator;
    connect(ui->save, SIGNAL(clicked(bool)), this, SLOT(save()));
    connect(ui->cancel, SIGNAL(clicked(bool)), this, SLOT(cancel()));
}

saveAs::~saveAs() {
    delete ui;
}

void saveAs::save() {
    filepath = ui->lineEdit->text().toStdString();
    creator->saveToPath();
}
void saveAs::cancel() {
    close();
}
