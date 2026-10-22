/**
 * @file Complex.h
 * @brief Заголовочный файл с объявлением класса Complex (Калькулятор комплексных чисел).
 * @author Царицон Павел
 * @date 2026
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Complex
 * @brief Класс, моделирующий математическое комплексное число вида a + bi.
 * 
 * Класс инкапсулирует действительную и мнимую части, предоставляет
 * перегруженные унарные и бинарные операторы, составные присваивания,
 * операторы сравнения и потокового ввода/вывода, а также ведёт историю вычислений.
 */
class Complex
{
private:
    double real; ///< Действительная часть комплексного числа (a)
    double imag; ///< Мнимая часть комплексного числа (b)

    /**
     * @brief Счётчик обращений к состоянию объекта.
     * 
     * Объявлен со спецификатором mutable, что позволяет модифицировать
     * его значение даже внутри константных методов (const) и для константных экземпляров.
     */
    mutable int accessCount;

    /**
     * @brief Статический счётчик общего количества существующих в памяти объектов Complex.
     */
    static int objectCount;

    /**
     * @brief Общий статический журнал истории выполненных математических операций калькулятора.
     */
    static std::vector<std::string> history;

public:
    /**
     * @brief Конструктор по умолчанию.
     * Инициализирует комплексное число значением (0.0 + 0.0i).
     */
    Complex();

    /**
     * @brief Параметризованный конструктор от одного вещественного числа.
     * @param r Действительная часть комплексного числа (мнимая устанавливается в 0.0).
     * 
     * Спецификатор explicit предотвращает нежелательные неявные преобразования типов из double в Complex.
     */
    explicit Complex(double r);

    /**
     * @brief Полный параметризованный конструктор.
     * @param r Действительная часть.
     * @param i Мнимая часть.
     */
    Complex(double r, double i);

    /**
     * @brief Деструктор класса.
     * Уменьшает статический счётчик живых объектов в памяти.
     */
    ~Complex();

    /**
     * @brief Получение действительной части числа.
     * @return Действительная часть (real).
     * @note Является const-методом, увеличивает счётчик accessCount (демонстрация mutable).
     */
    double getReal() const;

    /**
     * @brief Получение мнимой части числа.
     * @return Мнимая часть (imag).
     * @note Является const-методом, увеличивает счётчик accessCount (демонстрация mutable).
     */
    double getImag() const;

    /**
     * @brief Получение количества чтений/обращений к объекту.
     * @return Значение счётчика accessCount.
     */
    int getAccessCount() const;

    /**
     * @brief Получение общего числа существующих объектов класса.
     * @return Текущее значение static-счётчика objectCount.
     */
    static int getObjectCount();

    /**
     * @brief Вывод полного журнала истории операций в консоль.
     */
    static void printHistory();

    /**
     * @brief Добавление строковой записи в журнал истории операций.
     * @param operation Текстовое описание выполненного математического действия.
     */
    static void addHistory(const std::string& operation);

    /**
     * @brief Форматированный вывод комплексного числа в консоль вида (a + bi) или (a - bi).
     */
    void print() const;

    /**
     * @brief Префиксный инкремент (++z).
     * Увеличивает действительную часть (real) на 1.0.
     * @return Ссылка на текущий изменённый объект (*this).
     */
    Complex& operator++();

    /**
     * @brief Постфиксный инкремент (z++).
     * Увеличивает действительную часть (real) на 1.0, возвращая старое значение.
     * @param int Фиктивный неиспользуемый параметр C++ для отличия постфиксной формы от префиксной.
     * @return Временная копия объекта до выполнения инкремента.
     */
    Complex operator++(int);

    /**
     * @brief Префиксный декремент (--z).
     * Уменьшает действительную часть (real) на 1.0.
     * @return Ссылка на текущий изменённый объект (*this).
     */
    Complex& operator--();

    /**
     * @brief Постфиксный декремент (z--).
     * Уменьшает действительную часть (real) на 1.0, возвращая старое значение.
     * @param int Фиктивный неиспользуемый параметр C++ для отличия постфиксной формы от префиксной.
     * @return Временная копия объекта до выполнения декремента.
     */
    Complex operator--(int);

    /**
     * @brief Составное арифметическое сложение с присваиванием (+=).
     * @param other Правый операнд.
     * @return Ссылка на текущий модифицированный объект (*this).
     */
    Complex& operator+=(const Complex& other);

