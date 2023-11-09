#include <SFML/Graphics.hpp>

// Funciones declaradas
void initializeTextures(sf::Texture& backgroundTexture, sf::Texture& playerTexture);
void handlePlayerInput(sf::Sprite& playerSprite);
void scaleSpriteToWindowSize(sf::Sprite& sprite, const sf::Texture& texture, const sf::RenderWindow& window);
void centerSprite(sf::Sprite& sprite, const sf::RenderWindow& window);


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
        handlePlayerInput(playerSprite);

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

void handlePlayerInput(sf::Sprite& playerSprite) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        playerSprite.move(0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        playerSprite.move(0.f, 1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        playerSprite.move(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        playerSprite.move(1.f, 0.f);
    }
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