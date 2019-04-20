#pragma once

#include <QWidget>

#include <SFML/Graphics.hpp>

class QResizeEvent;

class QtSFMLCanvas
    : public QWidget
    , public sf::RenderWindow
{
    Q_OBJECT
public:
    explicit QtSFMLCanvas(QWidget* parent = nullptr);
    ~QtSFMLCanvas() override;

protected: // QWidget
    void showEvent(QShowEvent*) override;
    QPaintEngine* paintEngine() const override;
    void paintEvent(QPaintEvent*) override;
    void resizeEvent(QResizeEvent* event) override;

protected: // Children API
    virtual void OnInit() = 0;
    virtual void OnUpdate(float angle) = 0;

private:
    int mFrameTime = 0;
    int mUpdadteTimerId = 0;
    bool mInitialized = false;
};
