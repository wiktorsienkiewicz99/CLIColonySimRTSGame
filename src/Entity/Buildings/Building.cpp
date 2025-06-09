//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#include "Building.h"
#include "../../UI/ConsoleUI.h"
#include <iostream>

void Building::showStatus(ConsoleUI& ui) const {
    ui.log("[Building] " + name + " operational for " + std::to_string(ticksAlive) + " ticks.");
    ui.log("[Building] " + name + " has position = " + std::to_string(position.x) + " " + std::to_string(position.y));
}

void Building::Tick(ConsoleUI& ui) {
    ticksAlive++;
    showStatus(ui);
}