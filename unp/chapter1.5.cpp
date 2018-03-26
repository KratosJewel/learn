//
// Created by kratos on 18-3-1.
//

#include <time.h>
#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>
#include "helper.h"

int main(int argc, char *argv[])
{
    int listenfd = 0;
    int connfd = 0;

    sockaddr_in servaddr;
    sockaddr_in cliaddr;

    socklen_t len = 0;

    char buf[256] = {0};
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    if (0 > listenfd)
    {
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9588);

    if (0 > Bind(listenfd, (const sockaddr *) &servaddr, sizeof(servaddr)))
    {
        return 1;
    }

    if (0 > Listen(listenfd, 10))
    {
        return 1;
    }

    while (1)
    {
        len = sizeof(cliaddr);

        connfd = Accept(listenfd,(sockaddr *) &cliaddr,&len);

        if (0 > connfd)
        {
            return 1;
        }

        std::cout << "connection from " << inet_ntop(AF_INET,&cliaddr.sin_addr,buf,sizeof(buf))
                  << ",port " << ntohs(cliaddr.sin_port) << std::endl;

        ticks = time(NULL);

        snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));

        write(connfd, buf, strlen(buf));

        close(connfd);
    }

    return 1;
}