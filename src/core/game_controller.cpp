#include <iostream>

#include "core/game_controller.hpp"

GameController::GameController(sf::RenderWindow& window, Textures& textures, Fonts& fonts) 
    : window_(window), textures_(textures), fonts_(fonts) {
        assert(&textures != nullptr);
        assert(&fonts != nullptr);
        initDeck_();
        shuffleDeck();
        initUI_();
}

void GameController::handleEvent(const sf::Event& event) {
    if (event.is<sf::Event::Closed>()) {
        textures_.clear();
        fonts_.clear();
        window_.close();
        return;
    }
    for (auto& button : buttons_) {
        button->handleEvent(event, window_);
    }
}

void GameController::update(float deltaTime) {
    // Update game state (animations, timers, etc.)
}

void GameController::render() {
    window_.clear(sf::Color::Black);

    for (const auto& tile : hand_) {
        tile.draw(window_);
    }
    for (const auto& tile : flop_) {
        tile.draw(window_);
    }

    for (const auto& button : buttons_) {
        button->draw(window_);
    }

    window_.display();
}

/*
point of this is to just loop the deal tile until a container is full
*/
void GameController::dealContainer(std::vector<Tile>& tileContainer, float y_pos, const float& constraint) {
    while (tileContainer.size() < constraint) {
        dealTile(tileContainer, y_pos, constraint);
    }
}

void GameController::dealTile(std::vector<Tile>& tileContainer, float& y_pos, const float& constraint) {
    if (deck_.empty() || tileContainer.size() >= constraint) return;
    
    tileContainer.push_back(deck_.front());
    deck_.pop_front();
    positionContainer_(tileContainer, y_pos);
}

void GameController::shuffleDeck() {
    std::random_device rd;
    std::mt19937 gen(rd());
    shuffle(deck_.begin(), deck_.end(), gen);
}

/*
 * initialize buttons  here
 *    link controller functions callbacks to buttons
 */
void GameController::initUI_() {
    //TODO
    // initDeckUI();

    auto dealHandButton = std::make_unique<Button>(
        sf::Vector2f(100, 100), 
        textures_.load("deal_hand_button"), 
        "deal me!", 
        fonts_.load("balatro")
    );
    dealHandButton->setOnClick([this]() {
        this->dealContainer(hand_, Constants::HAND_YPOS, Constants::HANDSIZE);
    });

    auto dealFlopButton = std::make_unique<Button>(
        sf::Vector2f(500, 100), 
        textures_.load("deal_flop_button"), 
        "hit me.", 
        fonts_.load("balatro")
    );
    dealFlopButton->setOnClick([this]() {
        this->dealContainer(flop_, Constants::FLOP_YPOS, Constants::FLOPSIZE);
    });

    buttons_.push_back(std::move(dealHandButton));
    buttons_.push_back(std::move(dealFlopButton));
}

void GameController::initDeck_() {
    // 144 tiles
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 9; j++) {
            deck_.emplace_back(textures_.load("tiao_" + std::to_string(j)), Type::TIAO, j);
            deck_.emplace_back(textures_.load("tong_" + std::to_string(j)), Type::TONG, j);
            deck_.emplace_back(textures_.load("wan_" + std::to_string(j)), Type::WAN, j);
        }
        for (int j = 1; j <= 2; j++) {
            deck_.emplace_back(textures_.load("flower_" + std::to_string(i+1)), Type::FLOWER, i+1);
        }
        deck_.emplace_back(textures_.load("wind_bei_v1"), Direction::BEI);
        deck_.emplace_back(textures_.load("wind_dong_v1"), Direction::DONG);
        deck_.emplace_back(textures_.load("wind_nan_v1"), Direction::NANN);
        deck_.emplace_back(textures_.load("wind_xi_v1"), Direction::XI);
        deck_.emplace_back(textures_.load("dragon_fu_v1"), Dragon::FU);
        deck_.emplace_back(textures_.load("dragon_pi_v1"), Dragon::PI);
        deck_.emplace_back(textures_.load("dragon_zhong_v2"), Dragon::ZHONG);
    }
}

/*
 * y_offset (float) : offset of y posiiton of the hand row from bottom of the screen
 */
void GameController::positionContainer_(std::vector<Tile>& tileContainer, float y_offset) {
    if (tileContainer.empty()) return;

    const float maxTotalWidth = window_.getSize().x * 0.8f;
    const float minSpacing = 5.0f;
    const float tileWidth = tileContainer[0].getWidth();
    const float maxHeight = tileContainer[0].getHeight();
    
    float totalContentWidth = tileContainer.size() * tileWidth;
    float availableSpace = maxTotalWidth - totalContentWidth;
    float spacing = (tileContainer.size() > 1) 
        ? std::max(minSpacing, availableSpace / (tileContainer.size() - 1)) 
        : 0.0f;
    
    float totalWidth = totalContentWidth + (spacing * (tileContainer.size() - 1));
    float startX = (window_.getSize().x - totalWidth) / 2.0f;
    float y_pos = window_.getSize().y - maxHeight - y_offset;

    float curr_x = startX;
    for (auto& tile : tileContainer) {
        tile.setPosition(curr_x, y_pos);
        curr_x += tileWidth + spacing;
    }
}
