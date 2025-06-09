//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#include "Unit.h"

#include <iostream>

#include "../../UI/ConsoleUI.h"

void Unit::showStatus(ConsoleUI& ui) const {
    ui.log("[Unit] " + name + " is getting hungry. Hunger = " + std::to_string(hunger));
    ui.log("[Unit] " + name + " has position = " +
           std::to_string(position.x) + " " + std::to_string(position.y));
}

void Unit::Tick(ConsoleUI& ui) {
    hunger++;
    showStatus(ui);

}
