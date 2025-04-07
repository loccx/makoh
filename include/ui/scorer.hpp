#pragma once
#include <SFML/Graphics.hpp>

#include <vector>
#include <unordered_map>

#include "ui/tile.hpp"
#include "utils/enum.hpp"

class Scorer {
public:
    Scorer() = delete; // no default constructor

    Scorer(std::vector<Tile>& hand);
    /*
    if numeric tile, put into vector and sort it to check for sequences

    dragon type:  map<type : count>
    direction type:  map<type : count>
    dragon type:  map<type : count>
    */

private:
    // general types
    unordered_map<Type, int> types;

    // characters
    unordered_map<Dragon, int> dragons;
    unordered_map<Direction, int> winds;

    // numbered types
    unordered_map<Type, unordered_map<int, int>> numberedTypes;

    // flowers
    unordered_map<Flower, unordered_map<int, int>> flowers;
    // unordered_map<int, int> tongNums;
    // unordered_map<int, int> wanNums;
    // unordered_map<int, int> tiaoNums;
};