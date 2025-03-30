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
    sf::err().rdbuf(std::cerr.rdbuf());

    Textures textures;
    Fonts fonts;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "makoh", sf::Style::Default, sf::State::Fullscreen);
    /*
     * controller
     */
    GameController controller(window, textures, fonts);

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                textures.clear();
                fonts.clear();
                window.close();
            }
            else if (event->is<sf::Event::KeyPressed>()) {
                if (auto keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyEvent->code == sf::Keyboard::Key::Escape) {
                        textures.clear();
                        fonts.clear();
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
