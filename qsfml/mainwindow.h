#pragma once

#include <QMainWindow>

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