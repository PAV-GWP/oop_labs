#include <iostream>
#include <stdexcept>

#include "smartphone.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Лабораторная работа №2 по ООП" << endl;
    cout << "Вариант 10: Мобильный телефон (Smartphone)" << endl;
    cout << endl;

    // 1. Конструктор без параметров
    Smartphone phone1;

    // 2. Полный параметризованный конструктор
    Smartphone phone2(
        "Apple iPhone 67",
        256,
        Battery{80, 3349},
        true
    );

    // 3. Сокращённый параметризованный конструктор (делегирующий)
    Smartphone phone3(
        "Samsung Galaxy S67",
        512
    );

    cout << "Количество существующих объектов: "
         << Smartphone::getObjectCount()
         << endl;
    
    cout << endl;
    cout << "===== НАЧАЛЬНОЕ СОСТОЯНИЕ =====" << endl;

    cout << endl;
    cout << "Телефон 1:" << endl;
    phone1.printInfo();

    cout << endl;
    cout << "Телефон 2:" << endl;
    phone2.printInfo();

    cout << endl;
    cout << "Телефон 3:" << endl;
    phone3.printInfo();

    cout << endl;
    cout << "===== КОРРЕКТНЫЕ ОПЕРАЦИИ =====" << endl;

    phone1.turnOn();
    cout << "Телефон 1 успешно включен." << endl;

    if (phone1.useBattery(20))
    {
        cout << "Телефон 1 израсходовал 20% заряда." << endl;
    }
    phone2.charge(15);
    cout << "Телефон 2 пополнен на 15% заряда." << endl;

    if (phone2.useBattery(40))
    {
        cout << "Телефон 2 израсходовал 40% заряда." << endl;
    }

    cout << endl;
    cout << "===== НЕКОРРЕКТНЫЕ ОПЕРАЦИИ =====" << endl;

    try
    {
        cout << "Попытка использовать заряд выключенного Телефона 3:" << endl;
        phone3.useBattery(15);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    try
    {
        phone1.charge(-30);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    if (!phone1.useBattery(95))
    {
        cout << "Ошибка: недостаточно заряда на аккумуляторе Телефона 1." << endl;
    }
    try
    {
        Smartphone badPhone(
            "", 
            -64, 
            Battery{150, -1000}, 
            false
        );
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}