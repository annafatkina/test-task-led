#include "response.h"

Response::Response() {}

void Response::setError(const std::string& error) {
    error_ = error;
}

void Response::setStatus(Status status) {
    status_ = status;
}

std::string Response::getError () const {
    return error_;
}
