#include "precomp.h"
#include <algorithm>
#include "Plane.h"

Plane* Plane::instance = nullptr;

Plane::Plane() {
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
}

void Plane::update(float deltaTime) {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        velocity.y = PLANE_V_SPEED;
    } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
        velocity.y = -PLANE_V_SPEED;
    } else {
        velocity.y = 0;
    }
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
