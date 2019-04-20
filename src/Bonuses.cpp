#include "precomp.h"
#include "Plane.h"
#include "Bonuses.h"
#include <cstdlib>

 Bonuses* Bonuses::instance = nullptr;

Bonuses::Bonuses() {
    instance = this;
    if(!texture.loadFromFile("fuelBirdArmor.png")) {
        throw std::runtime_error("Failed to load fuelBirdArmor.png");
    }

}
void Bonuses::initScene() {
   /* for(int i=0;i<3;i++) {
        createBonus();
    }*/
}

void Bonuses::update(float deltaTime) {

}

void Bonuses::render(RenderWindow &window) {
    for ( const auto& bonus: bonuses)
    {
        window.draw(bonus.sprite);
    }

}

void Bonuses::createBonus() {
    Bonus bonus;
    bonus.type = getRandomBonusType();
    bonus.sprite = getBonusSprite(bonus.type);
    //bonus.sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    bonus.sprite.setScale(BONUS_SIZE / texture.getSize().x, -BONUS_SIZE / texture.getSize().y);
    bonus.sprite.setPosition(Plane::instance->getPosition().x + 30, Plane::instance->getPosition().y);
    bonuses.push_back(bonus);
}

Bonuses::BonusType Bonuses::getRandomBonusType() {
    int x;
    x = 1 + rand() % 3;
    if (x == 1)
        return BonusType::FUEL;
    if (x == 2)
        return BonusType::BIRD;
    if (x == 3)
        return BonusType::LIFE;
    return BonusType::FUEL;
}

Sprite Bonuses::getBonusSprite(BonusType type) {
    Sprite sprite;
    sprite.setTexture(texture);
    if (type == BonusType::FUEL) {
        sprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
    }
    if (type == BonusType::BIRD) {
        sprite.setTextureRect(sf::IntRect(256, 0, 256, 256));
    }
    if (type == BonusType::LIFE) {
        sprite.setTextureRect(sf::IntRect(512, 0, 256, 256));
    }
    return sprite;
}
