//
// Created by Wiktor Sienkiewicz on 09/06/2025.
//

#pragma once

struct Position2D {
    int x = 0;
    int y = 0;

    Position2D() = default;
    Position2D(int xPos, int yPos) : x(xPos), y(yPos) {}

    Position2D(const std::string& xPos, const std::string& yPos) {
        x = std::stoi(xPos);
        y = std::stoi(yPos);
    };

    bool operator==(const Position2D& other) const {
        return x == other.x && y == other.y;
    }

    Position2D operator+(const Position2D& other) const {
        return {x + other.x, y + other.y};
    }

    Position2D operator-(const Position2D& other) const {
        return {x - other.x, y - other.y};
    }
};