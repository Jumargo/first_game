
#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"
#include "PerlinNoise.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <vector>

class World {
private:
    sf::RenderWindow& window;
    std::vector<std::vector<Tile>> map;
    sf::Texture aguaTexture, tierraTexture, cespedTexture;
    PerlinNoise perlinNoise;

public:
    World(sf::RenderWindow& window);

    void render();
    void initializeMap(unsigned int width, unsigned int height);
};

#endif // WORLD_H
