//
// Created by 1 on 08.11.2021.
//
#include "snake.h"
#include "Texture.h"
#include "buf.h"
#ifndef SNAKE_FIELD_H
#define SNAKE_FIELD_H
#define FIELD_CELL_TYPE_NONE 0
#define FIELD_CELL_TYPE_HEAD snake.get_length()
#define FIELD_CELL_TYPE_APPLE -1
#define FIELD_CELL_TYPE_WALL -2
class Field {
private:
    const int size_x = 35;
    const int size_y = 25;
    const int cell_size = 32;
    int window_width;
    int window_height;
    int field[35][25]{};
    Snake snake;
    Texture texture;
    Apple apple;

    void create_walls(){
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if((x==0||x==34) && y!=11 && y!=12 && y!=13 ) {
                    field[x][y] = FIELD_CELL_TYPE_WALL;
                }
                if((y==0||y==24) && x!=16 && x!=17 && x!=18 ){
                    field[x][y] = FIELD_CELL_TYPE_WALL;
                }
            }
        }
    }

public:

    Field() {
        window_width = cell_size * size_x;
        window_height = cell_size * size_y;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                field[x][y] = FIELD_CELL_TYPE_NONE;
            }
        }
        create_walls();
        for (int i = 0; i < snake.get_length(); i++) {
            field[snake.get_x_position()][snake.get_y_position() + i] = FIELD_CELL_TYPE_HEAD - i;
        }
        field[apple.getXPosition()][apple.getYPosition()]=FIELD_CELL_TYPE_APPLE;


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

    void draw_field(sf::RenderWindow &window,bool game_over,bool pause) {


        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                switch (field[x][y]) {
                    case FIELD_CELL_TYPE_NONE:
                        texture.none.setPosition(float(x * cell_size), float(y * cell_size));
                        window.draw(texture.none);
                        break;
                    case FIELD_CELL_TYPE_APPLE:
                        texture.apple.setPosition(float(x * cell_size), float(y * cell_size));
                        window.draw(texture.apple);
                        break;
                    case FIELD_CELL_TYPE_WALL:
                        texture.wall.setPosition(float(x * cell_size), float(y * cell_size));
                        window.draw(texture.wall);
                        break;
                    default:
                        if (field[x][y] == snake.get_length()) {
                            float offset_x = texture.head.getLocalBounds().width / 2;
                            float offset_y = texture.head.getLocalBounds().height / 2;
                            texture.head.setPosition(float(x * cell_size + offset_x), float(y * cell_size + offset_y));
                            texture.head.setOrigin(offset_x, offset_y);
                            switch (snake.get_direction()) {
                                case SNAKE_DIRECTION_UP:
                                    texture.head.setRotation(0);
                                    break;
                                case SNAKE_DIRECTION_RIGHT:
                                    texture.head.setRotation(90);
                                    break;
                                case SNAKE_DIRECTION_DOWN:
                                    texture.head.setRotation(180);
                                    break;
                                case SNAKE_DIRECTION_LEFT:
                                    texture.head.setRotation(-90);
                                    break;
                            }
                            window.draw(texture.head);
                        } else {
                            texture.body.setPosition(float(x * cell_size), float(y * cell_size));
                            window.draw(texture.body);
                        }

                }
            }
        }
        if(game_over){
            texture.game_over.setPosition(float(480), float(0));
            window.draw(texture.game_over);
        }
        if(pause){
            texture.pause.setPosition(float(480), float(0));
            window.draw(texture.pause);
        }
    }
    void grow_snake()
    {
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if (field[x][y] > FIELD_CELL_TYPE_NONE) {
                    field[x][y]++;
                }
            }
        }
    }
    bool make_event(){ //if true - game_over
        snake.make_move(); //change head position
        if (field[snake.get_x_position()][snake.get_y_position()] != FIELD_CELL_TYPE_NONE) {
            switch (field[snake.get_x_position()][snake.get_y_position()]) {
                case FIELD_CELL_TYPE_APPLE:
                    //sound_ate_apple.play();
                    snake.add_length();
                    grow_snake();
                    apple.create(field,size_x,size_y);
                    break;
                case FIELD_CELL_TYPE_WALL:
                    //sound_died_against_the_wall.play();
                    snake.die();
                    return true;
                    break;
                default:
                    if (field[snake.get_x_position()][snake.get_y_position()] > 1) {
                        //sound_ate_himself.play();
                        snake.die();
                        return true;
                    }
            }
        }
        field[snake.get_x_position()][snake.get_y_position()]=snake.get_length() +1;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if(field[x][y]>FIELD_CELL_TYPE_NONE){
                    field[x][y]--;
                }
            }
        }
        return false;
    };
    void change_snake_direction(int new_direction){
        snake.set_direction(new_direction);
    }
    int get_snake_direction(){
        return snake.get_direction();
    }
};


#endif //SNAKE_FIELD_H
