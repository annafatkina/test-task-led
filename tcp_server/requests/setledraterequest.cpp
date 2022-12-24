#include "setledraterequest.h"
#include <stdexcept>
#include "led.h"
#include "setterresponse.h"

SetLedRateRequest::SetLedRateRequest(float rate)
    : rate_(rate)
{
    if (rate > 5.0f || rate < 0.0f) {
        throw std::runtime_error("Wrong rate is provided, rate should be from "
                                 "0 to 5, rate provided: " +
                                 std::to_string(rate));
    }
}

std::shared_ptr<Response> SetLedRateRequest::process() {
    LED::getLED()->setRate(rate_);
    std::shared_ptr<Response> resp = std::make_shared<SetterResponse>();
    resp->setStatus(Status::OK);
    return resp;
}
