#include "led.h"
#include <mutex>
#include <shared_mutex>

// FREE FUNCTIONS
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

// LED

void LED::printOptionsLocked() const {
    printf(ANSI_COLOR_YELLOW ">> State: %s\n>> Color: %s\n>> Rate: %f\n" ANSI_COLOR_RESET,
           stateToString(state_).c_str(), colorToString(color_).c_str(), rate_);
}
void LED::reprintOptions() const {
    printf("\033[A\33[2KT\r\033[A\33[2KT\r\033[A\33[2KT\r");
    printOptionsLocked();
}

LED::LED()
  : state_(State::OFF)
  , color_(Color::RED)
  , rate_(0) {}

LED::~LED() {
}

void LED::setColor(Color color) {
    std::unique_lock lock(mutex_);
    color_ = color;
    reprintOptions();
}

void LED::setState(State state) {
    std::unique_lock lock(mutex_);
    state_ = state;
    reprintOptions();
}

void LED::setRate(float rate) {
    std::unique_lock lock(mutex_);
    rate_ = rate;
    reprintOptions();
}

Color LED::getColor() const {
    std::shared_lock lock(mutex_);
    return color_;
}

State LED::getState() const {
    std::shared_lock lock(mutex_);
    return state_;
}

float LED::getRate() const {
    std::shared_lock lock(mutex_);
    return rate_;
}

void LED::printOptions() const
{
    std::shared_lock lock(mutex_);
    printOptionsLocked();
}
