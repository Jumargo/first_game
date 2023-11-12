
#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML Game"), player(), world(window) {
    // Inicialización de miembros y recursos
    player.initialize();
    world.initialize();
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
    player.update(deltaTime); // Actualizar jugador
    world.update(deltaTime); // Actualizar mundo
}

void Game::render() {
    window.clear();
    world.render(); // Primero renderizamos el mundo
    player.render(window); // Luego el jugador
    window.display();
}
