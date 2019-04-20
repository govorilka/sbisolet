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
    , mCanvas(new MyCanvas(this))
    , mStatus(new QLabel)
    , mSettings(new SettingsDialog)
    , mSerial(new QSerialPort(this))
{
    ui->setupUi(this);
    setCentralWidget(mCanvas);

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    ui->statusBar->addWidget(mStatus);

    initActionsConnections();

    connect(mSerial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(mSerial, &QSerialPort::readyRead, this, &MainWindow::readData);
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
        std::cout<<x<<std::endl;
        while (mSerial->getChar(&x))
        {
            if (x == ';')
            {
                stable = true;
            }
            return;
        }
    }

    while (mSerial->getChar(&x))
    {
        if (x!=';')
        {
#ifdef linux
            if (x=='.') // =)
                x= ',';
#endif
            nextCommand+=x;
        }
        else
        {
            std::cout<<"READY COMMAND: "<<nextCommand <<std::endl;
            try {
             Command a = CommandParser::getCommand(nextCommand);
             for (double arg : a.args)
                 std::cout<<arg<<" ";
             std::cout<<std::endl<<std::endl;
            }
            catch (...) {
            }

            nextCommand.clear();
            return;
        }
    }

//    m_serial->getChar(&x);
//    if (x==';') {
//        stable = true;
//    }
//    command+=x;

//    std::cout<<x<<std::endl;
//    std::cout<<"READED "<<m_serial->read(x,250)<<std::endl;

/*    const QByteArray data = m_serial->read(15);
    //m_serial->readLine(
//    std::cout << data.constData() << std::endl
    auto str = std::string(data.constData());
    std::cout<<"STRING GOT "<<str<<std::endl<<std::endl;
    try {
    auto command = CommandParser::getCommand(str);
    std::cout<<"TYPE "<<(int)command.type<<std::endl <<"ARGS: ";
    for (auto& arg: command.args)
        std::cout<<arg<<std::endl;
    std::cout<<std::endl;
    }
    catch (std::exception& exc) {}
    std::cout << str.constData() << std::endl; */
//    Q_UNUSED(data);
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
