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
    double nVectorSum = 0;
    for(int i = 0; i < n; i++){
        if(i >= nVector.size()){
            std::string message = "Sum counting went out\nof bounds in N vector";
            writeToLogFile(message);
            throw std::out_of_range(message);
        }
        nVectorSum += *(nVector.begin() + i);
    }
    nVectorSum *= sqrt(x);
    double mVectorSum = 0;
    for(int i = 0; i < m; i++){
        if(i >= mVector.size()){
            std::string message = "Sum counting went out\nof bounds in M vector";
            writeToLogFile(message);
            throw std::out_of_range(message);
        }
        mVectorSum += *(mVector.begin() + i);
    }
    mVectorSum *= log(100 - x);
    double kVectorSum = 0;
    for(int i = 0; i < k; i++){
        if(i >= kVector.size()){
            std::string message = "Sum counting went out\nof bounds in K vector";
            writeToLogFile(message);
            throw std::out_of_range(message);
        }
        kVectorSum += *(kVector.begin() + i);
    }
    kVectorSum /= x - 10;
    return nVectorSum + mVectorSum + kVectorSum;
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