#include "precomp.h"

#include "mycanvas.h"


#include <iostream>
#include <string>

#include <QDir>
#include <QKeyEvent>

#include "Scene.h"

MyCanvas::MyCanvas(QWidget* parent)
    : QtSFMLCanvas(parent)
{}

void MyCanvas::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_S && mScene)
    {
        mScene->start();
    }
}

void MyCanvas::OnInit()
{
    mScene = std::make_unique<Scene>(*this);
    mScene->initScene();
    mScene->setArduinoMode();
    mClock.restart();
}

void MyCanvas::OnUpdate(float angle)
{
    Time deltaTime = mClock.restart();
    mScene->update(deltaTime.asSeconds());
    mScene->render(*this);
}
