#pragma on

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
#include "utils/constants.hpp"

class GameController {
public:
    explicit GameController(sf::RenderWindow& window, Textures& textures, Fonts& fonts);
    
    // Event handling
    void handleEvent(const sf::Event& event);
    
    // Game loop methods
    void update(float deltaTime);
    void render();
    
    // Game actions
    void dealCards();
    void shuffleDeck();

private:
    sf::RenderWindow& window_;
    std::vector<std::unique_ptr<Button>> buttons_;
    Textures textures_;
    Fonts fonts_;
    
    // Game state
    std::deque<Tile> deck_;
    std::vector<Tile> hand_;
    
    void initDeck_();
    void initUI_();
    void positionHand_(float y_offset);
};
