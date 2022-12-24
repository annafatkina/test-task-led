#ifndef GETLEDSTATEREQUEST_H
#define GETLEDSTATEREQUEST_H

#include "request.h"
#include "led.h"
#include "getledstateresponse.h"

class GetLedStateRequest : public Request
{
public:
    GetLedStateRequest();

    std::shared_ptr<Response> process() override {
        auto state = LED::getLED()->getState();
        std::shared_ptr<Response> resp = std::make_shared<GetLedStateResponse>(state);
        resp->setStatus(Status::OK);
        return resp;
    }
};

#endif // GETLEDSTATEREQUEST_H
