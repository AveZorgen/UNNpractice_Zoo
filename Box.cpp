#include "Box.h"

void Box2::Greeting(int i) {
    if ((*this)[i]) (*this)[i]->MakeRoar();
    else cout << "Тишина...";
}

void Box2::Info(int i) {
    if ((*this)[i]) cout << (*this)[i]->GetInfo();
    else cout << "Свободно";
}

void Box2::Repr() { //cout << Box box;
    for (int i = 0; i < 2; i++) {
        cout << "<"; Info(i); cout << "> ";
    }
}

void Box2::Init(IAnimal* a, int i) {

    if ((*this)[!i] && a) {
        int agr1 = (*this)[!i]->isAgressive();
        int agr2 = a->isAgressive();
        if (agr1 + agr2 > 0) {
            throw new StrErr("Так нельзя - он его съест");
        }
    }


    //cout << "[Init] delete animal;" << (*this)[i] << " from box\n";
    if (!i) {
        delete animal1;
        animal1 = a;
    }
    else {
        delete animal2;
        animal2 = a;
    }
    //cout << "[Init] New animal" << (*this)[i] << " from box\n";
}

IAnimal*& Box2::operator[](int i) {
    if (!i) return animal1;
    return animal2;
}

Box2::~Box2() {
    //cout << "[~Box]\n";
}