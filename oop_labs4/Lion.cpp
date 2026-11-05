#include "Lion.h"

Lion::Lion(const char* name, int age, int gestationPeriod, bool nursing, int prideSize)
    : Animal(name, age), Mammal(name, age, gestationPeriod, nursing), prideSize(prideSize) {}

Lion::Lion(const Lion& other)
    : Animal(other), Mammal(other), prideSize(other.prideSize) {}

Lion& Lion::operator=(const Lion& other) {
    if (this == &other) return *this;
    Mammal::operator=(other);
    this->prideSize = other.prideSize;
    return *this;
}

Lion::~Lion() {}

void Lion::makeSound() const {
    std::cout << name << " издает громогласный львиный рык: Р-Р-Р-А-У-У!" << std::endl;
}

const char* Lion::getSpecies() const {
    return "Лев (Panthera leo)";
}

void Lion::printInfo() const {
    Mammal::printInfo();
    std::cout << ", Размер прайда: " << prideSize << " особей" << std::endl;
}

int Lion::getPrideSize() const {
    return prideSize;
}