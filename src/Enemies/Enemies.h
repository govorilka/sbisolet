#pragma once

#include <GameObject.h>
#include "Segment.h"

class Enemies {
    std::vector<GameObject*> enemies;
    float lastKamikazeTime = 0;
    float lastBalloonTime = 0;
    float lastCloudTime=0;

public:
    Enemies();

    static Enemies* instance;
    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
    void onTerrainSegmentCreated(const Segment& segment);


};