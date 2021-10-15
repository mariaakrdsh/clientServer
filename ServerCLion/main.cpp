#include"server.h"
#include<iostream>
//#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char* argv[]) {

    int port;
    std::cout << "Enter port number for server:\n";
    std::cin >> port;
    return startServer(argc,argv, port);

}