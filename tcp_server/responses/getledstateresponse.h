#ifndef GETLEDSTATERESPONSE_H
#define GETLEDSTATERESPONSE_H

#include "response.h"
#include "led.h"

class GetLedStateResponse : public Response
{
    State state_;
public:
    GetLedStateResponse() = delete;

    GetLedStateResponse(State state) : state_(state) {}

    std::string serialize() override {
        std::string result;

        if (status_ == Status::OK) {
            result = "OK " + stateToString(state_);
        } else {
            result = "FAILED";
        }

        if (!error_.empty()) {
            result += " " + error_;
        }

        return result;
    }
};

#endif // GETLEDSTATERESPONSE_H
