
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
    // Suponiendo que quieras mover al personaje con las teclas del cursor.
    // Establece la velocidad horizontal y vertical a 0 si no se presiona ninguna tecla.
    velocity.x = 0.0f;
    velocity.y = 0.0f;

    // Comprobar las entradas del usuario y ajustar la velocidad en consecuencia.
    // Estos valores se pueden ajustar para cambiar la sensación del movimiento.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x = -200.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x = 200.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocity.y = -200.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velocity.y = 200.0f;
    }
}

void Player::update(sf::Time deltaTime, sf::Vector2u windowSize) {
    sf::Vector2f newPosition = sprite.getPosition() + velocity * deltaTime.asSeconds();

    // Colisiones con los bordes de la ventana
    if (newPosition.x < 0) {
        newPosition.x = 0;
    }
    if (newPosition.y < 0) {
        newPosition.y = 0;
    }
    if (newPosition.x + sprite.getGlobalBounds().width > windowSize.x) {
        newPosition.x = windowSize.x - sprite.getGlobalBounds().width;
    }
    if (newPosition.y + sprite.getGlobalBounds().height > windowSize.y) {
        newPosition.y = windowSize.y - sprite.getGlobalBounds().height;
    }

    sprite.setPosition(newPosition);
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
