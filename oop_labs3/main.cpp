/**
 * @file main.cpp
 * @brief Демонстрационная программа и тестовый сценарий для лабораторной работы №3.
 * @author Царицон Павел
 * @date 2026
 */

#include <iostream>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Complex.h"

/**
 * @brief Функция для демонстрации предотвращения неявного приведения типов с помощью explicit.
 * @param c Комплексное число, передаваемое по константной ссылке.
 */
void printComplexValue(const Complex& c)
{
    std::cout << "Передано комплексное число: " << c << std::endl;
}

/**
 * @brief Главная точка входа в программу.
 * Выполняет комплексное тестирование всех конструкторов, операторов,
 * константных модификаторов и статических компонентов класса Complex.
 * @return Код завершения программы (0 при успешном выполнении).
 */
int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    std::cout << "Лабораторная работа №3: Перегрузка функций и методов" << std::endl;
    std::cout << "Вариант №4: Калькулятор комплексных чисел" << std::endl;
    std::cout << "Начальное количество объектов: " << Complex::getObjectCount() << "\n" << std::endl;

    // 1. Демонстрация трех конструкторов
    std::cout << "--- 1. Создание объектов через разные конструкторы ---" << std::endl;
    Complex z1;             // по умолчанию: 0 + 0i
    Complex z2(5.0);        // с одним параметром: 5 + 0i (explicit)
    Complex z3(3.0, 4.0);   // полный конструктор: 3 + 4i
    Complex z4(1.0, -2.0);  // 1 - 2i

    std::cout << "z1 (default): " << z1 << std::endl;
    std::cout << "z2 (explicit double): " << z2 << std::endl;
    std::cout << "z3 (3, 4): " << z3 << std::endl;
    std::cout << "z4 (1, -2): " << z4 << std::endl;
    std::cout << "Всего объектов в памяти: " << Complex::getObjectCount() << "\n" << std::endl;

    // 2. Демонстрация предотвращения неявного преобразования (explicit)
    std::cout << "--- 2. Демонстрация работы explicit ---" << std::endl;
    // printComplexValue(10.5); // ОШИБКА КОМПИЛЯЦИИ! explicit запрещает неявный каст double -> Complex
    printComplexValue(Complex(10.5)); // Явное создание разрешено
    std::cout << "Неявное преобразование printComplexValue(10.5) заблокировано explicit.\n" << std::endl;

    // 3. Унарные операции: префиксные и постфиксные инкременты и декременты
    std::cout << "--- 3. Унарные операции (++ и --) ---" << std::endl;
    std::cout << "Исходное z3: " << z3 << std::endl;
    std::cout << "Префиксный ++z3: " << ++z3 << " (сразу изменился)" << std::endl;
    std::cout << "Постфиксный z3++: " << z3++ << " (значение до изменения)" << std::endl;
    std::cout << "После постфиксного инкремента: " << z3 << std::endl;
    std::cout << "Префиксный --z3: " << --z3 << std::endl;
    std::cout << "Постфиксный z3--: " << z3-- << std::endl;
    std::cout << "Итоговое z3: " << z3 << "\n" << std::endl;

    // 4. Арифметические присваивания (+=, -=, *=, /=)
    std::cout << "--- 4. Арифметические присваивания (+=, -=, *=, /=) ---" << std::endl;
    Complex a(2.0, 3.0);
    Complex b(1.0, 1.0);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    a += b;
    std::cout << "a += b -> a = " << a << std::endl;
    a -= b;
    std::cout << "a -= b -> a = " << a << std::endl;
    a *= b;
    std::cout << "a *= b -> a = " << a << std::endl;
    a /= b;
    std::cout << "a /= b -> a = " << a << "\n" << std::endl;

    // 5. Бинарные операции (+, -, *, /)
    std::cout << "--- 5. Бинарные операции (+, -, *, /) ---" << std::endl;
    Complex sum = z3 + z4;
    Complex diff = z3 - z4;
    Complex prod = z3 * z4;
    Complex quot = z3 / z4;

    std::cout << z3 << " + " << z4 << " = " << sum << std::endl;
    std::cout << z3 << " - " << z4 << " = " << diff << std::endl;
    std::cout << z3 << " * " << z4 << " = " << prod << std::endl;
    std::cout << z3 << " / " << z4 << " = " << quot << "\n" << std::endl;

    // 6. Обработка ошибки: деление на ноль
    std::cout << "--- 6. Проверка деления на нулевое комплексное число ---" << std::endl;
    try
    {
        Complex zero(0.0, 0.0);
        Complex badQuot = z3 / zero;
    }
    catch (const std::exception& e)
    {
        std::cout << "Перехвачено исключение: " << e.what() << "\n" << std::endl;
    }

    // 7. Операторы сравнения (по модулю)
    std::cout << "--- 7. Сравнение (по модулю |z|) ---" << std::endl;
    Complex c1(3.0, 4.0); // |c1| = sqrt(9 + 16) = 5
    Complex c2(0.0, 2.0); // |c2| = 2
    std::cout << "c1 = " << c1 << ", модуль = " << c1.getMagnitude() << std::endl;
    std::cout << "c2 = " << c2 << ", модуль = " << c2.getMagnitude() << std::endl;

    std::cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << std::endl;
    std::cout << "c1 != c2: " << (c1 != c2 ? "true" : "false") << std::endl;
    std::cout << "c1 > c2:  " << (c1 > c2  ? "true" : "false") << std::endl;
    std::cout << "c1 < c2:  " << (c1 < c2  ? "true" : "false") << std::endl;
    std::cout << "c1 >= c2: " << (c1 >= c2 ? "true" : "false") << std::endl;
    std::cout << "c1 <= c2: " << (c1 <= c2 ? "true" : "false") << "\n" << std::endl;

    // 8. Демонстрация const-объекта и поля mutable
    std::cout << "--- 8. Демонстрация const объекта и mutable поля ---" << std::endl;
    const Complex constNum(7.0, 8.0);
    std::cout << "Константный объект: " << constNum << std::endl;
    std::cout << "Обращений до вызовов: " << constNum.getAccessCount() << std::endl;

    // Вызываем const-геттеры, которые меняют поле mutable accessCount
    double r = constNum.getReal();
    double im = constNum.getImag();
    (void)r; (void)im; // подавление предупреждения о неиспользуемых переменных

    std::cout << "Обращений после вызова getReal() и getImag(): " 
              << constNum.getAccessCount() 
              << " (поле mutable изменилось у const-объекта!)\n" << std::endl;

    // 9. Просмотр истории калькулятора
    Complex::printHistory();

    std::cout << "Объектов перед выходом из main: " << Complex::getObjectCount() << std::endl;
    return 0;
}