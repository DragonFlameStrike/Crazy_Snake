#include <iostream>
#include <SFML/Graphics.hpp>
#include "field.h"

bool game_over;
bool pause;

int main() {
    pause=false;
    game_over=false;
    Field field;
    sf::RenderWindow window(sf::VideoMode(field.get_window_width(), field.get_window_height()), "Snake",
                            sf::Style::Close);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed){
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        if(field.get_snake_direction()!=SNAKE_DIRECTION_DOWN) {
                            field.change_snake_direction(SNAKE_DIRECTION_UP);
                        }
                        break;
                    case sf::Keyboard::Down:
                        if(field.get_snake_direction()!=SNAKE_DIRECTION_UP) {
                            field.change_snake_direction(SNAKE_DIRECTION_DOWN);
                        }
                        break;
                    case sf::Keyboard::Right:
                        if(field.get_snake_direction()!=SNAKE_DIRECTION_LEFT) {
                            field.change_snake_direction(SNAKE_DIRECTION_RIGHT);
                        }
                        break;
                    case sf::Keyboard::Left:
                        if(field.get_snake_direction()!=SNAKE_DIRECTION_RIGHT) {
                            field.change_snake_direction(SNAKE_DIRECTION_LEFT);
                        }
                        break;
                    case sf::Keyboard::Escape:
                        if(pause){ pause=false;}
                        else pause=true;
                        break;

                }
            }
        }
        window.clear(sf::Color(183,212,168));
        if(!game_over) {
            if (!pause) {
                game_over = field.make_event();
            }
        }
        field.draw_field(window,game_over,pause);
        sf::sleep(sf::milliseconds(200));
        window.display();


    }
    return 0;
}