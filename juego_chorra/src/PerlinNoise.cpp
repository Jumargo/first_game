#include "PerlinNoise.h"
#include <cmath>
#include <numeric>
#include <algorithm>
#include <random>

PerlinNoise::PerlinNoise() {
    // Llenar el arreglo p con valores de 0 a 255
    std::iota(p.begin(), p.begin() + 256, 0);

    // Embarajar los valores
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(p.begin(), p.begin() + 256, g);

    // Duplicar los valores de 256 a 511
    for (int i = 0; i < 256; ++i) {
        p[256 + i] = p[i];
    }
}

float PerlinNoise::fade(float t) const {
    // Implementación de la función fade
    return t * t * t * (t * (t * 6 - 15) + 10);
}

float PerlinNoise::lerp(float t, float a, float b) const {
    // Implementación de la función lerp
    return a + t * (b - a);
}

float PerlinNoise::grad(int hash, float x, float y, float z) const {
    // Implementación de la función grad
    int h = hash & 15;
    float u = h < 8 ? x : y;
    float v = h < 4 ? y : h == 12 || h == 14 ? x : z;
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

float PerlinNoise::noise(float x, float y, float z) const {
    // Calcula las coordenadas de la celda que contiene el punto
    int X = static_cast<int>(floor(x)) & 255;
    int Y = static_cast<int>(floor(y)) & 255;
    int Z = static_cast<int>(floor(z)) & 255;

    // Encuentra las coordenadas relativas del punto dentro de la celda
    x -= floor(x);
    y -= floor(y);
    z -= floor(z);

    // Calcula los factores de suavizado para cada coordenada
    float u = fade(x);
    float v = fade(y);
    float w = fade(z);

    // Hash coordinates of the 8 cube corners
    int A = p[X] + Y;
    int AA = p[A] + Z;
    int AB = p[A + 1] + Z;
    int B = p[X + 1] + Y;
    int BA = p[B] + Z;
    int BB = p[B + 1] + Z;

    // Agrega las contribuciones de cada esquina para obtener el valor final de ruido
    float res = lerp(w, lerp(v, lerp(u, grad(p[AA], x, y, z),
                                     grad(p[BA], x - 1, y, z)),
                            lerp(u, grad(p[AB], x, y - 1, z),
                                     grad(p[BB], x - 1, y - 1, z))),
                    lerp(v, lerp(u, grad(p[AA + 1], x, y, z - 1),
                                     grad(p[BA + 1], x - 1, y, z - 1)),
                            lerp(u, grad(p[AB + 1], x, y - 1, z - 1),
                                     grad(p[BB + 1], x - 1, y - 1, z - 1))));

    return res;
}
