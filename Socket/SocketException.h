//
// Created by florian on 13.04.23.
//

#ifndef SIMPLESOCKETDEMO_SOCKETEXCEPTION_H
#define SIMPLESOCKETDEMO_SOCKETEXCEPTION_H

#include <string>

class SocketException {
public:
    SocketException(std::string s) : m_s(s) {};

    ~SocketException() {};

    std::string description() { return m_s; }

private:

    std::string m_s;

};

#endif //SIMPLESOCKETDEMO_SOCKETEXCEPTION_H
