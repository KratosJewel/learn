//
// Created by kratos on 17-12-28.
//

#include <unistd.h>
#include <iostream>
#include <fcntl.h>

// 设置文件描述符标志
bool set_fd(int fd, int flags)
{
    int old_flags = 0;

    old_flags = fcntl(fd, F_GETFD, 0);

    if (0 > old_flags)
    {
        return false;
    }

    old_flags |= flags;

    old_flags = fcntl(fd, F_SETFD, old_flags);

    if (0 > old_flags)
    {
        return false;
    }

    return true;
}

// 清除文件描述符标志
bool clr_fd(int &fd, int flags)
{
    int old_flags = 0;

    old_flags = fcntl(fd, F_GETFD, 0);

    if (0 > old_flags)
    {
        return false;
    }

    old_flags &= ~flags;

    old_flags = fcntl(fd, F_SETFD, old_flags);

    if (0 > old_flags)
    {
        return false;
    }

    return true;
}

// 设置文件状态标志
bool set_fl(int fd, int flags)
{
    int old_flags = 0;

    old_flags = fcntl(fd, F_GETFL, 0);

    if (0 > old_flags)
    {
        return false;
    }

    old_flags |= flags;

    old_flags = fcntl(fd, F_SETFL, old_flags);

    if (0 > old_flags)
    {
        return false;
    }

    return true;
}

// 清除文件状态标志
bool clr_fl(int &fd, int flags)
{
    int old_flags = 0;

    old_flags = fcntl(fd, F_GETFL, 0);

    if (0 > old_flags)
    {
        return false;
    }

    old_flags &= ~flags;

    old_flags = fcntl(fd, F_SETFL, old_flags);

    if (0 > old_flags)
    {
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    char buf[4096] = {0};

    // 获取符号链接内容
    int fd = open("/home/kratos/Desktop", O_RDONLY);
    readlinkat(fd, "./code", buf, 4096);

    std::cout << buf << std::endl;
    return 1;
}