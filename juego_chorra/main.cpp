#include <SFML/Graphics.hpp>

// Funciones declaradas
void initializeTextures(sf::Texture& backgroundTexture, sf::Texture& playerTexture);
void handlePlayerInput(sf::Sprite& playerSprite);
void scaleSpriteToWindowSize(sf::Sprite& sprite, const sf::Texture& texture, const sf::RenderWindow& window);
void centerSprite(sf::Sprite& sprite, const sf::RenderWindow& window);
void handlePlayerMovement(sf::Sprite& playerSprite, const sf::Vector2u& windowSize);


int main() {
    // Configuración de la ventana
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "SFML Game", sf::Style::Fullscreen);

    // Texturas y sprites
    sf::Texture backgroundTexture, playerTexture;
    initializeTextures(backgroundTexture, playerTexture);

    sf::Sprite backgroundSprite(backgroundTexture);
    scaleSpriteToWindowSize(backgroundSprite, backgroundTexture, window);

    sf::Sprite playerSprite(playerTexture);
    playerSprite.setScale(0.1f, 0.1f); // Ajusta el tamaño del sprite del jugador
    centerSprite(playerSprite, window); // Centra el sprite del jugador en la ventana

    // Bucle principal
    while (window.isOpen()) {
        // Manejo de eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Actualizaciones
        handlePlayerMovement(playerSprite, window.getSize());

        // Renderizado
        window.clear();
        window.draw(backgroundSprite); // Dibuja el fondo
        window.draw(playerSprite); // Dibuja el personaje
        window.display();
    }

    return 0;
}

// Funciones definidas

void initializeTextures(sf::Texture& backgroundTexture, sf::Texture& playerTexture) {
    if (!backgroundTexture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\suelo.png")) {
        // manejar error
    }
    if (!playerTexture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\pj.png")) {
        // manejar error
    }
}

void handlePlayerMovement(sf::Sprite& playerSprite, const sf::Vector2u& windowSize) {
    float moveSpeed = 5.0f; // Ajusta la velocidad de movimiento según sea necesario
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        movement.y -= moveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        movement.y += moveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x -= moveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x += moveSpeed;
    }

    // Calcula la nueva posición potencial del jugador
    sf::Vector2f newPosition = playerSprite.getPosition() + movement;

    // Limites del mapa (asumiendo que el origen está en la esquina superior izquierda)
    sf::FloatRect playerBounds = playerSprite.getGlobalBounds();
    float leftBound = 0;
    float rightBound = windowSize.x - playerBounds.width;
    float topBound = 0;
    float bottomBound = windowSize.y - playerBounds.height;

    // Verifica y corrige la posición del jugador si está fuera de los límites
    newPosition.x = std::max(newPosition.x, leftBound);
    newPosition.x = std::min(newPosition.x, rightBound);
    newPosition.y = std::max(newPosition.y, topBound);
    newPosition.y = std::min(newPosition.y, bottomBound);

    // Establece la posición corregida
    playerSprite.setPosition(newPosition);
}

void scaleSpriteToWindowSize(sf::Sprite& sprite, const sf::Texture& texture, const sf::RenderWindow& window) {
    sf::Vector2u textureSize = texture.getSize();
    sf::Vector2u windowSize = window.getSize();

    float scaleX = (float)windowSize.x / textureSize.x;
    float scaleY = (float)windowSize.y / textureSize.y;

    sprite.setScale(scaleX, scaleY);
}

void centerSprite(sf::Sprite& sprite, const sf::RenderWindow& window) {
    sf::Vector2u windowSize = window.getSize();
    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    sprite.setPosition((windowSize.x - spriteBounds.width) / 2.0f, (windowSize.y - spriteBounds.height) / 2.0f);
}