#pragma once


#include <list>
#include <cstdlib>
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

    class Bonus{
    public:
        BonusType   type;
        Sprite      sprite;

        bool isAlive;
    };

    
    Texture texture;

    std::list<Bonus> bonuses;

    Bonuses();
    static Bonuses* instance;
    void initScene();
    void onTerrainSegmentCreated(const Segment &segment);
    void update(float deltaTime);
    void render(RenderWindow& window);
    void createBonus(const Segment &segment);
    BonusType getRandomBonusType();
    Sprite getBonusSprite(BonusType type);

    bool isToBeRemoved();
 private:
    void setPosition(Vector2f position);   
};
