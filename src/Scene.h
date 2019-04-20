#pragma once

#include <Enemies/Enemies.h>
#include "Plane.h"
#include "UI.h"
#include "terrain.h"
#include "Camera.h"
#include "Bonuses.h"

#include "Enemies/Kamikaze.h"
#include "Enemies/Balloon.h"

class Scene {
    UI ui;
    Plane plane;
    Camera camera;
    Terrain terrain;

    Enemies enemies;
    Bonuses bonuses;

    int birds;
    int record;

    Clock time;
    float lastBirdAddTime;

public:
    static Scene* instance;

    explicit Scene(RenderWindow& window);
    
    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
    void onTerrainSegmentCreated(const Segment& segment);

    bool isGameOver();

    float getlastBirdTime();
    void addBirds(int value);
    int getBirds();

    int get_score();

    int getFinalScore();
    int get_hp();
    float get_time();
    int get_record();
    void set_record(int value);
    bool isRocket();
    float get_gas();
    int getFuel();
};
