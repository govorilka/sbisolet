#pragma once

#include "qtsfmlcanvas.h"

#include <SFML/Graphics.hpp>

#include <memory>

class Scene;

class MyCanvas : public QtSFMLCanvas
{
public :
    MyCanvas(QWidget* parent = nullptr);

protected: // QtSFMLCanvas
    void OnInit();
    void OnUpdate();

private:
    sf::Clock mClock;
    std::unique_ptr<Scene> mScene;
};
