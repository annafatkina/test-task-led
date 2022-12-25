#ifndef REQUEST_H
#define REQUEST_H

#include <response.h>
#include <memory>
#include "led.h"

class Request
{
    // This class is an interface for all types of requests.

public:

    // Return this request response.
    virtual std::shared_ptr<Response> process(std::shared_ptr<LED> led) = 0;

    // Destroy this object.
    virtual ~Request() {};
};

#endif // REQUEST_H
