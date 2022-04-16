//
// Created by ave-zorgen on 31.03.2022.
//

#ifndef ZOO2_ZOO_H
#define ZOO2_ZOO_H

#include "Box.h"

class Zoo {
    int n;
    Box* boxes;
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
        if (newBoxLen<=0) return;
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

    void AddAnimal(IAnimal* a, int i) {
        try {
            boxes[i].setAnimal(a);
        }
        catch (Iexception* err) {
            err->show();
            for (i = 0; i < n; i++) {
                try {
                    boxes[i].setAnimal(a);
                    return;
                }
                catch (...) { }
            }
            AddBox(1);
            boxes[n - 1].setAnimal(a);
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
