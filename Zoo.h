//
// Created by ave-zorgen on 31.03.2022.
//

#ifndef ZOO2_ZOO_H
#define ZOO2_ZOO_H

#include "Box.h"

class GreetNewbee{
    Box* box;
public:
    GreetNewbee(Box* b = nullptr) : box(b) {}
    void event() {
        cout << "Привет, ";
        box->Info(box->getPoint() - 1);
        cout << "\n";
    }
};

class Zoo {
    int n;
    Box* boxes;
    GreetNewbee obs;
    void AnimalEvent() {
        obs.event();
    }
public:
    Zoo(int _n = 0): n(_n) {
        boxes = new Box[_n];
    }

    int getZooLen(){ return n;}

    void Repr(){
        for (int i = 0; i < n; i++){
            cout << i <<". ";
            boxes[i].Repr();
            cout<<"\n";
        }
    }

    void AddBox(int newBoxLen){ ///
        Box* tmp = new Box[n+1];
        for (int i = 0; i < n; i++){
            tmp[i] = boxes[i];
        }
        tmp[n] = Box(newBoxLen);
        n++;

        delete[] boxes;
        boxes = tmp;
        cout << "Added!\n";
    }

    void AddAnimalObs(IAnimal* a, int i) {
        boxes[i].setAnimal(a);
        obs = GreetNewbee(&boxes[i]);
        AnimalEvent();
    }

    void AddAnimal(IAnimal* a, int i) {
        try {
            AddAnimalObs(a, i);
        }
        catch (Iexception* err) {
            err->show();
            for (i = 0; i < n; i++) {
                try {
                    AddAnimalObs(a, i);
                    return;
                }
                catch (...) { }
            }
            AddBox(1);
            AddAnimalObs(a, i);
        }
    }

    void Clear(int _n){
        for (int i = 0; i < boxes[_n].getPoint(); i++) {
            delete boxes[_n][i];
        }
        boxes[_n].setPoint(0);

        cout << "Cleared!\n";
    }

    Box& operator[](int i){
        return boxes[i];
    }

    ~Zoo(){
        delete[] boxes;
    }
};

#endif //ZOO2_ZOO_H
