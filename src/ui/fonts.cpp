#include "ui/fonts.hpp"
#include "utils/path_utils.hpp"
#include <format>

/*
 * retrieves font from map if exists, otherwise insert to map
 */
sf::Font& Fonts::load(std::string_view filename) {
    auto it = m_fonts.find(filename);
    if (it != m_fonts.end()) {
        return *it->second;
    }
    
    const std::string path = std::format("fonts/{}", filename);
    auto font = std::make_unique<sf::Font>();

    if (!font->loadFromFile(Resoource::resources(path))) {
        throw std::runtime_error(std::string("Failed to load font: ") + filename.data());
    }
    
    auto& ref = *font;
    m_fonts.emplace(filename, std::move(font));
    return ref;
}

/*
 * initializer list of file names to load
 */
void Fonts::preload(std::initializer_list<std::string_view> filenames) {
    for (auto filename : filenames) {
        load(filename);
    }
}

void Fonts::clear() noexcept {
    m_fonts.clear();
}

