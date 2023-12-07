#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include <array>

class PerlinNoise {
private:
    std::array<int, 512> p;

    float fade(float t) const;
    float lerp(float t, float a, float b) const;
    float grad(int hash, float x, float y, float z) const;

public:
    PerlinNoise();
    float noise(float x, float y, float z) const;
};

#endif // PERLINNOISE_H
