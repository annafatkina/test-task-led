#include "getledraterequest.h"

GetLedRateRequest::GetLedRateRequest()
{

}

std::shared_ptr<Response> GetLedRateRequest::process(std::shared_ptr<LED> led) {
    float rate = led->getRate();
    std::shared_ptr<Response> resp = std::make_shared<GetLedRateResponse>(rate);
    resp->setStatus(Status::OK);
    return resp;
}
