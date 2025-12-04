#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <limits>
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

void resetStream();

int main(int argc, char *argv[])
{
    addrinfo hints;
    addrinfo *servInfo;
    char s[INET_ADDRSTRLEN];
    int rv; // return value
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (argc != 2)
    {
        std::cerr << "Usage: ./client <server ip address>" << std::endl;
        return 1;
    }
    try
    {
        rv = getaddrinfo(argv[1], "9431", &hints, &servInfo);
        if (rv != 0)
        {
            throw std::runtime_error("getaddrinfo error ");
        }
        int sock;
        sock = socket(servInfo->ai_family, servInfo->ai_socktype, servInfo->ai_protocol);
        if (sock == -1)
        {
            throw std::logic_error("Unable to open socket");
        }
        inet_ntop(servInfo->ai_family, (sockaddr_in *)servInfo->ai_addr, s, sizeof(s));
        std::cout << "client: attempting connection to " << s << std::endl;
        rv = connect(sock, servInfo->ai_addr, servInfo->ai_addrlen);
        if (rv == -1)
        {
            close(sock);
            throw std::logic_error("Unable to connect to server");
        }
        inet_ntop(servInfo->ai_family, (struct sockaddr_in *)servInfo->ai_addr, s, sizeof(s));
        std::cout << "client: connected to " << s << std::endl;
        int input = 0;
        std::cout << "Enter the starting number: ";
        std::cin >> input;
        while (!std::cin)
        {
            resetStream();
            std::cout << "Enter the starting number: ";
            std::cin >> input;
        }
        uint32_t val = static_cast<uint32_t>(input);
        val = htonl(val);
        rv = send(sock, &val, sizeof(val), 0);
        if (rv == -1)
        {
            close(sock);
            throw std::logic_error("Client is unable to send");
        }
        int numbytes = recv(sock, &val, sizeof(val), 0);
        if (numbytes == -1)
        {
            close(sock);
            throw std::logic_error("Client is unable to receive.");
        }
        val = ntohl(val);
        std::cout << "Server Response: " << val << std::endl;
        close(sock);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << " " << gai_strerror(rv) << std::endl;
    }
    catch (std::logic_error e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}