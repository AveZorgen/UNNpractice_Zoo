//
// Created by ave-zorgen on 01.04.2022.
//

#ifndef ZOO2_MENU_H
#define ZOO2_MENU_H

#include "Zoo.h"

class Menu{
    Zoo* zoo;
    int op = -1, op2 = 0, a = 0, n = 0, path = 0;

public:
    Menu(Zoo* _zoo): zoo(_zoo) {
        zoo->setObs(new Printer(zoo));
    }

    void MainMenu(){
        while (op){
            if (path == 110) zoo->Repr();
            
            n = zoo->getZooLen();
            cout << n << ". <Добавить клетку>\n";

            path = 0;

            cin >> op;
            system("cls");

            op = DoOP();
        }
    }

private:
    int DoOP(){
        path = path * 10 + 1;

        if (op > n || op < 0) return 0;

        if (op == n){
            BoxMenu(); return 1;
        }

        AnimalMenu(); return 1;
    }

    void BoxMenu(){
        path = path * 10 + 0;
        cout<<"Какого размера?\n";

        cin >> n;
        system("cls");

        if (n>0)
            zoo->AddBox(n);
    }

    void AnimalMenu(){
        path = path * 10 + 1;
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
        path = path * 10 + 0;
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
        path = path * 10 + 1;
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
        }
    }
};

#endif //ZOO2_MENU_H



