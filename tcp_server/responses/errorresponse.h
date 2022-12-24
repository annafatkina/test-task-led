#ifndef ERRORRESPONSE_H
#define ERRORRESPONSE_H

#include "response.h"

class ErrorResponse : public Response
{
public:
    ErrorResponse();

    std::string serialize() override;
};

#endif // ERRORRESPONSE_H
