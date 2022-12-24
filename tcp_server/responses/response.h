#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>

enum class Status {
    OK,
    FAILED
};

class Response
{
    // This class is an interface for all the types of response.
protected:
    Status status_;
    std::string error_;

public:
    Response() {}

    void setError(const std::string& error) { error_ = error; }
    void setStatus(Status status) {status_ = status; }
    virtual std::string serialize() = 0;

    virtual ~Response() {}
};

#endif // RESPONSE_H
