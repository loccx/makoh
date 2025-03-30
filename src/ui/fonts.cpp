#include <format>

#include "ui/fonts.hpp"
#include "utils/path_utils.hpp"

/*
 * retrieves font from map if exists, otherwise insert to map
 */
sf::Font& Fonts::load(const std::string& filename) {
    if (auto it = m_fonts.find(filename); it != m_fonts.end()) {
        return *it->second;
    }
    
    const std::string path = std::format("fonts/{}.ttf", filename);
    auto font = std::make_unique<sf::Font>();

    if (!font->openFromFile(Resource::resources(path))) {
        throw std::runtime_error(std::string("Failed to load font: ") + filename.data());
    }
    
    auto& ref = *font;
    m_fonts.emplace(filename, std::move(font));
    return ref;
}

void Fonts::preload(std::initializer_list<std::string> filenames) {
    for (auto filename : filenames) {
        load(filename);
    }
}

void Fonts::clear() noexcept {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fonts.clear();
}

