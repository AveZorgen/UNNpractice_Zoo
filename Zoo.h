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

    int GetZooLen(){ return n;}

    void Repr(){
        for (int i = 0; i < n; i++){
            cout << i <<". ";
            boxes[i].Repr();
            cout<<"\n";
        }
    }

    void Add(int newBoxLen){ ///
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

    void Clear(int _n){
        for (int i = 0; i < boxes[_n].GetBoxLen(); i++){
            boxes[_n].Init(nullptr,i);
        }
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
