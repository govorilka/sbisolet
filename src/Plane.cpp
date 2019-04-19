#include "precomp.h"
#include "Plane.h"

Plane* Plane::instance = nullptr;

Plane::Plane()
    :angle(0),
     hp(INIT_PLANE_HP)
    {
    instance = this;
    if(!texture.loadFromFile("plane.png")) {
        throw std::runtime_error("Failed to load plane.png");
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setScale(PLANE_SIZE / texture.getSize().x, -PLANE_SIZE / texture.getSize().y);
}

void Plane::initScene() {
    velocity = Vector2f(PLANE_H_SPEED, 0);
    setPosition(Vector2f(0, VIEW_SIZE_Y / 2));
    hp = INIT_PLANE_HP;
}

void Plane::update(float deltaTime) {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        setAngle(45);
    } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
        setAngle(-45);
    } else {
        setAngle(0);
    }
    if (getCurrentAngle() != 0) {
        velocity.y = PLANE_V_SPEED * (getCurrentAngle() / 45);
    }
    sprite.rotate(calculateRotation());
    Vector2f newPosition = sprite.getPosition() + velocity * deltaTime;
    newPosition.y = std::max(MIN_PLANE_HEIGHT, newPosition.y);
    newPosition.y = std::min(MAX_PLANE_HEIGHT, newPosition.y);
    setPosition(newPosition);
}

void Plane::render(RenderWindow& window) {
    window.draw(sprite);
}

const Vector2f& Plane::getPosition() {
    return sprite.getPosition();
}

void Plane::setPosition(Vector2f position) {
    sprite.setPosition(position);
}

float Plane::calculateRotation() {
    return (angle - getCurrentAngle()) / 30;
}

float Plane::getCurrentAngle() {
    float curAngle = sprite.getRotation();
    if (curAngle > 180) curAngle -= 360;
    return curAngle;
}

bool Plane::isAlive() {
    return hp > 0;
}

void Plane::addHP(int value) {
    hp += value;
    hp = std::min(hp, INIT_PLANE_HP);
}

int Plane::getHP() {
    return hp;
}

const FloatRect Plane::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void Plane::setAngle(float value) {
    angle = value;
}

