#include "ui/tile.hpp"
#include <stdexcept>

void Tile::validate() const {
    // Validate texture
    if (skin.getTexture().getSize() == sf::Vector2u(0, 0)) {
        throw std::runtime_error("Tile has no texture assigned!");
    }

    // Validate type-specific constraints
    switch (m_type) {
        case Type::TONG:
        case Type::WAN:
        case Type::TIAO:
            if (!m_number || *m_number < 1 || *m_number > 9) {
                throw std::invalid_argument("Numbered tiles must be 1-9");
            }
            break;
            
        case Type::DRAGON:
            if (m_number) {
                throw std::invalid_argument("Dragon tiles cannot have numbers");
            }
            if (!m_dragon) {
                throw std::invalid_argument("Dragon tiles must specify dragon type");
            }
            break;

        case Type::WIND:
            if (m_number) {
                throw std::invalid_argument("Dragon tiles cannot have numbers");
            }
            if (!m_direction) {
                throw std::invalid_argument("Wind tiles must have a direction");
            }
            break;

        case Type::FLOWER:
            if (!m_number || *m_number < 1 || *m_number > 4) {
                throw std::invalid_argument("Numbered flowers must be 1-4");
            }
            break;
            
        case Type::NONE:
            if (m_number || m_dragon || m_direction) {
                throw std::logic_error("NONE type cannot have other properties");
            }
            break;
            
    }
}

bool Tile::isNumberValid(int num) const {
    switch (m_type) {
        case Type::TONG:
        case Type::WAN:
        case Type::TIAO:
            return (num >= 1 && num <= 9);
        default:
            return false;
    }
}