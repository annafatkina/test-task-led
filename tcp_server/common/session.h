#ifndef SESSION_H
#define SESSION_H

#include "boost/asio.hpp"
#include "led.h"
#include "requestprocessor.h"
#include <memory>

class Session : public std::enable_shared_from_this<Session>
{
    // TYPES
    using Tcp = boost::asio::ip::tcp;

    // DATA
    Tcp::socket            socket_;
    int                    sessionId_;
    boost::asio::streambuf buffer;
    std::shared_ptr<LED>   led_;

    // PRIVATE METHODS

    // Return data read from buffer.
    std::string readBuffer();

    // Write the specified 'str' to buffer.
    void writeToBuffer(const std::string& str);

    // Read data from the socket and schedule the callback to be called after
    // we get data.
    void do_read();

    // Write data to the socket.
    void do_write();

    // Process the received data.
    void handle();

    // Print 'data' to the command line and reprint LED state the way to leave
    // it on the last lines.
    void logData(const std::string& data, bool reprint = true);

public:
    // Create 'Session' object with the specified 'socket' and 'sessionId'.
    Session(Tcp::socket socket, int sessionId, std::shared_ptr<LED> led);

    // Destroy this object.
    ~Session();

    // Start receiving data.
    void start();
};

#endif // SESSION_H
