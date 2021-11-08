//
// Created by 1 on 08.11.2021.
//
#include "snake.h"
#ifndef SNAKE_FIELD_H
#define SNAKE_FIELD_H
#define FIELD_CELL_TYPE_NONE 0
#define FIELD_CELL_TYPE_HEAD snake.get_length()
class Field {
private:
    const int size_x = 35;
    const int size_y = 25;
    const int cell_size = 32;
    int window_width;
    int window_height;
    int field[35][25]{};
    Snake snake;
public:
    Field() {
        window_width = cell_size * size_x;
        window_height = cell_size * size_y;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                field[x][y] = FIELD_CELL_TYPE_NONE;
            }
        }
        for (int i = 0; i < snake.get_length(); i++) {
            field[snake.get_x_position()][snake.get_y_position() + i] = FIELD_CELL_TYPE_HEAD - i;
        }

    }

    ~Field() = default;

    void clear_field() {
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {

                field[x][y] = FIELD_CELL_TYPE_NONE;
            }
        }
    }

    int get_window_width() const {
        return window_width;
    }

    int get_window_height() const {
        return window_height;
    }

    void draw_field(sf::RenderWindow &window) {
        sf::Texture none_texture;
        sf::Texture body_texture;
        sf::Texture head_texture;
        none_texture.loadFromFile(R"(D:\CLion_2021.2.1\MyProjects\snake\cmake-build-debug\images\none.png)");
        body_texture.loadFromFile(R"(D:\CLion_2021.2.1\MyProjects\snake\cmake-build-debug\images\snake.png)");
        head_texture.loadFromFile(R"(D:\CLion_2021.2.1\MyProjects\snake\cmake-build-debug\images\head.png)");
        sf::Sprite none;
        sf::Sprite body;
        sf::Sprite head;
        none.setTexture(none_texture);
        body.setTexture(body_texture);
        head.setTexture(head_texture);

        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                switch (field[x][y]) {
                    case FIELD_CELL_TYPE_NONE:
                        none.setPosition(float(x * cell_size), float(y * cell_size));
                        window.draw(none);
                        break;
                    default:
                        if (field[x][y] == snake.get_length()) {
                            float offset_x = head.getLocalBounds().width / 2;
                            float offset_y = head.getLocalBounds().height / 2;
                            head.setPosition(float(x * cell_size + offset_x), float(y * cell_size + offset_y));
                            head.setOrigin(offset_x, offset_y);
                            switch (snake.getDirection()) {
                                case SNAKE_DIRECTION_UP:
                                    head.setRotation(0);
                                    break;
                                case SNAKE_DIRECTION_RIGHT:
                                    head.setRotation(90);
                                    break;
                                case SNAKE_DIRECTION_DOWN:
                                    head.setRotation(180);
                                    break;
                                case SNAKE_DIRECTION_LEFT:
                                    head.setRotation(-90);
                                    break;
                            }
                            window.draw(head);
                        } else {
                            body.setPosition(float(x * cell_size), float(y * cell_size));
                            window.draw(body);
                        }

                }
            }
        }
    }
    void make_event(){
        snake.make_move();
        field[snake.get_x_position()][snake.get_y_position()]=snake.get_length() +1;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if(field[x][y]>FIELD_CELL_TYPE_NONE){
                    field[x][y]--;
                }
            }
        }
    };
};


#endif //SNAKE_FIELD_H
