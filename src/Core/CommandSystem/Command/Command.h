//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#pragma once
#include <string>
#include <vector>
#include "../../../Map/World.h"

class Command {
public:
    virtual ~Command() = default;
    virtual std::string description() const = 0;
    virtual void execute(const std::vector<std::string>& args, World& world, ConsoleUI& ui) = 0;
    virtual std::string name() const = 0;
};