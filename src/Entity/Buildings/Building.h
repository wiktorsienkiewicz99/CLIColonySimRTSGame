//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#pragma once

#include <utility>

#include "../Entity.h"

class ConsoleUI;

class Building : public Entity {
public:
    Building(Position2D position, std::string name) : Entity(position, std::move(name)) {}
    void Tick(ConsoleUI& ui) override;
    void showStatus(ConsoleUI& ui) const override;
    char GetSymbol() const override { return 'B'; }
private:
    int ticksAlive = 0;
};
