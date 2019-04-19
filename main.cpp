#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SBISolet");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;
    sf::Time deltaTime = sf::Time::Zero;
    while (window.isOpen())
    {
        sf::Event event{};
        deltaTime += clock.restart();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(0, 0, 255));
        window.display();
    }
    return EXIT_SUCCESS;
}