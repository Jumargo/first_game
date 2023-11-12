
#include "World.h"

World::World(sf::RenderWindow& window) : window(window) {
    // Constructor
}

void World::initialize() {
    if (!backgroundTexture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\suelo.png")) {
        // manejar error
    }
    backgroundSprite.setTexture(backgroundTexture);
    // El escalado del fondo se maneja aquí ahora
}

void World::update(sf::Time deltaTime) {
    // Actualizar la lógica del mundo
    // Puede incluir animaciones del fondo o cambios ambientales
}

void World::render() {
    window.draw(backgroundSprite);
}
