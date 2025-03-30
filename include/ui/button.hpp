#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>

class Button {
public:
    Button(const sf::Vector2f& position, 
           const sf::Texture& texture, 
           const std::string& label, 
           const sf::Font& font,
           std::unordered_set<GameState> activeStates
    );

    void draw(sf::RenderTarget& target) const;
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);

    void setOnClick(std::function<void()> callback);
    void setTextures(const sf::Texture& idle, 
                    const sf::Texture& hover, 
                    const sf::Texture& active);

    bool isValidState(GameState gameState) {
        return activeStates.count(gameState);
    }

private:
    sf::Sprite sprite;
    sf::Text text;
    std::function<void()> callback;
    std::unordered_set<GameState> activeStates;

    enum class State { IDLE, HOVERED, PRESSED };
    State state = State::IDLE;

    const sf::Texture* idleTexture;
    const sf::Texture* hoverTexture;
    const sf::Texture* activeTexture;
};
