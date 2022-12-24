cmake_minimum_required(VERSION 3.5)

project(tcp_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FIND_PACKAGE( Boost 1.40 COMPONENTS system REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} requests responses common)
set(REQUESTS
    requests/request.h
    requests/setledstaterequest.h
    requests/setledcolorrequest.h
    requests/setledraterequest.h
    requests/getledcolorrequest.h
    requests/getledstaterequest.h
    requests/getledraterequest.h
    requests/setledstaterequest.cpp
    requests/setledcolorrequest.cpp
    requests/setledraterequest.cpp
    requests/getledcolorrequest.cpp
    requests/getledstaterequest.cpp
    requests/getledraterequest.cpp
    )
set(RESPONSES
    responses/response.h
    responses/setterresponse.h
    responses/errorresponse.h
    responses/getledstateresponse.h
    responses/getledrateresponse.h
    responses/setterresponse.cpp
    responses/errorresponse.cpp
    responses/getledstateresponse.cpp
    responses/getledrateresponse.cpp
    )

add_executable(tcp_server
    ${REQUESTS}
    ${RESPONSES}
    main.cpp
    common/tcpserver.cpp
    common/tcpserver.h
    common/session.cpp
    common/session.h
    common/requestprocessor.cpp
    common/requestprocessor.h
    common/led.cpp
    common/led.h
    common/deserializer.h
    common/deserializer.cpp
)

TARGET_LINK_LIBRARIES(tcp_server LINK_PUBLIC ${Boost_LIBRARIES} -lpthread)
