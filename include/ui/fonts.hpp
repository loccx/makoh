#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include <stdexcept>
#include <string_view>


class Fonts {
public:
    /*
     * retrieves texture from map if exists, otherwise insert to map
     */
    sf::Font& load(std::string_view filename);
    
    /*
     * initializer list of file names to load
     */
    void preload(std::initializer_list<std::string_view> filenames);

    void clear();
    
private:
    std::unordered_map<std::string, std::unique_ptr<sf::Font>> m_fonts;
};

