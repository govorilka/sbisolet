#include "precomp.h"

#include <QLabel>
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QString>
#include <iostream>
#include <QStringList>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settingsdialog.h"
#include "mycanvas.h"

#include "Command.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
//    , mCanvas(new MyCanvas(this))
    , mStatus(new QLabel)
    , mSettings(new SettingsDialog)
    , mSerial(new QSerialPort(this)),
      curCommand("G",{})
{
    ui->setupUi(this);

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    ui->statusBar->addWidget(mStatus);

    initActionsConnections();

    connect(mSerial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(mSerial, &QSerialPort::readyRead, this, &MainWindow::readData);

    setWindowState(Qt::WindowFullScreen);
     mCanvas = new MyCanvas(this);
     setCentralWidget(mCanvas);

}

MainWindow::~MainWindow()
{
    delete mSettings;
    delete ui;
}

void MainWindow::openSerialPort()
{
    const SettingsDialog::Settings p = mSettings->settings();
    mSerial->setPortName(p.name);
    mSerial->setBaudRate(p.baudRate);
    mSerial->setDataBits(p.dataBits);
    mSerial->setParity(p.parity);
    mSerial->setStopBits(p.stopBits);
    mSerial->setFlowControl(p.flowControl);
    if (mSerial->open(QIODevice::ReadWrite))
    {
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), mSerial->errorString());
        showStatusMessage(tr("Open error"));
    }
}

void MainWindow::closeSerialPort()
{
    if (mSerial->isOpen())
    {
        mSerial->close();
    }

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);

    showStatusMessage(tr("Disconnected"));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("Sbisole"), tr("The <b>Sbisolet </b> game make for TesorHack 2019."));
}

void MainWindow::writeData(const QByteArray &data)
{
    mSerial->write(data);
}

void MainWindow::readData()
{
    char x = 0;
    if (!stable)
    {
        while (mSerial->getChar(&x))
        {
            std::cout << x << std::endl;
            if (x == ';')
            {
                stable = true;
                break;
            }
        }
        if (!stable)
        {
            return;
        }
    }

    while (mSerial->getChar(&x))
    {
        if (x!=';')
        {
            nextCommand+=x;
        }
        else
        {
            try
            {
//                std::cout<<nextCommand.constData()<<std::endl;
                curCommand = CommandParser::getCommand(nextCommand);
            }
            catch (...) {
                nextCommand.clear();
                return;
            }

            if (curCommand.type == Command::Type::SONAR) {
                float angle = curCommand.args.at(0);
                std::cout<<"SONAR :"<< angle << std::endl;
                if (angle < 10 || angle > 30) {
                     nextCommand.clear();
                    return;
                }

                mCanvas->setPlaneAngle((angle - 10.) * 4.5 - 45.);
            }
            else
            {
                auto angle = curCommand.args.at(0);
                std::cout<<"BEFORE :"<< angle<<std::endl;
                if (angle< -30  )
                    angle = -45;
                else if ( angle > 30 ) {
                    angle = 45;
                }
                else {
                    angle = 0;
                }
                mCanvas->setPlaneAngle(angle);
            }

            nextCommand.clear();
            return;
        }
    }
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this, tr("Critical Error"), mSerial->errorString());
        closeSerialPort();
    }
}

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionConfigure, &QAction::triggered, mSettings, &SettingsDialog::show);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
}

void MainWindow::showStatusMessage(const QString& message)
{
    mStatus->setText(message);
}
