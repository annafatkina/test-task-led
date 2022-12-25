#ifndef GETLEDRATERESPONSE_H
#define GETLEDRATERESPONSE_H

#include "response.h"

class GetLedRateResponse : public Response
{
    // This class specifies 'get-led-rate' response.

    float rate_;
public:
    // NOT IMPLEMENTED
    GetLedRateResponse() = delete;

    // Create 'GetLedRateResponse' with the specified 'rate'.
    GetLedRateResponse(float rate);

    // Return the serialized get-led-rate response.
    std::string serialize() const override;
};

#endif // GETLEDRATERESPONSE_H
