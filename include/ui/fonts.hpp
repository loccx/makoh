#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include <stdexcept>
#include <string_view>

class Fonts {
public:
    sf::Font& load(const std::string& filename);
    
    void preload(std::initializer_list<std::string> filenames);
    void clear() noexcept;
    
private:
    static std::unordered_map<std::string, std::unique_ptr<sf::Font>> m_fonts;
};

