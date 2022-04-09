#include <iostream>
#include "Menu.h"

int main() {
    setlocale(LC_ALL, "Ru");

    Zoo zoo;
    Menu menu(&zoo);
    menu.MainMenu();
    return 0;
}
