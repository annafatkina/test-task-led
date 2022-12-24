#ifndef SETLEDRATEREQUEST_H
#define SETLEDRATEREQUEST_H

#include <request.h>

class SetLedRateRequest : public Request
{
    // This class defines the concrete set-led-rate request with a given
    // rate.
    float rate_;

public:
    SetLedRateRequest() = delete;

    // Create 'SetLedRateRequest' object with the specified 'rate'
    SetLedRateRequest(float rate);

    std::shared_ptr<Response> process() override;
};

#endif // SETLEDRATEREQUEST_H
