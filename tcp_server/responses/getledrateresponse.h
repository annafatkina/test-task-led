#ifndef GETLEDRATERESPONSE_H
#define GETLEDRATERESPONSE_H

#include "response.h"

class GetLedRateResponse : public Response
{
    float rate_;
public:
    GetLedRateResponse() = delete;
    GetLedRateResponse(float rate) : rate_(rate) {}

    std::string serialize() override {
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
};

#endif // GETLEDRATERESPONSE_H
