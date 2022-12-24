#include "setledstaterequest.h"
#include "led.h"
#include "setterresponse.h"

SetLedStateRequest::SetLedStateRequest(State state)
    : state_(state)
{
}

std::shared_ptr<Response> SetLedStateRequest::process() {
    LED::getLED()->setState(state_);
    std::shared_ptr<Response> resp = std::make_shared<SetterResponse>();
    resp->setStatus(Status::OK);
    return resp;
}
