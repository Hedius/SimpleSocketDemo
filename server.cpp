#include "Socket/ServerSocket.h"
#include "Socket/SocketException.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

//ht
#include <iostream>

using namespace std;


// ht
int main(int argc, char *argv[]) {

    try {
        // Create the socket
        ServerSocket server(30000);
        std::cout << "running.... port " << 30000 << endl;

        while (true) {

            ServerSocket new_sock;
            server.accept(new_sock);


            int pid = fork();
            if (pid == 0) {


                try {
                    bool quit = false;
                    while (!quit) {
                        std::string data;
                        new_sock >> data;

                        cout << "SERVER: got <" << data << ">" << endl;
                        new_sock << data;
                        quit = (data == "quit" || data == "quit\r\n");

                    }


                }
                catch (SocketException &) {}

                exit(0);

            } else {

                int status;
                waitpid(-1, &status, WNOHANG);

                // !!! go to service the next

            }
        }
    }
    catch (SocketException &e) {
        std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

    return 0;
}