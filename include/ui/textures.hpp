#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include <string>
#include <stdexcept>

class Textures {
public:
    sf::Texture& load(const std::string& filename);
    
    void preload(std::initializer_list<std::string> filenames);
    void clear() noexcept;
    
private:
    static std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_textures;
};