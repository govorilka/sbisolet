#pragma once

#include "Plane.h"

class Scene {
    Plane plane;

public:
    void update(float deltaTime);
    void render(RenderWindow& window);
};
