
#include "Player.h"

Player::Player() : sprite(), velocity(0.f, 0.f) {
    // Cargar textura y configurar sprite aquí
}

void Player::initialize() {
    if (!texture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\pj.png")) {
        // manejar error
    }
    sprite.setTexture(texture);
    sprite.setScale(0.1f, 0.1f); // Ajusta el tamaño del sprite a la mitad
    // Posición inicial del personaje en el centro se manejará en Game.cpp
}

void Player::handleInput() {
    // Manejo de la entrada del jugador
    // Este código se traslada de main.cpp a aquí
}

void Player::update(sf::Time deltaTime) {
    // Actualizar la lógica del jugador
    // Incluirá el movimiento y la detección de colisiones
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
