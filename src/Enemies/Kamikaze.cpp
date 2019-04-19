#include "precomp.h"
#include "Kamikaze.h"
#include "Plane.h"

Kamikaze::Kamikaze() {
    texture.loadFromFile("kamikazePlaceholder.png");
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setScale(KAMIKAZE_SIZE / texture.getSize().x, -KAMIKAZE_SIZE / texture.getSize().y);
    velocity = Vector2f(-KAMIKAZE_H_SPEED, 0);
}

void Kamikaze::initScene() {
    sprite.setPosition(200, 50);
}

void Kamikaze::update(float deltaTime) {
    Vector2f planePosition = Plane::instance->getPosition();
    Vector2f deltaPosition = sprite.getPosition() - planePosition;
    float curAngle = 0;
    if (deltaPosition.x > 0) {
        curAngle = std::atan(-deltaPosition.y / deltaPosition.x) * 180 / 3.1415;
        curAngle = std::min(curAngle, 45.f);
        curAngle = std::max(curAngle, -45.f);
    }
    velocity.y = KAMIKAZE_V_SPEED * curAngle / 45;
    sprite.setPosition(sprite.getPosition() + velocity * deltaTime);
    if (sprite.getGlobalBounds().intersects(Plane::instance->getGlobalBounds())) {
        Plane::instance->addHP(-KAMIKAZE_DAMAGE);
        sprite.setPosition(-100, -100);
    }
}

void Kamikaze::render(RenderWindow &window) {
    window.draw(sprite);
}
