#pragma once


class UI {
private:
    FloatRect rect;
    Font font;
    Text game_over;//main title
    Text score,time,hp;
    Text cur_score;
    Text best_score;
    Text new_record,gratz;
    Font Fothers;
public:

    UI(RenderWindow &window);
    void update(float deltaTime);
    void render(RenderWindow& window);
};


