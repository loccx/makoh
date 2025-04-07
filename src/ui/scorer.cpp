#include <iostream>
#include "ui/scorer.hpp"

Scorer::Scorer(std::vector<Tile>& hand) {
    for (auto& tile : hand) {
        auto& type = tile.getType();
        if (type == Tile::TONG || type == Tile::TIAO || type == Tile::WAN) {
            auto& num = tile.getNumber();
            numberedTypes[type][num]++;
            break;
        }
        switch (type) {
            case Tile::WIND:
                winds[tile.getDirection()]++;
                break;
            case Tile::DRAGON:
                winds[tile.getDragon()]++;
                break;
            case Tile::FLOWER:
                flowers[type][tile.getNumber()]++;
        }
    }
};