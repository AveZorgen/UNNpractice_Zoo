#pragma once
#include "Box.h"
class Zoo {
    int n;
public:
    Box2* boxes;
    Zoo(int _n = 0) : n(_n), boxes(new Box2[_n]) {
        //cout << "[Zoo()]boxes = new Box2[_n];" << boxes << "\n";
    }

    int Repr();

    void Add();

    void Delete(int _n);

    Box2& operator[](int i);

    ~Zoo();
};
