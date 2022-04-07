#include "Zoo.h"

int Zoo::Repr() {
    int i = 0;
    for (; i < n; i++) {
        cout << i << ". ";
        boxes[i].Repr();
        cout << "\n";
    }
    return i;
}

void Zoo::Add() {
    Box2* newB = new Box2[n+1];
    for (int i = 0; i < n; i++) {
        newB[i].Init(boxes[i][0], 0);
        newB[i].Init(boxes[i][1], 1);
    }
    //cout << "[Add()]delete[] boxes;" << boxes << "\n";
    delete[] boxes;
    boxes = newB;
    n++;
    //cout << "[Add()]now it" << boxes << "\n";
    cout << "Added!\n";
}

void Zoo::Delete(int _n) {
    boxes[_n].Init(nullptr, 0);
    boxes[_n].Init(nullptr, 1);
    cout << "Deleted!\n";
}

Box2& Zoo::operator[](int i) {
    return boxes[i];
}

Zoo::~Zoo() {
    //cout << "Destruct Zoo" << this << "\n";

    for (int i = 0; i < n; i++) {
        //cout << "[~Zoo]delete boxes[i][0];" << boxes[i][0] << "\n";
        //cout << "[~Zoo]delete boxes[i][1];" << boxes[i][1] << "\n";
        delete boxes[i][0];
        delete boxes[i][1];
    }
    //cout << "[~Zoo]delete[] boxes;" << boxes << "\n";
    delete[] boxes;
}