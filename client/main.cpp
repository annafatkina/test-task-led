#include <string>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

enum { max_length = 1024 };

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n";
      return 1;
    }

    boost::asio::io_context io_context;

    tcp::socket s(io_context);
    tcp::resolver resolver(io_context);
    boost::asio::connect(s, resolver.resolve(argv[1], argv[2]));
    while(true) {
        std::cout << "Enter message: ";
        //char request[max_length];
        //std::cin.getline(request, max_length);

        std::string str;
        getline(std::cin, str);
        str += "\n";
        size_t request_length = str.size();
        boost::asio::write(s, boost::asio::buffer(str.c_str(), request_length));


        boost::asio::streambuf buffer(512);
        boost::asio::read_until(s, buffer, '\n');
        std::istream iss(&buffer);
        std::string s;
        std::getline(iss, s);
        std::cout << "Reply is: ";

        std::cout << s;
        std::cout << "\n";
    }
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
