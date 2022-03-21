//
// Created by User on 20.03.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainWindow.h"
#include <QPixmap>
#include <QImage>
#include "openfile.h"
#include "saveas.h"
saveAs* saveAsWindow;
mainWindow::mainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);
    connect(ui->open, SIGNAL(clicked(bool)), this, SLOT(open()));
    connect(ui->save, SIGNAL(clicked(bool)), this, SLOT(createSaveAsWindow()));
}

mainWindow::~mainWindow() {
    delete ui;
}

void mainWindow::open() {
    OpenFile* openFileWindow = new OpenFile(nullptr, this);
    openFileWindow->show();
}
void mainWindow::showOpened(std::string filepath){
    QPixmap* image = new QPixmap(filepath.c_str());
    ui->image->setPixmap((*image).scaled(ui->image->width(), ui->image->height()));
}
void mainWindow::createSaveAsWindow() {
    saveAsWindow = new class saveAs(nullptr, this);
    saveAsWindow->show();
}
void mainWindow::saveToPath() {
    ui->image->pixmap()->save(saveAsWindow->filepath.c_str());
    saveAsWindow->close();
}