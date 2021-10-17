#include "client.h"
#include <iostream>
#include<cstdio>
#include <regex>
#include <windows.h>
#include<Winsock2.h>


#pragma comment (lib, "Ws2_32.lib")

int mainClientFunc(int argc, char* argv[],int port) {
    WSADATA wsaData;
    int iResult;

// Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }
    SOCKET sock = 0, valread;
    struct sockaddr_in serv_addr;
    char textFromServer[4096] = {0};
    std::string textFromServerString;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);


    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection failed:( \n");
        return -1;
    }

    std::cout << "Hi!\n";

    char passwordSize[32];
    recv(sock, passwordSize, 1024, 0);

    std::cout << "Password size is " << passwordSize << '\n';
    while(true) {
        std::cout << "Please, try to guess server password:\n";
        std::string password;
        std::cin >> password;
        send(sock, password.c_str(), password.length() + 1, 0);

        //read result strings from server storage
        recv(sock, textFromServer, 1024, 0);
        if((std::string)textFromServer != "Try again:(") break;
    }


    return 0;
}