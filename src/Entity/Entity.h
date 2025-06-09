//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#pragma once

#include <string>
#include <utility>
#include "../Core/Coordinates/Position2D.h"


class ConsoleUI;

class Entity {
public:
    Entity(Position2D position, std::string name) : position(position), name(std::move(name)) {};
    Entity(int xPos, int yPos, std::string name) : position(xPos, yPos), name(std::move(name)) {
        position = Position2D(xPos, yPos);
    };
    virtual ~Entity() = default;
    virtual void Tick(ConsoleUI& ui) = 0;
    virtual void showStatus(ConsoleUI& ui) const = 0;
    std::string GetName() {return name;};
    Position2D GetPosition() const { return position; }
    void SetPosition(Position2D position) { position = position; }

protected:
    Position2D position;
    std::string name;

};
