//
// Created by ave-zorgen on 03.04.2022.
//

#ifndef ZOO2_EXCEPTIONS_H
#define ZOO2_EXCEPTIONS_H
#include <iostream>

using namespace std;

class Iexception {
public:
    virtual void show() = 0;
};

//class IntErr : public Iexception {
//    int err;
//public:
//    IntErr(int code = 0) : err(code) {}
//    void show() override {
//        cout << "code error:" << err<<"\n";
//    }
//};

class StrErr : public Iexception {
    string err;
public:
    StrErr(string s = "") : err(s) {}
    void show() override{
        cout << "error:" << err <<"\n";
    }
};

#endif //ZOO2_EXCEPTIONS_H
