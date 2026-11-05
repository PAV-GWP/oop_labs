#pragma once

#include "Animal.h"

/**
 * @brief Промежуточный класс птиц (виртуальное наследование от Animal).
 */
class Bird : virtual public Animal {
protected:
    double wingspan; ///< Размах крыльев в метрах
    bool canFly;     ///< Способность к полету

public:
    Bird(const char* name, int age, double wingspan, bool canFly = true);
    Bird(const Bird& other);
    Bird& operator=(const Bird& other);
    virtual ~Bird();

    void move() const override;
    void printInfo() const override;

    double getWingspan() const;
    bool getCanFly() const;
};