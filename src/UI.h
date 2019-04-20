#pragma once


class UI {
    Sprite sprite;//hp
    Texture texture;//hp
    Sprite rocketKit;
    Texture texture_kit;
    Sprite bird;
    Texture texture_bird;
    Vector2f birdScale,kitScale;
private:
    FloatRect rect;

    RectangleShape rectangle,rectangle_in,bar;
    Font font;
    Text game_over;//main title
    Text score,time,hp;
    Text cur_score;
    Text best_score;
    Text new_record;
    Text count_birds;
    Text count_rocketkit;
    Font Fothers;

public:

    UI(RenderWindow &window);
    void update(float deltaTime);
    void render(RenderWindow& window);
};


