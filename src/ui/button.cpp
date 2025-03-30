#include "ui/button.hpp"

Button::Button(const sf::Vector2f& position, 
              const sf::Texture& texture, 
              const std::string& label, 
              const sf::Font& font)
    : sprite(texture),
      text(font, label, 20)
{
    setTextures(texture, texture, texture);

    sf::FloatRect spriteBounds = sprite.getLocalBounds();
    sprite.setOrigin({(spriteBounds.size.x)/2.f, (spriteBounds.size.y)/2.f});
    sprite.setPosition(position);
    
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin({(textBounds.size.x)/2.f, (textBounds.size.y)/2.f});
    text.setPosition(position);
}

/*
void Button::update(const sf::Time& deltaTime) {
    // Optional animation logic
}
*/

void Button::draw(sf::RenderTarget& target) const {
    target.draw(sprite);
    target.draw(text);
}

void Button::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (event.is<sf::Event::MouseButtonPressed>()) {
        const auto& mouseEvent = *event.getIf<sf::Event::MouseButtonPressed>();
        
        if (mouseEvent.button == sf::Mouse::Button::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(mouseEvent.position);
            
            if (sprite.getGlobalBounds().contains(mousePos)) {
                state = State::PRESSED;
                sprite.setTexture(*activeTexture, true);
                
                if (callback) {
                    callback();
                }
            }
        }
    }
    else if (event.is<sf::Event::MouseMoved>()) {
        const auto& mouseEvent = *event.getIf<sf::Event::MouseMoved>();
        sf::Vector2f mousePos = window.mapPixelToCoords(mouseEvent.position);
        
        if (sprite.getGlobalBounds().contains(mousePos)) {
            state = State::HOVERED;
            sprite.setTexture(*hoverTexture, true);
        } else {
            state = State::IDLE;
            sprite.setTexture(*idleTexture, true);
        }
    }
}

void Button::setOnClick(std::function<void()> callback) {
    this->callback = std::move(callback);
}

void Button::setTextures(const sf::Texture& idle, 
                        const sf::Texture& hover, 
                        const sf::Texture& active) {
    idleTexture = &idle;
    hoverTexture = &hover;
    activeTexture = &active;
    sprite.setTexture(*idleTexture, true);
}
