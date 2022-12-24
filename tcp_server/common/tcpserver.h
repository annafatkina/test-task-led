#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <boost/asio.hpp>

class TcpServer
{
    using Tcp      = boost::asio::ip::tcp;
    using Acceptor = Tcp::acceptor;
    using Context  = boost::asio::io_context;

    Acceptor acceptor_;
    int sessionCounter_;

    void do_accept();

  public:
      TcpServer(Context& io_context, short port);
};

#endif // TCPSERVER_H
