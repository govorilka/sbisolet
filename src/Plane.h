#pragma once

class Plane {
    Sprite sprite;

public:
    static Plane* instance;

    Plane();

    const Vector2f& getPosition();

    void update(float deltaTime);
    void render(RenderWindow& window);
};
