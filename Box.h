//
// Created by ave-zorgen on 31.03.2022.
//

#ifndef ZOO2_BOX_H
#define ZOO2_BOX_H

#include "Animals.h"
#include "Exceptions.h"

class Box {
    int n;
    int p;
    IAnimal** animals;
public:
    Box(int _n = 0): n(_n), p(0) {
        animals = new IAnimal*[n];
        for (int i = 0; i < n; i++)
            animals[i] = nullptr;
    }

    Box(const Box& b){
        p = b.p;
        n = b.n;
        animals = new IAnimal*[n];
        for (int i = 0; i < p; i++)
            animals[i] = b[i]->createAnimal();
    }

    int GetBoxLen() { return n;}

    int GetPoint() { return p;}

    void SetPoint(int _p) { p = _p; }

    void Greeting(int i)  {
        if (i<p) animals[i]->MakeRoar();
        else cout << "[Anullptr] Тишина...";
    }

    void Info(int i)  {
        if (i<p) cout << animals[i]->GetInfo();
        else cout << "[Anullptr] Свободно";
    }

    void Repr() {
        for (int i = 0; i < n; i++) {
            cout << "<"; Info(i); cout << "> ";
        }
    }

    void SetAnimal(IAnimal* a) {
        if (p == n) throw new StrErr("Нет места");
        if (p){
            if (!(animals[0]->isAgressive() + a->isAgressive()))
                throw new StrErr("Он его съест!");
        }
        animals[p] = a;
        p++;
    }

    IAnimal*& operator[](int i) const {
        return animals[i];
    }

    Box& operator=(const Box& b){
        if (&b == this) { return *this; }

        for (int i = 0; i < p; i++){
            delete animals[i];
        }
        delete[] animals;

        p = b.p;
        n = b.n;
        animals = new IAnimal*[n];
        for (int i = 0; i < p; i++)
            animals[i] = b[i]->createAnimal();

        return *this;
    }

    ~Box()  {
        for (int i = 0; i < p; i++){
            delete animals[i];
        }
        delete[] animals;
    }
};

#endif //ZOO2_BOX_H
