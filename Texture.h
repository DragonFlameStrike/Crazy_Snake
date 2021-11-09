//
// Created by 1 on 09.11.2021.
//

#ifndef SNAKE_TEXTURE_H
#define SNAKE_TEXTURE_H

class Texture{
public:
    sf::Texture none_texture;
    sf::Texture body_texture;
    sf::Texture superbody_texture;
    sf::Texture head_texture;
    sf::Texture superhead_texture;
    sf::Texture apple_texture;
    sf::Texture wall_texture;
    sf::Texture game_over_texture;
    sf::Texture pause_texture;
    sf::Texture panel_texture;
    sf::Texture speedup_texture;
    sf::Texture speeddown_texture;
    sf::Font font;

    sf::Sprite none;
    sf::Sprite body;
    sf::Sprite superbody;
    sf::Sprite head;
    sf::Sprite superhead;
    sf::Sprite apple;
    sf::Sprite wall;
    sf::Sprite game_over;
    sf::Sprite pause;
    sf::Sprite panel;
    sf::Sprite speedup;
    sf::Sprite speeddown;
    sf::Text score;
    sf::Text speed;

    Texture(){
        none_texture.loadFromFile("images/none.png");
        body_texture.loadFromFile("images/snake.png");
        superbody_texture.loadFromFile("images/supersnake.png");
        head_texture.loadFromFile("images/head.png");
        superhead_texture.loadFromFile("images/superhead.png");
        wall_texture.loadFromFile("images/wall.png");
        apple_texture.loadFromFile("images/apple.png");
        game_over_texture.loadFromFile("images/game_over.png");
        pause_texture.loadFromFile("images/pause.png");
        panel_texture.loadFromFile("images/panel.png");
        speedup_texture.loadFromFile("images/speedup.png");
        speeddown_texture.loadFromFile("images/speeddown.png");
        font.loadFromFile("fonts/ShockMintFund-YzA8v.ttf");

        none.setTexture(none_texture);
        body.setTexture(body_texture);
        superbody.setTexture(superbody_texture);
        head.setTexture(head_texture);
        superhead.setTexture(superhead_texture);
        wall.setTexture(wall_texture);
        apple.setTexture(apple_texture);
        game_over.setTexture(game_over_texture);
        pause.setTexture(pause_texture);
        panel.setTexture(panel_texture);
        speedup.setTexture(speedup_texture);
        speeddown.setTexture(speeddown_texture);
        score.setFont(font);
        speed.setFont(font);
    }
};

#endif //SNAKE_TEXTURE_H
