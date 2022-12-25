#include "getledrateresponse.h"

GetLedRateResponse::GetLedRateResponse(float rate)
    : rate_(rate)
{}

std::string GetLedRateResponse::serialize() const {
    std::string result;

    if (status_ == Status::OK) {
        result = "OK " + std::to_string(rate_);
    } else {
        result = "FAILED";
    }

    if (!error_.empty()) {
        result += " " + error_;
    }

    return result;
}
