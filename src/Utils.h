#pragma once

class Utils {
    static std::random_device generator;

public:
    static int getRandomNumber(int min, int max);
};