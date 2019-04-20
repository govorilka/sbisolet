#pragma once
class SkyEffect {
public:
    RectangleShape effect;
    float activeTime;
    float effectDuration;
    SkyEffect();
    void startEffect(Color color,float duration);
    void update(float deltaTime);
    void render(RenderWindow &window);
};


