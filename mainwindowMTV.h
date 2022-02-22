#ifndef MAINWINDOWMTV_H
#define MAINWINDOWMTV_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowMTV; }
QT_END_NAMESPACE

class MainWindowMTV : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindowMTV(QWidget *parent = nullptr);
    ~MainWindowMTV() override;

private slots:
    void on_plusButtonMTV_clicked();

    void on_minusButtonMTV_clicked();

    void on_multiplyButtonMTV_clicked();

    void on_divideButtonMTV_clicked();

    void on_calculateButtonMTV_clicked();

    void on_clearButtonMTV_clicked();

    void on_buttonClicked();

private:
    Ui::MainWindowMTV *ui;
};
#endif
