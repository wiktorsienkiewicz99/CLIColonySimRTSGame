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
}

void World::AddEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}
