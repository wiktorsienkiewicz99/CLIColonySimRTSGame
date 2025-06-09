//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#include "CommandsList.h"
#include "../../../Entity/Units/Unit.h"
#include "../../../Entity/Buildings/Building.h"
#include <iostream>

void AddUnitCommand::execute(const std::vector<std::string>& args, World& world, ConsoleUI& ui) {
    if (args.size() == 1) {
        world.AddEntity(std::make_shared<Unit>(Position2D(0,0), args[0]));
    }
    else if (args.size() == 3) {
        //std::cout << args[0] << " " << args[1] << " " << args[2] << std::endl;
        world.AddEntity(std::make_shared<Unit>(Position2D(args[1],args[2]), args[0]));
    }
    else {
        std::cout << "WRONG COMMAND!"  << description() << "\n";
    }
}

void AddBuildingCommand::execute(const std::vector<std::string>& args, World& world, ConsoleUI& ui) {
    if (args.size() == 1) {
        world.AddEntity(std::make_shared<Building>(Position2D(0,0), args[0]));
    }
    else if (args.size() == 3) {
        world.AddEntity(std::make_shared<Building>(Position2D(args[1],args[2]), args[0]));
    }
    else {
        std::cout << "WRONG COMMAND!"  << description() << "\n";
    }
}

void HelpCommand::execute(const std::vector<std::string>&, World& world, ConsoleUI& ui) {
    registry.listCommands(world);
}