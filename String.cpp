//
// Created by User on 16.04.2022.
//

#include "String.h"
#include <cstdlib>
#include <cstring>
#include <cctype>

String::String() {
    this->string = (char*) malloc(1 * sizeof(char));
    this->string[0] = '\0';
}
String::String(char *string) {
    this->string = (char*) malloc(strlen(string) * sizeof(char));
    strcpy(this->string, string);
}
String::String(String *string) {
    this->string = (char*) malloc(strlen(string->string) * sizeof(char));
    strcpy(this->string, string->string);
}
void String::deleteSymbol(int index) {
    strcpy(&string[index], &string[index + 1]);
}
void String::replaceSymbols(char symbolToSwap, char swapSymbol) {
    char* symbolInStringToSwap;
    while((symbolInStringToSwap = strchr(this->string, symbolToSwap))){
        strncpy(symbolInStringToSwap, &swapSymbol, 1);
    }
}
void String::sort() {
    char min = 'z';
    int index;
    bool checked = false;
    for(int i = 0; i < (int)strlen(this->string); i++){
        for(int i2 = i; i2 < strlen(this->string); i2++){
            if(isalpha(this->string[i2])){
                char temp = toupper(this->string[i2]);
                char temp2 = toupper(min);
                if((strcmp(&temp2, &temp)) >= 0){
                    index = i2;
                    min = this->string[i2];
                    checked = true;
                }
            }
        }
        if(checked) {
            strncpy(&this->string[index], &this->string[i], 1);
            this->string[i] = min;
            checked = false;
        }
        min = 'z';
        index = 0;
    }
}
void String::insertStringAtPosition(int index, String *string) {
    char* newString = (char*) malloc((strlen(this->string) + strlen(string->string)) * sizeof(char));
    strncpy(newString, this->string, index);
    strncpy(&newString[index], string->string, strlen(string->string));
    strcpy(&newString[index + strlen(string->string)], &this->string[index]);
    this->string = newString;
}
void String::changeSize(int newSize) {
    char* newString = (char*) malloc((newSize + 1) * sizeof(char));
    if(newSize < strlen(this->string)){
        strncpy(newString, this->string, newSize);
    }else{
        strcpy(newString, this->string);
    }
    newString[newSize] = '\0';
    this->string = newString;
}
String* String::operator+(String &string) {
    String* newString = new String(strcat(this->string, string.string));
    return newString;
}
bool String::operator<(String &string) {
    if(strcmp(this->string, string.string) >= 0){
        return true;
    }else{
        return false;
    }
}
bool String::operator>(String &string) {
    if(strcmp(string.string, this->string) >= 0){
        return true;
    }else{
        return false;
    }
}
bool String::operator==(String &string) {
    if(!(strcmp(this->string, string.string))){
        return true;
    }else{
        return false;
    }
}
char String::operator[](int index) {
    return this->string[index];
}
String& String::operator=(String &string) {
    this->string = (char*) malloc(strlen(string.string) * sizeof(char));
    strcpy(this->string, string.string);
    return *this;
}
String::~String() {
    free(this->string);
}
void operator<<(String& string, QLineEdit& lineEdit){
    strcpy(string.string, lineEdit.text().toStdString().c_str());
    lineEdit.clear();
    string >> *string.labelToDisplay;
}
void operator<<(String& string, QTableWidget& table){
    QTableWidgetItem* item = table.item(string.i, string.j);
    strcpy(string.string, item->text().toStdString().c_str());
    string >> *string.labelToDisplay;
}
int String::getI(){
    return this->j;
}
int String::getJ() {
    return this->j;
}
void String::setI(int i) {
    this->i = i;
}
void String::setJ(int j) {
    this->j= j;
}
void String::setLabelToDisplay(QLabel *labelToDisplay) {
    this->labelToDisplay = labelToDisplay;
}
void operator>>(String& string, QLabel& label){
    label.setText(QString(string.string));
}
void operator>>(String& string, QTableWidget& table){
    QTableWidgetItem* item = new QTableWidgetItem(QString(string.string));
    table.setItem(string.i, string.j, item);
}
void operator>>(String& string, QLineEdit& lineEdit){
    lineEdit.setText(QString(string.string));
}
void operator>>(String& string, QTextEdit& textEdit){
    textEdit.setText(QString(string.string));
}
char* String::getString(){
    return this->string;
}
void String::setString(char *string) {
    this->string = string;
}