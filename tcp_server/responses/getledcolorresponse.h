#ifndef GETLEDCOLORRESPONSE_H
#define GETLEDCOLORRESPONSE_H

#include "response.h"
#include "led.h"
#include <string>

class GetLedColorResponse : public Response
{
    Color color_;

public:
    GetLedColorResponse() = delete;
    GetLedColorResponse(Color color) : color_(color) {}
    std::string serialize() const override {
        std::string result;

        if (status_ == Status::OK) {
            result = "OK " + colorToString(color_);
        } else {
            result = "FAILED";
        }

        if (!error_.empty()) {
            result += " " + error_;
        }

        return result;
    }
};

#endif // GETLEDCOLORRESPONSE_H
