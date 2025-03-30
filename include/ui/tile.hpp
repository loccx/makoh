#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include "utils/enum.hpp"

class Tile {
public:
    Tile() = delete;    

    explicit Tile(sf::Texture& texture, Type type = Type::NONE, 
                std::optional<int> number = std::nullopt)
        : skin(texture), m_type(type), m_number(number) {
        validate();
    }
    
    explicit Tile(sf::Texture& texture, Dragon dragon)
        : skin(texture), m_type(Type::DRAGON), m_dragon(dragon) {
        validate();
    }

    void draw(sf::RenderTarget& target) const {
        target.draw(skin);
    }

    // getters
    Type getType() const { return m_type; }
    std::optional<int> getNumber() const { return m_number; }
    std::optional<Dragon> getDragon() const { return m_dragon; }
    std::optional<Direction> getDirection() const { return m_direction; }
    
    // tile dimensions
    sf::Vector2f getSize() const { 
        auto bounds = skin.getLocalBounds();
        return {bounds.size.x, bounds.size.y};
    }
    float getWidth() const { return getSize().x; }
    float getHeight() const { return getSize().y; }

    // setters
    void setPosition(float x, float y) { skin.setPosition({x, y}); }
    void setType(Type type) { m_type = type; }
    
    void setNumber(std::optional<int> num) {
        if (num && !isNumberValid(*num)) {
            throw std::invalid_argument("Invalid tile number");
        }
        m_number = num;
    }
    
    void setDragon(std::optional<Dragon> dragon) {
        if (dragon) m_type = Type::DRAGON;
        m_dragon = dragon;
    }
    
    void setDirection(std::optional<Direction> dir) {
        m_direction = dir;
    }

private:
    sf::Sprite skin;
    Type m_type = Type::NONE;
    std::optional<int> m_number;
    std::optional<Dragon> m_dragon;
    std::optional<Direction> m_direction;

    void validate() const {
        if (skin.getTexture().getSize() == sf::Vector2u(0, 0)) {
            throw std::runtime_error("Tile has no valid texture");
        }
        
        if (m_type == Type::NONE && (m_number || m_dragon || m_direction)) {
            throw std::logic_error("NONE type cannot have other properties");
        }
    }
    
    bool isNumberValid(int num) const {
        return (m_type == Type::TONG || m_type == Type::WAN || m_type == Type::TIAO) 
               ? (num >= 1 && num <= 9)
               : (num == 0 || !num);
    }
};
