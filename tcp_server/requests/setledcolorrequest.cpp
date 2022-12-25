#include "setledcolorrequest.h"
#include "led.h"
#include "setterresponse.h"

SetLedColorRequest::SetLedColorRequest(Color color)
    : color_(color)
{
}

std::shared_ptr<Response> SetLedColorRequest::process(std::shared_ptr<LED> led) {
    std::shared_ptr<Response> response
            = std::make_shared<SetterResponse>();

    led->setColor(color_);
    response->setStatus(Status::OK);
    return response;
}
