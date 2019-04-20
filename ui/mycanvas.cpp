#include "precomp.h"

#include "mycanvas.h"

#include <iostream>
#include <string>

#include <QDir>

#include "Scene.h"

MyCanvas::MyCanvas(QWidget* parent)
    : QtSFMLCanvas(parent)
{}

void MyCanvas::OnInit()
{
    mScene = std::make_unique<Scene>(*this);
    mClock.restart();
}

void MyCanvas::OnUpdate()
{
    Time deltaTime = mClock.restart();
    mScene->update(deltaTime.asSeconds());
    mScene->render(*this);
}
