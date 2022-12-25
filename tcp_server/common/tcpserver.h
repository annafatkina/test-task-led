#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <boost/asio.hpp>
#include "led.h"

class TcpServer
{
    using Context  = boost::asio::io_context;
    using Signals  = boost::asio::signal_set;
    using Tcp      = boost::asio::ip::tcp;
    using Acceptor = Tcp::acceptor;

    unsigned int         num_threads_;
    Context              context_;
    Signals              signals_;
    Acceptor             acceptor_;
    int                  sessionCounter_;
    std::shared_ptr<LED> led_;

    // Accept new connection
    void do_accept();
    void handle_stop();

public:
    // Create 'TcpSerer' object with the specified 'io_context' and 'port'.
    TcpServer(short port);
    void run();
};

#endif // TCPSERVER_H
