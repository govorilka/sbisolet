#pragma once

#include "precomp.h"

class Plane {
    Sprite sprite;
    Vector2f velocity;
    Texture texture;

    int hp;
    float angle;

    float fuel;
    float godModeTimeLeft;

public:
    static Plane* instance;

    Plane();

    const Vector2f& getPosition();

    bool isAlive();
    void addHP(int value);
    int getHP();

    float getFuel();
    void addFuel(float seconds);

    void addGodModeTime(float value);

    const FloatRect getGlobalBounds();

    void setAngle(float value);

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);

private:
    void setPosition(Vector2f position);

    float getCurrentAngle();
    float calculateRotation();
};
