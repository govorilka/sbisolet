#pragma once

#include <random>

class Utils {
    static std::random_device generator;

public:
    static int getRandomNumber(int min, int max);

    static bool isInRange(int value, int min, int max);
};
