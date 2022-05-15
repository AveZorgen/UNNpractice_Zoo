//
// Created by ave-zorgen on 31.03.2022.
//

#ifndef ZOO2_BOX_H
#define ZOO2_BOX_H

#include "Animals.h"
#include "Exceptions.h"

class IObserver {
public:
    virtual void event() = 0;
    virtual IObserver* CreateObs() = 0;
};

class Box {
    int n;
    int p = 0;
    IAnimal** animals;
    IObserver* obs = nullptr;
    void ValidatePlace(IAnimal* a){
        if (p == n) throw new StrErr("Нет места");
        if (p) {
            if (animals[0]->isAgressive() + a->isAgressive())
                throw new StrErr("Он его съест!");
        }
    }
    void AnimalEvent() {
        obs->event();
    }
public:
    Box(int _n = 0): n(_n) {
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

    int getBoxLen() { return n;}

    int getPoint() { return p;}

    void setPoint(int _p) { p = _p; }

    void setObs(IObserver* o) { obs = o; }

    void setAnimal(IAnimal* a) {
        ValidatePlace(a);
        animals[p] = a;
        p++;
        AnimalEvent();
    }

    void Greeting(int i)  {
        if (i < p) animals[i]->MakeRoar();
        else cout << "[Anullptr] Тишина...";
    }

    void Info(int i)  {
        if (i < p) cout << animals[i]->GetInfo();
        else cout << "[Anullptr] Свободно";
    }

    void Repr() {
        for (int i = 0; i < n; i++) {
            cout << "<"; Info(i); cout << "> ";
        }
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
        delete obs;

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
        delete obs;
    }
};

    class GreetNewbee : public IObserver{
        Box* box;
        void event() {
            cout << "Привет, ";
            box->Info(box->getPoint() - 1);
            cout << "\n";
        }
        GreetNewbee* CreateObs() { return new GreetNewbee; }
    public:
        GreetNewbee(Box* b = nullptr) : box(b) {}
    };


#endif //ZOO2_BOX_H
