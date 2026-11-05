#pragma once

#include "Mammal.h"

/**
 * @brief Конкретный класс «Лев» — наследник Mammal.
 */
class Lion : public Mammal {
private:
    int prideSize; ///< Численность прайда

public:
    Lion(const char* name, int age, int gestationPeriod, bool nursing, int prideSize);
    Lion(const Lion& other);
    Lion& operator=(const Lion& other);
    ~Lion() override;

    void makeSound() const override;
    const char* getSpecies() const override;
    void printInfo() const override;

    int getPrideSize() const;
};