﻿#include <iostream>
#include "Menu.h"

int main() {
    setlocale(LC_ALL, "ru");

    Zoo zoo;
    Menu menu(&zoo);
    menu.MainMenu();
    return 0;
}
