#pragma once

#include <SFML/Graphics.hpp>

#include <unordered_set>

#include "ui/tile.hpp"

class TileSelector {
public:
    TileSelector(int selectLimit) : selectLimit(selectLimit) {}

    void selectTiles(
        sf::Vector2f& mouseCoords,
        std::vector<Tile>& hand_,
        std::vector<Tile>& flop_
    );
    bool swapTiles(std::vector<Tile>& hand_, std::vector<Tile>& flop_);
    void clearSelections();

private:
    std::unordered_set<Tile*> selectedHand_;
    std::unordered_set<Tile*> selectedFlop_;
    int selectLimit;

    bool validSwap() const;
};