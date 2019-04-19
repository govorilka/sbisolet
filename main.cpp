#include "precomp.h"
#include "Scene.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    RenderWindow window(VideoMode::getDesktopMode(), "SBISolet");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    Scene scene{};
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
        }
        deltaTime = clock.restart();
        scene.update(deltaTime.asSeconds());
        scene.render(window);
        window.display();
    }
    return EXIT_SUCCESS;
}