#include "ConsoleUI.h"
#include <cctype>
#include <iostream>  // for debug fallback

ConsoleUI::ConsoleUI() {
    initscr();
    cbreak();
    noecho();
    curs_set(1);
    keypad(stdscr, TRUE);
    initWindows();
}

ConsoleUI::~ConsoleUI() {
    delwin(logWin);
    delwin(inputWin);
    endwin();
}

void ConsoleUI::initWindows() {
    int height, width;
    getmaxyx(stdscr, height, width);

    logWin = newwin(height - 3, width, 0, 0);
    inputWin = newwin(3, width, height - 3, 0);

    scrollok(logWin, TRUE);
    keypad(inputWin, TRUE);  // ✅ Needed for KEY_ENTER, etc.

    werase(logWin);
    box(logWin, 0, 0);
    wrefresh(logWin);

    refreshInput();
}

void ConsoleUI::log(const std::string& message) {
    std::lock_guard lock(uiMutex);
    wprintw(logWin, "%s\n", message.c_str());
    wrefresh(logWin);
    refreshInput();
}

void ConsoleUI::refreshInput() {
    werase(inputWin);
    box(inputWin, 0, 0);
    mvwprintw(inputWin, 1, 1, "> %s", currentInput.c_str());
    wmove(inputWin, 1, 3 + currentInput.length());
    wrefresh(inputWin);
}

std::string ConsoleUI::readCommand() {
    currentInput.clear();

    while (true) {
        int ch = wgetch(inputWin);

        // DEBUG fallback to terminal
        // std::cerr << "KEY PRESSED: " << ch << std::endl;

        if (ch == '\n' || ch == '\r' || ch == 10 || ch == 13 || ch == KEY_ENTER) {
            break;
        }

        std::lock_guard lock(uiMutex);

        if (ch == KEY_BACKSPACE || ch == 127 || ch == '\b') {
            if (!currentInput.empty()) {
                currentInput.pop_back();
            }
        } else if (std::isprint(ch)) {
            currentInput.push_back(static_cast<char>(ch));
        }

        werase(inputWin);
        box(inputWin, 0, 0);
        mvwprintw(inputWin, 1, 1, "> %s", currentInput.c_str());
        wmove(inputWin, 1, 3 + currentInput.length());
        wrefresh(inputWin);
    }

    std::string result = currentInput;
    currentInput.clear();
    refreshInput();
    return result;
}