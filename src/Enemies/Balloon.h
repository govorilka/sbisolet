#pragma once

#include <GameObject.h>

class Balloon : public GameObject {
    Texture texture;
    Sprite sprite;

    Vector2f velocity;

    bool isAlive;

public:
    Balloon();

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);

    bool isToBeRemoved();
};