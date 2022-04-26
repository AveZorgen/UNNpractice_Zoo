//
// Created by ave-zorgen on 31.03.2022.
//

#ifndef ZOO2_ZOO_H
#define ZOO2_ZOO_H

#include "Box.h"


class Zoo {
    int n;
    Box* boxes;
    IObserver* obs = nullptr;
    void Update() {
        if (obs)
            obs->event();
    }

public:
    Zoo(int _n = 0): n(_n) {
        boxes = new Box[_n];
        for (int i = 0; i < _n; i++) {
            boxes[i].setObs(new GreetNewbee(&(boxes[i])));
        }
        Update();
        //cout << "A\n";
    }

    void setObs(IObserver* o) { obs = o; }

    int getZooLen(){ return n;}

    void Repr(){
        for (int i = 0; i < n; i++){
            cout << i <<". ";
            boxes[i].Repr();
            cout<<"\n";
        }
    }

    void AddBox(int newBoxLen){ 
        Box* tmp = new Box[n+1];
        for (int i = 0; i < n; i++){
            tmp[i] = boxes[i];
            tmp[i].setObs(new GreetNewbee(&(tmp[i])));
        }
        tmp[n] = Box(newBoxLen);
        tmp[n].setObs(new GreetNewbee(&(tmp[n])));
        n++;

        delete[] boxes;
        boxes = tmp;
        Update();
        //cout << "B\n";
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
                    Update();
                    //cout << "C\n";
                    return;
                }
                catch (...) { }
            }
            AddBox(1);
            boxes[i].setAnimal(a);
        }
        Update();
        //cout << "D\n";
    }

    void Clear(int _n){
        if (_n < 0 || _n >= n) {
            Update();
            //cout << "E\n"; 
            return;
        }
        for (int i = 0; i < boxes[_n].getPoint(); i++) {
            delete boxes[_n][i];
        }
        boxes[_n].setPoint(0);

        Update();
        //cout << "F\n";
    }

    Box& operator[](int i){
        return boxes[i];
    }

    ~Zoo(){
        delete[] boxes;
        delete obs;
    }
};

class Printer: public IObserver {
    Zoo* zoo;
    void event() {
        //system("cls");
        zoo->Repr();
    }
    Printer* CreateObs() { return new Printer; }
public:
    Printer(Zoo* z = nullptr) :zoo(z){}
};

#endif //ZOO2_ZOO_H
