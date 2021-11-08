#include <iostream>
#include <SFML/Graphics.hpp>
#include "field.h"
#include "snake.h"
#include <unistd.h>
int main() {
    Field field;
    sf::RenderWindow window(sf::VideoMode(field.get_window_width(), field.get_window_height()), "Snake",
                            sf::Style::Close);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color(183,212,168));
        field.make_event();
        usleep(500000);
        field.draw_field(window);
        window.display();
    }
    return 0;
}