#pragma once

#include <QMainWindow>
#include <QSerialPort>

#include <Scene.h>
#include <UI.h>

namespace Ui {
    class MainWindow;
}

class QLabel;
class MyCanvas;
class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

private:
    void initActionsConnections();

    void showStatusMessage(const QString &message);

private:
    Ui::MainWindow* ui = nullptr;
    QLabel* mStatus = nullptr;
    SettingsDialog* mSettings = nullptr;
    QSerialPort* mSerial = nullptr;

    MyCanvas* mCanvas = nullptr;

    bool stable = false;
    std::string nextCommand;
};
