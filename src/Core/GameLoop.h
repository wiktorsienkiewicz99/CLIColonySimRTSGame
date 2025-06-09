//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#pragma once

#include <atomic>
#include <queue>
#include <mutex>
#include <condition_variable>

#include "../Map/World.h"
#include "./CommandSystem/CommandProcessor/CommandProcessor.h"


class GameLoop {
public:
    GameLoop(ConsoleUI& ui) : commandProcessor(ui), ui(ui) {}
    void run();
    ~GameLoop();
private:
    void tickLoop();
    void inputLoop();

    std::atomic<bool> isRunning = true;
    World world;
    CommandProcessor commandProcessor;
    ConsoleUI& ui;

    std::queue<std::string> commandQueue;
    std::mutex queueMutex;
    std::condition_variable commandAvailable;
};