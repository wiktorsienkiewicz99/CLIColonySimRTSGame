//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//
#pragma once
#include <memory>
#include <unordered_map>
#include "../Command/Command.h"
#include "../../../UI/ConsoleUI.h"

class CommandRegistry {
public:
    CommandRegistry(ConsoleUI& ui): ui(ui) {};
    void putToRegister(std::unique_ptr<Command> command);
    void execute(const std::string& name, const std::vector<std::string>& args, World& world) const;
    void listCommands(World& world) const;
private:
    std::unordered_map<std::string, std::unique_ptr<Command>> commands;
    ConsoleUI& ui;
};