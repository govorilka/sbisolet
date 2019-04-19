#include "precomp.h"
#include "UI.h"
#include "Scene.h"
#include <stdio.h>

UI::UI(RenderWindow &window) : rect(0, 0, window.getSize().x * 1000 / window.getSize().y, 1000) {

    font.loadFromFile("arial.ttf");
    Fothers.loadFromFile("natron.ttf");

    game_over.setFont(font);
    game_over.setCharacterSize(90);
    game_over.setColor(Color::Red);
    game_over.setStyle(Text::Bold);

    score.setFont(font);
    score.setCharacterSize(50);
    score.setColor(Color::Red);//set it later
    score.setStyle(Text::Bold);

    hp.setFont(Fothers);
    hp.setCharacterSize(55);
    hp.setColor(Color(255, 58, 129));
    hp.setStyle(Text::Regular | Text::Bold);

    time.setFont(Fothers);
    time.setCharacterSize(55);
    time.setColor(Color(255, 254, 210));
    time.setStyle(Text::Regular);

    cur_score.setFont(Fothers);
    cur_score.setCharacterSize(55);
    cur_score.setColor(Color(255, 254, 210));
    cur_score.setStyle(Text::Regular);

    best_score.setFont(font);
    best_score.setCharacterSize(50);
    best_score.setColor(Color::Red);//set it later
    best_score.setStyle(Text::Bold);

    gratz.setFont(font);
    gratz.setCharacterSize(90);
    gratz.setColor(Color::Red);
    gratz.setStyle(Text::Bold);

    new_record.setFont(font);
    new_record.setCharacterSize(55);
    new_record.setColor(Color::Red);
    new_record.setStyle(Text::Bold);
}

void UI::update(float deltaTime) {
    Scene* scene=Scene::instance;
    score.setString("Your score: " + std::to_string(scene->get_score()));
    game_over.setString("GAME OVER");
    hp.setString("HP: " + std::to_string(scene->get_hp()));
    char str[32];
    sprintf(str,"%.1f",scene->get_time());
    time.setString(std::string("Time: ") +str);

    cur_score.setString("Score: " + std::to_string(scene->get_score()));
    best_score.setString("Best result: " + std::to_string(scene->get_record()));

    gratz.setString("Congratulations");
    //SETTING POSITIONS

    game_over.setPosition(rect.width / 2 - game_over.getLocalBounds().width / 2,
                          rect.height / 2 - 1.5 * game_over.getLocalBounds().height);
    score.setPosition(rect.width / 2 - score.getLocalBounds().width / 2,
                      rect.height / 2 - score.getLocalBounds().height / 2 + 0.5 * game_over.getLocalBounds().height);

    hp.setPosition(rect.width / 30 , 15 * rect.height / 16 - hp.getLocalBounds().height);
    time.setPosition(rect.width / 3,
                     15 * rect.height / 16 - time.getLocalBounds().height);
    cur_score.setPosition(rect.width / 30 , rect.height / 16 - cur_score.getLocalBounds().height);

    best_score.setPosition(rect.width / 2 - best_score.getLocalBounds().width / 2,
                           rect.height / 2 - best_score.getLocalBounds().height / 2 + 1.5 * game_over.getLocalBounds().height);
    gratz.setPosition(rect.width / 2 - game_over.getLocalBounds().width / 2,
            rect.height / 2 - 1.5 * game_over.getLocalBounds().height);
    new_record.setPosition(rect.width / 2 - new_record.getLocalBounds().width / 2,
                      rect.height / 2 - new_record.getLocalBounds().height / 2 + 0.5 * gratz.getLocalBounds().height);
}

void UI::render(sf::RenderWindow &window) {
    View view(rect);
    window.setView(view);
    Scene* scene=Scene::instance;

    if (Scene::instance->isGameOver() || Keyboard::isKeyPressed(Keyboard::D)) {
        if(scene->get_score()<scene->get_record()) {
            window.draw(game_over);
            window.draw(score);
            window.draw(best_score);
        } else {
            scene->set_record(scene->get_score());
            new_record.setString("New world record: " + std::to_string(scene->get_record()));
            window.draw(new_record);
            window.draw(gratz);
        }

    } else {
        window.draw(hp);
        window.draw(time);
        window.draw(cur_score);
    }

}