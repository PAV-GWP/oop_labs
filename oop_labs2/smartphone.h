#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Battery{
    int level;
    int capacity;
};

class Smatrphone {
    private:
    string model;
    int memory;
    bool isPoweredOn;
    Battery battery;

    static int objectCount;
    
    void validateModel(const string& model) const;
    void validateMemory(int memory) const;
    void validateBattery(const Battery& battery) const;
};