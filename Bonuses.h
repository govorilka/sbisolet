#pragma once
#include <vector>
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

    std::vector<Bonus> bonuses;

    Bonuses();
    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);
    void createBonus();
    BonusType getRandomBonusType();
    Sprite getBonusSprite(BonusType type);
};
