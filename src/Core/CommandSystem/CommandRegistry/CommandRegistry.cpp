//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#include "CommandRegistry.h"
#include <iostream>

void CommandRegistry::putToRegister(std::unique_ptr<Command> command) {
    commands[command->name()] = std::move(command);
}

void CommandRegistry::execute(const std::string& name, const std::vector<std::string>& args, World& world) const {
    auto it = commands.find(name);
    if (it != commands.end()) {
        it->second->execute(args, world, ui);
    } else {
        ui.log("Unknown command: " + name);
        return;
    }
}

void CommandRegistry::listCommands(World& world) const {
    std::cout << "Available commands:\n";
    for (const auto& [name, cmd] : commands) {
        ui.log(" - " + name + ": " + cmd->description());
    }
}