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
    // This class provides a mechanism to process request.
public:
    // NOT IMPLEMENTED
    RequestProcessor() = delete;

    // Return a response to the specified 'request'.
    static std::shared_ptr<Response> process(std::shared_ptr<LED> led,
                                             std::shared_ptr<Request> request) {
        return request->process(led);
    }
};

#endif // REQUESTPROCESSOR_H
