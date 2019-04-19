#pragma once

#include "Plane.h"
#include "UI.h"
#include "terrain.h"
#include "Camera.h"

class Scene {
    UI ui;
    Plane plane;
    Camera camera;
    Terrain terrain;

public:

    explicit Scene(RenderWindow& window);

    void update(float deltaTime);
    void render(RenderWindow& window);

private:
    void initScene();
};
