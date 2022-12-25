#include "getledcolorrequest.h"

GetLedColorRequest::GetLedColorRequest()
{
}

std::shared_ptr<Response> GetLedColorRequest::process(std::shared_ptr<LED> led) {
    auto color = led->getColor();
    std::shared_ptr<Response> resp = std::make_shared<GetLedColorResponse>(color);
    resp->setStatus(Status::OK);
    return resp;
}
