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

const int BACKLOG = 10;

int main(int argc, char *argv[])
{
    int sockfd;
    int clientfd;
    addrinfo hints;
    addrinfo *servInfo;
    addrinfo *p;
    int rv;      // return value
    int yes = 1; // reuse port

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
        sockfd = socket(servInfo->ai_family, servInfo->ai_socktype, servInfo->ai_protocol);
        if (sockfd == -1)
        {
            throw std::invalid_argument("There was an error creating the socket");
        }
        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
        rv = bind(sockfd, servInfo->ai_addr, servInfo->ai_addrlen);
        if (rv == -1)
        {
            close(sockfd);
            throw std::invalid_argument("Server is unable to bind");
        }
        rv = listen(sockfd, BACKLOG);
        if (rv == -1)
        {
            close(sockfd);
            throw std::invalid_argument("Server is unable to listen");
        }
        std::cout << "server: waiting for connections..." << std::endl;
        while (true)
        {
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << " " << gai_strerror(rv) << '\n';
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}