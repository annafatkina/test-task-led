#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <boost/asio.hpp>
#include "led.h"

class TcpServer
{
    using Tcp      = boost::asio::ip::tcp;
    using Acceptor = Tcp::acceptor;
    using Context  = boost::asio::io_context;

    Acceptor             acceptor_;
    int                  sessionCounter_;
    std::shared_ptr<LED> led_;

    // Accept new connection
    void do_accept();

public:
    // Create 'TcpSerer' object with the specified 'io_context' and 'port'.
    TcpServer(Context& io_context, short port);
};

#endif // TCPSERVER_H
