#include <iostream>
#include "Command.h"


Command::Command(const std::string &name, std::vector<double> args) : args(std::move(args)) {
    if (name == "A")
        type = Type::ACCELEROMETER;
    else if (name == "G")
        type = Type::GYROSCOPE;
    else if (name == "AB")
        type = Type::BUTTON_A;
    else if (name == "DB")
        type = Type::BUTTON_D;
    else if (name == "BB")
        type = Type::BUTTON_B;
    else if (name == "CB")
        type = Type::BUTTON_C;
}

Command CommandParser::getCommand(const std::string &data) {
    size_t pos = 0;
    auto s = data;
    std::string name;
    std::vector<double> args;
    while ((pos = s.find(' ')) != std::string::npos) {
        auto token = s.substr(0, pos);
        if (name.empty()) {
            if (not checkName(token))
                throw std::logic_error("Invalid command name get from Bluetooth");
            name = token;
        }
        if (token != name) {
            args.emplace_back(std::stod(token));
        }
        s.erase(0, pos + 1);
    }
    args.emplace_back(std::stod(s));
    return Command(name, args);
}

bool CommandParser::checkName(const std::string &name) {
    return name == "A" or
           name == "G" or
           name == "LB" or
           name == "BB" or
           name == "CB" or
           name == "DB";
}

