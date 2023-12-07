#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum TileType { AGUA, TIERRA, CESPED };

class Tile {
private:
    sf::Sprite sprite;
    TileType type;

public:
    Tile(sf::Texture& texture, TileType type);

    void render(sf::RenderWindow& window);
    void setPosition(float x, float y);
    void setScale(float scaleX, float scaleY);
};

#endif // TILE_H
