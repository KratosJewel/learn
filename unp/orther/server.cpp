//
// Created by logan on 18-6-7.
//

#include <iostream>
#include <time.h>
#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include "../helper.h"

#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 10

int SetNonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

void ResetOneshot(int epollfd, int fd)
{
    struct epoll_event event;
    event.data.ptr = 0;
    event.data.fd = fd;
    event.events = EPOLLET | EPOLLIN | EPOLLONESHOT;

    epoll_ctl(epollfd,EPOLL_CTL_MOD, fd, &event);
}

void Addfd(int epollfd, int fd, bool enable_et)
{
    struct epoll_event event;
    event.data.ptr = 0;
    event.data.fd = fd;
    event.events = EPOLLIN;

    if (enable_et)
    {
        event.events |= EPOLLET;
        event.events |= EPOLLONESHOT;
    }

    epoll_ctl(epollfd,EPOLL_CTL_ADD, fd, &event);
    SetNonblocking(fd);
}

void lt(epoll_event* events, int number, int epollfd, int listenfd)
{
    char buf[BUFFER_SIZE] = {0};

    for (int i = 0; i < number; ++i)
    {
        int sockfd = events[i].data.fd;

        if (sockfd == listenfd)
        {
            sockaddr_in client_address;
            socklen_t  client_address_len = sizeof(client_address);

            int connfd = Accept(listenfd, (sockaddr *) &client_address, &client_address_len);

            Addfd(epollfd,connfd,false);
        }
        else if(events[i].events & EPOLLIN)
        {
            printf("event trigger once\n");
            memset(buf, '\0',BUFFER_SIZE);

            int ret = recv(sockfd, buf, BUFFER_SIZE -1,0);

            if (0 >= ret)
            {
                close(sockfd);
                continue;
            }
            printf("get %d bytes of content:%s\n",ret,buf);
        }
    }
}

void et(epoll_event* events, int number, int epollfd, int listenfd)
{
    char buf[BUFFER_SIZE] = {0};

    for (int i = 0; i < number; ++i)
    {
        int sockfd = events[i].data.fd;

        if (sockfd == listenfd)
        {
            sockaddr_in client_address;
            socklen_t  client_address_len = sizeof(client_address);

            int connfd = Accept(listenfd, (sockaddr *) &client_address, &client_address_len);

            Addfd(epollfd,connfd,true);
        }
        else if(events[i].events & EPOLLIN)
        {
            printf("event trigger once\n");

            while (1)
            {
                memset(buf, '\0',BUFFER_SIZE);

                int ret = recv(sockfd, buf, BUFFER_SIZE -1,0);

                if (0 > ret)
                {
                    // 对于非阻塞IO，下面的条件成立表示数据已经全部读取完毕，此后，epoll就能
                    // 再次出发EPOLLIN事件，以驱动下一次读操作
                    if (EAGAIN == errno || EWOULDBLOCK == errno)
                    {
                        ResetOneshot(epollfd,sockfd);
                        break;
                    }
                    close(sockfd);
                    break;
                }
                else if (0 == ret)
                {
                    close(sockfd);
                }
                else
                {
                    printf("get %d bytes of content:%s\n",ret,buf);
                }
            }
        }
    }
}

void rest()
{
    static int i = 0;

    std::cout << i++ <<std::endl;
}

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

    if (0 > Listen(listenfd, 5))
    {
        return 1;
    }

    epoll_event events[MAX_EVENT_NUMBER];

    int epollfd = epoll_create(5);
    Addfd(epollfd,listenfd,false);

    int a = 0;
    while (1)
    {
        int ret = epoll_wait(epollfd,events,MAX_EVENT_NUMBER,-1);

        //lt(events,ret,epollfd,listenfd);
        et(events,ret,epollfd,listenfd);

        ++a;

        if (a == 3)
        {
            close(epollfd);
            return 1;
        }
    }

    len = sizeof(cliaddr);

    connfd = Accept(listenfd, (sockaddr *) &cliaddr, &len);

    if (0 > connfd)
    {
        return 1;
    }

    std::cout << "connection from " << inet_ntop(AF_INET, &cliaddr.sin_addr, buf, sizeof(buf))
              << ",port " << ntohs(cliaddr.sin_port) << std::endl;

    int file_fd = open("server.cpp", O_RDONLY);

    struct stat stat_buf;
    fstat(file_fd, &stat_buf);

    // 零拷贝发送文件
    // sendfile(connfd, file_fd,NULL,stat_buf.st_size);

    // 回射服务
    int pipe_fd[2];
    pipe(pipe_fd);

    splice(connfd, NULL, pipe_fd[1], NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE);
    splice(pipe_fd[0], NULL, connfd, NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE);

    close(file_fd);
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    shutdown(connfd, SHUT_RDWR);

    shutdown(listenfd, SHUT_RDWR);

    return 1;
}