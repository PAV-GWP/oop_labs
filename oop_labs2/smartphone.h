
#pragma once

#include <iostream>
#include <string>
using namespace std;
/// @brief Пользовательский тип данных: аккумулятор смартфона
struct Battery{
    int level;
    int capacity;
};
/// @brief Класс, моделирующий поведение и характеристики смартфона (Вариант 10)
class Smartphone {
private:
    string model;
    int memory;
    bool isPoweredOn;
    Battery battery;

    static int objectCount;
    /// @brief Проверяет инвариант названия модели
    /// @param model Название модели для проверки
    void validateModel(const string& model) const;
    /// @brief Проверяет инвариант объёма встроенной памяти
    /// @param memory Объём памяти в гигабайтах
    void validateMemory(int memory) const;
    /// @brief Проверяет инварианты параметров аккумулятора
    /// @param battery Структура аккумулятора для проверки
    void validateBattery(const Battery& battery) const;

public:
    
    Smartphone();
    /// @brief Полный параметризованный конструктор с валидацией инвариантов
    /// @param model Название модели смартфона
    /// @param memory Объём встроенной памяти в ГБ
    /// @param battery Параметры аккумулятора (уровень и ёмкость)
    /// @param isPoweredOn Начальное состояние питания
    Smartphone(
        const string& model,
        int memory,
        const Battery& battery,
        bool isPoweredOn
    );
    /// @brief Сокращённый делегирующий конструктор
    /// @param model Название модели смартфона
    /// @param memory Объём встроенной памяти в ГБ
    Smartphone(
        const string& model,
        int memory
    );
    /// @brief Деструктор класса Smartphone
    ~Smartphone();
    /// @brief Получить название модели смартфона
    /// @return Строка с названием модели
    string getModel() const;
    /// @brief Получить объём встроенной памяти
    /// @return Объём памяти в ГБ
    int getMemory() const;
    /// @brief Получить текущий уровень заряда аккумулятора
    /// @return Процент заряда (от 0 до 100)
    int getBatteryLevel() const;
    /// @brief Получить номинальную ёмкость аккумулятора
    /// @return Ёмкость аккумулятора в мА·ч
    int getBatteryCapacity() const;
    /// @brief Проверить состояние питания устройства
    /// @return true, если смартфон включен; false, если выключен
    bool isOn() const;

    /// @brief Включить смартфон
    void turnOn();
    /// @brief Выключить смартфон
    void turnOff();
    /// @brief Пополнить заряд аккумулятора устройства
    /// @param amount Количество процентов для пополнения (должно быть > 0)
    void charge(int amount);
    /// @brief Израсходовать заряд аккумулятора на выполнение операций
    /// @param amount Количество процентов для списания (> 0)
    /// @return true, если операция выполнена успешно; false, если не хватает заряда
    bool useBattery(int amount);

    /// @brief Вывести форматированную карточку состояния объекта в консоль
    void printInfo() const;
    /// @brief Получить текущее количество активных объектов класса
    /// @return Число активных экземпляров в памяти
    static int getObjectCount();
};