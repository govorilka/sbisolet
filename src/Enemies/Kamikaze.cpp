#include "precomp.h"
#include "Kamikaze.h"
#include "Plane.h"
#include "Scene.h"
Kamikaze::Kamikaze(float xPos, float yPos) : isAlive(true) {
    sprite.setTexture(Scene::instance->getEffectsTexture());
    sprite.setTextureRect(IntRect(256*1,256*1,256,256));
    sprite.setOrigin(128, 128);

    sprite.setScale(ENEMIES_KAMIKAZE_SIZE / 256, -ENEMIES_KAMIKAZE_SIZE / 256);
    velocity = Vector2f(-ENEMIES_KAMIKAZE_H_SPEED, 0);
    sprite.setPosition(xPos, yPos);

}

void Kamikaze::initScene() {
    isAlive = true;
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
    velocity.y = ENEMIES_KAMIKAZE_V_SPEED * curAngle / 45;
    sprite.setPosition(sprite.getPosition() + velocity * deltaTime);
    if (sprite.getGlobalBounds().intersects(Plane::instance->getGlobalBounds())) {
        Plane::instance->addHP(-ENEMIES_KAMIKAZE_DAMAGE);
        isAlive = false;
    }
    if (sprite.getPosition().x < -10) {
        isAlive = false;
    }
}

void Kamikaze::render(RenderWindow &window) {
    window.draw(sprite);
}

bool Kamikaze::isToBeRemoved() {
    return !isAlive;
}
