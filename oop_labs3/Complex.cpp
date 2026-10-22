#include "Complex.h"
#include <cmath>
#include <stdexcept>

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

Complex& Complex::operator++()
{
    real += 1.0;
    addHistory("Префиксный инкремент (++real)");
    return *this; // возвращаем ссылку на сам текущий объект
}


Complex Complex::operator++(int)
{
    Complex temp = *this; // 1. создали копию с текущим состоянием
    real += 1.0;          // 2. изменили себя
    addHistory("Постфиксный инкремент (real++)");
    return temp;          // 3. вернули старую копию
}


Complex& Complex::operator--()
{
    real -= 1.0;
    addHistory("Префиксный декремент (--real)");
    return *this;
}


Complex Complex::operator--(int)
{
    Complex temp = *this;
    real -= 1.0;
    addHistory("Постфиксный декремент (real--)");
    return temp;
}

// арифм присваивание

Complex& Complex::operator+=(const Complex& other)
{
    real += other.real;
    imag += other.imag;
    addHistory("Сложение с присваиванием (+)");
    return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
    real -= other.real;
    imag -= other.imag;
    addHistory("Вычитание с присваиванием (-)");
    return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
    // Временные переменные нужны, чтобы при расчете imag 
    // не использовать уже перезаписанный real
    double newReal = real * other.real - imag * other.imag;
    double newImag = real * other.imag + imag * other.real;

    real = newReal;
    imag = newImag;
    addHistory("Умножение с присваиванием (*)");
    return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0.0)
    {
        throw std::invalid_argument("Ошибка: деление на ноль (нулевое комплексное число).");
    }

    double newReal = (real * other.real + imag * other.imag) / denominator;
    double newImag = (imag * other.real - real * other.imag) / denominator;

    real = newReal;
    imag = newImag;
    addHistory("Деление с присваиванием (/)");
    return *this;
}

// Расчет модуля комплексного числа
double Complex::getMagnitude() const
{
    return std::sqrt(real * real + imag * imag);
}

// Бинарные
// Первый аргумент lhs принимается по значению (создается копия),
// к нему применяется составное присваивание и он возвращается.
Complex operator+(Complex lhs, const Complex& rhs)
{
    lhs += rhs; // используем  +=
    return lhs;
}

Complex operator-(Complex lhs, const Complex& rhs)
{
    lhs -= rhs; // используем  -=
    return lhs;
}

Complex operator*(Complex lhs, const Complex& rhs)
{
    lhs *= rhs; // используем  *=
    return lhs;
}

Complex operator/(Complex lhs, const Complex& rhs)
{
    lhs /= rhs; // используем  /=
    return lhs;
}

// сравнения
// Равенство: равны и действительная, и мнимая части
bool Complex::operator==(const Complex& other) const
{
    return (real == other.real) && (imag == other.imag);
}

// Неравенство: отрицание равенства
bool Complex::operator!=(const Complex& other) const
{
    return !(*this == other);
}

// Меньше: сравнение модулей
bool Complex::operator<(const Complex& other) const
{
    return this->getMagnitude() < other.getMagnitude();
}

// Больше: сравнение модулей
bool Complex::operator>(const Complex& other) const
{
    return this->getMagnitude() > other.getMagnitude();
}

// Меньше или равно: не больше
bool Complex::operator<=(const Complex& other) const
{
    return !(*this > other);
}

// Больше или равно: не меньше
bool Complex::operator>=(const Complex& other) const
{
    return !(*this < other);
}