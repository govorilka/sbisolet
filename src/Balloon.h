#pragma once

class Balloon {
    Texture texture;
    Sprite sprite;

    Vector2f velocity;

public:
    Balloon();

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
};