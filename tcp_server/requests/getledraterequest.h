#ifndef GETLEDRATEREQUEST_H
#define GETLEDRATEREQUEST_H

#include "request.h"
#include "led.h"
#include "getledrateresponse.h"

class GetLedRateRequest : public Request
{
    // This class specifies 'get-led-rate <rate>' request.
public:
    // Create 'GetLedRateRequest' request.
    GetLedRateRequest();

    // Set LED rate and return success response.
    std::shared_ptr<Response> process(std::shared_ptr<LED> led) override;
};

#endif // GETLEDRATEREQUEST_H
