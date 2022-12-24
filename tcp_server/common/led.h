#ifndef LED_H
#define LED_H

#include <string>
#include <algorithm>
#include <stdexcept>
#include <memory>

#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

enum class State
{
    OFF = 0,
    ON
};

std::string stateToString(State state);

State stringToState(std::string state);

enum class Color {
    RED,
    GREEN,
    BLUE
};

std::string colorToString(Color color);

Color stringToColor(std::string color);

class LED {

protected:
    State state_;
    Color color_;
    float rate_;

    // add mutex
    static LED* led_;

    LED()
      : state_(State::OFF)
      , color_(Color::RED)
      , rate_(0) {}

public:
    static LED* getLED();

    //~LED() {
        //delete led_;
    //}

    void setColor(Color color) {
        // todo thread safety
        color_ = color;
        reprintOptions();
    }

    void setState(State state) {
        state_ = state;
        reprintOptions();
    }

    void setRate(float rate) {
        rate_ = rate;
        reprintOptions();
    }

    Color getColor() const {
        return color_;
    }

    State getState() const {
        return state_;
    }

    float getRate() const {
        return rate_;
    }

    void printOptions() const {
        printf(ANSI_COLOR_YELLOW ">> State: %s\n>> Color: %s\n>> Rate: %f\n" ANSI_COLOR_RESET,
               stateToString(state_).c_str(), colorToString(color_).c_str(), rate_);
    }
    void reprintOptions() const {
        printf("\033[A\33[2KT\r\033[A\33[2KT\r\033[A\33[2KT\r");
        printOptions();
    }
};

#endif // LED_H
