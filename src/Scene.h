#pragma once

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
    Kamikaze kamikaze;
    Balloon balloon;

public:
    static Scene* instance;

    explicit Scene(RenderWindow& window);
    
    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);

    bool isGameOver();

    int get_hp();
    float get_time();
    int get_score();
    int get_record();
    void set_record(int value);
};
