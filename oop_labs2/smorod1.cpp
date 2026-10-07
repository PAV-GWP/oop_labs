/* 1 этап
1. Что представляет собой объект?
    Объект моделирует телефон
2. Какие данные характеризуют объект?
    String - Модель устройства
    int - Уровень заряда батареии (%)
    int - Объём памяти
    DeviceState:(Off,On) - Состояние устройства
    static int - Счётчик активных устройств (21 пункт)
3. Какие действия можно выполнять с объектом?
    turnOn - Вкл; turOff - Выкл; charge - заряжать;
    useBattery - разряжать; print - информация о текущем состоянии
4. Какие состояния объекта являются недопустимыми?
   *Уровень зарядки вне диапазона [0,100]%
   *Объём памяти <=0
   *Расход батареии при turnOff
   *Включение телефона при значении батерии 0%
*/
/*2 этап
Элемент	            Описание
Имя класса	        Smartphone - Модель мобильного телефона
Поля                std::string m_model       — название модели
                    int m_battery             — уровень заряда батареи (0..100)
                    int m_memoryGb            — объем встроенной памяти (> 0)
                    DeviceState m_state       — состояние устройства (enum: Off / On)
                    static int s_activeCount  — статический счетчик активных объектов
Конструкторы        1. Smartphone() 
                    Конструктор по умолчанию (базовые значения: Generic Phone, 50%, 64GB, Off)
                    2. Smartphone(model, memoryGb) 
                    Конструктор с двумя параметрами (через список инициализации)
                    3. Smartphone(model, battery, memoryGb, state) 
                    Параметризованный конструктор с проверкой инвариантов
Методы чтения       getModel() const       — получить название модели
 (getters, const)   getBattery() const     — получить процент заряда
                    getMemoryGb() const    — получить объем памяти
                    getState() const       — получить текущее состояние питания
                    getActiveCount()       — статический метод для чтения числа объектов
Инварианты          1. 0 <= battery <= 100 (уровень заряда строго в диапазоне от 0 до 100)
 (условия)          2. memoryGb > 0 (объем памяти строго положительный)
                    3. Нельзя расходовать заряд выключенного устройства
                    4. Нельзя включить устройство с зарядом 0%
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