//
// Created by kratos on 17-12-25.
//

#include <limits.h>
#include <sys/resource.h>
#include <unistd.h>
#include <iostream>

#define  OPEN_MAX_GUESS     256

// 获取每个进程能打开的进程数
int main(int argc, char *argv[])
{
    rlimit rl;
    long open_max = 0;

    open_max = sysconf(_SC_OPEN_MAX);

    // _SC_OPEN_MAX 未定义或者等于 LONG_MAX (过于大)
    // 则使用 getrlimit 获取
    if (0 > open_max || LONG_MAX == open_max)
    {
        if (0 > getrlimit(RLIMIT_NOFILE, &rl))
        {
            std::cerr << "can't get file limit" << std::endl;
            return 0;
        }
        if (RLIM_INFINITY == rl.rlim_max)
        {
            open_max = OPEN_MAX_GUESS;
        }
        else
        {
            open_max = rl.rlim_max;
        }
    }

    std::cout << open_max << std::endl;

    return 1;
}
