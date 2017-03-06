#pragma once

#include "TAnimal.h"

const float STEP = 1.5;

class TZoo {
    typedef TAnimal *TPtrAnimal;
    TPtrAnimal *Animals;
    size_t Capacity;
    size_t NumAnimals;
    float Time;
public:
    TZoo(size_t capacity);
    bool AddNewAnimal(TAnimal **newAnimal);
    void Work();
    ~TZoo();
    TAnimal *operator[](int i) const;
    TAnimal *&operator[](int i);
    void deleteByIndex(int i);
};
