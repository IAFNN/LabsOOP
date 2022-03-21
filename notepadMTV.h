//
// Created by User on 20.02.2022.
//

#ifndef LAB3OOP_NOTEPADMTV_H
#define LAB3OOP_NOTEPADMTV_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow {
Q_OBJECT

public:
    explicit Notepad(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event) override;
    ~Notepad() override;
    void beforeClosing(bool isBeforeClosing);
    void showOpened(std::string);
public slots:
    void save(bool isBeforeClosing = false);
    void textEdited();
private slots:
    void aboutUsTriggered();
    void createSaveAsWindow(bool isBeforeClosing = false);
    void newFile();
    void open();
private:
    Ui::Notepad *ui;
public:
    void saveToPath(bool);

};


#endif //LAB3OOP_NOTEPADMTV_H
