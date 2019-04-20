#include "precomp.h"
#include "UI.h"
#include "Scene.h"
#include <stdio.h>

UI::UI(RenderWindow &window) : rect(0, 0, window.getSize().x * 1000 / window.getSize().y, 1000) {

    texture.loadFromFile("heart.png");
    texture_kit.loadFromFile("rocket.png");
    texture_bird.loadFromFile("rocket.png");

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y / 2);
    sprite.setScale(PLANE_SIZE*10 / texture.getSize().x, PLANE_SIZE*10 / texture.getSize().y);

    kit.setTexture(texture_kit);
    kit.setOrigin(texture_kit.getSize().x/2,texture_kit.getSize().y/2);
    kit.setScale(PLANE_SIZE*10 / texture_kit.getSize().x, PLANE_SIZE*10 / texture_kit.getSize().y);

    bird.setTexture(texture_bird);
    bird.setOrigin(texture_bird.getSize().x/2,texture_bird.getSize().y/2);
    bird.setScale(UI_BIRD_SIZE / texture_bird.getSize().x, UI_BIRD_SIZE  / texture_bird.getSize().y);
    birdScale=Vector2f(UI_BIRD_SIZE / texture_bird.getSize().x, UI_BIRD_SIZE  / texture_bird.getSize().y);

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

    new_record.setFont(font);
    new_record.setCharacterSize(55);
    new_record.setColor(Color::Red);
    new_record.setStyle(Text::Bold);

    count_birds.setFont(Fothers);
    count_birds.setCharacterSize(55);
    count_birds.setColor(Color(255, 254, 210));
    count_birds.setStyle(Text::Regular);

    count_fuel.setFont(Fothers);
    count_fuel.setCharacterSize(55);
    count_fuel.setColor(Color(255, 254, 210));
    count_fuel.setStyle(Text::Regular);

   RectangleShape rectangle;
   RectangleShape rectangle_in;
   RectangleShape bar;


}

void UI::update(float deltaTime) {
    Scene* scene=Scene::instance;

    score.setString("Your score: " + std::to_string(scene->getFinalScore()));
    game_over.setString("GAME OVER");
    hp.setString("HP: " + std::to_string(scene->get_hp()));
    count_birds.setString("x "+std::to_string(scene->getBirds()));
    count_fuel.setString("x "+std::to_string(scene->getFuel()));

    char str[32];
    sprintf(str,"%.1f",scene->get_time());
    time.setString(std::string("Time: ") +str);
    cur_score.setString("Score: " + std::to_string(scene->getFinalScore()));
    best_score.setString("Best result: " + std::to_string(scene->get_record()));

    //gas
    rectangle.setSize(sf::Vector2f(UI_GAS_WIDTH*1.f, UI_GAS_HEIGHT*1.f));
    rectangle.setFillColor(Color(0, 0, 255));
    rectangle.setPosition(rect.width/2-rectangle.getSize().x/2,(UI_BAR_HEIGHT-0.5)*rect.height/UI_BAR_HEIGHT-rectangle.getSize().y/2);
    rectangle.setOutlineThickness(1.f);
    rectangle.setOutlineColor(Color(0,0,0));

    rectangle_in.setSize(Vector2f((scene->get_gas())*400.f,50.f));
    rectangle_in.setFillColor(Color(255,137,47));
    rectangle_in.setPosition(rect.width/2-rectangle.getSize().x/2,(UI_BAR_HEIGHT-0.5)*rect.height/UI_BAR_HEIGHT-rectangle.getSize().y/2);

    bar.setSize(Vector2f(rect.width,rect.height/UI_BAR_HEIGHT));
    bar.setFillColor(UI_BAR_COLOR);
    bar.setPosition(0,(UI_BAR_HEIGHT-1)*rect.height/UI_BAR_HEIGHT);
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
    new_record.setPosition(rect.width / 2 - new_record.getLocalBounds().width / 2,
                      rect.height / 2 - new_record.getLocalBounds().height / 2 + 0.5 * game_over.getLocalBounds().height);

    count_birds.setPosition(rect.width/2-texture_bird.getSize().x/3,rect.height/14-texture_bird.getSize().y/4);
    count_fuel.setPosition(13*rect.width/15+UI_BIRD_SIZE,(UI_BAR_HEIGHT-1)*rect.height/UI_BAR_HEIGHT+count_fuel.getLocalBounds().height/2);

    sprite.setPosition(rect.width/15,14*rect.height/15);
    kit.setPosition(13*rect.width/15,14*rect.height/15);
    bird.setPosition(rect.width/2-5*texture_bird.getSize().x/8,rect.height/14);

   if(scene->get_time()-scene->getlastBirdTime()>0 && scene->get_time()-scene->getlastBirdTime()<UI_BIRD_MAX_TIME){
       float bird_scale_scalar=UI_BIRD_MAX_SCALE-(UI_BIRD_MAX_SCALE-1)*(scene->get_time()-scene->getlastBirdTime())/UI_BIRD_MAX_TIME;
       bird.setScale(bird_scale_scalar*birdScale.x,bird_scale_scalar*birdScale.y);
    }else{
       bird.setScale(birdScale);
   }


}

void UI::render(sf::RenderWindow &window) {
    View view(rect);
    window.setView(view);

    Scene* scene=Scene::instance;

    if (Scene::instance->isGameOver() || Keyboard::isKeyPressed(Keyboard::D)) {
        if(scene->getFinalScore() < scene->get_record()) {
            window.draw(game_over);
            window.draw(score);
            window.draw(best_score);
        } else {
            scene->set_record(scene->getFinalScore());
            new_record.setString("New world record: " + std::to_string(scene->get_record()));
            window.draw(new_record);
            window.draw(game_over);
        }

    } else {
       // window.draw(hp);
       // window.draw(time);
        window.draw(bar);
       // window.draw(cur_score);
       window.draw(bird);
       window.draw(count_birds);
       window.draw(rectangle);
       window.draw(rectangle_in);
       window.draw(count_fuel);

        if(scene->isRocket()){
            window.draw(kit);
        }
        sprite.setPosition(rect.width/15,14*rect.height/15);
        window.draw(sprite);
        if(scene->get_hp()>1) {
            sprite.setPosition(rect.width / 15 + texture.getSize().x / 4, 14 * rect.height / 15);
            window.draw(sprite);
        }
        if(scene->get_hp()>2) {
            sprite.setPosition(rect.width / 15 + 2 * texture.getSize().x / 4, 14 * rect.height / 15);
            window.draw(sprite);
        }
    }

}