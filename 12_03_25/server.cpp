#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    int sockfd;
    int clientfd;
    addrinfo hints;
    addrinfo *servInfo;
    addrinfo *p;
    int rv; // return value

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;       // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP socket
    hints.ai_flags = AI_PASSIVE;     // use my IP;

    try
    {
        rv = getaddrinfo(NULL, "9431", &hints, &servInfo);
        if (rv != 0)
        {
            throw std::runtime_error("getaddrinfo error");
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << " " << gai_strerror(rv) << '\n';
    }

    return 0;
}