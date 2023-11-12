#include "Game.h"

// int main() {
//     Game game;
//     game.run();
//     return 0;
// }

int main() {
    // Obtener la resolución del monitor
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    Game game(desktop.width, desktop.height);
    game.run();

    return 0;
}