#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Lion.h"
#include "Parrot.h"
#include "Bat.h"

// Функция чтения 10 животных из файла
std::vector<Animal*> loadAnimalsFromFile(const std::string& filename) {
    std::vector<Animal*> zoo;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return zoo;
    }

    std::string type, name;
    int age;

    while (file >> type >> name >> age) {
        if (type == "Lion") {
            int gest, nursingInt, pride;
            file >> gest >> nursingInt >> pride;
            zoo.push_back(new Lion(name.c_str(), age, gest, nursingInt == 1, pride));
        } else if (type == "Parrot") {
            double wingspan;
            int canFlyInt, vocab;
            file >> wingspan >> canFlyInt >> vocab;
            zoo.push_back(new Parrot(name.c_str(), age, wingspan, canFlyInt == 1, vocab));
        } else if (type == "Bat") {
            int gest, nursingInt, canFlyInt;
            double wingspan, freq;
            file >> gest >> nursingInt >> wingspan >> canFlyInt >> freq;
            zoo.push_back(new Bat(name.c_str(), age, gest, nursingInt == 1, wingspan, canFlyInt == 1, freq));
        }
    }

    file.close();
    return zoo;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif


    // 1. Загрузка данных из файла
    std::cout << "--- 1. Загрузка 10 животных из файла animals.txt ---" << std::endl;
    std::vector<Animal*> zoo = loadAnimalsFromFile("animals.txt");
    std::cout << "Загружено объектов: " << zoo.size() << "\n" << std::endl;

    // 2. Демонстрация полиморфизма через базовый указатель Animal*
    std::cout << "--- 2. Полиморфный обход вольеров (массив указателей Animal*) ---" << std::endl;
    for (size_t i = 0; i < zoo.size(); ++i) {
        std::cout << (i + 1) << ". ";
        zoo[i]->printInfo();
        zoo[i]->makeSound(); // Полиморфный вызов
        zoo[i]->move();      // Полиморфный вызов
        std::cout << "----------------------------------------------------------" << std::endl;
    }

    // 3. Работа статических членов
    std::cout << "\n--- 3. Статические члены класса Animal ---" << std::endl;
    std::cout << "Всего животных в памяти: " << Animal::getTotalCount() << std::endl;
    Animal* oldest = Animal::getOldestAnimal();
    if (oldest) {
        std::cout << "Самое взрослое животное зоопарка: " << oldest->getName() 
                  << " (" << oldest->getAge() << " лет, вид: " << oldest->getSpecies() << ")" << std::endl;
    }

    // 4. Проверка глубокого копирования и независимости копий
    std::cout << "\n--- 4. Тестирование конструктора копирования и присваивания ---" << std::endl;
    Lion originalLion("Аслан", 7, 110, true, 8);
    Lion copiedLion = originalLion; // Конструктор копирования

    std::cout << "Оригинал: ";
    originalLion.printInfo();
    std::cout << "Копия:    ";
    copiedLion.printInfo();

    std::cout << "Адрес имени оригинала: " << (void*)originalLion.getName() << std::endl;
    std::cout << "Адрес имени копии:     " << (void*)copiedLion.getName() << std::endl;
    if ((void*)originalLion.getName() != (void*)copiedLion.getName()) {
        std::cout << ">> УСПЕХ: Память под имя выделена в разных ячейках (глубокое копирование)!" << std::endl;
    }

    // 5. Вызов дружественной функции
    std::cout << "\n--- 5. Вызов дружественной функции ---" << std::endl;
    printAnimalInfo(originalLion);

    // 6. Очистка динамической памяти
    std::cout << "\n--- 6. Полиморфное удаление объектов из памяти ---" << std::endl;
    for (Animal* animal : zoo) {
        delete animal; // Вызываются виртуальные деструкторы
    }
    zoo.clear();

    std::cout << "Животных после закрытия зоопарка: " << Animal::getTotalCount() << std::endl;
    return 0;
}