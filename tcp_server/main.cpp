#include <iostream>
#include <memory>
#include <utility>

#include "tcpserver.h"
#include "boost/asio.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    try
      {
        if (argc != 2)
        {
          std::cerr << "Usage: async_tcp_echo_server <port>\n";
          return 1;
        }

        TcpServer s(std::atoi(argv[1]));

        s.run();
      }
      catch (std::exception& e)
      {
        std::cerr << "Exception: " << e.what() << "\n";
      }

      return 0;
}
