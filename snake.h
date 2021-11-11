//
// Created by 1 on 08.11.2021.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#define start_position 17
#define SNAKE_DIRECTION_UP 270
#define SNAKE_DIRECTION_RIGHT 0
#define SNAKE_DIRECTION_DOWN 90
#define SNAKE_DIRECTION_LEFT 180
class Snake{

private:
    int field_size_y;
    int field_size_x;
    int x_position;
    int y_position;
    int length;
    int direction;
public:

    Snake(){
        field_size_y=25;
        field_size_x=35;
        x_position=start_position;
        y_position=start_position;
        length=5;
        direction=SNAKE_DIRECTION_UP;
    }
    [[nodiscard]] int get_length() const{
        return length;
    }
    [[nodiscard]] int get_x_position() const{
        return x_position;
    }
    [[nodiscard]] int get_y_position() const{
        return y_position;
    }
    [[nodiscard]] int get_direction() const {
        return direction;
    }
    void set_direction(int new_direction) {
        Snake::direction = new_direction;
    }
    void add_length(){
        length++;
    }
    void make_move(){
        switch (direction) {
            case SNAKE_DIRECTION_DOWN:
                if(y_position == field_size_y-1){
                    y_position = 0;
                }
                else{
                    y_position++;
                }
                break;
            case SNAKE_DIRECTION_RIGHT:
                if(x_position == field_size_x-1){
                    x_position = 0;
                }
                else{
                    x_position++;
                }
                break;
            case SNAKE_DIRECTION_UP:
                if(y_position==0){
                    y_position = field_size_y - 1;
                }
                else{
                    y_position--;
                }
                break;
            case SNAKE_DIRECTION_LEFT:
                if(x_position==0){
                    x_position = field_size_x - 1;
                }
                else{
                    x_position--;
                }
                break;
        }

    }
    void die(){
//sounds
    }

    void setXPosition(int xPosition) {
        x_position = xPosition;
    }

    void setYPosition(int yPosition) {
        y_position = yPosition;
    }

    void setLength(int length) {
        Snake::length = length;
    }


};


#endif //SNAKE_SNAKE_H
