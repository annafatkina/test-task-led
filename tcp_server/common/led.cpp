#include "led.h"

LED* LED::led_ = nullptr;

std::string stateToString(State state) {
    switch (state) {
    case State::ON:
        return "on";
    case State::OFF:
        return "off";
    default:
        return "";
    }
}

State stringToState(std::string state) {
    std::transform(state.begin(), state.end(), state.begin(), ::tolower);

    if (state == "on")
        return State::ON;
    if (state == "off")
        return State::OFF;
    throw std::runtime_error("Unknown state: " + state);
}

std::string colorToString(Color color) {
    switch (color) {
    case Color::RED:
        return "red";
    case Color::GREEN:
        return "green";
    case Color::BLUE:
        return "blue";
    default:
        return "";
    }
}

Color stringToColor(std::string color) {
    std::transform(color.begin(), color.end(), color.begin(), ::tolower);

    if (color == "red")
        return Color::RED;
    if (color == "green")
        return Color::GREEN;
    if (color == "blue")
        return Color::BLUE;
    throw std::runtime_error("Unknown color: " + color);
}

LED* LED::getLED() {
    if(led_ == nullptr) {
        led_ = new LED();
    }
    return led_;
}
