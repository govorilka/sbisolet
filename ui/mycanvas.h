#pragma once

#include "qtsfmlcanvas.h"

#include <SFML/Graphics.hpp>

#include <memory>

class Scene;
class QKeyEvent;

class MyCanvas : public QtSFMLCanvas
{
public :
    MyCanvas(QWidget* parent = nullptr);
//    void set( )
    Scene* getScene() {return  mScene.get();}

protected:
   void keyPressEvent(QKeyEvent *event) override;

protected: // QtSFMLCanvas
    void OnInit();
    void OnUpdate(float angle);

private:
    sf::Clock mClock;
    std::unique_ptr<Scene> mScene;
};
