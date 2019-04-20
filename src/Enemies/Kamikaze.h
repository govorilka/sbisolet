#pragma once

#include <GameObject.h>

class Kamikaze : public GameObject {
    Texture texture;
    Sprite sprite;

    Vector2f velocity;

    bool isAlive;

public:
    Kamikaze(float xPos, float yPos);

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);

    bool isToBeRemoved();
};