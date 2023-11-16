
#include "Player.h"

Player::Player() : sprite(), velocity(0.f, 0.f), currentTextureIndex(0), animationTimer(0.f) {
    // Cargar texturas y configurar sprite aquí
}

void Player::initialize() {
    // Cargar las texturas de caminata
    sf::Texture texture;
    if (texture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\Destroyer\\walk\\Walk1.png")) {
        walkingTextures.push_back(texture);
    }
    if (texture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\Destroyer\\walk\\Walk2.png")) {
        walkingTextures.push_back(texture);
    }

    // Establecer la textura inicial del sprite
    if (!walkingTextures.empty()) {
        sprite.setTexture(walkingTextures[0]);
    }

    sprite.setScale(3, 3); // Ajusta el tamaño del sprite
    // Posición inicial del personaje en el centro se manejará en Game.cpp
}

void Player::handleInput() {
    // Suponiendo que quieras mover al personaje con las teclas del cursor.
    // Establece la velocidad horizontal y vertical a 0 si no se presiona ninguna tecla.
    velocity.x = 0.0f;
    velocity.y = 0.0f;

    // Comprobar las entradas del usuario y ajustar la velocidad en consecuencia.
    // Estos valores se pueden ajustar para cambiar la sensación del movimiento.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x = -200.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x = 200.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        velocity.y = -200.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
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

    // Actualizar la animación solo si el personaje se está moviendo
    if (velocity.x != 0.0f || velocity.y != 0.0f) {
        animationTimer += deltaTime.asSeconds();
        if (animationTimer > 0.2f) {  // Cambiar la textura cada 0.2 segundos
            currentTextureIndex = (currentTextureIndex + 1) % walkingTextures.size();
            sprite.setTexture(walkingTextures[currentTextureIndex]);
            animationTimer = 0.f;
        }
    } else {
        // Si el personaje no se mueve, reiniciar la animación a la pose inicial
        currentTextureIndex = 0; // o cualquier índice que represente la pose estática
        sprite.setTexture(walkingTextures[currentTextureIndex]);
    }
    
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
