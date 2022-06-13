//
// Created by User on 11.05.2022.
//

#include "Expression.h"
#include <fstream>
#include <ctime>

double Expression::calculate() {
    if(x < 0){
        std::string message = "You are trying to find\nsquare root of " + std::to_string(x);
        writeToLogFile(message);
        throw SquareRootOfNegativeNumberException(message);
    }
    if(100 - x <= 0){
        std::string message = "You are trying to find\nnatural logarithm of " + std::to_string(100 - x);
        writeToLogFile(message);
        throw LogarithmOfNegativeNumberException(message);
    }
    if(x - 10 == 0){
        throw DividingOnZeroException();
    }
    float overflowTest = 0;
    double nVectorSum = 0;
    for(int i = 0; i < n; i++){
        if(i >= nVector.size()){
            std::string message = "Sum counting went out\nof bounds in N vector";
            writeToLogFile(message);
            throw std::out_of_range(message);
        }
        overflowTest += *(nVector.begin() + i);
        nVectorSum += *(nVector.begin() + i);
        if(overflowTest != nVectorSum){
            std::string message = "Overflow occured during\ncalculations with" + std::to_string(overflowTest);
            writeToLogFile(message);
            throw std::overflow_error(message);
        }
    }
    nVectorSum *= sqrt(x);
    overflowTest *= sqrt(x);
    if(overflowTest != nVectorSum){
        std::string message = "Overflow occured during\ncalculations with" + std::to_string(overflowTest);
        writeToLogFile(message);
        throw std::overflow_error(message);
    }
    overflowTest = 0;
    double mVectorSum = 0;
    for(int i = 0; i < m; i++){
        if(i >= mVector.size()){
            std::string message = "Sum counting went out\nof bounds in M vector";
            writeToLogFile(message);
            throw std::out_of_range(message);
        }
        overflowTest += *(mVector.begin() + i);
        mVectorSum += *(mVector.begin() + i);
        if(overflowTest != mVectorSum){
            std::string message = "Overflow occured during\ncalculations with" + std::to_string(overflowTest);
            writeToLogFile(message);
            throw std::overflow_error(message);
        }
    }
    overflowTest *= log(100 - x);
    mVectorSum *= log(100 - x);
    if(overflowTest != nVectorSum){
        std::string message = "Overflow occured during\ncalculations with" + std::to_string(overflowTest);
        writeToLogFile(message);
        throw std::overflow_error(message);
    }
    double kVectorSum = 0;
    overflowTest = 0;
    for(int i = 0; i < k; i++){
        if(i >= kVector.size()){
            std::string message = "Sum counting went out\nof bounds in K vector";
            writeToLogFile(message);
            throw std::out_of_range(message);
        }
        overflowTest += *(kVector.begin() + i);
        kVectorSum += *(kVector.begin() + i);
        if(overflowTest != kVectorSum){
            std::string message = "Overflow occured during\ncalculations with" + std::to_string(overflowTest);
            writeToLogFile(message);
            throw std::overflow_error(message);
        }
    }
    overflowTest /= x - 10;
    kVectorSum /= x - 10;
    if(overflowTest != nVectorSum){
        std::string message = "Overflow occured during\ncalculations with" + std::to_string(overflowTest);
        writeToLogFile(message);
        throw std::overflow_error(message);
    }
    nVectorSum += mVectorSum + kVectorSum;
    overflowTest = nVectorSum + mVectorSum + kVectorSum;
    if(overflowTest != nVectorSum){
        std::string message = "Overflow occured during\ncalculations with" + std::to_string(overflowTest);
        writeToLogFile(message);
        throw std::overflow_error(message);
    }
    return nVectorSum;
}

void Expression::setN(int n) {
    if(n <= 0){
        std::string message = "N is negative or equals 0";
        writeToLogFile(message);
        throw std::range_error(message);
    }
    this->n = n;
}

void Expression::setM(int m) {
    if(m <= 0){
        std::string message = "M is negative or equals 0";
        writeToLogFile(message);
        throw std::range_error(message);
    }
    this->m = m;
}

void Expression::setK(int k) {
    if(k <= 0){
        std::string message = "K is negative or equals 0";
        writeToLogFile(message);
        throw std::range_error(message);
    }
    this->k = k;
}

void Expression::setX(double x) {
    this->x = x;
}

void Expression::setNVector(std::vector<double> nVector) {
    if(nVector.size() > n){
        std::string message = "Size of N vector doesn't match N";
        writeToLogFile(message);
        throw std::invalid_argument(message);
    }
    this->nVector = nVector;
}

void Expression::setMVector(std::vector<double> mVector) {
    if(mVector.size() > m){
        std::string message = "Size of M vector doesn't match M";
        writeToLogFile(message);
        throw std::invalid_argument(message);
    }
    this->mVector = mVector;
}

void Expression::setKVector(std::vector<double> kVector) {
    if(kVector.size() > k){
        std::string message = "Size of K vector doesn't match K";
        writeToLogFile(message);
        throw std::invalid_argument(message);
    }
    this->kVector = kVector;
}

void Expression::writeToLogFile(const std::string& message) {
    std::ofstream file;
    file.open("log.txt", std::ios::app);
    std::time_t t = std::time(nullptr);
    file << std::asctime(std::localtime(&t));
    file << message << std::endl << std::endl;
    file.close();
}