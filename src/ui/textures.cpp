#include "ui/textures.hpp"
#include "utils/path_utils.hpp"
#include <format>

std::unordered_map<std::string, std::unique_ptr<sf::Texture>> Textures::m_textures;

sf::Texture& Textures::load(const std::string& filename) {
    if (auto it = m_textures.find(filename); it != m_textures.end()) {
        return *it->second;
    }
    
    const std::string path = std::format("textures/{}.png", filename);
    auto texture = std::make_unique<sf::Texture>();
   
    if (!texture->loadFromFile(Resource::resources(path))) {
        throw std::runtime_error(std::format("Failed to load texture: {}", path));
    }
    
    auto& ref = *texture;
    m_textures.emplace(filename, std::move(texture));
    return ref;
}

void Textures::preload(std::initializer_list<std::string> filenames) {
    for (const auto& filename : filenames) {
        load(filename);
    }
}

void Textures::clear() noexcept {
    m_textures.clear();
}