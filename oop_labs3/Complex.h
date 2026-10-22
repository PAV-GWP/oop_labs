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
    // Префиксный инкремент: ++z 
    Complex& operator++();

    // Постфиксный инкремент: z++
    Complex operator++(int);

    // Префиксный декремент: --z
    Complex& operator--();

    // Постфиксный декремент: z--
    Complex operator--(int);

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    double getMagnitude() const;
    // Реализуются через friend-функции с переиспользованием +=, -=, *=, /=
    friend Complex operator+(Complex lhs, const Complex& rhs);
    friend Complex operator-(Complex lhs, const Complex& rhs);
    friend Complex operator*(Complex lhs, const Complex& rhs);
    friend Complex operator/(Complex lhs, const Complex& rhs);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator<=(const Complex& other) const;
    bool operator>=(const Complex& other) const;

    // ввод вывод
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};