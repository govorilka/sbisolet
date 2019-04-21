#include "precomp.h"
#include "Plane.h"
#include "Bonuses.h"
#include "Scene.h"
#include "Segment.h"
#include "Utils.h"
#include <cstdlib>

Bonuses* Bonuses::instance = nullptr;

Bonuses::Bonuses()

{
    instance = this;
    if(!texture.loadFromFile("effects.png")) {
        throw std::runtime_error("Failed to load effects.png");
    }
}
void Bonuses::initScene() {
   bonuses.clear();
}

void Bonuses::update(float deltaTime) {
float p = 0.2;
    for ( auto it = bonuses.begin(); it != bonuses.end(); )
    {
        auto it_next = it;
        it_next++;
        const auto& bonus = *it;
        FloatRect rect = bonus.sprite.getGlobalBounds();
        float width = rect.width;
        float height = rect.height;
        rect.left += width * p;
        rect.top -= height * p;
        rect.width = width * (1-p);
        rect.height = height * (1-p);
        if (rect.intersects(Plane::instance->getGlobalBounds()))
        {
            bonuses.erase(it);
            applyBonus(bonus);
        }
        it = it_next;
    }

}

void Bonuses::render(RenderWindow &window) {
    for (const auto& bonus: bonuses)
    {
        window.draw(bonus.sprite);
    }

}

bool Bonuses::onTerrainSegmentCreated(const Segment &segment) {
    if (Utils::getRandomNumber(0, 5) == 0) {
        createBonus(segment);
        return true;
    }
    return false;
}

void Bonuses::createBonus(const Segment &segment) {
    Bonus bonus;

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
   // if (bonus.type == Bonuses::BonusType::ROCKET)
  //      bonus.sprite.setScale(BONUS_ROCKET_SIZE / 256, -BONUS_ROCKET_SIZE / 256);
    if ((bonus.type != Bonuses::BonusType::BIRD)&&(bonus.type != Bonuses::BonusType::CLOUD)){
        bonus.sprite.setPosition(segment.first.x,segment.first.y + 6);
    }
    else{
        bonus.sprite.setPosition(segment.first.x,60 + Utils::getRandomNumber(0, 30));
    }

   // bonus.sprite.setPosition(Plane::instance->getPosition().x + 30, Plane::instance->getPosition().y);
    bonuses.push_back(bonus);
}
Bonuses::BonusType Bonuses::getRandomBonusType() {
    int x;
    x = Utils::getRandomNumber(1, 4);
    if (x == 1)
        return BonusType::FUEL;
    if (x == 2)
        return BonusType::BIRD;
    if (x == 3)
        return BonusType::LIFE;
    if (x == 4)
        return BonusType::CLOUD;
   // if (x == 5)
    //    return BonusType::ROCKET;
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

void Bonuses::applyBonus(const Bonus &bonus){
    if (bonus.type == Bonuses::BonusType::FUEL){
        Plane::instance->addFuel(BONUS_FUEL_ADD);
        Sounds::instance->play_hp_fuel();
        }
    if (bonus.type == Bonuses::BonusType::BIRD) {
        Scene::instance->addBirds(BONUS_TAKE_BIRD);
        Sounds::instance->play_bird();
    }
    if (bonus.type == Bonuses::BonusType::LIFE) {
        Plane::instance->addHP(BONUS_HEALING);
        Sounds::instance->play_hp_fuel();
    }
    if (bonus.type == Bonuses::BonusType::CLOUD) {
        Plane::instance->addGodModeTime(BONUS_GODMODETIME);
        Sounds::instance->play_armor();
    }
    if (bonus.type == Bonuses::BonusType::ROCKET) {
        Scene::instance->addRocketKit(1);
        Sounds::instance->play_accelerate();
    }
}
