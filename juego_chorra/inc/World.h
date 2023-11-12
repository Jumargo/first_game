
#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

class World {
public:
    World(sf::RenderWindow& window);
    void initialize(unsigned int width, unsigned int height);
    void update(sf::Time deltaTime);
    void render();

private:
    sf::RenderWindow& window;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    // Otros miembros privados
};

#endif // WORLD_H
