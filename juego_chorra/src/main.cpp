#include "Game.h"

int main() {
    // Obtener la resolución del monitor
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    Game game(desktop.width, desktop.height);
    game.run();

    return 0;
}