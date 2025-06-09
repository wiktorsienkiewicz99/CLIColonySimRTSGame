//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//
#include <iostream>
#include <thread>
#include <chrono>

#include "GameLoop.h"


void GameLoop::run() {
    constexpr int tickRateMs = 1000;
    std::thread inputThread([&]() {
        while (isRunning) {
            std::string input = ui.readCommand();
            if (input == "exit") {
                isRunning = false;
                break;
            }
            commandProcessor.process(input, world);
        }
    });

    while (isRunning) {
        world.Tick(ui);
        std::this_thread::sleep_for(std::chrono::milliseconds(tickRateMs));
    }

    inputThread.join();
}

void GameLoop::tickLoop() {
    constexpr int tickRateMs = 1000;

    while (isRunning) {
        // Process any queued commands
        {
            std::unique_lock lock(queueMutex);
            while (!commandQueue.empty()) {
                std::string command = commandQueue.front();
                commandQueue.pop();

                if (command == "exit") {
                    isRunning = false;
                    return;
                }
                commandProcessor.process(command, world);
            }
        }

        world.Tick(ui);
        std::this_thread::sleep_for(std::chrono::milliseconds(tickRateMs));
    }
}

void GameLoop::inputLoop() {
    while (isRunning) {
        std::string input;
        std::getline(std::cin, input);

        std::unique_lock lock(queueMutex);
        commandQueue.push(input);
        commandAvailable.notify_one();
    }
}

GameLoop::~GameLoop() {
    isRunning = false;
}