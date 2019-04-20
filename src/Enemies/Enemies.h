#pragma once

#include <GameObject.h>

class Enemies {
    std::vector<GameObject*> enemies;

public:
    Enemies();

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
};