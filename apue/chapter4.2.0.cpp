//
// Created by kratos on 18-1-8.
//

#include <unistd.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    struct stat st_buf;
    struct timespec old_times[2];

    for (int i = 1; i < argc; ++i)
    {
        // 获取旧的访问时间和修改时间
        if (0 > stat(argv[i], &st_buf))
        {
            std::cerr << "argv is fail" << std::endl;
            continue;
        }

        // 打开文件并清空内容，访问时间和修改时间会被更新
        fd = open(argv[i], O_RDWR | O_TRUNC);

        if (0 > fd)
        {
            std::cerr << "open file error" << std::endl;
            continue;
        }

        // 保存旧的访问时间和修改时间
        old_times[0] = st_buf.st_atim;
        old_times[1] = st_buf.st_mtim;

        // 设置旧的访问时间和修改时间
        if (0 > futimens(fd, old_times))
        {
            std::cerr << "set time fail" << std::endl;
        }

        close(fd);
    }

    return 1;
}