    /**
     * @brief Составное арифметическое вычитание с присваиванием (-=).
     * @param other Правый операнд.
     * @return Ссылка на текущий модифицированный объект (*this).
     */
    Complex& operator-=(const Complex& other);

    /**
     * @brief Составное арифметическое умножение с присваиванием (*=).
     * @param other Правый операнд.
     * @return Ссылка на текущий модифицированный объект (*this).
     */
    Complex& operator*=(const Complex& other);

    /**
     * @brief Составное арифметическое деление с присваиванием (/=).
     * @param other Правый операнд (делитель).
     * @return Ссылка на текущий модифицированный объект (*this).
     * @throws std::invalid_argument Если делитель равен нулю (0 + 0i).
     */
    Complex& operator/=(const Complex& other);

    /**
     * @brief Вычисление модуля (магнитуды) комплексного числа: |z| = sqrt(real^2 + imag^2).
     * @return Модуль числа в виде значения типа double.
     */
    double getMagnitude() const;

    /**
     * @brief Бинарное сложение двух комплексных чисел (+).
     * @param lhs Левый операнд (принимается по значению для локальной копии).
     * @param rhs Правый операнд.
     * @return Новый объект Complex — сумма чисел.
     */
    friend Complex operator+(Complex lhs, const Complex& rhs);

    /**
     * @brief Бинарное вычитание двух комплексных чисел (-).
     * @param lhs Левый операнд (принимается по значению для локальной копии).
     * @param rhs Правый операнд.
     * @return Новый объект Complex — разность чисел.
     */
    friend Complex operator-(Complex lhs, const Complex& rhs);

    /**
     * @brief Бинарное умножение двух комплексных чисел (*).
     * @param lhs Левый операнд (принимается по значению для локальной копии).
     * @param rhs Правый операнд.
     * @return Новый объект Complex — произведение чисел.
     */
    friend Complex operator*(Complex lhs, const Complex& rhs);

    /**
     * @brief Бинарное деление двух комплексных чисел (/).
     * @param lhs Левый операнд (принимается по значению для локальной копии).
     * @param rhs Правый операнд.
     * @return Новый объект Complex — частное чисел.
     * @throws std::invalid_argument Если rhs равен нулю.
     */
    friend Complex operator/(Complex lhs, const Complex& rhs);

    /**
     * @brief Проверка двух комплексных чисел на строгое равенство (==).
     * @param other Правый операнд.
     * @return true, если действительные и мнимые части обоих чисел попарно равны.
     */
    bool operator==(const Complex& other) const;

    /**
     * @brief Проверка двух комплексных чисел на неравенство (!=).
     * @param other Правый операнд.
     * @return true, если числа отличаются хотя бы одной частью.
     */
    bool operator!=(const Complex& other) const;

    /**
     * @brief Сравнение «меньше» (<) по модулю чисел.
     * @param other Правый операнд.
     * @return true, если модуль левого числа меньше модуля правого.
     */
    bool operator<(const Complex& other) const;

    /**
     * @brief Сравнение «больше» (>) по модулю чисел.
     * @param other Правый операнд.
     * @return true, если модуль левого числа больше модуля правого.
     */
    bool operator>(const Complex& other) const;

    /**
     * @brief Сравнение «меньше или равно» (<=) по модулю чисел.
     * @param other Правый операнд.
     * @return true, если модуль левого числа не превосходит модуль правого.
     */
    bool operator<=(const Complex& other) const;

    /**
     * @brief Сравнение «больше или равно» (>=) по модулю чисел.
     * @param other Правый операнд.
     * @return true, если модуль левого числа не меньше модуля правого.
     */
    bool operator>=(const Complex& other) const;

    /**
     * @brief Дружественный оператор вывода комплексного числа в выходной поток.
     * @param os Выходной поток std::ostream.
     * @param c Выводимое комплексное число.
     * @return Ссылка на выходной поток std::ostream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

    /**
     * @brief Дружественный оператор ввода комплексного числа из входного потока.
     * @param is Входной поток std::istream.
     * @param c Модифицируемое комплексное число (считываются real и imag).
     * @return Ссылка на входной поток std::istream.
     */
    friend std::istream& operator>>(std::istream& is, Complex& c);
};