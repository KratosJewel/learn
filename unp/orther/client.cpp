//
// Created by logan on 18-6-7.
//

#include <iostream>
#include <time.h>
#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include "../helper.h"

int main(int argc, char *argv[])
{
    // 获取目标主机地址信息
    hostent* host_info = gethostbyname("localhost");
    // 获取daytime服务信息
    servent* serve_info = getservbyname("daytime","tcp");

    int sockfd = 0;
    int len = 0;

    char buf[256] = {0};

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    if (0 > sockfd)
    {
        return 1;
    }

    sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = serve_info->s_port;
    servaddr.sin_addr = *(in_addr*)*host_info->h_addr_list;

//    if (0 >= Inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr))
//    {
//        return 1;
//    }

    if (0 > Connect(sockfd, (const sockaddr *) &servaddr, sizeof(servaddr)))
    {
        return 1;
    }

    while (1)
    {
        len = recv(sockfd, buf, 256,0);

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