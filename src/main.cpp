#include <iostream>
#include "Core/GameLoop.h"
#include "UI/ConsoleUI.h"

int main() {
    ConsoleUI ui;
    GameLoop game(ui); // pass by reference or pointer
    game.run();
    return 0;
}