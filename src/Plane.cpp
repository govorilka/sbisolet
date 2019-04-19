#include "precomp.h"
#include <algorithm>
#include "Plane.h"

Plane* Plane::instance = nullptr;

Plane::Plane() {
    instance = this;
    initScene();
}

void Plane::initScene() {
    velocity = Vector2f(PLANE_H_SPEED, 0);
    setPosition(Vector2f(0, VIEW_SIZE_Y / 2));
}

void Plane::update(float deltaTime) {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        velocity.y = PLANE_V_SPEED * deltaTime;
    } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
        velocity.y = -PLANE_V_SPEED * deltaTime;
    } else {
        velocity.y = 0;
    }
    Vector2f newPosition = sprite.getPosition() + velocity;
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
