#include <iostream>
#include <SFML/Graphics.hpp>
#include "field.h"

bool game_over;
bool pause;
int game_speed=200;

int main() {
    pause=false;
    game_over=false;
    Field field;
    sf::RenderWindow window(sf::VideoMode(field.get_window_width(), field.get_window_height() + 32*2), "Snake",
                            sf::Style::Close);
    int new_snake_direction=field.get_snake_direction();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed){
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        if(field.get_snake_direction()!=SNAKE_DIRECTION_DOWN) {
                            new_snake_direction=SNAKE_DIRECTION_UP;
                        }
                        break;
                    case sf::Keyboard::Down:
                        if(field.get_snake_direction()!=SNAKE_DIRECTION_UP) {
                            new_snake_direction=SNAKE_DIRECTION_DOWN;
                        }
                        break;
                    case sf::Keyboard::Right:
                        if(field.get_snake_direction()!=SNAKE_DIRECTION_LEFT) {
                            new_snake_direction=SNAKE_DIRECTION_RIGHT;
                        }
                        break;
                    case sf::Keyboard::Left:
                        if(field.get_snake_direction()!=SNAKE_DIRECTION_RIGHT) {
                            new_snake_direction=SNAKE_DIRECTION_LEFT;
                        }
                        break;
                    case sf::Keyboard::Escape:
                        if(!game_over) {
                            if (pause) { pause = false; }
                            else pause = true;
                        }
                        break;

                }
            }
        }
        window.clear(sf::Color(250,212,199));//183 212 168
        if(!game_over) {
            if (!pause) {
                field.change_snake_direction(new_snake_direction);
                game_over = field.make_event(game_speed);
            }
        }
        field.draw_field(window,game_over,pause,game_speed);
        sf::sleep(sf::milliseconds(game_speed));
        window.display();



    }
    return 0;
}