#pragma once

class Kamikaze {
    Texture texture;
    Sprite sprite;

    Vector2f velocity;

public:
    Kamikaze();

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
};