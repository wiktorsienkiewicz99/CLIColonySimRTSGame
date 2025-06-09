//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#pragma once
#include <string>
#include "../CommandRegistry/CommandRegistry.h"


class CommandProcessor {
public:
    CommandProcessor(ConsoleUI& ui);
    void process(const std::string& input, World& world);
    CommandRegistry& GetRegistry();

private:
    CommandRegistry registry;
};