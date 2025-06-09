//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#include "World.h"

#include <iostream>

#include "../UI/ConsoleUI.h"

void World::Tick(ConsoleUI& ui) {
    ++currentTick;
    //std::cout << "Tick " << currentTick << std::endl;

    for (auto& entity : entities) {
        entity->Tick(ui);
    }
    Display(ui);
}

void World::AddEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void World::Display(ConsoleUI& ui) const {
    std::vector<std::string> grid(height, std::string(width, '.'));
    for (const auto& entity : entities) {
        Position2D pos = entity->GetPosition();
        if (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height) {
            grid[pos.y][pos.x] = entity->GetSymbol();
        }
    }

    ui.log("Map:");
    for (const auto& row : grid) {
        ui.log(row);
    }
}
