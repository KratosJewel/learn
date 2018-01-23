//
// Created by kratos on 17-12-18.
//

#include <unistd.h>
#include <iostream>

#define BUFF_SIZE 4096

int main(int argc, char *argv[])
{
    int r_len = 0;
    char buf[BUFF_SIZE] = {0};

    // 读取内容并写入
    while (0 < (r_len = read(STDIN_FILENO, buf, BUFF_SIZE)))
    {
        if (r_len != write(STDOUT_FILENO, buf, r_len))
        {
            std::cerr << "write error" << std::endl;
            return 0;
        }
    }

    if (0 < r_len)
    {
        std::cerr << "read error" << std::endl;
        return 0;
    }

    return 1;
}