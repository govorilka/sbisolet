#pragma once

#include <GameObject.h>
#include "Segment.h"
class Cloud : public GameObject {
    Sprite cloud;

    Vector2f velocity;

    Sprite lightning;
    bool damaged;
    float last_shot_time;
    bool isAlive;
public:
    Cloud(float xPos,float yPos);

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
    void startLightning();
    bool isLightningActive();
    bool isReadyToShoot();
    bool isToBeRemoved();
};