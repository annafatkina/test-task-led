#include "deserializer.h"

std::shared_ptr<Request> Deserializer::deserialize(std::string msg) {
    std::stringstream ss(msg);
    std::string word;

    // The first word contains the command
    getline(ss, word, ' ');

    if(word == "set-led-color") {
        std::string val;
        getline(ss, val, '\n');

        Color color = stringToColor(val);
        // Can throw, we will catch it outside
        return std::make_shared<SetLedColorRequest>(color);
    }

    if (word == "set-led-rate") {
        std::string val;
        getline(ss, val, '\n');
        float rate;
        try {
              rate = std::stof(val);
        } catch (std::exception& error) {
            throw std::runtime_error("Wrong rate type, rate provided: " + val);
        }
        return std::make_shared<SetLedRateRequest>(rate);
    }

    if (word == "set-led-state") {
        std::string val;
        getline(ss, val, '\n');
        State state = stringToState(val);
        return std::make_shared<SetLedStateRequest>(state);
    }

    if (word == "get-led-color") {
        return std::make_shared<GetLedColorRequest>();
    }

    if (word == "get-led-state") {
        return std::make_shared<GetLedStateRequest>();
    }

    if (word == "get-led-rate") {
        return std::make_shared<GetLedRateRequest>();
    }

    throw std::runtime_error("Cannot deserialize request msg:\n\t" +
                             msg + "\nNo known request type.\n");
}
