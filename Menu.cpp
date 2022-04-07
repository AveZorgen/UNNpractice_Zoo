#include "Menu.h"

void Menu::MainMenu() {
    while (op) {
        cout << "Клетки:\n";
        n = zoo->Repr() - 1;
        cout << n + 1 << ". <Добавить клетку>\n";

        cin >> op;
        system("cls");

        op = DoOP();
    }
}

int Menu::DoOP() {
    if (op > n + 1 || op < 0) return 0;

    if (op == n + 1) {
        zoo->Add(); return 1;
    }

    AnimalMenu(); return 1;
}

void Menu::AnimalMenu() {
    cout << "Клетка №" << op << ": ";
    (*zoo)[op].Repr();
    cout << "\nДоступные действия:\n"
        "0. Информация о животном\n"
        "1. Поздоровоться с животным\n"
        "2. Поменять животное\n"
        "3. Освободить клетку\n";

    cin >> op2;
    system("cls");

    if (op2 < 3) ChooseConcretePlace();
    else zoo->Delete(op);
}

void Menu::ChooseConcretePlace() {
    cout << "Какое именно? ";
    (*zoo)[op].Repr();
    cout << "\n(0/1)\n";

    cin >> a;
    system("cls");

    switch (op2) {
    case 0:
        (*zoo)[op].Info(a); cout << "\n"; break;
    case 1:
        (*zoo)[op].Greeting(a); cout << "\n"; break;
    case 2:
        ChooseNewAnimal(); break;
    default:
        break;
    }
}

void Menu::ChooseNewAnimal() {
    cout << "Выберете новое животнеое\n"
        "0. Кролик\n"
        "1. Волк\n";

    cin >> op2;
    system("cls");

    IAnimal* animal = nullptr;
    
    switch (op2) {
    case 0:
        animal = new Rabbit; break;
    case 1:
        animal = new Wolf; break;
    default: break;
    }
    
    if (animal) {
        try {
            (*zoo)[op].Init(animal, a);
        }
        catch (IException* err) {
            err->show();
            delete animal;
        }
    }
    
}