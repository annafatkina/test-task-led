#ifndef SETTERRESPONSE_H
#define SETTERRESPONSE_H

#include <response.h>

class SetterResponse : public Response
{
public:
    SetterResponse();

    std::string serialize() override {
        std::string result;

        if (status_ == Status::OK) {
            result = "OK";
        } else {
            result = "FAILED";
        }

        if (!error_.empty()) {
            result += " " + error_;
        }

        return result;
    }
};

#endif // SETTERRESPONSE_H
