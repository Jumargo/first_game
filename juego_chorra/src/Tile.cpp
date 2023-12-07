#include "Tile.h"

Tile::Tile(sf::Texture& texture, TileType type) : type(type) {
    sprite.setTexture(texture);
}

void Tile::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Tile::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Tile::setScale(float scaleX, float scaleY) {
    sprite.setScale(scaleX, scaleY);
}
