#pragma once

#include <string>
#include <vector>
#include <QByteArray>
#include <QList>

class Command {
public:
    enum class Type {
        ACCELEROMETER = 0,
        GYROSCOPE = 1,
        BUTTON_A = 2,
        BUTTON_B = 3,
        BUTTON_C = 4,
        BUTTON_D = 5,
        SONAR = 6
    };
    Command(const QByteArray &name, std::vector<double> args);
    Type type;
    std::vector<double> args;
};

class CommandParser {
public:
    static Command getCommand(const QByteArray &data);

private:
    static bool checkName(const std::string &name);
};




