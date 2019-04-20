#pragma once


class UI {
    Sprite hp_spr;//hp
    Texture texture;//hp
    Sprite rocketKit;
    Sprite bird;

    Vector2f birdScale,kitScale;
private:
    FloatRect rect;

    RectangleShape rectangle,rectangle_in,bar;
    Font font;
    Text game_over;//main title
    Text score;
    Text best_score;
    Text new_record;
    Text count_birds;
    Text count_rocketkit;
    Text its_fuel;
    Font Fothers;

public:

    UI(RenderWindow &window);
    void update(float deltaTime);
    void render(RenderWindow& window);
};


