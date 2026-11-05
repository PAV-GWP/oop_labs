#include "Parrot.h"

Parrot::Parrot(const char* name, int age, double wingspan, bool canFly, int vocabularySize)
    : Animal(name, age), Bird(name, age, wingspan, canFly), vocabularySize(vocabularySize) {}

Parrot::Parrot(const Parrot& other)
    : Animal(other), Bird(other), vocabularySize(other.vocabularySize) {}

Parrot& Parrot::operator=(const Parrot& other) {
    if (this == &other) return *this;
    Bird::operator=(other);
    this->vocabularySize = other.vocabularySize;
    return *this;
}

Parrot::~Parrot() {}

void Parrot::makeSound() const {
    std::cout << name << " звонко кричит: Пиастры! Кеша хороший! (знает " 
              << vocabularySize << " слов)" << std::endl;
}

const char* Parrot::getSpecies() const {
    return "Попугай (Psittaciformes)";
}

void Parrot::printInfo() const {
    Bird::printInfo();
    std::cout << ", Словарный запас: " << vocabularySize << " слов" << std::endl;
}

int Parrot::getVocabularySize() const {
    return vocabularySize;
}