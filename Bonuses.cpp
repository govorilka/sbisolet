#include "precomp.h"
#include "Bonuses.h"
#include <cstdlib>

Bonuses::Bonuses() {
    texture.loadFromFile("fuelBirdArmor.png");
}
void Bonuses::initScene() {
    for(int i=0;i<3;i++) {
        createBonus();
    }
}

void Bonuses::update(float deltaTime) {

}

void Bonuses::render(RenderWindow &window) {
    window.draw(sprite);


}

void Bonuses::createBonus() {
    Bonus bonus;
    bonus.type = getRandomBonusType();
    bonus.sprite = getBonusSprite(bonus.type);
    bonus.sprite.setPosition();
    bonuses.push_back(bonus);
}

BonusType Bonuses::getRandomBonusType() {
    int x;
    x = 1 + rand() % 3;
    if (x == 1)
        return FUEL;
    if (x == 2)
        return BIRD;
    if (x == 3)
        return LIFE;
    return FUEL;
}

Sprite Bonuses::getBonusSprite(BonusType type) {
    Sprite sprite;
    sprite.setTexture(texture);
    if (type == FUEL) {
        sprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
    }
    if (type == BIRD) {
        sprite.setTextureRect(sf::IntRect(256, 0, 256, 256));
    }
    if (type == LIFE) {
        sprite.setTextureRect(sf::IntRect(512, 0, 256, 256));
    }
    return sprite;
}