#ifndef SETTERRESPONSE_H
#define SETTERRESPONSE_H

#include <response.h>

class SetterResponse : public Response
{
    // This class specifies 'set-led-<...>' response.
public:
    // Create 'SetterResponse' object.
    SetterResponse();

    // Return the serialized set-led-<...> response.
    std::string serialize() const override;
};

#endif // SETTERRESPONSE_H
