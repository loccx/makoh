#include "tile.hpp"
#include <stdexcept>

void Tile::validate() const {
    // Validate texture
    if (skin.getTexture() == nullptr) {
        throw std::runtime_error("Tile has no texture assigned!");
    }

    // Validate number ranges
    if (m_type == Type::TONG || m_type == Type::WAN || m_type == Type::TIAO) {
        if (m_number < 1 || m_number > 9) {
            throw std::invalid_argument("Numbered tiles must be 1-9");
        }
    }
    // Dragons don't have numbers
    else if (m_type == Type::DRAGON && m_number != 0) {
        throw std::invalid_argument("Dragon tiles cannot have numbers");
    }
}

void Tile::setNumber(int num) {
    if (m_type == Type::DRAGON || m_type == Type::WIND || m_type == Type::FLOWER) {
        throw std::logic_error("This tile type doesn't support numbers");
    }
    m_number = num;
}

void Tile::setDragon(Dragon dragon) {
    if (m_type != Type::DRAGON) {
        throw std::logic_error("Can only set dragon type on dragon tiles");
    }
    m_dragon = dragon;
}
