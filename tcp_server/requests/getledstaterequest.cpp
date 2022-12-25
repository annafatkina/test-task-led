#include "getledstaterequest.h"

GetLedStateRequest::GetLedStateRequest()
{

}

std::shared_ptr<Response> GetLedStateRequest::process(std::shared_ptr<LED> led) {
    auto state = led->getState();
    std::shared_ptr<Response> resp = std::make_shared<GetLedStateResponse>(state);
    resp->setStatus(Status::OK);
    return resp;
}
