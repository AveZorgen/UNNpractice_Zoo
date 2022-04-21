//
// Created by ave-zorgen on 01.04.2022.
//

#ifndef ZOO2_MENU_H
#define ZOO2_MENU_H

#include "Zoo.h"

class Print {
    Zoo* zoo;
public:
    Print(Zoo* z) :zoo(z) {}
    void event() {
        zoo->Repr();
    }
};

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

class Menu{
    Zoo* zoo;
    Print obsPrinter;
    GreetNewbee obsGreeter;
    int op = -1, op2 = 0, a = 0, n = 0;
    void ZooEvent() {
        obsPrinter.event();
    }
    void AnimalEvent() {
        obsGreeter.event();
    }

public:
    Menu(Zoo* _zoo): zoo(_zoo), obsPrinter(zoo) { } ///

    void MainMenu(){
        while (op){
            n = zoo->getZooLen();

            cout << "Клетки:\n";
            ZooEvent();
            cout << n << ". <Добавить клетку>\n";

            cin >> op;
            system("cls");

            op = DoOP();
        }
    }

private:
    int DoOP(){
        if (op > n || op < 0) return 0;

        if (op == n){
            BoxMenu(); return 1;
        }

        AnimalMenu(); return 1;
    }

    void BoxMenu(){
        cout<<"Какого размера?\n";

        cin >> n;
        system("cls");
        if (n>0)
            zoo->AddBox(n); ///
    }

    void AnimalMenu(){
        cout << "Клетка №" << op << ": ";
        (*zoo)[op].Repr();
        cout << "\nДоступные действия:\n"
                "0. Информация о животном\n"
                "1. Поздоровоться с животным\n"
                "2. Добавить животное\n"
                "3. Освободить клетку\n";

        cin >> op2;
        system("cls");

        switch (op2) {
            case 0:
            case 1:
                ChooseConcretePlace(); break;
            case 2:
                ChooseNewAnimal(); break;
            case 3:
                zoo->Clear(op); break;
            default:;
        }
    }

    void ChooseConcretePlace(){
        cout<<"Какое именно? ";
        (*zoo)[op].Repr();
        cout <<"\n(0";
        for (int i = 1; i < (*zoo)[op].getBoxLen(); i++){
            cout<<"/"<<i;
        }
        cout <<")\n";
        cin >> a;
        system("cls");

        switch (op2) {
            case 0:
                (*zoo)[op].Info(a); cout<<"\n"; break;
            case 1:
                (*zoo)[op].Greeting(a); cout<<"\n"; break;
            default:;
        }
    }

    void ChooseNewAnimal(){
        cout << "Выберете новое животное\n"
                "0. Кролик\n"
                "1. Волк\n";

        cin >> op2;
        system("cls");

        IAnimal* animal = nullptr;

        switch (op2) {
            case 0:
                animal = new Rabbit;
                break;
            case 1:
                animal = new Wolf;
                break;
            default:;
            }
        if (animal) {
            zoo->AddAnimal(animal, op);

            obsGreeter = GreetNewbee(&((*zoo)[op]));
            AnimalEvent();
        }
    }
};

#endif //ZOO2_MENU_H



