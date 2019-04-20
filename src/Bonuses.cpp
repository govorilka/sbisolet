#include "precomp.h"
#include "Plane.h"
#include "Bonuses.h"
#include "Scene.h"
#include "Segment.h"
#include <cstdlib>

Bonuses* Bonuses::instance = nullptr;

Bonuses::Bonuses() {
    instance = this;
    if(!texture.loadFromFile("effects.png")) {
        throw std::runtime_error("Failed to load effects.png");
    }

}
void Bonuses::initScene() {
   /* for(int i=0;i<3;i++) {
        createBonus();
    }*/
}

void Bonuses::update(float deltaTime) {
    for ( auto& bonus: bonuses){
        if (bonus.sprite.getGlobalBounds().intersects(Plane::instance->getGlobalBounds())) {
            bonus.isAlive = false;
        }
    }
}

void Bonuses::render(RenderWindow &window) {
    for ( const auto& bonus: bonuses)
    {
        window.draw(bonus.sprite);
    }

}

void Bonuses::onTerrainSegmentCreated(const Segment &segment){
    if (rand() % 5 == 0) {
        createBonus(segment);
    }
}

void Bonuses::createBonus(const Segment &segment) {
    Bonus bonus;
    bonus.isAlive = true;
    bonus.type = getRandomBonusType();
    bonus.sprite = getBonusSprite(bonus.type);
    bonus.sprite.setOrigin(128,128);
    if (bonus.type == Bonuses::BonusType::FUEL)
        bonus.sprite.setScale(BONUS_FUEL_SIZE / 256, -BONUS_FUEL_SIZE / 256);
    if (bonus.type == Bonuses::BonusType::BIRD)
        bonus.sprite.setScale(BONUS_BIRD_SIZE / 256, -BONUS_BIRD_SIZE / 256);
    if (bonus.type == Bonuses::BonusType::LIFE)
        bonus.sprite.setScale(BONUS_LIFE_SIZE / 256, -BONUS_LIFE_SIZE / 256);
    if (bonus.type == Bonuses::BonusType::CLOUD)
        bonus.sprite.setScale(BONUS_CLOUD_SIZE / 256, -BONUS_CLOUD_SIZE / 256);
    if (bonus.type == Bonuses::BonusType::ROCKET)
        bonus.sprite.setScale(BONUS_ROCKET_SIZE / 256, -BONUS_ROCKET_SIZE / 256);
    if ((bonus.type != Bonuses::BonusType::BIRD)&&(bonus.type != Bonuses::BonusType::CLOUD)){
        bonus.sprite.setPosition(segment.first.x,segment.first.y + 6);
    }
    else{
        bonus.sprite.setPosition(segment.first.x,60 + (rand()%30));
    }

   // bonus.sprite.setPosition(Plane::instance->getPosition().x + 30, Plane::instance->getPosition().y);
    bonuses.push_back(bonus);
}

Bonuses::BonusType Bonuses::getRandomBonusType() {
    int x;
    x = 1 + rand() % 5;
    if (x == 1)
        return BonusType::FUEL;
    if (x == 2)
        return BonusType::BIRD;
    if (x == 3)
        return BonusType::LIFE;
    if (x == 4)
        return BonusType::CLOUD;
    if (x == 5)
        return BonusType::ROCKET;
    return BonusType::FUEL;
}

Sprite Bonuses::getBonusSprite(BonusType type) {
    Sprite sprite;
    sprite.setTexture(texture);
    if (type == BonusType::FUEL) {
        sprite.setTextureRect(sf::IntRect(512, 256, 256, 256));
    }
    if (type == BonusType::BIRD) {
        sprite.setTextureRect(sf::IntRect(256, 0, 256, 256));
    }
    if (type == BonusType::LIFE) {
        sprite.setTextureRect(sf::IntRect(512, 0, 256, 256));
    }
    if(type == BonusType::CLOUD) {
        sprite.setTextureRect(sf::IntRect(0, 256, 256, 256));
    }
    if(type == BonusType::ROCKET) {
        sprite.setTextureRect(sf::IntRect(512, 768, 256, 256));
    }
    return sprite;
}

/*bool Bonuses::isToBeRemoved() {
    return !isAlive;
}*/