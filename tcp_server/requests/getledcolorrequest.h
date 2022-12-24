#ifndef GETLEDCOLORREQUEST_H
#define GETLEDCOLORREQUEST_H

#include "request.h"
#include "response.h"
#include "led.h"
#include <getledcolorresponse.h>
#include <memory>

class GetLedColorRequest : public Request
{
public:
    GetLedColorRequest();

    std::shared_ptr<Response> process() override {
        auto color = LED::getLED()->getColor();
        std::shared_ptr<Response> resp = std::make_shared<GetLedColorResponse>(color);
        resp->setStatus(Status::OK);
        return resp;
    }
};

#endif // GETLEDCOLORREQUEST_H
