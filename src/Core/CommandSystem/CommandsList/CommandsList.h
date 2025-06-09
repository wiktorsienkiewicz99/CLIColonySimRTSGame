//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#pragma once
#include "../Command/Command.h"
#include "../CommandRegistry/CommandRegistry.h"

class AddUnitCommand : public Command {
public:
    std::string name() const override { return "add_unit"; }
    std::string description() const override { return "Add a unit to the world. Usage: add_unit <name>"; }
    void execute(const std::vector<std::string>& args, World& world, ConsoleUI& ui) override;
};

class AddBuildingCommand : public Command {
public:
    std::string name() const override { return "add_building"; }
    std::string description() const override { return "Add a building to the world. Usage: add_building <name>"; }
    void execute(const std::vector<std::string>& args, World& world, ConsoleUI& ui) override;
};

class HelpCommand : public Command {
public:
    HelpCommand(const CommandRegistry& registry) : registry(registry) {}
    std::string name() const override { return "help"; }
    std::string description() const override { return "List all available commands."; }
    void execute(const std::vector<std::string>& args, World& world, ConsoleUI& ui) override;
private:
    const CommandRegistry& registry;
};