//
// Created by 1 on 09.11.2021.
//
#include <cstdlib>
#ifndef SNAKE_BUF_H
#define SNAKE_BUF_H
#define FIELD_CELL_TYPE_NONE 0
#define FIELD_CELL_TYPE_HEAD snake.get_length()
#define FIELD_CELL_TYPE_APPLE -1
#define FIELD_CELL_TYPE_SPEEDUP -3
#define FIELD_CELL_TYPE_SPEEDDOWN -4
class Buf{
private:
public:
    int x_position=0;
    int y_position=0;
    int getXPosition() const {
        return x_position;
    }

    void setXPosition(int xPosition) {
        x_position = xPosition;
    }

    int getYPosition() const {
        return y_position;
    }

    void setYPosition(int yPosition) {
        y_position = yPosition;
    }

    virtual int create(int (& field)[35][25],int size_x,int size_y){
        return 0;
    }

};
class Apple:public Buf{
public:
    Apple() {
        this->x_position=start_position+5;
        this->y_position=start_position+5;
    }
    int create(int (& field)[35][25],int size_x,int size_y) override{
        int count_empty_cells=0;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if(field[x][y]==FIELD_CELL_TYPE_NONE){
                    count_empty_cells++;
                }
            }
        }
        int position=rand()%count_empty_cells;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if(field[x][y]==FIELD_CELL_TYPE_NONE){

                    if(position==0){
                        field[x][y]=FIELD_CELL_TYPE_APPLE;
                        return 0;
                    }
                    position--;
                }
            }
        }
        return -1;
    }


private:

};
class SpeedUp:public Buf{
public:
    SpeedUp() {
        this->x_position=start_position-5;
        this->y_position=start_position-14;
    }
    int create(int (& field)[35][25],int size_x,int size_y) override{
        int count_empty_cells=0;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if(field[x][y]==FIELD_CELL_TYPE_NONE){
                    count_empty_cells++;
                }
            }
        }
        int position=rand()%count_empty_cells;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if(field[x][y]==FIELD_CELL_TYPE_NONE){

                    if(position==0){
                        field[x][y]=FIELD_CELL_TYPE_SPEEDUP;
                        return 0;
                    }
                    position--;
                }
            }
        }
        return -1;
    }
};
class SpeedDown:public Buf{
public:
    SpeedDown() {
        this->x_position=start_position+5;
        this->y_position=start_position-11;
    }
    int create(int (& field)[35][25],int size_x,int size_y) override{
        int count_empty_cells=0;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if(field[x][y]==FIELD_CELL_TYPE_NONE){
                    count_empty_cells++;
                }
            }
        }
        int position=rand()%count_empty_cells;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if(field[x][y]==FIELD_CELL_TYPE_NONE){

                    if(position==0){
                        field[x][y]=FIELD_CELL_TYPE_SPEEDDOWN;
                        return 0;
                    }
                    position--;
                }
            }
        }
        return -1;
    }
};

#endif //SNAKE_BUF_H
