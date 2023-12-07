#include "World.h"
#include <random>

World::World(sf::RenderWindow& window) : window(window){}

void World::initializeMap(unsigned int width, unsigned int height) {
    // Cargar texturas
    aguaTexture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\tiles\\agua.png");
    tierraTexture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\tiles\\tierra.png");
    cespedTexture.loadFromFile("C:\\Programacion\\juego_chorra\\img\\tiles\\cesped.png");

    // Calcula el tamaño de los tiles
    float tileWidth = static_cast<float>(width) / 100;
    float tileHeight = static_cast<float>(height) / 100;

    // Inicializa el mapa con los tiles
    map.resize(100, std::vector<Tile>(100, Tile(aguaTexture, AGUA))); // Inicializa con un tipo por defecto
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            // Ajusta estos valores para cambiar la escala y el detalle del ruido
            float noiseValue = perlinNoise.noise(i * 0.05, j * 0.05, 0.0);

            // Mapear el ruido Perlin (aproximadamente de -1 a 1) a un rango de 0 a 1
            noiseValue = (noiseValue + 1) / 2;

            TileType type;
            if (noiseValue < 0.33) {
                type = AGUA;
            } else if (noiseValue < 0.66) {
                type = TIERRA;
            } else {
                type = CESPED;
            }

            map[i][j] = Tile((type == CESPED) ? cespedTexture : (type == TIERRA) ? tierraTexture : aguaTexture, type);
            map[i][j].setPosition(i * tileWidth, j * tileHeight);
            map[i][j].setScale(tileWidth / 32, tileHeight / 32);
        }
    }
}

void World::render() {
    for (auto& row : map) {
        for (auto& tile : row) {
            tile.render(window);
        }
    }
}