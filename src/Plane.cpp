#include "precomp.h"
#include "Plane.h"
#include "terrain.h"

Plane* Plane::instance = nullptr;

Plane::Plane()
    :angle(0),
     hp(INIT_PLANE_HP),
     fuel(MAX_FUEL),
     godModeTimeLeft(0),
     lostControlTime(0),
     isKeyboard(true)
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
    fuel = MAX_FUEL;
}

void Plane::update(float deltaTime) {
    if (godModeTimeLeft > 0) godModeTimeLeft -= deltaTime;
    if (lostControlTime > 0) lostControlTime -= deltaTime;
    float fuel_dec = 0;
    if (isKeyboard) {
        if (Keyboard::isKeyPressed(Keyboard::Up) && fuel > 0 && getPosition().y < MAX_PLANE_HEIGHT - 2.5) {
            fuel_dec = FUEL_DEC_UP;
            setAngle(45);
        } else if (Keyboard::isKeyPressed(Keyboard::Down) || fuel == 0) {
            setAngle(-45);
        } else if (fuel > 0) {
            fuel_dec = FUEL_DEC;
            setAngle(0);
        }
    } else {
        if (angle > 0) {
            fuel_dec = FUEL_DEC_UP;
        } else if (std::abs(angle) < ANGLE_DELTA) {
            fuel_dec = FUEL_DEC;
            angle = 0;
        }
    }
    if (hp == 1) {
        fuel_dec *= ONE_HP_MUL;
    }
    if (getCurrentAngle() != 0) {
        velocity.y = PLANE_V_SPEED * (getCurrentAngle() / 45);
    }
    if (fuel > 0) {
        fuel -= fuel_dec * deltaTime;
        if (fuel < 0) {
            fuel = 0;
        }
    }
    sprite.rotate(calculateRotation());
    Vector2f newPosition = sprite.getPosition() + velocity * deltaTime;
    newPosition.y = std::max(MIN_PLANE_HEIGHT, newPosition.y);
    newPosition.y = std::min(MAX_PLANE_HEIGHT, newPosition.y);
    setPosition(newPosition);
    /*if(Terrain::instance->isIntersects(getGlobalBoundingCircle())){
        hp = 0;
    }*/
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
    if (godModeTimeLeft > 0 && value < 0) return;
    hp += value;
    hp = std::min(hp, INIT_PLANE_HP);
}

int Plane::getHP() {
    return hp;
}

const FloatRect Plane::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void Plane::setAngle(float value, bool force) {

    if (!isKeyboard && !force) {
        if (fuel > 0 && getPosition().y > MAX_PLANE_HEIGHT - 2.5 && value > 0) {
            value = 0;
        }
        if (fuel == 0) {
            value = -45;
        }
    }
    angle = value;
}

void Plane::addGodModeTime(float seconds) {
    godModeTimeLeft += seconds;
}

float Plane::getFuel() {
    return fuel;
}

void Plane::addFuel(float value) {
    fuel += value;
}

void Plane::setControlMode(bool isKeyboardMode) {
    isKeyboard = isKeyboardMode;
}

Circle Plane::getGlobalBoundingCircle(){
    Circle circle;
    circle.center = getPosition();
    circle.radius = PLANE_SIZE/2;
    return circle;
}