#pragma once
#include "Animals.h"
#include "Exceptions.h"

class Box2 {
    IAnimal* animal1;
    IAnimal* animal2;
public:
    Box2(IAnimal* a1 = nullptr, IAnimal* a2 = nullptr) : animal1(a1), animal2(a2) {}

    void Greeting(int i);

    void Info(int i);

    void Repr();

    void Init(IAnimal* a, int i);

    IAnimal*& operator[](int i);

    ~Box2();
};