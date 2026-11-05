#pragma once

#include "Mammal.h"
#include "Bird.h"

/**
 * @brief Класс «Летучая мышь».
 * Демонстрирует множественное наследование от Mammal и Bird с общим предком Animal.
 */
class Bat : public Mammal, public Bird {
private:
    double echolocationFreq; ///< Частота эхолокации в кГц

public:
    Bat(const char* name, int age, int gestationPeriod, bool nursing,
        double wingspan, bool canFly, double echolocationFreq);
    Bat(const Bat& other);
    Bat& operator=(const Bat& other);
    ~Bat() override;

    void makeSound() const override;
    void move() const override;
    const char* getSpecies() const override;
    void printInfo() const override;

    double getEcholocationFreq() const;
};