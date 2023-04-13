cmake_minimum_required(VERSION 3.25)
project(simplesocketdemo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_library(socket SHARED
        Socket/SocketException.h
        Socket/Socket.cpp
        Socket/Socket.h
        Socket/ClientSocket.cpp
        Socket/ClientSocket.h
        Socket/ServerSocket.cpp
        Socket/ServerSocket.h)

add_executable(client client.cpp)
target_link_libraries(client socket)

add_executable(server server.cpp)
target_link_libraries(server socket)