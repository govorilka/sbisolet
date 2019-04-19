#pragma once

class Camera {

public:
    void update(float deltaTime);
    void render(RenderWindow& window);
};