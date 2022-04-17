
#ifndef LAB7OOP_STRING_H
#define LAB7OOP_STRING_H
#include <QLineEdit>
#include <QTableWidget>
#include <QLabel>
#include <QTextEdit>

class String {
private:
    char* string;
    int i;
    int j;
    QLabel* labelToDisplay;
public:
    String();
    String(char* string);
    String(String* string);
    void deleteSymbol(int index);
    void replaceSymbols(char symbolToSwap, char swapSymbol);
    void sort();
    void insertStringAtPosition(int index, String* string);
    void changeSize(int newSize);
    String* operator+(String& string);
    bool operator<(String& string);
    bool operator>(String& string);
    bool operator==(String& string);
    char operator[](int index);
    String& operator=(String& string);
    ~String();
    friend void operator<<(String& string, QLineEdit& lineEdit);
    friend void operator<<(String& string, QTableWidget& table);
    friend void operator>>(String& string, QLabel& label);
    friend void operator>>(String& string, QTableWidget& table);
    friend void operator>>(String& string, QLineEdit& lineEdit);
    friend void operator>>(String& string, QTextEdit& textEdit);
    int getI();
    int getJ();
    void setI(int i);
    void setJ(int j);
    void setLabelToDisplay(QLabel* labelToDisplay);
    char* getString();
    void setString(char* string);
};

#endif //LAB7OOP_STRING_H
