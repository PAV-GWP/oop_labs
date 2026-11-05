#include "Animal.h"

// Инициализация статических полей
int Animal::totalCount = 0;
Animal* Animal::oldestAnimal = nullptr;

// Конструктор с выделением динамической памяти
Animal::Animal(const char* name, int age) : age(age) {
    if (name) {
        this->name = new char[std::strlen(name) + 1];
        std::strcpy(this->name, name);
    } else {
        this->name = new char[1];
        this->name[0] = '\0';
    }

    totalCount++;
    Animal::updateOldest(this);
}

// Конструктор копирования (глубокое копирование)
Animal::Animal(const Animal& other) : age(other.age) {
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);

    totalCount++;
    Animal::updateOldest(this);
}

// Оператор присваивания с защитой от самоприсваивания
Animal& Animal::operator=(const Animal& other) {
    if (this == &other) {
        return *this; // Защита от присваивания самому себе (a = a)
    }

    // 1. Освобождаем старую память
    delete[] this->name;

    // 2. Копируем простые поля
    this->age = other.age;

    // 3. Выделяем новую память и копируем данные
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);

    Animal::updateOldest(this);
    return *this;
}

// Деструктор: освобождение динамической памяти
Animal::~Animal() {
    delete[] name;
    totalCount--;

    // Если удаляется самое старое животное, сбрасываем указатель
    if (oldestAnimal == this) {
        oldestAnimal = nullptr;
    }
}

// Виртуальная функция с реализацией по умолчанию
void Animal::move() const {
    std::cout << name << " перемещается обычным способом." << std::endl;
}

// Вывод общей информации
void Animal::printInfo() const {
    std::cout << "Вид: " << getSpecies() 
              << ", Кличка: " << name 
              << ", Возраст: " << age;
}

const char* Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

int Animal::getTotalCount() {
    return totalCount;
}

Animal* Animal::getOldestAnimal() {
    return oldestAnimal;
}

void Animal::updateOldest(Animal* candidate) {
    if (!candidate) return;
    if (!oldestAnimal || candidate->age > oldestAnimal->age) {
        oldestAnimal = candidate;
    }
}

// Дружественная функция: имеет прямой доступ к protected-полям
void printAnimalInfo(const Animal& a) {
    std::cout << "[Инспекция через friend]: " << a.name 
              << ", возраст: " << a.age << std::endl;
}