#include "errorresponse.h"

ErrorResponse::ErrorResponse()
{
    setStatus(Status::FAILED);
}

std::string ErrorResponse::serialize() {
    return "FAILED";
}
