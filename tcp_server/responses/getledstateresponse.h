#ifndef GETLEDSTATERESPONSE_H
#define GETLEDSTATERESPONSE_H

#include "response.h"
#include "led.h"

class GetLedStateResponse : public Response
{
    // This class specifies 'get-led-state' response.

    State state_;
public:
    // NOT IMPLEMENTED
    GetLedStateResponse() = delete;

    // Create 'GetLedStateResponse' object with the specified 'state'.
    GetLedStateResponse(State state);

    // Return the serialized get-led-state response.
    std::string serialize() const override;
};

#endif // GETLEDSTATERESPONSE_H
