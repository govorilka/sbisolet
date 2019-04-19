#pragma once

#include "qtsfmlcanvas.h"

#include <SFML/Graphics.hpp>

class MyCanvas : public QtSFMLCanvas
{
public :
    MyCanvas(QWidget* parent = nullptr);

protected: // QtSFMLCanvas
    void OnInit();
    void OnUpdate();

private:
    sf::Clock myClock;
    sf::Texture myImage;
    sf::Sprite mySprite;
};
