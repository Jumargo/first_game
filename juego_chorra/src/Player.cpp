
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

void Player::update(sf::Time deltaTime) {
    // Actualizar la posición del personaje.
    // deltaTime.asSeconds() convierte el tiempo de juego al tiempo en segundos,
    // lo cual es necesario para un movimiento suave y dependiente del tiempo.
    sprite.move(velocity * deltaTime.asSeconds());
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
