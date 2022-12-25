#ifndef GETLEDSTATEREQUEST_H
#define GETLEDSTATEREQUEST_H

#include "request.h"
#include "led.h"
#include "getledstateresponse.h"

class GetLedStateRequest : public Request
{
    // This class specifies 'get-led-state' request.

public:
    // Create 'GetLedStateRequest' object.
    GetLedStateRequest();

    // Return get-led-state success response.
    std::shared_ptr<Response> process(std::shared_ptr<LED> led) override;
};

#endif // GETLEDSTATEREQUEST_H
