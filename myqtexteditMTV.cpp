#include "myqtexteditMTV.h"
#include "ui_MyQTextEdit.h"
#include <QMenu>
#include <QChar>
#include <QLineEdit>
#include "notepadMTV.h"
#include <QContextMenuEvent>
Notepad* parentNotepadCasted;
MyQTextEdit::MyQTextEdit(QWidget *parent) :
        QTextEdit(parent), ui(new Ui::MyQTextEdit) {
    ui->setupUi(this);
    parentNotepadCasted = (Notepad*) parent;
//    connect(this, SIGNAL(textChanged()), this, SLOT(textEdited()));
}

MyQTextEdit::~MyQTextEdit() {
    delete ui;
}

void MyQTextEdit::contextMenuEvent(QContextMenuEvent *event){
    QMenu* contextMenu = new QMenu();
    contextMenu->addAction("Undo", this, SLOT(undo()));
    contextMenu->addAction("Redo", this, SLOT(redo()));
    contextMenu->addAction("Cut", this, SLOT(cut()));
    contextMenu->addAction("Copy", this, SLOT(copy()));
    contextMenu->addAction("Paste", this, SLOT(paste()));
    contextMenu->addAction("Find", this, SLOT(findTriggered()));
    contextMenu->addAction("Select All", this, SLOT(selectAll()));
    contextMenu->exec(event->globalPos());
}
void MyQTextEdit::findTriggered() {
    return;
}