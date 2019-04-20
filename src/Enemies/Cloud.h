#pragma once

#include <GameObject.h>
#include "Segment.h"
class Cloud : public GameObject {
    Sprite cloud;

    Sprite lightning;
    bool isPushed;
    bool damaged;
    bool isAlive;
    float last_shot_time;
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