//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#pragma once

#include <vector>
#include <memory>
#include "../Entity/Entity.h"
#include "../UI/ConsoleUI.h"

class ConsoleUI;

class World {
public:
    void Tick(ConsoleUI& ui);
    void AddEntity(std::shared_ptr<Entity> entity);
    void Display(ConsoleUI& ui) const;
    static constexpr int width = 20;
    static constexpr int height = 10;
private:
    int currentTick = 0;
    std::vector<std::shared_ptr<Entity>> entities;
};
