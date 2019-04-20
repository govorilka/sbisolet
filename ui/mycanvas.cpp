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

void MyCanvas::setPlaneAngle(float angle)
{
    if (mScene)
    {
        mScene->setPlaneAngle(angle, true);
    }
}

void MyCanvas::keyPressEvent(QKeyEvent *event)
{
    if (!mScene)
    {
        return;
    }

    switch(event->key()) {
    case Qt::Key_Q:
        mScene->start();
        break;
    case Qt::Key_W:
        mScene->setPlaneAngle(45);
        break;
    case Qt::Key_S:
        mScene->setPlaneAngle(-45);
        break;
    case Qt::Key_A:
        mScene->setPlaneAngle(0);
        break;
    }
//    if (event->key() == Qt::Key_S && mScene)
//    {
//        mScene->start();
//    }

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
