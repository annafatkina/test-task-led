#ifndef GETLEDCOLORREQUEST_H
#define GETLEDCOLORREQUEST_H

#include "request.h"
#include "response.h"
#include "led.h"
#include <getledcolorresponse.h>
#include <memory>

class GetLedColorRequest : public Request
{
    // This class specifies 'get-led-color <color>' request.
public:
    // Create 'GetLedColorRequest' object.
    GetLedColorRequest();

    // Set LED color and return the success response
    std::shared_ptr<Response> process(std::shared_ptr<LED> led) override;
};

#endif // GETLEDCOLORREQUEST_H
