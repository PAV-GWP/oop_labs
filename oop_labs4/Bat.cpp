#include "Bat.h"

// При виртуальном наследовании самый производный класс Bat САМ напрямую инициализирует Animal
Bat::Bat(const char* name, int age, int gestationPeriod, bool nursing,
         double wingspan, bool canFly, double echolocationFreq)
    : Animal(name, age),
      Mammal(name, age, gestationPeriod, nursing),
      Bird(name, age, wingspan, canFly),
      echolocationFreq(echolocationFreq) {}

Bat::Bat(const Bat& other)
    : Animal(other),
      Mammal(other),
      Bird(other),
      echolocationFreq(other.echolocationFreq) {}

Bat& Bat::operator=(const Bat& other) {
    if (this == &other) return *this;
    Animal::operator=(other);
    this->gestationPeriod = other.gestationPeriod;
    this->nursing = other.nursing;
    this->wingspan = other.wingspan;
    this->canFly = other.canFly;
    this->echolocationFreq = other.echolocationFreq;
    return *this;
}

Bat::~Bat() {}

void Bat::makeSound() const {
    std::cout << name << " издает высокочастотный ультразвуковой сигнал на частоте " 
              << echolocationFreq << " кГц." << std::endl;
}

void Bat::move() const {
    std::cout << name << " бесшумно маневрирует в ночной темноте, ориентируясь по эхолокации." << std::endl;
}

const char* Bat::getSpecies() const {
    return "Летучая мышь (Chiroptera)";
}

void Bat::printInfo() const {
    Animal::printInfo();
    std::cout << ", Вынашивание: " << gestationPeriod << " дн."
              << ", Кормит молоком: " << (nursing ? "Да" : "Нет")
              << ", Размах крыльев: " << wingspan << " м"
              << ", Эхолокация: " << echolocationFreq << " кГц" << std::endl;
}

double Bat::getEcholocationFreq() const {
    return echolocationFreq;
}