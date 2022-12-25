#include "setterresponse.h"

SetterResponse::SetterResponse()
{

}

std::string SetterResponse::serialize() const {
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
