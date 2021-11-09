//
// Created by 1 on 09.11.2021.
//

#ifndef SNAKE_TEXTURE_H
#define SNAKE_TEXTURE_H

class Texture{
public:
    sf::Texture none_texture;
    sf::Texture body_texture;
    sf::Texture head_texture;
    sf::Texture apple_texture;
    sf::Texture wall_texture;
    sf::Texture game_over_texture;
    sf::Texture pause_texture;

    sf::Sprite none;
    sf::Sprite body;
    sf::Sprite head;
    sf::Sprite apple;
    sf::Sprite wall;
    sf::Sprite game_over;
    sf::Sprite pause;

    Texture(){
        none_texture.loadFromFile("images/none.png");
        body_texture.loadFromFile("images/snake.png");
        head_texture.loadFromFile("images/head.png");
        wall_texture.loadFromFile("images/wall.png");
        apple_texture.loadFromFile("images/apple.png");
        game_over_texture.loadFromFile("images/game_over.png");
        pause_texture.loadFromFile("images/pause.png");

        none.setTexture(none_texture);
        body.setTexture(body_texture);
        head.setTexture(head_texture);
        wall.setTexture(wall_texture);
        apple.setTexture(apple_texture);
        game_over.setTexture(game_over_texture);
        pause.setTexture(pause_texture);
    }
};

#endif //SNAKE_TEXTURE_H
