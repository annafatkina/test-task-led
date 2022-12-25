# Test task: LED server

## TcpServer

is a server associated with a LED. It handles client's requests.
After any change (any 'set' request) it reprints LED state to the command line.
It uses async `boost::asio` operations and multithread request handling. 

To run the server:

```
./tcp_server <port>
```

## Client

is a simple client which reads request from the command line and sends it to 
the server.

To run the client:

```
./client <host> <port>
```


## How to build and run the system

This is a cmake project. You can build it by cmake or simply run `install.sh` 
script. Then run server and clients.

Example:

```
. install.sh
./tcp_server 1234
```

Other terminal window:
```
./client localhost 1234
```

## Supported requests

```
set-led-color red|green|blue
set-led-rate 0..5
set-led-state on|off
get-led-color
get-led-rate
get-led-state
```
