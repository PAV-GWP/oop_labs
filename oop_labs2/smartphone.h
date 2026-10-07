#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Battery{
    int level;
    int capacity;
};

class Smartphone {
private:
    string model;
    int memory;
    bool isPoweredOn;
    Battery battery;

    static int objectCount;
    
    void validateModel(const string& model) const;
    void validateMemory(int memory) const;
    void validateBattery(const Battery& battery) const;

public:
    Smartphone();

    Smartphone(
        const string& model,
        int memory,
        const Battery& battery,
        bool isPoweredOn
    );
    Smartphone(
        const string& model,
        int memory
    );
    ~Smartphone();
    string getModel() const;
    int getMemory() const;
    int getBatteryLevel() const;
    int getBatteryCapacity() const;
    bool isOn() const;

    void turnOn();
    void turnOff();
    void charge(int amount);
    bool useBattery(int amount);

    void printInfo() const;

    static int getObjectCount();
};