#pragma once

#include <iostream>
#include <cstring>

/**
 * @brief Абстрактный базовый класс для всех животных зоопарка.
 */
class Animal {
protected:
    char* name;        // Динамическая строка: кличка животного
    int age;           // Возраст животного

    static int totalCount;          // Статический счетчик всех созданных животных
    static Animal* oldestAnimal;    // Указатель на самое возрастное животное

public:
    // Конструктор с параметрами
    Animal(const char* name, int age);

    // Конструктор копирования (глубокое копирование)
    Animal(const Animal& other);

    // Оператор присваивания (глубокое копирование)
    Animal& operator=(const Animal& other);

    // Виртуальный деструктор
    virtual ~Animal();

    // Чисто виртуальная функция: делает класс абстрактным
    virtual void makeSound() const = 0;

    // Виртуальная функция с реализацией по умолчанию
    virtual void move() const;

    // Чисто виртуальная функция получения названия вида
    virtual const char* getSpecies() const = 0;

    // Виртуальный метод вывода информации
    virtual void printInfo() const;

    // Геттеры
    const char* getName() const;
    int getAge() const;

    // Статические методы
    static int getTotalCount();
    static Animal* getOldestAnimal();
    static void updateOldest(Animal* candidate);

    // Дружественная функция
    friend void printAnimalInfo(const Animal& a);
};