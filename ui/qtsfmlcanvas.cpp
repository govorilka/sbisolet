#include "qtsfmlcanvas.h"

#include <QTimerEvent>
#include <QResizeEvent>

#ifdef Q_WS_X11
#include < Qt/qx11info_x11.h >
#include < X11/Xlib.h >
#endif

#include <iostream>

QtSFMLCanvas::QtSFMLCanvas(QWidget* parent)
    : QWidget(parent)
{
    // Setup some states to allow direct rendering into the widget
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    // Set strong focus to enable keyboard events to be received
    setFocusPolicy(Qt::StrongFocus);
}

QtSFMLCanvas::~QtSFMLCanvas()
{
}

void QtSFMLCanvas::resizeEvent(QResizeEvent* event)
{
    if (mInitialized)
    {
        const auto s = event->size();
        RenderWindow::setSize(sf::Vector2u(s.width(), s.height()));
    }
}

void QtSFMLCanvas::showEvent(QShowEvent*)
{
    if (!mInitialized)
    {
        // Under X11, we need to flush the commands sent to the server to ensure that
        // SFML will get an updated view of the windows
        #ifdef Q_WS_X11
        //XFlush(QX11Info::display());
        #endif

        // Create the SFML window with the widget handle
        RenderWindow::create((sf::WindowHandle)winId());

        // Let the derived class do its specific stuff
        OnInit();

        mInitialized = true;
    }
}

QPaintEngine* QtSFMLCanvas::paintEngine() const
{
    return 0;
}

void QtSFMLCanvas::paintEvent(QPaintEvent*)
{
    // Let the derived class do its specific stuff
    OnUpdate();

    // Display on screen
    RenderWindow::display();

    update();
}

void QtSFMLCanvas::OnInit()
{}

void QtSFMLCanvas::OnUpdate()
{}
