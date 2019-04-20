#include "precomp.h"
#include "Scene.h"
#include "UI.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Bonuses.h>

int main()
{
    RenderWindow window(VideoMode::getDesktopMode(), "SBISolet");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    Scene scene{window};
    scene.initScene();

    Clock clock;
    Time deltaTime;

    while (window.isOpen())
    {
        Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::B){
                    Bonuses::instance->createBonus();
                }
            }   
        }
        deltaTime = clock.restart();
        scene.update(deltaTime.asSeconds());
        scene.render(window);

        window.display();
    }
    return EXIT_SUCCESS;
}