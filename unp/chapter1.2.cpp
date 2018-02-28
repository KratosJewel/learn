//
// Created by kratos on 17-12-18.
//


#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <unistd.h>

int Socket(int domain, int type, int protocol)
{
    int sockfd = 0;

    sockfd = socket(domain, type, protocol);

    if (0 > sockfd)
    {
        std::cerr << "create socket error" << std::endl;
    }

    return sockfd;
}

int main(int argc, char *argv[])
{
    int sockfd = 0;
    int len = 0;

    char buf[256] = {0};

    struct sockaddr_in servaddr;

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    if (0 > sockfd)
    {
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);

    if (0 >= inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr))
    {
        std::cerr << "inet_pton error" << std::endl;
        return 1;
    }

    if (0 > connect(sockfd, (const sockaddr *) &servaddr, sizeof(servaddr)))
    {
        std::cerr << "connect error" << std::endl;
        return 1;
    }

    while (1)
    {
        len = read(sockfd, buf, 256);

        buf[len] = 0;

        if (len > 0)
        {
            std::cout << len << std::endl;
        }
        else
        {
            std::cerr << "read error" << std::endl;
            break;
        }
    }

    return 1;
}