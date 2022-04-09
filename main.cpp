#include <iostream>
#include "Menu.h"

int main() {
    Zoo zoo;
    Menu menu(&zoo);
    menu.MainMenu();
    return 0;
}
