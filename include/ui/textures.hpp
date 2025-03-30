#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <string>
#include <stdexcept>
#include <mutex>

class Textures {
public:
    ~Textures() {
        clear();
    }

    sf::Texture& load(const std::string& filename);
    
    void preload(std::initializer_list<std::string> filenames);
    void clear() noexcept;
    
private:
    std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
    std::mutex m_mutex;
};