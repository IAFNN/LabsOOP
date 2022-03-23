//
// Created by User on 20.02.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Notepad.h" resolved

#include "notepadMTV.h"
#include "ui_Notepad.h"
#include "myqtexteditMTV.h"
#include "aboutprogrammtv.h"
#include <cstdio>
#include "saveasMTV.h"
#include "closefileMTV.h"
#include "CloseEventFilterMTV.h"
#include "openfileMTV.h"
MyQTextEdit* textEdit;
FILE* fileInUse = nullptr;
saveAs* saveAsWindow;
bool isSaved = true;
QString previousText = nullptr;
CloseEventFilterMTV* eventFilter1;
Notepad::Notepad(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::Notepad) {
    ui->setupUi(this);
    connect(ui->actionAbout_Us, SIGNAL(triggered(bool)), this, SLOT(aboutUsTriggered()));
    textEdit = new MyQTextEdit(ui->centralwidget);
    textEdit->resize(this->width(), this->height() - ui->menuBar->height());
    connect(ui->actionUndo, SIGNAL(triggered(bool)), textEdit, SLOT(undo()));
    connect(ui->actionCut, SIGNAL(triggered(bool)), textEdit, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered(bool)), textEdit, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered(bool)), textEdit, SLOT(paste()));
    connect(ui->actionFind, SIGNAL(triggered(bool)), textEdit, SLOT(findTriggered()));
    connect(ui->actionSelect_All, SIGNAL(triggered(bool)), textEdit, SLOT(selectAll()));
    connect(ui->actionRedo, SIGNAL(triggered(bool)), textEdit, SLOT(redo()));
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save()));
    connect(ui->actionSave_as, SIGNAL(triggered(bool)), this, SLOT(createSaveAsWindow()));
    connect(textEdit, SIGNAL(textChanged()), this, SLOT(textEdited()));
    connect(ui->actionNew, SIGNAL(triggered(bool)), this, SLOT(newFile()));
    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(open()));
    eventFilter1 = new CloseEventFilterMTV();
    this->installEventFilter(eventFilter1);
}

Notepad::~Notepad() {
    fclose(fileInUse);
    delete ui;
}

void Notepad::resizeEvent(QResizeEvent *event) {
    ui->centralwidget->resize(this->width(), this->height());
    textEdit->resize(this->width(), this->height() - ui->menuBar->height());
}
void Notepad::aboutUsTriggered(){
    AboutProgramMTV* aboutProgramWindow = new AboutProgramMTV();
    aboutProgramWindow->show();
}
void Notepad::save(bool isBeforeClosing) {
    if(fileInUse != nullptr) {
        rewind(fileInUse);
        if(previousText == nullptr) {
            fputs(textEdit->toPlainText().toStdString().c_str(), fileInUse);
        }else{
            fputs(previousText.toStdString().c_str(), fileInUse);
            setWindowTitle(*(new QString("Notepad")));
            previousText = nullptr;
        }
        isSaved = true;
        if(this->windowTitle().toStdString().c_str()[0] == '*'){
            setWindowTitle(windowTitle().remove(0, 1));
        }
        if(isBeforeClosing){
            close();
        }
    }else{
        createSaveAsWindow(isBeforeClosing);
    }
}
void Notepad::createSaveAsWindow(bool isBeforeClosing) {
    saveAsWindow = new class saveAs(nullptr, this, isBeforeClosing);
    saveAsWindow->exec();
}
void Notepad::saveToPath(bool isBeforeClosing) {
    fclose(fileInUse);
    fileInUse = fopen(saveAsWindow->filepath.c_str(), "w");
    setWindowTitle(*(new QString(saveAsWindow->filepath.c_str())));
    save(isBeforeClosing);
    saveAsWindow->close();
}
void Notepad::textEdited() {
    if(this->windowTitle().toStdString().c_str()[0] != '*') {
        this->setWindowTitle("*" + this->windowTitle());
        isSaved = false;
    }
}
void Notepad::beforeClosing(bool isBeforeClosing) {
    if(!isSaved){
        closeFile* closeFileWindow = new closeFile(nullptr, this, isBeforeClosing);
        closeFileWindow->show();
    }else{
        delete this;
    }
}
void Notepad::newFile() {
    if(!isSaved){
        beforeClosing(false);
        previousText = textEdit->toPlainText();
    }
    textEdit->clear();
    fclose(fileInUse);
    setWindowTitle("Notepad");
}
void Notepad::open() {
    OpenFile* openFileWindow = new OpenFile(nullptr, this);
    openFileWindow->show();
    if(!isSaved){
        beforeClosing(false);
        previousText = textEdit->toPlainText();
    }
}
void Notepad::showOpened(std::string filepath){
    textEdit->clear();
    fclose(fileInUse);
    fileInUse = fopen(filepath.c_str(), "r+");
    QString* textInFile = new QString();
    while(!feof(fileInUse)){
        char* temp = (char*)malloc(1000 * sizeof(char));
        textInFile->append(fgets(temp, 1000, fileInUse));
        free(temp);
    }
    textEdit->setText(*textInFile);
    isSaved = true;
    setWindowTitle(*(new QString(filepath.c_str())));
}
