#include "getledstateresponse.h"

GetLedStateResponse::GetLedStateResponse(State state)
    : state_(state)
{}

std::string GetLedStateResponse::serialize() const {
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
