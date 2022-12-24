#ifndef REQUEST_H
#define REQUEST_H

#include <response.h>
#include <memory>
class Request
{
    // This class is an interface for all types of requests.
public:
    virtual std::shared_ptr<Response> process() = 0;
    virtual ~Request() {};
};

#endif // REQUEST_H
