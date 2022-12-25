#ifndef LED_H
#define LED_H

#include <string>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <shared_mutex>

#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

enum class State
{
    OFF = 0,
    ON
};

// Return the string representation of the specified 'state'.
std::string stateToString(State state);

// Return the state represented in the specified 'state'.  Throw the runtime
// error if there is no conversion to 'State' object.
State stringToState(std::string state);

enum class Color {
    RED,
    GREEN,
    BLUE
};

// Return the string representation of the specified 'color'.
std::string colorToString(Color color);

// Return the color represented in the specified 'state'.  Throw the runtime
// error if there is no conversion to 'Color' object.
Color stringToColor(std::string color);

class LED {
    // This class represents a LED.

protected:
    State state_;
    Color color_;
    float rate_;

    mutable std::shared_mutex mutex_;

    // CLASS METHODS

    // Print all the LED options to cout.
    void printOptionsLocked() const;

    // Replace last cmd lines with printed LED options.
    void reprintOptions() const;

public:
    // Create 'LED' object.
    LED();

    // Delete this object
    ~LED();

    // Set LED color by the specified 'color'.
    void setColor(Color color);

    // Set LED state by the specified 'state'.
    void setState(State state);

    // Set LED rate by the specified 'rate'.
    void setRate(float rate);

    // Return LED color.
    Color getColor() const;

    // Return LED state.
    State getState() const;

    // Return LED rate.
    float getRate() const;

    // Print all the LED options to cout.
    void printOptions() const;
};

#endif // LED_H
