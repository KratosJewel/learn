//
// Created by kratos on 18-3-4.
//

#ifndef LEARN_HELPER_H
#define LEARN_HELPER_H

#include <iostream>
#include <string>
#include <arpa/inet.h>

int Socket(int domain, int type, int protocol)
{
    int sockfd = 0;

    sockfd = socket(domain, type, protocol);

    if (0 > sockfd)
    {
        std::cerr << "create socket error:" << strerror(errno) << std::endl;
    }

    return sockfd;
}

int Connect(int sockfd, const struct sockaddr *servaddr, unsigned int socket_len)
{
    int result = connect(sockfd, servaddr, socket_len);

    if (0 > result)
    {
        std::cerr << "connect socket error:" << strerror(errno) << std::endl;
    }

    return result;
}

int Inet_pton(int domain, const std::string &host, in_addr *sin_addr)
{
    int result = inet_pton(domain, host.c_str(), sin_addr);

    if (0 >= result)
    {
        std::cerr << "inet_pton error:" << strerror(errno) << std::endl;
    }

    return result;
}

int Bind(int listenfd, const struct sockaddr *servaddr, unsigned int socket_len)
{
    int result = bind(listenfd, servaddr, socket_len);

    if (0 > result)
    {
        std::cerr << "bind socket error:" << strerror(errno) << std::endl;
    }

    return result;
}

int Listen(int listenfd, int count)
{
    char *pcount = NULL;
    pcount = getenv("LISTENQ");

    if (NULL != pcount)
    {
        count = atoi(pcount);
    }

    int result = listen(listenfd, count);

    if (0 > result)
    {
        std::cerr << "listen socket error:" << strerror(errno) << std::endl;
    }

    return result;
}

int Accept(int listenfd, struct sockaddr *servaddr, socklen_t *socket_len)
{
    int result = accept(listenfd, servaddr, socket_len);

    if (0 > result)
    {
        std::cerr << "accept socket error:" << strerror(errno) << std::endl;
    }

    return result;
}


#endif //LEARN_HELPER_H
