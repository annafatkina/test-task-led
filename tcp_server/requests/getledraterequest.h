#ifndef GETLEDRATEREQUEST_H
#define GETLEDRATEREQUEST_H

#include "request.h"
#include "led.h"
#include "getledrateresponse.h"

class GetLedRateRequest : public Request
{
public:
    GetLedRateRequest();

    std::shared_ptr<Response> process() override {
        float rate = LED::getLED()->getRate();
        std::shared_ptr<Response> resp = std::make_shared<GetLedRateResponse>(rate);
        resp->setStatus(Status::OK);
        return resp;
    }
};

#endif // GETLEDRATEREQUEST_H
