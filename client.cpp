//
// Created by florian on 13.04.23.
//

#include "Socket/ClientSocket.h"
#include "Socket/SocketException.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    try {
        ClientSocket client_socket("localhost", 30000);

        std::string reply;

        try {
            client_socket << "Test message.";
            client_socket >> reply;
        }
        catch (SocketException &) {}

        std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;

    }
    catch (SocketException &e) {
        std::cout << "Exception was caught:" << e.description() << "\n";
    }

    return 0;
}
