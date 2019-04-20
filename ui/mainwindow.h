#pragma once

#include <QMainWindow>

#include <Scene.h>
#include <UI.h>

namespace Ui {
    class MainWindow;
}

class MyCanvas;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui = nullptr;
    MyCanvas* mCanvas = nullptr;


};
