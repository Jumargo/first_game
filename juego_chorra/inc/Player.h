
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void initialize();
    void handleInput();
    void update(sf::Time deltaTime, sf::Vector2u windowSize);
    void render(sf::RenderWindow& window);

private:
    std::vector<sf::Texture> walkingTextures;  // Vector para almacenar texturas de caminata
    sf::Sprite sprite;
    sf::Vector2f velocity;
    int currentTextureIndex;  // Índice para la textura actual en la animación
    float animationTimer;     // Temporizador para controlar la velocidad de la animación
};

#endif // PLAYER_H
