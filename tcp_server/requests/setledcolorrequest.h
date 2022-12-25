#ifndef SETLEDCOLORREQUEST_H
#define SETLEDCOLORREQUEST_H

#include <led.h>
#include <request.h>

class SetLedColorRequest : public Request
{
    // This class defines the concrete set-led-color request with a given
    // color.
    Color color_;

public:
    SetLedColorRequest() = delete;

    // Create 'SetLedColorRequest' object with the specified 'color'
    explicit SetLedColorRequest(Color color);

    // Return set-led-color success response.
    std::shared_ptr<Response> process(std::shared_ptr<LED> led) override;
};

#endif // SETLEDCOLORREQUEST_H
