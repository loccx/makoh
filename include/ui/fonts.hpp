#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <string_view>
#include <stdexcept>
#include <mutex>

class Fonts {
public:
    ~Fonts() {
        clear();
    }

    sf::Font& load(const std::string& filename);
    
    void preload(std::initializer_list<std::string> filenames);
    void clear() noexcept;
    
private:
    std::map<std::string, std::unique_ptr<sf::Font>> m_fonts;
    std::mutex m_mutex;
};

