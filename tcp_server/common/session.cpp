#include <iostream>
#include "session.h"
#include "boost/bind.hpp"
#include "deserializer.h"
#include "errorresponse.h"

std::string Session::readBuffer() {
    std::istream iss(&buffer);
    std::string s;
    std::getline(iss, s);
    return s;
}

void Session::writeToBuffer(const std::string& str) {
    std::ostream output(&buffer);
    output << str << "\n";
    do_write();
}

void Session::do_read()
{
  auto self(shared_from_this());
  auto callback = [this, self](boost::system::error_code ec, int size)
  {
    if (!ec)
    {
      handle();
    } else {
        printf("\033[A\33[2KT\r\033[A\33[2KT\r\033[A\33[2KT\r");
        std::cerr << "Error while reading data from client:\n\t" << ec
                  << "\nfor session with session id " << sessionId_
                  << ". Closing this session."<< std::endl;
        led_->printOptions();
        return;
    }
  };

  boost::asio::async_read_until(socket_, buffer, '\n', callback);
}

void Session::do_write()
{
  auto self(shared_from_this());
  auto callback = [this, self](boost::system::error_code ec, int size)
  {
    if (!ec)
    {
      do_read();
    }
  };

  boost::asio::async_write(socket_, buffer, callback);
}

void Session::handle() {
        std::string s = readBuffer();

        std::shared_ptr<Response> resp;

        try {
          std::shared_ptr<Request> request = Deserializer::deserialize(s);
          resp = RequestProcessor::process(led_, request);

        } catch (std::runtime_error& e){
            printf("\033[A\33[2KT\r\033[A\33[2KT\r\033[A\33[2KT\r");
            std::cerr << "Error: " << e.what();
            led_->printOptions();
            resp = std::make_shared<ErrorResponse>();
        }

        writeToBuffer(resp->serialize());
}

// public
Session::Session(Tcp::socket socket, int sessionId, std::shared_ptr<LED> led)
    : socket_(std::move(socket))
    , sessionId_(sessionId)
    , buffer(1024)
    , led_(led)
  {
  }

Session::~Session() {
    printf("\033[A\33[2KT\r\033[A\33[2KT\r\033[A\33[2KT\r");
    std::cout << "Session with session id " << sessionId_ << " closed."
              << std::endl;
    led_->printOptions();
}

void Session::start()
{
    if(sessionId_ > 0) {
        // We don't want to clean cmd for the first session as there was no
        // data printed yet
        printf("\033[A\33[2KT\r\033[A\33[2KT\r\033[A\33[2KT\r");
    }
    std::cout << "Session with session id " << sessionId_ << " started."
              << std::endl;
    led_->printOptions();
    do_read();
}
