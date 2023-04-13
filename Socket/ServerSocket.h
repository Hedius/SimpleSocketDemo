//
// Created by florian on 13.04.23.
//

#ifndef SIMPLESOCKETDEMO_SERVERSOCKET_H
#define SIMPLESOCKETDEMO_SERVERSOCKET_H


#include "Socket.h"


class ServerSocket : private Socket {
public:

    ServerSocket(int port);

    ServerSocket() {};

    virtual ~ServerSocket();

    const ServerSocket &operator<<(const std::string &) const;

    const ServerSocket &operator>>(std::string &) const;

    void accept(ServerSocket &);

};


#endif //SIMPLESOCKETDEMO_SERVERSOCKET_H
