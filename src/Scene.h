#pragma once

#include <Enemies/Enemies.h>
#include "Plane.h"
#include "UI.h"
#include "terrain.h"
#include "Camera.h"
#include "Enemies/Kamikaze.h"
#include "Enemies/Balloon.h"

class Scene {
    UI ui;
    Plane plane;
    Camera camera;
    Terrain terrain;
    Enemies enemies;

    int score;
    int record;

public:
    static Scene* instance;

    explicit Scene(RenderWindow& window);
    
    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);

    bool isGameOver();

    void addScore(int value);

    int get_hp();
    float get_time();
    int get_score();
    int get_record();
    void set_record(int value);
};
