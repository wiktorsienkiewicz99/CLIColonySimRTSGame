//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//
#include "CommandProcessor.h"
#include <sstream>
#include <iostream>
#include "../CommandsList/CommandsList.h"

CommandProcessor::CommandProcessor(ConsoleUI& ui)
    : registry(ui) // ✅ explicitly initialize the member
{
    registry.putToRegister(std::make_unique<AddUnitCommand>());
    registry.putToRegister(std::make_unique<AddBuildingCommand>());
    registry.putToRegister(std::make_unique<HelpCommand>(registry));
}
void CommandProcessor::process(const std::string& input, World& world) {
    std::istringstream iss(input);
    std::string name;
    iss >> name;

    std::vector<std::string> args;
    std::string arg;
    while (iss >> arg) {
        args.push_back(arg);
    }

    registry.execute(name, args, world);
}

CommandRegistry& CommandProcessor::GetRegistry() {
    return registry;
}