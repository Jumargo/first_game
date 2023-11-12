
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void initialize();
    void handleInput();
    void update(sf::Time deltaTime, sf::Vector2u windowSize);
    void render(sf::RenderWindow& window);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
};

#endif // PLAYER_H
