#include "Mammal.h"

Mammal::Mammal(const char* name, int age, int gestationPeriod, bool nursing)
    : Animal(name, age), gestationPeriod(gestationPeriod), nursing(nursing) {}

Mammal::Mammal(const Mammal& other)
    : Animal(other), gestationPeriod(other.gestationPeriod), nursing(other.nursing) {}

Mammal& Mammal::operator=(const Mammal& other) {
    if (this == &other) return *this;
    Animal::operator=(other);
    this->gestationPeriod = other.gestationPeriod;
    this->nursing = other.nursing;
    return *this;
}

Mammal::~Mammal() {}

void Mammal::move() const {
    std::cout << name << " шагает на четырех лапах по суше." << std::endl;
}

void Mammal::printInfo() const {
    Animal::printInfo();
    std::cout << ", Вынашивание: " << gestationPeriod << " дн."
              << ", Выкармливает молоком: " << (nursing ? "Да" : "Нет");
}

int Mammal::getGestationPeriod() const {
    return gestationPeriod;
}

bool Mammal::isNursing() const {
    return nursing;
}