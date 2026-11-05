#pragma once

#include "Bird.h"

/**
 * @brief Конкретный класс «Попугай» — наследник Bird.
 */
class Parrot : public Bird {
private:
    int vocabularySize; ///< Запас выученных слов

public:
    Parrot(const char* name, int age, double wingspan, bool canFly, int vocabularySize);
    Parrot(const Parrot& other);
    Parrot& operator=(const Parrot& other);
    ~Parrot() override;

    void makeSound() const override;
    const char* getSpecies() const override;
    void printInfo() const override;

    int getVocabularySize() const;
};