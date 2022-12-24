#include "tcpserver.h"
#include "session.h"


void TcpServer::do_accept()
{
  acceptor_.async_accept(
      [this](boost::system::error_code ec, Tcp::socket socket)
      {
        if (!ec)
        {
          std::make_shared<Session>(std::move(socket), sessionCounter_)->start();
          sessionCounter_++;
        }

        do_accept();
      });
}

TcpServer::TcpServer(Context& io_context, short port)
    : acceptor_(io_context, Tcp::endpoint(Tcp::v4(), port))
    , sessionCounter_(0)
  {
    do_accept();
  }
