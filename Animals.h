//
// Created by ave-zorgen on 31.03.2022.
//

#ifndef ZOO2_ANIMALS_H
#define ZOO2_ANIMALS_H

#include <iostream>
using namespace std;


class IAnimal {
public:
    virtual string GetInfo() = 0;
    virtual void MakeRoar() = 0;
    virtual int isAgressive() = 0;
    virtual ~IAnimal() = default;//cout << "[~IAnimal]"<< this<<"\n";}
    virtual IAnimal* createAnimal() = 0;
};

class Herbivores : public IAnimal {
protected:
    string ClassInfo = "Травоядное";
    string Roar = "Хрум-хрум";
public:
    string GetInfo() override {return ClassInfo; }
    int isAgressive() override { return 0;}
    void MakeRoar() override { cout << Roar; }
    virtual IAnimal* createAnimal() {return new Herbivores;}
};

class Carnivores : public IAnimal {
protected:
    string ClassInfo = "Плотоядное";
    string Roar = "Чавк-Чавк";
public:
    string GetInfo() override { return ClassInfo; }
    int isAgressive() override { return 1;}
    void MakeRoar() override { cout << Roar; }
    virtual IAnimal* createAnimal() {return new Carnivores;}
};

class Rabbit : public Herbivores {
protected:
    string PersonalInfo = "Кролик Роджер";
    string Roar = Herbivores::Roar = "Фыр-фыр";
    string GetInfo() override { return ClassInfo + "; " + PersonalInfo; }
    virtual IAnimal* createAnimal() {return new Rabbit;}
};

class Wolf : public Carnivores {
protected:
    string PersonalInfo = "Волк - зубами щёлк";
    string Roar = Carnivores::Roar = "Аууф";
    string GetInfo() override { return ClassInfo + "; " + PersonalInfo; }
    virtual IAnimal* createAnimal() {return new Wolf;}
};

#endif //ZOO2_ANIMALS_H
