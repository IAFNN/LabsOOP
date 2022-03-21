//
// Created by User on 20.02.2022.
//

#ifndef LAB3OOP_MYQTEXTEDITMTV_H
#define LAB3OOP_MYQTEXTEDITMTV_H

#include <QTextEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class MyQTextEdit; }
QT_END_NAMESPACE

class MyQTextEdit : public QTextEdit {
Q_OBJECT

public:
    explicit MyQTextEdit(QWidget *parent = nullptr);
    void contextMenuEvent(QContextMenuEvent *event) override;
    ~MyQTextEdit() override;

public slots:
    void findTriggered();
private:
    Ui::MyQTextEdit *ui;
};


#endif //LAB3OOP_MYQTEXTEDITMTV_H
