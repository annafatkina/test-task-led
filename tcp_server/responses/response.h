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
    Status      status_;
    std::string error_;

public:
    // Create 'Response' object.
    Response();

    // Destroy this onject.
    virtual ~Response() {}

    // Return the serialized response.
    virtual std::string serialize() const = 0;

    // Set this respose error by the specified 'error'.
    void setError(const std::string& error);

    // Set this response status by the specified 'status'.
    void setStatus(Status status);

    // Return this response error.
    std::string getError() const;
};

#endif // RESPONSE_H
