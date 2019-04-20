#include "precomp.h"
#include "Balloon.h"
#include "Plane.h"

Balloon::Balloon() {
    if (!texture.loadFromFile("balloonPlaceholder.png")) {
        throw std::runtime_error("Failed to load balloonPlaceholder.png");
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setScale(BALLOON_H_SIZE / texture.getSize().x, -BALLOON_V_SIZE / texture.getSize().y);
    velocity = Vector2f(-BALLOON_H_SPEED, BALLOON_V_SPEED);
}

void Balloon::initScene() {
    sprite.setPosition(300, 0);
    isAlive = true;
}

void Balloon::update(float deltaTime) {
    sprite.setPosition(sprite.getPosition() + velocity * deltaTime);
    if (sprite.getGlobalBounds().intersects(Plane::instance->getGlobalBounds())) {
        Plane::instance->addHP(-BALLOON_DAMAGE);
        isAlive = false;
    }
}

void Balloon::render(RenderWindow &window) {
    window.draw(sprite);
}

bool Balloon::isToBeRemoved() {
    return !isAlive;
}


