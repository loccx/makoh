#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include <string>
#include <stdexcept>

class Textures {
public:
    // Load or get existing texture
    sf::Texture& load(const std::string& filename);
    
    // Bulk load textures
    void preload(std::initializer_list<std::string> filenames);

    // Clear all textures
    void clear() noexcept;
    
private:
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_textures;
};