//
// Created by florian on 13.04.23.
//

#ifndef SIMPLESOCKETDEMO_CLIENTSOCKET_H
#define SIMPLESOCKETDEMO_CLIENTSOCKET_H

#include "Socket.h"

class ClientSocket : private Socket {
public:

    ClientSocket(std::string host, int port);

    virtual ~ClientSocket() {};

    const ClientSocket &operator<<(const std::string &) const;

    const ClientSocket &operator>>(std::string &) const;

};


#endif //SIMPLESOCKETDEMO_CLIENTSOCKET_H
