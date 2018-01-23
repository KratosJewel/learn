//
// Created by kratos on 17-12-18.
//

#include <unistd.h>
#include <iostream>
#include <wait.h>

#define MAX_LINE 256

static void sig_int(int signo)
{
    std::cout << "interrupt" << signo << std::endl;
}

int main(int argc, char *argv[])
{
    char buf[MAX_LINE] = {0};
    int pid = 0;

    // 捕捉信号，进行处理
    if (SIG_ERR == signal(SIGINT, sig_int))
    {
        std::cerr << "signal error" << std::endl;
        return 0;
    }

    std::cout << "%% ";

    // 读取一行
    while (std::cin.getline(buf, MAX_LINE))
    {
        // fork调用一次，返回两次
        pid = fork();

        // 此处输出两个fork的pid,fork从此处开始运行
        std::cout << "-----" << pid << "------" << std::endl;

        if (0 > pid)
        {
            std::cerr << "fork error" << std::endl;
            return 0;
        }
        else if (0 == pid) //fork返回0代表子进程
        {
            // execlp执行失败返回-1
            if (-1 == execlp(buf, buf, (char *) 0))
            {
                std::cerr << "couldn't execute:" << buf << std::endl;
            }
            return 35;
        }

        int status = 0;
        pid = waitpid(pid, &status, 0);

        if (0 > pid)
        {
            std::cerr << "waitpid error" << std::endl;
        }

        std::cout << "%% ";
    }

    return 1;
}