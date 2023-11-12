
#include "World.h"

World::World(sf::RenderWindow& window) : window(window) {
    // Constructor
}

void World::initialize(unsigned int width, unsigned int height) {
    if (!backgroundTexture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\suelo.png")) {
        // manejar error
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Escalar el sprite para que se ajuste a la resolución del monitor
    float scaleX = static_cast<float>(width) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(height) / backgroundTexture.getSize().y;
    backgroundSprite.setScale(scaleX, scaleY);
}

void World::update(sf::Time deltaTime) {
    // Actualizar la lógica del mundo
    // Puede incluir animaciones del fondo o cambios ambientales
}

void World::render() {
    window.draw(backgroundSprite);
}
