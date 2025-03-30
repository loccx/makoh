#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include <random>

#include "core/game_controller.hpp"
#include "ui/textures.hpp"
#include "ui/fonts.hpp"
#include "ui/tile.hpp"
#include "ui/button.hpp"
#include "utils/enum.hpp"
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
    /*
    auto tong_textures;
    auto wan_textures;
    auto wind_textures;
    auto dragon_textures;
    auto flower_textures;
    */
    Fonts fonts;

    /*
     * controller
     */
    GameController controller(window, textures, fonts);

    /*
     * shuffle deque
     */
    controller.shuffleDeck();

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (event->is<sf::Event::KeyPressed>()) {
                if (auto keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyEvent->code == sf::Keyboard::Key::Escape) {
                        window.close();
                    }
                }
            }

            controller.handleEvent(*event);
        }

        // controller.update();
        controller.render();
    }

    return EXIT_SUCCESS;
}
