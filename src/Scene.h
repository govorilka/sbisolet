#pragma once

#include "Plane.h"
#include "UI.h"
#include "terrain.h"
#include "Camera.h"

class Scene {
    UI ui;
    Plane plane;
    Terrain terrain;
    Camera camera;

public:
    void update(float deltaTime);
    void render(RenderWindow& window);
};
