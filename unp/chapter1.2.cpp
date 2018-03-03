//
// Created by kratos on 17-12-18.
//


#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include "helper.h"

int main(int argc, char *argv[])
{
    int sockfd = 0;
    int len = 0;

    char buf[256] = {0};

    sockaddr_in servaddr;

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    if (0 > sockfd)
    {
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9588);

    if (0 >= Inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr))
    {
        return 1;
    }

    if (0 > Connect(sockfd, (const sockaddr *) &servaddr, sizeof(servaddr)))
    {
        return 1;
    }

    while (1)
    {
        len = read(sockfd, buf, 256);

        if (len > 0)
        {
            std::cout << buf << std::endl;
        }
        else if (len < 0)
        {
            std::cerr << "read error" << std::endl;
            break;
        }
        else
        {
            break;
        }
    }

    return 1;
}