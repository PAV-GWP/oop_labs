#include "Complex.h"
#include <cmath>

// выделяем память под статик полей
int Complex::objectCount = 0;
std::vector<std::string> Complex::history;

// конструктор по умолчанию (0 + 0i)
Complex::Complex()
    : real(0.0), imag(0.0), accessCount(0)
{
    objectCount++;
}

// параметризованный конструктор от одного числа (r + 0i)
Complex::Complex(double r)
    : real(r), imag(0.0), accessCount(0)
{
    objectCount++;
}

// полный параметризованный конструктор (r + i*i)
Complex::Complex(double r, double i)
    : real(r), imag(i), accessCount(0)
{
    objectCount++;
}

// деструктор
Complex::~Complex()
{
    objectCount--;
}

// работаем с mutable меняем поле в const
double Complex::getReal() const
{
    accessCount++;
    return real;
}
// геттер мнимой части
double Complex::getImag() const
{
    accessCount++;
    return imag;
}

// получение количества обращений к объекту
int Complex::getAccessCount() const
{
    return accessCount;
}
// кол-во живых объектов
int Complex::getObjectCount()
{
    return objectCount;
}

// добавление записи в историю операций
void Complex::addHistory(const std::string& operation)
{
    history.push_back(operation);
}
// Выовод истории
void Complex::printHistory()
{
    std::cout << "\n=== ИСТОРИЯ ОПЕРАЦИЙ КАЛЬКУЛЯТОРА ===" << std::endl;
    if (history.empty())
    {
        std::cout << "История пуста." << std::endl;
        return;
    }

    for (size_t i = 0; i < history.size(); ++i)
    {
        std::cout << i + 1 << ". " << history[i] << std::endl;
    }
    std::cout << "=====================================\n" << std::endl;
}

// вывод комплексного числа
void Complex::print() const
{
    accessCount++;
    if (imag >= 0)
    {
        std::cout << real << " + " << imag << "i";
    }
    else
    {
        std::cout << real << " - " << std::abs(imag) << "i";
    }
}