#include "Game.h"

Game::Game(unsigned int width, unsigned int height) 
    : window(sf::VideoMode(width, height), "SFML Game"), player(), world(window) {
    // Inicialización de miembros y recursos
    player.initialize();
    world.initializeMap(width, height); // Pasar el tamaño de la ventana al mundo
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        processEvents();
        update(clock.restart());
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    player.handleInput(); // Ahora el jugador maneja la entrada
}

void Game::update(sf::Time deltaTime) {
    player.update(deltaTime, window.getSize());
}

void Game::render() {
    window.clear();
    world.render(); // Primero renderizamos el mundo
    player.render(window); // Luego el jugador
    window.display();
}
