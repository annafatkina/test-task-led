#ifndef SETLEDSTATEREQUEST_H
#define SETLEDSTATEREQUEST_H

#include <led.h>
#include <request.h>

class SetLedStateRequest : public Request
{
    // This class defines the concrete set-led-state request with a given
    // state.
    State state_;

public:
    SetLedStateRequest() = delete;

    // Create 'SetLedStateRequest' object with the specified 'state'
    explicit SetLedStateRequest(State state);

    // Return set-led-state success response.
    std::shared_ptr<Response> process(std::shared_ptr<LED> led) override;
};

#endif // SETLEDSTATEREQUEST_H
