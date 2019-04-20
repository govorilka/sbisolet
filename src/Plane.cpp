#include "precomp.h"
#include "Plane.h"
#include "Sounds.h"

#include "terrain.h"
#include "Camera.h"
#include "Scene.h"

Plane* Plane::instance = nullptr;

Plane::Plane()
    :angle(0),
     hp(PLANE_INIT_HP),
     fuel(PLANE_MAX_FUEL),
     godModeTimeLeft(0),
     lostControlTime(0),
     isKeyboard(true),
     fuelCooldown(0)
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

    fuelSprites.clear();

    lostControlTime=0;
    angle=0;
    sprite.setRotation(0);
    velocity = Vector2f(PLANE_H_SPEED, 0);
    setPosition(Vector2f(0, VIEW_SIZE_Y / 2));
    hp = PLANE_INIT_HP;
    fuel = PLANE_MAX_FUEL;
    Scene::instance->del_Rocket();
    godMode.setTexture(Scene::instance->getEffectsTexture());
    godMode.setTextureRect(sf::IntRect(256, 768, 256, 256));
    godMode.setOrigin(128,128);
    godMode.setColor(sf::Color(255, 255, 255, 100));
    godMode.setScale(GODMODE_SIZE / 256, -GODMODE_SIZE / 256);
    godModeTimeLeft = 0;
}

void Plane::update(float deltaTime) {

    if (godModeTimeLeft > 0){
        godModeTimeLeft -= deltaTime;
    }
    if (lostControlTime > 0) lostControlTime -= deltaTime;
    updateFuelSprites(deltaTime);
    float fuel_dec = 0;
    if (isKeyboard) {
        if(lostControlTime>0){
            setAngle(getCurrentAngle()-EFFECT_ROTATION_SPEED);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up) && fuel > 0 && getPosition().y < PLANE_MAX_HEIGHT - 2.5) {
            fuel_dec = PLANE_FUEL_DEC_UP;
            setAngle(45);
        } else if (Keyboard::isKeyPressed(Keyboard::Down) || fuel == 0) {
            setAngle(-45);
        } else if (fuel > 0) {
            fuel_dec = PLANE_FUEL_DEC;
            setAngle(0);
        }
    } else {
        if (angle > 0) {
            fuel_dec = PLANE_FUEL_DEC_UP;
        } else if (std::abs(angle) < ANGLE_DELTA) {
            fuel_dec = PLANE_FUEL_DEC;
            angle = 0;
        }
    }

    if (hp == 1) {
        fuel_dec *= PLANE_FUEL_CONSUMPTION_ONE_HP_MUL;
    } else if (hp == 2) {
        fuel_dec *= PLANE_FUEL_CONSUMPTION_TWO_HP_MUL;
    }

    if(lostControlTime>0){
        velocity.y =  -ENEMIES_LIGHTNING_VELOCITY;
    }
    else if (getCurrentAngle() != 0) {

        velocity.y = PLANE_V_SPEED * (getCurrentAngle() / 45);
    }

    if (fuel > 0) {
        fuel -= fuel_dec * deltaTime;
        if (fuel < 0) {
            fuel = 0;
        }
    }

    if (Terrain::instance->isIntersects(getGlobalBoundingCircle())) {
        if(hp!=0)Sounds::instance->play_big_boom();
        hp = 0;
    }

    sprite.rotate(calculateRotation());
    Vector2f newPosition = sprite.getPosition() + velocity * deltaTime;
    newPosition.y = std::max(PLANE_MIN_HEIGHT, newPosition.y);
    newPosition.y = std::min(PLANE_MAX_HEIGHT, newPosition.y);
    setPosition(newPosition);
    godMode.setPosition(Plane::getPosition());
}

void Plane::render(RenderWindow& window) {
    window.draw(sprite);
    for(const auto& fuelSprite: fuelSprites) {
        window.draw(fuelSprite);
    }

    if(godModeTimeLeft > 0){
        window.draw(godMode);
    }

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
    if(value<0){
        Scene::instance->getSkyEffect().startEffect(EFFECT_DAMAGE_COLOR,EFFECT_DAMAGE_DURATION);
        Sounds::instance->play_uhh();
    }
    hp = std::min(hp, PLANE_INIT_HP);
}

int Plane::getHP() {
    return hp;
}

const FloatRect Plane::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void Plane::setAngle(float value, bool force) {

    if (!isKeyboard && !force) {
        if (fuel > 0 && getPosition().y > PLANE_MAX_HEIGHT - 2.5 && value > 0) {
            value = 0;
        }
        if (fuel == 0) {
            value = -45;
        }
    }
    angle = value;
}

void Plane::addGodModeTime(float seconds) {
    godModeTimeLeft = seconds;
}


float Plane::getFuel() {
    return fuel;
}

void Plane::addFuel(float value) {
    fuel += value;
    fuel = std::min(fuel, PLANE_MAX_FUEL);
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

void Plane::updateFuelSprites(float deltaTime) {
    if (hp < 3) fuelCooldown -= deltaTime;
    if (hp < 3 && fuelCooldown < 0) {
        Sprite fuelSprite;
        Texture& effects = Scene::instance->getEffectsTexture();
        fuelSprite.setTexture(effects);
        fuelSprite.setTextureRect(IntRect(256*1,256*2,256,256));

        fuelSprite.setOrigin(128, 128);
        fuelSprite.setScale(PLANE_FUEL_SIZE / 256, -PLANE_FUEL_SIZE / 256);
        fuelSprite.setPosition(sprite.getPosition().x - 0.5,
                sprite.getPosition().y);
        fuelSprites.push_back(std::move(fuelSprite));
        if (hp == 1) fuelCooldown = PLANE_FUEL_COOLDOWN;
        if (hp == 2) fuelCooldown = PLANE_FUEL_COOLDOWN * 2;
    }
    for(auto it = fuelSprites.begin(); it != fuelSprites.end(); it++) {
        it->setPosition(it->getPosition() - Vector2f(-deltaTime * PLANE_FUEL_H_SPEED, deltaTime * PLANE_FUEL_V_SPEED));
        if (it->getPosition().x < Camera::instance->getRect().left - 2 * PLANE_FUEL_SIZE ||
            Terrain::instance->isIntersects(getBCircleFromSprite(*it))) {
            it = fuelSprites.erase(it);
        }
    }
}

Circle Plane::getBCircleFromSprite(Sprite sprite) {
    Circle circle;
    circle.center = sprite.getPosition();
    circle.radius = PLANE_FUEL_SIZE/2;
    return circle;
}
