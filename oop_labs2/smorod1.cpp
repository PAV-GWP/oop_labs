/* 1 этап
1. Что представляет собой объект?
   Объект моделирует работу мобильного телефона (смартфона), хранящего данные
   об аппаратных характеристиках, заряде батареи и состоянии питания.

2. Какие данные характеризуют объект?
   - string model       — название модели устройства
   - int memory         — объём встроенной памяти (в ГБ)
   - bool isPoweredOn   — состояние питания устройства (false - выключен, true - включен)
   - Battery battery    — аккумулятор устройства (пользовательский тип данных struct Battery)
   - static int objectCount — счётчик активных объектов класса в памяти

3. Какие действия можно выполнять с объектом?
   - turnOn()      — включить устройство
   - turnOff()     — выключить устройство
   - charge()      — пополнить заряд аккумулятора
   - useBattery()  — израсходовать заряд аккумулятора на работу
   - printInfo()   — вывести подробную информацию об устройстве
   - get...()      — методы чтения параметров (геттеры)
   - getObjectCount() — получить текущее число существующих объектов

4. Какие состояния объекта являются недопустимыми (инварианты)?
   - Название модели является пустой строкой
   - Объём встроенной памяти <= 0 ГБ
   - Физическая ёмкость аккумулятора <= 0 мА·ч
   - Уровень заряда аккумулятора вне диапазона [0, 100]%
   - Расход батареи при выключенном питании (isPoweredOn == false)
   - Включение устройства при значении заряда аккумулятора 0%
   - Отрицательные или нулевые значения пополнения/расхода заряда
*/

/* 2 этап
Элемент             Описание
Имя класса          Smartphone — модель мобильного телефона
Пользовательский    struct Battery { int level; int capacity; } — аккумулятор
тип данных          
Поля                string model           — название модели
                    int memory             — объём памяти в ГБ (> 0)
                    bool isPoweredOn       — питание (false / true)
                    Battery battery        — аккумулятор (уровень 0..100%, ёмкость > 0)
                    static int objectCount — счётчик активных объектов

Конструкторы        1. Smartphone() 
                       Конструктор по умолчанию ("Стандартный телефон", 64 ГБ, {50%, 4000 мА·ч}, false)
                    2. Smartphone(model, memory) 
                       Сокращённый конструктор (делегирует вызов полному: 100%, 4000 мА·ч, false)
                    3. Smartphone(model, memory, battery, isPoweredOn) 
                       Полный параметризованный конструктор с проверкой инвариантов

Методы чтения       getModel() const           — получить название модели
(геттеры)           getMemory() const          — получить объём памяти в ГБ
                    getBatteryLevel() const    — получить текущий % заряда
                    getBatteryCapacity() const — получить ёмкость аккумулятора в мА·ч
                    isOn() const               — проверить состояние питания (включен/выключен)
                    getObjectCount()           — статический метод получения числа объектов

Методы изменения    turnOn()                   — включение (запрещено при 0% заряда)
                    turnOff()                  — выключение
                    charge(amount)             — пополнение заряда (amount > 0, макс. 100%)
                    useBattery(amount)         — расход заряда (только для включенного устройства)

Инварианты          1. model не пустая строка
                    2. memory > 0
                    3. battery.capacity > 0
                    4. 0 <= battery.level <= 100
                    5. Нельзя включить устройство с зарядом 0%
                    6. Нельзя расходовать заряд выключенного устройства
*/

#include "smartphone.h"
#include <stdexcept>

int Smartphone::objectCount = 0;

void Smartphone::validateModel(const string& model) const
{
    if (model.empty())
    {
        throw invalid_argument(
            "Ошибка: название модели не может быть пустым."
        );
    }
}

void Smartphone::validateMemory(int memory) const
{
    if (memory <= 0)
    {
        throw invalid_argument(
            "Ошибка: объём встроенной памяти должен быть больше 0 ГБ."
        );
    }
}

void Smartphone::validateBattery(const Battery& battery) const
{
    if (battery.level < 0 || battery.level > 100)
    {
        throw invalid_argument(
            "Ошибка: уровень заряда аккумулятора должен быть в диапазоне от 0 до 100%."
        );
    }

    if (battery.capacity <= 0)
    {
        throw invalid_argument(
            "Ошибка: ёмкость аккумулятора должна быть больше 0 мА·ч."
        );
    }
}

Smartphone::Smartphone()
    : model("Стандартный телефон"),
      memory(64),
      isPoweredOn(false),
      battery{50, 4000}
{
    objectCount++;
}

Smartphone::Smartphone(
    const string& model,
    int memory,
    const Battery& battery,
    bool isPoweredOn)
    : model(model),
      memory(memory),
      isPoweredOn(isPoweredOn),
      battery(battery)
{
    validateModel(model);
    validateMemory(memory);
    validateBattery(battery);
    if (this->battery.level == 0 && this->isPoweredOn)
    {
        this->isPoweredOn = false;
    }

    objectCount++;
}
Smartphone::Smartphone(
    const string& model,
    int memory)
    : Smartphone(
        model,
        memory,
        Battery{100, 4000},
        false)
{
}
Smartphone::~Smartphone()
{
    cout << "Деструктор: смартфон \""
         << model
         << "\" уничтожен." << endl;

    objectCount--;
}
string Smartphone::getModel() const
{
    return model;
}

int Smartphone::getMemory() const
{
    return memory;
}

int Smartphone::getBatteryLevel() const
{
    return battery.level;
}

int Smartphone::getBatteryCapacity() const
{
    return battery.capacity;
}

bool Smartphone::isOn() const
{
    return isPoweredOn;
}

int Smartphone::getObjectCount()
{
    return objectCount;
}
void Smartphone::turnOn()
{
    if (battery.level == 0)
    {
        throw runtime_error(
            "Ошибка: невозможно включить устройство с разряженным аккумулятором (0%)."
        );
    }
    isPoweredOn = true;
}

void Smartphone::turnOff()
{
    isPoweredOn = false;
}

void Smartphone::charge(int amount)
{
    if (amount <= 0)
    {
        throw invalid_argument(
            "Ошибка: величина заряда должна быть больше нуля."
        );
    }

    battery.level += amount;
    if (battery.level > 100)
    {
        battery.level = 100;
    }
}

bool Smartphone::useBattery(int amount)
{
    if (!isPoweredOn)
    {
        throw runtime_error(
            "Ошибка: нельзя использовать батарею выключенного устройства."
        );
    }

    if (amount <= 0)
    {
        throw invalid_argument(
            "Ошибка: расход батареи должен быть больше нуля."
        );
    }

    if (amount > battery.level)
    {
        return false;
    }

    battery.level -= amount;

    if (battery.level == 0)
    {
        isPoweredOn = false;
        cout << "[Уведомление] Аккумулятор полностью разряжен. Устройство выключено." << endl;
    }

    return true;
}
void Smartphone::printInfo() const
{
    cout << "-----------------------------" << endl;
    cout << "Модель: " << model << endl;
    cout << "Память: " << memory << " ГБ" << endl;
    cout << "Ёмкость батареи: " << battery.capacity << " мА·ч" << endl;
    cout << "Заряд: " << battery.level << "%" << endl;
    cout << "Состояние: " << (isPoweredOn ? "включен" : "выключен") << endl;
    cout << "-----------------------------" << endl;
}