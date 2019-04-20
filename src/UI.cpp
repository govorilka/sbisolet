#include "precomp.h"
#include "UI.h"
#include "Scene.h"
#include <stdio.h>

UI::UI(RenderWindow &window) : rect(0, 0, window.getSize().x * 1000 / window.getSize().y, 1000) {

    if(!texture.loadFromFile("effects.png")){
        throw std::runtime_error("Failed to load effects.png");
    }

    hp_spr.setTexture(texture);
    hp_spr.setOrigin(128,128);
    hp_spr.setScale(UI_HEART_SIZE/ 256, UI_HEART_SIZE / 256);
    hp_spr.setTextureRect(IntRect (0,512,256,256));

    rocketKit.setTexture(texture);
    rocketKit.setOrigin(128,128);
    rocketKit.setScale(UI_KIT_SIZE / 256, UI_KIT_SIZE / 256);
    rocketKit.setTextureRect(IntRect (512,768,256,256));
    kitScale=Vector2f(UI_KIT_SIZE / 256, UI_KIT_SIZE / 256);

    bird.setTexture(texture);
    bird.setOrigin(128,128);
    bird.setScale(UI_BIRD_SIZE / 256, UI_BIRD_SIZE  / 256);
    bird.setTextureRect(IntRect(256,0,256,256));
    birdScale=Vector2f(UI_BIRD_SIZE / 256, UI_BIRD_SIZE  / 256);

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

    /*
    game_over.setFont(font);
    game_over.setCharacterSize(90);
    game_over.setColor(Color::Red);
    game_over.setStyle(Text::Bold);
    */
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

    count_rocketkit.setFont(Fothers);
    count_rocketkit.setCharacterSize(55);
    count_rocketkit.setColor(Color(255, 254, 210));
    count_rocketkit.setStyle(Text::Regular);

   RectangleShape rectangle;
   RectangleShape rectangle_in;
   RectangleShape bar;


}

void UI::update(float deltaTime) {
    Scene* scene=Scene::instance;

    score.setString("Your score: " + std::to_string(scene->getFinalScore()));
    game_over.setString("GAME OVER");
    count_birds.setString("x "+std::to_string(scene->getBirds()));
    count_rocketkit.setString("x "+std::to_string(scene->getRocketKits()));

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

    best_score.setPosition(rect.width / 2 - best_score.getLocalBounds().width / 2,
                           rect.height / 2 - best_score.getLocalBounds().height / 2 + 1.5 * game_over.getLocalBounds().height);
    //new_record.setPosition(rect.width / 2 - new_record.getLocalBounds().width / 2,
      //                rect.height / 2 - new_record.getLocalBounds().height / 2 + 0.5 * game_over.getLocalBounds().height);

    hp_spr.setPosition(rect.width/15,14*rect.height/15);
    //rocketkit
    count_rocketkit.setPosition(UI_ROCKETKIT_WIDTH*rect.width/100,(UI_BAR_HEIGHT-1)*rect.height/UI_BAR_HEIGHT+count_rocketkit.getLocalBounds().height);
    rocketKit.setPosition((UI_ROCKETKIT_WIDTH-2)*rect.width/100,14*rect.height/15);
    //bird
    bird.setPosition(rect.width/2-UI_BIRD_SIZE/3,UI_TOP_BAR_SIZE/2);
    count_birds.setPosition(rect.width/2,UI_TOP_BAR_SIZE/2-count_birds.getLocalBounds().height);

   if(scene->get_time()-scene->getlastBirdTime()>0 && scene->get_time()-scene->getlastBirdTime()<UI_BIRD_MAX_TIME){
       float bird_scale_scalar=UI_BIRD_MAX_SCALE-(UI_BIRD_MAX_SCALE-1)*(scene->get_time()-scene->getlastBirdTime())/UI_BIRD_MAX_TIME;
       bird.setScale(bird_scale_scalar*birdScale.x,bird_scale_scalar*birdScale.y);
    }else{
       bird.setScale(birdScale);
   }

 if(scene->get_time()-scene->getlastRocketKitTime()>0 && scene->get_time()-scene->getlastRocketKitTime()<UI_BIRD_MAX_TIME){
     float fuel_scale_scalar=UI_BIRD_MAX_SCALE-(UI_BIRD_MAX_SCALE-1)*(scene->get_time()-scene->getlastRocketKitTime())/UI_BIRD_MAX_TIME;
     rocketKit.setScale(fuel_scale_scalar*kitScale.x,fuel_scale_scalar*kitScale.y);
 }else{
     rocketKit.setScale(kitScale);
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
            new_record.setPosition(rect.width / 2 - new_record.getLocalBounds().width / 2,
                                   rect.height / 2 - new_record.getLocalBounds().height / 2 + 0.5 * game_over.getLocalBounds().height);
            window.draw(new_record);
            window.draw(game_over);
        }

    } else {
       window.draw(bar);//Down bar
       window.draw(bird);//SBIS BIRD
       window.draw(count_birds);//SBIS BIRDS-coutt
       window.draw(rectangle);//FUEL
       window.draw(rectangle_in);//FUEL
        if(scene->isRocket()){
            window.draw(rocketKit);
            window.draw(count_rocketkit);//Count kits
        }


        hp_spr.setPosition(UI_HEART_WIDTH,14*rect.height/15);
        window.draw(hp_spr);
        if(scene->get_hp()>1) {
            hp_spr.setPosition(UI_HEART_WIDTH+ UI_HEART_DIST + UI_HEART_SIZE, 14 * rect.height / 15);
            window.draw(hp_spr);
        }
        if(scene->get_hp()>2) {
            hp_spr.setPosition(UI_HEART_WIDTH + 2 * UI_HEART_DIST + 2*UI_HEART_SIZE, 14 * rect.height / 15);
            window.draw(hp_spr);
        }

    }

}