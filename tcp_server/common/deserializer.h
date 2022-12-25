#ifndef DESERIALIZER_H
#define DESERIALIZER_H

#include <string>
#include <sstream>
#include <istream>
#include "request.h"
#include "led.h"
#include "setledcolorrequest.h"
#include "setledraterequest.h"
#include "setledstaterequest.h"
#include "getledcolorrequest.h"
#include "getledstaterequest.h"
#include "getledraterequest.h"

class Deserializer
{
    // This class provides a mechanism to deserialize message into request.
public:
    // NOT IMPLEMENTED
    Deserializer() = delete;
    Deserializer(const Deserializer&) = delete;
    Deserializer(Deserializer&&) = delete;

    // Return the deserialized request which the specifies 'msg' contains.
    static std::shared_ptr<Request> deserialize(std::string msg);
};

#endif // DESERIALIZER_H
