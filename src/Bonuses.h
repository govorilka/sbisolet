#pragma once


#include <list>
#include <cstdlib>
#include <GameObject.h>
#include "precomp.h"

class Segment;

class Bonuses {
public:
    enum class BonusType: int
    {
        LIFE,
        FUEL,
        CLOUD,
        BIRD,
        ROCKET
    };

    class Bonus
    {
    public:
        BonusType   type;
        Sprite      sprite;

    };

    
    Texture texture;

    std::list<Bonus> bonuses;

    Bonuses();

    static Bonuses* instance;
    void initScene();

    bool onTerrainSegmentCreated(const Segment &segment);
    void update(float deltaTime);
    void render(RenderWindow& window);
    void applyBonus(const Bonus &bonus);
    void createBonus(const Segment &segment);
    BonusType getRandomBonusType();
    Sprite getBonusSprite(BonusType type);


 private:
    void setPosition(Vector2f position);   
};
