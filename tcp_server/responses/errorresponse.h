#ifndef ERRORRESPONSE_H
#define ERRORRESPONSE_H

#include "response.h"

class ErrorResponse : public Response
{
    // This class provides the error response.  Its status is always 'FALSE'.
public:
    // Create 'ErrorResponse' object.
    ErrorResponse();

    // Return the serialized error response.
    std::string serialize() const override;
};

#endif // ERRORRESPONSE_H
