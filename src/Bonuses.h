#pragma once
#include <list>
#include <cstdlib>

class Bonuses {
public:
    enum class BonusType: int
    {
        LIFE,
        FUEL,
        BIRD
    };

    class Bonus{
    public:
        BonusType   type;
        Sprite      sprite;
    };

    
    Texture texture;

    std::list<Bonus> bonuses;

    Bonuses();
    static Bonuses* instance;
    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
    void createBonus();
    BonusType getRandomBonusType();
    Sprite getBonusSprite(BonusType type);

 private:
    void setPosition(Vector2f position);   
};
