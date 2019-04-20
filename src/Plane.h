#pragma once

#include <list>
#include "Circle.h"


class Plane {
    Sprite sprite;
    Sprite godMode;

    Vector2f velocity;

    Texture texture;

    Texture fuelTexture;
    std::list<Sprite> fuelSprites;

    float fuelCooldown;

    int hp;
    float angle;

    float fuel;
    float godModeTimeLeft;

    bool isKeyboard;


public:
    static Plane* instance;

    Plane();

    const Vector2f& getPosition();

    bool isAlive();
    void addHP(int value);
    int getHP();

    float getFuel();

    void addFuel(float fuel);

    void addGodModeTime(float value);

    const FloatRect getGlobalBounds();
    void setAngle(float value, bool force = false);
    Circle getGlobalBoundingCircle();
    void setControlMode(bool isKeyboardMode);

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);

    float lostControlTime;

    bool isGodMode();

private:

    void setPosition(Vector2f position);

    float getCurrentAngle();
    float calculateRotation();

    void updateFuelSprites(float deltaTime);

    Circle getBCircleFromSprite(Sprite sprite);
};
