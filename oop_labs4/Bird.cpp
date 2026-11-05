#include "Bird.h"

Bird::Bird(const char* name, int age, double wingspan, bool canFly)
    : Animal(name, age), wingspan(wingspan), canFly(canFly) {}

Bird::Bird(const Bird& other)
    : Animal(other), wingspan(other.wingspan), canFly(other.canFly) {}

Bird& Bird::operator=(const Bird& other) {
    if (this == &other) return *this;
    Animal::operator=(other);
    this->wingspan = other.wingspan;
    this->canFly = other.canFly;
    return *this;
}

Bird::~Bird() {}

void Bird::move() const {
    if (canFly) {
        std::cout << name << " расправляет крылья (" << wingspan << " м) и взлетает в небо!" << std::endl;
    } else {
        std::cout << name << " бегает по земле на двух лапах (летать не умеет)." << std::endl;
    }
}

void Bird::printInfo() const {
    Animal::printInfo();
    std::cout << ", Размах крыльев: " << wingspan << " м"
              << ", Умеет летать: " << (canFly ? "Да" : "Нет");
}

double Bird::getWingspan() const {
    return wingspan;
}

bool Bird::getCanFly() const {
    return canFly;
}