#pragma once

class Plane {
    Sprite sprite;
    Vector2f velocity;
    Texture texture;

    int hp;
    float angle;
public:
    static Plane* instance;

    Plane();

    const Vector2f& getPosition();

    bool isAlive();
    void addHP(int value);
    int getHP();

    const FloatRect getGlobalBounds();

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);

private:
    void setPosition(Vector2f position);

    float getCurrentAngle();
    float calculateRotation();

    void setAngle(float value);
};
