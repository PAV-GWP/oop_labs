#pragma once

#include <iostream>
#include <string>
#include <vector>

class Complex{
private:
    double real;
    double imag;
    mutable int accessCount;
    static int objectCount;
    static std::vector<std::string> history;

public:
    Complex(); // конструктор создаёт (0 + 0i)
    explicit Complex(double r); // Параметризованный конструктор
    Complex(double r, double i); // Полный параметризованный конструктор
    ~Complex();
    // методы чтения
    double getReal() const;
    double getImag() const;
    int getAccessCount() const;

    static int getObjectCount();
    static void printHistory();
    static void addHistory(const std::string& operation);

    void print() const;
};