#include "mainwindow.h"
#include "mycanvas.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mCanvas(new MyCanvas(this))
{
    ui->setupUi(this);
    setCentralWidget(mCanvas);
}

MainWindow::~MainWindow()
{
    delete ui;
}
