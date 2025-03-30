#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include <random>

#include "core/game_controller.hpp"
#include "ui/tile.hpp"
#include "ui/textures.hpp"
#include "ui/functions.hpp"
#include "utils/enum.hpp"
#include "utils/button.hpp"
#include "utils/constants.hpp"


/*
 * runs game window
 */
int main() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "makoh", sf::Style::Default, sf::State::Fullscreen);

    std::deque<Tile> deck;
    std::vector<Tile> hand;

    /*
     * texture loading
     */
    Textures textures;
    textures.load(getResourcePath("sprites/button.png"));
    auto tiao_textures = loadTextures(textures, "tiao", 2, 9);
    /*
    auto tong_textures;
    auto wan_textures;
    auto wind_textures;
    auto dragon_textures;
    auto flower_textures;
    */

    /*
     * singular game font as of right now
     * implement font manager in the future if needed
     * i guess this isn't scalable design but it's okay we are iterating quickly
     */
    sf::Font font;
    if (!font.openFromFile(getResourcePath("balatro.ttf"))) {
        std::cerr << "font not loaded\n";
    }
    /*
     * controller
     */
    GameController controller(deck, hand, window, textures);

    Button deal_button({100, 100}, textures.load(getResourcePath("sprites/button.png")), "deal me!", font);
    deal_button.setOnClick([&]() {dealHand(deck, hand, HANDSIZE)});

    /*
     * shuffle deque
     */
    controller.shuffleDeck();

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            controller.handleEvent(event);

            /*
            if (auto* keyEvent = event->getIf<sf::Event::KeyPressed>(); keyEvent && keyEvent->code == sf::Keyboard::Key::Escape) {
                window.close();
            }
            else if (const auto* mouse_press = event->getIf<sf::Event::MouseButtonPressed>()) {
                std::cout << mouse_press->position.x << ' ' << mouse_press->position.y << '\n';
                deal_button.handleEvent(*mouse_press, window);
                if (!deck.empty() && hand.size() < HANDSIZE) {
                    hand.push_back(deck.front());
                    deck.pop_front();

                    float total_width = 0.f;
                    float max_height = 0.f;
                    const float tile_hand_spacing = 10.f;

                    for (auto& tile : hand) {
                        total_width += tile.getWidth() + tile_hand_spacing;
                        max_height = fmax(max_height, tile.getHeight());
                    }
                    total_width -= tile_hand_spacing;

                    std::cout << window.getSize().x << ' ' << window.getSize().y << std::endl;
                    float startX = (window.getSize().x - total_width) / 2.f;
                    float y_pos = (window.getSize().y - max_height - 20.f);
                    float curr_x = startX;
                    for (auto& tile : hand) {
                        tile.setPosition(curr_x, y_pos);
                        curr_x += tile.getWidth() + tile_hand_spacing;
                    }
                }
            }
            */

        }
        controller.render();
    }

    return EXIT_SUCCESS;
}
