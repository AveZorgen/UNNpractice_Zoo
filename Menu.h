//
// Created by ave-zorgen on 01.04.2022.
//

#ifndef ZOO2_MENU_H
#define ZOO2_MENU_H

#include "Zoo.h"

class Menu{
    Zoo* zoo;
    int op = -1, op2 = 0, a = 0, n = 0;
public:
    Menu(Zoo* _zoo): zoo(_zoo) {} ///

    void MainMenu(){
        while (op){
            n = zoo->GetZooLen();

            cout << "Клетки:\n";
            zoo->Repr();
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
        if (n>0){
            zoo->Add(n); ///
        }
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

//        if (op2<2) ChooseConcretePlace();
//        else zoo->Clear(op); ///
    }

    void ChooseConcretePlace(){
        cout<<"Какое именно? ";
        (*zoo)[op].Repr();
        cout <<"\n(0";
        for (int i = 1; i < (*zoo)[op].GetBoxLen(); i++){
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
        cout << "Выберете новое животнеое\n"
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
            default: break;
            }
        if (animal) {
            try{
                (*zoo)[op].Init(animal); ///
            }
            catch (Iexception* err) {
                err->show();
                for (int i = 0; i < zoo->GetZooLen();i++){
                    if (i!=op){
                        try {
                            (*zoo)[i].Init(animal);
                            return;
                        }
                        catch (...){
                            break;
                        }
                    }
                }
                zoo->Add(1);
                (*zoo)[zoo->GetZooLen()-1].Init(animal);
            }
        }
    }
};

#endif //ZOO2_MENU_H
