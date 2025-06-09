#pragma once
#include <string>
#include <mutex>
#include <ncurses.h>

class ConsoleUI {
public:
    ConsoleUI();
    ~ConsoleUI();

    void log(const std::string& message);
    std::string readCommand();
    void refreshInput();

private:
    void initWindows();

    WINDOW* logWin;
    WINDOW* inputWin;

    std::string currentInput;
    std::mutex uiMutex;
};