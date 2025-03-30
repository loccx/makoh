#include "core/game_controller.hpp"

GameController::GameController(sf::RenderWindow& window, Textures& textures, Fonts& fonts) 
    : window_(window), textures_(textures), fonts_(fonts) {
        assert(&textures != nullptr);
        assert(&fonts != nullptr);
        initDeck_();
        initUI_();
}

void GameController::handleEvent(const sf::Event& event) {
    if (event.is<sf::Event::Closed>()) {
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
    
    // Draw tiles
    for (const auto& tile : hand_) {
        tile.draw(window_);
    }
    
    // Draw buttons
    for (const auto& button : buttons_) {
        button->draw(window_);
    }
    
    window_.display();
}

void GameController::dealCard() {
    if (deck_.empty() || hand_.size() >= Constants::HANDSIZE) return;
    
    hand_.push_back(deck_.front());
    deck_.pop_front();
    positionHand_(20.0f);
}

void GameController::shuffleDeck() {
    std::random_device rd;
    std::mt19937 gen(rd());
    shuffle(deck_.begin(), deck_.end(), gen);
}

void GameController::initDeck_() {
    // tiao types
    for (int i = 0; i < 4; i++) {
        for (int j = 2; j <= 9; j++) {
            deck_.emplace_back(textures_.load("tiao_" + std::to_string(j)), Type::TIAO, j);
        }
    }
}

/*
 * initialize buttons  here
 *    link controller functions callbacks to buttons
 */
void GameController::initUI_() {
    auto dealButton = std::make_unique<Button>(
        sf::Vector2f(100, 100), 
        textures_.load("deal_button"), 
        "deal me!", 
        fonts_.load("balatro")
    );
    
    dealButton->setOnClick([this]() {
        this->dealCard();
    });

    auto testButton = std::make_unique<Button>(
        sf::Vector2f(500, 500),
        textures_.load("key"),
        "fuck you",
        fonts_.load("balatro")
    );
    
    buttons_.push_back(std::move(dealButton));
    buttons_.push_back(std::move(testButton));
}

/*
 * y_offset (float) : offset of y posiiton of the hand row from bottom of the screen
 */
void GameController::positionHand_(float y_offset) {
    float total_width = 0.f;
    float max_height = 0.f;
    const float tile_hand_spacing = 10.f;

    for (auto& tile : hand_) {
        total_width += tile.getWidth() + tile_hand_spacing;
        max_height = fmax(max_height, tile.getHeight());
    }
    total_width -= tile_hand_spacing;

    float startX = (window_.getSize().x - total_width) / 2.f;
    float y_pos = (window_.getSize().y - max_height - y_offset);
    float curr_x = startX;
    for (auto& tile : hand_) {
        tile.setPosition(curr_x, y_pos);
        curr_x += tile.getWidth() + tile_hand_spacing;
    }
}
