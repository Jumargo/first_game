
#include "Player.h"

Player::Player() : sprite(), velocity(0.f, 0.f), currentTextureIndex(0), animationTimer(0.f) {
    // Cargar texturas para caminar hacia la izquierda
    sf::Texture texture;
    if (texture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\Destroyer\\walk\\left_walk1.png")) {
        leftWalkingTextures.push_back(texture);
    }
    if (texture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\Destroyer\\walk\\left_Walk2.png")) {
        leftWalkingTextures.push_back(texture);
    }

    // Cargar texturas para caminar hacia la derecha
    if (texture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\Destroyer\\walk\\right_walk1.png")) {
        rightWalkingTextures.push_back(texture);
    }
    if (texture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\Destroyer\\walk\\right_walk2.png")) {
        rightWalkingTextures.push_back(texture);
    }
}

void Player::initialize() {
    // Cargar las texturas de caminata
    sf::Texture texture;
    if (texture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\Destroyer\\walk\\right_walk1.png")) {
        rightWalkingTextures.push_back(texture);
    }
    if (texture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\Destroyer\\walk\\right_walk2.png")) {
        rightWalkingTextures.push_back(texture);
    }

    // Establecer la textura inicial del sprite
    if (!rightWalkingTextures.empty()) {
        sprite.setTexture(rightWalkingTextures[0]);
    }

    sprite.setScale(1, 1); // Ajusta el tamaño del sprite
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

    // Actualizar la animación
    if (velocity.x != 0.0f || velocity.y != 0.0f) {
        animationTimer += deltaTime.asSeconds();
        if (animationTimer > 0.09f) {
            // Aquí puedes agregar una lógica similar para las direcciones arriba/abajo si es necesario
            if (velocity.x < 0) { // Movimiento hacia la izquierda
                currentTextureIndex = (currentTextureIndex + 1) % leftWalkingTextures.size();
                sprite.setTexture(leftWalkingTextures[currentTextureIndex]);
            } else if (velocity.x > 0) { // Movimiento hacia la derecha
                currentTextureIndex = (currentTextureIndex + 1) % rightWalkingTextures.size();
                sprite.setTexture(rightWalkingTextures[currentTextureIndex]);
            }
            animationTimer = 0.f;
        }
    } else {
        // Reiniciar la animación a la pose inicial si el personaje no se mueve
        currentTextureIndex = 0;
        sprite.setTexture(rightWalkingTextures[currentTextureIndex]); // O la textura estática correspondiente
    }
    
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
