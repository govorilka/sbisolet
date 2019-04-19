#include "precomp.h"
#include "Plane.h"

Plane* Plane::instance = nullptr;

Plane::Plane() {
    instance = this;
}

void Plane::update(float deltaTime) {

}

void Plane::render(RenderWindow& window) {
    window.draw(sprite);
}

const Vector2f& Plane::getPosition() {
    return sprite.getPosition();
}
