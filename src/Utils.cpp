#include "precomp.h"

#include "Utils.h"

std::random_device Utils::generator;

int Utils::getRandomNumber(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(Utils::generator);
}
