#pragma once

#include "Animal.h"

/**
 * @brief Промежуточный класс млекопитающих (виртуальное наследование от Animal).
 */
class Mammal : virtual public Animal {
protected:
    int gestationPeriod; ///< Период беременности в днях
    bool nursing;        ///< Вскармливает ли детенышей молоком

public:
    Mammal(const char* name, int age, int gestationPeriod, bool nursing = true);
    Mammal(const Mammal& other);
    Mammal& operator=(const Mammal& other);
    virtual ~Mammal();

    void move() const override;
    void printInfo() const override;

    int getGestationPeriod() const;
    bool isNursing() const;
};