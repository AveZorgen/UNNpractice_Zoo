#pragma once
#include "Zoo.h"

class Menu {
    Zoo* zoo;
    int op, op2, a;
    int n;
public:
    Menu(Zoo* _zoo) : zoo(_zoo), op(-1), n(0), op2(0), a(0) {}

    void MainMenu();
private:
    int DoOP();

    void AnimalMenu();

    void ChooseConcretePlace();

    void ChooseNewAnimal();
};