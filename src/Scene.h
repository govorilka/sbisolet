#pragma once

#include "Plane.h"
#include "UI.h"
#include "terrain.h"

class Scene {
    UI ui;
    Plane plane;
    Terrain terrain;

public:
    void update(float deltaTime);
    void render(RenderWindow& window);
};
