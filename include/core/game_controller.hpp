#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <deque>

#include "ui/button.hpp"
#include "ui/tile.hpp"
#include "ui/textures.hpp"
#include "ui/fonts.hpp"
#include "ui/tile_selector.hpp"
#include "utils/constants.hpp"
#include "utils/states.hpp"

class GameController {
public:
    explicit GameController(sf::RenderWindow& window, Textures& textures, Fonts& fonts);
    
    void handleEvent(const sf::Event& event);
    void update(float deltaTime);
    void render();

    void setState(GameState newstate);
    GameState getState() const;
    
    void dealContainer(std::vector<Tile>& tileContainer, float y_pos, const float& constraint);
    void shuffleDeck();

private:
    GameState currState_ = GameState::MAINMENU;
    sf::RenderWindow& window_;
    std::vector<std::unique_ptr<Button>> buttons_;
    Textures& textures_;
    Fonts& fonts_;
    
    std::deque<Tile> deck_;
    std::vector<Tile> hand_;
    std::vector<Tile> flop_;
    TileSelector tileSelector_;
    Scorer scorer_;
    
    void initUI_();
    void initDeck_();

    void dealTile(std::vector<Tile>& tileContainer, float& y_pos, const float& constraint);
    void positionContainer_(std::vector<Tile>& tileContainer, float y_offset);
};
