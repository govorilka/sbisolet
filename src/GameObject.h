#pragma once

#include "precomp.h"

class GameObject {
public:
    virtual ~GameObject() = default;

    virtual void initScene() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(RenderWindow& window) = 0;

    virtual bool isToBeRemoved() = 0;
};
