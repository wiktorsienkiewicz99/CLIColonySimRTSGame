//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#pragma once

#include <utility>

#include "../Entity.h"

class ConsoleUI;

class Unit : public Entity {
public:
    Unit(Position2D position, std::string name) : Entity(position, std::move(name)) {}
    void showStatus(ConsoleUI& ui) const override;
    void Tick(ConsoleUI& ui) override;
    char GetSymbol() const override { return 'U'; }
private:
    int hunger = 0;
};
