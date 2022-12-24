#ifndef REQUESTPROCESSOR_H
#define REQUESTPROCESSOR_H

#include "request.h"
#include "setledcolorrequest.h"
#include "setledraterequest.h"
#include "setledstaterequest.h"
#include "response.h"
#include "setterresponse.h"

class RequestProcessor
{
public:
    RequestProcessor();

    std::shared_ptr<Response> process(std::shared_ptr<Request> request) {
        return request->process();
    }
};

#endif // REQUESTPROCESSOR_H
